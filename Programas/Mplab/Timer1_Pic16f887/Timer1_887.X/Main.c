/*
 * Descripcion: Este programa configura un timer1 en un pic16f887 con la intencion de 
 * hacer un delay no bloqueante.
 * 
 * Autor: Agustin
 * 
 * Fecha de finalizacion: 16/12/2020
 * 
 * Uso: 
 *      *Para lo calculos del timer se utilizo la siguiente formula: TMR1 = 65535 - (Tiempo del timer/(4*Valor_Preescaler/Frecuencia Oscilador))
 *      *Para demostrar el uso de diferentes valores utiizamos dos pulsadores con la intencion de setear el delay
 *       en diferente valores: 1 segundo y 5 segundos
 *      *Para setear el valor del delay se utiliza la variable "Tiempo" la cual es unsigned long 
 *      *Libreria C99
 *      *Tiempo = Valor * 10ms --> Para 10segundos Tiempo = 1000 * 10ms = 10s
 */

#include "Configuracion_Bits.h" //Configura todos los bits y la frecuencia del oscilador
#include "Timer1.h"             //Libreria timer1

//Pulsador 1 segundo
#define S1_PIN_READ    PORTBbits.RB0
#define S1_PIN_TRIS    TRISBbits.TRISB0
//---
//Pulsador 5 segundos
#define S5_PIN_READ    PORTBbits.RB1
#define S5_PIN_TRIS    TRISBbits.TRISB1
//---
//Led 
#define LED_HIGH       PORTBbits.RB3=1
#define LED_LOW        PORTBbits.RB3=0
#define LED_TRIS       TRISBbits.TRISB3
//---

//Variables
unsigned long Tiempo=100;
volatile unsigned long Delay=0;

//Prototipos de funciones
void __interrupt () ISR (void);
void Fin_Delay(void);
void Antirrebote(void);

////////////////////////////////////////////////////////////////////////////////
void main(void) {
    //Configuracione de salidas
    ANSEL = 0;      //Todo digital
    ANSELH = 0;     //Todo digital
    
    S1_PIN_TRIS = 1;    //Setea como entrada pulsador 1 segundo
    S5_PIN_TRIS = 1;    //Setea como entrada pulsador 5 segundos
    LED_TRIS = 0;       //Setea como salida 
    LED_LOW;            //Apaga el led
    
    //Inicializaciones
    Timer1_Init();      //Configura el timer1 
    Timer1_Stop();      //Detiene el timer1

    while(1)
    {
        if(S1_PIN_READ)
        {
            LED_HIGH;
            Tiempo = 100;   //1 segundo
            Timer1_Start();
            Antirrebote();
        }
        if(S5_PIN_READ)
        {
            LED_HIGH;
            Tiempo = 500;   //5 segundos
            Timer1_Start();
            Antirrebote();
        }
    }
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void __interrupt () ISR (void)
{
    if(PIR1bits.TMR1IF == 1)
    {
        if(Delay!=0)    Delay--;
        
        TMR1 = 64285;               //10ms para 4MHz
        PIR1bits.TMR1IF = 0;
    }
    
    if(!Delay)  Fin_Delay();
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Fin_Delay(void)
{
    if(Delay==0)
    {
        /*
         Realiza una accion, ya pasaron X segundos
         */
        LED_LOW;
        Timer1_Stop();
        Delay = Tiempo;
    }
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Antirrebote(void)
{
    __delay_ms(10);
    while(S1_PIN_READ==1 || S5_PIN_READ==1)   __delay_ms(10);
    
    return;
}
////////////////////////////////////////////////////////////////////////////////