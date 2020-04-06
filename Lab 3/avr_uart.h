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
 * @file avr_uart.h
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
#ifndef __AVR_UART_H__
#define __AVR_UART_H__


/*
 *  Section: Included Files
 */
#include <io.h>
#include "stdint.h"
#include "stdbool.h"
/*
 *  Section: Macros Definitions
 */

/*
 *  Section: Data Types
 */
typedef enum {
	NONE,
	EVEN,
	ODD
}eParity;

/*
 *  Section: Variables Declaration 
 */

/* 
 *  Section: Functions Prototype
 */

/*
 * @brief:
 *       Initilize the UART peripheral with the approperiate settings: baud rate,
 * no. of bits, and parity.
 *
 *  @Param 
 *  baud_rate:      300, 600, 1200, 2400, 4800, 9600, etc... 
 *  number_of_bits: 7, 8 or 9 bits
 *	parity:         even odd or none 
 *	stop_bits:      1 or 2
 *  @Returns
 *
 *
 * @return none
 */

void USART_Init(uint16_t baud_rate, uint8_t number_of_bits, eParity parity, uint8_t stop_bits);

/*
 * @brief check the status of hardware UART TX buffer
 *
 * This function will return the status of the UART TX hardware buffer if it is full or
 * empty.
 *
 * @return status of the buffer: 1 full, 0 empty.
 */
bool tx_buffer_is_empty(); 
 
/*
 * @brief check the status of hardware UART RX buffer
 *
 * This function will return the status of the UART RX hardware buffer if it is full or
 * empty.
 *
 * @return status of the buffer: 1 full, 0 empty.
 */
bool rx_buffer_is_full();

/*
 * @brief send 1 byte data to the UART port
 *
 * This function will send 1 byte to the port in UART by placing the byte in UART
 * hardware buffer.
 *
 * @param  byte to be sent
 */
void USART_Transmit(uint8_t data);
/*
 * @brief receive a 1 byte data from the UART port
 *
 * This function will return a 1 byte from the port in UART by moving the byte in UART
 * hardware rx buffer.
 *
 * @return received byte
 */
uint8_t USART_Receive(void);

#endif  // __AVR_UART_H__