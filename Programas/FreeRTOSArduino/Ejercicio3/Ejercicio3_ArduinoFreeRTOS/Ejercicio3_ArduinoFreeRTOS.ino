/**
* Autor: Agustin
* Fecha: 04/02/2021
* Programa: En este programa el objetivo principal es aprender a utilizar las colas de datos en freertos, pero solo el comienzo de estas.
*		- vTaskSender1Adc   --> Envia datos de 0 a 1023; con el adc0 modifica frecuencia y el adc1 el pwm
*		- vTaskSender2		--> Envia el valor de un contador que se va sumando y haciendo un blink de 1hz
*		- vTaskReceiver1	--> Recive una estructura donde luego segundo los datos imprime en el lcd 
*/

// Defines //
#define PWM_INPUT			A0
#define PWM2_INPUT			A1
#define PWM_OUTPUT			2
#define PWM2_OUTPUT			3
#define LED_BLINK_PIN		13
// End //

// Includes //
#include <LiquidCrystal.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>
// End //

// Clase for Lcd //
const int rs = 36, en = 37, d4 = 38, d5 = 39, d6 = 46, d7 = 47;
LiquidCrystal Lcd(rs, en, d4, d5, d6, d7);
// End //

// Task prototypes //
void vTaskSender1Adc(void* pvParameter);
void vTaskSender2(void* pvParameter);
void vTaskReceiver1(void* pvParameter);
// End //

// Pwm Configuration //
//void Pwm_Init(unsigned int freq);
//void Pwm_SetDutyA(uint8_t duty);
//void Pwm_SetDutyB(uint8_t duty);
//void Pwm_On(void);
//void Pwm_Off(void);
//unsigned int _freq = 0;
// End //

// Variables for freertos //
typedef enum
{
	eAdcPwm2,
	eAdcPwm1
}DataSource_t;
typedef struct
{
	uint16_t usValue;
	DataSource_t eDataSource;
}Data_t;
// End //

// Queue //
QueueHandle_t xQueueMotorControl,xQueueCount;
// End //

void setup()
{
	// Setting up pwm //
	//Pwm_Init(200);

	// End //

	// Init serial monitor //
	Serial.begin(9600);
	// End //

	// Create a Queue //
	/*
	* Creamos una cola de datos de 3 espacios con un tipo de dato de estructura
	* 1er parametro: cantidad de espacios
	* 2do parametro: tipo de datos
	*/
	xQueueMotorControl = xQueueCreate(3,sizeof(Data_t));
	xQueueCount = xQueueCreate(5, sizeof(uint8_t));

	// Create tasks for queueMotorControl //
	/*
	* Si se creo existosamente la cola de datos, se crean las tareas realcionadas con esta
	*/
	if (xQueueMotorControl != NULL)
	{
		xTaskCreate(
			vTaskSender1Adc	// Nombre de la tarea en referencia al kernel
			, "PwmAndFreq"	// Nombre de la tarea en referencia al usuario
			, 128			// Stack o nivel de pila
			, NULL			// Parametros que se envian
			, 1				// Nivel de prioridad
			, NULL);		// Manipulador de tarea
		xTaskCreate(
			vTaskReceiver1
			, "DisplayLcd"
			, 128
			, NULL
			, 2
			, NULL);
	}
	if (xQueueCount != NULL)
	{
		xTaskCreate(
			vTaskSender2
			, "CounterAndBlink"
			, 128
			, NULL
			, 1
			, NULL);
	}
	
	// Start scheduler //
	vTaskStartScheduler();
}

void loop() {}

