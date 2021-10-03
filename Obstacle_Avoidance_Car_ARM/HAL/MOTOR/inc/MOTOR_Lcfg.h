/*
 * MOTOR_Lcfg.h
 *
 * Created: 8/12/2021 11:25:46 AM
 *  Author: Ahmed Essam
 */ 




#ifndef __MOTOR_LCFG_H__
#define __MOTOR_LCFG_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_TYPES.h"
#include "DIO.h"

/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_MOTOR_config_t{
   uint8_t u8_MotorPortDirA;
   uint8_t u8_MotorPinDirA;
   uint8_t u8_MotorPortDirB;
   uint8_t u8_MotorPinDirB;
} STR_MOTOR_config_t;

/*- MACROS -------------------------------------------------*/
#define  MOTORS_NUMBER              (uint8_t)( 2 )

//MOTORS PORRTS
#define MOTOR1_PORT_DIR_A           PORT_C
#define MOTOR1_PORT_DIR_B           PORT_C
#define MOTOR2_PORT_DIR_A           PORT_C
#define MOTOR2_PORT_DIR_B           PORT_C
//MOTORS PINS
#define MOTOR1_PIN_DIR_A            PIN1
#define MOTOR1_PIN_DIR_B            PIN2
#define MOTOR2_PIN_DIR_A            PIN4
#define MOTOR2_PIN_DIR_B            PIN5
#endif /* __MOTOR_LCFG_H__ */