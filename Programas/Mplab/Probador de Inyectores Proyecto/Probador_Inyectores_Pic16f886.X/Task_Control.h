#include <xc.h>
#include <stdio.h>
#include "LCD_control.h"

#define _XTAL_FREQ 20000000
#define TICKS_T3    10000 // Cada 1 segundo

unsigned char Pwm,Min,Seg,Temp,Modo=0;
unsigned int T_Tiempo=TICKS_T3;
unsigned int Rpm;
_Bool Out_E=0;
_Bool Fin=0;
_Bool Temporizador=0;
_Bool mod_min=0,mod_seg=0;

//ADC
/**
 * Se encarga de seleccionar la maquina de estado
 * @param Estado
 */
void Task1(unsigned char *Estado); 
/**
 * Maquina de estado de lectura analogica de potenciometro rpm
 */
void E_Task1_Rpm(void);             
/**
 * Maquina de estado de lectura analogica de ponteciometro pwm
 */
void E_Task1_Pwm(void);             
/**
 * Maquina de estado de lectura analogica de potenciometro min
 */
void E_Task1_Min(void);             
/**
 * Maquina de estado de lectura analogica de ponteciometro temp
 */
void E_Task1_Temp(void);            

//Tarea pwm
/**
 * Activa el pwm1
 */
void Task2(void);

/**
 * Actualiza el valor del tiempo
 */
void Task3(void);