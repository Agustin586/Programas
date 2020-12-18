#ifndef XC_MODO_FUGA_H
#define	XC_MODO_FUGA_H

#include "Adc_Read.h"

#define Lectura_Adc_Fuga    Lec_Adc_Modo_Fuga
#define Salida_Fuga         Salida_Modo_Fuga
#define SALIDA_LOW          PORTBbits.RB4=0

void Lec_Adc_Modo_Fuga(void);
void Salida_Modo_Fuga(void);

#endif	/* XC_MODO_FUGA_H */

