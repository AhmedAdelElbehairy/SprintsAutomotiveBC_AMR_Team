/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Lcfg.h
 *       Module:  IntCtrl
 *
 *  Description:  header file for IntCtrl module linking configurations.
 *
 *********************************************************************************************************************/
#ifndef __INTCTRL_LCFG_H__
#define __INTCTRL_LCFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"

/*- CONSTANTS ----------------------------------------------*/
#define INT_NUMBERS                     (uint8_t)(138)

#define INT_GROUPS_8_SUBGROUPS_1        (uint8_t)(0)
#define INT_GROUPS_4_SUBGROUPS_2        (uint8_t)(5)
#define INT_GROUPS_2_SUBGROUPS_4        (uint8_t)(6)
#define INT_GROUPS_1_SUBGROUPS_8        (uint8_t)(7)

#define INT_BASEPRI_0                   (uint8_t)(0x00)
#define INT_BASEPRI_1                   (uint8_t)(0x20)
#define INT_BASEPRI_2                   (uint8_t)(0x02)
#define INT_BASEPRI_3                   (uint8_t)(0x03)
#define INT_BASEPRI_4                   (uint8_t)(0x04)
#define INT_BASEPRI_5                   (uint8_t)(0x05)
#define INT_BASEPRI_6                   (uint8_t)(0x06)
#define INT_BASEPRI_7                   (uint8_t)(0x07)

#define INT_INVALID_PRI                 (uint8_t)(0x08)

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_INT_config_t{
   uint8_t  u8_GroupAndSubgroupPRI;
   uint8_t  u8_Enable;
} STR_INT_config_t;

typedef struct STR_IntCtrl_config_t{
   uint8_t          u8_GroupAndSubgroup;
   uint8_t          u8_BasePriority;
   STR_INT_config_t aSTR_Ints[INT_NUMBERS];
} STR_IntCtrl_config_t;

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

#endif  /* __INTCTRL_LCFG_H__ */
