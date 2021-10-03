/*
 * Keypad.h
 *
 * Created: 7/25/2021 4:47:04 PM
 *  Author: Mohamed Wagdy
 */ 


#ifndef __KEYPAD_H__
#define __KEYPAD_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"
#include "DIO.h"
#include "Keypad_Lcfg.h"

/*- ERRORS DEFINITIONS--------------------------------------*/

/**
* @brief: Module ID.
*/
#define           E_KEYPAD_ID                         (ERROR_STATE_t)( 0xE0 )

/**
* @brief: This return value indicate that a function got an
* uninitialized pointer.
*/
#define           E_KEYPAD_NULL_PTR                   (ERROR_STATE_t)( 1 )

/**
* @brief: This return value indicate that a function got an
* invalid channel.
*/
#define           E_KEYPAD_INVALID_CH                 (ERROR_STATE_t)( 2 )

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Initialize a keypad */
extern ERROR_STATE_t KP_Init(uint8_t KP_CH);

/* get keypad pressed key */
extern ERROR_STATE_t KP_GetPressedValue(uint8_t KP_CH, uint32_t * const Data);

#endif /* __KEYPAD_H__ */