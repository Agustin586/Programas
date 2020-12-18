#ifndef XC_MEF_H
#define	XC_MEF_H

#include "Display_Lcd.h"
#include "Lcd.h"
#include "Menu_Modo.h"
#include "Pwm_Soft.h"
#include "ADC.h"
#include "Modo_Pulverizacion.h"
#include "Modo_Fuga.h"
#include "Modo_Flujo.h"

#define Mef_Init            MEF_Init
#define Mef_Updated         MEF_Actualizacion
#define Mef_Subest_Updated  MEF_Subest_Actualizacion

//Funciones de la maquina de estados
void MEF_Init(void);
void MEF_Actualizacion(void);
void MEF_Subest_Actualizacion(void);

#endif	/* XC_MEF_H */

