/*
 * File Name: PWM_Lcfg.c
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: C File for PWM Linker Configuration  ...
 */ 

  
#include "PWM_Lcfg.h"

Str_PWMConfig_t gastr_PWMConfig[PWM_CHANNEL_NUMBERS] = {
															{OC0_CLK_1024,OC0_FAST_PWM,DISCONNECT},
															{OC1_CLK_1024,OC1_FAST_PWM_8BITS,DISCONNECT},
															{OC1_CLK_1024,OC1_FAST_PWM_8BITS,DISCONNECT},
															{OC2_CLK_8,OC2_FAST_PWM,NON_INVERTING},
													   };