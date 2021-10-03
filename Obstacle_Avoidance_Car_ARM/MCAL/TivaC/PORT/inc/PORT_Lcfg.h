/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT_Lcfg.h
 *       Module:  PORT
 *
 *  Description:  header file for PORT module linking configurations.
 *
 *********************************************************************************************************************/
#ifndef __PORT_LCFG_H__
#define __PORT_LCFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"
#include "PORT_Cfg.h"

/*- CONSTANTS ----------------------------------------------*/
#define PORT_PINS_NUM            (uint8_t)(43U)
/* Pin Levels Values */
#define PORT_PIN_HIGH            (Port_PinLevel)(STD_HIGH)
#define PORT_PIN_LOW             (Port_PinLevel)(STD_LOW)
#define PORT_PIN_LEVEL_INVALID   (Port_PinLevel)(2)
/* Pin Directions Values */
#define PORT_PIN_INPUT           (Port_PinDirectionType)(0)
#define PORT_PIN_OUTPUT          (Port_PinDirectionType)(1)
#define PORT_PIN_DIR_INVALID     (Port_PinDirectionType)(2)
/* Pin Internal Attach Values */
#define PORT_PIN_PUR             (Port_PinInternalAttachType)(0)
#define PORT_PIN_PDR             (Port_PinInternalAttachType)(1)
#define PORT_PIN_ODR             (Port_PinInternalAttachType)(2)
#define PORT_PIN_RES_INVALID     (Port_PinInternalAttachType)(3)
/* Pin Output Current Values */
#define PORT_PIN_CUR_2MA         (Port_PinOutputCurrentType)(0)
#define PORT_PIN_CUR_4MA         (Port_PinOutputCurrentType)(1)
#define PORT_PIN_CUR_8MA         (Port_PinOutputCurrentType)(2)
#define PORT_PIN_CUR_INVALID     (Port_PinOutputCurrentType)(3)
/* Pin Mode Values */
#define PORT_PIN_MODE_INVALID    (Port_PinModeType)(16)

/* Port Number Values. */
#define PORT_A                   (Port_Num)(0)
#define PORT_B                   (Port_Num)(1)
#define PORT_C                   (Port_Num)(2)
#define PORT_D                   (Port_Num)(3)
#define PORT_E                   (Port_Num)(4)
#define PORT_F                   (Port_Num)(5)

/* Port Pin Number Values. */
#define PORT_PIN_0               (Port_PinNum)(0)
#define PORT_PIN_1               (Port_PinNum)(1)
#define PORT_PIN_2               (Port_PinNum)(2)
#define PORT_PIN_3               (Port_PinNum)(3)
#define PORT_PIN_4               (Port_PinNum)(4)
#define PORT_PIN_5               (Port_PinNum)(5)
#define PORT_PIN_6               (Port_PinNum)(6)
#define PORT_PIN_7               (Port_PinNum)(7)

/* PCTL Values */
#define PORT_PIN_DEN             (Port_PinModeType)(0)
#define PORT_PIN_AMSEL           (Port_PinModeType)(16)
#define PORT_PIN_EXTI            (Port_PinModeType)(17)

/* PortA PCTL Values. */
#define PA0_U0RX                 (Port_PinModeType)(1)
#define PA0_CAN1RX               (Port_PinModeType)(8)

#define PA1_U0TX                 (Port_PinModeType)(1)
#define PA1_CAN1TX               (Port_PinModeType)(8)

#define PA2_SSI0CLK              (Port_PinModeType)(2)

#define PA3_SSI0FSS              (Port_PinModeType)(2)

#define PA4_SSI0RX               (Port_PinModeType)(2)

#define PA5_SSI0TX               (Port_PinModeType)(2)

#define PA6_I2C1SCL              (Port_PinModeType)(3)
#define PA6_M1PWM2               (Port_PinModeType)(5)

#define PA7_I2C1SDA              (Port_PinModeType)(3)
#define PA7_M1PWM3               (Port_PinModeType)(5)

/* PortB PCTL Values. */
#define PB0_USB0ID               PORT_PIN_AMSEL
#define PB0_U1RX                 (Port_PinModeType)(1)
#define PB0_T2CCP0               (Port_PinModeType)(7)

#define PB1_USB0VBUS             PORT_PIN_AMSEL
#define PB1_U1TX                 (Port_PinModeType)(1)
#define PB1_T2CCP1               (Port_PinModeType)(7)

#define PB2_I2C0SCL              (Port_PinModeType)(3)
#define PB2_T3CCP0               (Port_PinModeType)(7)

#define PB3_I2C0SDA              (Port_PinModeType)(3)
#define PB3_T3CCP1               (Port_PinModeType)(7)

