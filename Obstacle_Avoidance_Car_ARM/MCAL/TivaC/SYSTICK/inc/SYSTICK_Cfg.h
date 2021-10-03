/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYSTICK_Cfg.h
 *       Module:  SYSTICK
 *
 *  Description:  header file for SYSTICK module preprocessor configurations.
 *
 *********************************************************************************************************************/
#ifndef __SYSTICK_CFG_H__
#define __SYSTICK_CFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"

/*- CONSTANTS ----------------------------------------------*/
#define SYSTICK_CLK_ENABLE      (uint8_t)(0x01)
#define SYSTICK_INT_BIT         (uint32_t)(0x10000)
#define SYSTICK_INVALID_VALUE   (uint32_t)(16777216)

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

#endif  /* __SYSTICK_CFG_H__ */
