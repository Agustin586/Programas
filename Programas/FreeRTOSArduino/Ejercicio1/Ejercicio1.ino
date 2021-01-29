/*
 Name:    EjercicioN1_FreeRTOSArduino.ino
 Created: 29/01/2021 1:48:51
 Author:  Agustin
 Description: Este programa consiste en utilizar freertos,
              para esto vamos a crear 3 tareas. La primera consiste
              en hacer un blink con un led a una frecuencia de 100hz.
              La segunda tarea lee un pulsador y prende un led.
              La tercera tarea lee las cantidad de pulsaciones y prende y 
              apaga otro led la cantidad esta.
*/


// Hardware //
/*
    Led 1:
        Función: Blink a 100hz (10ms) con 50% duty 
        Pin: 13
    Led 2:
        Función: Prender cuando el se detecte el pulsador 1
        Pin: 12
    Led 3: 
        Función: Destellar la cantidad de veces pulsado 
        el pulsador 2
        Pin: 11

    Pulsador 1:
        Función: Prender el led 2
        Pin: 10
    Pulsador 2:
        Función: Detectar la cantidad de veces pulsado y mostrarlo
        en el led 3
        Pin: 9
*/

// Includes //
#include <Arduino_FreeRTOS.h>

// Defines //
#define LED1_PIN    13
#define LED2_PIN    12
#define LED3_PIN    11
#define PULSADOR1_PIN   10
#define PULSADOR2_PIN   9

// Task Prototypes //
void Task_Create(void);
void Task_Blink100Hz(void* pvParameter);
void Task_Led2(void* pvParameter);
void Task_Led3(void* pvParameter);
// End //

// Functions //
void Antirrebote(void);
// End //

// Variables //
typedef enum
{
    EST_WAITtoPULSE,
    EST_CONT,
    EST_DISPLAY,
}EstateTaskLed3_t;
EstateTaskLed3_t ActualEstate_TaskLed3;
// End //

// the setup function runs once when you press reset or power the board
void setup()
{
    // Create a task for rtos
    Task_Create();
    vTaskStartScheduler();
}

// the loop function runs over and over again until power down or reset
void loop() {}

void Task_Create(void)
{
    xTaskCreate(
        Task_Blink100Hz,
        "Blink 100Hz",
        128,
        NULL,
        2,
        NULL
    );
    xTaskCreate(
        Task_Led2,
        "Led off_on",
        128,
        NULL,
        1,
        NULL
    );
    xTaskCreate(
        Task_Led3,
        "Led signal",
        240,
        NULL,
        1,
        NULL
    );
}

void Task_Blink100Hz(void* pvParameter)
{
    (void) pvParameter;
    pinMode(LED1_PIN, OUTPUT);
    digitalWrite(LED1_PIN, LOW);

    while (1)
    {
        digitalWrite(LED1_PIN,!digitalRead(LED1_PIN));
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void Task_Led2(void* pvParameter)
{
    (void) pvParameter;
    pinMode(LED2_PIN, OUTPUT);
    pinMode(PULSADOR1_PIN, INPUT);

    while (1)
    {
        if (digitalRead(PULSADOR1_PIN) == HIGH)
        {
            digitalWrite(LED2_PIN, HIGH);
            Antirrebote();
        }
        else
        {
            digitalWrite(LED2_PIN, LOW);
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void Task_Led3(void* pvParameter)
{
    (void)pvParameter;

    static uint8_t uCont = 0;
    uint16_t usSeg = 0;
    bool bEndTime = false, bEnableTime = false;

    pinMode(LED3_PIN, OUTPUT);
    pinMode(PULSADOR2_PIN, INPUT);
    digitalWrite(LED3_PIN, LOW);

    while (1)
    {
        switch (ActualEstate_TaskLed3)
        {
            case EST_WAITtoPULSE:
            {
                usSeg = 0, uCont = 0;
                bEnableTime = false, bEndTime = false;
                digitalWrite(LED3_PIN, LOW);

                if (digitalRead(PULSADOR2_PIN) == HIGH)    ActualEstate_TaskLed3 = EST_CONT;
                break;
            }
            case EST_CONT:
            {
                if (digitalRead(PULSADOR2_PIN) == HIGH)    uCont++, digitalWrite(LED3_PIN, HIGH), Antirrebote();
                else                                       digitalWrite(LED3_PIN, LOW);

                vTaskDelay(30 / portTICK_PERIOD_MS);
                //vTaskDelay(1); son 15ms
                usSeg += 30;

                if (usSeg == 3000)   ActualEstate_TaskLed3 = EST_DISPLAY;
                break;
            }
            case EST_DISPLAY:
            {
                for (uint8_t i = uCont; i > 0; i--)
                {
                    digitalWrite(LED3_PIN, !digitalRead(LED3_PIN));
                    vTaskDelay(pdMS_TO_TICKS(500));
                }

                ActualEstate_TaskLed3 = EST_WAITtoPULSE;
                break;
            }
        }
    }
}

void Antirrebote(void)
{
    vTaskDelay(pdMS_TO_TICKS(30));
    if(digitalRead(PULSADOR1_PIN)==HIGH || digitalRead(PULSADOR2_PIN)==HIGH) vTaskDelay(pdMS_TO_TICKS(50));
}

/*
    Nota: Usar delays y esperar menos que el tiempo del tick, en este caso 15ms, hace que haga cualquier cosa el delay
    y en vez de esperar los correspondientes por ejemplo 1ms, son mucho menos de esos, es por esto que para que el delay funcione
    correctamente debe ser mayor o igual a 15ms, o mejor dicho mayor o igual al tick interrupt.
*/
