/*
 * LCD.h
 *
 *  Created on: Jul 31, 2021
 *      Author: zoldeyck
 */
#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
/*File Includes*/
#include "DIO.h"
#include "LCD_Lcfg.h"

/*functions return*/
#define OperationSuccess 											0
#define OperationFail 												1
#define OperationRunning											2
#define OperationStarted 											255

/*Macros*/
#define LCD_CLR           		      0x01		   /*Clear Screen*/
#define LCD_HOME          		      0x02        /*return cursor to first position on first line*/
#define LCD_INCREMENTENTRYMODE     	0x06		   /*Increment Entry Mode*/
#define LCD_SHIFTINCREMENTENTRYMODE 0x07		   /*Display Shift + Increment Entry Mode*/
#define LCD_DECREMENTENTRYMODE  	   0x04		   /*Decrement Entry Mode*/
#define LCD_SHIFTDECREMENTENTRYMODE 0x05		   /*Display Shift + Decrement Entry Mode*/
#define LCD_DISPOFF       			   0x08        /*turn display off*/
#define LCD_DISPON_CURSON 			   0x0E        /*display on, cursor on, don't blink character*/
#define LCD_DISPON_CURSOFF 			0x0C        /*display on, cursor off, don't blink character*/
#define LCD_DISPON_CURSBLINK		   0x0F        /*display on , cursor blinking*/
#define LCD_FUNCSET_1     			   0x30        /*8-bit data, 1-line display, 5 x 7 font*/
#define LCD_FUNCSET_2     			   0x34        /*8-bit data, 1-line display, 5 x 10 font*/
#define LCD_FUNCSET_3   			   0x38        /*8-bit data, 2-line display, 5 x 7 font*/
#define LCD_FUNCSET_4     			   0x20        /*4-bit data, 1-line display, 5 x 7 font*/
#define LCD_FUNCSET_5     			   0x24        /*4-bit data, 1-line display, 5 x 10 font*/
#define LCD_FUNCSET_6   			   0x28        /*4-bit data, 2-line display, 5 x 7 font*/
#define LCD_Init_CMD_1				   0x03		   /*first command in initializing sequence*/
#define LCD_CURS_Position0			   0x80		   /*First Position in the LCD*/
#define LCD_CURS_Position10			0x8A		   /*First Position in the LCD*/
#define LCD_CURS_LINE2			      0xC0		   /*First Position in the LCD*/

#define LCD_Channel_0               (0)

/*Function Prototypes*/
Std_ReturnType LCD_Init(void);
Std_ReturnType LCD_SendCommand(uint8_t Cmd);
Std_ReturnType LCD_SendData(uint8_t Data);
Std_ReturnType LCD_SendString(const uint8_t* String);
Std_ReturnType LCD_SendNumber(uint32_t Number);

#endif /* HAL_LCD_LCD_H_ */
