/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  IntCtrl
 *
 *  Description:  header file for IntCtrl module preprocessor configurations.
 *
 *********************************************************************************************************************/
#ifndef __INTCTRL_CFG_H__
#define __INTCTRL_CFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"

/*- CONSTANTS ----------------------------------------------*/
#define INT_BASEPRI_START_BIT       (uint8_t)(5)
#define INT_APINT_KEY               (uint32_t)(0x05FA0000)
#define INT_PRIGROUP_START_BIT      (uint8_t)(8)

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

#endif  /* __INTCTRL_CFG_H__ */
