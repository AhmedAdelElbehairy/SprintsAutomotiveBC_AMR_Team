/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT.c
 *       Module:  PORT
 *
 *  Description:  source file for PORT module.
 *
 *********************************************************************************************************************/
/*- INCLUDES
----------------------------------------------*/
#include "PORT.h"
#include "Mcu_Hw.h"
#include "Bit_Math.h"

/*- LOCAL MACROS
------------------------------------------*/
#define PORT_LOCK_VALUE         (uint32_t)(0x4C4F434B)
#define BIT_MASKING_OFFSET      (uint8_t)(2)
#define PCTL_PIN_MASK           (uint32_t)(0x0000000F)
#define PCTL_PIN_BIT_NUM        (uint8_t)(4)
#define MIN_PCTL_VAL            (uint8_t)(1)
#define MAX_PCTL_VAL            (uint8_t)(15)

/*- LOCAL Dataypes
----------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
----------------------------*/

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t u8_Init = STD_NOT_INIT;

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/

/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------*/

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ConfigPtr - Ports configuration address.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the MCU Ports.
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
    /* Variable to store Port base address */
    uint32_t * u32_PortBaseAddr;
    /* Variable for loop counter. */
    uint8_t u8_PinCounter;

    /* Check if init before. */
    if(STD_INIT == u8_Init)
    {
        /* Init before error. */
    }
    else
    {
        /* Loop on all configured pins. */
        for(u8_PinCounter = 0; u8_PinCounter < PORT_PINS_NUM; u8_PinCounter++)
        {
            /* Get Port Base Address */
            switch(ConfigPtr[u8_PinCounter].PortNum)
            {
                case PORT_A:
                    u32_PortBaseAddr = (uint32_t *)PORTA_APB_BASE_ADDRESS;
                    break;
                case PORT_B:
                    u32_PortBaseAddr = (uint32_t *)PORTB_APB_BASE_ADDRESS;
                    break;
                case PORT_C:
                    u32_PortBaseAddr = (uint32_t *)PORTC_APB_BASE_ADDRESS;
                    break;
                case PORT_D:
                    u32_PortBaseAddr = (uint32_t *)PORTD_APB_BASE_ADDRESS;
                    break;
                case PORT_E:
                    u32_PortBaseAddr = (uint32_t *)PORTE_APB_BASE_ADDRESS;
                    break;
                case PORT_F:
                    u32_PortBaseAddr = (uint32_t *)PORTF_APB_BASE_ADDRESS;
                    break;
                default:
                    break;
            }

            /* Protect JTAG Pins in PORTC. */
            if((PORT_C == ConfigPtr[u8_PinCounter].PortNum) && (PORT_PIN_3 >= ConfigPtr[u8_PinCounter].PortPinNum))
            {
                continue;
            }
            /* Unlock changes to protected pins. */
            else if(( (PORT_D == ConfigPtr[u8_PinCounter].PortNum) && (PORT_PIN_7 == ConfigPtr[u8_PinCounter].PortPinNum) ) ||
                    ( (PORT_F == ConfigPtr[u8_PinCounter].PortNum) && (PORT_PIN_0 == ConfigPtr[u8_PinCounter].PortPinNum) )
                   )
            {
                *((volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_LOCK_OFFSET)) = PORT_LOCK_VALUE;
                SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_CR_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
            }
            else
            {
                /* Do Nothing. */
            }

            /* Configure Pin Direction */
            if(PORT_PIN_OUTPUT == ConfigPtr[u8_PinCounter].PortPinDirection)
            {
                /* Set output direction */
                SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_DIR_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Configure Pin Level */
                if(PORT_PIN_HIGH == ConfigPtr[u8_PinCounter].PortPinLevelValue)
                {
                    /* Set Level High */
                    SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_DATA_ALL_PINS_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                }
                else if(PORT_PIN_LOW == ConfigPtr[u8_PinCounter].PortPinLevelValue)
                {
                    /* Set Level Low */
                    CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_DATA_ALL_PINS_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                }
                else
                {
                    /* Invalid Config error. */
                    break;
                }

                /* Configure Pin Output Current */
                switch(ConfigPtr[u8_PinCounter].PortPinOutputCurrent)
                {
                    case PORT_PIN_CUR_2MA:
                        SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_DR2R_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                        break;
                    case PORT_PIN_CUR_4MA:
                        SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_DR4R_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                        break;
                    case PORT_PIN_CUR_8MA:
                        SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_DR8R_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                        break;
                    default:
                        /* Invalid config error. */
                        u8_PinCounter = PORT_PINS_NUM;
                        continue;
                }

            }
            else if(PORT_PIN_INPUT == ConfigPtr[u8_PinCounter].PortPinDirection)
            {
                /* Set input direction */
                CLEAR_BIT(*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_DIR_OFFSET) , ConfigPtr[u8_PinCounter].PortPinNum);
                /* Configure Pin Resistance */
                switch(ConfigPtr[u8_PinCounter].PortPinInternalAttach)
                {
                    case PORT_PIN_PUR:
                        SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_PUR_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                        break;
                    case PORT_PIN_PDR:
                        SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_PDR_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                        break;
                    case PORT_PIN_ODR:
                        SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_ODR_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                        CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_PUR_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                        CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_PDR_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                        break;
                    default:
                        /* Invalid config error. */
                        u8_PinCounter = PORT_PINS_NUM;
                        continue;
                }
            }
            else
            {
                /* Invalid Config error. */
                break;
            }


            /* Configure Pin Mode */
            /* Clear the PMCx bits for this pin */
            *(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_PCTL_OFFSET) &= ~(PCTL_PIN_MASK << (ConfigPtr[u8_PinCounter].PortPinNum * PCTL_PIN_BIT_NUM));
            if(PORT_PIN_DEN == ConfigPtr[u8_PinCounter].PortPinMode)
            {
                /* Clear the corresponding bit in the GPIOAFSEL register to disable the alternative functionality on this pin */
                CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_AFSEL_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_DEN_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_AMSEL_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
            }
            else if(PORT_PIN_AMSEL == ConfigPtr[u8_PinCounter].PortPinMode)
            {
                /* Clear the corresponding bit in the GPIOAFSEL register to disable the alternative functionality on this pin */
                CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_AFSEL_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Clear the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_DEN_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Set the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_AMSEL_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
            }
            else if(PORT_PIN_EXTI == ConfigPtr[u8_PinCounter].PortPinMode)
            {
                /* Clear the corresponding bit in the GPIOAFSEL register to disable the alternative functionality on this pin */
                CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_AFSEL_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_DEN_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_AMSEL_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Detect edges */
                CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_IS_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Detect Both edges */
                SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_IBE_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Clear Interupt Flag */
                SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_ICR_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Enable Interrupt for pin */
                SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_IM_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
            }
            else if((ConfigPtr[u8_PinCounter].PortPinMode >= MIN_PCTL_VAL) && (ConfigPtr[u8_PinCounter].PortPinMode <= MAX_PCTL_VAL))
            {
                /* Set the corresponding bit in the GPIOAFSEL register to disable the alternative functionality on this pin */
                SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_AFSEL_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_DEN_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_AMSEL_OFFSET)), ConfigPtr[u8_PinCounter].PortPinNum);
                /* Set the corresponding bit in the GPIOPCTL register to select the alternative functionality on this pin */
                *(volatile uint32_t *)((volatile uint8_t *)u32_PortBaseAddr + PORT_PCTL_OFFSET) |= (ConfigPtr[u8_PinCounter].PortPinMode << (ConfigPtr[u8_PinCounter].PortPinNum * PCTL_PIN_BIT_NUM));
            }
            else
            {
                /* Invalid Config error. */
                break;
            }
        }

        /* Set init Flag. */
        u8_Init = STD_INIT;
    }
}
