/*
 * std_macros.h
 *
 * Created: 18-Feb-22 1:24:12 PM
 *  Author: ezz_a
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
//MACROS File for setting, resetting, toggling and reading bits from registers.
#define SET_BIT(reg,bit)	reg|=(1<<bit) //asserting a bit in a register
#define CLR_BIT(reg,bit)	reg&=(~(1<<bit)) //deasserting a bit in a register
#define TOG_BIT(reg,bit)	reg^=(1<<bit) //toggling a bit in a register
#define READ_BIT(reg,bit)	(reg&(1<<bit))>>bit //reading a bit in a register.



#endif /* STD_MACROS_H_ */