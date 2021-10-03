/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.h
 *       Module:  IntCtrl
 *
 *  Description:  header file for IntCtrl module.
 *
 *********************************************************************************************************************/
#ifndef __INTCTRL_H__
#define __INTCTRL_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"

/*- CONSTANTS ----------------------------------------------*/
/* Errors Definitions */

/**
* @brief: Module ID.
*/
#define           E_INTCTRL_ID                  (Std_ReturnType)( 0x10 )

/**
* @brief: This return value indicate that the configurations have an
* invalid value.
*/
#define           E_INTCTRL_INVALID_CONFIG      (Std_ReturnType)( 1 )

/**
* @brief: This return value indicate that the module was
* initialized before.
*/
#define           E_INTCTRL_INIT_BEFORE         (Std_ReturnType)( 2 )

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/
/* Enable Global Interrupt. */
extern void IntCtrl_EnableGlobal(void);

/* Disable Global Interrupt. */
extern void IntCtrl_DisableGlobal(void);

/* Initialize interrupt module. */
extern Std_ReturnType IntCtrl_Init(void);

#endif  /* __INTCTRL_H__ */
