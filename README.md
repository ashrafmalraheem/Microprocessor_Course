# Mircoprocessor Course
EEE42101 Mircoprocessor System Design University of Khartoum 2020.
This repository contains all the material for the practical sessions for the Mircoprocessor course. 
The initial course outlines: 
  - two theortical and introductory sessions.
  - four practical sessons that cover major topic in microcontrollers: Development Environment, LED Blink, Periperals: timers & PWM, ADC, Communication such as UART.
  The suggested platform is Arduino nano. It has Atmega328P microcontroller. The suggested IDE either MPLAB X or Atmel Studio or standard gnu make and text editors.

It is suggested that the whole class is divided into 4 groups, each of 25 students at max. Better to divide them according to the track they take. So that the projects can be related to their track. The practical sessions should be 2 hours. Two groups at a time. One in the Electronics Labs and the Other in the computers Lab. The time is Sunday from 10:15 a.m to 12:15 a.m and Thursday 7:30 a.m. to 9:30 a.m.
4 teaching assistant are required to implement the sessions. 

The kits should be tested before starting the sessions. It has to verify the correct bootloader is written in the microcontroller. 

## 1- Introductoin To Microcontrollers: 
### @20/2/2020
This is an introductory sessino about the basics of microcontrollers, environements and some definitions of some terminologies.

### What is Microcontroller, Microcprocessor, SoC, Processor?
### General Characteristics of Microcontrollers:
  - Word Size
  - Insturction Set
  - Max Clock Speed
  - Available Memory (flash, RAM, EEPROM!)
  - Available Peripherals ( timers,comparators,PWM,ADC,Communication interfaces, GPIO)
  - Electrical Characterisitcs: (Voltage rating, temperature rating, ...etc)
  
  ### How to use Microcontroller?
    1- either by command line (Text editors: vi,vim,notepad++ & GNU make build automation)
    2- Through IDE
 Most IDE's are based on either eclipse or Netbeans. 
 
### Our Developing Platform:
  Arduino Nano platform: open hardare project designed by Arduino. It is a clone version. 
  It has an ATmega328p microcontroller. 
  General Charactersitics: 
    1- 8-bit MCE
    2- 32KB flash, 1KB EEPROM, 2KB SRAM.
    3- Two 8-bit Timers/counters, One 16-bit Timer/coutner
    4- Six PWM Channels.
    5- 8-Channel 10-bit ADC.
    6- Communication Interfaces: USART, SPI
 The platform communication to PC for programming, communication and debugging through FTDI FT232RL chip USB to serial converter. 
 
