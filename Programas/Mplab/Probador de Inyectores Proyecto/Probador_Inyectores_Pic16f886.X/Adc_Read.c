#include "Configuracion_Bits.h"
#include "Adc_Read.h"

extern unsigned int Rpm;
extern unsigned char Pwm,Min,Seg,Temp;
extern _Bool mod_tiempo;

////////////////////////////////////////////////////////////////////////////////
void Adc_Rpm_Read(void)
{
    unsigned int valor,cent=0,dec_m=0,uni_m=0;
    
    valor = (int)((Adc(0)*5.0/1023.0)*10000.0/5.0);
    
    dec_m = (int)(valor/10000)*10000;
    uni_m = (int)((valor-dec_m)/1000)*1000;
    cent = (int)((valor-(uni_m+dec_m))/100)*100;

    valor = cent+uni_m+dec_m;
    Rpm = valor;
    
    if(Rpm == 0)            Rpm = 60;
    else if(Rpm > 10000)    Rpm = 10000;
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Adc_Pwm_Read(void)
{
    Pwm = (int)((Adc(1)*5.0/1023.0)*100.0/5.0);
    if(Pwm > 95)        Pwm = 95;
    else if(Pwm < 5)    Pwm = 5;
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Adc_Min_Read(void)
{   
    if(mod_tiempo)        Min = (int)((Adc(2)*5.0/1023.0)*59.0/5.0);
    else if(!mod_tiempo)  Seg = (int)((Adc(2)*5.0/1023.0)*59.0/5.0);
    
    if(Seg == 0)    Seg = 1;
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
void Adc_Temp_Read(void)
{
    Temp = (int)((Adc(3)*5.0/1023.0)*100.0);
    
    return;
}
////////////////////////////////////////////////////////////////////////////////
