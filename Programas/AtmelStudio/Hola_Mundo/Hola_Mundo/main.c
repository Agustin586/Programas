#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = (1<<PB7);	// Setup PinB7 how to output
    /* Replace with your application code */
    while (1) 
    {
		PORTB = (1<<PB7);	// Set PinB7
		_delay_ms(1000);
		PORTB = (0<<PB7);	// Clear PinB7
		_delay_ms(1000);
    }
}

