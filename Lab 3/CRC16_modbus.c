//================= CRC 16 for modbus checksum  ============================//
/******************************************************************************
 * Copyright (C) 2018 by SEDC
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. SEDC are not liable for any
 * misuse of this material.
 *****************************************************************************/
/**
 * @file CRC16_modbus.c
 * @brief CRC calculator
 *
 * This implementation CRC calculation function. It will compute the CRC for 16 bit data.
 * Also it validate the CRC for a given string of data
 *
 * @author Samah Nafie 
 * @modify Ashraf Abubaker
 * @date   24 April 2019
 *
 */
#include "CRC16_modbus.h"
#include "stdint.h"
#include "stdlib.h"

// Note : reflected CRC 16 Algorithm 
uint16_t CRC16(uint8_t *data ,uint8_t data_length) 
{
   uint16_t pattern = 0xA001;
   uint16_t CheckSum;
   uint8_t j=0;
   uint8_t i=0;
   
   CheckSum = 0xffff;

   for (j=0; j<data_length; j++)
   {
      CheckSum = CheckSum^(uint8_t)data[j];
  
      for(i=8 ; i>0 ; i--)
         if( (CheckSum) & 0x0001)
         {
            CheckSum = (CheckSum>>1)^ pattern ;  
         }
         else
         {
            CheckSum>>=1;
         }
   }
   CheckSum= CheckSum>>8 | CheckSum<<8;
   
   return CheckSum;
}

//================== CRC VALIDATION FUNCTION   =============================//
uint8_t valid_CRC(uint8_t* data , uint8_t data_length)
{
   uint8_t valid= true; 
   uint16_t CRC=0;
   
   //========================================//
   CRC  = (int16_t)(data[data_length+3])<<8;
   CRC += data[data_length+4];
   if(CRC != CRC16(data, data_length+3))
      valid = false;
   return valid;
}


