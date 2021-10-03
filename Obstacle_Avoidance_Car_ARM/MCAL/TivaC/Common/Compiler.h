/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Compiler.h
 *       Module:  -
 *
 *  Description:  Contains Compiler Dependent MACRO Definition     
 *  
 *********************************************************************************************************************/
#ifndef __COMPILER_H__
#define __COMPILER_H__

/*- INCLUDES -----------------------------------------------*/

/*- CONSTANTS ----------------------------------------------*/
/* NULL_PTR define with a void pointer to zero definition*/
#define NULL_PTR            ((void *)0)

/* INLINE  define for abstraction of the keyword inline*/
#define INLINE              inline

/* LOCAL_INLINE define for abstraction of the keyword inline in functions with "static" scope.
   Different compilers may require a different sequence of the keywords "static" and "inline" 
   if this is supported at all. */
#define LOCAL_INLINE        static inline

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/
/* Switch to unprivileged mode */
#define Switch_to_Unprivileged() \
   __asm(" MRS R0, CONTROL");\
   __asm(" ORR R0, R0, #0x01");\
   __asm(" MSR CONTROL, R0")

/* Switch to privileged mode */
#define Switch_to_Privileged() \
   __asm(" MRS R0, CONTROL");\
   __asm(" AND R0, R0, #0xFE");\
   __asm(" MSR CONTROL, R0")

/* Trigger SVC Exception to Switch to privileged mode.*/
#define Trigger_SVC_SwitchToPrivileged() __asm(" SVC #0x00")

/* Get SVC Number */
#define Get_SVC_Number() \
   /* Extract the stacked LR register value which vectoring to this handler */\
   __asm(" LDR R0, [SP, #32]");\
   /* Extract the SVC number value it is exist in the first byte of address LR-2 */\
   __asm(" LDRB R0, [R0, #-2]");\
   /* Load the R0 value to SVC_Num variable as SP is pointing to SVC_Num location in the stack memory */\
   __asm(" STR R0, [SP]")

/* Enable Global Interrupts. */
#define Enable_Interrupts()    __asm(" CPSIE I")

/* Disable Global Interrupts. */
#define Disable_Interrupts()   __asm(" CPSID I")

/* Set Base Priority */
#define Set_BasePRI() \
   __asm(" LDR R0, [SP, #16]");\
   __asm(" MSR BASEPRI, R0")

/*- FUNCTION DECLARATIONS ----------------------------------*/

#endif  /* __COMPILER_H__ */
