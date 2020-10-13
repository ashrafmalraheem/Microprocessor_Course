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
#include "math.h"
#include "stdio.h"

/*
 * Section: Macros
 */
#define BIT5          0b00100000
#define BAUD_RATE     19200
#define NO_OF_BITS    _7BITS
#define PARITY        EVEN
#define STOP_BITS     _1BIT
#define ADDRESS       1

/*
 * Section: Function Decalartion
 */

void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
unsigned char EEPROM_read(unsigned int uiAddress);

/*
 * Section: Interrupt Service routing Defintion
 */
 

int main(void)
{
    /* Replace with your application code */
	
	/*** set section ***/
	USART_Init(BAUD_RATE, NO_OF_BITS, PARITY, 1);
	Log_String((char*)"EEPROM");
	int i = 4;
	int j = 0;
	char str[20];
	Log_Int((char*)"Address: 0 03",EEPROM_read(0));
	while(1){
		/*** Loop section ***/
		_delay_ms(1000);
		/*Print the reading */	
		//EEPROM_write(ADDRESS+j++,i++);
		//Log_String((char*)"Write Complete");
		sprintf(str,"Address: %d",ADDRESS+j);
		Log_Int(str,EEPROM_read(ADDRESS+j));
		if(j++ == 3874){
			break;
		}
	
		
		
	}
}


/*
 * Section: Function Defintion
 */
 
void EEPROM_write(unsigned int uiAddress, unsigned char ucData)
{
/* Wait for completion of previous write */
while(EECR & (1<<EEPE));
/* Set up address and Data Registers */
EEAR = uiAddress;
EEDR = ucData;
/* Write logical one to EEMPE */
EECR |= (1<<EEMPE);
/* Start eeprom write by setting EEPE */
EECR |= (1<<EEPE);
}

unsigned char EEPROM_read(unsigned int uiAddress)
{
/* Wait for completion of previous write */
while(EECR & (1<<EEPE));
/* Set up address register */
EEAR = uiAddress;
/* Start eeprom read by writing EERE */
EECR |= (1<<EERE);
/* Return data from Data Register */
return EEDR;
}
