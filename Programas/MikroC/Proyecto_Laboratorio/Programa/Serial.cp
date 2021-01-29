#line 1 "C:/Users/aguat/OneDrive/Programacion Microcontroladores/Github/Programas/MikroC/Proyecto_Laboratorio/Programa/Serial.c"
#line 1 "c:/users/aguat/onedrive/programacion microcontroladores/github/programas/mikroc/proyecto_laboratorio/programa/serial.h"



extern volatile char Rx;
extern volatile bit echo;

void Serial_writeInit(void);
void Reception(void);
void Echo_Tx(void);
#line 3 "C:/Users/aguat/OneDrive/Programacion Microcontroladores/Github/Programas/MikroC/Proyecto_Laboratorio/Programa/Serial.c"
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
 echo = 1;

 return;
}

void Echo_Tx(void)
{
 UART1_Write(Rx);

 return;
}
