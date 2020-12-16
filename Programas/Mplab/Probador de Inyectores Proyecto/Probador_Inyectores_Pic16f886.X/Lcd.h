#ifndef _XTAL_FREQ
#error  Debe definir la frecuencia del oscilador
#endif

/*------------------------------------------------------------------------------
                            PROGRAM DEFINES
 -----------------------------------------------------------------------------*/
#ifndef LCD_lib
    #define LCD_lib
    
    //Configuraciones de pines
    //#define BACKLIGHT_PIN   PORTBbits.RB0
    //#define BACKLIGHT_TRIS  TRISBbits.TRISB0
    #define RS_PIN      PORTCbits.RC1
    #define RS_TRIS     TRISCbits.TRISC1
    #define RW_PIN      PORTCbits.RC2
    #define RW_TRIS     TRISCbits.TRISC2
    #define E_PIN       PORTCbits.RC3
    #define E_TRIS      TRISCbits.TRISC3
    #define D4_PIN      PORTCbits.RC4      
    #define D4_TRIS     TRISCbits.TRISC4
    #define D5_PIN      PORTCbits.RC5
    #define D5_TRIS     TRISCbits.TRISC5
    #define D6_PIN      PORTCbits.RC6
    #define D6_TRIS     TRISCbits.TRISC6
    #define D7_PIN      PORTCbits.RC7
    #define D7_TRIS     TRISCbits.TRISC7
    //#define BITS_PIN    PORTB
    //#define BITS_TRIS   TRISB
    
    //Funciones del lcd
    #define CLEAR           0x01        //Limpiar el display
    #define CURSOR_OFF      0x0C        //Desactiva el cursor
    #define CURSOR_ON       0x0E        //Actva el cursor solo
    #define CURSOR_BLINK_ON 0x0F        //Activa el cursor y el destello
    #define HOME            0x02        //Vuelve a la posicion home 0,0
    #define DISPLAY_RIGHT   0x1C        //Corrimiento de pantalla a la derecha
    #define DISPLAY_LEFT    0x18        //Corrimiento de pantalla a la izquierda
    #define CURSOR_RIGHT    0x14        //Movimiento del cursor a la derecha
    #define CURSOR_LEFT     0x10        //Movimiento del cursor a la izquierda
    #define PRIMERA_FILA    0x02        //Ubica en la primera fila
    #define SEGUNDA_FILA    0xC0        //Ubica en la segunda fila
    #define TERCERA_FILA    0x94        //Ubica en la tercera fila
    #define CUARTA_FILA     0xD4        //Ubica en la cuarta fila

    //Generacion de caracter
    #define CARACTER_POS0 0x00          //Caracter posicion 0
    #define CARACTER_POS1 0x01          //Caracter posicion 1
    #define CARACTER_POS2 0x02          //Caracter posicion 2  
    #define CARACTER_POS3 0x03          //Caracter posicion 3
    #define CARACTER_POS4 0x04          //Caracter posicion 4
    #define CARACTER_POS5 0x05          //Caracter posicion 5
    #define CARACTER_POS6 0x06          //Caracter posicion 6
    #define CARACTER_POS7 0x07          //Caracter posicion 7 

    //Definiciones de funciones
    #define Lcd_Init        LCD_init
    #define Lcd_comando     LCD_command
    #define Lcd_cadena      LCD_array
    #define Lcd_posicion    LCD_xy
    #define Lcd_dato        LCD_date
    #define Lcd_corrimiento LCD_shift
    #define Lcd_caracter    LCD_character

    //Generacion de numero grandes
    #define JUST_RIGHT 0x10  //Numeros con justificacion derecha de la pantalla
    #define JUST_LEFT 0x11   //Numeros con justificacion izquierda de la pantalla

/*------------------------------------------------------------------------------
                            FUNCTION PROTOTYPES
 -----------------------------------------------------------------------------*/
void LCD_init(void);                                        // Permite inicializa el lcd
void LCD_command(unsigned char cmd);                        // Envia un comando al lcd
void LCD_array(int x,int y,char *date);                     // Envia una cadena de caracteres al lcd
void LCD_xy(int x,int y);                                   // Envia la posicion al lcd
void LCD_date(char date);                                   // Envia un caracter al lcd
void LCD_shift(unsigned char dir,unsigned char cant);       // Realiza un corrimiento
void LCD_character(unsigned char adress,char caracter[]);   // Genera un caracter especial

#endif
