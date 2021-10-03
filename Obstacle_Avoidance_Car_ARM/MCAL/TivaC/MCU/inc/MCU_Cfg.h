/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MCU_Cfg.h
 *       Module:  MCU
 *
 *  Description:  header file for MCU module preprocessor configurations.
 *
 *********************************************************************************************************************/
#ifndef __MCU_CFG_H__
#define __MCU_CFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"

/*- CONSTANTS ----------------------------------------------*/
#define SYSDIV_MASK                 (uint8_t)(0xF)
#define USESYSDIV_MASK              (uint8_t)(0x1)
#define PWRDN_MASK                  (uint8_t)(0x1)
#define BYPASS_MASK                 (uint8_t)(0x1)
#define XTAL_MASK                   (uint8_t)(0x1F)
#define OSCSRC_MASK                 (uint8_t)(0x3)
#define MOSCDIS_MASK                (uint8_t)(0x1)

#define SYSDIV_START_BIT            (uint8_t)(23)
#define USESYSDIV_START_BIT         (uint8_t)(22)
#define PWRDN_START_BIT             (uint8_t)(13)
#define BYPASS_START_BIT            (uint8_t)(11)
#define XTAL_START_BIT              (uint8_t)(6)
#define OSCSRC_START_BIT            (uint8_t)(4)
#define MOSCDIS_START_BIT           (uint8_t)(0)

#define XTAL_4_MHZ                  (uint8_t)(0x06)
#define XTAL_16_MHZ                 (uint8_t)(0x15)

#define APINT_KEY                   (uint32_t)(0x05FA0000)

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

#endif  /* __MCU_CFG_H__ */
