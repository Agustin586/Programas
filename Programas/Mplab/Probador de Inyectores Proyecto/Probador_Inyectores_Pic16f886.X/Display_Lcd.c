#include "Configuracion_Bits.h"
#include "Display_Lcd.h"

extern unsigned char Modo;

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
    
    Lcd_cadena(1,1,">");
    
    return;
}

void Pant_Selector(void)
{
    if(Modo == 1)       Lcd_cadena(4,1," "),Lcd_cadena(1,1,">");
    else if(Modo == 2)  Lcd_cadena(1,1," "),Lcd_cadena(2,1,">");
    else if(Modo == 3)  Lcd_cadena(2,1," "),Lcd_cadena(3,1,">");
    else if(Modo == 4)  Lcd_cadena(3,1," "),Lcd_cadena(4,1,">");
//    else if(Modo == 5)
//    {
//        Lcd_comando(CLEAR);
//        Lcd_cadena(1,1,">");
//    }
    
    return;
}

void Pant_Menu(void)
{
    Lcd_cadena(1,3,"PULVERIZACION");          // Prueba de variar rpm
    Lcd_cadena(2,3,"FUGA");                   // Prueba de goteo
    Lcd_cadena(3,3,"FLUJO");                  // Pulso totalmente abierto
    Lcd_cadena(4,3,"LIMP. ULTRASONIDO");      // Limpieza ultrasonido
    
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