/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : DIO_program.c                                   	     */
/* Date          : Feb 5, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "DIO_interface.h"

void DIO_vPinInit(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8PinDir, u8 Copy_u8PinVal){
	DIO_vSetPinDir(Copy_u8PortName, Copy_u8PinNum, Copy_u8PinDir);
	DIO_vSetPinValue(Copy_u8PortName, Copy_u8PinNum, Copy_u8PinVal);
}

//sets data direction of 1 pin in a port
void DIO_vSetPinDir(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8PinDir){
	if(Copy_u8PinDir == OUTPUT)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: SET_BIT(DDRA_REG, Copy_u8PinNum); break;
		case PORTB: SET_BIT(DDRB_REG, Copy_u8PinNum); break;
		case PORTC: SET_BIT(DDRC_REG, Copy_u8PinNum); break;
		case PORTD: SET_BIT(DDRD_REG, Copy_u8PinNum); break;
		}
	}
	else if(Copy_u8PinDir == INPUT)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: CLR_BIT(DDRA_REG, Copy_u8PinNum); break;
		case PORTB: CLR_BIT(DDRB_REG, Copy_u8PinNum); break;
		case PORTC: CLR_BIT(DDRC_REG, Copy_u8PinNum); break;
		case PORTD: CLR_BIT(DDRD_REG, Copy_u8PinNum); break;
		}
	}
}

//sets value of 1 pin in a port
void DIO_vSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8PinVal){
	if(Copy_u8PinVal == HIGH)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: SET_BIT(PORTA_REG, Copy_u8PinNum); break;
		case PORTB: SET_BIT(PORTB_REG, Copy_u8PinNum); break;
		case PORTC: SET_BIT(PORTC_REG, Copy_u8PinNum); break;
		case PORTD: SET_BIT(PORTD_REG, Copy_u8PinNum); break;
		}
	}
	else if(Copy_u8PinVal == LOW)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: CLR_BIT(PORTA_REG, Copy_u8PinNum); break;
		case PORTB: CLR_BIT(PORTB_REG, Copy_u8PinNum); break;
		case PORTC: CLR_BIT(PORTC_REG, Copy_u8PinNum); break;
		case PORTD: CLR_BIT(PORTD_REG, Copy_u8PinNum); break;
		}
	}
}

//reads value on 1 pin in a port
u8 DIO_u8ReadPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNum){
	u8 Local_u8ReadValue = 0;
	switch(Copy_u8PortName)
	{
	case PORTA: Local_u8ReadValue = GET_BIT(PINA_REG, Copy_u8PinNum); break;
	case PORTB: Local_u8ReadValue = GET_BIT(PINB_REG, Copy_u8PinNum); break;
	case PORTC: Local_u8ReadValue = GET_BIT(PINC_REG, Copy_u8PinNum); break;
	case PORTD: Local_u8ReadValue = GET_BIT(PIND_REG, Copy_u8PinNum); break;
	}
	return Local_u8ReadValue;
}

//sets data direction of all 8 pins in a port
void DIO_vSetGroupDir(u8 Copy_u8PortName, u8 Copy_u8PortDir){
	if(Copy_u8PortDir == OUTPUT)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: DDRA_REG = 0xFF; break;
		case PORTB: DDRB_REG = 0xFF; break;
		case PORTC: DDRC_REG = 0xFF; break;
		case PORTD: DDRD_REG = 0xFF; break;
		}
	}
	else if(Copy_u8PortDir == INPUT)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: DDRA_REG = 0x00; break;
		case PORTB: DDRB_REG = 0x00; break;
		case PORTC: DDRC_REG = 0x00; break;
		case PORTD: DDRD_REG = 0x00; break;
		}
	}
}

//sets value of all 8 pins in a port
void DIO_vSetGroupValue(u8 Copy_u8PortName, u8 Copy_u8PortValue){
	switch(Copy_u8PortName)
	{
	case PORTA: PORTA_REG = (PORTA_REG&0) | Copy_u8PortValue; break;
	case PORTB: PORTB_REG = (PORTB_REG&0) | Copy_u8PortValue; break;
	case PORTC: PORTC_REG = (PORTC_REG&0) | Copy_u8PortValue; break;
	case PORTD: PORTD_REG = (PORTD_REG&0) | Copy_u8PortValue; break;
	}
}

//reads value on all 8 pins of a port
u8 DIO_u8ReadGroupValue(u8 Copy_u8PortName){
	u8 Local_u8ReadValue = 0;
	switch(Copy_u8PortName)
	{
	case PORTA: Local_u8ReadValue = PINA_REG; break;
	case PORTB: Local_u8ReadValue = PINB_REG; break;
	case PORTC: Local_u8ReadValue = PINC_REG; break;
	case PORTD: Local_u8ReadValue = PIND_REG; break;
	}
	return Local_u8ReadValue;
}

//sets data direction of 4 LSB pins of a port
void DIO_vSet4LSBDir(u8 Copy_u8PortName, u8 Copy_u8PinDir){
	if(Copy_u8PinDir == OUTPUT)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: DDRA_REG |= 0x0F; break;
		case PORTB: DDRB_REG |= 0x0F; break;
		case PORTC: DDRC_REG |= 0x0F; break;
		case PORTD: DDRD_REG |= 0x0F; break;
		}
	}
	else if(Copy_u8PinDir == INPUT)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: DDRA_REG &= 0xF0; break;
		case PORTB: DDRB_REG &= 0xF0; break;
		case PORTC: DDRC_REG &= 0xF0; break;
		case PORTD: DDRD_REG &= 0xF0; break;
		}
	}
}

//sets data direction of 4 MSB pins of a port
void DIO_vSet4MSBDir(u8 Copy_u8PortName, u8 Copy_u8PinDir){
	if(Copy_u8PinDir == OUTPUT)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: DDRA_REG |= 0xF0; break;
		case PORTB: DDRB_REG |= 0xF0; break;
		case PORTC: DDRC_REG |= 0xF0; break;
		case PORTD: DDRD_REG |= 0xF0; break;
		}
	}
	else if(Copy_u8PinDir == INPUT)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: DDRA_REG &= 0x0F; break;
		case PORTB: DDRB_REG &= 0x0F; break;
		case PORTC: DDRC_REG &= 0x0F; break;
		case PORTD: DDRD_REG &= 0x0F; break;
		}
	}
}

//sets value of 4LSB pins of a port
void DIO_vSet4LSBValue(u8 Copy_u8PortName, u8 Copy_u8PinVal){
	switch(Copy_u8PortName)
	{
	case PORTA: PORTA_REG = (PORTA_REG&0xF0) | (Copy_u8PinVal&0x0F); break;
	case PORTB: PORTB_REG = (PORTB_REG&0xF0) | (Copy_u8PinVal&0x0F); break;
	case PORTC: PORTC_REG = (PORTC_REG&0xF0) | (Copy_u8PinVal&0x0F); break;
	case PORTD: PORTD_REG = (PORTD_REG&0xF0) | (Copy_u8PinVal&0x0F); break;
	}
}

//sets value of 4MSB pins of a port
void DIO_vSet4MSBValue(u8 Copy_u8PortName, u8 Copy_u8PinVal){
	switch(Copy_u8PortName)
	{
	case PORTA: PORTA_REG = (PORTA_REG&0x0F) | (Copy_u8PinVal&0xF0); break;
	case PORTB: PORTB_REG = (PORTB_REG&0x0F) | (Copy_u8PinVal&0xF0); break;
	case PORTC: PORTC_REG = (PORTC_REG&0x0F) | (Copy_u8PinVal&0xF0); break;
	case PORTD: PORTD_REG = (PORTD_REG&0x0F) | (Copy_u8PinVal&0xF0); break;
	}
}
