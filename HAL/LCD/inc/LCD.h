/*
 * LCD.h
 *
 *  Created on: Jul 31, 2021
 *      Author: Ahmed Adel
 */
#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
/*File Includes*/
#include "LIB.h"
#include "DIO.h"
#include "TIMER.h"
#include "LCD_Lcfg.h"

/*Macros*/
#define LCD_CLR           		    0x01		/*Clear Screen 0x00000001*/
#define LCD_HOME          		    0x02        /*return cursor to first position on first line 0x0000001X*/
/*Entry modes*/
#define LCD_INCREMENTENTRYMODE     	0x06		/*Increment Entry Mode and display shifting is off 0x000001 I/D S*/
#define LCD_SHIFTINCREMENTENTRYMODE 0x07		/*Display Shift + Increment Entry Mode*/
#define LCD_DECREMENTENTRYMODE  	0x04		/*Decrement Entry Mode*/
#define LCD_SHIFTDECREMENTENTRYMODE 0x05		/*Display Shift + Decrement Entry Mode*/
/*Display on/off control*/
#define LCD_DISPOFF       			0x08        /*turn display off , Cursor off, blinks off 0x00001DCB*/
#define LCD_DISPON_CURSON 			0x0E        /*display on, cursor on, don't blink character*/
#define LCD_DISPON_CURSOFF 			0x0C        /*display on, cursor off, don't blink character*/
#define LCD_DISPON_CURSBLINK		0x0F        /*display on , cursor blinking*/
/*cursor or display shift*/
#define LCD_SHIFTCURSLEFT			0x10		/*Shift cursor to left 0x0001 S/C R/L XX*/
#define LCD_SHIFTCURSRIGHT			0x14		/*Shift cursor to right*/
#define LCD_SHIFTDISPLEFT			0x18		/*Shift display left the cursor follows up*/
#define LCD_SHIFTDISPRIGHT			0x1C		/*Shift display right the cursor follows up*/
/*function sets*/
#define LCD_FUNCSET_1     			0x30        /*8-bit data, 1-line display, 5 x 7 font*/
#define LCD_FUNCSET_2     			0x34        /*8-bit data, 1-line display, 5 x 10 font*/
#define LCD_FUNCSET_3   			0x38        /*8-bit data, 2-line display, 5 x 7 font*/
#define LCD_FUNCSET_4     			0x20        /*4-bit data, 1-line display, 5 x 7 font*/
#define LCD_FUNCSET_5     			0x24        /*4-bit data, 1-line display, 5 x 10 font*/
#define LCD_FUNCSET_6   			0x28        /*4-bit data, 2-line display, 5 x 7 font*/
#define LCD_Init_CMD_1				0x03		/*first command in initializing sequence*/
#define LCD_Init_CMD_8_BIT			0x30		/*first command in initializing sequence*/
/*positions*/
#define LCD_CURS_Position0			0x80		/*First Position in the LCD*/
#define LCD_CURS_Position10			0x8A		/*First Position in the LCD*/
#define LCD_CURS_LINE2			    0xC0		/*First Position in the LCD*/

#define LCD_Channel_0               (0)

/*Function Prototypes*/
ERROR_STATE_t LCD_Init(void);
ERROR_STATE_t LCD_SendCommand(uint8_t Cmd);
ERROR_STATE_t LCD_SendData(uint8_t Data);
ERROR_STATE_t LCD_SendString(const uint8_t* String);
ERROR_STATE_t LCD_SendNumber(uint32_t Number);
ERROR_STATE_t LCD_ReadDispLoc(uint8_t Location, uint8_t* Character);

#endif /* HAL_LCD_LCD_H_ */
