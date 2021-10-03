/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MCU.c
 *       Module:  MCU
 *
 *  Description:  source file for MCU module.
 *
 *********************************************************************************************************************/
/*- INCLUDES
----------------------------------------------*/
#include "MCU.h"
#include "Mcu_Hw.h"

/*- LOCAL MACROS
------------------------------------------*/
/* Reset Values. */
#define SYSRESREQ_BIT               (uint8_t)(2)
#define SYSTEM_RESET_CAUSE_BITS     (uint8_t)(0x3F)

/* PLL Status Values. */
#define PLL_STATE_BIT               (uint8_t)(6)
#define PLL_UNLOCKED                (uint8_t)(0)
#define PLL_LOCKED                  (uint8_t)(1)

/* Freq Values. */
#define PIOSC_MAX_FREQ              (uint32_t)(16000)
#define PIOSC_4_MAX_FREQ            (uint32_t)(4000)
#define PLL_MAX_FREQ                (uint32_t)(80000)
#define PLL_IN_FREQ                 (uint32_t)(200000)

/*- LOCAL Dataypes
----------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
----------------------------*/
static Std_ReturnType Mcu_DistributePllClock( void );
static Mcu_PllStatusType Mcu_GetPllStatus( void );

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t u8_Init = STD_NOT_INIT;
static STR_Mcu_ConfigType * STR_MCUConfig = NULL_PTR;

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const uint16_t au16_ClockGates[CONFIGURED_CLOCK_GATES];

/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------*/

/************************************************************************************
* Service Name: Mcu_DistributePllClock
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: Function error state.
* Description: Set Using PLL.
************************************************************************************/
static Std_ReturnType Mcu_DistributePllClock( void )
{
    /* Variable to store function error state. */
    Std_ReturnType E_MCU_State;

    if(STD_INIT != u8_Init)
    {
        E_MCU_State = E_NOK;
    }
    else
    {
        /* Enable PLL Bypass. */
        SYSCTL_RCC &= ~(BYPASS_MASK << BYPASS_START_BIT);
        E_MCU_State = E_OK;
    }

    /* Return error state. */
    return E_MCU_State;
}

/************************************************************************************
* Service Name: Mcu_GetPllStatus
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: PLL State.
* Description: Return if PLL is locked or not.
************************************************************************************/
static Mcu_PllStatusType Mcu_GetPllStatus( void )
{
    /* Variable to store PLL state in it. */
    Mcu_PllStatusType PLLState;

    /* Check PLL state. */
    if(SYSCTL_RIS & (STD_HIGH << PLL_STATE_BIT))
    {
        PLLState = PLL_LOCKED;
    }
    else
    {
        PLLState = PLL_UNLOCKED;
    }

    /* Return PLL state. */
    return PLLState;
}

/*- APIs IMPLEMENTATION
-----------------------------------*/

/************************************************************************************
* Service Name: Mcu_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Clock settings configuration address.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the MCU Config variable.
************************************************************************************/
void Mcu_Init( const STR_Mcu_ConfigType* ConfigPtr)
{
    /* Check valid parameters. */
    if(STD_NOT_INIT == u8_Init && ConfigPtr != NULL_PTR)
    {
        /* Store Clock settings address. */
        STR_MCUConfig = ConfigPtr;

        /* Set module to init. */
        u8_Init = STD_INIT;
    }
}

/************************************************************************************
* Service Name: Mcu_GetResetRawValue
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: Reset Cause.
* Description: Returns the reset cause of the MCU.
************************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue( void )
{
    /* Variable to store Reset cause in it. */
    Mcu_RawResetType ResetCause;

    /* Get Reset Cause bits. */
    uint32_t u32_ResetReg = SYSCTL_RESC & SYSTEM_RESET_CAUSE_BITS;
    switch(u32_ResetReg)
    {
        case (STD_HIGH << RESET_EXT):
            ResetCause = RESET_EXT;
            break;
        case (STD_HIGH << RESET_POR):
            ResetCause = RESET_POR;
            break;
        case (STD_HIGH << RESET_BOR):
            ResetCause = RESET_BOR;
            break;
        case (STD_HIGH << RESET_WDT0):
            ResetCause = RESET_WDT0;
            break;
        case (STD_HIGH << RESET_SW):
            ResetCause = RESET_SW;
            break;
        case (STD_HIGH << RESET_WDT1):
            ResetCause = RESET_WDT1;
            break;
        default:
            ResetCause = RESET_ERROR;
            break;
    }

    /* Return Reset cause. */
    return ResetCause;
}

/************************************************************************************
* Service Name: Mcu_PerformReset
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Perform System Reset.
************************************************************************************/
void Mcu_PerformReset(void)
{
    /* Perform System Reset. */
    APINT = APINT_KEY | (STD_HIGH << SYSRESREQ_BIT);
}

