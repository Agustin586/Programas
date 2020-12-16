#ifndef XC_MEF_H
#define	XC_MEF_H

#include "Display_Lcd.h"
#include "Lcd.h"
#include "Menu_Modo.h"
#include "Pwm_Soft.h"

#define Mef_Init        MEF_Init
#define Mef_Updated     MEF_Actualizacion

//Funciones de la maquina de estados
void MEF_Init(void);
void MEF_Actualizacion(void);

#endif	/* XC_MEF_H */

