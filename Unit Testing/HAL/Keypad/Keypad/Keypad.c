/*
 * Keypad.c
 *
 * Created: 7/25/2021 4:47:13 PM
 *  Author: Mohamed Wagdy
 */ 
/*- INCLUDES
----------------------------------------------*/
#include "Keypad.h"

/*- LOCAL MACROS
------------------------------------------*/
#define PRESSED         (uint8_t)(0)
#define NOT_PRESSED     (uint8_t)(1)

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const STR_KP_config_t aSTR_KPConfig[KEYPAD_NUMBERS];
#ifdef KP_CH_0
extern const uint8_t KP_Ch0Map[KP_CH_0_ROWS][KP_CH_0_COLS];
#endif

/*- APIs IMPLEMENTATION
-----------------------------------*/
/**
* @brief: This function initializes a Keypad channel.
*
* @param [in]  KP_CH   -  Keypad channel number.
*
* @return function error state.
*/
extern ERROR_STATE_t KP_Init(uint8_t KP_CH)
{
   /* Variable to store function error state. */
   ERROR_STATE_t KP_ErrorState;
   
   /* Validate valid Parameters are passed. */
   if(KP_INVALID_CH <= KP_CH)
   {
      /* Set invalid channel error. */
      KP_ErrorState = (E_KEYPAD_ID | E_KEYPAD_INVALID_CH);
   }
   else
   {
      /* Set columns pins to input and set pull up resistors  */
      for(uint8_t u8_Counter = 0; u8_Counter < aSTR_KPConfig[KP_CH].u8_KPCols; u8_Counter++)
      {
         DIO_SetPinDirection(aSTR_KPConfig[KP_CH].u8_KPColPort, (aSTR_KPConfig[KP_CH].u8_KPColPinStart + u8_Counter) , PIN_INPUT);
         DIO_EnablePinPullup(aSTR_KPConfig[KP_CH].u8_KPColPort, (aSTR_KPConfig[KP_CH].u8_KPColPinStart + u8_Counter));
      }
      
      /* Set rows pins to input and set pull up resistors */
      for(uint8_t u8_Counter = 0; u8_Counter < aSTR_KPConfig[KP_CH].u8_KPRows; u8_Counter++)
      {
         DIO_SetPinDirection(aSTR_KPConfig[KP_CH].u8_KPRowPort, (aSTR_KPConfig[KP_CH].u8_KPRowPinStart + u8_Counter) , PIN_INPUT);
         DIO_EnablePinPullup(aSTR_KPConfig[KP_CH].u8_KPRowPort, (aSTR_KPConfig[KP_CH].u8_KPRowPinStart + u8_Counter));
      }
      KP_ErrorState = ERROR_OK;
   }
   
   /* return Error state. */
   return KP_ErrorState;
}

/**
* @brief: This function gets the pressed button value on the keypad.
*
* @param [in]  KP_CH    -  Keypad channel number.
* @param [out] Data     -  Pressed Key Value.
*
* @return function error state.
*/
ERROR_STATE_t KP_GetPressedValue(uint8_t KP_CH, uint32_t * const Data)
{
   /* Variable to store function error state. */
   ERROR_STATE_t KP_ErrorState;
      
   /* Validate valid Parameters are passed. */
   if(NULL_PTR == Data)
   {
      /* Set null pointer error. */
      KP_ErrorState = (E_KEYPAD_ID | E_KEYPAD_NULL_PTR);
   }
   else if(KP_INVALID_CH <= KP_CH)
   {
      /* Set invalid channel error. */
      KP_ErrorState = (E_KEYPAD_ID | E_KEYPAD_INVALID_CH);
   }
   else
   {
      uint32_t u32_NewState = 0x00;
      uint8_t u8_KeyState;
      
      /* loops on every column */
      for(uint8_t u8_ColCounter = 0; u8_ColCounter < aSTR_KPConfig[KP_CH].u8_KPCols; u8_ColCounter++)
      {
         /* set column direction to output and value to low */
         DIO_SetPinDirection(aSTR_KPConfig[KP_CH].u8_KPColPort, (aSTR_KPConfig[KP_CH].u8_KPColPinStart + u8_ColCounter) , PIN_OUTPUT);
         DIO_WritePin(aSTR_KPConfig[KP_CH].u8_KPColPort, (aSTR_KPConfig[KP_CH].u8_KPColPinStart + u8_ColCounter), PIN_LOW);
         
         /* loops on every row */
         for(uint8_t u8_RowCounter = 0; u8_RowCounter < aSTR_KPConfig[KP_CH].u8_KPRows; u8_RowCounter++)
         {
            /* read row value */
            DIO_ReadPin(aSTR_KPConfig[KP_CH].u8_KPRowPort, (aSTR_KPConfig[KP_CH].u8_KPRowPinStart + u8_RowCounter), &u8_KeyState);
            /* check if row is pressed */
            if(u8_KeyState == PRESSED)
            {
               /* Check for multipressed buttons. */
               if(u32_NewState > 0)
               {
                  u32_NewState |= 1;
               }
               switch(KP_CH)
               {
                  #ifdef KP_CH_0
                  case KP_CH_0:
                     u32_NewState |= (1<<KP_Ch0Map[u8_RowCounter][u8_ColCounter]);
                     break;
                  #endif
               }
            }
         }
         
         /* return column direction to input and resistor to pulled up. */
         DIO_SetPinDirection(aSTR_KPConfig[KP_CH].u8_KPColPort, (aSTR_KPConfig[KP_CH].u8_KPColPinStart + u8_ColCounter) , PIN_INPUT);
         DIO_EnablePinPullup(aSTR_KPConfig[KP_CH].u8_KPColPort, (aSTR_KPConfig[KP_CH].u8_KPColPinStart + u8_ColCounter));
      }
      
      /* Return the keys data. */
      *Data = u32_NewState;
      KP_ErrorState = ERROR_OK;

      
   }
   
   /* return Error state. */
   return KP_ErrorState;
}