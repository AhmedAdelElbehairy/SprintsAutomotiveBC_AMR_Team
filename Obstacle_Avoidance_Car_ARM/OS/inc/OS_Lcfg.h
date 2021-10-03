/*
 * File Name: OS_Lcfg.h
 * Creation Date: 08/09/2021
 * Author: Ahmed&Rehab
 * Description: Header File for OS Linker Configuration....
 */ 

#ifndef __OS_LCFG__
#define __OS_LCFG__

#include "STD_TYPES.h"
#include "OS_Cfg.h"

#define OS_TIMER_RESOLUATION_5U			(uint8_t)5
#define OS_TIMER_RESOLUATION_10U		(uint8_t)10
#define OS_TIMER_RESOLUATION_20U		(uint8_t)20

#define OS_TIMER_RESOLUATION_1MS        (uint8_t)1000
#define OS_TickTime_Us        1000

typedef struct Str_OS_SchedulerCfg
{
	uint8_t au8_OS_PrioritiesSizes[OS_PRIORITIES_NUMBER];
	uint32_t u8_OS_TimerResolution;
	uint32_t u32_OS_TickTime_Us;
	
	
}Str_OS_SchedulerCfg_t;
#endif
