/*
 * USONIC_Lcfg.c
 *
 * Created: 8/12/2021 12:20:19 PM
 *  Author: Ahmed Essam
 */ 
/*- INCLUDES
----------------------------------------------*/
#include "USONIC_Lcfg.h"

const STR_USONIC_config_t gastr_USONIC_Config[USONIC_NUMBER] = {
   {USONIC_TRIG_PORT, USONIC_TRIG_PIN}
};

const uint32_t gu32_USONIC_SystemFreq = 16000000;
