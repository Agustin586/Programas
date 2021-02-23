/*
 * File:   Main.c
 * Author: aguat
 *
 * Created on 10 de febrero de 2021, 00:44
 */


// PIC16F628A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// Defines //
#define _XTAL_FREQ  4000000
#define CRUCE_X_CERO        PORTBbits.RB0
#define SALIDA_TRIAC_PIN    PORTBbits.RB1
#define SALIDA_TRIAC_TRIS   TRISBbits.TRISB1
#define UP_PIN              PORTBbits.RB2
#define UP_TRIS             TRISBbits.TRISB2
#define START_STOP_PIN      PORTBbits.RB3
#define START_STOP_TRIS     TRISBbits.TRISB3
#define DOWN_PIN            PORTBbits.RB4
#define DOWN_TRIS           TRISBbits.TRISB4
#define BLINK_TRIS          TRISAbits.TRISA7
#define BLINK_PIN           PORTAbits.RA7
#define HIGH    1
#define LOW     0
#define DUTY_MIN    10
#define DUTY_MAX    100
// Digitos //
#define TIEMPO_MULTIPLEXACION   2
#define D1_PIN              PORTBbits.RB5
#define D2_PIN              PORTBbits.RB6
#define D3_PIN              PORTBbits.RB7
#define D1_TRIS             TRISBbits.TRISB5
#define D2_TRIS             TRISBbits.TRISB6
#define D3_TRIS             TRISBbits.TRISB7
// CD4511 //
#define A_PIN               PORTAbits.RA0
#define B_PIN               PORTAbits.RA1
#define C_PIN               PORTAbits.RA2
#define D_PIN               PORTAbits.RA3
#define A_TRIS              TRISAbits.TRISA0
#define B_TRIS              TRISAbits.TRISA1
#define C_TRIS              TRISAbits.TRISA2
#define D_TRIS              TRISAbits.TRISA3
// End //

// Includes //
#include <xc.h>
#include <stdint.h>
// End //

// Funciones //
void Perifericos_Init(void);
void InOutPines_Init(void);
void TimerReady(void);
void Control(void);
void CargaDigitos(void);
void Antirrebote(void);
void __interrupt() ISR(void);
// End //

// Variables //
volatile _Bool SalTriac_E=0;
_Bool Disp_E=0;
volatile unsigned int TimerSalTriac=0,TimerBlink=500,TimerMultiplexacion=TIEMPO_MULTIPLEXACION;
uint8_t Duty=0,ValorTimerTriac=0; // 0% al 100%
volatile uint8_t DigitoActivo=1;    // 1 - 3 
// End //