/************************************************************************************
* Service Name: Mcu_InitClock
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: Function Error State
* Description: Configure the MCU clock.
************************************************************************************/
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)
{
    /* Variable to store function error state. */
    Std_ReturnType E_MCU_Config;

    /* Validate valid Parameters are passed. */
    if(NULL_PTR == STR_MCUConfig)
    {
        /* Set init before error. */
        E_MCU_Config = (E_MCU_ID | E_MCU_NULL_PTR);
    }
    else if(
            ((OSCSRC_PIOSC == STR_MCUConfig[ClockSetting].u8_OSCSRC) && (PIOSC_MAX_FREQ < STR_MCUConfig[ClockSetting].u32_Freq) && (STD_OFF == STR_MCUConfig[ClockSetting].u8_PLLUse)) ||
            ((OSCSRC_PIOSC_DIV_4 == STR_MCUConfig[ClockSetting].u8_OSCSRC) && (PIOSC_4_MAX_FREQ < STR_MCUConfig[ClockSetting].u32_Freq) && (STD_OFF == STR_MCUConfig[ClockSetting].u8_PLLUse)) ||
            ((STD_ON == STR_MCUConfig[ClockSetting].u8_PLLUse) && (PLL_MAX_FREQ < STR_MCUConfig[ClockSetting].u32_Freq) && (OSCSRC_PIOSC_DIV_4 != STR_MCUConfig[ClockSetting].u8_OSCSRC || OSCSRC_LFIOSC != STR_MCUConfig[ClockSetting].u8_OSCSRC))
            )
    {
        /* Set invalid config error. */
        E_MCU_Config = (E_MCU_ID | E_MCU_INVALID_CONFIG);
    }
    else
    {
        /* Store temp RCC val. */
        uint32_t u32_RCCVal = SYSCTL_RCC;

        /* Get max frequency of clock source. */
        uint32_t u32_FreqMax;
        if(OSCSRC_PIOSC == STR_MCUConfig[ClockSetting].u8_OSCSRC)
        {
            u32_FreqMax = PIOSC_MAX_FREQ;
        }
        else if(OSCSRC_PIOSC_DIV_4 == STR_MCUConfig[ClockSetting].u8_OSCSRC)
        {
            u32_FreqMax = PIOSC_4_MAX_FREQ;
        }
        else if(STD_ON == STR_MCUConfig[ClockSetting].u8_PLLUse)
        {
            u32_FreqMax = PLL_IN_FREQ;
        }
        else
        {
            /* Do Nothing. */
        }

        /* Clear Temp RCC Configurations */
        u32_RCCVal &= ~(MOSCDIS_MASK<<MOSCDIS_START_BIT);
        u32_RCCVal &= ~(OSCSRC_MASK<<OSCSRC_START_BIT);
        u32_RCCVal &= ~(XTAL_MASK<<XTAL_START_BIT);
        u32_RCCVal &= ~(USESYSDIV_MASK << USESYSDIV_START_BIT);
        u32_RCCVal &= ~(SYSDIV_MASK << SYSDIV_START_BIT);

        /* Check whether system division is needed. */
        uint8_t u8_SysDivVal = (uint8_t)(u32_FreqMax/STR_MCUConfig[ClockSetting].u32_Freq);
        if(u8_SysDivVal >= 2)
        {
            u8_SysDivVal--;
            u32_RCCVal |= (u8_SysDivVal << SYSDIV_START_BIT) | (USESYSDIV_MASK << USESYSDIV_START_BIT);
        }

        /* Configure Temp RCC */
        u32_RCCVal |= (
                (STR_MCUConfig[ClockSetting].u8_OSCSRC << OSCSRC_START_BIT) |
                (XTAL_16_MHZ << XTAL_START_BIT)
            );

        if(OSCSRC_MOSC != STR_MCUConfig[ClockSetting].u8_OSCSRC)
        {
            /* Enable Main oscillator source. */
            u32_RCCVal |= (MOSCDIS_MASK << MOSCDIS_START_BIT);
        }

        /* Set Required Value to RCC Register */
        SYSCTL_RCC = u32_RCCVal;

        /* Enable PLL if used. */
        if(STD_ON == STR_MCUConfig[ClockSetting].u8_PLLUse)
        {
            /* Power on PLL */
            SYSCTL_RCC &= ~(PWRDN_MASK << PWRDN_START_BIT);
            /* Wait for PLL to work correctly. */
            while(PLL_UNLOCKED == Mcu_GetPllStatus());
            /* Distribute PLL clock. */
            Mcu_DistributePllClock();
        }

        /* Set initialized flag. */
        u8_Init = STD_INIT;

        /* Set error ok value. */
        E_MCU_Config = E_OK;
    }

    uint8_t u8_CGCounter;
    for(u8_CGCounter =0; u8_CGCounter < CONFIGURED_CLOCK_GATES; u8_CGCounter++)
    {
        uint8_t u8_RegOffset = (au16_ClockGates[u8_CGCounter] >> 4);
        uint8_t u8_BitNum = (au16_ClockGates[u8_CGCounter] & 0xF);
        *((volatile uint32_t *)(SYSCTL_BASE_ADDRESS + SYSCTL_RCGC_OFFSET) + u8_RegOffset) |= (STD_HIGH << u8_BitNum);
    }

    /* Return function error state. */
    return E_MCU_Config;
}
