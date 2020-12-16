#include "Configuracion_Bits.h"
#include "Display_Lcd.h"

void Pant_Inicio(void)
{
    //Caracter especial
    char caracter1[8] = 
    {
        0b00000110,
        0b00001001,
        0b00001001,
        0b00000110,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000
    };
    Lcd_caracter(CARACTER_POS1,caracter1);
    
    //Caracter especial
    char caracter[8] = {0,0,0,0,0,0,0,0};
    LCD_character(CARACTER_POS0,caracter);
    
    //Presentation
    Lcd_comando(CLEAR);
    Lcd_cadena(1,1,"====================");
    Lcd_cadena(2,1,"PROBADOR AUTOMOTRIZ ");
    Lcd_cadena(3,1,"   DE INYECTORES    ");
    Lcd_cadena(4,1,"====================");
    __delay_ms(2000);
    
    //Principal Menu
    Lcd_comando(CLEAR);
    
    return;
}

void Pant_Menu(void)
{
    
    
    return;
}

void Pant_Pulverizacion(void)
{
    
    return;
}

void Pant_Fuga(void)
{
    
    return;
}

void Pant_Flujo(void)
{
    
    return;
}