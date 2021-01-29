#include <TimerOne.h>
#include "DefinesMain.h"
#include "MEF.h"

// Variables //
volatile char Rx;
volatile bool echo = false, EncoderDelay = false;
bool Relay1 = false, Relay2 = false, Relay3 = false, Relay4 = false;
volatile unsigned long long ms = 0;
volatile uint8_t Opc=0,OpcAnt=Opc;
uint8_t	maxSteps=255, minSteps=1;
// Variables for task //
volatile unsigned char _Delay_Encoder = DELAY_ENCODER, _Task_Blink = DELAY_BLINK, _Task_Menu = TICKS_TASK_MENU, _Task_Encoder = TICKS_TASK_ENCODER;
bool Est_Task_Menu = false, Est_Task_Blink = false, Est_Task_Encoder = false;
// End //

// Functions externs //
extern void MEF_Init(void);
extern void MEF_Updated(void);

void setup()
{
	Serial.begin(9600);
	IO_Cofig();
	Interrupt_Init();
	MEF_Init();
	Display_Init();
}

void loop()
{
	MEF_Updated();
}

// Functions for settings //
void IO_Cofig(void)
{
	// Setup of input and outputs //
	DDRB = 0x00;
	DDRG = 0x00;
	DDRL = 0x00;
	DDRD = 0x00;
	DDRA = 0x00;

	// Blink //
	BLINK_OUTPUT;
	// Reles //
	RELE1_OUTPUT;
	RELE2_OUTPUT;
	RELE3_OUTPUT;
	RELE4_OUTPUT;
	// Encoder //
	pinMode(19, INPUT);
	pinMode(22, INPUT);
	pinMode(23, INPUT_PULLUP);
	// Buzzer //
	// --Here-- //
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
	// Setup interrupt with INT4 for Falling edge in Pin19 PD2 for Arduino Mega //
	//attachInterrupt(INT4, ISR_ExtInt4, LOW);
	// End //
	// Setup Interrupt for Timer1 //
	Timer1.initialize(15000);	// 15ms
	Timer1.attachInterrupt(ISR_TMR1);
	// End //

	return;
}
// End //

// Interrupt Service Rutine // 
void ISR_ExtInt4(void)
{
	if (EncoderDelay == false && digitalRead(19) != HIGH)
	{
		if (digitalRead(ENCODER_B_READ)==HIGH)	Opc+=1;
		else Opc-=1;

		if (Opc > maxSteps)			Opc = maxSteps;
		else if (Opc < minSteps)	Opc = minSteps;

		EncoderDelay = true;
	}

	return;
}
void ISR_TMR1(void)
{
	if (EncoderDelay==true && _Delay_Encoder!=0)	_Delay_Encoder--;	// Antirrebote for Encoder Rotative
	if (_Task_Blink != 0)							_Task_Blink--;		// 495ms 
	if (_Task_Menu != 0)							_Task_Menu--;		// 15ms
	if (_Task_Encoder != 0)							_Task_Encoder--;	// 30ms

	TaskReady();

	return;
}
void TaskReady(void)
{
	//if (!_Delay_Encoder)
	//{
	//	_Delay_Encoder = DELAY_ENCODER;

	//	EncoderDelay = false;
	//}
	//if (!_Task_Blink)
	//{
	//	_Task_Blink = DELAY_BLINK;

	//	Est_Task_Blink = true;
	//}
	if (!_Task_Menu)
	{
		_Task_Menu = TICKS_TASK_ENCODER;

		Est_Task_Menu = true;
	}
	//if (!_Task_Encoder)
	//{
	//	_Task_Encoder = TICKS_TASK_ENCODER;

	//	Est_Task_Encoder = true;
	//}

	return;
}
// End All rutines //

void Push_Antirrebote(void)
{
	delay(20);
	while (digitalRead(ENCODER_PUSH_READ) == 1)	delay(10);

	return;
}