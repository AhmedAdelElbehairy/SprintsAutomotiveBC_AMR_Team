/*
 * File Name: OS.c
 * Creation Date: 08/09/2021
 * Author: Ahmed&Rehab
 * Description: C File for OS Module....
 */ 

#include "SYSTICK.h"
#include "OS.h"

extern Str_OS_SchedulerCfg_t gstr_OS_SchedulerCfg;
extern volatile uint8_t gu8_OS_ReadyTasksCounter;

TaskHandler_t gpstr_Task=NULL_PTR;
static uint32_t gu32_OS_TicksNumber=ZERO;
		
static void OS_IdealTask(void);
static void OS_Start(void);	

static void OS_IdealTask(void)
{
	while(TRUE)
	{
		if(ZERO!=gu8_OS_ReadyTasksCounter)
		{
			break;
		}
		else
		{
			/*Do Nothing*/
		}
			
	}	
}
	
static void OS_Start(void)
{
	SYSTICK_Start();
}

extern Std_ReturnType OS_Init(void)
{	
	Std_ReturnType u8_ErrorState = E_OK;
	
	SYSTICK_Init();
	
	u8_ErrorState=OS_Get(&gpstr_Task);
	gu32_OS_TicksNumber = gstr_OS_SchedulerCfg.u32_OS_TickTime_Us/gstr_OS_SchedulerCfg.u8_OS_TimerResolution;
	return u8_ErrorState;
}

extern void OS_Run(void)
{
	uint8_t u8_TaskCounter;
	OS_Start();
	while(1)
	{	
		for(u8_TaskCounter=ZERO;u8_TaskCounter<OS_TASKS_NUMBER;u8_TaskCounter++)
		{
			if(NULL_PTR==(gpstr_Task[u8_TaskCounter].ptr_OS_TaskCallback))
			{
				continue ;
			}
			else if(OS_TASKREADY==gpstr_Task[u8_TaskCounter].u8_OS_TaskState)
			{
				gpstr_Task[u8_TaskCounter].u8_OS_TaskState=OS_TASKRUNING;
				(gpstr_Task[u8_TaskCounter].ptr_OS_TaskCallback)();
				gu8_OS_ReadyTasksCounter--;
				
				if(ZERO!=gpstr_Task[u8_TaskCounter].u32_OS_TaskPeriodicity)
				{
					if(OS_TASKRUNING==gpstr_Task[u8_TaskCounter].u8_OS_TaskState)
					{
						gpstr_Task[u8_TaskCounter].u8_OS_TaskState=OS_TASKWAIT;						
					}
					else
					{
						/*Do Nothing*/
					}
				}
				else
				{
					OS_DeleteTask((gpstr_Task+u8_TaskCounter));
				}
				break;
			}
			else
			{
				/*Do Nothing*/
			}
		}
		if(ZERO==gu8_OS_ReadyTasksCounter)
		{
			OS_IdealTask();
		}
		else
		{
			/*Do Nothing*/
		}
	}
}

void Systick_Handler(void)
{
	static volatile uint32_t u32_ISRsCounter=ZERO;
	uint8_t u8_TaskCounter;
	u32_ISRsCounter++;
	if(gu32_OS_TicksNumber==u32_ISRsCounter)
	{
		for(u8_TaskCounter=ZERO;u8_TaskCounter<OS_TASKS_NUMBER;u8_TaskCounter++)
		{
			if(NULL_PTR==gpstr_Task[u8_TaskCounter].ptr_OS_TaskCallback)
			{
				continue ;
			}
			else if((OS_TASKWAIT==gpstr_Task[u8_TaskCounter].u8_OS_TaskState)||(OS_TASKRUNING==gpstr_Task[u8_TaskCounter].u8_OS_TaskState))
			{
				if(ZERO==gpstr_Task[u8_TaskCounter].u8_OS_TaskDelay)
				{
					gpstr_Task[u8_TaskCounter].u8_OS_TaskState=OS_TASKREADY;
					gu8_OS_ReadyTasksCounter++;
					gpstr_Task[u8_TaskCounter].u8_OS_TaskDelay=gpstr_Task[u8_TaskCounter].u32_OS_TaskPeriodicity-1;
				}
				else
				{
					gpstr_Task[u8_TaskCounter].u8_OS_TaskDelay--;
				}				
			}
			else
			{
				/*Do Nothing*/
			}
		}
		u32_ISRsCounter=ZERO;
	}
	else
	{
		/*Do Nothing*/
	}   
}
