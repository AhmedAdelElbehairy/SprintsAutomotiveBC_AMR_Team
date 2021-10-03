/*
 * Global_Interrupts.c
 *
 * Created: 7/24/2021 8:00:15 PM
 *  Author: Mohamed Wagdy
 */ 
/*- INCLUDES
----------------------------------------------*/
#include "GLOBAL_Interrupt.h"
#include "MC_REGISTERS.h"
#include "BIT_MATH.h"

/*- APIs IMPLEMENTATION
-----------------------------------*/

/**
* @brief: This function enables global interrupts.
*/
void GLOBALINTTERUPTS_Enable(void)
{
   SET_BIT(SREG, I);
}

/**
* @brief: This function disables global interrupts.
*/
void GLOBALINTTERUPTS_Disable(void)
{
   CLEAR_BIT(SREG, I);
}