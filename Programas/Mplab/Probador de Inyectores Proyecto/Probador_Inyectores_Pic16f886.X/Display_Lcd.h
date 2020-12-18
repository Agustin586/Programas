#ifndef XC_DISPLAY_LCD_H
#define	XC_DISPLAY_LCD_H

#include "MEF.h"

#define Pantalla_Inicio                 Pant_Inicio
#define Pantalla_Menu                   Pant_Menu
#define Pantalla_Modos_Pulv_Fuga_Flujo  Pant_Modos
#define Pantalla_Actualiza_Valores      Pant_Val_Act
#define Pantalla_Temporizador           Pant_Temporizador
#define Pantalla_Selector               Pant_Selector
#define Pantalla_Detener                Pant_Detener
#define Pantalla_Pulverizacion          Pant_Pulverizacion
#define Pantalla_Fuga                   Pant_Fuga
#define Pantalla_Flujo                  Pant_Flujo
#define Proceso_Finalizado              Proceso_Fin

void Pant_Inicio(void);
void Pant_Menu(void);
void Pant_Modos(void);
void Pant_Val_Act(void);
void Pant_Temporizador(void);
void Pant_Selector(void);
void Pant_Detener(void);
void Pant_Pulverizacion(void);
void Pant_Fuga(void);
void Pant_Flujo(void);
void Proceso_Fin(void);

#endif	/* XC_DISPLAY_LCD_H */

