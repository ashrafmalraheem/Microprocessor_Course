#******************************************************************************
# Copyright (C) 2020 by Ashraf Abubaker - SEDC & University of Khartoum
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Ashraf Abubaker, SEDC and the University of Khartoum are not liable 
# for any misuse of this material. 
# 
# Created by Ashraf Abubaker for Microprocessor System Design Course 
# University of Khartoum - NOV 2018
# You can obtain this file from the Git Repository
# https://github.com/ashrafmalraheem/Mircoprocessor_Course
#*****************************************************************************

#------------------------------------------------------------------------------

# Add your target here
TARGET  = main
# Add your mcu type here
MCU = atmega328p
# Add your Platform here
PLATFORM = arduino
# Add the mcu crystal frequency here
CLOCK_FREQ = 16000000UL
# Add the com port that your platform is connected to
COM = COM1
# Add the baud rate here
BAUD_RATE = 57600
# Add the OS 
OS = LINUX
