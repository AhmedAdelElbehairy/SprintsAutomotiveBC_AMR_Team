/*
 * SSD_Display_Interface.c
 *
 * Created: 9/7/2021 3:10:55 PM
 * Author: Mohamed Wagdy
 */ 

/*INCLUDES-------------------------------*/
#include "SSD_Display_Interface.h"

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
extern ERROR_STATE_t SSD_Display_GetSevenSegment(uint8_t * Value)
{
   /* Variable to store function error state. */
   ERROR_STATE_t Display_ErrorState;
   
   /* Validate valid Parameters are passed. */
   if(NULL_PTR == Value)
   {
      /* Set null pointer error. */
      Display_ErrorState = (E_DISPLAY_ID | E_DISPLAY_NULL_PTR);
   }
   else
   {
      /* Return the segment value. */
      *Value = gu8_SevenSegmentValue;
      Display_ErrorState = ERROR_OK;
   }
   
   /* return Error state. */
   return Display_ErrorState;
}

/**
* @brief: This function sets the seven segment value.
*
* @param [in]  Value    -  Indicator pattern value.
*
* @return function error state.
*/
extern ERROR_STATE_t SSD_Display_SetSevenSegment(uint8_t Value)
{
   /* Variable to store function error state. */
   ERROR_STATE_t Display_ErrorState;
   
   /* Validate valid Parameters are passed. */
   if(INVALID_SEVEN_SEGMENT_VALUE <= Value)
   {
      /* Set invalid Value error. */
      Display_ErrorState = (E_DISPLAY_ID | E_DISPLAY_INVALID_VAL);
   }
   else
   {
      /* Set the segment value. */
      gu8_SevenSegmentValue = Value;
      Display_ErrorState = ERROR_OK;
   }
   
   /* return Error state. */
   return Display_ErrorState;
}