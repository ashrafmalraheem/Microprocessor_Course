'''/*****************************************************************************
 * Copyright (C) 2020 by R&D SEDC
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. SEDC are not liable for any misuse of this material.
****************************************************************************/'''
'''/**
 * @file Logger.py
 * @brief 
 *
 *  
 *
 * @author: R&D SEDC
 * @Modifyed: 
 * @date February 13, 2020, 2:20 PM
 *
 */'''


'''/*
 * Section: Included Files
 */'''
import serial
import time
print("Logger Program")
TX_BUFFER_MAX_SIZE = 100
ser = serial.Serial('COM13',baudrate=2400, bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE, timeout=None)
print(ser.name)
#ser.open(COM13)
#ser.write(b'hello')
print(ser.is_open)
#x = "logger program"
while True :
	x = ser.read_until(b'\n',size = TX_BUFFER_MAX_SIZE)
	print(str(x))
	
ser.close()
