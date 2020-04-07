/******************************************************************************
 * Copyright (C) 2018 by Ashraf Abdalraheem
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Ashraf Abdalraheem are not liable for any
 * misuse of this material.
 *****************************************************************************/
/**
 * @file avr_uart.c
 * @brief avr_uart interface
 *
 * This interface for uart transmit and receive function specifically for avr atemga328p. 
 * it has the send,read and get status of uart ports buffers. 
 * it could also used to implement the interrupt service for uart.
 *
 * @author Ashraf Abdalraheem
 * @date April 23 2019
 *
 */


/*
 *  Section: Included Files
 */
#include "avr_uart.h"




/*
 *  Section: Variables Declaration 
 */


void USART_Init(uint16_t baud_rate, uint8_t number_of_bits, eParity parity, uint8_t stop_bits){
	uint16_t ubrr  = (uint16_t)(F_CPU/(16*(float)baud_rate)-1);
	/*Set baud rate */
	UBRR0H = (uint8_t)(ubrr>>8);
	UBRR0L = (uint8_t)ubrr;
	/*Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 7data, 1stop bit */
	if (number_of_bits == 7){
		UCSR0C |= (1<<UCSZ01);  // 7 bit
	}
	else if(number_of_bits == 8){
		UCSR0C |= ((1<<UCSZ01) | (1<<UCSZ00)); // for 8 bit set UCSZ00 
	}else if (number_of_bits == 9){
		UCSR0C |= ((1<<UCSZ01) | (1<<UCSZ00)); // 8 bit
		UCSR0B |= (1<<UCSZ02); // 9th bit
	}
	/* Set Parity to Even Parity*/
	if (parity == EVEN){
		UCSR0C |= (1<<UPM01);   // even parity
	}else if (parity == ODD){
		UCSR0C |= ((1<<UPM01) | (1<<UPM00));   // odd parity
	}	
	/* Set no. of stop bits*/
	if(stop_bits == 2){
		UCSR0C |= (1<<USBS0);
	}
}


bool tx_buffer_is_empty(){
	return (UCSR0A & (1<<UDRE0));
}
 

bool rx_buffer_is_full(){
	return (UCSR0A & (1<<RXC0));
}


void USART_Transmit(uint8_t data){
	/* Copy 9th bit to TXB8 */
	/*UCSR0B &= ~(1<<TXB80);
	if (data & 0x0100)
	UCSR0B |= (1<<TXB80);*/
	/* Put data into buffer, sends the data */
	UDR0 = data;
		
}

uint8_t USART_Receive(void){
	/* Get and return received data from buffer */
	return UDR0;
}
