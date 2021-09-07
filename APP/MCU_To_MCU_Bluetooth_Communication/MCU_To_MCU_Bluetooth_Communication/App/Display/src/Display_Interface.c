/*
 * Display_Interface.c
 *
 * Created: 9/7/2021 3:10:55 PM
 * Author: Mohamed Wagdy
 */ 

/*INCLUDES-------------------------------*/
#include "Display_Interface.h"

/*- LOCAL MACROS
------------------------------------------*/
#define INVALID_SEVEN_SEGMENT_VALUE       (uint8_t)(100)

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t gu8_SevenSegmentValue = 0;

/*APIs IMPLEMENTATION------------------------*/
/**
* @brief: This function gets the Seven segment value.
*
* @param [out] Value    -  Pointer to where to store the Value.
*
* @return function error state.
*/
extern ERROR_STATE_t Display_GetSevenSegment(uint8_t * Value)
{
   ERROR_STATE_t Display_ErrorState;
   
   if(NULL_PTR == Value)
   {
      Display_ErrorState = (E_DISPLAY_ID | E_DISPLAY_NULL_PTR);
   }
   else
   {
      *Value = gu8_SevenSegmentValue;
      Display_ErrorState = ERROR_OK;
   }
   
   return Display_ErrorState;
}

/**
* @brief: This function sets the seven segment value.
*
* @param [in]  Value    -  Indicator pattern value.
*
* @return function error state.
*/
extern ERROR_STATE_t Display_SetSevenSegment(uint8_t Value)
{
   ERROR_STATE_t Display_ErrorState;
   
   if(INVALID_SEVEN_SEGMENT_VALUE <= Value)
   {
      Display_ErrorState = (E_DISPLAY_ID | E_DISPLAY_INVALID_VAL);
   }
   else
   {
      gu8_SevenSegmentValue = Value;
      Display_ErrorState = ERROR_OK;
   }
   
   return Display_ErrorState;
}