/*
 * EEPROM.c
 *
 * Created: 05-Mar-22 8:13:24 AM
 *  Author: ezz_a
 */ 
#include <avr/io.h>
#include "std_macros.h"

void EEPROM_vWrite(unsigned short address, unsigned char data)
{
	//setting up address register;
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	//setting up data register
	EEDR=data;
	//Assert EEMWE
	SET_BIT(EECR,EEMWE);
	//Start writing by asserting EEWE
	SET_BIT(EECR,EEWE);
	//loop until write is complete
	while(READ_BIT(EECR,EEWE)==1);
}

unsigned char EEPROM_u8Read(unsigned short address)
{
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	
	SET_BIT(EECR,EERE);
	
	return EEDR;
}