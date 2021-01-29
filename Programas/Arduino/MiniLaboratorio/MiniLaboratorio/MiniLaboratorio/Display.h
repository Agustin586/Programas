#ifndef _DISPLAY_H
#define _DISPLAY_H

// Includes //
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include "Fonts.h"
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>
#include <FreeDefaultFonts.h>
// End //

// Variables //
extern volatile uint8_t Opc, OpcAnt;
unsigned int posX = 0, posY = 0;
extern bool Relay1, Relay2, Relay3, Relay4;

struct theme
{
	unsigned int screenColour;
	unsigned int letterColour;
	unsigned int backgroundletterColour;
	unsigned int edgeColour;
};
struct theme actual_theme;

struct Strings
{
	unsigned int xS;
	unsigned int yS;
	unsigned int letterColour;
	unsigned int backgroundColour;
	unsigned char size;
};
struct Strings StrgRelay { 10, 100, actual_theme.letterColour, actual_theme.backgroundletterColour, 2 };
struct Strings StrgTheme { 10, 160, actual_theme.letterColour, actual_theme.backgroundletterColour, 2 };
struct Strings StrgRtc { 10, 130, actual_theme.letterColour, actual_theme.backgroundletterColour, 2 };
struct Strings StrgHome { 10, 60, actual_theme.edgeColour, actual_theme.backgroundletterColour, 2 };
struct Strings StrgRelay1Est {215, 50, actual_theme.letterColour, actual_theme.backgroundletterColour, 1};
struct Strings StrgRelay2Est { 215, 65, actual_theme.letterColour, actual_theme.backgroundletterColour, 1 };
struct Strings StrgRelay3Est { 215, 80, actual_theme.letterColour, actual_theme.backgroundletterColour, 1 };
struct Strings StrgRelay4Est { 215, 95, actual_theme.letterColour, actual_theme.backgroundletterColour, 1 };

struct Rect
{
	unsigned int xS;
	unsigned int yS;
	unsigned int xE;
	unsigned int yE;
	unsigned int backgroundColour;
	unsigned int edgeColour;
	unsigned char radius;
};
struct Rect RectEdge { 1, 1, 319, 239, 0,actual_theme.edgeColour, 0};
struct Rect RectBgnd { 5, 95, 200, 120, actual_theme.edgeColour, 0, 20 };
struct Rect RectStaticReleATemp { 210, 46, 310, 230, 0, actual_theme.edgeColour, 0};

struct Line
{
	unsigned int xS;
	unsigned int yS;
	unsigned int xE;
	unsigned int yE;
	unsigned int Colour;
};
struct Line LineEdge { 6, 36, 313, 0, actual_theme.edgeColour};
struct Line LineHigh { 5, 80, 200, 0, actual_theme.edgeColour };
struct Line LineLow { 5, 200, 200, 0, actual_theme.edgeColour };
struct Line LineDivisor { 210, 110, 310, 0, actual_theme.edgeColour};

struct Circle
{
	unsigned int xS;
	unsigned int yS;
	unsigned int radius;
	unsigned int Colour;
};
struct Circle _Relay1Est { 270, 53, 3};
struct Circle _Relay2Est { 270, 68, 3};
struct Circle _Relay3Est { 270, 83, 3 };
struct Circle _Relay4Est { 270, 98, 3 };

struct Rtc
{
	unsigned int value;
	unsigned int xS;
	unsigned int yS;
	uint8_t size;
};
struct Rtc _date { 19, 110, 15, 2 };
struct Rtc month { 11, 0, 0, 2 };
struct Rtc year { 2021, 0, 0, 2 };
struct Rtc hour {22, 0, 0, 2};
struct Rtc minutes { 22, 0, 0, 2};
// End //

// Functions Prototipes //
void Display_Init(void);
void DisplaySetLetterParamether(unsigned int TxtColour, unsigned int TxtBackgroundColour, unsigned int PosX, unsigned int PosY, unsigned char Size, const char Text[]);
void Display_StaticShow(void);
void ChangeTheme(void);
void UpdatedTheme(void);
void UpdatedDateATime(void);
void UpdatedRelaysEstates(void);
// End //

