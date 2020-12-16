#include "Task_Control.h"
#include "ADC.h"
#include "Pwm_Soft.h"
#define BUZZER      PORTAbits.RA5
#define DETENER     PORTBbits.RB2

////////////////////////////////////////////////////////////////////////////////

void Task1(unsigned char *Estado)
{
    //Lee el adc del rpm
    if(*Estado == 1 && (Modo == 1 || Modo == 3 || Modo == 2))  E_Task1_Rpm();
    //Lee el adc del pwm
    else if(*Estado == 2 && (Modo == 1 || Modo == 3))  E_Task1_Pwm();
    //Lee el adc de los minutos
    else if(*Estado == 3 && Out_E == 0)                E_Task1_Min();
    //Lee el adc de la temperatura
    else if(*Estado == 4)                              E_Task1_Temp();
    
    *Estado+=1;                        // Cambia de estado
    if(*Estado == 5)   *Estado = 1;   // Reinicia los estados
        
    return;
}

////////////////////////////////////////////////////////////////////////////////

void E_Task1_Rpm(void)
{
    char buffer[10];
    unsigned int aux,valor,cent=0,dec_m=0,uni_m=0;
    
    aux = Rpm;
    valor = (int)((Adc(0)*5.0/1023.0)*10000.0/5.0);
    
    dec_m = (int)(valor/10000)*10000;
    uni_m = (int)((valor-dec_m)/1000)*1000;
    cent = (int)((valor-(uni_m+dec_m))/100)*100;

    valor = cent+uni_m+dec_m;
    Rpm = valor;
    
    if(Rpm == 0)            Rpm = 60;
    else if(Rpm > 10000)    Rpm = 10000;
        
    if(Rpm != aux)
    {
        sprintf(buffer,"%05u",Rpm);
        LCD_array(1,5,buffer);
    }
    
    return;
}

////////////////////////////////////////////////////////////////////////////////

void E_Task1_Pwm(void)
{
    char buffer[10],aux;
    aux = Pwm;
    
    if(Modo == 1)
    {
        Pwm = (int)((Adc(1)*5.0/1023.0)*100.0/5.0);
        if(Pwm > 95)        Pwm = 95;
        else if(Pwm < 5)    Pwm = 5;
    }
    else if(Modo == 3)  Pwm = 99;
    
    if(Pwm != aux)
    {
        sprintf(buffer,"%02d",Pwm);
        LCD_array(2,5,buffer);
    }
    
    return;
}

////////////////////////////////////////////////////////////////////////////////

void E_Task1_Min(void)
{
    char buffer[10],aux_min,aux_seg;
    
    //Modifica los minutos o segundos
    if(mod_min == 1)        aux_min = Min,Min = (int)((Adc(2)*5.0/1023.0)*59.0/5.0);
    else if(mod_seg == 1)   aux_seg = Seg,Seg = (int)((Adc(2)*5.0/1023.0)*59.0/5.0);
    
    if(Seg == 0)    Seg = 1;
    
    if((Min != aux_min && mod_min == 1) || (Seg != aux_seg && mod_seg == 1))
    {
        sprintf(buffer,"%02d",Min);
        LCD_array(3,8,buffer);
        sprintf(buffer,"%02d",Seg);
        LCD_array(3,11,buffer);
    }
//    else if(Seg != aux_seg && mod_seg == 1)
//    {
//        sprintf(buffer,"%02d",Min);
//        LCD_array(3,8,buffer);
//        sprintf(buffer,"%02d",Seg);
//        LCD_array(3,11,buffer);
//    }
    
    return;
}

////////////////////////////////////////////////////////////////////////////////

void E_Task1_Temp(void)
{
    char buffer[10];
    unsigned char aux;
    aux = Temp;
    Temp = (int)((Adc(3)*5.0/1023.0)*100.0);
    if(Temp != aux)
    {
        sprintf(buffer,"%02d",Temp);
        LCD_array(4,13,buffer);
    }
    
    return;
}

////////////////////////////////////////////////////////////////////////////////

void Task3(void)
{
    char buffer[10];
    
    //Escribe solo si paso 1 segundo
    if(Temporizador == 1)
    {
        sprintf(buffer,"%02d",Min);
        LCD_array(3,8,buffer);
        sprintf(buffer,"%02d",Seg);
        LCD_array(3,11,buffer);
        
        Temporizador = 0;
    }
    if(Min == 0 && Seg == 0)
    {
        Fin = 1;

        for(char i=0;i<3;i++)
        {
            BUZZER = 1;
            __delay_ms(100);
            BUZZER = 0;
            __delay_ms(100);
        }
    }
    
    return;
}

////////////////////////////////////////////////////////////////////////////////

void Task2(void)
{
    PwmS1_init((int)(Rpm/60.0));
    PwmS1_set(Pwm);
    
    return;
}

////////////////////////////////////////////////////////////////////////////////
//void Task2(void)
//{
//    float per=0;
//    unsigned int v_tmr1=0;
//    unsigned char i=0,aux;
//
//    //Genera el periodo de la señal
//    per = 1.0 / (Rpm / 60.0);
//    //Valor del tmr1
//    v_tmr1 = 65535 - (int)((per / 100.0) / 0.0000016);
//    
//    /*
//     valor_timer1 = 65535 - ((periodo / 100) / 1.6us)
//     
//     65534 = 65535 - (el 1% de la señal)
//     65534 + (1% señal) = 65535
//     ((periodo/100)/1.6us) = 1
//     periodo / 100 = 1 * 1.6us
//     periodo = 1.6us * 100
//     periodo = 160 us --> frecuencia = 6250 Hz o Rpm = 375000
//     
//     
//     1 = 65535 -(1% señal)
//     ((periodo/100)/1.6us) = 65535 - 1
//     periodo = (65534 * 1.6us) * 100
//     periodo = 10.485 --> Freq = 0.095 Hz o Rpm = 5.72  
//     */
//
//    WDTCONbits.SWDTEN = 0;          // Deshabilita el watchdog timer
//    
//    PWM_TRIS = 0;                                   // Pone como salida 
//    while(DETENER == 0 && Fin == 0)
//    {
//        for(char i=0;i<=Pwm;i++)
//        {
//            PWM_PIN = 1;
//            while(1)
//            {
//                if(PIR1bits.TMR1IF == 1)
//                {
//                    TMR1 = v_tmr1;
//                    PIR1bits.TMR1IF = 0;
//                    break;
//                }
//            }
//        }
//        for(char i=0;i<=(100-Pwm);i++)
//        {
//            PWM_PIN = 0;
//            while(1)
//            {
//                if(PIR1bits.TMR1IF == 1)
//                {
//                    TMR1 = v_tmr1;
//                    PIR1bits.TMR1IF = 0;
//                    break;
//                }
//            }
//        }
//        E_Task1_1seg();
//    }
//    PWM_TRIS = 1;
//    
//    WDTCONbits.SWDTEN = 1;          // Habilita el watchdog timer
//    
//    return;
//}






