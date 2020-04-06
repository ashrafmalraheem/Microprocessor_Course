/******************************************************************************
 * Copyright (C) 2018 by R&D SEDC
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. SEDC are not liable for any misuse of this material.
 *****************************************************************************/
/**
 * @file LogMessage.h
 * @brief Log functions
 *
 * This interface logging messages used for debugging. Different types of logging
 * messages are available such as loging int, float or array data type. 
 *
 * @author 
 * @modification Ashraf Abubaker
 * @date April 24 2019
 *
 */
#ifndef __LOG_MESSAGE_H__
#define __LOG_MESSAGE_H__

/*
 *  Section: Included Files
 */
#include "stdint.h"
#include "buffer.h"
#include "uart.h"

/*
 *  Section: Macro Definition
 */
#define LOG_MAX_BUFFER    PC_TX_BUFFER_MAX_SIZE  
/* 
 *  Section: Functions Prototype
 */

/*
 * @brief Log float variables
 *
 * This function take a text and float variable store it in array and place it in the UART Tx buffer
 *
 * @param string text 
 * @param float variable
 */
void Log_Float(char* pLog_txt, float Log_value);

/*
 * @brief Log int variables
 *
 * This function take a text and integer variable store it in array and place it in the UART Tx buffer
 *
 * @param string text 
 * @param integer variable 
 */
void Log_Int(char* pLog_txt,  int32_t Log_value);

/*
 * @brief Log hex variables
 *
 * This function take a text, hexadecimal and its length variable store it in array and place 
 * it in the UART Tx buffer
 *
 * @param string text 
 * @param hex variable
 * @param Length of variable 
 */
void Log_Hex(char* pLog_txt, char* pHex_Log, uint16_t Hex_len); 

/*
 * @brief Log array
 *
 * This function take a text and array pointer and length store it in array and place it in 
 * the UART Tx buffer
 *
 * @param string text 
 * @param array pointer
 * @param length of the array
 */
void Log_Int_Arr(char* pLog_txt, char* pLog_array, uint16_t Arr_len);                                

#endif // __LOG_MESSAGE_H__