// Functions body //
void Display_Init(void)
{
	tft.begin(0x9341);	// Setup tft lcd
	tft.setRotation(1);	// 90°
	tft.fillScreen(TFT_BLACK);

	Opc = 1;
	ChangeTheme();

	return;
}
void Display_StaticShow(void)
{
	tft.fillScreen(actual_theme.screenColour);
	tft.drawRect(RectEdge.xS, RectEdge.yS, RectEdge.xE-RectEdge.xS, RectEdge.yE-RectEdge.yS, RectEdge.edgeColour);
	tft.drawFastHLine(LineEdge.xS, LineEdge.yS, LineEdge.xE-LineEdge.xS, LineEdge.Colour);

	return;
}
void DisplaySetLetterParamether(unsigned int TxtColour, unsigned int TxtBackgroundColour, unsigned int PosX, unsigned int PosY, unsigned char Size, const char Text[])
{
	tft.setTextColor(TxtColour,TxtBackgroundColour);
	tft.setCursor(PosX, PosY);
	tft.setTextSize(Size);
	tft.print(Text);

	return;
}
void ChangeTheme(void)
{
	struct theme dark_green = {TFT_BLACK,TFT_DARKGREEN,TFT_BLACK,TFT_WHITE};
	struct theme dark_yellow = {TFT_BLACK,TFT_YELLOW,TFT_BLACK,TFT_ORANGE};
	struct theme pink_black = {TFT_PINK,TFT_BLACK,TFT_PINK,TFT_BLACK};
	struct theme blue_white = {TFT_BLUE,TFT_WHITE,TFT_CYAN,TFT_BLACK};
	struct theme white_blue = {TFT_WHITE,TFT_BLUE,TFT_CYAN,TFT_BLACK};

	if (Opc == 1)        actual_theme = dark_green;
	else if (Opc == 2)   actual_theme = pink_black;
	else if (Opc == 3)   actual_theme = blue_white;
	else if (Opc == 4)   actual_theme = white_blue;
	else if (Opc == 5)	actual_theme = dark_yellow;

	UpdatedTheme();

	return;
}
void UpdatedTheme(void)
{
	StrgRelay.backgroundColour = actual_theme.backgroundletterColour;
	StrgRtc.backgroundColour = actual_theme.backgroundletterColour;
	StrgTheme.backgroundColour = actual_theme.backgroundletterColour;
	StrgHome.backgroundColour = actual_theme.backgroundletterColour;
	StrgRelay1Est.backgroundColour = actual_theme.backgroundletterColour;
	StrgRelay2Est.backgroundColour = actual_theme.backgroundletterColour;
	StrgRelay3Est.backgroundColour = actual_theme.backgroundletterColour;
	StrgRelay4Est.backgroundColour = actual_theme.backgroundletterColour;
	
	StrgRelay.letterColour = actual_theme.letterColour;
	StrgRtc.letterColour = actual_theme.letterColour;
	StrgTheme.letterColour = actual_theme.letterColour;
	StrgRelay.letterColour = actual_theme.letterColour;
	StrgHome.letterColour = actual_theme.edgeColour;
	StrgRelay1Est.letterColour = actual_theme.letterColour;
	StrgRelay2Est.letterColour = actual_theme.letterColour;
	StrgRelay3Est.letterColour = actual_theme.letterColour;
	StrgRelay4Est.letterColour = actual_theme.letterColour;

	RectEdge.edgeColour = actual_theme.edgeColour;
	RectBgnd.backgroundColour = actual_theme.edgeColour;
	RectStaticReleATemp.edgeColour = actual_theme.edgeColour;

	LineEdge.Colour = actual_theme.edgeColour;
	LineHigh.Colour = actual_theme.edgeColour;
	LineLow.Colour = actual_theme.edgeColour;
	LineDivisor.Colour = actual_theme.edgeColour;

	return;
}
void UpdatedDateATime(void)
{
	tft.setTextColor(actual_theme.letterColour, actual_theme.backgroundletterColour);
	tft.setCursor(_date.xS, _date.yS);
	tft.setTextSize(_date.size);
	tft.print(_date.value), tft.print("/"), tft.print(month.value), tft.print("/"), tft.print(year.value);
	tft.print("  "), tft.print(hour.value), tft.print(":"), tft.print(minutes.value);

	return;
}
void UpdatedRelaysEstates(void)
{
	if (Relay1 == true)	_Relay1Est.Colour = TFT_GREEN;
	else				_Relay1Est.Colour = TFT_RED;

	if (Relay2 == true)	_Relay2Est.Colour = TFT_GREEN;
	else				_Relay2Est.Colour = TFT_RED;

	if (Relay3 == true)	_Relay3Est.Colour = TFT_GREEN;
	else				_Relay3Est.Colour = TFT_RED;

	if (Relay4 == true)	_Relay4Est.Colour = TFT_GREEN;
	else				_Relay4Est.Colour = TFT_RED;

	tft.fillCircle(_Relay1Est.xS, _Relay1Est.yS, _Relay1Est.radius, _Relay1Est.Colour);
	tft.fillCircle(_Relay2Est.xS, _Relay2Est.yS, _Relay2Est.radius, _Relay2Est.Colour);
	tft.fillCircle(_Relay3Est.xS, _Relay3Est.yS, _Relay3Est.radius, _Relay3Est.Colour);
	tft.fillCircle(_Relay4Est.xS, _Relay4Est.yS, _Relay4Est.radius, _Relay4Est.Colour);

	return;
}
// End //

#endif // !_DISPLAY_H
