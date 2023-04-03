/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : STD_TYPES.h                                    	     */
/* Date          : Feb 5, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef SERVICES_STD_TYPES_STD_TYPES_H_
#define SERVICES_STD_TYPES_STD_TYPES_H_

/*********************************************************/
/* 				  Data types declaration 				 */
/*********************************************************/

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef float f32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef double f64;

/*********************************************************/
/* 				  MACRO FUNCTIONS DECLARATION			 */
/*********************************************************/

#define HWREG8(_REG)		(*((volatile u8*) _REG))
#define HWREG16(_REG)		(*((volatile u16*) _REG))
#define HWREG32(_REG)		(*((volatile u32*) _REG))

typedef enum{
	E_NOT_OK,
	E_OK
}Std_ReturnType;

#endif /* SERVICES_STD_TYPES_STD_TYPES_H_ */
