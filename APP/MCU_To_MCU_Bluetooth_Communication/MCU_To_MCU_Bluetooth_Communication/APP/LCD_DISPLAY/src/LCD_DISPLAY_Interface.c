/*
 * DISPLAY_Interface.c
 *
 * Created: 9/7/2021 6:38:01 PM
 *  Author: Ahmed Adel
 */ 
#include "LCD_DISPLAY_Interface.h"
uint8_t static State = OperationStarted;
uint8_t static Number_of_Asteriks = 0;

void DISPLAY_GetState(uint8_t* StateVal)
{
	*StateVal = State;
}
void DISPLAY_GetNumber_of_Asterisk(uint8_t* AsterisksNumVal)
{
	*AsterisksNumVal = Number_of_Asteriks;
}
void DISPLAY_SetState(uint8_t StateVal)
{
	State = StateVal;
}
void DISPLAY_SetNumber_of_Asterisk(uint8_t AsterisksNumVal)
{
	Number_of_Asteriks = AsterisksNumVal;
}