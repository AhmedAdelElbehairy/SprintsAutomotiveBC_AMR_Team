/*
 * LED_Lcfg.c
 *
 * Created: 9/6/2021 12:44:47 PM
 * Author: Mohamed Wagdy
 */ 

/*- INCLUDES -----------------------------------------------*/
#include "LED_Lcfg.h"
#include "PWM.h"

const STR_LED_config_t gSTR_LEDConfig[LED_CH_NUMBERS] = {
  {PORT_D, PIN7, PWM_ON, PWM_CHANNEL_OC2}, 
};