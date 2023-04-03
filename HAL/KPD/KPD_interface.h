/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : KPD_interface.h                                  	     */
/* Date          : Mar 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef KPD_KPD_INTERFACE_H_
#define KPD_KPD_INTERFACE_H_

/* Section : Includes */
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"

/* Section : Macro Declarations */
#define BTN_PRESSED			0
#define BTN_NOT_PRESSED		1

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef struct{
	u8 KPD_Port :2;
	u8 R1_PIN	:3;
	u8 R2_PIN	:3;
	u8 R3_PIN	:3;
	u8 R4_PIN	:3;
	u8 C1_PIN	:3;
	u8 C2_PIN	:3;
	u8 C3_PIN	:3;
	u8 C4_PIN	:3;
}KPD_cfg;

typedef enum{
	R1,
	R2,
	R3,
	R4,
	ROW_MAX
}enu_KPD_Rows;

typedef enum{
	C1,
	C2,
	C3,
	C4,
	COL_MAX
}enu_KPD_Cols;

/* Section : Function Declarations */
void KPD_vInit(const KPD_cfg *KPD);

void KPD_vGetButton(const KPD_cfg *KPD, u8 *Copy_u8PressedKey);

#endif /* KPD_KPD_INTERFACE_H_ */
