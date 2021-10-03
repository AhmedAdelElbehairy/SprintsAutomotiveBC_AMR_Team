/*
 * SSD_Display_Lcfg.h
 *
 * Created: 9/7/2021 3:10:14 PM
 * Author: Mohamed Wagdy
 */ 


#ifndef __SSD_DISPLAY_LCFG_H__
#define __SSD_DISPLAY_LCFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"

/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_DISPLAY_SEGMENT_config_t{
   uint8_t u8_SegmentCh0;
   uint8_t u8_SegmentCh1;
} STR_DISPLAY_SEGMENT_config_t;

#endif /* __SSD_DISPLAY_LCFG_H__ */