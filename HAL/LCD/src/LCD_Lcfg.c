/*
 * LCD_Lcfg.c
 *
 * Created: 8/12/2021 2:58:23 PM
 *  Author: Ahmed Adel
 */ 
#include "DIO.h"
#include "LCD_Lcfg.h"


const STR_LCD_config_t gastr_LCD_Config[LCD_NUMBER] = {
   {PORT_A, PIN1, PIN2, PIN3, PIN7, PIN6, PIN5, PIN4}
   };

const STR_LCD_8_config_t gastr_LCD_8_Config[LCD_NUMBER] = {
	{PORT_A, PORT_B, PIN1, PIN2, PIN3, PIN7, PIN6, PIN5, PIN4, PIN3, PIN2, PIN1,}
};

