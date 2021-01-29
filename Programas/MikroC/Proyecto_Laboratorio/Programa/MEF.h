#ifndef MEF_H
#define MEF_H

#include "Serial.h"
#include "Display.h"

// Funtions //
void Mef_init(void);
void Mef_Updated(void);
void SubEst_MENU_Updated(void);
// Variables //
extern volatile bit echo;
extern volatile char Rx;

typedef enum
{
    ESTATE_INIT,
    ESTATE_MENU,
    ESTATE_OUTPUT,
    ESTATE_RTC,
    ESTATE_TESTING,
    ESTATE_UART,
    ESTATE_THEME,
}MEFestado_t;

static MEFestado_t Estado_Actual;

typedef enum
{
   SUBM_MENU_INIT,
   SUBM_MENU_SELECT,
}SUBM_MENUestado_t;

static SUBM_MENUestado_t SubEst_Menu;

#endif