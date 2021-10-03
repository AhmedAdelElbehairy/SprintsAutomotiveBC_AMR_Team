/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.c
 *       Module:  IntCtrl
 *
 *  Description:  source file for IntCtrl module.
 *
 *********************************************************************************************************************/
/*- INCLUDES
----------------------------------------------*/
#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"
#include "IntCtrl_Lcfg.h"
#include "Mcu_Hw.h"

/*- LOCAL MACROS
------------------------------------------*/
#define PRI_PIN_START_BIT       (uint8_t)(5)
#define PIN_RESTART_NUM         (uint8_t)(32)
#define PRI_PIN_RESTART_NUM     (uint8_t)(37)
#define PRI_PIN_INCREMENT_VAL   (uint8_t)(8)
#define PRI_BITS                (uint8_t)(7)

/*- LOCAL Dataypes
----------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
----------------------------*/

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t u8_Init = STD_NOT_INIT;

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const STR_IntCtrl_config_t STR_IntCtrlConfig;

/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------*/
/************************************************************************************
* Service Name: IntCtrl_EnableGlobal
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Enable Global Interrupts.
************************************************************************************/
void IntCtrl_EnableGlobal(void)
{
    Enable_Interrupts();
}

/************************************************************************************
* Service Name: IntCtrl_DisableGlobal
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Disable Global Interrupts.
************************************************************************************/
void IntCtrl_DisableGlobal(void)
{
    Disable_Interrupts();
}

/************************************************************************************
* Service Name: IntCtrl_Init
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: Function Error State
* Description: Initializes the IntCtrl module.
************************************************************************************/
Std_ReturnType IntCtrl_Init(void)
{
    volatile uint32_t * ptru32_EnReg = &EN0;
    volatile uint32_t * ptru32_DisReg = &DIS0;
    volatile uint32_t * ptru32_PriReg = &PRI0;
    uint8_t u8_PinNum = 0;
    uint8_t u8_PriPinNum = PRI_PIN_START_BIT;

    /* Variable to store function error state. */
    Std_ReturnType E_IntCtrl_Init = E_OK;

    /* Validate valid Parameters are passed. */
    if(STD_NOT_INIT != u8_Init)
    {
        /* Set init before error. */
        E_IntCtrl_Init = (E_INTCTRL_ID | E_INTCTRL_INIT_BEFORE);
    }
    else
    {
        /* Set Base Priority. */
        volatile uint8_t u8_BasePRI = (STR_IntCtrlConfig.u8_BasePriority << INT_BASEPRI_START_BIT);
        Set_BasePRI();

        /* Set Group and Subgroup Priorities. */
        APINT = (INT_APINT_KEY | (STR_IntCtrlConfig.u8_GroupAndSubgroup << INT_PRIGROUP_START_BIT) );

        /* Loop on all Interrupts */
        uint8_t u8_IntCounter;
        for(u8_IntCounter = 0; u8_IntCounter < INT_NUMBERS; u8_IntCounter++)
        {
            /* Change Used Registers. */
            if(u8_PinNum == PIN_RESTART_NUM)
            {
                /* Reset pin number */
                u8_PinNum = 0;
                /* Get Next Enable/Disable Register */
                ptru32_EnReg++;
                ptru32_DisReg++;
            }
            else
            {
                /* Do nothing. */
            }

            if(u8_PriPinNum == PRI_PIN_RESTART_NUM)
            {
                /* Reset PRI pin number */
                u8_PriPinNum = PRI_PIN_START_BIT;
                /* Get Next PRI Register */
                ptru32_PriReg++;
            }
            else
            {
                /* Do nothing. */
            }

            /* Check valid Priority. */
            if(INT_INVALID_PRI > STR_IntCtrlConfig.aSTR_Ints[u8_IntCounter].u8_GroupAndSubgroupPRI)
            {
                /* Set Priority. */
                *ptru32_PriReg = (*ptru32_PriReg & ~(PRI_BITS<<u8_PriPinNum) | (STR_IntCtrlConfig.aSTR_Ints[u8_IntCounter].u8_GroupAndSubgroupPRI<<u8_PriPinNum));
            }
            else
            {
                /* Set invalid config error. */
                E_IntCtrl_Init = (E_INTCTRL_ID | E_INTCTRL_INVALID_CONFIG);
                break;
            }

            /* Check Enable/Disable Interrupt. */
            if(STD_ON == STR_IntCtrlConfig.aSTR_Ints[u8_IntCounter].u8_Enable)
            {
                /* Enable Interrupt. */
                *ptru32_EnReg |= (STD_HIGH << u8_PinNum);
            }
            else if(STD_OFF == STR_IntCtrlConfig.aSTR_Ints[u8_IntCounter].u8_Enable)
            {
                /* Disable Interrupt. */
                *ptru32_DisReg |= (STD_HIGH << u8_PinNum);
            }
            else
            {
                /* Set invalid config error. */
                E_IntCtrl_Init = (E_INTCTRL_ID | E_INTCTRL_INVALID_CONFIG);
                break;
            }

            /* Increment Pin number */
            u8_PinNum++;
            /* Increment PRI Pin number */
            u8_PriPinNum+=PRI_PIN_INCREMENT_VAL;
        }

        /* Set initialized flag. */
        u8_Init = STD_INIT;
    }

    /* Return function error state. */
    return E_IntCtrl_Init;
}
