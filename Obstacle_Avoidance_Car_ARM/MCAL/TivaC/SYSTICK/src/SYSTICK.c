/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYSTICK.c
 *       Module:  SYSTICK
 *
 *  Description:  source file for SYSTICK module.    
 *  
 *********************************************************************************************************************/
/*- INCLUDES
----------------------------------------------*/
#include "SYSTICK.h"
#include "SYSTICK_Cfg.h"
#include "SYSTICK_Lcfg.h"
#include "Mcu_Hw.h"

/*- LOCAL MACROS
------------------------------------------*/

/*- LOCAL Dataypes
----------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
----------------------------*/

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t u8_Init = STD_NOT_INIT;

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const STR_SYSTICK_config_t STR_SystickConfig;

/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------*/
/************************************************************************************
* Service Name: SYSTICK_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: Function Error State (E_OK or E_NOK)
* Description: Initializes the Systick module and set its Period.
************************************************************************************/
Std_ReturnType SYSTICK_Init(void)
{
    /* Variable to store function error state. */
    Std_ReturnType E_SYSTICK_Init;

    /* Validate valid Parameters are passed. */
    if(STD_NOT_INIT != u8_Init)
    {
        /* Set init before error. */
        E_SYSTICK_Init = (E_SYSTICK_ID | E_SYSTICK_INIT_BEFORE);
    }
    else if(SYSTICK_INVALID_VALUE <= STR_SystickConfig.u32_Period && 0 == STR_SystickConfig.u32_Period)
    {
        /* Set invalid value error. */
        E_SYSTICK_Init = (E_SYSTICK_ID | E_SYSTICK_INVALID_VALUE);
    }
    else
    {
        /* Disables the systick clock */
        STCTRL.B.ENABLE = STD_LOW;

        /* Set the period */
        STRELOAD.B.RELOAD = STR_SystickConfig.u32_Period;

        /* Configure the systick */
        STCTRL.B.CLK_SRC = STR_SystickConfig.u8_ClkMode;
        STCTRL.B.INTEN = STR_SystickConfig.u8_IntMode;

        /* Set initialized flag. */
        u8_Init = STD_INIT;

        /* Set error ok. */
        E_SYSTICK_Init = E_OK;
    }

    return E_SYSTICK_Init;
}

Std_ReturnType SYSTICK_Start(void)
{
    /* Variable to store function error state. */
    Std_ReturnType E_SYSTICK_Start;

    /* Validate valid Parameters are passed. */
    if(STD_NOT_INIT == u8_Init)
    {
        /* Set not init error. */
        E_SYSTICK_Start = E_NOK;
    }
    else
    {
        /* Enable systick clock */
        STCTRL.B.ENABLE = STD_HIGH;

        /* Set error ok. */
        E_SYSTICK_Start = E_OK;
    }

    return E_SYSTICK_Start;
}
