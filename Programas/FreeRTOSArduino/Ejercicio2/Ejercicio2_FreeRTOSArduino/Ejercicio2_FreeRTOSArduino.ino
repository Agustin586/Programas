/*
	Date: 30/01/2021
	Author: Agustin 
	Programa: En este programa utilizaremos las siguiente caracteristicas:
					* Suspender una tarea
					* Resumir o reanurar una tarea
					* Utilizar DelayUntil
					* Comunicar con vPrintString (si es posible en arduino sino utilizaremos Serial.println)
					* Mandar una cadena como parametro a una tarea
					* Utilizaremos la Idle Task Hook
					* Obtendremos la prioridad de una tarea
					* Modificaremos la prioridad de una tarea
					* Borrar una tarea
	Consigna:	La 1ra tarea consiste en hacer un blink lo mas exacto posible utilizando el delayuntil.
				La 2da tarea leera el serial para poder suspender o reanurar la tarea 1; obtener,cambiar la prioridad o borrar la tarea 3.
				La 3ra tarea leera una entrada analogica cada 50ms.
				La 4ta tarea mostrara por un lcd el valor que se va sumando en la tarea idle hook.
*/

// Defines //
#define LED_BLINK_PIN	13
#define ANALOG_PIN		A0
// End //

// --Includes-- //
#include <LiquidCrystal.h>
#include <Arduino_FreeRTOS.h>
// --End-- //

// Clases //
const int rs = 36, en = 37, d4 = 38, d5 = 39, d6 = 46, d7 = 47;
LiquidCrystal Lcd(rs, en, d4, d5, d6, d7);
TaskHandle_t xTask3Handle;
// End //

// Task for freertos //
void vTask1(void* pvParameter);
void vTask2(void* pvParameter);
void vTask3(void* pvParameter);
void vTask4(void* pvParameter);
void vApplicationIdleHook(void);
// End //

// Variables for FreeRTOS //
volatile uint32_t ulIdleCycleCount = 0;
static const char* pcTextForTask3 = "Task 3 is running \n";
static const char* pcTextForTask4 = "Task4:HelloWorld";
float ulVoltage = 0;
// End // 

void setup() 
{
	Serial.begin(9600);

	xTaskCreate(
		vTask1
		, "Blink"
		, 128
		, NULL
		, 2
		, NULL);
	xTaskCreate(
		vTask2
		, "UseSerial"
		, 128
		, NULL
		, 1
		, NULL);
	xTaskCreate(
		vTask3
		, "Adc"   
		, 128  
		, (void*)pcTextForTask3
		, 1  
		, &xTask3Handle);
	xTaskCreate(
		vTask4
		, "Lcd"
		, 128
		, (void*)pcTextForTask4
		, 1
		, NULL);

	vTaskStartScheduler();
}

void loop() {}

// *** Tasks *** //
void vTask1(void* pvParameter)
{
	(void)pvParameter;

	TickType_t xLastWakeTime;
	const TickType_t xDelay500ms = pdMS_TO_TICKS(500);

	xLastWakeTime = xTaskGetTickCount();
	pinMode(LED_BLINK_PIN, OUTPUT);
	digitalWrite(LED_BLINK_PIN, LOW);

	while (1)
	{
		digitalWrite(LED_BLINK_PIN, !digitalRead(LED_BLINK_PIN));
		xTaskDelayUntil(&xLastWakeTime, xDelay500ms);
	}
	vTaskDelete(NULL);
}
void vTask2(void* pvParameter)
{
	(void)pvParameter;
	
	char cSerialBuffer[20],cSerialRead;
	const TickType_t xDelay10ms = pdMS_TO_TICKS(10);
	UBaseType_t uxPriority;
	uint8_t index = 0, action = 0;
	
	while (1)
	{
		while (cSerialBuffer[index] != 13)
		{
			if (Serial.available())
			{
				cSerialRead = Serial.read();
				cSerialBuffer[index] = cSerialRead;
				if(cSerialRead != 13)	index++;
			}
			vTaskDelay(1);
		}

		cSerialBuffer[index] = 0;	// Clear value 13

		if (strcmp(cSerialBuffer, "Suspend") == 0) action = 1;
		else if (strcmp(cSerialBuffer, "Resume") == 0) action = 2;
		else if (strcmp(cSerialBuffer, "Delete") == 0) action = 3;
		else if (strcmp(cSerialBuffer, "GetPriority") == 0) action = 4;
		else if (strcmp(cSerialBuffer, "SetPriority") == 0) action = 5;
		else if (strcmp(cSerialBuffer, "Create") == 0) action = 6;

		switch (action)
		{
			case 1:
			{
				Serial.println("");
				Serial.println("cmd > Task 3 suspend");
				vTaskSuspend(xTask3Handle);
				
				break;
			}
			case 2:
			{
				Serial.println("");
				Serial.println("cmd > Task 3 resume");
				vTaskResume(xTask3Handle);

				break;
			}
			case 3:
			{
				Serial.println("");
				Serial.println("cmd > Task 3 delete");
				vTaskDelete(xTask3Handle);

				break;
			}
			case 4:
			{
				Serial.println("");
				Serial.print("cmd > Task 3 priority:");
				uxPriority = uxTaskPriorityGet(xTask3Handle);
				Serial.println(uxPriority);

				break;
			}
			case 5:
			{
				bool bReceived = false;

				Serial.println("");
				Serial.print("cmd > Task 3 value:");
				while (bReceived == false)
				{
					if (Serial.available())
					{
						cSerialRead = Serial.read();
						Serial.write(cSerialRead);
						bReceived = true;
					}
				}
				vTaskPrioritySet(xTask3Handle, cSerialRead - 48);

				break;
			}
			case 6:
			{
				Serial.println("");
				Serial.println("cmd > Task 3 create");

				xTaskCreate(
					vTask3
					, "Adc"
					, 128
					, (void*)pcTextForTask3
					, 1
					, &xTask3Handle);

				break;
			}
			case 0:
			{
				break;
			}
		}

		for (uint8_t i = 0; i < index; i++)
		{
			cSerialBuffer[i] = 0;
		}
		index = 0;
		action = 0;

		vTaskDelay(xDelay10ms);
	}
	vTaskDelete(NULL);
}
void vTask3(void* pvParameter)
{
	(void)pvParameter;

	char* pcTaskName;
	const TickType_t xDelay100ms = pdMS_TO_TICKS(100);
		  TickType_t xAnalogRead=0;
	pcTaskName = (char *)pvParameter;

	while (1)
	{
		xAnalogRead = analogRead(ANALOG_PIN);
		ulVoltage = (5.0 * xAnalogRead / 1024.0);

		vTaskDelay(xDelay100ms);
	}
	vTaskDelete(NULL);
}
void vTask4(void* pvParameter)
{
	(void)pvParameter;

	char* pcTaskName;
	const TickType_t xDelay20ms = pdMS_TO_TICKS(20);
	const TickType_t xDelay2s = pdMS_TO_TICKS(2000);
	pcTaskName = (char*)pvParameter;

	Lcd.begin(16,2);
	Lcd.setCursor(0,0);
	Lcd.print(pcTaskName);
	vTaskDelay(xDelay2s);
	Lcd.clear();

	while (1)
	{
		Lcd.setCursor(0, 0);
		Lcd.print(ulIdleCycleCount);
		Lcd.setCursor(0, 1);
		Lcd.print(ulVoltage),Lcd.print("V");
		
		vTaskDelay(xDelay20ms);
	}
	vTaskDelete(NULL);
}
void vApplicationIdleHook(void)
{
	ulIdleCycleCount++;
}
// *** End Tasks *** //
