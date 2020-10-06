/******************************************************************************
 * Copyright (C) 2020 by R&D SEDC
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. SEDC are not liable for any misuse of this material.
 *****************************************************************************/
/**
 * @file main.c
 * @brief 
 *
 *  
 *
 * @author: R&D SEDC
 * @Modifyed: 
 * @date February 13, 2020, 2:20 PM
 *
 */


/*
 * Section: Included Files
 */
#include <io.h>
#include <stdint.h>
#include <delay.h>
#include "avr_uart.h"
#include "LogMessage.h"
#include "math.h"

/*
 * Section: Macros
 */
#define BIT5  0b00100000
#define BAUD_RATE     19200
#define NO_OF_BITS    _7BITS
#define PARITY        EVEN
#define STOP_BITS     _1BIT

#define ADC_FULL      1023
#define VCC           5.0
#define RF            18000

/*
 * Section: Function Decalartion
 */
void ADC_Setup();
void ADC_StartConvert();
float ADC_read();
uint8_t ADC_IsNotComplete();
float GetResistor(float adcReading);
float GetTemperature(float ntc);
/*
 * Section: Interrupt Service routing Defintion
 */
 

int main(void)
{
    /* Replace with your application code */
	
	/*** set section ***/
	USART_Init(BAUD_RATE, NO_OF_BITS, PARITY, 1);
	ADC_Setup();
	Log_Int((char*)"Hello World",ADCSRA);
	while(1){
		/*** Loop section ***/
		_delay_ms(1000);
		/*Print the reading */	
		Log_Float((char*)"Temperature",GetTemperature(GetResistor(ADC_read())));
		
	}
}


/*
 * Section: Function Defintion
 */
void ADC_Setup(){
	// Enable the ADC
	ADCSRA |= 1<<ADEN;
	// Select the refence voltage to be AVcc, which is connected to Vcc in the Arduino Nano board
	ADMUX |= 1<<REFS0;
	// Set Prescaler to 128, so that the ADC clock is 16M/128= 125Khz
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	ADCSRA |= (1<<ADSC) | (1<<ADATE);
	
}
void ADC_StartConvert(){
	ADCSRA |= (1<<ADSC);
}
float ADC_read(){
	return ADC*VCC/ADC_FULL;
}
uint8_t ADC_IsNotComplete(){
	// return 1 if not complete
	return (ADCSRA & (1<<ADSC));
}

float GetResistor(float adcReading){
	return adcReading*RF/(VCC-adcReading);
}

float GetTemperature(float ntc){
	/* Using the simplified Steinhart Equation
	 * T = 1/(1/T0 + ln(Rt/R0)/B) - 273.15
	 * T in celsius
	 * T0 and B in kelvin
	 */
	 float T;
	 const float T0 = 298.2; // base temperature
	 const float B = 3470;    // material constant
	 const float R0 = 10000; // base resistor
	 T = 1/(1/T0 + log(ntc/R0)/B) - 273.15;
	 return T;
}
