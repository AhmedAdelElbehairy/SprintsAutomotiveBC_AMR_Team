/*
 * Keypad_Lcfg.h
 *
 * Created: 9/5/2021 4:54:10 PM
 *  Author: Mohamed Wagdy
 */ 


#ifndef __KEYPAD_LCFG_H__
#define __KEYPAD_LCFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"

/*- MACROS -------------------------------------------------*/
#define  KEYPAD_NUMBERS             (uint8_t)(1)

/* Channel 0 */
#define KP_CH_0                     (uint8_t)(0)
#define KP_CH_0_ROWS                (uint8_t)(4)
#define KP_CH_0_COLS                (uint8_t)(3)

#define KP_INVALID_CH               KEYPAD_NUMBERS

/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_KP_config_t{
   uint8_t u8_KPRows;
   uint8_t u8_KPRowPort;
   uint8_t u8_KPRowPinStart;
   uint8_t u8_KPCols;
   uint8_t u8_KPColPort;
   uint8_t u8_KPColPinStart;
} STR_KP_config_t;

#endif /* __KEYPAD_LCFG_H__ */