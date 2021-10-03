/*INCLUDES-------------------------------*/
#include "MOTOR.h"

/*----GLOBAL STATIC VARIABLES----*/
static ERROR_STATE_t gu8_ERROR_STAT = ERROR_OK;
static uint8_t gu8_InitFlag = NOT_INIT;
extern const STR_MOTOR_config_t gastr_Motor_Config[MOTORS_NUMBER];

/*APIs IMPLEMENTATION------------------------*/
ERROR_STATE_t MOTOR_init(void) {
		/*CHECK IF MOTORS HAS BEEN INITIALIZED*/
	if (INIT == gu8_InitFlag) {//IF MOTORS IS INITIALIZED
		gu8_ERROR_STAT = MOTOR_SEC_INIT;//STORE SEC INIT IN ERRROR STAT
	} else if (NOT_INIT == gu8_InitFlag) {//IF MOTORS IS NOT INITIALIZED
	PWM_Init(PWM_CHANNEL_OC0);
   /*SETTING MOTOR1 DIR PINS TO OUTPUT*/
	DIO_SetPinDirection(gastr_Motor_Config[MOTOR1].u8_MotorPortDirA, gastr_Motor_Config[MOTOR1].u8_MotorPinDirA, PIN_OUTPUT);
	DIO_SetPinDirection(gastr_Motor_Config[MOTOR1].u8_MotorPortDirB, gastr_Motor_Config[MOTOR1].u8_MotorPinDirB, PIN_OUTPUT);
	/*SETTING MOTOR2 DIR PINS TO OUTPUT*/
	
	DIO_SetPinDirection(gastr_Motor_Config[MOTOR2].u8_MotorPortDirA, gastr_Motor_Config[MOTOR2].u8_MotorPinDirA, PIN_OUTPUT);
	DIO_SetPinDirection(gastr_Motor_Config[MOTOR2].u8_MotorPortDirB, gastr_Motor_Config[MOTOR2].u8_MotorPinDirB, PIN_OUTPUT);
   /*START THE PWM WAVE*/
   PWM_Start(PWM_CHANNEL_OC0);
	gu8_InitFlag = INIT;//SET INIT FLAG
	gu8_ERROR_STAT = ERROR_OK;//STORE ERROR_OK IN ERRROR STAT
	}
	/*STOP MOTOER EN PINS AT THE START*/
	return gu8_ERROR_STAT ;//RETURN FROM THE API
}
ERROR_STATE_t MOTOR_start(uint8_t motor_no, uint8_t speed,  uint8_t dir) {
	if (NOT_INIT == gu8_InitFlag) { //IF MOTOR IS NOT INITIALIZED
		gu8_ERROR_STAT = MOTOR_NOT_INIT; //STORE NOT INIT IN ERRROR STAT
	} else if (INIT == gu8_InitFlag) { //IF MOTOR IS INITIALIZED
      PWM_SetDuty(PWM_CHANNEL_OC0, speed);
      PWM_Connect(PWM_CHANNEL_OC0);
	switch (motor_no) {
	case MOTOR1 :
		switch (dir) {
		case MOTOR_FORWARD :
			DIO_WritePin(gastr_Motor_Config[MOTOR1].u8_MotorPortDirA, gastr_Motor_Config[MOTOR1].u8_MotorPinDirA,PIN_HIGH);
			DIO_WritePin(gastr_Motor_Config[MOTOR1].u8_MotorPortDirB, gastr_Motor_Config[MOTOR1].u8_MotorPinDirB,PIN_LOW);
			gu8_ERROR_STAT = ERROR_OK;
			break;
		case MOTOR_BACKWARD :
			DIO_WritePin(gastr_Motor_Config[MOTOR1].u8_MotorPortDirA, gastr_Motor_Config[MOTOR1].u8_MotorPinDirA,PIN_LOW);
			DIO_WritePin(gastr_Motor_Config[MOTOR1].u8_MotorPortDirB, gastr_Motor_Config[MOTOR1].u8_MotorPinDirB,PIN_HIGH);
            gu8_ERROR_STAT = ERROR_OK;

			break;
		default:
		gu8_ERROR_STAT=MOTOR_INVALID_DIR;
			break;
		}
		break;
	case MOTOR2 :
		switch (dir) {
		case MOTOR_FORWARD :
			DIO_WritePin(gastr_Motor_Config[MOTOR2].u8_MotorPortDirA, gastr_Motor_Config[MOTOR2].u8_MotorPinDirA,PIN_HIGH);
			DIO_WritePin(gastr_Motor_Config[MOTOR2].u8_MotorPortDirB, gastr_Motor_Config[MOTOR2].u8_MotorPinDirB,PIN_LOW);
            gu8_ERROR_STAT = ERROR_OK;

			break;
		case MOTOR_BACKWARD :
			DIO_WritePin(gastr_Motor_Config[MOTOR2].u8_MotorPortDirA, gastr_Motor_Config[MOTOR2].u8_MotorPinDirA,PIN_LOW);
			DIO_WritePin(gastr_Motor_Config[MOTOR2].u8_MotorPortDirB, gastr_Motor_Config[MOTOR2].u8_MotorPinDirB,PIN_HIGH);
            gu8_ERROR_STAT = ERROR_OK;

			break;
		default:
		gu8_ERROR_STAT=MOTOR_INVALID_DIR;
			break;
		}
		break;
	default:
	gu8_ERROR_STAT=MOTOR_INVALID_CH;
		break;
	}
	}
	return gu8_ERROR_STAT ;
}
ERROR_STATE_t MOTOR_stop(uint8_t motor_no) {
    if (NOT_INIT == gu8_InitFlag) { //IF MOTOR IS NOT INITIALIZED
		gu8_ERROR_STAT = MOTOR_NOT_INIT; //STORE NOT INIT IN ERRROR STAT
        } else if (INIT == gu8_InitFlag) { //IF MOTOR IS INITIALIZED
		PWM_Disconnect(PWM_CHANNEL_OC0);
       switch (motor_no){
        case MOTOR1:
            DIO_WritePin(gastr_Motor_Config[MOTOR1].u8_MotorPortDirA, gastr_Motor_Config[MOTOR1].u8_MotorPinDirA,PIN_HIGH);
            DIO_WritePin(gastr_Motor_Config[MOTOR1].u8_MotorPortDirB, gastr_Motor_Config[MOTOR1].u8_MotorPinDirB,PIN_HIGH);
            gu8_ERROR_STAT = ERROR_OK;
            break;
        case MOTOR2:
            DIO_WritePin(gastr_Motor_Config[MOTOR2].u8_MotorPortDirA, gastr_Motor_Config[MOTOR2].u8_MotorPinDirA,PIN_HIGH);
            DIO_WritePin(gastr_Motor_Config[MOTOR2].u8_MotorPortDirB, gastr_Motor_Config[MOTOR2].u8_MotorPinDirB,PIN_HIGH);
            gu8_ERROR_STAT = ERROR_OK;
            break;
        default:
        gu8_ERROR_STAT=MOTOR_INVALID_CH;
            break;
        }
	}
	return gu8_ERROR_STAT ;
}
ERROR_STATE_t MOTOR_Update_dir(uint8_t motor_no, uint8_t dir) {
    if (NOT_INIT == gu8_InitFlag) { //IF MOTOR IS NOT INITIALIZED
    gu8_ERROR_STAT = MOTOR_NOT_INIT; //STORE NOT INIT IN ERRROR STAT
    } else if (INIT == gu8_InitFlag) { //IF MOTOR IS INITIALIZED
        switch (motor_no) {
            case MOTOR1 :
                switch (dir) {
                case MOTOR_FORWARD :
                DIO_WritePin(gastr_Motor_Config[MOTOR1].u8_MotorPortDirA, gastr_Motor_Config[MOTOR1].u8_MotorPinDirA,PIN_HIGH);
                DIO_WritePin(gastr_Motor_Config[MOTOR1].u8_MotorPortDirB, gastr_Motor_Config[MOTOR1].u8_MotorPinDirB,PIN_LOW);
                gu8_ERROR_STAT = ERROR_OK;

                    break;
                case MOTOR_BACKWARD :
                DIO_WritePin(gastr_Motor_Config[MOTOR1].u8_MotorPortDirA, gastr_Motor_Config[MOTOR1].u8_MotorPinDirA,PIN_LOW);
                DIO_WritePin(gastr_Motor_Config[MOTOR1].u8_MotorPortDirB, gastr_Motor_Config[MOTOR1].u8_MotorPinDirB,PIN_HIGH);
                gu8_ERROR_STAT = ERROR_OK;

                    break;
                default:
                gu8_ERROR_STAT=MOTOR_INVALID_DIR;
                    break;
                }
                break;
            case MOTOR2 :
                switch (dir) {
                case MOTOR_FORWARD :
                DIO_WritePin(gastr_Motor_Config[MOTOR2].u8_MotorPortDirA, gastr_Motor_Config[MOTOR2].u8_MotorPinDirA,PIN_HIGH);
                DIO_WritePin(gastr_Motor_Config[MOTOR2].u8_MotorPortDirB, gastr_Motor_Config[MOTOR2].u8_MotorPinDirB,PIN_LOW);
                gu8_ERROR_STAT = ERROR_OK;

                    break;
                case MOTOR_BACKWARD :
                DIO_WritePin(gastr_Motor_Config[MOTOR2].u8_MotorPortDirA, gastr_Motor_Config[MOTOR2].u8_MotorPinDirA,PIN_LOW);
                DIO_WritePin(gastr_Motor_Config[MOTOR2].u8_MotorPortDirB, gastr_Motor_Config[MOTOR2].u8_MotorPinDirB,PIN_HIGH);
                gu8_ERROR_STAT = ERROR_OK;

                    break;
                default:
                   gu8_ERROR_STAT=MOTOR_INVALID_DIR;
                    break;
                }
                break;
            default:
               gu8_ERROR_STAT=MOTOR_INVALID_CH;
                break;
            }
    }

		return gu8_ERROR_STAT ;
}
