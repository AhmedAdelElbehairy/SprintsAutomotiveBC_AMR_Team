/*
 * TIMER.h
 *
 * Created: 8/9/2021 12:04:11 PM
 *  Author: Mohamed Wagdy
 */ 


#ifndef __TIMER_H__
#define __TIMER_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_TYPES.h"
#include "TIMER_Lcfg.h"

/*- MACROS -------------------------------------------------*/
#define  TIMER_OVERFLOW_FLAG        (uint8_t)( 0 )
#define  TIMER_COMPARE_FLAG         (uint8_t)( 1 )

/* Timer Channels */
#define  TIMER_0                    (uint8_t)( 0 )
#define  TIMER_1                    (uint8_t)( 1 )
#define  TIMER_2                    (uint8_t)( 2 )
#define  INVALID_TIMER_CH           (uint8_t)( 3 )

/*- ERRORS DEFINITIONS--------------------------------------*/

/**
* @brief: This return value indicate that a Timer function
* got an uninitialized pointer.
*/
#define           TIMER_E_NULL_PTR              (ERROR_STATE_t)( -1 )

/**
* @brief: This return value indicate that a Timer function
* got an invalid timer number.
*/
#define           TIMER_E_INVALID_CH_NUM        (ERROR_STATE_t)( -2 )

/**
* @brief: This return value indicate that a Timer function
* didn't finish it's functionality yet.
*/
#define           TIMER_E_PENDING               (ERROR_STATE_t)( -3 )

/**
* @brief: This return value indicate that a Timer Delay function
* got unsupported prescaler value
*/
#define           TIMER_E_UNSUPPORTED_PRESCALE  (ERROR_STATE_t)( -4 )

/**
* @brief: This return value indicate that a Timer Delay is Empty
*/
#define           TIMER_E_DELAY_EMPTY           (ERROR_STATE_t)( -5 )

/*- PRIMITIVE TYPES ----------------------------------------*/
typedef uint8_t TIM_CH_t;
typedef uint32_t TIM_Delay_t;
typedef uint16_t TIM_Preload_t;

/*- ENUMS --------------------------------------------------*/
typedef enum 
{
   DelayReady = 0,
   DelayPending = 1,
} Enu_DelayStateMachine; 

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Function that initializes a timer */
ERROR_STATE_t TIM_Init(TIM_CH_t TIM_channel);

/* Function that starts a timer */
ERROR_STATE_t TIM_Start(TIM_CH_t TIM_channel, TIM_Preload_t PreloadVal);

/* Function that stops a timer. */
ERROR_STATE_t TIM_Stop(TIM_CH_t TIM_channel);

/* Function that check if a timer raised a flag */
ERROR_STATE_t TIM_GetStatus(TIM_CH_t TIM_channel, uint8_t* FlagStatus);

/* Function that uses a timer to delay useconds. */
ERROR_STATE_t TIM_DelayUs(TIM_CH_t TIM_channel, TIM_Delay_t TIM_Delay, Ptr_VoidFuncVoid_t DelayRequester);

/* Function that uses a timer to delay mseconds. */
ERROR_STATE_t TIM_DelayMs(TIM_CH_t TIM_channel, TIM_Delay_t TIM_Delay, Ptr_VoidFuncVoid_t DelayRequester);

/* Function that return delay status. */
ERROR_STATE_t TIM_DelayStatus(TIM_CH_t TIM_channel, Ptr_VoidFuncVoid_t DelayRequester);

#endif /* __TIMER_H__ */
