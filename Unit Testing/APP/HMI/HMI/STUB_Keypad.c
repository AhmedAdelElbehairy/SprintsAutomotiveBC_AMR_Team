/*
 * Keypad.c
 *
 * Created: 7/25/2021 4:47:13 PM
 *  Author: Mohamed Wagdy
 */
 /*- INCLUDES
 ----------------------------------------------*/
#include "STUB_Keypad.h"

uint32_t KP_RetVal = 0x00;

/*- APIs IMPLEMENTATION
-----------------------------------*/
ERROR_STATE_t KP_Init(uint8_t KP_CH)
{
   return ERROR_OK;
}

ERROR_STATE_t KP_GetPressedValue(uint8_t KP_CH, uint32_t* const Data)
{
   *Data = KP_RetVal;
   return ERROR_OK;
}