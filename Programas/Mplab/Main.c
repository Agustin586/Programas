#include "Configuracion_Bits.h"
#include <xc.h>
#include <stdio.h>
#include "LCD_control.h"
#include "ADC.h"
#include "Task_Control.h"
#include "Pwm_Soft.h"

#define _XTAL_FREQ 20000000

#define INICIO      PORTBbits.RB0
#define ENTER       PORTBbits.RB1
#define DETENER     PORTBbits.RB2
#define MOVER       PORTBbits.RB3
#define BUZZER      PORTAbits.RA5

#define TICKS_T1    200   // Cada 20ms cambia de estado
#define TICKS_PANT  700   // Cada 70ms escribe en la pantalla
#define TICKS_T2    200   // Cada 20ms ingresa a tarea 2
#define TICKS_T4    400   // Cada 40ms


extern unsigned char Modo;

///////////////////////////
//Prototipos de funciones//
///////////////////////////

/**
 * Espera el tiempo de antirrebote para poder presionar
 */
void antirrebote(void);                           
/**
 * Escribe en la pantalla el cursor que se mueve
 * @param opcion
 */
void Seleccion_Modo(void);   
/**
 * Ingresa al modo de pulverizacion
 */
void MP_Pulv(void);
/**
 * Ingresa al modo de fuga
 */
//void MP_Fuga(void);
/**
 * Ingresa al modo de flujo
 */
//void MP_Flujo(void);
/**
 * Escribe en la pantalla los parametros principales
 */
void Lcd_PPAR(void);              
/**
 * Seleecion el modo de trabajo
 * @param opcion
 */
void Lcd_PTM(unsigned char opcion); 
/**
 * Interrupcion
 */
void __interrupt() ISR(void);            
/**
 * Elije la tarea a realizar
 */
void Task_Ready(void);
/**
 * Configura los pines como digitales y analogicos segun corresponda
 * Ademas configura otras cosas
 */
void Pines_Init(void);
void MEF_Init(void);
void MEF_Actualizacion(void);

unsigned int T_Task1=TICKS_T1,T_Task2=TICKS_T2,T_Task3=TICKS_T4,T_Lcd=TICKS_PANT;
//T_running=0 --> ninguna tarea corriendo
//T_running=1 --> tarea 1 corriendo
unsigned char Est_Task1=0,Est_Task2=0,Est_Task3=0,T_running=0;
_Bool mostrar=0,clock100us=0;

typedef enum
{
    ESTADO_MENU,
    ESTADO_MODO_PULV,
        SUBEST_ADC_MODO_PULV,
        SUBEST_PWM_MODO_PULV,
        SUBEST_TIEMPO_MODO_PULV,
    ESTADO_MODO_FUGA,
    ESTADO_MODO_FLUJO,
}MEFestado_t;

MEFestado_t Estado_Actual;

