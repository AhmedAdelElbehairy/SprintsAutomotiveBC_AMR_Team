/*
 * Indicator_interface.c
 *
 * Created: 9/6/2021 1:55:00 PM
 * Author: Mohamed Wagdy
 */ 

/*INCLUDES-------------------------------*/
#include "Indicator_Interface.h"

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t gu8_IndicatorPattern = INDICATOR_INVALID_PATTERN;

/*APIs IMPLEMENTATION------------------------*/
/**
* @brief: This function gets the Indicator pattern.
*
* @param [out]  Value -  Pointer to where to store the Value.
*
* @return function error state.
*/
extern ERROR_STATE_t Indicator_GetPattern(uint8_t * Value)
{
   /* Variable to store function error state. */
   ERROR_STATE_t Indicator_ErrorState;
   
   /* Validate valid Parameters are passed. */
   if(NULL_PTR == Value)
   {
      /* Set null pointer error. */
      Indicator_ErrorState = (E_INDICATOR_ID | E_INDICATOR_NULL_PTR);
   }
   else
   {
      /* Return the indicator pattern. */
      *Value = gu8_IndicatorPattern;
      Indicator_ErrorState = ERROR_OK;
   }
   
   /* return Error state. */
   return Indicator_ErrorState;
}

/**
* @brief: This function sets the Indicator pattern.
*
* @param [in]  Value -  Indicator pattern value.
*
* @return function error state.
*/
extern ERROR_STATE_t Indicator_SetPattern(uint8_t Value)
{
   /* Variable to store function error state. */
   ERROR_STATE_t Indicator_ErrorState;
   
   /* Validate valid Parameters are passed. */
   if(INDICATOR_INVALID_PATTERN <= Value)
   {
      /* Set invalid value error. */
      Indicator_ErrorState = (E_INDICATOR_ID | E_INDICATOR_INVALID_VAL);
   }
   else
   {
      /* Set the indicator pattern. */
      gu8_IndicatorPattern = Value;
      Indicator_ErrorState = ERROR_OK;
   }
   
   /* return Error state. */
   return Indicator_ErrorState;
}