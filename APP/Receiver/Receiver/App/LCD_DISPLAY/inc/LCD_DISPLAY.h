/*
 * DISPLAY.h
 *
 * Created: 9/7/2021 6:37:13 PM
 *  Author: Ahmed Adel
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_d
#include "LCD_DISPLAY_Interface.h"
#include "LCD.h"

#define ShiftingLeft 1
#define ShiftingRight 2


void DISPLAY_MainFunction(void);
void DISPLAY_ShiftAndDisplay(uint8_t StringLength, uint8_t* StringPTR);
void DISPLAY_START_SHIFTING(uint8_t stringLength, uint8_t passWordLength);

#endif /* DISPLAY_H_ */