/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MCU.h
 *       Module:  MCU
 *
 *  Description:  header file for MCU module.
 *
 *********************************************************************************************************************/
#ifndef __MCU_H__
#define __MCU_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"
#include "MCU_Cfg.h"
#include "MCU_Lcfg.h"

/*- CONSTANTS ----------------------------------------------*/
/* Errors Definitions */

/**
* @brief: Module ID.
*/
#define           E_MCU_ID                      (Std_ReturnType)( 0x20 )

/**
* @brief: This return value indicate that the configurations have an
* invalid value.
*/
#define           E_MCU_INVALID_CONFIG          (Std_ReturnType)( 1 )

/**
* @brief: This return value indicate that the module was
* initialized before.
*/
#define           E_MCU_INIT_BEFORE             (Std_ReturnType)( 2 )

/**
* @brief: This return value indicate that a function got
* an uninitialized pointer.
*/
#define           E_MCU_NULL_PTR                (Std_ReturnType)( 3 )

/* Reset Cause Values. */
#define RESET_EXT                   (uint8_t)(0)
#define RESET_POR                   (uint8_t)(1)
#define RESET_BOR                   (uint8_t)(2)
#define RESET_WDT0                  (uint8_t)(3)
#define RESET_SW                    (uint8_t)(4)
#define RESET_WDT1                  (uint8_t)(5)
#define RESET_ERROR                 (uint8_t)(6)

/*- PRIMITIVE TYPES ----------------------------------------*/
typedef uint8_t Mcu_PllStatusType;
typedef uint8_t Mcu_ClockType;
typedef uint8_t Mcu_RawResetType;

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Initialize module. */
extern void Mcu_Init( const STR_Mcu_ConfigType* ConfigPtr);
extern Mcu_RawResetType Mcu_GetResetRawValue( void );
extern void Mcu_PerformReset(void);
extern Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting);

#endif  /* __MCU_H__ */
