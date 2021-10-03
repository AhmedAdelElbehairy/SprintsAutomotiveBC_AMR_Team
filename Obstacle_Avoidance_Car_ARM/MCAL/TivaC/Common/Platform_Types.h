/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Platform_Types.h
 *       Module:  -
 *
 *  Description:  Contains types that dependent on platform - CortexM4     
 *  
 *********************************************************************************************************************/
#ifndef __PLATFORM_TYPES_H__
#define __PLATFORM_TYPES_H__

/*- INCLUDES -----------------------------------------------*/

/*- CONSTANTS ----------------------------------------------*/
#define WORD_LENGTH_BITS         (32u)
#define WORD_LENGTH_BYTES        (4u)
#define MSB_FIRST                (0u)    /* big endian bit ordering */
#define LSB_FIRST                (1u)    /* little endian bit ordering */

#define HIGH_BYTE_FIRST          (0u)    /* big endian byte ordering */
#define LOW_BYTE_FIRST           (1u)    /* little endian byte ordering */

#ifndef TRUE
   #define TRUE                  (1u)
#endif

#ifndef FALSE
   #define FALSE                 (0u)
#endif

#define CPU_BIT_ORDER            LSB_FIRST        /*little endian bit ordering*/
#define CPU_BYTE_ORDER           LOW_BYTE_FIRST   /*little endian byte ordering*/

/*- PRIMITIVE TYPES ----------------------------------------*/
typedef unsigned char            boolean;       /*        TRUE .. FALSE           */

typedef signed char              sint8_t;       /*        -128 .. +127            */
typedef unsigned char            uint8_t;       /*           0 .. 255             */
typedef signed short             sint16_t;      /*      -32768 .. +32767          */
typedef unsigned short           uint16_t;      /*           0 .. 65535           */
typedef signed long              sint32_t;      /* -2147483648 .. +2147483647     */
typedef unsigned long            uint32_t;      /*           0 .. 4294967295      */

typedef float                    float32_t;
typedef double                   float64_t;

typedef void (*Ptr_VoidFuncVoid_t)(void);
typedef void (*Ptr_VoidFuncU8_t)(uint8_t);

#ifdef PLATFORM_SUPPORT_SINT64_UINT64 /*Valid only for gnu and C99 */
typedef signed    long long      sint64;   /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned  long long      uint64;   /*                    0 .. 18446744073709551615     */
#endif

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/
 
#endif  /* __PLATFORM_TYPES_H__ */