void main(void)
{
    // Iniciliazaciones //
    Perifericos_Init();
    InOutPines_Init();
    
    Duty = DUTY_MIN;
    
    /* Loop */
    while(1)
    {
        Control();
        CargaDigitos();
    }
    return;
}
void Perifericos_Init(void)
{
    CMCON = 0x07;
    
    //Configuracion de timer //
    T1CONbits.T1CKPS = 0b11;    // 1:8
    TMR1CS = 0;
    TMR1ON = 1;
    TMR1 = 65411; // 1ms = 65536 - 125
    
    //Activa las interrupciones //
    INTCONbits.PEIE = 1;    // Activa interrupcion por perifericos
    //Interrupcion de RB0 
    INTCONbits.INTE = 1;
    INTCONbits.INTF = 0;
    OPTION_REGbits.INTEDG = 1;  // RB0 por flanco ascendente
    
    TMR1IE = 1;   // Interrupcion activada
    TMR1IF = 0;   // Cuenta
    
    return;
}
void InOutPines_Init(void)
{
    /* Configuracion del modo de trabajo */
    SALIDA_TRIAC_TRIS = 0;
    START_STOP_TRIS = 1;
    UP_TRIS = 1;
    DOWN_TRIS = 1;
    BLINK_TRIS = 0;
    A_TRIS = 0;
    B_TRIS = 0;
    C_TRIS = 0;
    D_TRIS = 0;
    D1_TRIS = 0;
    D2_TRIS = 0;
    D3_TRIS = 0;
    
    /* Estado inicial */
    SALIDA_TRIAC_PIN = LOW;
    BLINK_PIN = LOW;
    A_PIN = LOW;
    B_PIN = LOW;
    C_PIN = LOW;
    D_PIN = LOW;
    D1_PIN = LOW;
    D2_PIN = LOW;
    D3_PIN = LOW;
    
    return;
}
void Control(void)
{
    /* Lectura de estado de pulsadores */
    if(UP_PIN && Duty < DUTY_MAX)           Duty+=10,Antirrebote();
    else if(DOWN_PIN && Duty > DUTY_MIN)    Duty-=10,Antirrebote();
    else if(START_STOP_PIN) Disp_E=!Disp_E,Antirrebote();
    
    /* Acciones */
    // Habilitacion o deshabilitacion //
    if(Disp_E)
        INTCONbits.GIE = 1;
    else
    {
        INTCONbits.GIE = 0;
        SALIDA_TRIAC_PIN = LOW;
        BLINK_PIN = LOW;
        Duty = DUTY_MIN;
    }
    /* Fin */
    
    // Valor temporizador triac //
    ValorTimerTriac = (10 - (Duty/10.0));
    
    return;
}
void CargaDigitos(void)
{
    uint8_t unidad,decena,centena;
    
    centena = Duty/100;
    decena  = (Duty- (centena*100))/10;
    unidad  = Duty - (centena*100+decena*10);
    
    if(Disp_E)
    {
        switch(DigitoActivo)
        {
            case 1:
            {
                D1_PIN=HIGH,D2_PIN=LOW,D3_PIN=LOW;
                PORTA &= 0b11110000; // 0xF0 Limpia bits anteriormente seteados
                PORTA |= centena;
            break;
            }
            case 2:
            {
                D1_PIN=LOW,D2_PIN=HIGH,D3_PIN=LOW;
                PORTA &= 0b11110000; // 0xF0 Limpia bits anteriormente seteados
                PORTA |= decena;
            break;
            }
            case 3:
            {
                D1_PIN=LOW,D2_PIN=LOW,D3_PIN=HIGH;
                PORTA &= 0b11110000; // 0xF0 Limpia bits anteriormente seteados
                PORTA |= unidad;
            break;
            }
        }
    }
    else D1_PIN=LOW,D2_PIN=LOW,D3_PIN=LOW;
    
    return;
}
void Antirrebote(void)
{
    __delay_ms(10);
    while(START_STOP_PIN || UP_PIN || DOWN_PIN) __delay_ms(5);
    
    return;
}
void __interrupt() ISR(void)
{
    /* Deteccion de cruce por cero */
    if(INTF == 1)
    {
        // Limpia bandera //
        INTF = 0;
        
        // Activa Timer por Software //
        SalTriac_E = 1;     // Habilita el timer
        TimerSalTriac = ValorTimerTriac;  // Tiempo en ms
        //TimerSalTriac = 5;
        
        // Desactiva cuando salida cuando detecta el cruce x cero //
        if(Duty==100)
        {
            SALIDA_TRIAC_PIN = HIGH;
        }
        else SALIDA_TRIAC_PIN = LOW;
    }
    /* Timers por Software */
    if(TMR1IF == 1)
    {
        /* Timers */
        if(SalTriac_E==1 && TimerSalTriac!=0)   TimerSalTriac--; // Timer para salida Triac
        if(TimerBlink!=0)   TimerBlink--;
        if(TimerMultiplexacion!=0)              TimerMultiplexacion--;   // Cambio de digito
        
        /* Accion en base a los timers por software */
        TimerReady();
        
        /* Re-inicia el timer por hardware */
        TMR1 = 65411;   // 1ms
        TMR1IF = 0;     // Limpia bandera timer
    }
    
    return;
}
void TimerReady(void)
{
    /* Timer Triac */
    if(!TimerSalTriac)
    {
        // Limpia banderas //
        TimerSalTriac = 0;
        SalTriac_E = 0;
        // Activa salida Triac //
        SALIDA_TRIAC_PIN = HIGH;
    }
    /* Timer Led indicador encendido */
    if(!TimerBlink)
    {
        BLINK_PIN = !BLINK_PIN;
        TimerBlink = 500;
    }
    /* Timer para el cambio de digito activo */
    if(!TimerMultiplexacion)
    {
        if(DigitoActivo < 3)    DigitoActivo+=1;
        else                    DigitoActivo=1;
        
        TimerMultiplexacion = TIEMPO_MULTIPLEXACION;
    }
    
    return;
}