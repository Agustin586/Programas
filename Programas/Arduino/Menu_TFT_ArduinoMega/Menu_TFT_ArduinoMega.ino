/*
 * 
 *  La idea de este proyecto es utilizar la pantalla tft con el arduino mega:
 *  Para esto tenemos un menu en que vamos a utilizar enconder rotativo para seleccionar
 *  y en el primer menu tenemos que seleccionar que led prender; en el segundo es una
 *  barra semicircular que se va llenando. Todavia esta en proceso el proyecto, puede
 *  cambiar en el transcurso.
 * 
 *  PORTRAIT  CALIBRATION     240 x 320
 *  x = map(p.x, LEFT=97, RT=929, 0, 240)
 *  y = map(p.y, TOP=66, BOT=907, 0, 320)
 * 
 *  LANDSCAPE CALIBRATION     320 x 240
 *  x = map(p.y, LEFT=66, RT=907, 0, 320)
 *  y = map(p.x, TOP=929, BOT=97, 0, 240)
 *  
 */

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include "Maquinas_Estados_Finitas.h"
#include "Display_TFT.h"
#include "Touchscreen2.h"

const int XP = 8, XM = A2, YP = A3, YM = 9; //ID=0x9341
const int TS_LEFT = 907, TS_RT = 66, TS_TOP = 97, TS_BOT = 929;

MCUFRIEND_kbv tft;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Adafruit_GFX_Button aceptar_btn = Adafruit_GFX_Button();

//Variables del programa
unsigned char Prtj_carga=0,Menu=1;
bool mostrar=false;
unsigned int Estado_Actual=0,pixel_x,pixel_y;

//Funciones de de incializacion
void setup() 
{
    Serial.begin(9600);
    Serial.println(" ");
    Serial.println("------------------------------------------------------------");
    Serial.println("Programa: Menu para TFT");
    Serial.println("Controlador: Arduino Mega 2560");
    Serial.println("Autor: Zuliani, Agustin");
    Serial.println("------------------------------------------------------------");
    Serial.println("Espere mientras carga el programa...");

    Pantalla_Setup();       // Configura la pantalla tft
    Mef_init();             // Inicializa la maquina de estados finitas

    Serial.println("Programa cargado");
    Serial.println("------------------------------------------------------------");
}

void loop()
{  
    Mef_Updated();
}
