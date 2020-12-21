#include "Configuracion_Bits.h"
#include "MEF.h"

#define  ENTER      PORTBbits.RB1
#define  INICIO     PORTBbits.RB0
#define  DETENER    PORTBbits.RB2
#define  BUZZER     PORTAbits.RA5
#define MOVER       PORTBbits.RB3

extern void Antirrebote(void);
extern unsigned char Modo,Min,Seg,Temp,Pwm;
extern _Bool Act_Variables,Output,Reset,Temporizador,mod_tiempo;
extern unsigned int Rpm;

////////////////////////////////////////////////////////////////////////////////
typedef enum
{
    ESTADO_INICIO,
    ESTADO_MENU,
    ESTADO_MODO_PULV,
    ESTADO_MODO_FUGA,
    ESTADO_MODO_FLUJO,
    ESTADO_MODO_RESET,
}MEFestado_t;

MEFestado_t Estado_Actual;
////////////////////////////////////////////////////////////////////////////////
typedef enum
{
    SUBEST_INICIAL,
    SUBEST_DISPLAY,
    SUBEST_ADC,
    SUBEST_SALIDA,
    SUBEST_TIEMPO,
    SUBEST_RESET,
}MEFsubestado_t;

MEFsubestado_t  Subestado_Actual;
////////////////////////////////////////////////////////////////////////////////
void MEF_Init(void)
{
    Estado_Actual = ESTADO_INICIO;
    Subestado_Actual = SUBEST_INICIAL;
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void MEF_Actualizacion(void)
{
    switch(Estado_Actual)
    {
        case ESTADO_INICIO:
        {
            Pantalla_Inicio();
            
            Estado_Actual = ESTADO_MENU;
        break;
        }
        case ESTADO_MENU:
        {
            Seleccion_Modo();
            
            if(ENTER && Modo==1)        Estado_Actual = ESTADO_MODO_PULV,Antirrebote();
            else if(ENTER && Modo==2)   Estado_Actual = ESTADO_MODO_FUGA,Antirrebote();
            else if(ENTER && Modo==3)   Estado_Actual = ESTADO_MODO_FLUJO,Antirrebote();
        break;
        }
        case ESTADO_MODO_PULV:
        {
            Mef_Subest_Updated();
            
            if(Reset)                   Estado_Actual = ESTADO_MODO_RESET;
        break;
        }
        case ESTADO_MODO_FUGA:
        {
            Mef_Subest_Updated();
            
            if(Reset)                   Estado_Actual = ESTADO_MODO_RESET;
        break;
        }
        case ESTADO_MODO_FLUJO:
        {
            Mef_Subest_Updated();
            
            if(Reset)                   Estado_Actual = ESTADO_MODO_RESET;
        break;
        }
        case ESTADO_MODO_RESET:
        {
            Subestado_Actual = SUBEST_INICIAL;
            Reset = 0;
            
            Estado_Actual = ESTADO_MENU;
        break;
        }
    }
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void MEF_Subest_Actualizacion(void)
{
    switch(Subestado_Actual)
    {
        case SUBEST_INICIAL:
        {
            if(Estado_Actual==ESTADO_MODO_PULV)         Pantalla_Pulverizacion(); 
            else if(Estado_Actual==ESTADO_MODO_FUGA)    Pantalla_Fuga();
            else if(Estado_Actual==ESTADO_MODO_FLUJO)   Pantalla_Flujo();
            
            Pantalla_Modos_Pulv_Fuga_Flujo(); 
            
            Subestado_Actual = SUBEST_DISPLAY;
        break;
        }
        case SUBEST_DISPLAY:
        {
            Pantalla_Actualiza_Valores();
            
            Subestado_Actual = SUBEST_ADC;
        break;
        }
        case SUBEST_ADC:
        {
            if(Estado_Actual==ESTADO_MODO_PULV)         Lectura_Adc_Pulverizacion(); 
            else if(Estado_Actual==ESTADO_MODO_FUGA)    Lectura_Adc_Fuga();
            else if(Estado_Actual==ESTADO_MODO_FLUJO)   Lectura_Adc_Flujo();
            
            if(MOVER)   mod_tiempo=!mod_tiempo,Antirrebote();

            if(Act_Variables)   Subestado_Actual = SUBEST_DISPLAY,Act_Variables=0;
            if(INICIO)          Subestado_Actual = SUBEST_SALIDA,Antirrebote(),Output=!Output;
            if(DETENER)         Subestado_Actual = SUBEST_RESET,Output=!Output,Detener_Proceso();
        break;
        }
        case SUBEST_SALIDA:
        {
            if(Estado_Actual==ESTADO_MODO_PULV)         Salida_Pulverizacion();
            else if(Estado_Actual==ESTADO_MODO_FUGA)    Salida_Fuga();
            else if(Estado_Actual==ESTADO_MODO_FLUJO)   Salida_Flujo();
                
            if(Temporizador)    Subestado_Actual = SUBEST_TIEMPO;
            if(DETENER)         Subestado_Actual = SUBEST_RESET,Detener_Proceso();
        break;
        }
        case SUBEST_TIEMPO:
        {
            Pantalla_Temporizador();
            Analiza_Estado_Proceso();
            
            if(Output)  Subestado_Actual = SUBEST_SALIDA;
            else        Subestado_Actual = SUBEST_RESET;
        break;
        }
        case SUBEST_RESET:
        {
            Rpm=0,Pwm=0,Min=0,Seg=0,Temp=0,Modo=0;
            SALIDA_LOW;
            Lcd_comando(CLEAR);            
            Reset = 1;
            
            Subestado_Actual = SUBEST_INICIAL;
        break;
        }
    }
    
    return;
}
////////////////////////////////////////////////////////////////////////////////