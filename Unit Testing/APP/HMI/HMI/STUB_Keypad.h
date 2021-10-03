/*
 * STUB_Keypad.h
 *
 * Created: 7/25/2021 4:47:04 PM
 *  Author: Mohamed Wagdy
 */


#ifndef __STUB_KEYPAD_H__
#define __STUB_KEYPAD_H__

 /*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Initialize a keypad */
extern ERROR_STATE_t KP_Init(uint8_t KP_CH);

/* get keypad pressed key */
extern ERROR_STATE_t KP_GetPressedValue(uint8_t KP_CH, uint32_t* const Data);

#endif /* __STUB_KEYPAD_H__ */