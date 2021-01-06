#pragma once

#ifndef MAQUINAS_ESTADOS_FINITAS_H
#define MAQUINAS_ESTADOS_FINITAS_H

#include "Display_TFT.h"
#include "Touchscreen2.h"

extern unsigned int Estado_Actual;
extern unsigned char Prtj_carga;
extern bool mostrar;

/////////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
    ESTADO_INICIAL,
    ESTADO_MENU,
    ESTADO_LEDS,
    ESTADO_BARRA,
    ESTADO_PANT_ESTATICA,
}MEFestado;
MEFestado state = Estado_Actual;
/////////////////////////////////////////////////////////////////////////////////////////
void Mef_init(void)
{
    Estado_Actual = ESTADO_INICIAL;

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
void Mef_Updated(void)
{
    switch (Estado_Actual)
    {
        case ESTADO_INICIAL:
        {
            Pantalla_inicial();

            Estado_Actual = ESTADO_MENU;
            break;
        }
        case ESTADO_MENU:
        {
            Pantalla_Menu();
            Obtener_touch();

            break;
        }
        case ESTADO_LEDS:
        {

            break;
        }
        case ESTADO_BARRA:
        {

            break;
        }
        case ESTADO_PANT_ESTATICA:
        {


            break;
        }
    }

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////

#endif // !MAQUINAS_ESTADOS_FINITAS_H
