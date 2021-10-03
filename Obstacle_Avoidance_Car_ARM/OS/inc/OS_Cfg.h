/*
 * File Name: OS_Cfg.h
 * Creation Date: 08/09/2021
 * Author: Ahmed&Rehab
 * Description: Header File for OS Configuration....
 */ 

#ifndef __OS_CFG__
#define __OS_CFG__

#include "STD_TYPES.h"

#define OS_TIMER_0						0
#define OS_TIMER_1						0
#define OS_TIMER_2						1

#define OS_PRIORITIES_NUMBER       	(uint8_t)3
#define OS_PRIORITY_0_TASKS			(uint8_t)1
#define OS_PRIORITY_1_TASKS			(uint8_t)1
#define OS_PRIORITY_2_TASKS			(uint8_t)1

#define OS_TASKS_NUMBER 			(OS_PRIORITY_0_TASKS+OS_PRIORITY_1_TASKS+OS_PRIORITY_2_TASKS)

#endif
