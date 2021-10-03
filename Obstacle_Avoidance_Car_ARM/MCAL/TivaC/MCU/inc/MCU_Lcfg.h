/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MCU_Lcfg.h
 *       Module:  MCU
 *
 *  Description:  header file for MCU module linking configurations.
 *
 *********************************************************************************************************************/
#ifndef __MCU_LCFG_H__
#define __MCU_LCFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"

/*- CONSTANTS ----------------------------------------------*/
#define CLOCK_SETTINGS_NUM      (uint8_t)(3)

/* Oscillator Source Values */
#define OSCSRC_MOSC             (uint8_t)(0x00)
#define OSCSRC_PIOSC            (uint8_t)(0x01)
#define OSCSRC_PIOSC_DIV_4      (uint8_t)(0x02)
#define OSCSRC_LFIOSC           (uint8_t)(0x03)
#define OSCSRC_INVALID_VAL      (uint8_t)(0x04)

/* Clock Gates */
#define CONFIGURED_CLOCK_GATES  (uint8_t)(6)

#define CG_WDT0                 (uint16_t)(0x000)
#define CG_WDT1                 (uint16_t)(0x001)

#define CG_T0                   (uint16_t)(0x010)
#define CG_T1                   (uint16_t)(0x011)
#define CG_T2                   (uint16_t)(0x012)
#define CG_T3                   (uint16_t)(0x013)
#define CG_T4                   (uint16_t)(0x014)
#define CG_T5                   (uint16_t)(0x015)

#define CG_PORTA                (uint16_t)(0x020)
#define CG_PORTB                (uint16_t)(0x021)
#define CG_PORTC                (uint16_t)(0x022)
#define CG_PORTD                (uint16_t)(0x023)
#define CG_PORTE                (uint16_t)(0x024)
#define CG_PORTF                (uint16_t)(0x025)

#define CG_DMA                  (uint16_t)(0x030)

#define CG_HIB                  (uint16_t)(0x050)

#define CG_UART0                (uint16_t)(0x060)
#define CG_UART1                (uint16_t)(0x061)
#define CG_UART2                (uint16_t)(0x062)
#define CG_UART3                (uint16_t)(0x063)
#define CG_UART4                (uint16_t)(0x064)
#define CG_UART5                (uint16_t)(0x065)
#define CG_UART6                (uint16_t)(0x066)
#define CG_UART7                (uint16_t)(0x067)

#define CG_SSI0                 (uint16_t)(0x070)
#define CG_SSI1                 (uint16_t)(0x071)
#define CG_SSI2                 (uint16_t)(0x072)
#define CG_SSI3                 (uint16_t)(0x073)

#define CG_I2C0                 (uint16_t)(0x080)
#define CG_I2C1                 (uint16_t)(0x081)
#define CG_I2C2                 (uint16_t)(0x082)
#define CG_I2C3                 (uint16_t)(0x083)

#define CG_USB                  (uint16_t)(0x0A0)

#define CG_CAN0                 (uint16_t)(0x0D0)
#define CG_CAN1                 (uint16_t)(0x0D1)

#define CG_ADC0                 (uint16_t)(0x0E0)
#define CG_ADC1                 (uint16_t)(0x0E1)

#define CG_ACMP                 (uint16_t)(0x0F0)

#define CG_PWM0                 (uint16_t)(0x100)
#define CG_PWM1                 (uint16_t)(0x101)

#define CG_QEI0                 (uint16_t)(0x110)
#define CG_QEI1                 (uint16_t)(0x111)

#define CG_EEPROM               (uint16_t)(0x160)

#define CG_WT0                  (uint16_t)(0x170)
#define CG_WT1                  (uint16_t)(0x171)
#define CG_WT2                  (uint16_t)(0x172)
#define CG_WT3                  (uint16_t)(0x173)
#define CG_WT4                  (uint16_t)(0x174)
#define CG_WT5                  (uint16_t)(0x175)

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_Mcu_ConfigType{
   uint8_t          u8_PLLUse;
   uint8_t          u8_OSCSRC;
   uint32_t         u32_Freq;
} STR_Mcu_ConfigType;

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

#endif  /* __MCU_LCFG_H__ */
