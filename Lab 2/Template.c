/******************************************************************************
 * Copyright (C) 2020 by R&D SEDC
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. SEDC are not liable for any misuse of this material.
 *****************************************************************************/
/**
 * @file TemplateName.c
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
#include "Template.h"
#include <io.h>
#include <delay.h>


/*
 *  Section: Variables Declaration 
 */
uint8_t *pPointer;
uint8_t variable_one;

/* 
 *  Section: Functions Implementation
 */
uint8_t FunctionLikeThis(uint8_t* pSrcData, uint8_t bitIndex){
	PINB = BIT5;
	_delay_ms(200);
	return bitIndex;
}