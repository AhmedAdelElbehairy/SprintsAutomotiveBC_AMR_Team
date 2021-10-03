/*
 * Indicator.c
 *
 * Created: 9/6/2021 1:54:49 PM
 * Author: Mohamed Wagdy
 */ 

/*INCLUDES-------------------------------*/
#include "LED.h"
#include "Indicator.h"
#include "Indicator_Interface.h"
#include "FreeRTOS.h"
#include "task.h"

/*- LOCAL MACROS
------------------------------------------*/
#define MAX_DUTY        (uint8_t)(100)
#define MIN_DUTY        (uint8_t)(0)

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const uint8_t LED_UsedChannel;
extern const STR_INDICATOR_config_t aSTR_IndicatorConfig[INDICATOR_PATTERN_NUMBERS];

/*APIs IMPLEMENTATION------------------------*/
/**
* @brief: This function is the indicator main function.
*
* @return function error state.
*/
extern void Indicator_MainFunction(void)
{
   /* OS Variable used for calculating the function waiting period. */
   portTickType xLastWakeTime;
   xLastWakeTime=xTaskGetTickCount();
   
   /* Used Local variables */
   static uint8_t u8_Init = 0;
   uint8_t u8_Pattern;
   static uint8_t u8_OldPattern = INDICATOR_INVALID_PATTERN;
   static Enu_IndicatorStateMachine State = Indicator_LowTime;
   static uint8_t u8_Duty = 0;
   
   /* Initialization sequence. */
   if (u8_Init == 0)
   {
      Indicator_SetPattern(INDICATOR_MALFUNCTION_PATTERN);
      LED_Init(LED_UsedChannel);
      u8_Init = 1;
   }
   
   /* Get the current pattern. */
   Indicator_GetPattern(&u8_Pattern);
   
   /* If a new pattern is set. */
   if( u8_Pattern != u8_OldPattern)
   {
      u8_OldPattern = u8_Pattern;
      /* Reinitialize the state and the duty cycle. */
      State = Indicator_LowTime;
      u8_Duty = MIN_DUTY;
   }
   
   if(INDICATOR_INVALID_PATTERN != u8_Pattern)
   {
      switch(State)
      {
         case Indicator_LowTime:
            /* Turn off led */
            LED_Off(LED_UsedChannel);
            /* Change state to rise time state. */
            State = Indicator_RiseTime;
            /* Put the task in waiting state for the low time period. */
            vTaskDelayUntil(&xLastWakeTime, aSTR_IndicatorConfig[u8_Pattern].u32_LowTime);
            break;
         case Indicator_RiseTime:
            /* Increase the duty with the rate of change. */
            u8_Duty += aSTR_IndicatorConfig[u8_Pattern].u8_RateOfChange;
            /* Dim the led with the current duty cycle. */
            LED_Dim(LED_UsedChannel, u8_Duty);
            /* Change state to high time state. */
            if(u8_Duty == MAX_DUTY)
            {
               State = Indicator_HighTime;
            }
            /* Put the task in waiting state for the step time period. */
            vTaskDelayUntil(&xLastWakeTime, aSTR_IndicatorConfig[u8_Pattern].u8_StepTime);
            break;
         case Indicator_HighTime:
            /* Turn led on. */
            LED_On(LED_UsedChannel);
            /* Change state to fall time state. */
            State = Indicator_FallTime;
            /* Put the task in waiting state for the high time period. */
            vTaskDelayUntil(&xLastWakeTime, aSTR_IndicatorConfig[u8_Pattern].u32_HighTime);
            break;
         case Indicator_FallTime:
            /* decrease the duty with the rate of change. */
            u8_Duty -= aSTR_IndicatorConfig[u8_Pattern].u8_RateOfChange;
            /* Dim the led with the current duty cycle. */
            LED_Dim(LED_UsedChannel, u8_Duty);
            /* Change state to low time state. */
            if(u8_Duty == MIN_DUTY)
            {
               State = Indicator_LowTime;
            }
            /* Put the task in waiting state for the step time period. */
            vTaskDelayUntil(&xLastWakeTime, aSTR_IndicatorConfig[u8_Pattern].u8_StepTime);
            break;
      }
   }
}