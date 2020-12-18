#include "Configuracion_Bits.h"
#include "Modo_Pulverizacion.h"

void Lec_Adc_Modo_Pulv(void)
{
    //Primero lee el adc del rpm 
    Rpm_read();
    
    //Segundo lee el adc del pwm
    Pwm_read();
    
    //Tercero lee el adc de los minutos
    Min_read();
    
    //Cuarto lee el adc de la temperatura
    Temp_read();
    
    return;
}
