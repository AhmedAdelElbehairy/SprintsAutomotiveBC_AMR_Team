/*
 * HMI_Interface.c
 *
 * Created: 9/5/2021 6:39:47 PM
 * Author: Mohamed Wagdy
 */ 

/*INCLUDES-------------------------------*/
#include "HMI_Interface.h"

/*- LOCAL MACROS
------------------------------------------*/
#define DEVICE_ERASE_FLAG           (uint8_t)(1)
#define PASSWORD_CHANGE_FLAG        (uint8_t)(1)
#define INVALID_KEY_PRESSED_VALUE   (uint8_t)(13)

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
uint8_t gu8_DeviceEraseFlag = 0;
uint8_t gu8_PasswordChangeFlag = 0;
uint8_t gu8_KeyPressedValue = 0;

/*APIs IMPLEMENTATION------------------------*/
/**
* @brief: This function gets the device erase flag.
*
* @param [out]  Flag -  Pointer to where to store the flag.
*
* @return function error state.
*/
extern ERROR_STATE_t HMI_GetDeviceEraseFlag(uint8_t * Flag)
{
   /* Variable to store function error state. */
   ERROR_STATE_t HMI_ErrorState;
   
   /* Validate valid Parameters are passed. */
   if(NULL_PTR == Flag)
   {
      /* Set null pointer error. */
      HMI_ErrorState = (E_HMI_ID | E_HMI_NULL_PTR);   
   }
   else
   {
      /* Return the device erase flag */
      *Flag = gu8_DeviceEraseFlag;
      /* Clear the flag. */
      gu8_DeviceEraseFlag = 0;
      HMI_ErrorState = ERROR_OK;
   }
   
   /* return Error state. */
   return HMI_ErrorState;
}

/**
* @brief: This function gets the password erase flag.
*
* @param [out]  Flag -  Pointer to where to store the flag.
*
* @return function error state.
*/
extern ERROR_STATE_t HMI_GetPasswordChangeFlag(uint8_t * Flag)
{
   /* Variable to store function error state. */
   ERROR_STATE_t HMI_ErrorState;
   
   /* Validate valid Parameters are passed. */
   if(NULL_PTR == Flag)
   {
      /* Set null pointer error. */
      HMI_ErrorState = (E_HMI_ID | E_HMI_NULL_PTR);
   }
   else
   {
      /* Return the password change flag. */
      *Flag = gu8_PasswordChangeFlag;
      /* Clear the flag. */
      gu8_PasswordChangeFlag = 0;
      HMI_ErrorState = ERROR_OK;
   }
   
   /* return Error state. */
   return HMI_ErrorState;
}

/**
* @brief: This function gets the pressed key value.
*
* @param [out]  Value -  Pointer to where to store the pressed key value.
*
* @return function error state.
*/
extern ERROR_STATE_t HMI_GetKeyPressed(uint8_t * Value)
{
   /* Variable to store function error state. */
   ERROR_STATE_t HMI_ErrorState;
   
   /* Validate valid Parameters are passed. */
   if(NULL_PTR == Value)
   {
      /* Set null pointer error. */
      HMI_ErrorState = (E_HMI_ID | E_HMI_NULL_PTR);
   }
   else
   {
      /* Return the key pressed value. */
      *Value = gu8_KeyPressedValue;
      /* Clear the key pressed. */
      gu8_KeyPressedValue = 0;
      HMI_ErrorState = ERROR_OK;
   }
   
   /* return Error state. */
   return HMI_ErrorState;
}

/**
* @brief: This function sets the device erase flag.
*
* @return function error state.
*/
extern ERROR_STATE_t HMI_SetDeviceEraseFlag(void)
{
   /* Set the device erase flag. */
   gu8_DeviceEraseFlag = DEVICE_ERASE_FLAG;
   /* return Error state. */
   return ERROR_OK;
}

/**
* @brief: This function set the password change flag.
*
* @return function error state.
*/
extern ERROR_STATE_t HMI_SetPasswordChangeFlag(void)
{
   /* Set the password change flag. */
   gu8_PasswordChangeFlag = PASSWORD_CHANGE_FLAG;
   /* return Error state. */
   return ERROR_OK;
}

/**
* @brief: This function sets the pressed key value.
*
* @param [in]  Value -  Pressed key value.
*
* @return function error state.
*/
extern ERROR_STATE_t HMI_SetKeyPressed(uint8_t Value)
{
   /* Variable to store function error state. */
   ERROR_STATE_t HMI_ErrorState;
   
   /* Validate valid Parameters are passed. */
   if(INVALID_KEY_PRESSED_VALUE <= Value)
   {
      /* Set invalid Value error. */
      HMI_ErrorState = (E_HMI_ID | E_HMI_INVALID_VAL);
   }
   else
   {
      /* Set the pressed key value. */
      gu8_KeyPressedValue = Value;
      HMI_ErrorState = ERROR_OK;
   }
   
   /* return Error state. */
   return HMI_ErrorState;
}