/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Bit_Math.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Bit Manipulation
 *
 *********************************************************************************************************************/

#ifndef __BIT_MATH_H__
#define __BIT_MATH_H__

/*- INCLUDES -----------------------------------------------*/
# include "Std_Types.h"

/*- CONSTANTS ----------------------------------------------*/
#define BIT_0           (uint32_t)(0)
#define BIT_1           (uint32_t)(1)
#define BIT_2           (uint32_t)(2)
#define BIT_3           (uint32_t)(3)
#define BIT_4           (uint32_t)(4)
#define BIT_5           (uint32_t)(5)
#define BIT_6           (uint32_t)(6)
#define BIT_7           (uint32_t)(7)

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/
/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG = (REG>>num) | (REG << ((sizeof(REG) * 8)-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG = (REG<<num) | (REG >> ((sizeof(REG) * 8)-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( (REG & (1<<BIT)) >> BIT)

/* Set Bit using bit mapping of SRAM */
#define SET_BIT_RAM_BB(REG,BIT) ((*((volatile uint32_t *)( 0x22000000 + (((uint32_t)(&REG) - 0x20000000) * 32) + ((BIT) * 4) ))) = STD_HIGH)

/* Set Bit using bit mapping of Peripheral */
#define SET_BIT_PER_BB(REG,BIT) ((*((volatile uint32_t *)( 0x42000000 + (((uint32_t)(&REG) - 0x40000000) * 32) + ((BIT) * 4) ))) = STD_HIGH)

/* Clear Bit using bit mapping of SRAM */
#define CLEAR_BIT_RAM_BB(REG,BIT) ((*((volatile uint32_t *)( 0x22000000 + (((uint32_t)(&REG) - 0x20000000) * 32) + ((BIT) * 4) ))) = STD_LOW)

/* Clear Bit using bit mapping of Peripheral */
#define CLEAR_BIT_PER_BB(REG,BIT) ((*((volatile uint32_t *)( 0x42000000 + (((uint32_t)(&REG) - 0x40000000) * 32) + ((BIT) * 4) ))) = STD_LOW)

/*- FUNCTION DECLARATIONS ----------------------------------*/

#endif /* __BIT_MATH_H__ */
