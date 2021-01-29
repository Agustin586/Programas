#ifndef _DISPLAY_ESTATE_INIT_H
#define _DISPLAY_ESTATE_INIT_H

// Includes //
#include "Display.h"

// Variables //
const char author[] = "Author: Zuliani,Agustin";
const char date[] = "Date: 17/01/2021";
const char desp[] = "Program: Control of Relays,Triacs and RTC";
const char load[] = "Load: ";

// Functions //
void Display_ESTATE_INIT(void);

void Display_ESTATE_INIT(void)
{
	//tft.setFont(&FreeSans9pt7b);
	posY = 20;
	DisplaySetLetterParamether(actual_theme.letterColour, actual_theme.backgroundletterColour, posX, posY, 2, author);
	posY += 30;
	DisplaySetLetterParamether(actual_theme.letterColour, actual_theme.backgroundletterColour, posX, posY, 2, date);
	posY += 30;
	DisplaySetLetterParamether(actual_theme.letterColour, actual_theme.backgroundletterColour, posX, posY, 2, desp);
	posY = 240 - 30;
	DisplaySetLetterParamether(actual_theme.letterColour, actual_theme.backgroundletterColour, posX, posY, 2, load);

	for (uint8_t i = 1; i <= 100; i++)
	{
		tft.setCursor(posX + 70, posY);
		tft.print("%"), tft.print(i);
		delay(30);
	}

	delay(1000);

	return;
}

#endif // !_DISPLAY_ALL_INITS_H
