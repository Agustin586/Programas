#ifndef XC_MENU_MODO_H
#define	XC_MENU_MODO_H

#include "Pwm_Soft.h"

#define Seleccion_Modo          Select_Modo
#define Detener_Proceso         Detener
#define Analiza_Estado_Proceso  Fin_Proceso

extern _Bool Pwm_Seteado;

void Select_Modo(void);
void Detener(void);
void Fin_Proceso(void);

#endif	/* XC_MENU_MODO_H */

