/*
 * SSD_Display_Interface.h
 *
 * Created: 9/7/2021 3:10:26 PM
 * Author: Mohamed Wagdy
 */ 


#ifndef __SSD_DISPLAY_INTERFACE_H__
#define __SSD_DISPLAY_INTERFACE_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"
#include "SSD_Display_Lcfg.h"

/*- ERRORS DEFINITIONS--------------------------------------*/

/**
* @brief: Module ID.
*/
#define           E_DISPLAY_ID                        (ERROR_STATE_t)( 0x90 )

/**
* @brief: This return value indicate that a function got an
* invalid value.
*/
#define           E_DISPLAY_INVALID_VAL               (ERROR_STATE_t)( 1 )

/**
* @brief: This return value indicate that a function got an
* uninitialized pointer.
*/
#define           E_DISPLAY_NULL_PTR                  (ERROR_STATE_t)( 2 )

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Display Interface Getters */
/* Return Seven segment Value. */
extern ERROR_STATE_t SSD_Display_GetSevenSegment(uint8_t * Value);

/* Display Interface Setters */
/* Set Seven segment Value. */
extern ERROR_STATE_t SSD_Display_SetSevenSegment(uint8_t Value);

#endif /* __SSD_DISPLAY_INTERFACE_H__ */