#define PB4_AIN10                PORT_PIN_AMSEL
#define PB4_SSI2CLK              (Port_PinModeType)(2)
#define PB4_M0PWM2               (Port_PinModeType)(4)
#define PB4_T1CCP0               (Port_PinModeType)(7)
#define PB4_CAN0RX               (Port_PinModeType)(8)

#define PB5_AIN11                PORT_PIN_AMSEL
#define PB5_SSI2FSS              (Port_PinModeType)(2)
#define PB5_M0PWM3               (Port_PinModeType)(4)
#define PB5_T1CCP1               (Port_PinModeType)(7)
#define PB5_CAN0TX               (Port_PinModeType)(8)

#define PB6_SSI2RX               (Port_PinModeType)(2)
#define PB6_M0PWM0               (Port_PinModeType)(4)
#define PB6_T0CCP0               (Port_PinModeType)(7)

#define PB7_SSI2TX               (Port_PinModeType)(2)
#define PB7_M0PWM1               (Port_PinModeType)(4)
#define PB7_T0CCP1               (Port_PinModeType)(7)

/* PortC PCTL Values. */
#define PC0_TCK                  (Port_PinModeType)(1)
#define PC0_T4CCP0               (Port_PinModeType)(7)

#define PC1_TMS                  (Port_PinModeType)(1)
#define PC1_T4CCP1               (Port_PinModeType)(7)

#define PC2_TDI                  (Port_PinModeType)(1)
#define PC2_T5CCP0               (Port_PinModeType)(7)

#define PC3_TDO                  (Port_PinModeType)(1)
#define PC3_T5CCP1               (Port_PinModeType)(7)

#define PC4_C1NEG                PORT_PIN_AMSEL
#define PC4_U4RX                 (Port_PinModeType)(1)
#define PC4_U1RX                 (Port_PinModeType)(2)
#define PC4_M0PWM6               (Port_PinModeType)(4)
#define PC4_IDX1                 (Port_PinModeType)(6)
#define PC4_WT0CCP0              (Port_PinModeType)(7)
#define PC4_U1RTS                (Port_PinModeType)(8)

#define PC5_C1POS                PORT_PIN_AMSEL
#define PC5_U4TX                 (Port_PinModeType)(1)
#define PC5_U1TX                 (Port_PinModeType)(2)
#define PC5_M0PWM7               (Port_PinModeType)(4)
#define PC5_PHA1                 (Port_PinModeType)(6)
#define PC5_WT0CCP1              (Port_PinModeType)(7)
#define PC5_U1CTS                (Port_PinModeType)(8)

#define PC6_C0POS                PORT_PIN_AMSEL
#define PC6_U3RX                 (Port_PinModeType)(1)
#define PC6_PHB1                 (Port_PinModeType)(6)
#define PC6_WT1CCP0              (Port_PinModeType)(7)
#define PC6_USB0EPEN             (Port_PinModeType)(8)

#define PC7_C0NEG                PORT_PIN_AMSEL
#define PC7_U3TX                 (Port_PinModeType)(1)
#define PC7_WT1CCP1              (Port_PinModeType)(7)
#define PC7_USB0PFLT             (Port_PinModeType)(8)

/* PortD PCTL Values. */
#define PD0_AIN7                 PORT_PIN_AMSEL
#define PD0_SSI3CLK              (Port_PinModeType)(1)
#define PD0_SSI1CLK              (Port_PinModeType)(2)
#define PD0_I2C3SCL              (Port_PinModeType)(3)
#define PD0_M0PWM6               (Port_PinModeType)(4)
#define PD0_M1PWM0               (Port_PinModeType)(5)
#define PD0_WT2CCP0              (Port_PinModeType)(7)

#define PD1_AIN6                 PORT_PIN_AMSEL
#define PD1_SSI3FSS              (Port_PinModeType)(1)
#define PD1_SSI1FSS              (Port_PinModeType)(2)
#define PD1_I2C3SDA              (Port_PinModeType)(3)
#define PD1_M0PWM7               (Port_PinModeType)(4)
#define PD1_M1PWM1               (Port_PinModeType)(5)
#define PD1_WT2CCP1              (Port_PinModeType)(7)

#define PD2_AIN5                 PORT_PIN_AMSEL
#define PD2_SSI3RX               (Port_PinModeType)(1)
#define PD2_SSI1Rx               (Port_PinModeType)(2)
#define PD2_M0FAULT0             (Port_PinModeType)(4)
#define PD2_WT3CCP0              (Port_PinModeType)(7)
#define PD2_USB0EPEN             (Port_PinModeType)(8)

#define PD3_AIN4                 PORT_PIN_AMSEL
#define PD3_SSI3TX               (Port_PinModeType)(1)
#define PD3_SSI1Tx               (Port_PinModeType)(2)
#define PD3_IDX0                 (Port_PinModeType)(6)
#define PD3_WT3CCP1              (Port_PinModeType)(7)
#define PD3_USB0PFLT             (Port_PinModeType)(8)

