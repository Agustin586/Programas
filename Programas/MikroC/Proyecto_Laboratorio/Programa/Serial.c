#include "Serial.h"

void Serial_writeInit(void)
{
   UART1_Write_Text("Programa: Control de Reles y Salidas");
   UART1_Write_Text("Autor: Zuliani,Agustin");
   UART1_Write_Text("Fecha Inicio: 11/1/2021");
   UART1_Write_Text("Descripcion: Controla salida a Reles, una salida a Triac y demas");

   return;
}

void Reception(void)
{
   Rx = UART1_Read();
   echo = 1;      // Echo

   return;
}

void Echo_Tx(void)
{
   UART1_Write(Rx);

   return;
}