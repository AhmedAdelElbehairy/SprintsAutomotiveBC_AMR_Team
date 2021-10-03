/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_HwTags.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers Tags definition    
 *  
 *********************************************************************************************************************/
#ifndef __MCU_HWTAGS_H__
#define __MCU_HWTAGS_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"

/*- CONSTANTS ----------------------------------------------*/

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/
/*- Systick Timer Tags--------------------------------------*/
typedef struct 
{
    uint32_t ENABLE     :1;
    uint32_t INTEN      :1;
    uint32_t CLK_SRC    :1;
    uint32_t            :13;
    uint32_t COUNT      :1;
    uint32_t            :15;
}STCTRL_BF;

typedef union 
{
    uint32_t R;
    STCTRL_BF B;
}STCTRL_Tag;

typedef struct 
{
    uint32_t RELOAD     :24;
    uint32_t            :8;
}STRELOAD_BF;

typedef union 
{
    uint32_t R;
    STRELOAD_BF B;
}STRELOAD_Tag;

typedef struct 
{
    uint32_t CURRENT    :24;
    uint32_t            :8;
}STCURRENT_BF;

typedef union 
{
    uint32_t R;
    STCURRENT_BF B;
}STCURRENT_Tag;

typedef struct 
{
    uint32_t VECACT     :8;
    uint32_t            :3;
    uint32_t RETBASE    :1;
    uint32_t VECPEND    :8;
    uint32_t            :2;
    uint32_t ISRPEND    :1;
    uint32_t ISRPRE     :1;
    uint32_t            :1;
    uint32_t PENDSTCLR  :1;
    uint32_t PENDSTSET  :1;
    uint32_t UNPENDSV   :1;
    uint32_t PENDSV     :1;
    uint32_t            :2;
    uint32_t NMISET     :1; 
}INTCTRL_BF;

typedef union 
{
    uint32_t R;
    INTCTRL_BF B;
}INTCTRL_Tag;

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/
 
#endif  /* __MCU_HWTAGS_H__ */
