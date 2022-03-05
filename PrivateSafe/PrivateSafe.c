/*
 * PrivateSafe.c
 *
 * Created: 04-Mar-22 7:52:35 PM
 *  Author: ezz_a
 */ 

#include "EEPROM.h"
#include "keypad.h"
#include "LCD.h"
#include "DIO.h"
#include "util/delay.h"
#define PASSWORD_LOC0 0x20
#define PASSWORD_LOC1 0x21
#define PASSWORD_LOC2 0x22
#define PASSWORD_LOC3 0x23
#define CHECK_PASSWORD_SETTING 0x30
#define LOCKFLAG 0x10
#define Max_Trials 4

/*
void Set_Pass(char *arr, unsigned short adr)
{
	LCD_vSend_string("Set Password: ");
	LCD_movecursor(2,1);
	char x;
	while((adr+4)==0xFF)
	{
		x=keypad_u8read();
		if(x!=0xFF)
		{
			(*arr)=x;
			arr++;
			EEPROM_vWrite(adr,x);
			adr++;
			LCD_vSend_char(x);
			LCD_movecursor(2,1);
			_delay_ms(300);
			LCD_vSend_char('*');
			_delay_ms(200);
		}
	}
	EEPROM_vWrite(200,0x00);
}
*/
void set_password(void)
{
	char i=0;
	LCD_clearscreen();
	LCD_vSend_string("SET PASSWORD");
	LCD_movecursor(2,1);
	for(i=0;i<4;i++)
	{
		char x;
		do
		{
			x=keypad_u8read();
		}
		while(x==0xFF);
		LCD_vSend_char(x);
		_delay_ms(250);
		LCD_movecursor(2,1+i);
		LCD_vSend_char('*');
		EEPROM_vWrite(PASSWORD_LOC0+i,x);
	}
}
int main(void)
{
	keypad_vInit();
	LCD_vInit();
	LCD_vSend_string("Welcome");
	_delay_ms(200);
	LCD_clearscreen();
	char j;
	char trials=0;
	char password[4];
	char flag=0;
	char c;
	if(EEPROM_u8Read(CHECK_PASSWORD_SETTING)==0xFF)
	{
		set_password();
		EEPROM_vWrite(CHECK_PASSWORD_SETTING,0x00);
	}
    while(trials<Max_Trials)
    {
		if(EEPROM_u8Read(LOCKFLAG)==0x00)
		{
			trials=5;
			continue;
		}
		LCD_clearscreen();
		LCD_vSend_string("Enter Password: ");
		LCD_movecursor(2,1);
		for(j=0;j<4;j++)
		{
			do
			{
				password[j]=keypad_u8read();
			} while (password[j]==0xFF);
			LCD_vSend_char(password[j]);
			_delay_ms(250);
			LCD_movecursor(2,1+j);
			LCD_vSend_char('*');
			_delay_ms(200);
		}
		
	    LCD_clearscreen();
	    LCD_vSend_string("Loading...");
	    _delay_ms(200);
		
	    for(c=0;c<4;c++)
	    {
		    if(password[c]==EEPROM_u8Read(PASSWORD_LOC0+c)) continue;
		    else flag=1;
	    }
	    if(flag==1)
	    {
			trials++;
		    LCD_clearscreen();
		    LCD_vSend_string("WRONG PASSWORD!");
			LCD_movecursor(2,1);
			LCD_vSend_char((Max_Trials-trials)+48);
			LCD_vSend_string(" trials left");
		    _delay_ms(1000);
	    }
		else
		{
			LCD_clearscreen();
			LCD_vSend_string("Correct Password");
			_delay_ms(200);
			LCD_movecursor(2,1);
			LCD_vSend_string("Safe Open!");
			_delay_ms(1000);
			break;
		}
    }
	
	if(trials>=Max_Trials)
	{
		LCD_clearscreen();
		LCD_vSend_string("SAFE LOCKED !");
		EEPROM_vWrite(LOCKFLAG,0x00);
		_delay_ms(500);
		LCD_vSend_cmd(0x08);
	}
	else
	{
		char x;
		do {
			x=keypad_u8read();
		} while(x==0xFF);
		if(x=='A')
		{
			LCD_clearscreen();
			LCD_vSend_string("Resetting...");
			_delay_ms(1000);
			set_password();
			LCD_clearscreen();
			LCD_vSend_string("Password Reset");
			_delay_ms(500);
			LCD_movecursor(2,1);
			LCD_vSend_string("Please Restart.");
			_delay_ms(1000);
			LCD_vSend_cmd(0x08);
		}
		else LCD_vSend_cmd(0x08);
	}

}