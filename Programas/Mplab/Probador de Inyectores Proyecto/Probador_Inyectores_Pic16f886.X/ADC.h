#ifndef XC_ADC_H
#define XC_ADC_H

#include <xc.h>
#define _XTAL_FREQ 20000000

void Adc_init(void);
int Adc(unsigned char canal);

#endif  /* XC_ADC_H */
