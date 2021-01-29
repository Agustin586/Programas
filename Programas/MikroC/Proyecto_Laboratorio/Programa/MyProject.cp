#line 1 "C:/Users/aguat/OneDrive/Programacion Microcontroladores/Github/Programas/MikroC/Proyecto_Laboratorio/Programa/MyProject.c"
#line 1 "c:/users/aguat/onedrive/programacion microcontroladores/github/programas/mikroc/proyecto_laboratorio/programa/mef.h"
#line 1 "c:/users/aguat/onedrive/programacion microcontroladores/github/programas/mikroc/proyecto_laboratorio/programa/serial.h"



extern volatile char Rx;

void Serial_writeInit(void);
void Reception(void);

void Serial_writeInit(void)
{
 UART_Write_Text("Programa: Control de Reles y Salidas");
 UART_Write_Text("Autor: Zuliani,Agustin");
 UART_Write_Text("Fecha Inicio: 11/1/2021");
 UART_Write_Text("Descripcion: Controla salida a Reles, una salida a Triac y demas");

 return;
}

void Reception(void)
{
 Rx = UART_Read();
 UART_Write(Rx);

 return;
}
#line 6 "c:/users/aguat/onedrive/programacion microcontroladores/github/programas/mikroc/proyecto_laboratorio/programa/mef.h"
void Mef_init(void);
void Mef_Updated(void);
#line 3 "C:/Users/aguat/OneDrive/Programacion Microcontroladores/Github/Programas/MikroC/Proyecto_Laboratorio/Programa/MyProject.c"
volatile char Rx;

void Interrupt_init(void);

void main()
{
 ADCON1 = 0x0F;

 UART1_Init(56800);
 Mef_init();


 while(1)
 {
 Mef_Updated();
 }
}

void Interrupt_init(void)
{
 GIE_bit = 1;
 IPEN_bit = 1;
 PEIE_bit = 1;


 RCIF_bit = 0;
 RCIE_bit = 1;
 RCIP_bit = 1;


 return;
}

void ISR_HP() iv 0x0008 ics ICS_AUTO
{
 if(RCIF_bit==1)
 {
 RCIF_bit = 0;
 Reception();

 }

 return;
}

void ISR_LP() iv 0x0018 ics ICS_AUTO
{

}
