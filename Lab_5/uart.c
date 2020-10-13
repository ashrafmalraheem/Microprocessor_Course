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
 * @file uart.c
 * @brief uart implementation
 *
 * This implementation of uart transmit and receive function. It will have 
 * different uart send function such as send to pc and send to UIU (user 
 * interface unit). It aslo check status of uart hardware buffer to ensure 
 * if empty or not.
 *
 * @author Ashraf Abdalraheem
 * @date April 23 2019
 *
 */

/*
 * Section: Included Files
 */
#include "uart.h"
#include "CRC16_modbus.h"
#include "string.h"
#include "avr_uart.h"
#include "delay.h"
/*
 *  Section: Variables Declaration 
 */
uint8_t receive_packet_size_overflow_flag; // what is this for??

/* 
 *  Section: Functions Implementation
 */
eUART_TX_status_t tx_hw_buffer_status()
{
	/////////////////////////////////////           
    /* platform specific code required */
    /////////////////////////////////////
		if(tx_buffer_is_empty()){
			return UART_TX_EMPTY;
		}
			return UART_TX_FULL;
}

eUART_RX_status_t rx_hw_buffer_status()
{
	/////////////////////////////////////           
    /* platform specific code required */
    /////////////////////////////////////
		if(rx_buffer_is_full()){
			return UART_RX_NOT_EMPTY;
		}
			return UART_RX_EMPTY;
}

void send(uint8_t data)
{
	/////////////////////////////////////           
    /* platform specific code required */
    /////////////////////////////////////
	USART_Transmit(data);
}

uint8_t receive()
{
	/////////////////////////////////////           
    /* platform specific code required */
    /////////////////////////////////////
	return USART_Receive();
}

void receive_data_handle(uint8_t data, uint8_t *data_length, uint8_t *complete_message_received)
{ 
   #if 0
   //===============================================================//
   static uint8_t   receive_data_index =0;
   static uint8_t   receive_packet_size=0;
   static uint8_t   receive_data_buffer[RX_MESSAGE_MAX_SIZE];
   receive_data_buffer[receive_data_index]= data ;
   //========handshake process==============//
   if ((receive_data_index == START_BYTE_INDEX) && (receive_data_buffer[START_BYTE_INDEX] != START_BYTE  ))
   {
      return; // This is not a correct message
   }
   else if (receive_data_index == DATA_LENGTH_INDEX)
   {
      //========extract data length byte=======//
      receive_packet_size = receive_data_buffer[DATA_LENGTH_INDEX] + CONTROL_BYTES;
      if (receive_packet_size > RX_MESSAGE_MAX_SIZE)
      {
         receive_packet_size_overflow_flag= 1;
         receive_data_index = 0 ;
         return; 
      }
   }
   receive_data_index++;
   if ( (receive_data_index == receive_packet_size) || (receive_data_index >= RX_MESSAGE_MAX_SIZE) )
   {
	  receive_data_index=0;                    // reset data index
	  //fifo_buffer_push_array(rx_buffer,receive_data_buffer,receive_packet_size);  // push the received data to the buffer
	  (*data_length)  = receive_packet_size;    // pass by reference the received data length
	  (*complete_message_received)++;           // increment the no. of completed message received in the buffer
   }
   #endif 
}

void send_data_process(uint8_t *data, uint8_t transmit_data_length,
                        uint8_t data_type , uint8_t test_ID)
{
   uint8_t      TxPacketLng = 0;
   uint8_t      TxDataBuff[PC_TX_BUFFER_MAX_SIZE];
	//========== Check message length =======//
    if (transmit_data_length > PC_TX_BUFFER_MAX_SIZE)
    {                                                  
      transmit_data_length = 0 ;                        // reject message due to greater than max buffer size                    
      data_type = REJECT_MSG_LEN  ;                 
    }                                                                                
   //====================================================================//
   TxPacketLng = transmit_data_length; 
   /* Copy the Message to the Tx Buffer */
   memcpy(TxDataBuff+DATA_INDEX , data , transmit_data_length);           
   TxDataBuff [DATA_INDEX + transmit_data_length]    = '\n'; // Data Stream ends by new line
   // ============== Send the data in serial UART Port and wait until the end =================// 
   for (int i =0 ; i<=TxPacketLng ; i++)
      {                                   
         while(tx_hw_buffer_status()== UART_TX_FULL);  // wait until it is empty
		 send(TxDataBuff[i]);   
         _delay_us(1);
      }
}