/*
 * STEERING_Int.h
 *
 * Created: 8/16/2021 4:46:42 PM
 *  Author: Ahmed Essam
 */ 
 
 
#ifndef __STEERING_INT_H__
#define __STEERING_INT_H__
/*INCLUDES-------------------------------*/
#include "STD_TYPES.h"
/*- MACROS -------------------------------------------------*/
/*DIRECTIONS*/
#define  STEERING_FORWARD           (uint8_t)( 0 )
#define  STEERING_BACKWARD          (uint8_t)( 1 )
#define  STEERING_RIGHT             (uint8_t)( 2 )
#define  STEERING_LEFT              (uint8_t)( 3 )
#define  INVALID_STEERING           (uint8_t)( 4 )
/*SPEEDS*/
#define  STEERING_MAX_SPEED         (uint16_t)(100)
#define  STEERING_MIN_SPEED         (uint16_t)(0)

/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_STEERING_State_t
{
	uint16_t u16_steering_Speed;
	uint8_t u8_steering_Dir;	
}STR_STEERING_State_t;



/*APIs DECLARATIONS------------------------*/
/*Set the direction and speed*/
extern ERROR_STATE_t  STEERING_Set(uint8_t  Dir, uint16_t Speed );
/*Get the direction and speed*/
extern ERROR_STATE_t  STEERING_Get(ptr_uint8_t  Dir, ptr_uint16_t Speed);


#endif /*__STEERING_INT_H__*/