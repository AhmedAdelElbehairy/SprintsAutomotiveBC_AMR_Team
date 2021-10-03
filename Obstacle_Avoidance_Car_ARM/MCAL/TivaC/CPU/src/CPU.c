/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  CPU.c
 *       Module:  CPU
 *
 *  Description:  source file for CPU module.
 *
 *********************************************************************************************************************/
/*- INCLUDES
----------------------------------------------*/
#include "CPU.h"

/*- LOCAL MACROS
------------------------------------------*/
#define SVC_SWITCH_TO_PRIVILEGED            (uint32_t)(0)

/*- LOCAL Dataypes
----------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
----------------------------*/

/*- GLOBAL STATIC VARIABLES
-------------------------------*/

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/

/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------*/
/************************************************************************************
* Service Name: CPU_PrivilegedMode
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Set Processor Privilege Level to privileged level.
************************************************************************************/
void CPU_PrivilegedMode(void)
{
   /* Trigger SVC to switch to privileged mode. */
   Trigger_SVC_SwitchToPrivileged();
}

/************************************************************************************
* Service Name: CPU_UnPrivilegedMode
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Set Processor Privilege Level to privileged level.
************************************************************************************/
void CPU_UnPrivilegedMode(void)
{
   /* Switch to unprivileged mode. */
   Switch_to_Unprivileged();
}

/************************************************************************************
* Service Name: CPU_Handler
* Service ID[hex]: 0x02
* Sync/Async: Asynchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: SVC ISR.
************************************************************************************/
void CPU_Handler(void)
{
   uint32_t u32_SVCNumber;
   /* Get SVC Number from stack. */
   Get_SVC_Number();
   switch(u32_SVCNumber)
   {
      case SVC_SWITCH_TO_PRIVILEGED:
         Switch_to_Privileged();
         break;
      default:
         break;
   }
}
