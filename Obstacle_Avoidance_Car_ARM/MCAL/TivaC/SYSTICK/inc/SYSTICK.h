/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYSTICK.h
 *       Module:  SYSTICK
 *
 *  Description:  header file for SYSTICK module.    
 *  
 *********************************************************************************************************************/
#ifndef __SYSTICK_H__
#define __SYSTICK_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"

/*- CONSTANTS ----------------------------------------------*/
/*- ERRORS DEFINITIONS--------------------------------------*/

/**
* @brief: Module ID.
*/
#define           E_SYSTICK_ID                      (Std_ReturnType)( 0x00 )


/**
* @brief: This return value indicate that a function got an
* invalid value.
*/
#define           E_SYSTICK_INVALID_VALUE           (Std_ReturnType)( 1 )

/**
* @brief: This return value indicate that the module was
* initialized before.
*/
#define           E_SYSTICK_INIT_BEFORE             (Std_ReturnType)( 2 )

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/
/* Initializes the Systick module and set its Period. */
extern Std_ReturnType SYSTICK_Init(void);

/* Start Systick Clock */
extern Std_ReturnType SYSTICK_Start(void);

#endif  /* __SYSTICK_H__ */
