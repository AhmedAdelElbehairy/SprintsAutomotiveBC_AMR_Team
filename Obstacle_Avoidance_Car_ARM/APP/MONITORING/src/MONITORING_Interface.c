/*
 * MONITORING_Interface.c
 *
 * Created: 8/16/2021 3:22:17 PM
 *  Author: zoldeyck
 */ 
#include "MONITORING_Interface.h"

static STR_MONITOR_data_t * From_Outside_To_Inside = NULL_PTR;
Std_ReturnType MONITOR_Set(STR_MONITOR_data_t * Data_To_Display)
{
	uint8_t ErrRetVal = 0;
	From_Outside_To_Inside = Data_To_Display;
	return ErrRetVal;
}
Std_ReturnType MONITOR_Get(STR_MONITOR_data_t * Data_From_Display)
{
	uint8_t ErrRetVal = 0;
	if(From_Outside_To_Inside != NULL_PTR)
	{
		Data_From_Display = From_Outside_To_Inside;	
	}
	return ErrRetVal;
}
