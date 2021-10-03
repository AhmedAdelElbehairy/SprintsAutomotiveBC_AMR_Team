/*
 * File Name: SENSING_Interface.c
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: C File for Interfacing with Sensing Module....
 */ 
 
#include "SENSING_Interface.h"

static double64_t gd64_Distance = 0;

ERROR_STATE_t SENSING_Get(ptr_double64_t Distance)
{
	uint8_t u8_ErrorState = ERROR_OK;
	
	if(NULL_PTR==Distance)
	{
		u8_ErrorState = ERROR_NOK;
	}
	else
	{
		*Distance = gd64_Distance;
		u8_ErrorState = ERROR_OK;
	}
	return u8_ErrorState;
}

ERROR_STATE_t SENSING_Set(double64_t Distance)
{
	uint8_t u8_ErrorState=ERROR_OK;
	
	gd64_Distance = Distance;
	
	return u8_ErrorState;
}