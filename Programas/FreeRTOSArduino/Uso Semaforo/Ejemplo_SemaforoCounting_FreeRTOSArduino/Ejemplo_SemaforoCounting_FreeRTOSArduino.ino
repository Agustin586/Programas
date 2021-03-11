#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include "UART_INTERRUPT.h"

// FREERTOS definiciones //
/* Semaforo Handle */
SemaphoreHandle_t CoutingSemaphore;
/* Task and Interrupt task */
void vTaskBlink(void *pvParameter);
void vISR_RX0(void *pvParameter);
void ISR_RX0(void);
/* Definiciones */
#define DELAY500ms  pdMS_TO_TICKS(500)
#define LEDBLINK    13
// Fin FREERTOS definiciones //

void setup()
{
    // Inicalizacion de Apis de FreeRTOS//
    xTaskCreate(vTaskBlink,"Blink",128,NULL,1,NULL);
    CoutingSemaphore = xSemaphoreCreateCounting(10,0);
    if(CoutingSemaphore != NULL)
    {
        xTaskCreate(vISR_RX0,"Interrupcion0",128,NULL,configMAX_PRIORITIES,NULL);
        USART_Init(MYUBRR);
    }
}

void loop() {}

void vTaskBlink(void *pvParameter)
{
    (void) pvParameter;
    TickType_t xLastWakeTime;

    pinMode(LEDBLINK,OUTPUT);
    digitalWrite(LEDBLINK,LOW);
    xLastWakeTime = xTaskGetTickCount();

    while (1)
    {
        /* code */
        digitalWrite(LEDBLINK,!digitalRead(LEDBLINK));
        xTaskDelayUntil(&xLastWakeTime, DELAY500ms);
    }
    vTaskDelete(NULL);
}

void vISR_RX0(void *pvParameter)
{
    (void) pvParameter;

    while (1)
    {
        /* code */
        if(xSemaphoreTake(CoutingSemaphore,DELAY500ms)==pdPASS)
        {
            Uart_println("Interrupcion por RX0");
        }
    }
    vTaskDelete(NULL);
}

void ISR_RX0(void)
{
    // Da los semaforos //
    xSemaphoreGiveFromISR(CoutingSemaphore,NULL);
    xSemaphoreGiveFromISR(CoutingSemaphore,NULL);   /* Simula las multiples interrupciones */
    xSemaphoreGiveFromISR(CoutingSemaphore,NULL);
}