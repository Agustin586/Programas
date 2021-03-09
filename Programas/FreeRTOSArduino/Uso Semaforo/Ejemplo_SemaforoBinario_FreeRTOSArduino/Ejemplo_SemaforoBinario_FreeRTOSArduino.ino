#include <Arduino_FreeRTOS.h>
#include <semphr.h>

/*FreRTOS*/
// Semaforo //
SemaphoreHandle_t Int0_SmphBnr;
// Tareas //
void vTaskInt0(void *pvParameter);
void vTaskBlink(void *pvParameter);
// Interrupcion //
void Int0(void);

void setup() {
  /*Serial*/
  Serial.begin(9600);
  /*FreeRTOS*/
  //Tareas//
  xTaskCreate(vTaskInt0,"Interupcion0",128,NULL,configMAX_PRIORITIES,NULL);
  xTaskCreate(vTaskBlink,"Blink",128,NULL,1,NULL);

  //Semaforo//
  Int0_SmphBnr = xSemaphoreCreateBinary();
  if(Int0_SmphBnr != NULL)
  {
    attachInterrupt(digitalPinToInterrupt(2), Int0, FALLING);
  }

  // Inicia el planificador //
  vTaskStartScheduler();
}

void loop() {}

////////////////////////////////////////////////////////////////////
/* Tareas */
void vTaskBlink(void *pvParameter)
{
  (void) pvParameter;

  TickType_t Delay500ms=pdMS_TO_TICKS(500);

  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);

  while (1)
  {
    /* code */
    digitalWrite(13,!digitalRead(13));
    vTaskDelay(Delay500ms);
  }
  vTaskDelete(NULL);
}
////////////////////////////////////////////////////////////////////

/* Funcion de Interrupcion */
void vTaskInt0(void *pvParameter)
{
  (void) pvParameter;
  TickType_t Delay30ms=pdMS_TO_TICKS(30);

  while (1)
  {
    /* code */
    if(xSemaphoreTake(Int0_SmphBnr,portMAX_DELAY)==pdPASS)
    {
      Serial.println("Interrupcion 0");
      while(digitalRead(2)==HIGH) vTaskDelay(Delay30ms);
    }
  }
  vTaskDelete(NULL);
}

void Int0(void)
{
  // Da en semaforo // 
  xSemaphoreGiveFromISR(Int0_SmphBnr,NULL);
}
////////////////////////////////////////////////////////////////////

