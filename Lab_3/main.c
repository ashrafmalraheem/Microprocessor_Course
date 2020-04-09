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
#include "avr_uart.h"
#include "LogMessage.h"

#define BIT5  0b00100000


#define BAUD_RATE     2400
#define NO_OF_BITS    _8BITS

int main(void)
{
    /* Replace with your application code */
	//uint32_t i;//=MYUBRR;
	uint8_t j = 0;
	float float_k = 33.4;
	//unsigned char k = 0xA5;
	//i++;
	unsigned char Ping_message[11]={0x01, 0x05, 0x0D, 0x41, 0x42, 0x43, 0x44, 0x45, 0xD0, 0xEA,0x04};
	DDRB |= BIT5;
	USART_Init(BAUD_RATE, NO_OF_BITS, NONE, 1);
	_delay_ms(100);
	while(1){
		PINB = BIT5;
		_delay_ms(1000);
		//USART_Transmit(j++);
		Log_Float((char*)"float is now working :) :0",float_k);
		//float_k *= (j++);
		/*for(j=0;j<10;j++){
		USART_Transmit(Ping_message[j]);
		_delay_ms(1);
		}*/
	}
}
