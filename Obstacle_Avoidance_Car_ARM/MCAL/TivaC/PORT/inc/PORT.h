/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT.h
 *       Module:  PORT
 *
 *  Description:  header file for PORT module.
 *
 *********************************************************************************************************************/
#ifndef __PORT_H__
#define __PORT_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"
#include "PORT_Cfg.h"
#include "PORT_Lcfg.h"

/*- CONSTANTS ----------------------------------------------*/
/* Errors Definitions */

/**
* @brief: Module ID.
*/
#define           E_PORT_ID                     (Std_ReturnType)( 0x30 )

/**
* @brief: This return value indicate that the configurations have an
* invalid value.
*/
#define           E_PORT_INVALID_CONFIG         (Std_ReturnType)( 1 )

/**
* @brief: This return value indicate that the module was
* initialized before.
*/
#define           E_PORT_INIT_BEFORE            (Std_ReturnType)( 2 )

/**
* @brief: This return value indicate that a function got
* an uninitialized pointer.
*/
#define           E_PORT_NULL_PTR               (Std_ReturnType)( 3 )

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Initialize module. */
extern void Port_Init(const Port_ConfigType* ConfigPtr);

#endif  /* __PORT_H__ */
