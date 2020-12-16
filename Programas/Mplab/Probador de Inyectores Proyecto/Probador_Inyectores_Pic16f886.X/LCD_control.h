#include <xc.h>
#define _XTAL_FREQ 20000000

/*------------------------------------------------------------------------------
                            PROGRAM DEFINES
 -----------------------------------------------------------------------------*/
#ifndef LCD_16X2
    #define LCD_16X2 0x01
    
    //Configuraciones de pines
    #define RS_PIN      PORTCbits.RC1
    #define RS_TRIS     TRISCbits.TRISC1
    #define RW_PIN      PORTCbits.RC2
    #define RW_TRIS     TRISCbits.TRISC2
    #define E_PIN       PORTCbits.RC3
    #define E_TRIS      TRISCbits.TRISC3
    #define BITS_PIN    PORTC
    #define BITS_TRIS   TRISC
    
    //Funciones del lcd
    #define CLEAR 0x01                  //Limpiar el display
    #define CURSOR_OFF 0x0C             //Desactiva el cursor
    #define CURSOR_ON 0x0E              //Actva el cursor solo
    #define CURSOR_BLINK_ON 0x0F        //Activa el cursor y el destello
    #define HOME 0x02                   //Vuelve a la posicion home 0,0
    #define DISPLAY_RIGHT 0x1C          //Corrimiento de pantalla a la derecha
    #define DISPLAY_LEFT 0x18           //Corrimiento de pantalla a la izquierda
    #define CURSOR_RIGHT 0x14           //Movimiento del cursor a la derecha
    #define CURSOR_LEFT 0x10            //Movimiento del cursor a la izquierda
    #define PRIMERA_FILA 0x02
    #define SEGUNDA_FILA 0xC0
    #define TERCERA_FILA 0x94
    #define CUARTA_FILA 0xD4

    //Generacion de caracter
    #define CARACTER_POS0 0x00          //Caracter posicion 0
    #define CARACTER_POS1 0x01          //Caracter posicion 1
    #define CARACTER_POS2 0x02          //Caracter posicion 2  
    #define CARACTER_POS3 0x03          //Caracter posicion 3
    #define CARACTER_POS4 0x04          //Caracter posicion 4
    #define CARACTER_POS5 0x05          //Caracter posicion 5
    #define CARACTER_POS6 0x06          //Caracter posicion 6
    #define CARACTER_POS7 0x07          //Caracter posicion 7 

    //Generacion de numero grandes
    #define LCD_20X4 0x02    //Numero grandes para Lcd 20x4
    #define JUST_RIGHT 0x10  //Numeros con justificacion derecha de la pantalla
    #define JUST_LEFT 0x11   //Numeros con justificacion izquierda de la pantalla

/*------------------------------------------------------------------------------
                            FUNCTION PROTOTYPES
 -----------------------------------------------------------------------------*/
void LCD_init(void);
void LCD_command(unsigned char cmd);
void LCD_array(int x,int y,const char *date);
void LCD_xy(int x,int y);
void LCD_date(char date);
void LCD_E(void);
void LCD_shift(unsigned char dir,unsigned char cant);
void LCD_character(unsigned char adress,char caracter[]);
void LCD_numerogrande(int valor);

#endif