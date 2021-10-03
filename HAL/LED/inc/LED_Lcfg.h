/*
 * LED_Lcfg.h
 *
 * Created: 9/5/2021 4:54:10 PM
 *  Author: Mohamed Wagdy
 */ 


#ifndef __LED_LCFG_H__
#define __LED_LCFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"

/*- MACROS -------------------------------------------------*/
#define  LED_CH_NUMBERS             (uint8_t)(1)
#define  PWM_ON                     (uint8_t)(1)
#define  PWM_OFF                    (uint8_t)(0)

/* Channel 0 */
#define  LED_CH_0                   (uint8_t)(0)

#define  LED_INVALID_CH             LED_CH_NUMBERS

/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_LED_config_t{
   uint8_t u8_LEDPort;
   uint8_t u8_LEDPin;
   uint8_t u8_PWM;
   uint8_t u8_PWMCh;
} STR_LED_config_t;

#endif /* __LED_LCFG_H__ */