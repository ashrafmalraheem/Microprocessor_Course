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

print("Logger Program")

ser = serial.Serial('COM13',baudrate=2400, bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE, timeout=None)
print(ser.name)
ser.write(b'hello')
print(ser.is_open)
x = ser.read(10)
print(x)

