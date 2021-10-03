/*
 * STEERING_Int.c
 *
 * Created: 8/16/2021 4:46:42 PM
 *  Author: Ahmed Essam
 */
/*INCLUDES-------------------------------*/
#include "STEERING_Interface.h"
/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static STR_STEERING_State_t gstr_Steering_State;
/*APIs IMPLEMENTATION------------------------*/
/**
* * @brief: This function sets the parameters of the car.
* @param [in]  Direction -  Direction of Car to move.
* @param [in]  Speed -  Speed of Car to move.
* @return function error state.
*/
extern ERROR_STATE_t  STEERING_Set(uint8_t  Dir, uint16_t Speed){
	ERROR_STATE_t STEERING_ErrorState = ERROR_OK;
	/*CHECK IF INVALID DIRECTION*/
	if(Dir >=INVALID_STEERING){
		STEERING_ErrorState = ERROR_NOK;
	}
	/*CHECK IF INVLAID SPEED*/
	else if(Speed > STEERING_MAX_SPEED){
		STEERING_ErrorState = ERROR_NOK;
	}
	else{
		/*SET THE SPEED*/
		gstr_Steering_State.u16_steering_Speed=Speed;
		/*SET THE DIRECTION*/
		gstr_Steering_State.u8_steering_Dir=Dir;
	}
	return STEERING_ErrorState;
}
/**
* @brief: This function gets the parameters of the car.
* @param [out]  Direction - Direction of Car.
* @param [out]  Speed -  Speed of Car.
* @return function error state.
*/
extern ERROR_STATE_t  STEERING_Get(ptr_uint8_t  Dir, ptr_uint16_t Speed){
	ERROR_STATE_t STEERING_ErrorState = ERROR_OK;
	/*CHECK IF NULL_PTR*/
	if((NULL_PTR==Dir)||(NULL_PTR==Speed))
    {
		STEERING_ErrorState=ERROR_NOK;
	}
	else
    {
		/*GET THE SPEED*/
		*(Speed)=gstr_Steering_State.u16_steering_Speed;
		/*GET THE DIRECTION*/
		*(Dir)=gstr_Steering_State.u8_steering_Dir;
	}
	return STEERING_ErrorState;
}