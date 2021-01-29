#include "MEF.h"
#include "Display.h"
#include "Fonts.h"
#include "Clock.h"

// Defines for Reles //
// PINS //
#define RELE1_HIGH LATA5_bit=1
#define RELE1_LOW  LATA5_bit=0
#define RELE2_HIGH LATE0_bit=1
#define RELE2_LOW  LATE0_bit=0
#define RELE3_HIGH LATE1_bit=1
#define RELE3_LOW  LATE1_bit=0
#define RELE4_HIGH LATE2_bit=1
#define RELE4_LOW  LATE2_bit=0
// TRIS //
#define RELE1_TRIS TRISA5_bit
#define RELE2_TRIS TRISE0_bit
#define RELE3_TRIS TRISE1_bit
#define RELE4_TRIS TRISE2_bit
// End //

// Defines for Encoder //
// PINS //
#define ENCODER_B_READ     RC0_bit
#define ENCODER_PUSH_READ  RC1_bit
// TRIS //
#define ENCODER_A_TRIS     TRISB0_bit
#define ENCODER_PUSH_TRIS  TRISC1_bit
#define ENCODER_B_TRIS     TRISC0_bit
// **ENCODER_B Y ENCODER_PUSH YA SON DEFINIDOS COMO ENTRADA AUTOMATICAMENTE** //
// End //

// Defines for Analog Channels //
// PINS //
#define AN0_PIN   8
#define AN1_PIN   11
// TRIS //
#define AN0_TRIS  TRISA0_bit
#define AN1_TRIS  TRISA1_bit
// End //

// Defines for buzzer //
// PINS //
#define BUZZER_HIGH  LATC0_bit=1
#define BUZZER_LOW   LATC0_bit=0
// TRIS //
#define BUZZER_TRIS  TRISC0_bit
// End //

// Define for Delays //
#define DELAY_ENCODER   50    // 50ms for encoder delay
// End //

// Software I2C connections  //
sbit Soft_I2C_Scl           at RA4_bit;
sbit Soft_I2C_Sda           at RA3_bit;
sbit Soft_I2C_Scl_Direction at TRISA4_bit;
sbit Soft_I2C_Sda_Direction at TRISA3_bit;
// End Software I2C connections //


volatile char Rx;
volatile bit echo,Encoder_E;
volatile unsigned long long ms=0;
volatile char Pos=0;

// Variables for delays //
volatile unsigned char _Delay_Encoder = DELAY_ENCODER;

void IO_Config(void);
void Interrupt_init(void);
void Timer0_init(void);
unsigned long long milis(void);
void Antirrebote_Encoder(void);
void Task_Detected(void);

void main()
{
   ADCON1 = 0x0D;       // AN0 and AN1 Enable and others how to digital I/O
   UCON &= 0b11110111;
   UCFG |= 0b00001000;
   
   echo = 0;
   Encoder_E = 0;

   IO_Config();
   Interrupt_init();
   Timer0_init();
   UART1_Init(56000);
   TFT_Init_ILI9341_8bit(320,240);
   I2C_Clock_Init();
   Mef_init();

   TFT_Write_Command(0x36);
   TFT_Write_Data(0x20|0x08);    // 90°
   //0x40|0x80|0x20|0x08 --> 270°

   // Begin code loop //
   while(1)
   {
      Mef_Updated();
   }
   // End code loop //
}

void IO_Config(void)
{
   // Reles GPIO //
   RELE1_TRIS = 0;
   RELE1_LOW;
   RELE2_TRIS = 0;
   RELE2_LOW;
   RELE3_TRIS = 0;
   RELE3_LOW;
   RELE4_TRIS = 0;
   RELE4_LOW;
   // End //
   
   // Encoder GPIO //
   ENCODER_A_TRIS = 1;
   ENCODER_PUSH_TRIS = 1;
   ENCODER_B_TRIS = 1;
   // End //
   
   // Buzzer GPIO //
   BUZZER_TRIS = 0;
   BUZZER_LOW;
   // End //
   
   // Analog channels //
   AN0_TRIS = 1;       // Input channel 0
   AN1_TRIS = 1;       // Input channel 1
   // End //

   return;
}

void Interrupt_init(void)
{
   // High Priority //
   GIE_bit = 1;
   IPEN_bit = 1;
   PEIE_bit = 1;
   // End //
   
   // Low Priority //
   GIEL_bit = 1;
   // End //
   
   // Interrupt with UART //
   RCIF_bit = 0;
   RCIE_bit = 1;
   RCIP_bit = 1;     // High priority with uart
   // End Config //
   
   // Interrupt with Timer0 //
   TMR0IE_bit = 1;
   TMR0IF_bit = 0;
   TMR0IP_bit = 0;   // Low priority
   // End Config //
   
   // Interrupt with External Interrupt 0 with High Priority //
   INT0IE_bit = 1;
   INT0IF_bit = 0;
   INTEDG0_bit = 0;  // Falling edge
   // End Config //
   
   // Interrupt with External Interrupt 2 with Low Priority //
   INT2E_bit = 1;
   INT2IF_bit = 0;
   INT2IP_bit = 0;   // Low Priority
   INTEDG2_bit = 1;  // Rising edge
   // End Config //
   
   return;
}

void Timer0_init(void)
{
   // Timer0 Config //
   T08BIT_bit = 0;   // 16bits counter
   T0CS_bit = 0;     // Internal clock
   T0SE_bit = 0;
   PSA_bit = 0;      // Prescaler assinged
   T0PS0_bit = 0;
   T0PS1_bit = 0;    // 1:2 prescaler
   T0PS2_bit = 0;
   TMR0ON_bit = 1;   // Enable timer0

   TMR0L = 0X90;     // 59536 = 1ms para 48MHz
   TMR0H = 0xE8;
   // End //

   return;
}

unsigned long long milis(void)
{
   unsigned long long milis=ms;
   
   return milis;
}

void Antirrebote_Encoder(void)
{
   INT0IE_bit = 0;   // Disabled Interrupt
   Encoder_E = 1;    // Delay for Encoder

   // Buzzer //
   BUZZER_HIGH;
   // End //

   return;
}

void Task_Detected(void)
{
   if(!_Delay_Encoder)
   {
      // Encoder //
      _Delay_Encoder = DELAY_ENCODER;
      Encoder_E = 0;
      INT0IF_bit = 0;
      INT0IE_bit = 1;   // Enable Interrupt
      // End //
      
      // Buzzer //
      BUZZER_LOW;
      // End //
   }

   return;
}

void ISR_HP() iv 0x0008 ics ICS_AUTO
{       //HIGH PRIORITY
   if(RCIF_bit==1)
   {
      RCIF_bit = 0;
      Reception();
   }
   if(INT0IF_bit==1)
   {
      INT0IF_bit = 0;
      
      if(ENCODER_B_READ)         Pos++;
      else if(!ENCODER_B_READ)   Pos--;
      
      Antirrebote_Encoder();
   }

   return;
}

void ISR_LP() iv 0x0018 ics ICS_AUTO
{      //LOW PRIORITY
   if(TMR0IF_bit==1)
   {
      TMR0IF_bit = 0;
      TMR0L = 0X90;
      TMR0H = 0xE8;
      
      ms++;
      
      if(Encoder_E)  _Delay_Encoder--;
      Task_Detected();  // Verified if a task has finished
   }
   if(INT2IF_bit==1)
   {
      INT2IF_bit = 0;
      
   }

   return;
}