void vTaskSender1Adc(void* pvParameter)
{
	(void)pvParameter;
	BaseType_t xStatus;
	uint16_t xAdcPwm2=0,xAdcPwm1=0;
	const TickType_t xDelay50ms = pdMS_TO_TICKS(50);
	const TickType_t xDelay200ms = pdMS_TO_TICKS(200);
	Data_t xStructMotorControl[2]
	{
		{0, eAdcPwm2},
		{0, eAdcPwm1}
	};

	while (1)
	{
		xAdcPwm2 = analogRead(PWM2_INPUT);
		xStructMotorControl[0].usValue = (uint16_t) ((xAdcPwm2*255.0)/1024.0);

		xAdcPwm1 = analogRead(PWM_INPUT);
		xStructMotorControl[1].usValue = (uint16_t)((xAdcPwm1*255.0)/1024.0);

		// Send AdcPwm2
		xStatus = xQueueSendToBack(xQueueMotorControl, &(xStructMotorControl[0]), xDelay200ms);
		
		// Send AdcPwm2
		xStatus = xQueueSendToBack(xQueueMotorControl, &(xStructMotorControl[1]), xDelay200ms);
		if (xStatus == NULL)
		{
			Serial.println("No fue posible enviar el adc de pwm");
		}

		vTaskDelay(xDelay50ms);
	}
	vTaskDelete(NULL);
}
void vTaskSender2(void* pvParameter)
{
	(void)pvParameter;
	uint8_t ucCounttoSend;
	BaseType_t xStatusSendCount;
	TickType_t xLastWakeTime;
	const TickType_t xDelay500ms = pdMS_TO_TICKS(500);
	const TickType_t xDelay100ms = pdMS_TO_TICKS(100);

	xLastWakeTime = xTaskGetTickCount();
	pinMode(LED_BLINK_PIN, OUTPUT);
	digitalWrite(LED_BLINK_PIN, LOW);

	while (1)
	{
		xStatusSendCount = xQueueSendToBack(xQueueCount, &ucCounttoSend, xDelay100ms);
		if (xStatusSendCount == pdPASS)	ucCounttoSend++;

		digitalWrite(LED_BLINK_PIN, !digitalRead(LED_BLINK_PIN));
		xTaskDelayUntil(&xLastWakeTime, xDelay500ms);
	}
	vTaskDelete(NULL);
}
void vTaskReceiver1(void* pvParameter)
{
	(void)pvParameter;
	Data_t xStructReceiveMotorControl;
	uint8_t ucCountReceive;
	BaseType_t xStatusReceiveQueue,xStatusReceiveCount;
	const TickType_t xDelay2s = pdMS_TO_TICKS(2000);
	const TickType_t xDelay100ms = pdMS_TO_TICKS(100);

	pinMode(PWM_OUTPUT, OUTPUT);

	Lcd.begin(16, 2);
	Lcd.setCursor(0, 0);
	Lcd.print("FreeRTOS Ej.3");
	Lcd.setCursor(0, 1);
	Lcd.print("Cola de Datos");
	vTaskDelay(xDelay2s);
	Lcd.clear();

	Lcd.setCursor(0, 0);
	Lcd.print("Pwm2:");
	Lcd.setCursor(0, 1);
	Lcd.print("Pwm1:");
	Lcd.setCursor(11, 1);
	Lcd.print("490Hz");

	while (1)
	{
		xStatusReceiveQueue = xQueueReceive(xQueueMotorControl, &xStructReceiveMotorControl, xDelay100ms);
		if (xStatusReceiveQueue == pdPASS)
		{
			if (xStructReceiveMotorControl.eDataSource == eAdcPwm2)
			{
				Lcd.setCursor(5, 0);
				Lcd.print("   ");
				Lcd.setCursor(5, 0);
				Lcd.print(xStructReceiveMotorControl.usValue);
				analogWrite(PWM2_OUTPUT, xStructReceiveMotorControl.usValue);
			}
			if (xStructReceiveMotorControl.eDataSource == eAdcPwm1)
			{
				Lcd.setCursor(5, 1);
				Lcd.print("   ");
				Lcd.setCursor(5, 1);
				Lcd.print(xStructReceiveMotorControl.usValue);
				analogWrite(PWM_OUTPUT, xStructReceiveMotorControl.usValue);
			}
		}

		xStatusReceiveCount = xQueueReceive(xQueueCount, &ucCountReceive, xDelay100ms);
		if (xStatusReceiveCount == pdPASS)
		{
			Lcd.setCursor(13, 0);
			Lcd.print("   ");
			Lcd.setCursor(13, 0);
			Lcd.print(ucCountReceive);
		}

		vTaskDelay(1);
	}
	vTaskDelete(NULL);
}


// Pwm Configuration //
//void Pwm_Init(unsigned int freq)
//{
//	TCCR3A &= ~(1<<WGM30);
//	TCCR3A |= (1<<WGM31);
//	TCCR3B |= (1<<WGM32);
//	TCCR3B |= (1<<WGM33);
//
//	_freq = freq;
//	ICR3 = (F_CPU / 1024 / freq) - 1;
//}
//void Pwm_on(void)
//{
//	TCNT3 = 0;
//	// Preescaler 1024
//	TCCR3B |= (1 << CS30);
//	TCCR3B &=~(1 << CS31);
//	TCCR3B |= (1 << CS32);
//}
//void Pwm_off(void)
//{
//	TCCR3B &=~(1 << CS30);
//	TCCR3B &=~(1 << CS31);
//	TCCR3B &=~(1 << CS32);
//}
//void Pwm_SetDutyA(uint8_t duty)
//{
//	DDRE |= (1 << DDE3);
//	TCCR3A &= ~(1 << COM3A0);	// Modo no invertido
//	TCCR3A |= (1 << COM3A1);	// --
//
//	OCR3A = (((F_CPU / 1024 / _freq) - 1) * duty) / 100;
//}
//void Pwm_SetDutyB(uint8_t duty)
//{
//	DDRE |= (1 << DDE4);
//	TCCR3A &= ~(1 << COM3B0);	// Modo no invertido
//	TCCR3A |= (1 << COM3B1);	// --
//
//	OCR3B = (((F_CPU / 1024 / _freq) - 1) * duty) / 100;
//}
// End configuration //