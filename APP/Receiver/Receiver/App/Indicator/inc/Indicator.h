/*
 * Indicator.h
 *
 * Created: 9/6/2021 1:54:15 PM
 * Author: Mohamed Wagdy
 */ 


#ifndef __INDICATOR_H__
#define __INDICATOR_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"

/*- ENUMS --------------------------------------------------*/
/* Enum for Indicator State Machine */
typedef enum
{
   Indicator_LowTime = 0,
   Indicator_RiseTime = 1,
   Indicator_HighTime = 2,
   Indicator_FallTime = 3,
} Enu_IndicatorStateMachine;

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Indicator Main Function. */
extern void Indicator_MainFunction(void);

#endif /* __INDICATOR_H__ */