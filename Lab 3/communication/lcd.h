#include <io.h>

#ifndef F_CPU
	#define F_CPU 12000000UL
#endif

#include <delay.h>

#include "myutils.h"

#ifndef _LCD_H
#define _LCD_H
/*_________________________________________________________________________________________*/
/***************************************************
	M A C R O S
***************************************************/
#define LCDClear() LCDCmd(0b00000001)
#define LCDHome() LCDCmd(0b00000010);
#define LCDCmd(c) (LCDByte(c,0))
#define LCDData(d) (LCDByte(d,1))
#define LCDWriteStringXY(x,y,msg) {\
 LCDGotoXY(x,y);\
 LCDWriteString(msg);\
}

#define LCDWriteIntXY(x,y,val,fl) {\
 LCDGotoXY(x,y);\
 LCDWriteInt(val,fl);\
}
/***************************************************/

/************************************************
	LCD CONNECTIONS
*************************************************/

#define LCD_DATA C	//Port PC0-PC3 are connected to D4-D7

#define LCD_E D 		//Enable OR strobe signal
#define LCD_E_POS	PD7	//Position of enable in above port

#define LCD_RS D	
#define LCD_RS_POS 	PD6

#define LCD_RW D
#define LCD_RW_POS 	PD5


//************************************************

#define LS_BLINK 0B00000001
#define LS_ULINE 0B00000010



/***************************************************
			F U N C T I O N S
****************************************************/


/*****************************************************************
	
	This function Initializes the lcd module
	must be called before calling lcd related functions

	Arguments:
	style = LS_BLINK,LS_ULINE(can be "OR"ed for combination)
	LS_BLINK :The cursor is blinking type
	LS_ULINE :Cursor is "underline" type else "block" type

	*****************************************************************/
void InitLCD(uint8_t style);
/*****************************************************************
	
	This function Writes a given string to lcd at the current cursor
	location.

	Arguments:
	msg: a null terminated string to print


	*****************************************************************/
void LCDWriteString(const char *msg);
/***************************************************************
	This function writes a integer type value to LCD module

	Arguments:
	1)int val	: Value to print

	2)unsigned int field_length :total length of field in which the value is printed
	must be between 1-5 if it is -1 the field length is no of digits in the val

	****************************************************************/
void LCDWriteInt(int val,unsigned int field_length);
/***************************************************************
	This function move the cursor to the x,y location

	Arguments:
	1)x	: x axis starts from 1

	2)y : y axis starts from 1

	****************************************************************/
void LCDGotoXY(uint8_t x,uint8_t y);

//Low level
/***************************************************************
	Sends a byte to the LCD in 4bit mode
	cmd=0 for data
	cmd=1 for command


	NOTE: THIS FUNCTION RETURS ONLY WHEN LCD HAS PROCESSED THE COMMAND

	****************************************************************/
void LCDByte(uint8_t,uint8_t);

/***************************************************************
This function waits till lcd is BUSY
	****************************************************************/
void LCDBusyLoop();

/***************************************************
			F U N C T I O N S     E N D
****************************************************/







/*_________________________________________________________________________________________*/
#endif






