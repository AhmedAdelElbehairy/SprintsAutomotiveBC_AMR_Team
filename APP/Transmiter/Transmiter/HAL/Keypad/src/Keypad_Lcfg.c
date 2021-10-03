/*
 * Keypad_Lcfg.c
 *
 * Created: 9/5/2021 4:59:16 PM
 *  Author: Mohamed Wagdy
 */ 

/*- INCLUDES -----------------------------------------------*/
#include "DIO.h"
#include "Keypad_Lcfg.h"

const STR_KP_config_t aSTR_KPConfig[KEYPAD_NUMBERS] = {
   {KP_CH_0_ROWS, PORT_C, PIN1, KP_CH_0_COLS, PORT_C, PIN5},
};

const uint8_t KP_Ch0Map[KP_CH_0_ROWS][KP_CH_0_COLS] = {
   {1, 2, 3},
   {4, 5, 6},
   {7, 8, 9},
   {10, 11, 12},
};