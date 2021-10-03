/*
 * HMI.c
 *
 * Created: 9/5/2021 6:39:36 PM
 * Author: Mohamed Wagdy
 */ 

/*INCLUDES-------------------------------*/
#include "Keypad.h"
#include "HMI.h"
#include "HMI_Interface.h"

/*- LOCAL MACROS
------------------------------------------*/
#define DEVICE_ERASE_VALUE          (uint32_t)(0x1043)
#define PASSWORD_CHANGE_VALUE       (uint32_t)(0x443)
#define MULTI_PRESS_BIT             (uint32_t)(1)

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const uint8_t KP_UsedChannel;

/*APIs IMPLEMENTATION------------------------*/
/**
* @brief: This function is the HMI main function.
*
* @return function error state.
*/
extern void HMI_MainFunction(void)
{
   /* Used Local variables */
   static uint8_t u8_Init = 0;
   uint32_t u32_Key;
   static uint32_t u32_OldKey = 0;
   static uint32_t u32_LastSetKey = 0;
   
   /* Initialization sequence. */
   if (u8_Init == 0)
   {
      KP_Init(KP_UsedChannel);
      u8_Init = 1;
   }
   
   /* Get KEypad pressed keys. */
   KP_GetPressedValue(KP_UsedChannel, &u32_Key);
   
   if(u32_OldKey == u32_Key && u32_LastSetKey != u32_Key)
   {
      u32_LastSetKey = u32_Key;
      /* If multi buttons are pressed. */
      if(MULTI_PRESS_BIT & u32_Key)
      {
         /* Device erase pattern keys are pressed */
         if(DEVICE_ERASE_VALUE == u32_Key)
         {
            /* Set device erase flag. */
            HMI_SetDeviceEraseFlag();
         }
         /* password change pattern keys are pressed */
         else if(PASSWORD_CHANGE_VALUE == u32_Key)
         {
            /* Set password change flag. */
            HMI_SetPasswordChangeFlag();
         }
         else
         {
         }
      }
      /* If a single key is pressed. */
      else if(u32_Key != 0)
      {
         /* Determine the single pressed key. */
         for(uint8_t u8_KeyCounter = 1; u8_KeyCounter<= 12; u8_KeyCounter++)
         {
            if((u32_Key >> u8_KeyCounter) & 1 )
            {
               HMI_SetKeyPressed(u8_KeyCounter);
               break;
            }
         }
      }
      else
      {
      }
   }
   u32_OldKey = u32_Key;
      
}