/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYSTICK_Lcfg.c
 *       Module:  SYSTICK
 *
 *  Description:  source file for SYSTICK module linking configurations.
 *
 *********************************************************************************************************************/
/*- INCLUDES
----------------------------------------------*/
#include "SYSTICK_Lcfg.h"

const STR_SYSTICK_config_t STR_SystickConfig = {
  16000, SYSTICK_INT_ENABLE, SYSTICK_SYS_CLK
};