#define PD4_USB0DM               PORT_PIN_AMSEL
#define PD4_U6RX                 (Port_PinModeType)(1)
#define PD4_WT4CCP0              (Port_PinModeType)(7)

#define PD5_USB0DP               PORT_PIN_AMSEL
#define PD5_U6TX                 (Port_PinModeType)(1)
#define PD5_WT4CCP1              (Port_PinModeType)(7)

#define PD6_U2RX                 (Port_PinModeType)(1)
#define PD6_M0FAULT0             (Port_PinModeType)(4)
#define PD6_PHA0                 (Port_PinModeType)(6)
#define PD6_WT5CCP0              (Port_PinModeType)(7)

#define PD7_U2TX                 (Port_PinModeType)(1)
#define PD7_PHB0                 (Port_PinModeType)(6)
#define PD7_WT5CCP1              (Port_PinModeType)(7)
#define PD7_NMI                  (Port_PinModeType)(8)

/* PortE PCTL Values. */
#define PE0_AIN3                 PORT_PIN_AMSEL
#define PE0_U7RX                 (Port_PinModeType)(1)

#define PE1_AIN2                 PORT_PIN_AMSEL
#define PE1_U7TX                 (Port_PinModeType)(1)

#define PE2_AIN1                 PORT_PIN_AMSEL

#define PE3_AIN0                 PORT_PIN_AMSEL

#define PE4_AIN9                 PORT_PIN_AMSEL
#define PE4_U5RX                 (Port_PinModeType)(1)
#define PE4_I2C2SCL              (Port_PinModeType)(3)
#define PE4_M0PWM4               (Port_PinModeType)(4)
#define PE4_M1PWM2               (Port_PinModeType)(5)
#define PE4_CAN0RX               (Port_PinModeType)(8)

#define PE5_AIN8                 PORT_PIN_AMSEL
#define PE5_U5TX                 (Port_PinModeType)(1)
#define PE5_I2C2SDA              (Port_PinModeType)(3)
#define PE5_M0PWM5               (Port_PinModeType)(4)
#define PE5_M1PWM3               (Port_PinModeType)(5)
#define PE5_CAN0TX               (Port_PinModeType)(8)

/* PortF PCTL Values. */
#define PF0_U1RTS                (Port_PinModeType)(1)
#define PF0_SSI1RX               (Port_PinModeType)(2)
#define PF0_CAN0RX               (Port_PinModeType)(3)
#define PF0_M1PWM4               (Port_PinModeType)(5)
#define PF0_PHA0                 (Port_PinModeType)(6)
#define PF0_T0CCP0               (Port_PinModeType)(7)
#define PF0_NMI                  (Port_PinModeType)(8)
#define PF0_C0O                  (Port_PinModeType)(9)

#define PF1_U1CTS                (Port_PinModeType)(1)
#define PF1_SSI1TX               (Port_PinModeType)(2)
#define PF1_M1PWM5               (Port_PinModeType)(5)
#define PF1_PHB0                 (Port_PinModeType)(6)
#define PF1_T0CCP1               (Port_PinModeType)(7)
#define PF1_C1O                  (Port_PinModeType)(9)
#define PF1_TRD1                 (Port_PinModeType)(14)

#define PF2_SSI1CLK              (Port_PinModeType)(2)
#define PF2_M0FAULT0             (Port_PinModeType)(4)
#define PF2_M1PWM6               (Port_PinModeType)(5)
#define PF2_T1CCP0               (Port_PinModeType)(7)
#define PF2_TRD0                 (Port_PinModeType)(14)

#define PF3_SSI1FSS              (Port_PinModeType)(2)
#define PF3_CAN0TX               (Port_PinModeType)(3)
#define PF3_M1PWM7               (Port_PinModeType)(5)
#define PF3_T1CCP1               (Port_PinModeType)(7)
#define PF3_TRCLK                (Port_PinModeType)(14)

#define PF4_M1FAULT0             (Port_PinModeType)(5)
#define PF4_IDX0                 (Port_PinModeType)(6)
#define PF4_T2CCP0               (Port_PinModeType)(7)
#define PF4_USB0EPEN             (Port_PinModeType)(8)

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct
{
    Port_PinModeType PortPinMode;
    Port_PinLevel PortPinLevelValue;
    Port_PinDirectionType PortPinDirection;
    Port_PinInternalAttachType PortPinInternalAttach;
    Port_PinOutputCurrentType PortPinOutputCurrent;
    Port_Num PortNum;
    Port_PinNum PortPinNum;
}Port_ConfigType;

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

#endif  /* __PORT_LCFG_H__ */
