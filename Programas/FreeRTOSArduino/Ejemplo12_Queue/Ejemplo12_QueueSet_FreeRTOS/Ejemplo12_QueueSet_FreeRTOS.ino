/*
    Autor: Agustin
    Fecha: 12/02/21
    Programa: Ejemplo 12 de manejo de cola de datos en un conjunto de cola de datos.
*/

// Includes //
#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <semphr.h>
// Fin //

// Variables de tipo QueueHandler_t y QueueSetHanler_t //
QueueHandle_t xQueue1,xQueue2;   // Se declaran dos colas de datos queue1 y queue2
QueueSetHandle_t xQueueSet;      // En este conjunto de colas se almacenan las colas de datos y semaforos
// SemaphoreHandle_t xBinarySemaphore;
// Fin //

// Tareas //
void vTaskSender1(void *pvParameter);
void vTaskSender2(void *pvParameter);
void vTaskReceive(void *pvParameter);
void vTaskBlink(void *pvParameter);
// Fin //

void setup()
{
    BaseType_t xStatus1,xStatus2;

    /* Inicializamos el puerto serial */
    Serial.begin(9600);
    Serial.println("Inicializando");

    /*
        Nota: se debe habilitar configUSE_QUEUE_SETS en 1, para poder utilizar el conjunto de colas de datos (esta en 0 por defecto)
    */

    /* Creamos las dos colas de datos */
    xQueue1 = xQueueCreate(1,sizeof(char*));
    xQueue2 = xQueueCreate(1,sizeof(uint16_t));

    /* Creamos el conjuto de cola de datos */
    xQueueSet = xQueueCreateSet(1+1);   // xQueue1 = 1 espacio y xQueue2 = 1 espacio --> Total espacios = 1 + 1 = 2   

    /* Añadimos las colas de datos al conjunto */
    xStatus1 = xQueueAddToSet(xQueue1,xQueueSet);  // Se añade la cola 1 al conjunto
    if (xStatus1 == pdPASS) Serial.println("Cola 1 aniadido correctamente");
    xStatus2 = xQueueAddToSet(xQueue2,xQueueSet);  // se añade la cola 2 al conjunto
    if (xStatus2 == pdPASS) Serial.println("Cola 2 aniadida correctamente");

    if (xQueueSet != NULL && xQueue1 != NULL && xQueue2 != NULL)
    {
        /* Creamos las tareas */
        xTaskCreate(
            vTaskSender1    // Nombre de la tarea como funcion
            ,"Emisor1"      // Nombre de la tarea para el usuario
            ,128            // Ram asignada
            ,NULL           // No se envia ningun parametro
            ,1              // Prioridad
            ,NULL);         // No utilizamos el manipulador de tareas
        xTaskCreate(vTaskSender2,"Emisor2",128,NULL,1,NULL);
        xTaskCreate(vTaskReceive,"Receptor",128,NULL,2,NULL);

        Serial.println("Todo creado correctamente");
    }
    xTaskCreate(vTaskBlink,"Blink",128,NULL,1,NULL);
    
    /* Inicia el planificador */
    vTaskStartScheduler();  
}

void loop() {}

void vTaskSender1(void *pvParameter)
{
    (void) pvParameter;
    const TickType_t xDelay300ms = pdMS_TO_TICKS(300);          // Delay para el vtaskdelay
    const char * pcMensaje1 = "Mensaje desde Emisor 1\r\n";     // Mensaje desde el emisor 1

    while (1)
    {
        vTaskDelay(xDelay300ms);    // Espera 300ms luego de enviar o no el dato
        /* Envia datos a la cola 1 */
        xQueueSend(xQueue1,&pcMensaje1,0);
    }

    vTaskDelete(NULL);
}
void vTaskSender2(void *pvParameter)
{
    (void) pvParameter;
    const TickType_t xDelay400ms = pdMS_TO_TICKS(400);      // Delay para el vtaskdelay
    uint32_t ulCount=0;                                     // Variable de 32 bits

    while (1)
    {
        vTaskDelay(xDelay400ms);            // Espera 400ms
        xQueueSend(xQueue2,&ulCount,0);     // Envia el dato de la variable contador   
        ulCount++;                          // Suma el contador
    }

    vTaskDelete(NULL);
}
void vTaskReceive(void *pvParameter)
{
    (void) pvParameter;
    QueueSetMemberHandle_t xQueueSelecionada;           // Crea un variable de tipo miembro del conjunto de la cola de datos
    const TickType_t xDelay100ms = pdMS_TO_TICKS(100);  // 100ms
    uint32_t ulCount=0;                                          
    char * pcMensajeRecivido;
    bool PrintCount=false;                              // Permite imprimir el contador o la cadena

    while (1)
    {
        xQueueSelecionada = xQueueSelectFromSet(xQueueSet,xDelay100ms);

        if (xQueueSelecionada == (QueueSetMemberHandle_t) xQueue1)
        {
            xQueueReceive(xQueue1,&pcMensajeRecivido,0);
            // if (*pcMensajeRecivido == '\n') PrintCount=true;
            Serial.print(pcMensajeRecivido);  
        }
        if (xQueueSelecionada == (QueueSetMemberHandle_t) xQueue2)
        {
            xQueueReceive(xQueue2,&ulCount,0);
            Serial.print(ulCount),Serial.print("\r\n");
            // if (PrintCount==true) Serial.print(ulCount),PrintCount=false;
        }
        else if (xQueueSelecionada == NULL)
        {
            /* Accion cuando nada es seleccionado */
            // Serial.println("Nada enviado");
        }

        vTaskDelay(pdMS_TO_TICKS(50));
    }

    vTaskDelete(NULL);
}
void vTaskBlink(void *pvParameter)
{
    (void) pvParameter;
    TickType_t xLastWakeTime;
    const TickType_t xDelay500ms = pdMS_TO_TICKS(500);

    pinMode(13,OUTPUT);
    xLastWakeTime = xTaskGetTickCount();

    while (1)
    {
        digitalWrite(13,!digitalRead(13));
        xTaskDelayUntil(&xLastWakeTime, xDelay500ms);
    }
    
    vTaskDelete(NULL);
}