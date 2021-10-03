/*
 * DISPLAY_Interface.h
 *
 * Created: 9/7/2021 6:36:43 PM
 *  Author: Ahmed Adel
 */ 


#ifndef DISPLAY_INTERFACE_H_
#define DISPLAY_INTERFACE_H_
#include "LIB.h"
#include "LCD.h"
#define SystemLoading 3
#define Welcome 4
#define PassEntering 5
#define CorrectPassword 6
#define WrongPassword 7
#define Waiting 8
#define SevenSegments 9
#define ChangePassword 10

void DISPLAY_GetState(uint8_t* StateVal);
void DISPLAY_GetNumber_of_Asterisk(uint8_t* AsterisksNumVal);
void DISPLAY_SetState(uint8_t StateVal);
void DISPLAY_SetNumber_of_Asterisk(uint8_t AsterisksNumVal);

#endif /* DISPLAY_INTERFACE_H_ */