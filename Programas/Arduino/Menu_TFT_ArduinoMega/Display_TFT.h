#pragma once

#ifndef DISPLAY_TFT_H
#define DISPLAY_TFT_H

extern const int XP, XM, YP, YM;
extern const int TS_LEFT, TS_RT, TS_TOP, TS_BOT;

extern MCUFRIEND_kbv tft;
extern TouchScreen ts;
extern Adafruit_GFX_Button aceptar_btn;

#define MINPRESSURE 200
#define MAXPRESSURE 1000

//Colores disponibles
#define TFT_BLACK       0x0000      /*   0,   0,   0 */
#define TFT_NAVY        0x000F      /*   0,   0, 128 */
#define TFT_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define TFT_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define TFT_MAROON      0x7800      /* 128,   0,   0 */
#define TFT_PURPLE      0x780F      /* 128,   0, 128 */
#define TFT_OLIVE       0x7BE0      /* 128, 128,   0 */
#define TFT_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define TFT_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define TFT_BLUE        0x001F      /*   0,   0, 255 */
#define TFT_GREEN       0x07E0      /*   0, 255,   0 */
#define TFT_CYAN        0x07FF      /*   0, 255, 255 */
#define TFT_RED         0xF800      /* 255,   0,   0 */
#define TFT_MAGENTA     0xF81F      /* 255,   0, 255 */
#define TFT_YELLOW      0xFFE0      /* 255, 255,   0 */
#define TFT_WHITE       0xFFFF      /* 255, 255, 255 */
#define TFT_ORANGE      0xFDA0      /* 255, 180,   0 */
#define TFT_GREENYELLOW 0xB7E0      /* 180, 255,   0 */
#define TFT_PINK        0xFC9F

extern unsigned char Prtj_carga,Menu;
extern bool mostrar;

void Selector_Menu(void);
void Creador_Pulsadores_Touch(void);

/////////////////////////////////////////////////////////////////////////////////////////
void Pantalla_Setup(void)
{
    // Configuraciones iniciales
    tft.reset();                    // Enviamos un reset por hardware para comenzar
    tft.begin(0x9341);              // Controlador ili9341
    tft.setRotation(1);             // Seteamos a 90°
    tft.fillScreen(TFT_WHITE);      // Limpia la pantalla de color blanco

    // Pantalla de carga
    tft.drawRect(10, 180, 300, 50, TFT_BLACK);  // Barra de carga
    tft.setTextSize(2);                         // Primera frase de presentacion
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft.setCursor(90, 20);  
    tft.print("Bienvenido");                    // Fin frase de presentacion
    tft.setCursor(25, 40);                      // Segunda frase de presentacion    
    tft.print("Espere mientra carga");          // Fin segunda frase de presentacion

    // Animacion de carga
    unsigned int Barra = 0;
    while (Prtj_carga!=100)
    {
        Prtj_carga += 1;                // Porcetaje de carga total
        Barra = Prtj_carga * 3;         // Regla de 3 para setear la barra azul 
        if (Barra > 300) Barra = 300;   // Maximo de barra azul

        tft.setTextSize(7);                         // Muestra valor en porcentaje
        tft.setTextColor(TFT_BLUE, TFT_WHITE);
        tft.setCursor(90, 100);
        tft.print(Prtj_carga), tft.print("%");      // Fin muestra valor en porcentaje
        tft.fillRect(10, 180, Barra, 50, TFT_BLUE); // Dibuja la barra azul de carga
        delay(30);
    }

    tft.fillScreen(TFT_BLACK);          // Limpia pantalla

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
void Pantalla_inicial(void)
{
    //Menu
    tft.setTextSize(5); tft.setTextColor(TFT_RED, TFT_BLACK);   // Muestra palabra "Menu"
    tft.setCursor(100, 20); tft.print("Menu");                  // Fin muestra palabra "Menu"
    //Opciones:
    Selector_Menu();                                            // Selecciona el menu 
    Creador_Pulsadores_Touch();                                 // Crea el pulsador

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
void Pantalla_Menu(void)
{
    
    
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
void Selector_Menu(void)
{
    if (Menu == 1)
    {
        tft.fillRect(0, 68, 310, 20, TFT_WHITE);                // Selecciona la opcion 1
        tft.fillRect(0, 98, 310, 20, TFT_BLACK);                // Fin seleccion opcion 1
    }
    if (Menu == 2)
    {
        tft.fillRect(0, 98, 310, 20, TFT_WHITE);                // Selecciona la opcion 2
        tft.fillRect(0, 68, 310, 20, TFT_BLACK);                // Fin seleccion opcion 2
    }

    tft.setTextSize(2); tft.setTextColor(TFT_BLUE, TFT_WHITE);  // Muestra los menus
    tft.setCursor(10, 70); tft.print("LEDS");
    tft.setTextSize(2); tft.setTextColor(TFT_BLUE, TFT_BLACK);
    tft.setCursor(10, 100); tft.print("MEDIDOR");               // Fin muestra los menus

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
void Creador_Pulsadores_Touch(void)
{
    aceptar_btn.initButton(&tft, 160, 200, 300, 38, TFT_WHITE, TFT_CYAN, TFT_BLACK, "Aceptar", 2);
    aceptar_btn.drawButton(false);

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////

#endif // !DISPLAY_TFT_H
#
