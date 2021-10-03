/*
 * File Name: SENSING_Interface.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for Interfacing with Sensing Module....
 */ 

#ifndef __SENSING_INTERFACE__
#define __SENSING_INTERFACE__

//FILES INCLUDING
#include "STD_TYPES.h"

//FUNCTIONS PROTOTYPES

ERROR_STATE_t SENSING_Get(ptr_double64_t Distance);
ERROR_STATE_t SENSING_Set(double64_t Distance);

#endif
