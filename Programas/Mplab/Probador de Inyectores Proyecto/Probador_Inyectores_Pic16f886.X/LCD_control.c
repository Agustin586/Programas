#include "LCD_control.h"

//********************************************************************************
//Esta funcion inicializa el lcd con sus configuraciones; Debe utilizarse primero*
//********************************************************************************
void LCD_init(void)
{
    //Tiempo de inicilizacion
    __delay_ms(25);
    
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

//********************************************************************************
//Esta funcion permite ingresar un comando al lcd; LCD_command(CLEAR);************
//********************************************************************************
void LCD_command(unsigned char cmd)
{
    //Salidas en 0
    BITS_TRIS &= 0x00;              //Pone todo el puerto como salida,para poder escribir en el lcd              

    //Escribe los comandos
    BITS_PIN &= 0x00;               //Limpiar el puerto
    BITS_PIN |= (cmd & 0xF0);       //Envia el MSB del comando
    LCD_E();                        //Habilita el lcd para poder guardar los datos
    __delay_us(50);
    BITS_PIN &= 0x00;               //Limpia el puerto
    BITS_PIN |= (cmd<<4 & 0xF0);    //Envia el LSB del comando
    LCD_E();                        //Habilita el lcd para poder guardar los datos
    __delay_us(50);
    
    BITS_TRIS &= 0xF0;              //Vuelve a poner como entrada
    
    __delay_ms(5);
    return;
}

//********************************************************************************
//Esta funcion permite enviar los datos al lcd, para poder visalizar la letra*****
//********************************************************************************
void LCD_date(char date)
{
    //Setea las configuraciones para poder escribir
    BITS_TRIS &= 0x00;              //Modo de salida

    //Envia el dato
    BITS_PIN &= 0x00;               //Limpia el puerto
    BITS_PIN |= (date & 0xF0);      //Envia MSB
    RS_PIN = 1;                     //Modo de escritura
    LCD_E();                        //Habilita los datos
    __delay_us(50);
    BITS_PIN &= 0x00;               //Limpiar el puerto
    BITS_PIN |= (date<<4 & 0xF0);   //Enviar LSB
    RS_PIN = 1;                     //Modo de escritura
    LCD_E();                        //Habilita los datos
    __delay_us(50);
    
    BITS_TRIS &= 0xF0;              //Modo de entrada

    __delay_ms(5);
    return;
}

//********************************************************************************
//Esta funcion permite enviar el dato al lcd**************************************
//********************************************************************************
void LCD_E(void)
{
    E_PIN = 1;
    __delay_us(10);
    E_PIN = 0;
    __delay_us(10);
}

//********************************************************************************
//Esta funcion permite enviar una candena de caracteres***************************
//********************************************************************************
void LCD_array(int x,int y,const char *date)
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

//********************************************************************************
//Esta funcion permite ubicar en un lugar el lcd**********************************
//********************************************************************************
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

//*********************************************************************************
//Esta funcion realiza un corrimiento de pantalla; El 10 representa la cantidad de*
//veces que se va a correr la pantalla*********************************************
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

//********************************************************************************
//Esta funcion genera un caracter que no se encuentra en la lista del lcd*********
//********************************************************************************
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

    


