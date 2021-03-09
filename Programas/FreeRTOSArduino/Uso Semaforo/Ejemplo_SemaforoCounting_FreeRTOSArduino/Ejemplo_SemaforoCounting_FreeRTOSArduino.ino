#include <Arduino_FreeRTOS.h>
#include <semphr.h>

// FREERTOS definiciones //
/* Semaforo Handle */
SemaphoreHandle_t CoutingSemaphore;
/* Task and Interrupt task */
void vTaskBlink(void *pvParameter);
void vISRInt0(void *pvParameter);
void Int0(void);
/* Definiciones */
#define DELAY500ms  pdMS_TO_TICKS(500)
#define LEDBLINK    13
// Fin FREERTOS definiciones //

void setup()
{
    // Inicializacion del puerto serie //
    Serial.begin(115200);
    // Inicalizacion de Apis de FreeRTOS//
    xTaskCreate(vTaskBlink,"Blink",128,NULL,1,NULL);
    CoutingSemaphore = xSemaphoreCreateCounting(10,0);
    if(CoutingSemaphore != NULL)
    {
        xTaskCreate(vISRInt0,"Interrupcion0",128,NULL,configMAX_PRIORITIES,NULL);
        attachInterrupt(digitalPinToInterrupt(2), Int0, FALLING);
    }
}

void loop() {}

void vTaskBlink(void *pvParameter)
{
    (void) pvParameter;

    pinMode(LEDBLINK,OUTPUT);
    digitalWrite(LEDBLINK,LOW);

    while (1)
    {
        /* code */
        digitalWrite(LEDBLINK,!digitalRead(LEDBLINK));
        vTaskDelay(DELAY500ms);
    }
    vTaskDelete(NULL);
}

void vISRInt0(void *pvParameter)
{
    (void) pvParameter;

    while (1)
    {
        /* code */
        if(xSemaphoreTake(CoutingSemaphore,DELAY500ms)==pdPASS)
        {
            if()
        }
    }
    vTaskDelete(NULL);
}

void Int0(void)
{
    // Da los semaforos //
    xSemaphoreGiveFromISR(CoutingSemaphore,NULL);
    xSemaphoreGiveFromISR(CoutingSemaphore,NULL);   /* Simula las multiples interrupciones */
    xSemaphoreGiveFromISR(CoutingSemaphore,NULL);
}