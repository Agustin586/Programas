#line 1 "C:/Users/aguat/OneDrive/Programacion Microcontroladores/Github/Programas/MikroC/Proyecto_Laboratorio/Programa/Display.c"
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
#line 5 "C:/Users/aguat/OneDrive/Programacion Microcontroladores/Github/Programas/MikroC/Proyecto_Laboratorio/Programa/Display.c"
void Display_init(void)
{
 unsigned int _load=0;
 struct button load = {5,300,240-27,240-2,CL_BLUE};






 TFT_Fill_Screen(CL_WHITE);
 x=2,y=2;
 TFT_Set_Pen(CL_BLACK, 2);
 TFT_Rectangle(x,y,x+298,y+60);

 x=5,y=5;
 TFT_Set_Font(TFT_defaultFont, CL_RED, FO_HORIZONTAL);
 TFT_Write_Const_Text(autor,x,y);
 y+=20;
 TFT_Write_Const_Text(fecha,x,y);
 y+=20;
 TFT_Write_Const_Text(progm,x,y);


 x=2;
 TFT_Set_Pen(CL_BLUE, 2);
 TFT_Rectangle(load.Xs,load.Ys,load.Xe+3,load.Ye);
 Delay_ms(30);

 TFT_Set_Brush(1,load.backgroundColour,0,0,0,0);


 for(_load=5;_load<301;_load++)
 {
 TFT_Rectangle(_load,load.Ys,(load.Xs-2)+_load,load.Ye);
 Delay_ms(10);
 }
 Delay_ms(1500);


 return;
}





void SubmMenu_DisplayInit(void)
{
 StaticDisplay();
 MenuGenerator(4,10,2);

 return;
}



void ChangeTheme(void)
{
 struct theme dark_green = {CL_BLACK,CL_WHITE,CL_LIME,CL_GREEN};
 struct theme fuchsia_black = {CL_FUCHSIA,CL_BLACK,CL_FUCHSIA,CL_BLACK};
 struct theme blue_white = {CL_BLUE,CL_WHITE,CL_AQUA,CL_BLACK};
 struct theme white_blue = {CL_WHITE,CL_BLUE,CL_AQUA,CL_BLACK};

 if(Pos==1) actual_theme = dark_green;
 else if(Pos==2) actual_theme = fuchsia_black;
 else if(Pos==3) actual_theme = blue_white;
 else if(Pos==4) actual_theme = white_blue;

 ThemeUpdated();

 return;
}



void MenuGenerator(unsigned char menu_cant,unsigned char separacion,unsigned char _widthEdge)
{
 char i=1;
 unsigned char width=((316/(menu_cant/2))-(separacion*2));
 unsigned char high=((213/(menu_cant/2))-(separacion*2));


 struct button button1;
 button1.Xs = 2;
 button1.Ys = 25;
 button1.Xe = button1.Xs + width;
 button1.Ye = button1.Ys + high;
 button1.backgroundColour = actual_theme.backgroundletterColour;
 button1.edgeColour = actual_theme.edgeColour;
 button1.width = _widthEdge;



 TFT_Set_Pen(button1.edgeColour,button1.width);
 TFT_Set_Brush(1,button1.backgroundColour,0,0,0,0);



 for(i=1;i<=menu_cant;i++)
 {
 TFT_Rectangle_Round_Edges(button1.Xs+separacion,button1.Ys+separacion,button1.Xe,button1.Ye,12);
 button1.Xs = button1.Xe;
 button1.Xe = separacion + width;
 button1.Ys = button1.Ye;
 button1.Ye = separacion + high;
 }

 ThemeUpdated();

 return;
}

void Selector(unsigned char estate)
{
 if(estate==_ESTATE_MENU)
 {

 }
 else if(estate==_ESTATE_OUTPUT)
 {

 }
 else if(estate==_ESTATE_THEME)
 {

 }

 return;
}

void StaticDisplay(void)
{
 TFT_Fill_Screen(actual_theme.screenColour);


 TFT_Rectangle(1,1,319,239);
 TFT_H_Line(10,310,25);

 DateUpdated();

 return;
}

void DateUpdated(void)
{
 char buffer1[4];


 TFT_Set_Brush(1,actual_theme.screenColour,0,0,0,0);
 TFT_Set_Pen(actual_theme.screenColour, 3);
 TFT_Rectangle(200,4,316,22);
 ThemeUpdated();



 x=210;
 y=4;
 IntToStr(day,buffer1),TFT_Write_Text("11/11/11   12:12",x,y);
#line 187 "C:/Users/aguat/OneDrive/Programacion Microcontroladores/Github/Programas/MikroC/Proyecto_Laboratorio/Programa/Display.c"
 return;
}

void ThemeUpdated(void)
{
 TFT_Set_Font(TFT_defaultFont,actual_theme.letterColour,FO_HORIZONTAL);
 TFT_Set_Brush(0,actual_theme.backgroundletterColour,0,0,0,0);
 TFT_Set_Pen(actual_theme.edgeColour, 1);

 return;
}
