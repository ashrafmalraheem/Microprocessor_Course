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
int main(void)
{
    /* Replace with your application code */
	uint32_t i=0;
	i++;
	//DDRB |= BIT5;
	InitLCD(LS_BLINK);
	LCDClear();
	LCDWriteString("Hello World");
	while(0){
		//PINB = BIT5;
		//LCDGotoXY(1,1);
		//LCDWriteString("Hello World");
		LCDGotoXY(uint8_t x,uint8_t y);
		_delay_ms(10);
	}
}

