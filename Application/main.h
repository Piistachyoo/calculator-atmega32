/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.h                                  	     */
/* Date          : Mar 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef APPLICATION_MAIN_H_
#define APPLICATION_MAIN_H_

/* Section : Includes */
#include "../HAL/KPD/KPD_interface.h"
#include "../HAL/LCD/lcd_interface.h"

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
KPD_cfg KPD1 = {
		.KPD_Port = PORTD,
		.R1_PIN = PIN4,
		.R2_PIN = PIN5,
		.R3_PIN = PIN6,
		.R4_PIN = PIN7,
		.C1_PIN = PIN3,
		.C2_PIN = PIN2,
		.C3_PIN = PIN1,
		.C4_PIN = PIN0,
};

LCD_4bit_cfg LCD1 = {
		.LCD_PORT = PORTC,
		.LCD_RS_PIN = PIN0,
		.LCD_RW_PIN = PIN1,
		.LCD_EN_PIN = PIN2,
		.LCD_D4_PIN = PIN4,
		.LCD_D5_PIN = PIN5,
		.LCD_D6_PIN = PIN6,
		.LCD_D7_PIN = PIN7,
};

typedef enum{
	State_FirstOp,
	State_SecondOp,
	State_result
}Prog_States;

/* Section : Function Declarations */
void app_init(void);
void app_prog(void);
void save_array(u16 *Copy_u16OP);
void array_reset();
void StartCalculation(u16 *Copy_u8Result);
#endif /* APPLICATION_MAIN_H_ */
