/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Std_Types.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Standard Types
 *
 *********************************************************************************************************************/

#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__

/*- INCLUDES -----------------------------------------------*/
# include "Platform_Types.h"
# include "Compiler.h"

/*- CONSTANTS ----------------------------------------------*/
#define STD_LOW         (uint8_t)(0)   /* Physical state 0V */
#define STD_HIGH        (uint8_t)(1)   /* Physical state 5V or 3.3V */

#define STD_ACTIVE      (uint8_t)(1)   /* Logical state active */
#define STD_IDLE        (uint8_t)(0)   /* Logical state idle */

#define STD_ON          (uint8_t)(1)
#define STD_OFF         (uint8_t)(0)

#define STD_INIT        (uint8_t)(1)
#define STD_NOT_INIT    (uint8_t)(0)

#define NULL_TERMINATOR (uint8_t)('\0')
#define END_OF_STRING   (uint8_t)('\0')
#define NEW_LINE        (uint8_t)('\r')
#define BACKSPACE       (uint8_t)('\b')

#define ZERO            (uint8_t)(0)
/*- PRIMITIVE TYPES ----------------------------------------*/
typedef uint8_t Std_ReturnType;
#define E_OK            (uint8_t)(0)
#define E_NOK           (uint8_t)(1)

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

#endif /* __STD_TYPES_H__ */
