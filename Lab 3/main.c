/******************************************************************************
 * Copyright (C) 2020 by R&D SEDC
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. SEDC are not liable for any misuse of this material.
 *****************************************************************************/
/**
 * @file main.c
 * @brief 
 *
 *  
 *
 * @author: R&D SEDC
 * @Modifyed: 
 * @date February 13, 2020, 2:20 PM
 *
 */


/*
 * Section: Included Files
 */
#include <io.h>
#include <stdint.h>
#include <delay.h>
#include "lcd.h"

#define BIT5  0b00100000
#define BAUD 2400
#define MYUBRR (uint32_t)(F_CPU/(16*(float)BAUD)-1)
void USART_Transmit(unsigned int data);
void USART_Init(unsigned int ubrr);
unsigned char USART_Receive(void);
int main(void)
{
    /* Replace with your application code */
	uint32_t i=MYUBRR;
	unsigned int j = 0;
	unsigned char k = 0xA5;
	i++;
	unsigned char Ping_message[10]={0xA5, 0x05, 0x0D, 0x01, 0x02, 0x03, 0x04, 0x05, 0xD0, 0xEA};
	DDRB |= BIT5;
	//DDRD |= 1<<PIND
	//InitLCD(LS_ULINE);
	//LCDClear();
	USART_Init(MYUBRR);
	//LCDWriteString("Hello World");
	//LCDGotoXY(7,0);
	//LCDWriteString("World");
	_delay_ms(100);
	while(1){
		PINB = BIT5;
		//LCDGotoXY(1,2);
		//LCDWriteInt(i,4);
		//LCDGotoXY(10,2);
		//LCDWriteInt(j,4);
		//_delay_ms(10);
		USART_Transmit(USART_Receive());
		//j = USART_Receive();
		//_delay_ms(1000);
		/*for(j=0;j<10;j++){
		USART_Transmit(Ping_message[j]);
		_delay_ms(1);
		}*/
	}
}
void USART_Init(unsigned int ubrr)
{
/*Set baud rate */
UBRR0H = (unsigned char)(ubrr>>8);
UBRR0L = (unsigned char)ubrr;
/*Enable receiver and transmitter */
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
/* Set frame format: 7data, 1stop bit */
UCSR0C |= ((1<<UCSZ01) | (1<<UCSZ00)); // for 8 bit set UCSZ00 
//UCSR0B |= (1<<UCSZ02);
}
void USART_Transmit(unsigned int data)
{
/* Wait for empty transmit buffer */
while (!(UCSR0A & (1<<UDRE0)));
/* Copy 9th bit to TXB8 */
/*UCSR0B &= ~(1<<TXB80);
if (data & 0x0100)
UCSR0B |= (1<<TXB80);*/
/* Put data into buffer, sends the data */
UDR0 = data;
}
unsigned char USART_Receive(void)
{
/* Wait for data to be received */
while (!(UCSR0A & (1<<RXC0)));
/* Get and return received data from buffer */
return UDR0;
}