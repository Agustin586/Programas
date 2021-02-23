/*
    Autor: Agustin
    Fehca: 22/02/2021
    Programa: Utilizaremos software timers y trabajeremos con las id de ellos.
*/

/* Librerias */
#include <Arduino_FreeRTOS.h>
#include <timers.h>

/* --SOFTWARE TIMERS-- */
/* Definiciones */
#define DELAY_200MS  pdMS_TO_TICKS(200)
#define DELAY_3S     pdMS_TO_TICKS(3000)
/* Manipulador de software timers */
TimerHandle_t   xTimer200ms, xTimer3s;
/* Callback fucntion */
static void prvTimerReady(TimerHandle_t xTimer);
/* Variables */
uint8_t ucContadorFinTimer200ms=0;

void setup()
{
	/* Serial */
    Serial.begin(9600);

    /* Led */
    pinMode(13,OUTPUT);

    /* FreeRTOS */
    // Crea timers //
    xTimer200ms = xTimerCreate("Timer200ms",DELAY_200MS,pdTRUE,0,prvTimerReady);
    xTimer3s = xTimerCreate("Timer3s",DELAY_3S,pdFALSE,0,prvTimerReady);
    // Inicia los timers //
    xTimerStart(xTimer200ms,0);
    xTimerStart(xTimer3s,0);
    // Inicia el kernel //
    vTaskStartScheduler();
}

void loop() {}

static void prvTimerReady(TimerHandle_t xTimer)
{
    TickType_t xTimeNow;
    uint32_t ulExecution;

    ulExecution = (uint32_t) pvTimerGetTimerID(xTimer); // Obtiene el id del timer que ingresa o finaliza
    vTimerSetTimerID(xTimer, (void *) ulExecution);

    xTimeNow = xTaskGetTickCount();

    if(xTimer == xTimer200ms)
    {
        digitalWrite(13,!digitalRead(13));
        Serial.print("Timer 200ms ticks:"),Serial.println(xTimeNow);

        ucContadorFinTimer200ms++;
        if(ucContadorFinTimer200ms == 5)    
        {
            xTimerStop(xTimer,0);
        }
    }
    else if(xTimer == xTimer3s)
    {
        Serial.print("Timer 3s ticks:"),Serial.println(xTimeNow);
    }
}