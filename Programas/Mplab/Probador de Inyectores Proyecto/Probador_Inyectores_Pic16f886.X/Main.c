#define INICIO      PORTBbits.RB0
#define ENTER       PORTBbits.RB1
#define DETENER     PORTBbits.RB2
#define MOVER       PORTBbits.RB3
#define BUZZER      PORTAbits.RA5

#define TICKS_T1    200   // Cada 20ms cambia de estado
#define TICKS_PANT  700   // Cada 70ms escribe en la pantalla
#define TICKS_T2    200   // Cada 20ms ingresa a tarea 2
#define TICKS_T4    400   // Cada 40ms

#include "Configuracion_Bits.h"
#include "MEF.h"
#include <stdio.h>

void Pines_Init(void);
void Antirrebote(void);

////////////////////////////////////////////////////////////////////////////////
void main(void)
{   
    //Inicializaciones
    Pines_Init();
    Mef_Init();
    
    //Habilita el watch dog
    WDTCONbits.SWDTEN = 1;
    WDTCONbits.WDTPS  = 0b1010;     // Preescaler de wdt 1:32768 --> timer = 32768 / 32Khz ~= 1 segundo
    CLRWDT();
    
    TMR1IE=1,TMR1IF=1;      // Activa la interrupcion de tmr1
    
    while(1)
    {
        Mef_Updated(); 
    }

    return;
}
////////////////////////////////////////////////////////////////////////////////
void Pines_Init(void)
{
    //Configuraciones de Entradas y Salidas
    TRISAbits.TRISA5 = 0;
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    TRISB = 0xFF;                       // Port B how to input
    TRISC = 0x00;                       // Port C how to output
    ANSELHbits.ANS12 = 0;               // Setting RB0 how to a digital input
    ANSELHbits.ANS11 = 0;               // Setea como digital
    ANSELHbits.ANS10 = 0;               // Setting RB1 how to a digital input
    ANSELHbits.ANS8 = 0;                // Setting RB2 how to a diigtla input
    ANSELHbits.ANS9 = 0;                // Setting RB3 how to a diigtla input
    ANSELbits.ANS4  = 0;
    
    ANS13 = 0;
    TRISB5 = 0;
    RB5 = 0;
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Antirrebote(void)
{
    __delay_ms(10);
    while(INICIO || ENTER || DETENER || MOVER)  __delay_ms(10);
    
    return;
}
////////////////////////////////////////////////////////////////////////////////