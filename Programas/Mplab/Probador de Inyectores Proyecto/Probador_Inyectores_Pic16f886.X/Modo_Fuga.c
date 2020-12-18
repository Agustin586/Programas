#include "Configuracion_Bits.h"
#include "Modo_Fuga.h"

void Lec_Adc_Modo_Fuga(void)
{
    //Segundo lee el adc de los minutos
    Min_read();
    
    //Tercero lee el adc de la temperatura 
    Temp_read();
    
    return;
}

void Salida_Modo_Fuga(void)
{
    
    
    return;
}