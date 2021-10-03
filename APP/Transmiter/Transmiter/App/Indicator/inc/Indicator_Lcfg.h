/*
 * Indicator_Lcfg.h
 *
 * Created: 9/6/2021 2:00:26 PM
 * Author: Mohamed Wagdy
 */ 


#ifndef __INDICATOR_LCFG_H__
#define __INDICATOR_LCFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"

/*- MACROS -------------------------------------------------*/
#define  INDICATOR_PATTERN_NUMBERS        (uint8_t)(4)
#define  INDICATOR_MALFUNCTION_PATTERN    (uint8_t)(0)
#define  INDICATOR_SEARCH_PATTERN         (uint8_t)(1)
#define  INDICATOR_VERIFICATION_PATTERN   (uint8_t)(2)
#define  INDICATOR_CONNECTED_PATTERN      (uint8_t)(3)
#define  INDICATOR_INVALID_PATTERN        INDICATOR_PATTERN_NUMBERS

/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_INDICATOR_config_t{
   uint32_t u32_TotalPeriod;
   uint32_t u32_HighTime;
   uint32_t u32_RiseTime;
   uint32_t u32_FallTime;
   uint32_t u32_LowTime;
   uint8_t u8_StepTime;
   uint8_t u8_RateOfChange;
} STR_INDICATOR_config_t;

#endif /* __INDICATOR_LCFG_H__ */