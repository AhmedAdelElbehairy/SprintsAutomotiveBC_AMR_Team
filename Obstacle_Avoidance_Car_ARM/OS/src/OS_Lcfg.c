/*
 * File Name: OS_Lcfg.c
 * Creation Date: 08/09/2021
 * Author: Ahmed&Rehab
 * Description: C File for OS Linker Configuration....
 */ 

#include "OS_Lcfg.h"

Str_OS_SchedulerCfg_t gstr_OS_SchedulerCfg ={
												{OS_PRIORITY_0_TASKS,OS_PRIORITY_1_TASKS,OS_PRIORITY_2_TASKS},
												OS_TIMER_RESOLUATION_1MS,
												OS_TickTime_Us
											};
