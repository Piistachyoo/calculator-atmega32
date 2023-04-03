/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : KPD_program.c                                  	     */
/* Date          : Mar 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "KPD_interface.h"

static u8 KPD_Buttons [4][4] = {
		{'7', '8', '9', '/'},
		{'4', '5', '6', 'x'},
		{'1', '2', '3', '-'},
		{'C', '0', '=', '+'}
};

static u8 KPD_Rows[4];
static u8 KPD_Cols[4];

void KPD_vInit(const KPD_cfg *KPD){
	DIO_vPinInit(KPD->KPD_Port, KPD->R1_PIN, OUTPUT, HIGH);
	DIO_vPinInit(KPD->KPD_Port, KPD->R2_PIN, OUTPUT, HIGH);
	DIO_vPinInit(KPD->KPD_Port, KPD->R3_PIN, OUTPUT, HIGH);
	DIO_vPinInit(KPD->KPD_Port, KPD->R4_PIN, OUTPUT, HIGH);
	DIO_vPinInit(KPD->KPD_Port, KPD->C1_PIN, INPUT, HIGH);
	DIO_vPinInit(KPD->KPD_Port, KPD->C2_PIN, INPUT, HIGH);
	DIO_vPinInit(KPD->KPD_Port, KPD->C3_PIN, INPUT, HIGH);
	DIO_vPinInit(KPD->KPD_Port, KPD->C4_PIN, INPUT, HIGH);
	KPD_Rows[0] = KPD->R1_PIN;
	KPD_Rows[1] = KPD->R2_PIN;
	KPD_Rows[2] = KPD->R3_PIN;
	KPD_Rows[3] = KPD->R4_PIN;
	KPD_Cols[0] = KPD->C1_PIN;
	KPD_Cols[1] = KPD->C2_PIN;
	KPD_Cols[2] = KPD->C3_PIN;
	KPD_Cols[3] = KPD->C4_PIN;
}

void KPD_vGetButton(const KPD_cfg *KPD, u8 *Copy_u8PressedKey){
	u8 found_flag=0;
	*Copy_u8PressedKey = 'n';
	for(u8 RowIndex=0;RowIndex<ROW_MAX;RowIndex++){
		DIO_vSetPinValue(KPD->KPD_Port, KPD_Rows[RowIndex], LOW);
		for(u8 ColIndex=0;ColIndex<COL_MAX;ColIndex++){
			if(DIO_u8ReadPinValue(KPD->KPD_Port, KPD_Cols[ColIndex]) == BTN_PRESSED){
				while(DIO_u8ReadPinValue(KPD->KPD_Port, KPD_Cols[ColIndex]) == BTN_PRESSED){
					for(int i=0;i<4000;i++);
				}
				*Copy_u8PressedKey = KPD_Buttons[RowIndex][ColIndex];
				found_flag = 1;
				break;
			}
		}
		DIO_vSetPinValue(KPD->KPD_Port, KPD_Rows[RowIndex], HIGH);
		if(found_flag == 1){
			break;
		}
	}
}
