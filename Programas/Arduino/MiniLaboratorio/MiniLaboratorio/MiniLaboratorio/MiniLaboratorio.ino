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
#define ENCODER_B_READ     PINA0
#define ENCODER_PUSH_READ  PINA1
// DIR //
#define ENCODER_A_INPUT     DDRB|=(1<<PB6)
#define ENCODER_PUSH_INPUT  DDRA|=(1<<PA1)
#define ENCODER_B_INPUT     DDRA|=(1<<PA0)
// End //

// Define for Blink //
// PIN //
#define BLINK	PORTB ^= (1 << PB7)
// DIR //
#define BLINK_OUTPUT	DDRB|=(1<<PB7)
// End //

// Define for Delays //
#define DELAY_ENCODER   50    // 50ms for encoder delay
// End //

volatile char Rx;
volatile bool echo=false, Encoder_E=false;
volatile unsigned long long ms = 0;
volatile char Pos = 0;

// Variables for delays //
volatile unsigned char _Delay_Encoder = DELAY_ENCODER;

void Timer0_init(void);
unsigned long long milis(void);
void Antirrebote_Encoder(void);
void Task_Detected(void);

void setup()
{
	IO_Cofig();
	Interrupt_Init();
}

void loop()
{
	//BLINK;	// Set PinB7
	BLINK;
	_delay_ms(500);
}

void IO_Cofig(void)
{
	// Setup of input and outputs //
	DDRB = 0x00;
	DDRG = 0x00;
	DDRL = 0x00;
	
	// Blink //
	BLINK_OUTPUT;
	// Reles //
	RELE1_OUTPUT;
	RELE2_OUTPUT;
	RELE3_OUTPUT;
	RELE4_OUTPUT;
	// Encoder //
	
	// End setup //
	
	// Testing Reles //
	RELE1_HIGH;
	RELE2_HIGH;
	RELE3_HIGH;
	RELE4_HIGH;
	
	_delay_ms(2000);
	RELE1_LOW;
	RELE2_LOW;
	RELE3_LOW;
	RELE4_LOW;
	// End testing // 
}

void Interrupt_Init(void)
{


	return;
}