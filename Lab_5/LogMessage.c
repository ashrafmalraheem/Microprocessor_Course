/******************************************************************************
 * Copyright (C) 2018 by R&D SEDC
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. SEDC are not liable for any misuse of this material.
 *****************************************************************************/
/**
 * @file LogMessage.c
 * @brief Log functions implementation
 *
 * This implementation logging messages used for debugging. Different types of logging
 * messages are available such as loging int, float or array data type. 
 *
 * @author 
 * @modification Ashraf Abubaker
 * @date April 24 2019
 *
 */

/*
 *  Section: Included Files
 */
#include "LogMessage.h"
#include "MessageFormatDefinition.h"
#include "string.h"
#include "stdio.h"

/*
 *  Section: Variables Declaration 
 */

/* 
 *  Section: Functions Implementation
 */
 
 void Log_String(char* pLog_txt)                                            
{
     
   char msg [LOG_MAX_BUFFER] ;
      
   sprintf (msg , "%s", pLog_txt) ;                                                   
   
   send_data_process((uint8_t*)msg, strlen(msg) , LOG_MSG , 0);     
}

void Log_Float(char* pLog_txt, float Log_value)                                            
{
   char msg [LOG_MAX_BUFFER] ;
      
   sprintf (msg , "%s %lf", pLog_txt, Log_value) ;                                                   
   
   send_data_process((uint8_t*)msg, strlen(msg) , LOG_MSG , 0);     
}
//==========================================================================//

void Log_Int (char* pLog_txt, int32_t Log_value){ // takes text and unsigned integer32 as parameters and store them in one array and send it to PC port   
   char msg [LOG_MAX_BUFFER] ;
      
   sprintf (msg , "%s %ld", pLog_txt, Log_value) ;
   send_data_process((uint8_t*)msg, strlen(msg) , LOG_MSG , 0);     
}
//==========================================================================//

void Log_Hex(char* pLog_txt, char* pHex_Log, uint16_t Hex_len)   //, int flip)                     // taks text and array of hex as parameters and store them in one array and send it to PC port
{
   if (Hex_len > LOG_MAX_BUFFER){
       return ;
   }
   char msg [LOG_MAX_BUFFER] ;
   char temp[10] ;
   uint16_t i ;
      
    sprintf (msg , "%s", pLog_txt);
    for (i=0; i<Hex_len; i++)
    {
      sprintf(temp, "%02X ", (unsigned char)pHex_Log[i]) ; 
      strcat(msg, temp) ;                                                      // concatinate string & array of hex in one array
      //Log_Int((char*)"Length",strlen(msg),port_in_use);
    }
       
    send_data_process( (uint8_t*)msg, strlen(msg) , LOG_MSG , 0);     
    
}

void Log_Int_Arr (char* pLog_txt, char* pLog_array, uint16_t Arr_len)                                 // taks text and array of unsigned int as parameters and store them in one array and send it to PC port
{
   if (Arr_len > LOG_MAX_BUFFER)
   {
       return ;
   }
   char msg [LOG_MAX_BUFFER] ;
   char temp[128] ;
   uint16_t i ;
      
    sprintf (msg , "%s", pLog_txt) ;
    for (i=0; i<Arr_len; i++)
    {
      sprintf(temp, "%d ", (uint8_t)pLog_array[i]) ; 
      strcat(msg, temp) ;                                                      // concatinate string & array of hex in one array
    }
                                                            
    send_data_process((uint8_t*)msg, strlen(msg) , LOG_MSG , 0);     
}

