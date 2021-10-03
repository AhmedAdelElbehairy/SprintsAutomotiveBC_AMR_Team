/*
 * MOTOR_Lcfg.c
 *
 * Created: 8/12/2021 11:28:48 AM
 *  Author: Ahmed Essam
 */ 

/*- INCLUDES
----------------------------------------------*/
#include "MOTOR_Lcfg.h"


const STR_MOTOR_config_t gastr_Motor_Config[MOTORS_NUMBER] = {
   {MOTOR1_PORT_DIR_A, MOTOR1_PIN_DIR_A, MOTOR1_PORT_DIR_B, MOTOR1_PIN_DIR_B},
   {MOTOR2_PORT_DIR_A, MOTOR2_PIN_DIR_A, MOTOR2_PORT_DIR_B, MOTOR2_PIN_DIR_B},
};