#ifndef XC_MODO_FLUJO_H
#define	XC_MODO_FLUJO_H

#include "Adc_Read.h"

#define Lectura_Adc_Flujo    Lec_Adc_Modo_Flujo
#define Salida_Flujo         Salida_Modo_Flujo
#define SALIDA_PIN  PORTBbits.RB4
#define SALIDA_TRIS TRISBbits.TRISB4
#define SALIDA_HIGH PORTBbits.RB4=1
#define SALIDA_LOW  PORTBbits.RB4=0

void Lec_Adc_Modo_Flujo(void);
void Salida_Modo_Flujo(void);

#endif	/* XC_MODO_FLUJO_H */

