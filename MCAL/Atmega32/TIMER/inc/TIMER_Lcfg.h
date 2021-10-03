/*
 * TIMER_Lcfg.h
 *
 * Created: 8/12/2021 10:56:27 AM
 *  Author: Mohamed Wagdy
 */ 


#ifndef __TIMER_LCFG_H__
#define __TIMER_LCFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_TYPES.h"

/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_TIMER_config_t{
   uint8_t u8_mode;
   uint8_t u8_interrupt_mode;
   uint8_t u8_prescale;
} STR_TIMER_config_t;

/*- MACROS -------------------------------------------------*/
#define  TIMERS_NUMBER              (uint8_t)( 3 )

/* Timer 0 & 1 Prescales */
#define  CLK_NO_SRC                 (uint8_t)( 0x00 )
#define  CLK_NO_PRESCALE            (uint8_t)( 0x01 )
#define  CLK_8_PRESCALE             (uint8_t)( 0x02 )
#define  CLK_64_PRESCALE            (uint8_t)( 0x03 )
#define  CLK_256_PRESCALE           (uint8_t)( 0x04 )
#define  CLK_1024_PRESCALE          (uint8_t)( 0x05 )
#define  CLK_EXT_FALLING_EDGE       (uint8_t)( 0x06 )
#define  CLK_EXT_RISING_EDGE        (uint8_t)( 0x07 )
#define  CLK_DEFAULT                (uint8_t)( 0x00 )

/* Timer 2 Prescales Only */
#define  T2_CLK_NO_SRC              (uint8_t)( 0x00 )
#define  T2_CLK_NO_PRESCALE         (uint8_t)( 0x01 )
#define  T2_CLK_8_PRESCALE          (uint8_t)( 0x02 )
#define  T2_CLK_32_PRESCALE         (uint8_t)( 0x03 )
#define  T2_CLK_64_PRESCALE         (uint8_t)( 0x04 )
#define  T2_CLK_128_PRESCALE        (uint8_t)( 0x05 )
#define  T2_CLK_256_PRESCALE        (uint8_t)( 0x06 )
#define  T2_CLK_1024_PRESCALE       (uint8_t)( 0x07 )
#define  T2_CLK_DEFAULT             (uint8_t)( 0x00 )

#define  NORMAL_MODE                (uint8_t)( 0x00 )
#define  COMPARE_MATCH_MODE         (uint8_t)( 0x08 )
#define  DEFAULT_MODE               (uint8_t)( 0x00 )

#define  NO_INTERRUPT               (uint8_t)( 0x00 )
#define  TIMER_0_OVERFLOW_INTERRUPT (uint8_t)( 0x01 )
#define  TIMER_0_COMPARE_INTERRUPT  (uint8_t)( 0x02 )
#define  TIMER_1_OVERFLOW_INTERRUPT (uint8_t)( 0x04 )
#define  TIMER_1A_COMPARE_INTERRUPT  (uint8_t)( 0x08 )
#define  TIMER_1B_COMPARE_INTERRUPT  (uint8_t)( 0x10 )
#define  TIMER_2_OVERFLOW_INTERRUPT (uint8_t)( 0x40 )
#define  TIMER_2_COMPARE_INTERRUPT  (uint8_t)( 0x80 )
#define  DEFAULT_INTERRUPT          (uint8_t)( 0X00 )

#define  TIMER_0_OVERFLOW_FLAG      (uint8_t)( 0x01 )
#define  TIMER_0_COMPARE_FLAG       (uint8_t)( 0x02 )
#define  TIMER_1_OVERFLOW_FLAG      (uint8_t)( 0x04 )
#define  TIMER_1A_COMPARE_FLAG      (uint8_t)( 0x10 )
#define  TIMER_1B_COMPARE_FLAG      (uint8_t)( 0x08 )
#define  TIMER_2_OVERFLOW_FLAG      (uint8_t)( 0x40 )
#define  TIMER_2_COMPARE_FLAG       (uint8_t)( 0x80 )

#endif /* __TIMER_LCFG_H__ */