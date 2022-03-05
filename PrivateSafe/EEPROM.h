/*
 * EEPROM.h
 *
 * Created: 05-Mar-22 8:21:08 AM
 *  Author: ezz_a
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
/*
Function Name: EEPROM_vWrite
Function Description: This functions writes data in EEPROM Memory
Function Input: address of EEPROM to be written into. data to be written in the address selected.
Function return type: void
*/
void EEPROM_vWrite(unsigned short address, unsigned char data);


/*
Function Name: EEPROM_u8Read
Function Description: This functions reads data from EEPROM Memory
Function Input: address of EEPROM to be read from.
Function return type: unsigned char
*/
unsigned char EEPROM_u8Read(unsigned short address);


#endif /* EEPROM_H_ */