#include "Configuracion_Bits.h"
#include "MEF.h"

#define  ENTER  PORTBbits.RB1

extern void Antirrebote(void);
extern unsigned char Modo;

////////////////////////////////////////////////////////////////////////////////
typedef enum
{
    ESTADO_INICIO,
    ESTADO_MENU,
    ESTADO_MODO_PULV,
    ESTADO_MODO_FUGA,
    ESTADO_MODO_FLUJO,
}MEFestado_t;

MEFestado_t Estado_Actual;
////////////////////////////////////////////////////////////////////////////////
typedef enum
{
    SUBEST_INICIAL,
    SUBEST_DISPLAY,
    SUBEST_ADC,
    SUBEST_PWM,
    SUBEST_TIEMPO,
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
            WDTCONbits.SWDTEN = 1;          //Habilita el watch dog
            WDTCONbits.WDTPS  = 0b1010;     // Preescaler de wdt 1:32768 --> timer = 32768 / 32Khz ~= 1 segundo
            CLRWDT();
            
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
            
            
        break;
        }
        case ESTADO_MODO_FUGA:
        {
            
        break;
        }
        case ESTADO_MODO_FLUJO:
        {
            
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
            Pantalla_Modos_Pulv_Fuga_Flujo(); 
            
            Subestado_Actual = SUBEST_DISPLAY;
        break;
        }
        case SUBEST_DISPLAY:
        {
            Pantalla_Actualiza_Valores();
            
            
        break;
        }
        case SUBEST_ADC:
        {
            
            
        break;
        }
        case SUBEST_PWM:
        {
            
            
        break;
        }
        case SUBEST_TIEMPO:
        {
            
            
        break;
        }
    }
    
    return;
}
////////////////////////////////////////////////////////////////////////////////