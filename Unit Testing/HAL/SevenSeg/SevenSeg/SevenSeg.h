/*
 * SevenSeg.h
 *
 * Created: 7/25/2021 4:47:04 PM
 * Author: Mohamed Wagdy
 */ 


#ifndef __SEVENSEG_H__
#define __SEVENSEG_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"
#include "STUB_DIO.h"
#include "SevenSeg_Lcfg.h"

/*- ERRORS DEFINITIONS--------------------------------------*/

/**
* @brief: Module ID.
*/
#define           E_SEVEN_SEG_ID                      (ERROR_STATE_t)( 0xA0 )

/**
* @brief: This return value indicate that a function got an
* invalid channel.
*/
#define           E_SEVEN_SEG_INVALID_CH              (ERROR_STATE_t)( 1 )

/**
* @brief: This return value indicate that a channel was called
* in an API before initializing the channel.
*/
#define           E_SEVEN_SEG_NOT_INIT                (ERROR_STATE_t)( 2 )

/**
* @brief: This return value indicate that a channel was initialized
* before.
*/
#define           E_SEVEN_SEG_INIT_BEFORE             (ERROR_STATE_t)( 3 )

/**
* @brief: This return value indicate that an invalid number was
* sent to be displayed on a channel.
*/
#define           E_SEVEN_SEG_INVALID_NUMBER          (ERROR_STATE_t)( 3 )

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Initialize a Seven segment channel */
extern ERROR_STATE_t SevenSeg_Init(const uint8_t Channel);

/* Display a number on seven segment */
extern ERROR_STATE_t SevenSeg_Display(const uint8_t Channel, const uint8_t Number);

#endif /* __SEVENSEG_H__ */