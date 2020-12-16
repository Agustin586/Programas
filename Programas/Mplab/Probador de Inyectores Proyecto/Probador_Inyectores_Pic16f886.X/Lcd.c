#include "Configuracion_Bits.h"
#include "Lcd.h"

void LCD_init(void)
{
    //Setea como salida los pines para el lcd
    D4_TRIS=0,D5_TRIS=0,D6_TRIS=0,D7_TRIS=0;
    RS_TRIS=0,E_TRIS=0;
    RW_TRIS=0,RW_PIN=0;
    
    //Tiempo de inicilizacion
    __delay_ms(30);
    
    for(char i=0;i<3;i++)
    {
        LCD_command(0x03);              //Recomendado para inicializar el controlador
        __delay_ms(7);
    }
    
    //Configuraciones del LCD 16x2
	LCD_command(0x33);                  //Inicializa el controlador
    __delay_us(100);                        
    LCD_command(0x32);                  //Modo de 4 bits
    __delay_ms(5);  
	LCD_command(0x28);                  //Modo 4 bits,2 lineas y fuente de 5x7
    __delay_us(100);
	LCD_command(0x0C);                  
    __delay_us(100);
	LCD_command(0x06);
    __delay_us(100);
    LCD_command(CLEAR);                 //Limpia la pantalla
    __delay_ms(10);

    return;
}

////////////////////////////////////////////////////////////////////////////////

void LCD_command(unsigned char cmd)
{
    //Limpia puerto
    D4_PIN=0,D5_PIN=0,D6_PIN=0,D7_PIN=0;
    
    //Envia MSB 
    D4_PIN = ((cmd >> 4) & 0x01);
    D5_PIN = ((cmd >> 5) & 0x01);
    D6_PIN = ((cmd >> 6) & 0x01);
    D7_PIN = ((cmd >> 7) & 0x01);

    //Configura en modo comando
    RS_PIN = 0;
    E_PIN  = 0;
    
    //Cargo los datos
    E_PIN = 1;
    __delay_us(15);
    E_PIN = 0;
    __delay_us(15);
    
    
    //Limpia puerto
    D4_PIN=0,D5_PIN=0,D6_PIN=0,D7_PIN=0;

    //Envia LSB 
    D4_PIN = (cmd & 0x01);
    D5_PIN = ((cmd >> 1) & 0x01);
    D6_PIN = ((cmd >> 2) & 0x01);
    D7_PIN = ((cmd >> 3) & 0x01);
    
    //Modo Comando
    RS_PIN = 0;
    E_PIN  = 0;
    
    //Cargo los datos
    E_PIN = 1;
    __delay_us(15);
    E_PIN = 0;
    __delay_us(15);
    
    
    __delay_ms(3);
    
    return;
}

////////////////////////////////////////////////////////////////////////////////

void LCD_date(char date)
{
    //Limpia puerto
    D4_PIN=0,D5_PIN=0,D6_PIN=0,D7_PIN=0;
    
    //Envia MSB 
    D4_PIN = ((date >> 4) & 0x01);
    D5_PIN = ((date >> 5) & 0x01);
    D6_PIN = ((date >> 6) & 0x01);
    D7_PIN = ((date >> 7) & 0x01);
    
    //Modo caracteres o datos
    RS_PIN = 1;
    E_PIN  = 0;
    
    //Cargo los datos
    E_PIN = 1;
    __delay_us(15);
    E_PIN = 0;
    __delay_us(15);
    
    
    //Limpia puerto
    D4_PIN=0,D5_PIN=0,D6_PIN=0,D7_PIN=0;
    
    //Envia LSB 
    D4_PIN = (date & 0x01);
    D5_PIN = ((date >> 1) & 0x01);
    D6_PIN = ((date >> 2) & 0x01);
    D7_PIN = ((date >> 3) & 0x01);
    
    //Modo caracteres
    RS_PIN = 1;
    E_PIN  = 0;

    //Cargo los datos
    E_PIN = 1;
    __delay_us(50);
    E_PIN = 0;
    __delay_us(50);
    
    
    __delay_ms(3);
    
    return;
}

////////////////////////////////////////////////////////////////////////////////

void LCD_array(int x,int y,char *date)
{
    //Ubica el lcd
    switch(x)
    {
        case 1: LCD_command(0x80 | (0x00 + (y - 1)));
        break;
        case 2: LCD_command(0x80 | (0x40 + (y - 1)));
        break;
        case 3: LCD_command(0x80 | (0x14 + (y - 1)));
        break;
        case 4: LCD_command(0x80 | (0x54 + (y - 1)));
        break;
    }
    
    //Envia la cadena
    while(*date)
    {
        LCD_date(*date);
        __delay_ms(1);
        date++;
    }
}

////////////////////////////////////////////////////////////////////////////////

void LCD_xy(int x,int y)
{
    switch(x)
    {
        case 1: LCD_command(0x80 | (0x00 + (y - 1)));
        break;
        case 2: LCD_command(0x80 | (0x40 + (y - 1)));
        break;
        case 3: LCD_command(0x80 | (0x14 + (y - 1)));
        break;
        case 4: LCD_command(0x80 | (0x54 + (y - 1)));
        break;
    }
}

////////////////////////////////////////////////////////////////////////////////

void LCD_shift(unsigned char dir,unsigned char cant)
{
    char i=1;
    //Realiza el corrimiento de pantalla
    while(i <= cant)
    {
        LCD_command(dir);
        __delay_ms(250);
        i++;
    }

    LCD_command(HOME);              //Vuelve a la posicion inicial
    i = 1;
}

////////////////////////////////////////////////////////////////////////////////

void LCD_character(unsigned char adress,char caracter[])
{
    LCD_command(0x40 + (adress * 8));
    for(char i=0;i<8;i++)
    {
        LCD_date(caracter[i]);
    }
}

/*Ejemplo de uso de la funcion de creacion de caracter:
 *char caracter1[8] = 
    {
        0b00000000,
        0b00001010,
        0b00001010,
        0b00001010,
        0b00001010,
        0b00010001,
        0b00001110,
        0b00000000,
    };
    LCD_command(CLEAR);
    LCD_caracter(CARACTER_POS0,caracter1);
    LCD_xy(0,0);
    LCD_date(CARACTER_POS0);
    __delay_ms(1000);
 */

    


