/*
    Autor: Agustin 
    Fecha: 22/02/2021
    Programa: En este programa veremos el uso de software timer en freertos
*/

/*
    *Existen dos tipos de software timers: los auto reseteables (Auto-reload timers) y los que se ejecutan una sola vez (One-shot timers).
    *Cada vez que un timer finaliza ingresa a una funcion determinada llamada callback function.
    *Cuando los one-shot timers finalizan pasan a estado dormant o inactivos.
    *Una vez finalizado un one-shot timer puede ser reiniciado manualmente.
    *Para ejecutar diversos tipos de acciones con los timers, el usuario llama a funciones las cuales internamente son colas de datos
    que se usan para decir que hacer o ejecutar en cierto software timer.
    *Si el timer es iniciado antes que la vstartscheduler, este comenzera luego de que se llame a esta funcion.
*/

/* Incluimos librerias */
#include <Arduino_FreeRTOS.h>
#include <timers.h>
/* --SOFTWARE TIMERS-- */
/* Definiciones */
#define SoftTimer3333ms pdMS_TO_TICKS(3333)
#define SoftTimer500ms  pdMS_TO_TICKS(500)
/* Manipulador de timer */
TimerHandle_t   xTimerReseteable, xTimerUnico;
/* Callback functions */
static void prvTimerUnico(TimerHandle_t xTimer);
static void prvTimerReseteable(TimerHandle_t xTimer);

void setup()
{
    /* Serial */
    Serial.begin(9600);
    /* Led */
    pinMode(13,OUTPUT);
    /* FreeRTOS */
	BaseType_t xSoftTimer1Started, xSoftTimer2Started;

    xTimerUnico = xTimerCreate(
        "One-shotTimer",    // Nombre del timer para el usuario
        SoftTimer3333ms,    // Tiempo
        pdFALSE,            // Tipo de timer one-shot timer
        0,                  // Sin id
        prvTimerUnico       // Callback function
    );
    xTimerReseteable = xTimerCreate("AutoReload",SoftTimer500ms,pdTRUE,0,prvTimerReseteable);

    if((xTimerUnico!=NULL)&&(xTimerReseteable!=NULL))
    {
        xSoftTimer1Started = xTimerStart(xTimerUnico,0);
        xSoftTimer2Started = xTimerStart(xTimerReseteable,0);

        if((xSoftTimer1Started==pdPASS)&&(xSoftTimer2Started==pdPASS))  vTaskStartScheduler();
    }
}

void loop() {}

static void prvTimerUnico(TimerHandle_t xTimer)
{
    TickType_t xTimeNow;

    xTimeNow = xTaskGetTickCount();
    Serial.print("One-Shot timer:"),Serial.println(xTimeNow);
}

static void prvTimerReseteable(TimerHandle_t xTimer)
{
    TickType_t xTimeNow;
    
    xTimeNow = xTaskGetTickCount();
    Serial.print("AutoReload timer:"),Serial.println(xTimeNow);
    digitalWrite(13,!digitalRead(13));
}

