#include <xc.h>

#define _XTAL_FREQ 20000000

#ifndef PWM_SOFT_TMR1_H
#define	PWM_SOFT_TMR1_H


//Definiciones de las funciones a utilizar
#define PwmS1_init  Pwm1_init
#define PwmS1_set   Pwm1
#define PwmS1_stop  Pwm1_stop

//Definiciones de salidas

#define PWMS1_TRIS  TRISB4
#define PWMS1_HIGH  RB4=1
#define PWMS1_LOW   RB4=0

//Funciones
void Pwm_init(void);
void Pwm1_init(unsigned int frecuencia);
void Pwm1(float duty);
void Pwm1_stop(void);

void Pwm_Signal(void);

//Variables globales

//Frecuencia globales:
unsigned int freqPwmS1=0;
//Contador de pwm:
unsigned int PwmS1=0;
//Parametros:
float Per_PwmS1=0,Pw_PwmS1=0;
unsigned int P_W_T_S1=0,PER_T_S1=0;
//Activaciones de pwm:
_Bool Act_PwmS1=0;

#endif
