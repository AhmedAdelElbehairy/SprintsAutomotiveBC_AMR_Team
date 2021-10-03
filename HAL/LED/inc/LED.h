/*
 * LED.h
 *
 * Created: 7/7/2021 1:50:00 PM
 *  Author: Mohamed Wagdy
 */ 


#ifndef __LED_H__
#define __LED_H__

/*- INCLUDES -----------------------------------------------*/
#include "LED_Lcfg.h"

/*- ERRORS DEFINITIONS--------------------------------------*/

/**
* @brief: This return value indicate that the function
* ran successfully and it returns no errors.
*/
#define           E_LED_MODULE_ID         (ERROR_STATE_t)( 0xC0 )

/**
* @brief: This return value indicate that a function
* got an invalid channel number.
*/
#define           E_LED_INVALID_CH_NO     (ERROR_STATE_t)( 1 )

/**
* @brief: This return value indicate that the init function
* was called before.
*/
#define           E_LED_INIT_BEFORE       (ERROR_STATE_t)( 2 )

/**
* @brief: This return value indicate that a function
* was called before initialization.
*/
#define           E_LED_NOT_INIT          (ERROR_STATE_t)( 3 )

/**
* @brief: This return value indicate that a function
* was sent a null pointer in parameters.
*/
#define           E_LED_NULL_PTR          (ERROR_STATE_t)( 4 )

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Function that initialize all LEDS */
extern ERROR_STATE_t LED_Init(uint8_t LED_ch);

/* Function that turns off a LED */
extern ERROR_STATE_t LED_Off(uint8_t LED_ch);

/* Function that turns on a LED */
extern ERROR_STATE_t LED_On(uint8_t LED_ch);

/* Function that turns on a LED with a certain duty cycle. */
extern ERROR_STATE_t LED_Dim(uint8_t LED_ch, uint8_t Duty);

/* Function that toggles a LED */
extern ERROR_STATE_t LED_Toggle(uint8_t LED_ch);

/* Function that returns a LED state */
extern ERROR_STATE_t LED_Status(uint8_t LED_ch, uint8_t * state);

#endif /* __LED_H__ */