////////////////////////////////////////////////////////////////////////////////
void main(void)
{
    unsigned char opcion=1;
    
    //Inicializaciones
    Pines_Init();
    LCD_init();
    Adc_init();
    Pwm_init();
    MEF_Init();
    
    //Caracter especial
    char caracter1[8] = 
    {
        0b00000110,
        0b00001001,
        0b00001001,
        0b00000110,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000
    };
    LCD_character(CARACTER_POS1,caracter1);
    
    //Caracter especial
    char caracter[8] = {0,0,0,0,0,0,0,0};
    LCD_character(CARACTER_POS0,caracter);
    
    //Presentation
    LCD_command(CLEAR);
    LCD_array(1,1,"====================");
    LCD_array(2,1,"PROBADOR AUTOMOTRIZ ");
    LCD_array(3,1,"   DE INYECTORES    ");
    LCD_array(4,1,"====================");
    __delay_ms(2000);
    
    //Principal Menu
    LCD_command(CLEAR);
    
    //Habilita el watch dog
    WDTCONbits.SWDTEN = 1;
    WDTCONbits.WDTPS  = 0b1010;     // Preescaler de wdt 1:32768 --> timer = 32768 / 32Khz ~= 1 segundo
    CLRWDT();
    
    ////////////////////////////////////////////////////////////////////////////
    //                          PROGRAMA PRINCIPAL                            // 
    ////////////////////////////////////////////////////////////////////////////
    
    TMR1IE=1,TMR1IF=1;      // Activa la interrupcion de tmr1
    
    while(1)
    {
        /*
        //Parametros iniciales
        Out_E = 0;
        Modo = 0;
        opcion = 1;
        
        while(ENTER==0)   Seleccion_Modo(&opcion);
        
        antirrebote(),LCD_command(CLEAR);   
        Modo = opcion;                      // Elije el modo de trabajo
        Lcd_PPAR();                         // Escribe los parametros en la pantalla
        */
        
    }

    return;
}
////////////////////////////////////////////////////////////////////////////////
void MEF_Init(void)
{
    Estado_Actual = ESTADO_MENU;
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void MEF_Actualizacion(void)
{
    switch(Estado_Actual)
    {
        case ESTADO_MENU:
        {
            //Accion
            Seleccion_Modo();
            //Transicion
            if(ENTER && Modo==1)        Estado_Actual = ESTADO_MODO_PULV,antirrebote();
            else if(ENTER && Modo==2)   Estado_Actual = ESTADO_MODO_FUGA,antirrebote();
            else if(ENTER && Modo==3)   Estado_Actual = ESTADO_MODO_FLUJO,antirrebote();
        break;
        }
    }
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Seleccion_Modo(unsigned char *opcion)
{
    unsigned char opc_ant=0;    
    
    CLRWDT();           // Limpia la bandera del watchdog
    
    opc_ant = *opcion; // Guarda la opcion anterior para luego compararla
    
    //Escribe la pantallas con opciones
    if(*opcion == 1 && mostrar)
    {
        LCD_array(1,3,"PRUEBA PULVER.");         // Prueba de variar rpm
        LCD_array(2,3,"PRUEBA FUGA");            // Prueba de goteo
        LCD_array(3,3,"PRUEBA FLUJO INY.");      // Pulso totalmente abierto
        LCD_array(4,3,"LIMP. ULTRASONIDO");      // Limpieza ultrasonido
        mostrar = 0;                             // Deja de mostrar los datos durante un periodo de tiempo
    }
    
    if(*opcion == 5 && mostrar)  LCD_array(1,3,"MODO AUTOMATICO"),mostrar=0;
    else if(*opcion == 6)        LCD_command(CLEAR);

    if(MOVER == 1)                  antirrebote(),*opcion+=1;
    else if(*opcion == 6)           *opcion=1;

    //Detecta si se cambio de opcion
    if((*opcion != opc_ant)|| *opcion == 1)           Lcd_PTM(*opcion),__delay_ms(100);
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void MP_Pulv(void)
{
    unsigned char Maq_task1=1;

    //Limpia variable
    Out_E = 0;          // Comienza detenido 
    Seg = 0;            // Comienzan los segundos en 0
    mod_seg = 1;        // Comienza modificado los segundos
    mod_min = 0;        // --

    //Ciclo del modo de pulverizacion
    while(1)
    {
        //Habilitacion o detencion de la señal:
        /*===============================================================*/
        if(INICIO == 1)                 antirrebote(),Out_E=!Out_E;
        else if(DETENER == 1)           antirrebote(),PwmS1_stop(),Out_E=!Out_E,Seg=1;
        /*===============================================================*/

        //Tareas:
        /*====================================================================*/
        switch(T_running)
        {
            //Tarea sin procesos
            case 0:
            {
                CLRWDT();       // Limpia la bandera del watchdog
            break;
            }
            //Tarea de lectura analogica
            case 1:
            {
                Task1(&Maq_task1),Est_Task1=0,T_running=0;
            break;
            }
            case 2:
            {
                Task2(),Est_Task2=0,T_running=0;
            break;
            }
            case 3:
            {
                Task3(),Est_Task3=0,T_running=0;
            break;
            }
        }
        /*====================================================================*/

        //Termina la funcion elejida
        if(Fin == 1 && Out_E == 1)      
        {
            PwmS1_stop();
            break;
        }
        //Cambia entre modo de modificar minutos o segundos
        if(MOVER == 1)  antirrebote(),mod_min=!mod_min,mod_seg=!mod_seg;
    }
    
    //Reinicia banderas
    Fin=0,Out_E=0,LCD_command(CLEAR);
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Lcd_PTM(unsigned char opcion)
{
    if(opcion == 1)
    {
        LCD_xy(2,1),LCD_date(CARACTER_POS0);
        LCD_xy(3,1),LCD_date(CARACTER_POS0);
        LCD_xy(4,1),LCD_date(CARACTER_POS0);
        LCD_array(1,1,">");
    }
    else if(opcion == 2)
    {
        LCD_xy(1,1),LCD_date(0);
        LCD_xy(3,1),LCD_date(0);
        LCD_xy(4,1),LCD_date(0);
        LCD_array(2,1,">");
    }
    else if(opcion == 3)
    {
        LCD_xy(1,1),LCD_date(0);
        LCD_xy(2,1),LCD_date(0);
        LCD_xy(4,1),LCD_date(0);
        LCD_array(3,1,">");
    }
    else if(opcion == 4)
    {
        LCD_xy(1,1),LCD_date(0);
        LCD_xy(3,1),LCD_date(0);
        LCD_xy(2,1),LCD_date(0);
        LCD_array(4,1,">");
    }
    else if(opcion == 5)
    {
        LCD_command(CLEAR);
        LCD_array(1,1,">");
    }
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Lcd_PPAR(void)
{
    LCD_array(1,1,"RPM:");
    LCD_array(2,1,"PWM:");
    LCD_array(3,1,"TIEMPO:"),LCD_array(3,10,":");
    LCD_array(4,1,"TEMPERATURA:"),LCD_xy(4,16),LCD_date(CARACTER_POS1);
    LCD_array(4,17,"C");
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void __interrupt() ISR(void)
{
    _Bool f_pwmS1=0;
    
    //Interrupcion por timer 0 
    if(TMR1IF == 1)
    {
        clock100us = !clock100us;
        if(clock100us)  RB5 = 1;
        else            RB5 = 0;

        if(T_Task1 != 0 && Out_E == 0)              T_Task1--;  //Temporizador de lectura analogica
        if(T_Task2 != 0 && Out_E == 1)              T_Task2--;  //Temporizador de pwm
        if(T_Task3 != 0 && Out_E == 1)              T_Task3--;  //Temporizador de muestreo de tiempo
        if(T_Tiempo != 0 && Out_E == 1)             T_Tiempo--; //Temporizador de contador de segundos
        if(T_Lcd != 0 && Modo == 0)                 T_Lcd--;    //Temporizador de muestra del display          
        
        //Temporizador para pwm
        if(Act_PwmS1 && PwmS1!=PER_T_S1)            PwmS1++;
        if(PwmS1 == P_W_T_S1 || PwmS1 == PER_T_S1)  f_pwmS1=1;
        
        TMR1 = 65285;     // 100us
//        TMR1 = 63035;           // 1ms
        TMR1ON = 1;
        TMR1IF = 0;             // Limpia la bandera de desborde
    }
    //Cuando desborda un temporizador habilita la tarea
    if(!T_Task1 || !T_Lcd || !T_Task2 || !T_Task3)          Task_Ready();
    if(f_pwmS1 && Act_PwmS1)                                Pwm_Signal();

    //Cuando pasa 1 segundo disminuye el tiempo
    if(T_Tiempo == 0)
    {
        if(Seg == 0)
        {
            if(Min != 0)
            {
                Min--;
                Seg = 59;
            }
        }
        else Seg--;
        T_Tiempo = TICKS_T3; // Re-inicializa el temporizador
        Temporizador = 1;
    }
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Task_Ready(void)
{
    if(T_Task1 == 0)
    {
        T_Task1 = TICKS_T1;     // Re-inicia los ticks del temporizador
        Est_Task1 = 1;          // Tarea 1 corriendo
        T_running = 1;          // Elije la tarea a realizar
    }
    if(T_Lcd == 0)
    {
        T_Lcd = TICKS_PANT;
        mostrar = 1;
    }
    if(T_Task2 == 0)
    {
        T_Task2 = TICKS_T4;
        Est_Task2 = 1;
        T_running = 2;
    }
    if(T_Task3 == 0)
    {
        T_Task3 = TICKS_T4;
        Est_Task3 = 1;
        T_running = 3;
    }
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void antirrebote(void)
{
    WDTCONbits.SWDTEN = 0;      // Deshabilita el wdt
    
    BUZZER = 1;
    __delay_ms(50);
    BUZZER = 0;
    
    while(INICIO == 1 || ENTER == 1 || MOVER == 1 || DETENER == 1) __delay_ms(30);
    
    WDTCONbits.SWDTEN = 1;      // Habilita el wdt
    
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

///*//Ciclo infinito
//    while(1)
//    {
//        //Modo de funcion a utilizar
//        Out_E = 0;
//        Modo = 0;
//        opcion = 1;
//        
//        //Bucle que permite elejir la opcion
//        while(ENTER == 0)
//        {
//            CLRWDT();       // Limpia la bandera del watchdog
//            aux_opc = opcion;
//            
//            //Escribe la pantallas con opciones
//            if(opcion == 1 && mostrar)
//            {
//                LCD_array(1,3,"PRUEBA PULVER.");         // Prueba de variar rpm
//                LCD_array(2,3,"PRUEBA FUGA");            // Prueba de goteo
//                LCD_array(3,3,"PRUEBA FLUJO INY.");      // Pulso totalmente abierto
//                LCD_array(4,3,"LIMP. ULTRASONIDO");      // Limpieza ultrasonido
//                mostrar = 0;
//            }
//            if(opcion == 5 && mostrar)  LCD_array(1,3,"MODO AUTOMATICO"),mostrar=0;
//            else if(opcion == 6)        LCD_command(CLEAR);
//           
//            if(MOVER == 1)                  antirrebote(),opcion++;
//            else if(opcion == 6)            opcion=1;
//            
//            //Detecta si se cambio de opcion
//            if((opcion != aux_opc)|| opcion == 1)           Lcd_PTM(opcion),__delay_ms(100);
//        }
//        
//        antirrebote(),LCD_command(CLEAR);
//        Modo = opcion;      // Elije el modo de trabajo
//        Lcd_PPAR();    // Escribe la pantalla principal
//        
//        //Modo de trabajo 
//        switch(opcion)
//        {
//            //Pulverizacion
//            case 1:
//            {
//                unsigned char Maq_task1=1;
//                
//                //Limpia variable
//                Out_E = 0;          // Comienza detenido 
//                Seg = 0;            // Comienzan los segundos en 0
//                mod_seg = 1;        // Comienza modificado los segundos
//                mod_min = 0;        // --
//                
//                //Ciclo del modo de pulverizacion
//                while(1)
//                {
//                    //Habilitacion o detencion de la señal:
//                    /*===============================================================*/
//                    if(INICIO == 1)                 antirrebote(),Out_E=!Out_E;
//                    else if(DETENER == 1)           antirrebote(),Out_E=!Out_E,Seg=1;
//                    /*===============================================================*/
//                    
//                    //Tareas:
//                    /*===================================================================================*/
//                    //Tarea 1 de lectura analogica
//                    if(T_running == 1 && Out_E == 0)        Task1(&Maq_task1),Est_Task1=0,T_running=0;
//                    else if(T_running == 0 && Out_E == 0)   CLRWDT();   // Limpia la bandera del watchdog
//                    //Tarea 2 de pwm 
//                    if(Out_E == 1)                          Task2();
//                    /*===================================================================================*/
//                    
//                    //Termina la funcion elejida
//                    if(Fin == 1 && Out_E == 1)      break;
//                    
//                    //Cambia entre modo de modificar minutos o segundos
//                    if(MOVER == 1)  antirrebote(),mod_min=!mod_min,mod_seg=!mod_seg;
//                }
//                //Reinicia banderas
//                Fin=0,Out_E=0,LCD_command(CLEAR);
//                
//            break;
//            }
//            
//            //Modo prueba de fuga
//            case 2:
//            {
//                unsigned char Maq_task1=1;
//                char buffer[5];
//
//                //Configuraciones seteadas para el modo prueba de fuega
//                Out_E = 0;          // Comienza detenido 
//                Seg = 0;            // Comienzan los segundos en 0
//                mod_seg = 1;        // Comienza modificado los segundos
//                mod_min = 0;        // --
//                Pwm = 1;            // Duty de la señal al 1%
//                sprintf(buffer,"%02d",Pwm); //
//                LCD_array(2,5,buffer);      // Escribe el valor en display
//                
//                //Bucle del modo prueba de fuga
//                while(1)
//                {
//                    //Habilitacion o detencion de la señal:
//                    /*===============================================================*/
//                    if(INICIO == 1)                 antirrebote(),Out_E=!Out_E;
//                    else if(DETENER == 1)           antirrebote(),Out_E=!Out_E,Seg=1;
//                    /*===============================================================*/
//                    
//                    //Tareas:
//                    /*================================================================================*/
//                    //Selecciona la tarea
//                    if(T_running == 1 && Out_E == 0)        Task1(&Maq_task1),Est_Task1=0,T_running=0;
//                    else if(T_running == 0 && Out_E == 0)   CLRWDT();   // Limpia el wdt
//                    //Tarea de señal 
//                    if(Out_E == 1)                          Task2();
//                    /*================================================================================*/
//                    
//                    if(Fin == 1 && Out_E == 1)      break;
//                    
//                    //Cambia entre modo de modificar minutos o segundos
//                    if(MOVER == 1)  antirrebote(),mod_min=!mod_min,mod_seg=!mod_seg;
//                }
//                Fin=0,Out_E=0,opcion=1,LCD_command(CLEAR);
//                
//            break;
//            }
//            
//            //Modo prueba de flujo
//            case 3:
//            {
//                unsigned char Maq_task1=1;
//                char buffer[5];
//                
//                //Configuraciones seteadas para el modo prueba de fuega
//                Out_E = 0;          // Comienza detenido 
//                Seg = 0;            // Comienzan los segundos en 0
//                mod_seg = 1;        // Comienza modificado los segundos
//                mod_min = 0;        // --
//                Pwm = 99;           // Duty de la señal al 1%
//                sprintf(buffer,"%02d",Pwm); //
//                LCD_array(2,5,buffer);      // Escribe el valor en display
//                
//                //Ciclo del modo prueba de flujo
//                while(1)
//                {
//                    //Habilitacion o detencion de la señal:
//                    /*===============================================================*/
//                    if(INICIO == 1)                 antirrebote(),Out_E=!Out_E;
//                    else if(DETENER == 1)           antirrebote(),Out_E=!Out_E,Seg=1;
//                    /*===============================================================*/
//                    
//                    //Tareas:
//                    /*============================================================================*/
//                    if(T_running == 1 && Out_E == 0)    Task1(&Maq_task1),Est_Task1=0,T_running=0;
//                    else if(!T_running && !Out_E)       CLRWDT();
//                    if(Out_E == 1)                      Task2();
//                    /*============================================================================*/
//                    
//                    if(Fin == 1 && Out_E == 1)      break;
//                    
//                    //Cambia entre modo de modificar minutos o segundos
//                    if(MOVER == 1)  antirrebote(),mod_min=!mod_min,mod_seg=!mod_seg;
//                }
//                Fin=0,Out_E=0,opcion=1,LCD_command(CLEAR);
//                
//            break;
//            }
//            case 4:
//            {
//            
//            break;
//            }
//        }
//        
//        //Reinicia valores 
//        Rpm=0,Pwm=0,Min=0,Seg=0,Temp=0;
//    }*/