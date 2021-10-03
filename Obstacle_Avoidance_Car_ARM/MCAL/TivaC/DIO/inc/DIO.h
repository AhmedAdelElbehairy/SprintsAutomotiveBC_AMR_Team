/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  DIO
 *
 *  Description:  header file for DIO module.
 *
 *********************************************************************************************************************/
#ifndef __DIO_H__
#define __DIO_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"
#include "DIO_Cfg.h"

/*- CONSTANTS ----------------------------------------------*/
/* Errors Definitions */

/**
* @brief: Module ID.
*/
#define           E_DIO_ID                      (Std_ReturnType)( 0x40 )

/**
* @brief: This return value indicate that a function got an
* invalid channel.
*/
#define           E_DIO_INVALID_CH              (Std_ReturnType)( 1 )

/* Dio Channel Type Values. */
#define DIO_CH_PA0                              (Dio_ChannelType)(0x00)
#define DIO_CH_PA1                              (Dio_ChannelType)(0x01)
#define DIO_CH_PA2                              (Dio_ChannelType)(0x02)
#define DIO_CH_PA3                              (Dio_ChannelType)(0x03)
#define DIO_CH_PA4                              (Dio_ChannelType)(0x04)
#define DIO_CH_PA5                              (Dio_ChannelType)(0x05)
#define DIO_CH_PA6                              (Dio_ChannelType)(0x06)
#define DIO_CH_PA7                              (Dio_ChannelType)(0x07)

#define DIO_CH_PB0                              (Dio_ChannelType)(0x10)
#define DIO_CH_PB1                              (Dio_ChannelType)(0x11)
#define DIO_CH_PB2                              (Dio_ChannelType)(0x12)
#define DIO_CH_PB3                              (Dio_ChannelType)(0x13)
#define DIO_CH_PB4                              (Dio_ChannelType)(0x14)
#define DIO_CH_PB5                              (Dio_ChannelType)(0x15)
#define DIO_CH_PB6                              (Dio_ChannelType)(0x16)
#define DIO_CH_PB7                              (Dio_ChannelType)(0x17)

#define DIO_CH_PC0                              (Dio_ChannelType)(0x20)
#define DIO_CH_PC1                              (Dio_ChannelType)(0x21)
#define DIO_CH_PC2                              (Dio_ChannelType)(0x22)
#define DIO_CH_PC3                              (Dio_ChannelType)(0x23)
#define DIO_CH_PC4                              (Dio_ChannelType)(0x24)
#define DIO_CH_PC5                              (Dio_ChannelType)(0x25)
#define DIO_CH_PC6                              (Dio_ChannelType)(0x26)
#define DIO_CH_PC7                              (Dio_ChannelType)(0x27)

#define DIO_CH_PD0                              (Dio_ChannelType)(0x30)
#define DIO_CH_PD1                              (Dio_ChannelType)(0x31)
#define DIO_CH_PD2                              (Dio_ChannelType)(0x32)
#define DIO_CH_PD3                              (Dio_ChannelType)(0x33)
#define DIO_CH_PD4                              (Dio_ChannelType)(0x34)
#define DIO_CH_PD5                              (Dio_ChannelType)(0x35)
#define DIO_CH_PD6                              (Dio_ChannelType)(0x36)
#define DIO_CH_PD7                              (Dio_ChannelType)(0x37)

#define DIO_CH_PE0                              (Dio_ChannelType)(0x40)
#define DIO_CH_PE1                              (Dio_ChannelType)(0x41)
#define DIO_CH_PE2                              (Dio_ChannelType)(0x42)
#define DIO_CH_PE3                              (Dio_ChannelType)(0x43)
#define DIO_CH_PE4                              (Dio_ChannelType)(0x44)
#define DIO_CH_PE5                              (Dio_ChannelType)(0x45)

#define DIO_CH_PF0                              (Dio_ChannelType)(0x50)
#define DIO_CH_PF1                              (Dio_ChannelType)(0x51)
#define DIO_CH_PF2                              (Dio_ChannelType)(0x52)
#define DIO_CH_PF3                              (Dio_ChannelType)(0x53)
#define DIO_CH_PF4                              (Dio_ChannelType)(0x54)

/* Dio Port Type Values. */
#define DIO_PORT_A                              (Dio_ChannelType)(0)
#define DIO_PORT_B                              (Dio_ChannelType)(1)
#define DIO_PORT_C                              (Dio_ChannelType)(2)
#define DIO_PORT_D                              (Dio_ChannelType)(3)
#define DIO_PORT_E                              (Dio_ChannelType)(4)
#define DIO_PORT_F                              (Dio_ChannelType)(5)

/* DIO Channel Values. */
#define DIO_CH_VAL_HIGH                         STD_HIGH
#define DIO_CH_VAL_LOW                          STD_LOW
#define DIO_INVALID_CH_VAL                      (Dio_LevelType)(2)

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Read A DIO Channel */
extern Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
/* Write on A DIO Channel */
extern void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
/* Read A DIO Port */
extern Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
/* Write on A DIO Port */
extern void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
/* Toggle A DIO Channel */
extern Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif  /* __PORT_H__ */
