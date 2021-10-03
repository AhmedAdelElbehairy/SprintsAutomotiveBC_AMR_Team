/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  CPU.h
 *       Module:  CPU
 *
 *  Description:  header file for CPU module.
 *
 *********************************************************************************************************************/
#ifndef __CPU_H__
#define __CPU_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"

/*- CONSTANTS ----------------------------------------------*/

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/
/* Set Processor Privilege Level to privileged level */
extern void CPU_PrivilegedMode(void);

/* Set Processor Privilege Level to unprivileged level */
extern void CPU_UnPrivilegedMode(void);

#endif  /* __CPU_H__ */
