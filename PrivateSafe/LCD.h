/*
 * LCD.h
 *
 * Created: 04-Mar-22 12:07:11 PM
 *  Author: ezz_a
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "LCD_config.h"
//Macros defining Pin numbers and Some LCD Commands to ease their use.
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAY_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define EN 0
#define RW 1
#define RS 2
#define EIGHT_BITS 0x38
#define FOUR_BITS 0x28

/*
Function Name: LCD_vInit
Function Description: This Function Initializes LCD according to Ports and mode selected in LCD_config.h file
Function input: No input
Function return type: void (no returned data)
*/
void LCD_vInit(void);

/*
Function Name: peekaboo
Function Description: This Function Sends a Pulse on LCD Enable Pin in order to execute required action. (Not to be used in Main File)
Function input: No input
Function return type: void
*/
static void peekaboo(void);

/*
Function Name: LCD_vSend_cmd
Function Description: This Function sends and executes a command provided by the user to the LCD
Function input: Command Number (Provided by LCD Device Datasheet)
Function return type: void
*/
void LCD_vSend_cmd(char cmd);

/*
Function Name: LCD_vSend_char
Function Description: This Function sends and displays a char provided by the user to the LCD
Function input: ASCII code of the character to be displayed.
Function return type: void
*/
void LCD_vSend_char(char chr);

/*
Function Name: LCD_vSend_string
Function Description: This Function sends and displays a string provided by the user to the LCD (Based on LCD_vSend_char)
Function input: a string ex:"Hello_World"
Function return type: void
*/
void LCD_vSend_string(char *data);

/*
Function Name: LCD_clearscreen
Function Description: This Function clears the screen and returns pointer to Initial LCD Location (Based on LCD_vSend_cmd)
Function input: No input
Function return type: void
*/
void LCD_clearscreen(void);

/*
Function Name: LCD_clearscreen
Function Description: This Function moves LCD pointer to required position in the LCD (Based on LCD_vSend_cmd)
Function input: Coordinates of the point we need to move pointer to it (rows,column)
Function return type: void
*/
void LCD_movecursor(char row, char column);




#endif /* LCD_H_ */