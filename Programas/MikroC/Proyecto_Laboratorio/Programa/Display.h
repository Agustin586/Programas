#ifndef DISPLAY_H
#define DISPLAY_H

#include "Clock.h"

// TFT display connections
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
// End of TFT display connections

// Funtions //
void Display_init(void);
void ChangeTheme(void);
void MenuGenerator(unsigned char menu_cant,unsigned char separacion,unsigned char _widthEdge);
void Selector(unsigned char estate);
void SubmMenu_DisplayInit(void);
void StaticDisplay(void);  // ALL MENUS AND SUBMENUS MUST LOAD THIS FUNCTION
void DateUpdated(void);    // UPDATE DATE AND TIME
void ThemeUpdated(void);
// Variables //
static const char autor[]="Autor: Zuliani,Agustin";
static const char fecha[]="Fecha inicio: 11/1/2021";
static const char progm[]="Programa: Control de salidas a Rele y Triac";
static unsigned int  x=0;
static unsigned char y=0;  // Xmax = 320 y Ymax = 240
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

#endif