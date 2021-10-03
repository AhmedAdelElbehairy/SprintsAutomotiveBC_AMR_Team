/*
 * File Name: SENSING.c
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: C File for Sensing Module....
 */ 
 
#include "SENSING.h"
#include "USONIC.h"

static ERROR_STATE_t SENSING_Init(void);
static ERROR_STATE_t SENSING_Init(void)
{
	uint8_t u8_ErrorState=ERROR_NOK;
	u8_ErrorState = USONIC_Init();

	return u8_ErrorState;
}

void SENSING_MainFunction(void)
{
	uint8_t u8_UsonicState=ERROR_OK;
	double64_t d64_Distance;
	static ERROR_STATE_t u8_InitFlag=NOT_INIT;
	if(NOT_INIT==u8_InitFlag)
	{
		if(ERROR_OK==SENSING_Init())
		{
			u8_InitFlag=INIT;
		}
		else
		{	
					
		}
	}
	if(INIT==u8_InitFlag)
	{
		u8_UsonicState = USONIC_GetDistance(&d64_Distance);
		if(ERROR_OK==u8_UsonicState)
		{
			SENSING_Set(d64_Distance);
		}	
		else
		{
			/*Do Nothing*/			
		}		
	}	
	return;
}