/*
 * File Name: OS_Interface.c
 * Creation Date: 08/09/2021
 * Author: Ahmed&Rehab
 * Description: C File for OS Interface File....
 */ 

#include "OS_Interface.h"

extern Str_OS_SchedulerCfg_t gstr_OS_SchedulerCfg;

static Str_OS_TaskCfg_t gastr_OS_TaskCfg[OS_TASKS_NUMBER];
static uint8_t gau8_OS_TaskCounter[OS_PRIORITIES_NUMBER]={ZERO,ZERO,ZERO};
volatile uint8_t gu8_OS_ReadyTasksCounter=ZERO;

extern Std_ReturnType OS_CreateTask(
								uint8_t Priority,
								uint8_t Delay,
								uint32_t Periodicity,
								Ptr_VoidFuncVoid_t TaskCallback,
								TaskHandler_t* TaskHandler
							)
{
	Std_ReturnType u8_ErrorState = E_OK;
	uint8_t u8_TempArrayIndex=ZERO;
	uint8_t u8_Counter;
	uint8_t u8_CurrentPrioritySize=gstr_OS_SchedulerCfg.au8_OS_PrioritiesSizes[Priority];
	if(NULL_PTR==TaskCallback)
	{
		u8_ErrorState=E_NOK;
	}
	else if(Priority>=OS_PRIORITIES_NUMBER)
	{
		u8_ErrorState=OS_UNSUPPORTED_PRIORITY;
	}
	else if(gau8_OS_TaskCounter[Priority]>=u8_CurrentPrioritySize)
	{
		u8_ErrorState=OS_MEMORY_FULL;	
	}
	else
	{
		for(u8_Counter=ZERO;u8_Counter<Priority;u8_Counter++)
		{
			u8_TempArrayIndex+=gstr_OS_SchedulerCfg.au8_OS_PrioritiesSizes[u8_Counter];
		}
		
		for(u8_Counter=u8_TempArrayIndex;(u8_Counter<(u8_TempArrayIndex+u8_CurrentPrioritySize));u8_Counter++)
		{
			if(NULL_PTR==gastr_OS_TaskCfg[u8_Counter].ptr_OS_TaskCallback)
			{
				gastr_OS_TaskCfg[u8_Counter].u8_OS_TaskPriority=Priority;
				gastr_OS_TaskCfg[u8_Counter].u8_OS_TaskDelay=Delay;
				gastr_OS_TaskCfg[u8_Counter].u32_OS_TaskPeriodicity=Periodicity;
				gastr_OS_TaskCfg[u8_Counter].ptr_OS_TaskCallback=TaskCallback;
				gastr_OS_TaskCfg[u8_Counter].u8_OS_TaskID=u8_Counter;
				
				if(NULL_PTR!=TaskHandler)
				{
					*TaskHandler=gastr_OS_TaskCfg+u8_Counter;				
				}
				else
				{
					/*Do Nothing*/
				}
				
				if(ZERO==Delay)
				{
					gastr_OS_TaskCfg[u8_Counter].u8_OS_TaskState=OS_TASKREADY;
					gu8_OS_ReadyTasksCounter++;
				}
				else
				{
					gastr_OS_TaskCfg[u8_Counter].u8_OS_TaskState=OS_TASKWAIT;
				}
				gau8_OS_TaskCounter[Priority]++;
				break;
			}
			else
			{
				/*Do Nothing*/
			}
			
		}			
	}
	return u8_ErrorState;
}

extern Std_ReturnType OS_DeleteTask(TaskHandler_t TaskHandler)
{
	Std_ReturnType u8_ErrorState = E_OK;
	if(NULL_PTR!=TaskHandler)
	{
		TaskHandler->ptr_OS_TaskCallback=NULL_PTR;
		TaskHandler->u8_OS_TaskState=OS_TASKDELETED;
		gau8_OS_TaskCounter[TaskHandler->u8_OS_TaskPriority]--;
	}
	else
	{
		
	}
	return u8_ErrorState;
}

extern Std_ReturnType OS_SuspandTask(TaskHandler_t TaskHandler)
{
	Std_ReturnType u8_ErrorState = E_OK;
	if(NULL_PTR!=TaskHandler)
	{
		TaskHandler->u8_OS_TaskState=OS_TASKSUSPEND;
		if(OS_TASKREADY==TaskHandler->u8_OS_TaskState)
		{
			gu8_OS_ReadyTasksCounter--;	
		}
		else
		{
			/*Do Nothing*/
		}	
	}
	else
	{
		
	}
	return u8_ErrorState;	
}

extern Std_ReturnType OS_UnsuspandTask(TaskHandler_t TaskHandler)
{
	Std_ReturnType u8_ErrorState = E_OK;
	if(NULL_PTR!=TaskHandler)
	{
		TaskHandler->u8_OS_TaskState=OS_TASKREADY;
		TaskHandler->u8_OS_TaskDelay=TaskHandler->u32_OS_TaskPeriodicity-1;
		gu8_OS_ReadyTasksCounter++;
	}
	else
	{
		
	}
	return u8_ErrorState;	
}

extern Std_ReturnType OS_Get(TaskHandler_t* Task)
{
	Std_ReturnType u8_ErrorState = E_OK;
	if(NULL_PTR==Task)
	{
		u8_ErrorState=E_NOK;
	}
	else
	{
		*Task=gastr_OS_TaskCfg;
	}
	return u8_ErrorState;	
}
