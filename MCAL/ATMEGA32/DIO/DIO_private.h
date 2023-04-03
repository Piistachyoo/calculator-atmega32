/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : DIO_private.h                                   	     */
/* Date          : Feb 5, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef MCAL_ATMEGA32_DIO_DIO_PRIVATE_H_
#define MCAL_ATMEGA32_DIO_DIO_PRIVATE_H_

//Creating an enum to substitute every PIN with it's number
typedef enum{
	PIN0 = 0, //making sure first element equals 0
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_PINS_t;

//Creating an enum to substitute every PORT with it's number
typedef enum{
	PORTA = 0, //making sure first element equals 0
	PORTB,
	PORTC,
	PORTD
}DIO_PORTS_t;

//Setting addresses of every port (PIN, PORT, DDR)

//PORT A
#define PORTA_REG *((volatile u8*) 0x3B)
#define DDRA_REG *((volatile u8*) 0x3A)
#define PINA_REG *((volatile u8*) 0x39)

//PORT B
#define PORTB_REG *((volatile u8*) 0x38)
#define DDRB_REG *((volatile u8*) 0x37)
#define PINB_REG *((volatile u8*) 0x36)

//PORT C
#define PORTC_REG *((volatile u8*) 0x35)
#define DDRC_REG *((volatile u8*) 0x34)
#define PINC_REG *((volatile u8*) 0x33)

//PORT D
#define PORTD_REG *((volatile u8*) 0x32)
#define DDRD_REG *((volatile u8*) 0x31)
#define PIND_REG *((volatile u8*) 0x30)

//Macros for HIGH/LOW/INPUT/OUTPUT
#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0

#endif /* MCAL_ATMEGA32_DIO_DIO_PRIVATE_H_ */
