/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYSTICK_Lcfg.h
 *       Module:  SYSTICK
 *
 *  Description:  header file for SYSTICK module linking configurations.
 *
 *********************************************************************************************************************/
#ifndef __SYSTICK_LCFG_H__
#define __SYSTICK_LCFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"

/*- CONSTANTS ----------------------------------------------*/
/* Interrupts Macros */
#define SYSTICK_INT_ENABLE      STD_HIGH
#define SYSTICK_INT_DISABLE     STD_LOW
#define SYSTICK_DEFAULT_INT     SYSTICK_INT_DISABLE

/* Clock Source Macros */
#define SYSTICK_SYS_CLK         STD_HIGH
#define SYSTICK_PIOSC_DIV_4     STD_LOW
#define SYSTICK_DEFAULT_CLK     SYSTICK_SYS_CLK

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_SYSTICK_config_t{
   uint32_t u32_Period;
   uint8_t  u8_IntMode;
   uint8_t  u8_ClkMode;
} STR_SYSTICK_config_t;

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

#endif  /* __SYSTICK_LCFG_H__ */
