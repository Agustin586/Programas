#line 1 "C:/Users/aguat/OneDrive/Programacion Microcontroladores/Github/Programas/MikroC/Proyecto_Laboratorio/Programa/MEF.c"
#line 1 "c:/users/aguat/onedrive/programacion microcontroladores/github/programas/mikroc/proyecto_laboratorio/programa/mef.h"
#line 1 "c:/users/aguat/onedrive/programacion microcontroladores/github/programas/mikroc/proyecto_laboratorio/programa/serial.h"



extern volatile char Rx;
extern volatile bit echo;

void Serial_writeInit(void);
void Reception(void);
void Echo_Tx(void);
#line 1 "c:/users/aguat/onedrive/programacion microcontroladores/github/programas/mikroc/proyecto_laboratorio/programa/display.h"
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
#line 7 "c:/users/aguat/onedrive/programacion microcontroladores/github/programas/mikroc/proyecto_laboratorio/programa/display.h"
char TFT_DataPort at LATD;
sbit TFT_RD at LATB3_bit;
sbit TFT_WR at LATB4_bit;
sbit TFT_RS at LATB5_bit;
sbit TFT_CS at LATB6_bit;
sbit TFT_RST at LATB7_bit;

char TFT_DataPort_Direction at TRISD;
sbit TFT_RD_Direction at TRISB3_bit;
sbit TFT_WR_Direction at TRISB4_bit;
sbit TFT_RS_Direction at TRISB5_bit;
sbit TFT_CS_Direction at TRISB6_bit;
sbit TFT_RST_Direction at TRISB7_bit;



void Display_init(void);
void ChangeTheme(void);
void MenuGenerator(unsigned char menu_cant,unsigned char separacion,unsigned char _widthEdge);
void Selector(unsigned char estate);
void SubmMenu_DisplayInit(void);
void StaticDisplay(void);
void DateUpdated(void);
void ThemeUpdated(void);

static const char autor[]="Autor: Zuliani,Agustin";
static const char fecha[]="Fecha inicio: 11/1/2021";
static const char progm[]="Programa: Control de salidas a Rele y Triac";
static unsigned int x=0;
static unsigned char y=0;
extern uint8_t week,day,month,year,hour,minute,second;

extern volatile char Pos=0;
static const unsigned char _ESTATE_INIT=0;
static const unsigned char _ESTATE_MENU=1;
static const unsigned char _ESTATE_OUTPUT=2;
static const unsigned char _ESTATE_RTC=3;
static const unsigned char _ESTATE_TESTING=4;
static const unsigned char _ESTATE_UART=5;
static const unsigned char _ESTATE_THEME=6;

static struct button
{
 unsigned int Xs;
 unsigned int Xe;
 unsigned char Ys;
 unsigned char Ye;
 unsigned int edgeColour;
 unsigned int backgroundColour;
 unsigned char width;
};

static struct theme
{
 unsigned int screenColour;
 unsigned int letterColour;
 unsigned int backgroundletterColour;
 unsigned int edgeColour;
};

static struct theme actual_theme;
#line 8 "c:/users/aguat/onedrive/programacion microcontroladores/github/programas/mikroc/proyecto_laboratorio/programa/mef.h"
void Mef_init(void);
void Mef_Updated(void);
void SubEst_MENU_Updated(void);

extern volatile bit echo;
extern volatile char Rx;

typedef enum
{
 ESTATE_INIT,
 ESTATE_MENU,
 ESTATE_OUTPUT,
 ESTATE_RTC,
 ESTATE_TESTING,
 ESTATE_UART,
 ESTATE_THEME,
}MEFestado_t;

static MEFestado_t Estado_Actual;

typedef enum
{
 SUBM_MENU_INIT,
 SUBM_MENU_SELECT,
}SUBM_MENUestado_t;

static SUBM_MENUestado_t SubEst_Menu;
#line 3 "C:/Users/aguat/OneDrive/Programacion Microcontroladores/Github/Programas/MikroC/Proyecto_Laboratorio/Programa/MEF.c"
void Mef_init(void)
{
 Estado_Actual = ESTATE_INIT;
 SubEst_Menu = SUBM_MENU_INIT;

 return;
}

void Mef_Updated(void)
{
 switch(Estado_Actual)
 {
 case ESTATE_INIT:
 {
 Serial_writeInit();
 Display_init();

 Estado_Actual = ESTATE_MENU;
 break;
 }
 case ESTATE_MENU:
 {
 SubEst_MENU_Updated();

 if(echo) Estado_Actual = ESTATE_UART;
 break;
 }
 case ESTATE_OUTPUT:
 {
 break;
 }
 case ESTATE_RTC:
 {
 break;
 }
 case ESTATE_TESTING:
 {
 break;
 }
 case ESTATE_UART:
 {
 if(echo) Echo_Tx(),echo=0;

 Estado_Actual = ESTATE_MENU;
 break;
 }
 case ESTATE_THEME:
 {

 break;
 }
 }

 return;
}

void SubEst_MENU_Updated(void)
{
 switch(SubEst_Menu)
 {
 case SUBM_MENU_INIT:
 {
 Pos = 1;
 ChangeTheme();
 SubmMenu_DisplayInit();
 Pos = 0;

 SubEst_Menu = SUBM_MENU_SELECT;
 break;
 }
 case SUBM_MENU_SELECT:
 {

 break;
 }
 }

 return;
}
