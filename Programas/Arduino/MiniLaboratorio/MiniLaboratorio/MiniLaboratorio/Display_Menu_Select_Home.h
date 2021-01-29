#ifndef _DISPLAY_MENU_SELECT_HOME_H
#define _DISPLAY_MENU_SELECT_HOME_H

// Includes //
#include "Display.h"

// Variables //
const char relay[] = "Relay settings";
const char _theme[] = "Theme settings";
const char rtc[] = "Rtc settings";

// Functions //
void Display_MENU_SELECT_HOME(void);
void Display_MENU_SELECT_HOME_Scroll1(void);
void Display_MENU_SELECT_HOME_Scroll2(void);
void Display_MENU_SELECT_HOME_Scroll3(void);
void Display_MENU_SELECT_HOME_Options(void);
void Display_MENU_SELECT_HOME_ClearOldOption(unsigned int _xS, unsigned int _yS, unsigned int _xE, unsigned int _yE);
void Display_MENU_SELECT_HOME_DrawNewOption(unsigned int _xS, unsigned int _yS, unsigned int _xE, unsigned int _yE);

void Display_MENU_SELECT_HOME(void)
{
	if (Opc != OpcAnt)
	{
		OpcAnt = Opc;
		if (Opc == 1)
		{
			Display_MENU_SELECT_HOME_Scroll1();
		}
		else if (Opc == 2)
		{
			Display_MENU_SELECT_HOME_Scroll2();
		}
		else if (Opc == 3)
		{
			Display_MENU_SELECT_HOME_Scroll3();
		}
	}

	return;
}
void Display_MENU_SELECT_HOME_Scroll1(void)
{
	// Draw selector //
	Display_MENU_SELECT_HOME_ClearOldOption( 5, 125, 200, 150);
	Display_MENU_SELECT_HOME_ClearOldOption(5, 155, 200, 180);
	
	// Draw selector //
	Display_MENU_SELECT_HOME_DrawNewOption( 5, 95, 200, 120);
		
	// Print Menu selection //
	StrgRelay.backgroundColour = RectBgnd.backgroundColour;
	Display_MENU_SELECT_HOME_Options();	// Write Menu Home Options
	// End //

	UpdatedTheme();		// Reset colour for all

	return;
}
void Display_MENU_SELECT_HOME_Scroll2(void)
{
	// Clear old option //
	Display_MENU_SELECT_HOME_ClearOldOption(5, 95, 200, 120);
	Display_MENU_SELECT_HOME_ClearOldOption( 5, 155, 200, 180);

	// Draw selector //
	Display_MENU_SELECT_HOME_DrawNewOption(5, 125, 200, 150);

	// Print Menu selection //
	StrgRtc.backgroundColour = RectBgnd.backgroundColour;
	Display_MENU_SELECT_HOME_Options();	// Write Menu Home Options
	// End //

	UpdatedTheme();		// Reset colour for all
	
	return;
}
void Display_MENU_SELECT_HOME_Scroll3(void)
{
	// Clear old option //
	Display_MENU_SELECT_HOME_ClearOldOption(5, 125, 200, 150);
	Display_MENU_SELECT_HOME_ClearOldOption(5, 95, 200, 120);

	// Draw selector //
	Display_MENU_SELECT_HOME_DrawNewOption(5, 155, 200, 180);

	// Print Menu selection //
	StrgTheme.backgroundColour = RectBgnd.backgroundColour;
	Display_MENU_SELECT_HOME_Options();	// Write Menu Home Options
	// End //

	UpdatedTheme();		// Reset colour for all

	return;
}
void Display_MENU_SELECT_HOME_Options(void)
{
	if (Opc <= 3)
	{
		// String Relay //
		DisplaySetLetterParamether(StrgRelay.letterColour, StrgRelay.backgroundColour, StrgRelay.xS, StrgRelay.yS, StrgRelay.size, relay);
		// String Rtc //
		DisplaySetLetterParamether(StrgRtc.letterColour, StrgRtc.backgroundColour, StrgRtc.xS, StrgRtc.yS, StrgRtc.size, rtc);
		// String Theme //
		DisplaySetLetterParamether(StrgTheme.letterColour, StrgTheme.backgroundColour, StrgTheme.xS, StrgTheme.yS, StrgTheme.size, _theme);
	}

	return;
}
void Display_MENU_SELECT_HOME_ClearOldOption(unsigned int _xS, unsigned int _yS, unsigned int _xE, unsigned int _yE)
{
	RectBgnd.xS = _xS,   RectBgnd.xE = _xE;
	RectBgnd.yS = _yS; RectBgnd.yE = _yE;
	RectBgnd.backgroundColour = actual_theme.backgroundletterColour;
	tft.fillRoundRect(RectBgnd.xS, RectBgnd.yS, RectBgnd.xE - RectBgnd.xS, RectBgnd.yE - RectBgnd.yS, RectBgnd.radius, RectBgnd.backgroundColour);

	return;
}
void Display_MENU_SELECT_HOME_DrawNewOption(unsigned int _xS, unsigned int _yS, unsigned int _xE, unsigned int _yE)
{
	RectBgnd.xS = _xS, RectBgnd.xE = _xE;
	RectBgnd.yS = _yS; RectBgnd.yE = _yE;
	RectBgnd.backgroundColour = actual_theme.edgeColour;
	tft.fillRoundRect(RectBgnd.xS, RectBgnd.yS, RectBgnd.xE - RectBgnd.xS, RectBgnd.yE - RectBgnd.yS, RectBgnd.radius, RectBgnd.backgroundColour);

	return;
}

#endif // !_DISPLAY_MENU_SELECT_HOME_H

