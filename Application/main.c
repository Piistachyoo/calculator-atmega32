/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c                                  	     		 */
/* Date          : Mar 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "main.h"

static Prog_States Current_State;
static u16 local_firstOP;
static u16 local_secondop;
static u8  local_operand;
static u16 result;
static u16 temp_array[5];
static u8  temp_array_size=0;
static u8 local_PressedKey;

void main(){
	app_init();
	while(1){
		app_prog();
	}
}

void app_init(void){
	KPD_vInit(&KPD1);
	LCD_4bit_vInit(&LCD1);
	Current_State = State_FirstOp;
	LCD_4bit_vSendCmd(&LCD1, CLEAR_DISPLAY);
}

void app_prog(void){
	KPD_vGetButton(&KPD1, &local_PressedKey);
	if(local_PressedKey != 'n'){
		switch(Current_State){
		case State_FirstOp:
			if((local_PressedKey >= '0') && (local_PressedKey <= '9')){
				LCD_4bit_vSendChar(&LCD1, local_PressedKey);
				temp_array[temp_array_size] = local_PressedKey-48;
				temp_array_size++;
			}
			else if((local_PressedKey == '+') | (local_PressedKey == '-')
				  | (local_PressedKey == '/') | (local_PressedKey == 'x')){
				LCD_4bit_vSendChar(&LCD1, local_PressedKey);
				save_array(&local_firstOP);
				local_operand = local_PressedKey;
				Current_State = State_SecondOp;
			}
			else if(local_PressedKey == 'C'){
				LCD_4bit_vSendCmd(&LCD1, CLEAR_DISPLAY);
				array_reset();
				local_firstOP = 0;
				local_secondop = 0;
				local_operand = 0;
			}
			else if(local_PressedKey == '='){
				save_array(&local_firstOP);
				LCD_4bit_vSendNumber(&LCD1, local_firstOP);
				Current_State = State_result;
			}
			else{ /* Do Nothing */ }
			break;
		case State_SecondOp:
			if((local_PressedKey >= '0') && (local_PressedKey <= '9')){
				LCD_4bit_vSendChar(&LCD1, local_PressedKey);
				temp_array[temp_array_size] = local_PressedKey-48;
				temp_array_size++;
			}
			else if((local_PressedKey == '+') | (local_PressedKey == '-')
				  | (local_PressedKey == '/') | (local_PressedKey == 'x')){
				save_array(&local_secondop);
				StartCalculation(&local_firstOP);
				LCD_4bit_vSendCmd(&LCD1, CLEAR_DISPLAY);
				LCD_4bit_vSendNumber(&LCD1, local_firstOP);
				LCD_4bit_vSendChar(&LCD1, local_PressedKey);
				local_secondop = 0;
				local_operand = local_PressedKey;
				Current_State = State_SecondOp;
			}
			else if(local_PressedKey == 'C'){
				LCD_4bit_vSendCmd(&LCD1, CLEAR_DISPLAY);
				array_reset();
				local_firstOP = 0;
				local_secondop = 0;
				local_operand = 0;
				Current_State = State_FirstOp;
			}
			else if(local_PressedKey == '='){
				save_array(&local_secondop);
				StartCalculation(&result);
				LCD_4bit_vSendCmd(&LCD1, CLEAR_DISPLAY);
				LCD_4bit_vSendNumber(&LCD1, result);
				Current_State = State_result;
			}
			else{ /* Do Nothing */ }
			break;
		case State_result:
			if((local_PressedKey >= '0') && (local_PressedKey <= '9')){
				Current_State = State_FirstOp;
				LCD_4bit_vSendCmd(&LCD1, CLEAR_DISPLAY);
				LCD_4bit_vSendChar(&LCD1, local_PressedKey);
				temp_array[temp_array_size] = local_PressedKey-48;
				temp_array_size++;
			}
			else if((local_PressedKey == '+') | (local_PressedKey == '-')
				  | (local_PressedKey == '/') | (local_PressedKey == 'x')){
				Current_State = State_SecondOp;
				LCD_4bit_vSendChar(&LCD1, local_PressedKey);
				local_operand = local_PressedKey;
				local_firstOP = result;
			}
			else if(local_PressedKey == 'C'){
				LCD_4bit_vSendCmd(&LCD1, CLEAR_DISPLAY);
				array_reset();
				local_firstOP = 0;
				local_secondop = 0;
				local_operand = 0;
				Current_State = State_FirstOp;
			}
			break;
		default: /* Do Nothing */ break;
		}
	}
}

void array_reset(){
	temp_array[0] = 0;
	temp_array[1] = 0;
	temp_array[2] = 0;
	temp_array[3] = 0;
	temp_array[4] = 0;
	temp_array_size = 0;
}

void save_array(u16 *Copy_u16OP){
	*Copy_u16OP = 0;
	*Copy_u16OP += temp_array[0];
	for(int i=1;i<temp_array_size;i++){
		*Copy_u16OP *= 10;
		*Copy_u16OP += temp_array[i];
	}
	array_reset();
}

void StartCalculation(u16 *Copy_u8Result){
	if(local_operand == '+'){
		*Copy_u8Result = local_firstOP + local_secondop;
	}
	else if(local_operand == '-'){
		if(local_firstOP>local_secondop){ *Copy_u8Result = local_firstOP - local_secondop; }
		else { *Copy_u8Result = local_secondop - local_firstOP; }
	}
	else if(local_operand == 'x'){
		*Copy_u8Result = local_firstOP * local_secondop;
	}
	else if(local_operand == '/'){
		*Copy_u8Result = local_firstOP - local_secondop;
	}
	else{ /* Do Nothing */ }
}

