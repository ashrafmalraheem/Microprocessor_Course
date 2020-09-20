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
#include "avr_uart.h"
#include "LogMessage.h"

#define BIT5  0b00100000


#define BAUD_RATE     19200
#define NO_OF_BITS    _7BITS
#define PARITY        EVEN
#define STOP_BITS     _1BIT

int main(void)
{
    /* Replace with your application code */
	uint8_t j = 0;
	float float_k = 33.4;
	USART_Init(BAUD_RATE, NO_OF_BITS, EVEN, 1);
	_delay_ms(1000);
	while(1){
		PINB = BIT5;
		_delay_ms(100);
		Log_Float((char*)"float is now working :) :0",float_k+j++);
		
	}
}
