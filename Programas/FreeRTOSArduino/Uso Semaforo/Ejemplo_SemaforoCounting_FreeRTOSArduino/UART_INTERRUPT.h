#ifndef UART_INTERRUPT_H
#define UART_INTERRUPT_H

#include <avr/io.h>
#include <avr/interrupt.h>

#define FOSC 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/(BAUD-1)

/* Definiciones de funciones */
#define Uart_Init   USART_Init
#define Uart_Write  USART_Transmit
#define Uart_print  USART_Array
#define Uart_println USART_Arrayln    
#define Uart_Read   USART_Receive

/* Variable para interrupcion rx */
volatile char RxBuffer;
/* Funciones */
void USART_Init(unsigned int baud_rate);
void USART_Transmit(unsigned char date);
void USART_Array(const char *buffer);
void USART_Arrayln(const char *buffer);
unsigned char USART_Receive(void);
extern void ISR_RX0(void);

void USART_Init(unsigned int baud_rate)
{
    cli();
    // Limpiamos los puertos //
    UCSR0A = 0;
    UCSR0B = 0;
    UCSR0C = 0;
    /* Setea el baudaje */
    UBRR0H = (unsigned char) (baud_rate>>8);
    UBRR0L = (unsigned char) (baud_rate);
    /* Habilita el receptor y el transimisor */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
    /* Set frame format: Modo asincrono,8data, 1stop bit */
    UCSR0C = (1<<UCSZ00)|(1<<UCSZ01);
    sei();  // Habilita interrupcion global
}
void USART_Transmit(unsigned char date)
{
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)) );
    /* Put data into buffer, sends the data */
    UDR0 = date;
}
unsigned char USART_Receive(void)
{
    /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) );
    /* Get and return received data from buffer */
    return UDR0;
}
void USART_Array(const char *buffer)
{
    while(*buffer)
    {
        USART_Transmit(*buffer);
        buffer++;
    }
}
void USART_Arrayln(const char *buffer)
{
    while(*buffer)
    {
        USART_Transmit(*buffer);
        buffer++;
    }
    USART_Transmit('\n');
    USART_Transmit(13);
}
ISR(USART0_RX_vect)
{
    RxBuffer = Uart_Read();
    Uart_print("Letra:"),Uart_Write(RxBuffer),Uart_println(" ");
    ISR_RX0();
}

#endif