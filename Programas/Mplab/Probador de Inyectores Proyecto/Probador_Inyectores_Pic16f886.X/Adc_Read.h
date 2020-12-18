#ifndef XC_ADC_READ_H
#define	XC_ADC_READ_H

#include "ADC.h"

#define Rpm_read    Adc_Rpm_Read
#define Pwm_read    Adc_Pwm_Read
#define Min_read    Adc_Min_Read
#define Temp_read   Adc_Temp_Read

void Adc_Rpm_Read(void);
void Adc_Pwm_Read(void);
void Adc_Min_Read(void);
void Adc_Temp_Read(void);

#endif	/* XC_ADC_READ_H */

