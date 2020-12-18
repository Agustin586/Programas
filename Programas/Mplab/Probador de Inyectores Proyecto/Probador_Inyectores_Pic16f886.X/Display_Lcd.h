#ifndef XC_DISPLAY_LCD_H
#define	XC_DISPLAY_LCD_H

#include "MEF.h"

#define Pantalla_Inicio                 Pant_Inicio
#define Pantalla_Menu                   Pant_Menu
#define Pantalla_Modos_Pulv_Fuga_Flujo  Pant_Modos
#define Pantalla_Actualiza_Valores      Pant_Val_Act
#define Pantalla_Temporizador           Pant_Temporizador
#define Pantalla_Selector               Pant_Selector

void Pant_Inicio(void);
void Pant_Menu(void);
void Pant_Modos(void);
void Pant_Val_Act(void);
void Pant_Temporizador(void);
void Pant_Selector(void);

#endif	/* XC_DISPLAY_LCD_H */

