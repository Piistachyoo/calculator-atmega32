/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : lcd_config.h                                  	     */
/* Date          : Mar 26, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

/* Function Set */
#define TWO_LINE_8BIT_BIG_FONT			0x3C
#define TWO_LINE_4BIT_BIG_FONT	 		0x2C

/* Display ON/OFF Control */
#define CURSOR_ON_BLINK					0x0F
#define CURSOR_ON_NO_BLINK				0x0E
#define CURSOR_OFF						0x0C

/* Clear Display */
#define CLEAR_DISPLAY					0x01

/* Entry mode set */
#define START_FROM_LEFT					0x06

#endif /* LCD_LCD_CONFIG_H_ */
