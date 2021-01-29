#ifndef _DEFINES_MAIN_H
#define _DEFINES_MAIN_H

// Defines for Reles //
// PINS //
#define RELE1_HIGH PORTG|=(1<<PG1)
#define RELE1_LOW  PORTG&=~(1<<PG1)
#define RELE2_HIGH PORTG|=(1<<PG0)
#define RELE2_LOW  PORTG&=~(1<<PG0)
#define RELE3_HIGH PORTL|=(1<<PL7)
#define RELE3_LOW  PORTL&=~(1<<PL7)
#define RELE4_HIGH PORTL|=(1<<PL6)
#define RELE4_LOW  PORTL&=~(1<<PL6)
// DIR //
#define RELE1_OUTPUT DDRG|=(1<<PG1)	// 40 
#define RELE2_OUTPUT DDRG|=(1<<PG0)	// 41 --> Bien
#define RELE3_OUTPUT DDRL|=(1<<PL7)	// 42
#define RELE4_OUTPUT DDRL|=(1<<PL6)	// 43 --> Bien ;= 1 how to output; = 0 how to input 
// End //

// Defines for Encoder //
// PINS //
#define ENCODER_B_READ     22
#define ENCODER_PUSH_READ  23
// DIR //
#define ENCODER_A_INPUT     DDRD&=~(1<<PD2)
#define ENCODER_PUSH_INPUT  DDRA&=~(1<<PA1)
#define ENCODER_B_INPUT     DDRA&=~(1<<PA0)
// End //

// Define for Blink //
// PIN //
#define BLINK	PORTB ^= (1 << PB7)
// DIR //
#define BLINK_OUTPUT	DDRB|=(1<<PB7)
// End //

// Define for Delays //
#define DELAY_ENCODER   1		// 15ms for encoder delay
#define DELAY_BLINK		33		// 500ms for blink pin13
#define TICKS_TASK_MENU 1		// 15ms
#define TICKS_TASK_ENCODER	2	// 30ms
// End //

#endif // !_DEFINES_MAIN_H
