/*
 * LCD.c
 *
 * Created: 04-Mar-22 12:06:58 PM
 *  Author: ezz_a
 */ 
#include "std_macros.h"
#include <avr/io.h>
#include "LCD.h"
#include "util/delay.h"

void LCD_vInit(void) //LET LCD IS CONNECTED TO PORTA & CONTROLLED BY 1st 3 PINS IN B
{
	#if defined EIGHT_BITS_MODE
	DIO_vSETPORTDir(LCD_PORT,1);
	DIO_vSetPinDir(CTRL_PORT,EN,1);
	DIO_vSetPinDir(CTRL_PORT,RS,1);
	DIO_vSetPinDir(CTRL_PORT,RW,1);
	DIO_vWrite('B',RW,0);
	LCD_vSend_cmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE);
	_delay_ms(1);
	#elif defined FOUR_BITS_MODE
	DIO_vSetPinDir(LCD_PORT,4,1);
	DIO_vSetPinDir(LCD_PORT,5,1);
	DIO_vSetPinDir(LCD_PORT,6,1);
	DIO_vSetPinDir(LCD_PORT,7,1);
	DIO_vSetPinDir(CTRL_PORT,EN,1);
	DIO_vSetPinDir(CTRL_PORT,RS,1);
	DIO_vSetPinDir(CTRL_PORT,RW,1);
	DIO_vWrite(CTRL_PORT,RW,0);
	LCD_vSend_cmd(RETURN_HOME);
	_delay_ms(10);
	LCD_vSend_cmd(FOUR_BITS);
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE);
	_delay_ms(1);
	#endif
}


static void peekaboo(void)
{
	DIO_vWrite(CTRL_PORT,EN,1);
	_delay_ms(2);
	DIO_vWrite(CTRL_PORT,EN,0);
	_delay_ms(2);
}

void LCD_vSend_cmd(char cmd)
{
	#if defined EIGHT_BITS_MODE
	DIO_vWritePORT(LCD_PORT,cmd);
	DIO_vWrite(CTRL_PORT,RS,0);
	peekaboo();
	_delay_ms(1);
	#elif defined FOUR_BITS_MODE
	DIO_vWriteHighNibble(LCD_PORT,(cmd>>4));
	DIO_vWrite(CTRL_PORT,RS,0);
	peekaboo();
	DIO_vWriteHighNibble(LCD_PORT,cmd);
	DIO_vWrite(CTRL_PORT,RS,0);
	peekaboo();
	#endif
	_delay_ms(1);
	
}

void LCD_vSend_char(char chr)
{
	#if defined EIGHT_BITS_MODE
	DIO_vWritePORT(LCD_PORT,chr);
	DIO_vWrite(CTRL_PORT,RS,1);
	peekaboo();
	_delay_ms(1);
	#elif defined FOUR_BITS_MODE
	DIO_vWriteHighNibble(LCD_PORT,(chr>>4));
	DIO_vWrite(CTRL_PORT,RS,1);
	peekaboo();
	DIO_vWriteHighNibble(LCD_PORT,chr);
	DIO_vWrite(CTRL_PORT,RS,1);
	peekaboo();
	#endif
}

void LCD_vSend_string(char *data)
{
	while((*data)!='\0')
	{
		LCD_vSend_char(*data);
		data++;
	}
}

void LCD_clearscreen(void)
{
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
}

void LCD_movecursor(char row, char column)
{
	char pos=0;
	if(row==1)
	{
		pos=(0x80)+column-1;
	}
	else if(row==2)
	{
		pos=(0xC0)+column-1;
	}
	else
	{
		pos=0x80;
	}
	LCD_vSend_cmd(pos);
	_delay_ms(1);
}



