#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>

// Funtions //
void Get_Dates(void);
void I2C_Clock_Init(void);
// Variables //
static uint8_t week=11,day=11,month=11,year=11,hour=11,minute=11,second=11;

#endif