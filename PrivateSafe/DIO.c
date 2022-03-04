/*
 * DIO.c
 *
 * Created: 04-Mar-22 9:33:17 AM
 *  Author: ezz_a
 */ 
#include "std_macros.h"
#include <avr/io.h>

void DIO_vSetPinDir(unsigned char portname,unsigned char pinnumber,unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		{
			if(direction==1) SET_BIT(DDRA,pinnumber);
			else CLR_BIT(DDRA,pinnumber);
		}
		break;
		
		case 'B':
		case 'b':
		{
			if(direction==1) SET_BIT(DDRB,pinnumber);
			else CLR_BIT(DDRB,pinnumber);
		}
		break;
		
		case 'C':
		case 'c':
		{
			if(direction==1) SET_BIT(DDRC,pinnumber);
			else CLR_BIT(DDRC,pinnumber);
		}
		break;
		
		case 'D':
		case 'd':
		{
			if(direction==1) SET_BIT(DDRD,pinnumber);
			else CLR_BIT(DDRD,pinnumber);
		}
		break;
	}
}

void DIO_vWrite(unsigned char portname, unsigned char pinnumber, unsigned char val)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		{
			if(val==1) SET_BIT(PORTA,pinnumber);
			else CLR_BIT(PORTA,pinnumber);
		}
		break;
		
		case 'B':
		case 'b':
		{
			if(val==1) SET_BIT(PORTB,pinnumber);
			else CLR_BIT(PORTB,pinnumber);
		}
		break;
		
		case 'C':
		case 'c':
		{
			if(val==1) SET_BIT(PORTC,pinnumber);
			else CLR_BIT(PORTC,pinnumber);
		}
		break;
		
		case 'D':
		case 'd':
		{
			if(val==1) SET_BIT(PORTD,pinnumber);
			else CLR_BIT(PORTD,pinnumber);
		}
		break;
	}
}

void DIO_vToggle(unsigned char portname, unsigned char pinnumber)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		{
			TOG_BIT(PORTA,pinnumber);
		}
		break;
		
		case 'B':
		case 'b':
		{
			TOG_BIT(PORTB,pinnumber);
		}
		break;
		
		case 'C':
		case 'c':
		{
			TOG_BIT(PORTC,pinnumber);
		}
		break;
		
		case 'D':
		case 'd':
		{
			TOG_BIT(PORTD,pinnumber);
		}
		break;
	}
}

unsigned char DIO_u8read(unsigned char portname, unsigned char pinnumber)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		{
			return READ_BIT(PINA,pinnumber);
		}
		break;
		
		case 'B':
		case 'b':
		{
			return READ_BIT(PINB,pinnumber);
		}
		break;
		
		case 'C':
		case 'c':
		{
			return READ_BIT(PINC,pinnumber);
		}
		break;
		
		case 'D':
		case 'd':
		{
			return READ_BIT(PIND,pinnumber);
		}
		break;
	}
}

void DIO_vSETPORTDir(unsigned char portname, unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		{
			DDRA = direction;
		}
		break;
		
		case 'B':
		case 'b':
		{
			DDRB=direction;
		}
		break;
		
		case 'C':
		case 'c':
		{
			DDRC=direction;
		}
		break;
		
		case 'D':
		case 'd':
		{
			DDRD=direction;
		}
		break;
	}
}

void DIO_vWritePORT(unsigned char portname, unsigned char val)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		{
			PORTA=val;
		}
		break;
		
		case 'B':
		case 'b':
		{
			PORTB=val;
		}
		break;
		
		case 'C':
		case 'c':
		{
			PORTC=val;
		}
		break;
		
		case 'D':
		case 'd':
		{
			PORTD=val;
		}
		break;
	}
}

void DIO_vTOGPORT(unsigned char portname)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		{
			PORTA^=0xFF;
		}
		break;
		
		case 'B':
		case 'b':
		{
			PORTB^=0xFF;
		}
		break;
		
		case 'C':
		case 'c':
		{
			PORTC^=0xFF;
		}
		break;
		
		case 'D':
		case 'd':
		{
			PORTD^=0xFF;
		}
		break;
	}
}
unsigned char DIO_u8ReadPort(unsigned char portname)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		{
			return PINA;
		}
		break;
		
		case 'B':
		case 'b':
		{
			return PINB;
		}
		break;
		
		case 'C':
		case 'c':
		{
			return PINC;
		}
		break;
		
		case 'D':
		case 'd':
		{
			return PIND;
		}
		break;
	}
}

void DIO_vWriteHighNibble(unsigned char portname, unsigned char val)
{
	val<<=4;
	switch (portname)
	{
		case 'A':
		case 'a':
		{
			PORTA &= 0x0F; //We must ensure high nibble pins are is deasserted
			PORTA|=val; //we then write the 4 least sig bits on the high nibbole of the port.
		}
		break;
		
		case 'B':
		case 'b':
		{
			PORTB &= 0x0F;
			PORTB|=val;
		}
		break;
		
		case 'C':
		case 'c':
		{
			PORTC &= 0x0F;
			PORTC|=val;
		}
		break;
		
		case 'D':
		case 'd':
		{
			PORTD &= 0x0F;
			PORTD|=val;
		}
		break;
	}
}

void DIO_vWriteLowNibble(unsigned char portname, unsigned char val)
{
	switch (portname)
	{
		case 'A':
		case 'a':
		{
			PORTA &= 0xF0; //We must ensure low nibble pins are is deasserted because we will use or to write our data
			PORTA|=val; //we then write the 4 least sig bits on the high nibble of the port.
		}
		break;
		
		case 'B':
		case 'b':
		{
			PORTB &= 0xF0;
			PORTB|=val;
		}
		break;
		
		case 'C':
		case 'c':
		{
			PORTC &= 0xF0;
			PORTC|=val;
		}
		break;
		
		case 'D':
		case 'd':
		{
			PORTD &= 0xF0;
			PORTD|=val;
		}
		break;
	}
}

void DIO_vEnablePullUp(unsigned char portname, unsigned char pinnumber,unsigned char en)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		{
			if(en==1) SET_BIT(PORTA,pinnumber);
			else CLR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		case 'b':
		{
			if(en==1) SET_BIT(PORTB,pinnumber);
			else CLR_BIT(PORTB,pinnumber);
		}
		break;
		
		
		case 'C':
		case 'c':
		{
			if(en==1) SET_BIT(PORTC,pinnumber);
			else CLR_BIT(PORTC,pinnumber);
		}
		break;
		
		
		case 'D':
		case 'd':
		{
			if(en==1) SET_BIT(PORTD,pinnumber);
			else CLR_BIT(PORTD,pinnumber);
		}
		break;
		
		
		default:
		break;
	}
}