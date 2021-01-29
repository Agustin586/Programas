#include "Clock.h"

void Get_Dates(void)
{
   rtc2_getDate(&week,&day,&month,&year);
   rtc2_getTime(&hour,&minute,&second);

   return;
}

void I2C_Clock_Init(void)
{
   GIEH_bit = 0;
   GIEL_bit = 0;
   Soft_I2C_Init();
//   Get_Dates();
   GIEH_bit = 1;
   GIEL_bit = 1;

   return;
}