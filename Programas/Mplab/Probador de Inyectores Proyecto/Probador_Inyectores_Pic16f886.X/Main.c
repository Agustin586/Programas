#include "Configuracion_Bits.h"
#include "MEF.h"
#include <stdio.h>

#define INICIO      PORTBbits.RB0
#define ENTER       PORTBbits.RB1
#define DETENER     PORTBbits.RB2
#define MOVER       PORTBbits.RB3
#define BUZZER      PORTAbits.RA5

#define TICKS_T1                200   // Cada 20ms cambia de estado
#define TICKS_DELAY100ms        1000  // Cada 100ms escribe en la pantalla
#define TICKS_DELAY500ms        2000  // Cada 200ms limpia el watch dog y actualizar variables en lcd
#define TICKS_T2                200   // Cada 20ms ingresa a tarea 2
#define TICKS_T4                400   // Cada 40ms

#define Pin_Init    Pines_Init

void Pines_Init(void);
void Antirrebote(void);
void Task_Ready(void);
void __interrupt () ISR (void);

unsigned char Modo=0,Pwm=0,Min=0,Seg=0,Temp=0; 
_Bool Mostrar=0,Act_Variables=0,mod_tiempo=0;
volatile unsigned int Delay100ms=TICKS_DELAY100ms,Delay500ms=TICKS_DELAY500ms;
unsigned int Rpm=0;

////////////////////////////////////////////////////////////////////////////////
void main(void)
{   
    //Inicializaciones
    Pin_Init();
    Mef_Init();
    Lcd_Init();
    Timer1_Init();
    Adc_Init();
    
    TMR1IE=1,TMR1IF=1;      // Activa la interrupcion de tmr1
    
    WDTCONbits.SWDTEN = 1;          //Habilita el watch dog
    WDTCONbits.WDTPS  = 0b1010;     // Preescaler de wdt 1:32768 --> timer = 32768 / 32Khz ~= 1 segundo
    
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
    ANSELbits.ANS4  = 0;                // Setting how to digital input
    
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
void __interrupt () ISR (void)
{
    //Interrupcion por timer 0 
    if(TMR1IF == 1)
    {
        if(Delay100ms!=0 && !Mostrar)       Delay100ms--;    // Temporizador de muestra del display 
        if(Delay500ms!=0)                   Delay500ms--;    // Limpia el wdt y actualiza variables del lcd
        
        
        TMR1 = 65285;     // 100us
        TMR1ON = 1;
        TMR1IF = 0;       // Limpia la bandera de desborde
    }
    
    if(!Delay100ms || !Delay500ms)          Task_Ready();
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Task_Ready(void)
{
    if(!Delay100ms)
    {
        Mostrar = 1;
        Delay100ms = TICKS_DELAY100ms;
    }
    if(!Delay500ms)
    {
        CLRWDT();
        Act_Variables = 1;
        Delay500ms = TICKS_DELAY500ms;
    }
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
