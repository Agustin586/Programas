#pragma once

#ifndef TOUCHSCREEN2_H
#define TOUCHSCREEN2_H

#include "Display_TFT.h"
#include <TouchScreen.h>

#define MINPRESSURE 20
#define MAXPRESSURE 1000

#define Obtener_touch Touch_getXY

extern unsigned int pixel_x,pixel_y;     
extern const int XP,XM,YP,YM; 
extern const int TS_LEFT,TS_RT,TS_TOP,TS_BOT;

extern MCUFRIEND_kbv tft;
extern TouchScreen ts;

bool Touch_getXY(void)
{
    TSPoint p = ts.getPoint();  // Accese a los atributos de la clase TouchScreen --> x,y,z

    // Configuracion pines
    pinMode(YP, OUTPUT);      
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   
    digitalWrite(XM, HIGH);
    // Fin configuracion pines

    bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);

    if (pressed) 
    {
        pixel_y = map(p.x, TS_LEFT, TS_RT, 0, 240); 
        pixel_x = map(p.y, TS_TOP, TS_BOT, 0, 320);

        if(pixel_x>320) pixel_x=320;
        if(pixel_y>240) pixel_y=240;
        
        /*Serial.print("Touch X:"), Serial.println(pixel_x);
        Serial.print("Touch Y:"), Serial.println(pixel_y);*/
    }
    
    delay(100);
    
    return pressed;
}

#endif // !TOUCHSCREEN2_H
