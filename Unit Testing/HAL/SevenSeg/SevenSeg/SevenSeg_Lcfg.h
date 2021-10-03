/*
 * SevenSeg_Lcfg.h
 *
 * Created: 9/5/2021 4:54:10 PM
 * Author: Mohamed Wagdy
 */ 


#ifndef __SEVENSEG_LCFG_H__
#define __SEVENSEG_LCFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"

/*- MACROS -------------------------------------------------*/
#define SEVEN_SEG_NUMBERS           (uint8_t)(2)
#define SEVEN_SEG_INVALID_CH        SEVEN_SEG_NUMBERS

/* ChannelS */
#define SEVEN_SEG_CH_0              (uint8_t)(0)
#define SEVEN_SEG_CH_1              (uint8_t)(1)



/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_SEVEN_SEG_config_t{
   uint8_t u8_EnPort;
   uint8_t u8_EnPin;
   uint8_t u8_DataPort;
   uint8_t u8_DataPinStart;
} STR_SEVEN_SEG_config_t;

#endif /* __SEVENSEG_LCFG_H__ */