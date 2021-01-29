#ifndef SERIAL_H
#define SERIAL_H

extern volatile char Rx;
extern volatile bit echo;

void Serial_writeInit(void);
void Reception(void);
void Echo_Tx(void);

#endif