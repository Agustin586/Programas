/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

/*
 * 
 * La idea de este proyecto es utilizar la pantalla tft con el arduino mega:
 *  Para esto tenemos un menu en que vamos a utilizar enconder rotativo para seleccionar
 *  y en el primer menu tenemos que seleccionar que led prender; en el segundo es una
 *  barra semicircular que se va llenando. Todavia esta en proceso el proyecto, puede
 *  cambiar en el transcurso.
 * 
 * PORTRAIT  CALIBRATION     240 x 320
 *  x = map(p.x, LEFT=97, RT=929, 0, 240)
 *  y = map(p.y, TOP=66, BOT=907, 0, 320)
 * 
 *  LANDSCAPE CALIBRATION     320 x 240
 *  x = map(p.y, LEFT=66, RT=907, 0, 320)
 *  y = map(p.x, TOP=929, BOT=97, 0, 240)
 *  
 */
//Incluimos las librerias para manejar la pantalla tft
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;       
#include <TouchScreen.h>
//Beginning of Auto generated function prototypes by Atmel Studio
void Mef_init(void );
void Mef_Updated(void );
void Pantalla_inicial(void );
void Pantalla_Menu(void );
void Selector_Menu(void );
//End of Auto generated function prototypes by Atmel Studio



const int XP=8,XM=A2,YP=A3,YM=9; //ID=0x9341
const int TS_LEFT=66,TS_RT=907,TS_TOP=929,TS_BOT=97;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Adafruit_GFX_Button aceptar_btn;

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


//Variables del programa
unsigned char Estado_Actual=0,Prtj_carga=0,Menu=1;
bool mostrar=false;
unsigned int pixel_x,pixel_y;

/////////////////////////////////////////////////////////////////////////////////////////
//Funciones de Maquinas de estados
typedef enum
{
    ESTADO_INICIAL,
    ESTADO_MENU,
    ESTADO_LEDS,
    ESTADO_BARRA,
    ESTADO_PANT_ESTATICA,
}MEFestado;

MEFestado state = Estado_Actual;
void Mef_init(void)
{
    Estado_Actual = ESTADO_INICIAL;
    
    return;
}
void Mef_Updated(void)
{
    switch(Estado_Actual)
    { 
        case ESTADO_INICIAL:
        {
            Pantalla_inicial();

            if(Prtj_carga==100) Estado_Actual = ESTADO_MENU,mostrar=true,tft.fillScreen(TFT_BLACK);
        break;
        }
        case ESTADO_MENU:
        {
            Pantalla_Menu();
            
        break;
        }
        case ESTADO_LEDS:
        {
          
        break;
        }
        case ESTADO_BARRA:
        {

        break;
        }
        case ESTADO_PANT_ESTATICA:
        {
            
          
        break;
        }
    }
  
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
//Funciones de de incializacion
void setup() 
{
    Serial.begin(9600);
    tft.reset();          // Enviamos un reset por hardware para comenzar
    tft.begin(0x9341);    // Controlador ili9341
    tft.setRotation(1);   // Seteamos a 180°
    tft.fillScreen(TFT_WHITE);
    Mef_init();           // Inicializa la maquina de estados finitas
    tft.drawRect(10,180,300,50,TFT_BLACK);
    tft.setTextSize(2);
    tft.setTextColor(TFT_YELLOW,TFT_BLACK);
    tft.setCursor(90,20);
    tft.print("Bienvenido");
    tft.setCursor(25,40);
    tft.print("Espere mientra carga");
}
void loop()
{  
    Mef_Updated();
}
/////////////////////////////////////////////////////////////////////////////////////////
//Funciones del display para mostrar datos:
void Pantalla_inicial(void)
{
    unsigned int Barra=0;
    
    Prtj_carga+=1;
    Barra = Prtj_carga * 3;
    if(Barra > 300) Barra = 300;

    tft.setTextSize(7);
    tft.setTextColor(TFT_BLUE,TFT_WHITE);
    tft.setCursor(90,100);
    tft.print(Prtj_carga),tft.print("%");
    tft.fillRect(10,180,Barra,50,TFT_BLUE);
    delay(30);
    
    return;
}
void Pantalla_Menu(void)
{
    if(mostrar==true)
    {
        //Menu
        tft.setTextSize(5);tft.setTextColor(TFT_RED,TFT_BLACK);
        tft.setCursor(100,20);tft.print("Menu");
        //Opciones:
        Selector_Menu();
        tft.setTextSize(2);tft.setTextColor(TFT_BLUE,TFT_WHITE);
        tft.setCursor(10,70);tft.print("LEDS");
        tft.setTextSize(2);tft.setTextColor(TFT_BLUE,TFT_BLACK);
        tft.setCursor(10,100);tft.print("MEDIDOR");
        mostrar = false;
    }

    return;
}
void Selector_Menu(void)
{
    if(Menu==1)
    {
        tft.fillRect(0,68,310,20,TFT_WHITE);
        tft.fillRect(0,98,310,20,TFT_BLACK);
    }
    if(Menu==2)
    {
        tft.fillRect(0,98,310,20,TFT_WHITE);
        tft.fillRect(0,68,310,20,TFT_BLACK);
    }
    
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
