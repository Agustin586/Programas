#include "Pwm_Soft.h"

////////////////////////////////////////////////////////////////////////////////

void Pwm_init(void)
{
    ANSELHbits.ANS11 = 0;               // RB0 como salida
    
    //Configuraciones del timer1
    T1CONbits.TMR1GE = 0;
    T1CONbits.T1SYNC = 1;
    T1CONbits.TMR1CS = 0;               // Fosc/4 internal clock
    T1CONbits.T1CKPS = 0b01;            // Prescaler of 1:2 --> 400ns con 20Mhz
    T1CONbits.TMR1ON = 1;               // Timer1 habilitado
    
    TMR1 = 65285;     // 100us
    //TMR1 = 63035;   // 1ms
    
    //Configura la interrupcion por timer1
    PEIE = 1;
    GIE  = 1;
    TMR1IE = 0;
    TMR1IF = 1;
    
    return;
}

////////////////////////////////////////////////////////////////////////////////

void Pwm1_init(unsigned int frecuencia)
{
    //Pone como salida
    PWMS1_TRIS = 0;
    PWMS1_LOW;

    /*
     El error del pic mediante la interrupcion es de 150us
     */
    
    //Obtiene la frecuencia y el periodo de la onda
    freqPwmS1 = frecuencia;
    Per_PwmS1 = (1.0/frecuencia)-0.005;
    PER_T_S1  = Per_PwmS1 / 0.0001;    //100us
    
    //Carga el valor de parametros
    Pw_PwmS1 = 0;
    PwmS1 = 0;

    return;
}

////////////////////////////////////////////////////////////////////////////////

void Pwm1(float duty)
{
    //Activa el Pwm
    Act_PwmS1 = 1;

    Pw_PwmS1 = (duty * Per_PwmS1) / 100.0;
    P_W_T_S1 = Pw_PwmS1 / 0.0001;      //100us
        
    if(PwmS1 == 0)  PWMS1_HIGH;
    
    //Habilita el timer1
    TMR1ON  = 1;
    
    return;
}

////////////////////////////////////////////////////////////////////////////////

void Pwm1_stop(void)
{
    //Desactiva el pwm
    Act_PwmS1 = 0;
    
    Pw_PwmS1 = 0;
    PwmS1 = 0;
    
    PWMS1_LOW;
    
    return;
}

////////////////////////////////////////////////////////////////////////////////

void Pwm_Signal(void)
{
    if(PwmS1==P_W_T_S1)
    {
        PWMS1_LOW;                              //Baja el pin
    }
    if(PwmS1==PER_T_S1)
    {
        PwmS1 = 0;
        PWMS1_HIGH;                             //Sube el pin
    }
    
    return;
}

////////////////////////////////////////////////////////////////////////////////