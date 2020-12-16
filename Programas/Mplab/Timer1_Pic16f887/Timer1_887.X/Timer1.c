#include "Configuracion_Bits.h"
#include "Timer1.h"

extern volatile unsigned long Delay;
extern unsigned long Tiempo;

////////////////////////////////////////////////////////////////////////////////
void Timer1_Init(void)
{
    //Configuracion Timer1
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1CKPS = 0b11;    //Preescaler 1:8
    T1CONbits.TMR1ON = 0;       //Deshabilita el timer1
    T1CONbits.T1OSCEN = 0;
    TMR1 = 64285;               //Tmr1 = 65535 - (10ms/(4*8/4Mzh)) //10ms
    //Fin Configuracion Timer 1
            
    //Configuracion Interrupcion Timer1
    INTCONbits.GIE  = 1;        //Habilita interrupcion global
    INTCONbits.PEIE = 1;        //Interrupcion por perifericos
    PIE1bits.TMR1IE = 1;        //Habilita interupcion por timer1
    PIR1bits.TMR1IF = 0;        //Limpia bandera de interrupcion
    //Fin Configuracion Interrupcion Timer1
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Timer1_Start(void)
{
    Delay = Tiempo;
    TMR1 = 64285;               //10ms
    T1CONbits.TMR1ON = 1;       //Activa el contador
    
    INTCONbits.GIE = 1;
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Timer1_Stop(void)
{
    T1CONbits.TMR1ON = 0;
    TMR1 = 64285;
    
    INTCONbits.GIE = 0;
    
    return;
}
////////////////////////////////////////////////////////////////////////////////