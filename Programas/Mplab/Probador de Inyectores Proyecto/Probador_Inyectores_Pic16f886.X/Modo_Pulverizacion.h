#ifndef XC_MODO_PULVERIZACION_H
#define	XC_MODO_PULVERIZACION_H

#include "Adc_Read.h"
#include "Pwm_Soft.h"

#define Lectura_Adc_Pulverizacion   Lec_Adc_Modo_Pulv
#define Salida_Pulverizacion        Salida_Modo_Pulv

extern unsigned int Rpm;
extern unsigned char Pwm;
extern _Bool Pwm_Seteado;

void Lec_Adc_Modo_Pulv(void);
void Salida_Modo_Pulv(void);

#endif	/* XC_MODO_PULVERIZACION_H */

