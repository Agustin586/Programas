#include "Configuracion_Bits.h"
#include "MEF.h"

#define  ENTER  PORTBbits.RB1

extern void Antirrebote(void);

////////////////////////////////////////////////////////////////////////////////
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
            
            //Transicion
            if(ENTER)        Estado_Actual = ESTADO_MODO_PULV,Antirrebote();
            else if(ENTER)   Estado_Actual = ESTADO_MODO_FUGA,Antirrebote();
            else if(ENTER)   Estado_Actual = ESTADO_MODO_FLUJO,Antirrebote();
        break;
        }
    }
    
    return;
}
////////////////////////////////////////////////////////////////////////////////