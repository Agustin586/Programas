#line 1 "C:/Users/aguat/OneDrive/Programacion Microcontroladores/Github/Programas/MikroC/Proyecto_Laboratorio/Programa/Clock.c"
#line 1 "c:/users/aguat/onedrive/programacion microcontroladores/github/programas/mikroc/proyecto_laboratorio/programa/clock.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;



typedef signed char int_fast8_t;
typedef signed int int_fast16_t;
typedef signed long int int_fast32_t;


typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned long int uint_fast32_t;


typedef signed int intptr_t;
typedef unsigned int uintptr_t;


typedef signed long int intmax_t;
typedef unsigned long int uintmax_t;
#line 7 "c:/users/aguat/onedrive/programacion microcontroladores/github/programas/mikroc/proyecto_laboratorio/programa/clock.h"
void Get_Dates(void);
void I2C_Clock_Init(void);

static uint8_t week=11,day=11,month=11,year=11,hour=11,minute=11,second=11;
#line 3 "C:/Users/aguat/OneDrive/Programacion Microcontroladores/Github/Programas/MikroC/Proyecto_Laboratorio/Programa/Clock.c"
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

 GIEH_bit = 1;
 GIEL_bit = 1;

 return;
}
