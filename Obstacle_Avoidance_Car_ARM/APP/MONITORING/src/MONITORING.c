/*
 * MONITORING.c
 *
 * Created: 8/16/2021 3:20:58 PM
 *  Author: zoldeyck
 */ 
#include "LCD.h"
//#include "SENSING_Interface.h"
extern Std_ReturnType SENSING_Get(float64_t * Num);
#include "MONITORING_Interface.h"
#include "MONITORING.h"

static STR_MONITOR_data_t STR_ToDisplay = {0,0,NULL_PTR,NULL_PTR};
static STR_MONITOR_data_t * To_Display_Manager = &STR_ToDisplay;

static float64_t number = 0;
static uint32_t u32_Number = 0;
static uint32_t u32_PrevNumber = 0;
static uint8_t InitializationFlag = 0;
static uint8_t u8_DelayPeriod = 0;

/*uint8_t FuncRetVal = OperationStarted;*/
/*states of function MONITOR_SendDataToDisplay()*/
#define CursorAtPosition (0)
#define SpaceCleared (1)
#define CursorHoming (2)
#define GoToPosition (3)
#define MonitorDelay (4)
/*Initialization Flag Macros*/
#define InitializationFlag_0  (0)
#define InitializationFlag_1  (1)
#define InitializationFlag_2  (2)
#define InitializationFlag_3  (3)
void MONITOR_MainFunction(void)
{
   uint8_t FunRetVal = OperationStarted;
   
	if(InitializationFlag == InitializationFlag_0)
	{
		FunRetVal = LCD_Init();
		if(FunRetVal == OperationSuccess)
		{
			InitializationFlag = InitializationFlag_1;
		}
	}
   else if (1 == InitializationFlag)
   {
      STR_ToDisplay.u8_MONITOR_String = (uint8_t*)"Distance: ";
      STR_ToDisplay.u32_MONITOR_Number = NULL_PTR;
      STR_ToDisplay.u32_MONITOR_Xpos = 0;
      STR_ToDisplay.u32_MONITOR_Ypos = 0;
      FunRetVal = MONITOR_SendDataToDisplay();
      if(FunRetVal == OperationSuccess)
      {
         InitializationFlag = InitializationFlag_2;
      }
   }      
   else if (2 == InitializationFlag)
   {
      STR_ToDisplay.u8_MONITOR_String = (uint8_t*)"AMR_TEAM";
      STR_ToDisplay.u32_MONITOR_Number = NULL_PTR;
      STR_ToDisplay.u32_MONITOR_Xpos = 4;
      STR_ToDisplay.u32_MONITOR_Ypos = 1;
      FunRetVal = MONITOR_SendDataToDisplay();
      if(FunRetVal == OperationSuccess)
      {
         InitializationFlag = InitializationFlag_3;
      }
   }      
	else
	{
		SENSING_Get(&number);
		u32_Number=(uint32_t)number;
      if(u32_PrevNumber != u32_Number)
      {
         if(u32_Number<=150)
         {
            STR_ToDisplay.u8_MONITOR_String = NULL_PTR;
            STR_ToDisplay.u32_MONITOR_Number = &u32_Number;
            STR_ToDisplay.u32_MONITOR_Xpos = 10;
            STR_ToDisplay.u32_MONITOR_Ypos = 0;
            FunRetVal = MONITOR_SendDataToDisplay();
            
         }
         else
         {
            STR_ToDisplay.u8_MONITOR_String = (uint8_t*)"FREE";
            STR_ToDisplay.u32_MONITOR_Number = NULL_PTR;
            STR_ToDisplay.u32_MONITOR_Xpos = 10;
            STR_ToDisplay.u32_MONITOR_Ypos = 0;
            FunRetVal = MONITOR_SendDataToDisplay();
         }   
      }
	}
}
Std_ReturnType MONITOR_SendDataToDisplay()
{
    Std_ReturnType ErrRetVal = OperationStarted;
	static uint8_t State = OperationStarted;
	uint8_t FunRetVal = OperationStarted;
	static uint8_t Position = 0;
   
	if(To_Display_Manager != NULL_PTR)
	{
		if((STR_ToDisplay.u32_MONITOR_Number != NULL_PTR) ^ (STR_ToDisplay.u8_MONITOR_String != NULL_PTR))
		{
			switch(State)
			{
         case OperationStarted:
            /*logic of data sending starts here*/
            /*Determine the Position*/
            if((STR_ToDisplay.u32_MONITOR_Ypos == 0) & (STR_ToDisplay.u32_MONITOR_Xpos < 16))
            {
               Position = LCD_CURS_Position0 | STR_ToDisplay.u32_MONITOR_Xpos;
               ErrRetVal = OperationRunning;
               State = GoToPosition;
            }
            else if((STR_ToDisplay.u32_MONITOR_Ypos == 1) & (STR_ToDisplay.u32_MONITOR_Xpos < 16))
            {
               Position = LCD_CURS_LINE2 | STR_ToDisplay.u32_MONITOR_Xpos;
               ErrRetVal = OperationRunning;
               State = GoToPosition;
            }
            else
            {
               ErrRetVal = OperationFail;
            }
            break;
         case GoToPosition:
            /*go to position*/
				FunRetVal = LCD_SendCommand(Position);
				if(FunRetVal==OperationSuccess)
				{
					State = CursorAtPosition;//CursorAtPosition
				}
				break;
			case CursorAtPosition:
				FunRetVal = LCD_SendString((uint8_t*)"          ");
				if(FunRetVal == OperationSuccess)
				{
					State = SpaceCleared;
				}
				break;
			case SpaceCleared:
				FunRetVal = LCD_SendCommand(Position);
				if(FunRetVal == OperationSuccess)
				{
					State = CursorHoming;
				}
				break;
			case CursorHoming:
				if(To_Display_Manager->u32_MONITOR_Number==NULL_PTR)
				{
					FunRetVal = OperationStarted;
               while (OperationSuccess != FunRetVal)
               {
                  FunRetVal = LCD_SendString((To_Display_Manager->u8_MONITOR_String));
               }                  
					if(FunRetVal == OperationSuccess)
					{
						State = MonitorDelay;
					}
				}
				else
				{
					FunRetVal = LCD_SendNumber(*(To_Display_Manager->u32_MONITOR_Number));
					if(FunRetVal == OperationSuccess)
					{
						State = MonitorDelay;
					}
				}
				break;
         case MonitorDelay:
             if(200 < u8_DelayPeriod)
             {
                 ErrRetVal = OperationSuccess;
                 State = OperationStarted;
             }
             u32_PrevNumber = u32_Number;
             u8_DelayPeriod++;
		}
		}
		else
		{
			ErrRetVal = OperationFail;
		}
	}
	else
	{
		ErrRetVal = OperationFail;
	}
	return ErrRetVal;
}
