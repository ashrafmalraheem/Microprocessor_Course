/******************************************************************************
 * Copyright (C) 2018 by R&D SEDC
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. SEDC are not liable for any misuse of this material.
 *****************************************************************************/
/**
 * @file MessageFormatDefinition.h
 * @brief 
 *
 *  
 *
 * @author: Samah Fadlelmoula
 * @Modifyed: 
 * @date February 13, 2020, 2:20 PM
 *
 */

#ifndef MESSEG_FORMAT_DEFINITION_H
#define	MESSEG_FORMAT_DEFINITION_H

/*
 *  Section: Included Files
 */


/*
 *  Section: Macros Definitions
 */

////================================================================================////
////                    MESSAGE FORMAT                                              ////
////  +------------+-------------+------+------+----------------+                   ////
////  |                         data                            |                   ////
////  +------------+-------------+------+------+----------------+                   ////
////  |                         index 0                                             ////
////  +------------+-------------+------+------+----------------+                   ////

////   data:            0 to data length bytes :Data being sent                     ////                      
//=================DATA MESSAGE DEFENITIONS==========//
#define DATA_INDEX                  0                                                     //index of data field in the data packet
//===========================================================//
#define MAX_DATA_LENGTH             256          // 1 byte data length
//==============  CRC ERROR DEFENITIONS   ====================//
#define NUM_OF_RETRIES              3
//==============  MESSAGE type  ====================//    
//============ MCU<->PC SEND/RECEIVE DATA TYPES                        
#define  LOG_MSG                    11     //0xB                                              //pc         
#define  INVALID_RQ                 62
#define  TEST_RESULT                9                                                   //uiu
//========= UIU->MCU SEND DATA TYPES 
#define  ACK                        25
//=====================================//  
#define  REJECT_MSG_LEN             26

//========== data value in case of sys_status_symboles ==//
#define  LCD_ON                     5              //All LCD segments on

#endif	/* MESSEG_FORMAT_DEFINITION_H */
