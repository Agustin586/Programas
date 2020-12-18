#include "Configuracion_Bits.h"
#include "Menu_Modo.h"
#include "Display_Lcd.h"

#define MOVER   PORTBbits.RB3

extern unsigned char Modo;
extern _Bool Mostrar;

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
