/*
 * keypad.c
 *
 * Created: 04-Mar-22 8:52:24 AM
 *  Author: ezz_a
 */ 
#include "DIO.h"
#include "keypad_config.h"

void keypad_vInit(void)
{
	DIO_vSETPORTDir(KPORT,0x0F); //P7 to P4 are input
	DIO_vEnablePullUp(KPORT,7,1);
	DIO_vEnablePullUp(KPORT,6,1);
	DIO_vEnablePullUp(KPORT,5,1);
	DIO_vEnablePullUp(KPORT,4,1);
}

unsigned char keypad_u8read(void)
{
	unsigned char ascii[4][4] = {
								{'7','8','9','/'},
								{'4','5','6','x'},
								{'1','2','3','-'},
								{'A','0','=','+'}
												};
	char row,col,x;
	char return_value=0xFF;
	
	for(row=0;row<=3;row++)
	{
		DIO_vWriteLowNibble(KPORT,0xFF);
		DIO_vWrite(KPORT,row,0); //this is output, so i write 0 on the row i want to start reading from pins(0,1,2,3)==>rows(0.,1,2,3)
		for(col=0;col<=3;col++)
		{
			x=DIO_u8read(KPORT,col+4);//this is input so i iterate on pins(4,5,6,7)===>col(0,1,2,3) to see if one is pushed 
			if(x==0)
			{
				return_value=ascii[row][col];
				break;
			}
		}
		if(x==0) break;
	}
	return return_value;
}