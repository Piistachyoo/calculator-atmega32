/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : lcd_interface.h                                  	     */
/* Date          : Mar 26, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_



/* Section : Includes */
#include "lcd_config.h"
#include "lcd_private.h"
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include <util/delay.h>
#include "../../Services/BIT_MATH/BIT_MATH.h"
#include "../../Services/STD_TYPES/STD_TYPES.h"

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

typedef struct{
	u8 LCD_DataPort		:2;
	u8 LCD_CtrlPort		:2;
	u8 LCD_RS_PIN		:3;
	u8 LCD_RW_PIN		:3;
	u8 LCD_EN_PIN		:3;
}LCD_8bit_cfg;

typedef struct{
	u8 LCD_PORT			:2;
	u8 LCD_RS_PIN		:3;
	u8 LCD_RW_PIN		:3;
	u8 LCD_EN_PIN		:3;
	u8 LCD_D4_PIN		:3;
	u8 LCD_D5_PIN		:3;
	u8 LCD_D6_PIN		:3;
	u8 LCD_D7_PIN		:3;
}LCD_4bit_cfg;

/* Section : Function Declarations */
void LCD_8bit_vInit(const LCD_8bit_cfg *PTR_LCD);

void LCD_8bit_vSendCmd(const LCD_8bit_cfg *PTR_LCD, u8 Copy_u8Cmd);

void LCD_8bit_vSendChar(const LCD_8bit_cfg *PTR_LCD, u8 Copy_u8Char);

void LCD_8bit_vSendString(const LCD_8bit_cfg *PTR_LCD, u8 *Copy_u8String);

void LCD_8bit_vSendNumber(const LCD_8bit_cfg *PTR_LCD, u16 Copy_u16Number);

void LCD_4bit_vInit(const LCD_4bit_cfg *PTR_LCD);

void LCD_4bit_vSendCmd(const LCD_4bit_cfg *PTR_LCD, u8 Copy_u8Cmd);

void LCD_4bit_vSendChar(const LCD_4bit_cfg *PTR_LCD, u8 Copy_u8Char);

void LCD_4bit_vSendString(const LCD_4bit_cfg *PTR_LCD, u8 *Copy_u8String);

void LCD_4bit_vSendNumber(const LCD_4bit_cfg *PTR_LCD, u16 Copy_u16Number);

#endif /* LCD_LCD_INTERFACE_H_ */
