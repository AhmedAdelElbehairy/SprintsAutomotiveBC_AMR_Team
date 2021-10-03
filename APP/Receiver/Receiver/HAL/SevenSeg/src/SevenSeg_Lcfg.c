/*
 * SevenSeg_Lcfg.c
 *
 * Created: 9/7/2021 1:15:50 PM
 * Author: Mohamed Wagdy
 */ 

/*- INCLUDES -----------------------------------------------*/
#include "DIO.h"
#include "SevenSeg_Lcfg.h"

const STR_SEVEN_SEG_config_t aSTR_SevenSegConfig[SEVEN_SEG_NUMBERS] = {
  {PORT_D, PIN2, PORT_B, PIN0},
  {PORT_D, PIN3, PORT_B, PIN0}, 
};