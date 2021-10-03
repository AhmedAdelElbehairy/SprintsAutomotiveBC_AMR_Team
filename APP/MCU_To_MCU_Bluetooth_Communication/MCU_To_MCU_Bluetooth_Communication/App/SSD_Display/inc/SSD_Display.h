/*
 * SSD_Display.h
 *
 * Created: 9/7/2021 3:10:00 PM
 * Author: Mohamed Wagdy
 */ 


#ifndef __SSD_DISPLAY_H__
#define __SSD_DISPLAY_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"

/*- ENUMS --------------------------------------------------*/
/* Enum for Display State Machine */
typedef enum
{
   SSD_Display_FirstNumber = 0,
   SSD_Display_SecondNumber = 1,
} Enu_SSDDisplayStateMachine;

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Display Main Function. */
extern void SSD_Display_MainFunction(void);

#endif /* __SSD_DISPLAY_H__ */