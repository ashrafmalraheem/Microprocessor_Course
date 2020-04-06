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
 * @file uart.h
 * @brief uart interface
 *
 * This interface uart transmit and receive function. It will have different uart 
 * send function such as send to pc and send to UIU (user interface unit). It aslo check
 * status of uart hardware buffer to ensure if empty or not.
 *
 * @author Ashraf Abdalraheem
 * @date April 23 2019
 *
 */
#ifndef __UART_H__
#define __UART_H__


/*
 *  Section: Included Files
 */
#include "stdint.h"
#include "buffer.h"
#include "MessageFormatDefinition.h"

/*
 *  Section: Macros Definitions
 */
#define PC_TX_BUFFER_MAX_SIZE  128    // buffer max size
#define PC_RX_BUFFER_MAX_SIZE  128
#define UIU_TX_BUFFER_MAX_SIZE 128
#define UIU_RX_BUFFER_MAX_SIZE 128
#define TX_MESSAGE_MAX_SIZE    128    // Message max size
#define RX_MESSAGE_MAX_SIZE    128
#define NUMBER_OF_PORTS         1      // How many ports do you have

/*
 *  Section: Data Types
 */

typedef enum{
    PORT_1,
	PORT_2
}ePortInUse_t;

typedef enum{
	START_BYTE_INDEX,
	DATA_LENGTH_INDEX,
	DATA_TYPE_INDEX
}eData_index_t;


typedef enum {
	UART_TX_FULL,
	UART_TX_NOT_FULL,
	UART_TX_EMPTY,
	UART_TX_NOT_EMPTY,
	UART_TX_ERROR,
	UART_TX_NO_ERROR,
	UART_TX_ENOUGH_SPACE,
	UART_TX_NO_ENOUGH_SPACE,
	UART_TX_NULL
}eUART_TX_status_t;

typedef enum {
	UART_RX_FULL,
	UART_RX_NOT_FULL,
	UART_RX_EMPTY,
	UART_RX_NOT_EMPTY,
	UART_RX_ERROR,
	UART_RX_NO_ERROR,
	UART_RX_ENOUGH_SPACE,
	UART_RX_NO_ENOUGH_SPACE,
	UART_RX_NULL
}eUART_RX_status_t;
/*
 *  Section: Variables Declaration 
 */
extern ePortInUse_t port_in_use;
extern buffer_t     tx_sw_buffer[NUMBER_OF_PORTS],rx_sw_buffer[NUMBER_OF_PORTS];

/* 
 *  Section: Functions Prototype
 */

/*
 *  @brief:  
 *      FunctionLikeThis(): function to 
 * 
 *  @Param
 *      V1: 
 *      V2:  
 *  @Returns
 *      None
 */

/*
 * @brief:
 *       check the status of PC hardware UART TX buffer
 *
 *  @Param
 * 
 *  @Returns
 * This function will return the status of the PC UART TX hardware buffer if it is full or
 * empty.
 *
 * @return status of the buffer
 */
eUART_TX_status_t tx_hw_buffer_status();

/*
 * @brief check the status of hardware UART RX buffer
 *
 * This function will return the status of the UART RX hardware buffer if it is full or
 * empty.
 *
 * @return status of the buffer
 */
eUART_RX_status_t rx_hw_buffer_status();

/*
 * @brief send 1 byte data to the UART port
 *
 * This function will send 1 byte to the port in UART by placing the byte in UART
 * hardware buffer.
 *
 * @param  byte to be sent
 */
void send(uint8_t data);
/*
 * @brief receive a 1 byte data from the UART port
 *
 * This function will return a 1 byte from the port in UART by moving the byte in UART
 * hardware rx buffer.
 *
 * @return received byte
 */
uint8_t receive();

/*
 * @brief handle received messages
 *
 * This function will take 1 byte data and handle it. It tests if this byte is from a valid message.
 * It put this byte in a temporary buffer until the whole message is complete and it push it to the 
 * receive buffer. The length of received data is returned by reference. The counter of no. of received 
 * message is incremented. 
 *
 * @param  data 
 * @param  receive buffer pointer
 * @param  received data length pointer
 * @param  counter of completed messages pointer
 */
void receive_data_handle(uint8_t data, uint8_t *data_length, uint8_t *complete_message_received);

/*
 * @brief Process data to be sent through UART
 *
 * This function will send an array of data and process it to be in the correct format for 
 * sending through UART port. It calculate the CRC and add the start byte and the data 
 * length for the message.
 *
 * @param  tranmit buffer pointer
 * @param  data buffer pointer
 * @param  transmit data length
 * @param  transmit data typedef
 * @param  transmit data test id
 * @param  port in use to send to it
 */
void send_data_process(uint8_t *data, uint8_t transmit_data_length 
                       , uint8_t data_type , uint8_t test_ID);
#endif  // __UART_H__