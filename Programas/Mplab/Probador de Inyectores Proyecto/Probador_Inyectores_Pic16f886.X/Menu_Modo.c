#include "Configuracion_Bits.h"
#include "Menu_Modo.h"
#include "Display_Lcd.h"

#define MOVER       PORTBbits.RB3
#define SALIDA_LOW  PORTBbits.RB4=0
#define BUZZER      PORTAbits.RA5

extern unsigned char Modo,Min,Seg;
extern _Bool Mostrar,Output;

extern void Antirrebote(void);

void Select_Modo(void)
{
    CLRWDT();
    
    if(Mostrar) Pantalla_Menu(),Mostrar=0;
    
    if(MOVER || Modo==0)
    {
        Modo+=1;
        if(Modo>=5||Modo<1) Modo=1;
        Pantalla_Selector(),Antirrebote();
    }
    
    return;
}

void Detener(void)
{
    Antirrebote();
    Output = !Output;
    SALIDA_LOW;
    
    Pantalla_Detener();
    
    for(char i=0;i<3;i++)
    {
        BUZZER = 1;
        __delay_ms(100);
        BUZZER = 0;
        __delay_ms(100);
    }
    
    __delay_ms(1200);
    
    return;
}

void Fin_Proceso(void)
{
    if(!Min && !Seg)
    {
        Proceso_Finalizado();
        Output = !Output;
        for(char i=0;i<3;i++)
        {
            BUZZER = 1;
            __delay_ms(100);
            BUZZER = 0;
            __delay_ms(100);
        }
        __delay_ms(1200);
    }
    
    return;
}
