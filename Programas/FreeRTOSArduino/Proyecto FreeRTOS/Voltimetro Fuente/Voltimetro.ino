#include <LiquidCrystal.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <timers.h>

#define ADC0    A0
#define ADC1    A1
#define ADC2    A2
#define xDELAY100ms pdMS_TO_TICKS(100)
#define xDELAY1000ms pdMS_TO_TICKS(1000)
#define xDELAY2000ms pdMS_TO_TICKS(2000)
#define xDELAY500ms  pdMS_TO_TICKS(500)
#define xDELAY200ms  pdMS_TO_TICKS(200)
#define xDELAY5000ms pdMS_TO_TICKS(5000)

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal Lcd(rs, en, d4, d5, d6, d7);

// Tareas  de FreeRTOS //
void vTaskAdc(void *pvParameter);
void vTaskLcd(void *pvParameter);
static void prvSoftTimerLcdClear(TimerHandle_t xTimer);
void Lcd_WriteAdc0(void);
void Lcd_WriteAdc1(void);
void Lcd_WriteTotal(void);

// Variables para freertos //
typedef enum
{
	eAdc0,
	eAdc1,
    eAdc2
}DataSource_t;
typedef struct
{
	float ulValue;
	DataSource_t eDataSource;
}Data_t;
// End //

// Handlers //
QueueHandle_t xQueueAdc;
TimerHandle_t xTimerLcdClear;
TaskHandle_t xTaskAdc;
// End //

// Variables //
float adc0,adc1,adc2;
struct Adc
{
    char cAdc[10];
    uint8_t ucX;
    uint8_t ucY;
};
struct Adc Adc0 = {"+:",0,0};
struct Adc Adc1 = {"-:",0,1};
struct Adc Adc2 = {"Total:",10,0};

// Inicio programa //
void setup()
{
    // Creamos la cola de datos //
	xQueueAdc = xQueueCreate(3,sizeof(Data_t));
    if(xQueueAdc != NULL)
    {
        // Creamos la tarea que permite leer el adc //
        xTaskCreate(vTaskAdc, "LecturaAdc", 128, NULL, 1, &xTaskAdc);
    }
    // Creamos la tarea que permite escribir en el adc //
    xTaskCreate(vTaskLcd,"Lcd",128,NULL,2,NULL);
    // Creamos los software timers //
    xTimerLcdClear = xTimerCreate("LcdClear",xDELAY200ms,pdTRUE,0,prvSoftTimerLcdClear);

    // Iniciamos el planificador //
    if(xTimerLcdClear != NULL)
        vTaskStartScheduler();
}

void loop() {}

void vTaskAdc(void *pvParameter)
{
    (void) pvParameter;
    uint16_t usAdcRead;
    uint32_t ulAdcProm;
    float   fAdcReal;
    Data_t xStructAdcRead[3]
	{
		{0, eAdc0},
		{0, eAdc1},
        {0, eAdc2}
	};

    while (1)
    {
        /* code */
        // Lee el Adc0 //
        ulAdcProm = 0;
        for(uint16_t i=0;i<500;i++)
        {
            usAdcRead = analogRead(ADC0);
            ulAdcProm = ulAdcProm + usAdcRead;
        }
        fAdcReal = ulAdcProm / 500.0;
        xStructAdcRead[0].ulValue = (((fAdcReal * 5.0) / 1024.0) * 4.8)-0.145;
        xQueueSendToBack(xQueueAdc, &(xStructAdcRead[0]), xDELAY100ms);

        // Lee el Adc1 //
        ulAdcProm = 0;
        for(uint16_t i=0;i<500;i++)
        {
            usAdcRead = analogRead(ADC1);
            ulAdcProm = ulAdcProm + usAdcRead;
        }
        fAdcReal = ulAdcProm / 500.0;
        xStructAdcRead[1].ulValue = (((fAdcReal * 5.0) / 1024.0) * 4.8)-0.145;
        xQueueSendToBack(xQueueAdc, &(xStructAdcRead[1]), xDELAY100ms);

        // Envia el valor del Adc0 + el Adc1 //
        xStructAdcRead[2].ulValue = xStructAdcRead[0].ulValue + xStructAdcRead[1].ulValue;
        xQueueSendToBack(xQueueAdc, &(xStructAdcRead[2]), xDELAY100ms);

        vTaskDelay(xDELAY100ms);
    }
    vTaskDelete(NULL);
}

void vTaskLcd(void *pvParameter)
{
    (void) pvParameter;
    Data_t xStructReceiveAdc;
    BaseType_t xStatus;

    vTaskSuspend(xTaskAdc); // Detiene la tarea de lectura del adc

    // Inicializacion //
    Lcd.begin(16,2);
    Lcd.setCursor(0,0);
    Lcd.print("Fuente Regulable");
    Lcd.setCursor(4,1);
    Lcd.print("24V+24V");
    vTaskDelay(xDELAY1000ms);
    Lcd.clear();
    Lcd.setCursor(0,0);
    Lcd.print("Zuliani Agustin");
    Lcd.setCursor(0,1);
    Lcd.print("Colegio San Jose");
    vTaskDelay(xDELAY2000ms);
    Lcd.clear();

    vTaskResume(xTaskAdc);  // Reanuda la tarea del adc
    // Iniciamos el timer por software que limpia la pantalla //
    xTimerStart(xTimerLcdClear,0);

    while (1)
    {
        /* code */
        xStatus = xQueueReceive(xQueueAdc,&xStructReceiveAdc,portMAX_DELAY);
        if(xStatus == pdPASS)
        {
            // Actualiza los valores //
            if(xStructReceiveAdc.eDataSource == eAdc0)
            {
                adc0 = xStructReceiveAdc.ulValue;
            }
            if(xStructReceiveAdc.eDataSource == eAdc1)
            {
                adc1 = xStructReceiveAdc.ulValue;
            }
            if(xStructReceiveAdc.eDataSource == eAdc2)
            {
                adc2 = xStructReceiveAdc.ulValue;
            }
        }
        vTaskDelay(5);
    }
    vTaskDelete(NULL);
}

static void prvSoftTimerLcdClear(TimerHandle_t xTimer)
{
    Lcd.clear();
    // Carga los valores //
    Lcd_WriteAdc0();
    Lcd_WriteAdc1();
    Lcd_WriteTotal();
}

void Lcd_WriteAdc0(void)
{
    char buffer[20];

    dtostrf(adc0,2,2,buffer);
    Lcd.setCursor(Adc0.ucX,Adc0.ucY);
    Lcd.print(Adc0.cAdc),Lcd.print(buffer),Lcd.print("v");
}
void Lcd_WriteAdc1(void)
{
    char buffer[20];

    dtostrf(adc1,2,2,buffer);
    Lcd.setCursor(Adc1.ucX,Adc1.ucY);
    Lcd.print(Adc1.cAdc),Lcd.print(buffer),Lcd.print("v");
}
void Lcd_WriteTotal(void)
{
    char buffer[20];

    dtostrf(adc2,2,2,buffer);
    Lcd.setCursor(Adc2.ucX,Adc2.ucY);
    Lcd.print(Adc2.cAdc);
    Lcd.setCursor(Adc2.ucX,Adc2.ucY+1);
    Lcd.print(buffer),Lcd.print("v");
}