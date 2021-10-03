/*
 * LCD_Lcfg.c
 *
 * Created: 8/12/2021 2:58:23 PM
 *  Author: zoldeyck
 */ 
#include "DIO.h"
#include "LCD_Lcfg.h"
const STR_LCD_config_t gastr_LCD_Config[LCD_NUMBER] = {
   {DIO_CH_PA2, DIO_CH_PA3, DIO_CH_PA4, DIO_CH_PC7, DIO_CH_PC6, DIO_CH_PC5, DIO_CH_PC4}
   };
