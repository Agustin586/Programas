#include "Configuracion_Bits.h"
#include "Modo_Flujo.h"

void Lec_Adc_Modo_Flujo(void)
{
    //Segundo lee el adc de los minutos
    Min_read();
    
    //Tercero lee el adc de la temperatura 
    Temp_read();
    
    return;
}

void Salida_Modo_Flujo(void)
{
    SALIDA_HIGH;
    
    return;
}