/*
 * Indicator_Lcfg.c
 *
 * Created: 9/6/2021 2:10:56 PM
 * Author: Mohamed Wagdy
 */ 

/*- INCLUDES -----------------------------------------------*/
#include "Indicator_Lcfg.h"
#include "LED_Lcfg.h"

const uint8_t LED_UsedChannel = LED_CH_0;

const STR_INDICATOR_config_t aSTR_IndicatorConfig[INDICATOR_PATTERN_NUMBERS] = {
   {3000, 500, 500, 500, 1500, 10, 2},
   {1500, 250, 250, 250, 750, 10, 4},
   {1200, 200, 200, 200, 600, 10, 5},
   {300, 50, 50, 50, 150, 10, 20},   
};