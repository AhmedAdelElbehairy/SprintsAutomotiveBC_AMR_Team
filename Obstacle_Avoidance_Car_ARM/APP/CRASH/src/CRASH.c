/*
 * CRASH.c
 *
 * Created: 8/16/2021 1:30:57 PM
 *  Author: Mohamed Wagdy
 */ 
/*- INCLUDES
----------------------------------------------*/
#include "CRASH.h"


/*- LOCAL Dataypes
----------------------------------------*/
/*- ENUMS --------------------------------------------------*/
/* Enum for Crash Login State Machine */
typedef enum
{
   CRASH_Ready = 0,
   CRASH_Forward = 1,
   CRASH_Backward = 2,
   CRASH_RotateRight = 3,
   CRASH_Delay = 4,
} Enu_LogicStateMachine;

/*- LOCAL FUNCTIONS PROTOTYPES
----------------------------*/
static ERROR_STATE_t CRASH_Logic(void);

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t gu8_CarDirection;
static uint16_t gu8_CarSpeed;
static double64_t gd64_distance;

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const double64_t gd64_UpperDistanceLimit;
extern const double64_t gd64_LowerDistanceLimit;

/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------*/
/**
* @brief: This function Computes the car speed and direction 
* depending CRASH Logic.
*
* @return function error state.
*/
static ERROR_STATE_t CRASH_Logic(void)
{
   static Enu_LogicStateMachine u8_CurrentState = CRASH_Ready;
   static Enu_LogicStateMachine u8_PreviousState = CRASH_Ready;

   if(gd64_distance > gd64_UpperDistanceLimit)
   {
      u8_CurrentState = CRASH_Forward;
   }
   else if (gd64_distance < gd64_LowerDistanceLimit)
   {
		u8_CurrentState = CRASH_Backward;  
   }
   else
   {
      u8_CurrentState = CRASH_RotateRight;
   }
   
   if(u8_PreviousState != u8_CurrentState)
   {
      switch(u8_CurrentState)
      {
         case CRASH_Forward:
            gu8_CarDirection = STEERING_FORWARD;
            gu8_CarSpeed = 15;
            u8_PreviousState = u8_CurrentState;
            break;
         case CRASH_Backward:
            gu8_CarDirection = STEERING_BACKWARD;		
            gu8_CarSpeed = 15;
            u8_PreviousState = u8_CurrentState;
            break;
         case CRASH_RotateRight:
            gu8_CarDirection = STEERING_RIGHT;		
            gu8_CarSpeed = 100;
            u8_PreviousState = u8_CurrentState;
            break;
         default:
            return ERROR_NOK;
            break;
      }
   }
   return ERROR_OK;
}

/*- APIs IMPLEMENTATION
-----------------------------------*/
/**
* @brief: This is the main function of CRASH module.
*/
extern void CRASH_MainFunction(void)
{
   ERROR_STATE_t CRASH_MainErrorState;
   
   /* Call Distance Getter Function */
   SENSING_Get(&gd64_distance);
   
   /* Call Crash Logic API */
   CRASH_MainErrorState = CRASH_Logic();
   
   /* Call Speed and Direction Setters */
   if(ERROR_OK == CRASH_MainErrorState)
   {
      STEERING_Set(gu8_CarDirection, gu8_CarSpeed);
   }
   return;
}
