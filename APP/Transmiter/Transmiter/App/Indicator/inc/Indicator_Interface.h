/*
 * Indicator_Interface.h
 *
 * Created: 9/6/2021 1:54:39 PM
 * Author: Mohamed Wagdy
 */ 


#ifndef __INDICATOR_INTERFACE_H__
#define __INDICATOR_INTERFACE_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"
#include "Indicator_Lcfg.h"

/*- ERRORS DEFINITIONS--------------------------------------*/

/**
* @brief: Module ID.
*/
#define           E_INDICATOR_ID                      (ERROR_STATE_t)( 0xB0 )

/**
* @brief: This return value indicate that a function got an
* invalid value.
*/
#define           E_INDICATOR_INVALID_VAL             (ERROR_STATE_t)( 1 )

/**
* @brief: This return value indicate that a function got an
* uninitialized pointer.
*/
#define           E_INDICATOR_NULL_PTR                (ERROR_STATE_t)( 2 )

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Indicator Interface Getters */
/* Return Indicator Pattern Value. */
extern ERROR_STATE_t Indicator_GetPattern(uint8_t * Value);

/* Indicator Interface Setters */
/* Set Indicator Pattern Value. */
extern ERROR_STATE_t Indicator_SetPattern(uint8_t Value);

#endif /* __INDICATOR_INTERFACE_H__ */