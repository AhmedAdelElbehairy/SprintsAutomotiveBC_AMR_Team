#include "LCD.h"
#include "UTILS.h"
#include "Bit_Math.h"

/*Local Macros*/
/*functions states*/
#define Sending_First_Nibble										      (1)
#define First_Nibble_Sent											      (2)
#define Sending_Second_Nibble										      (3)
#define Second_Nibble_Sent											      (4)
#define LCD_Pin_Initializing										      (5)
#define LCD_Start_Sending_Initialization_Sequence					(6)
#define LCD_Sent_Initialization_Sequence							   (7)
#define First_Cmd_In_Initialization_Sequence_Is_Sent				(8)
#define Second_Cmd_In_Initialization_Sequence_Is_Sent				(9)
#define Third_Cmd_In_Initialization_Sequence_Is_Sent				(10)
#define Fourth_Cmd_In_Initialization_Sequence_Is_Sent				(11)
#define Fifth_Cmd_In_Initialization_Sequence_Is_Sent				(12)
#define Sixth_Cmd_In_Initialization_Sequence_Is_Sent				(13)
#define Seventh_Cmd_In_Initialization_Sequence_Is_Sent			(14)
#define Final_Cmd_In_Initialization_Sequence_Is_Sent				(15)

/*Externed global variables*/
extern const STR_LCD_config_t gastr_LCD_Config[LCD_NUMBER];
volatile uint32_t i;
Std_ReturnType LCD_SendCommand(uint8_t CMD)
{
	/*function starting*/
	uint8_t ErrRetVal = OperationStarted;
	/*setting the functions state*/
	uint8_t static State = OperationStarted;
	switch(State)
	{
	case OperationStarted:
		/*sending control signals with configurations of selection of control reg. and write process*/
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, STD_LOW);
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, STD_LOW);

		/*copying upper nibble of the command to the pins*/
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, BIT_IS_SET(CMD, BIT_4));
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, BIT_IS_SET(CMD, BIT_5));
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, BIT_IS_SET(CMD, BIT_6));
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, BIT_IS_SET(CMD, BIT_7));


		/*writing data to the register by pulling the enable pin high for 1 Us*/
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, STD_HIGH);
		/*set status of the function*/
		State = Sending_First_Nibble;
		break;
	case Sending_First_Nibble:
        /*if timer delay function finished correctly pull enable pin low*/
        Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, STD_LOW);
        /*update the function's state*/
        State = First_Nibble_Sent;
		break;
	case First_Nibble_Sent:
		/*sending control signals with configurations of selection of control reg. and write process*/
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs,STD_LOW);
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw,STD_LOW);

		/*copying lower nibble of the command to the pins*/

	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4,BIT_IS_SET(CMD,BIT_0));
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5,BIT_IS_SET(CMD,BIT_1));
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6,BIT_IS_SET(CMD,BIT_2));
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7,BIT_IS_SET(CMD,BIT_3));
		/*writing data to the register by pulling the enable pin high for 1 Us*/
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_En,STD_HIGH);
		/*set status of the function*/
		State = Sending_Second_Nibble;
		break;
	case Sending_Second_Nibble:
         /*if timer delay function finished correctly pull enable pin low*/
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_En,STD_LOW);
         /*reset the function's state*/
         State = Second_Nibble_Sent;
		break;
	case Second_Nibble_Sent:
			/*reset the function's state*/
			State = OperationStarted;
			/*process finished successfully*/
			ErrRetVal = OperationSuccess;
		break;
	default:
		ErrRetVal = OperationFail;
	}
	/*return from function*/
	return ErrRetVal;
}
Std_ReturnType LCD_SendData(uint8_t Character)
{
	/*function starting*/
	uint8_t ErrRetVal = OperationStarted;
	/*setting the functions state*/
	uint8_t static State = OperationStarted;
	switch (State) {
	case OperationStarted:
		/*sending control signals with configurations of selection of control reg. and write process*/
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, STD_HIGH);
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, STD_LOW);
		/*copying upper nibble of the command to the pins*/
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, BIT_IS_SET(Character, BIT_7));
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, BIT_IS_SET(Character, BIT_6));
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, BIT_IS_SET(Character, BIT_5));
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, BIT_IS_SET(Character, BIT_4));

		/*writing data to the register by pulling the enable pin high for 1 Us*/
		Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, STD_HIGH);
		/*set status of the function*/
		State = Sending_First_Nibble;
		break;
	case Sending_First_Nibble:
         /*if timer delay function finished correctly pull enable pin low*/
	    Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, STD_LOW);
         /*update the function's state*/
         State = First_Nibble_Sent;
		break;
	case First_Nibble_Sent:
		/*sending control signals with configurations of selection of control reg. and write process*/
		Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, STD_HIGH);
		Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, STD_LOW);
		/*copying lower nibble of the command to the pins*/
		Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, BIT_IS_SET(Character, BIT_3));
		Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, BIT_IS_SET(Character, BIT_2));
		Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, BIT_IS_SET(Character, BIT_1));
		Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, BIT_IS_SET(Character, BIT_0));

		/*writing data to the register by pulling the enable pin high for 1 Us*/
		Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, STD_HIGH);
		/*set status of the function*/
		State = Sending_Second_Nibble;
		break;
	case Sending_Second_Nibble:
         /*if timer delay function finished correctly pull enable pin low*/
         Dio_WriteChannel(gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, STD_LOW);
         /*reset the function's state*/
         State = OperationStarted;
         /*process finished successfully*/
         ErrRetVal = OperationSuccess;
		break;
	default:
		ErrRetVal = OperationFail;
	}
	/*return from function*/
	return ErrRetVal;

}
Std_ReturnType LCD_Init()
{
	/*function starting*/
	uint8_t ErrRetVal = OperationStarted;
	/*setting the functions state*/
	uint8_t static State = LCD_Start_Sending_Initialization_Sequence;
	uint8_t LCD_SendCommandRetVal = OperationStarted;
	switch (State) {
#if 0
	case OperationStarted:
		/*Dio Initialize for the*/
		TIM_Init(TIMER_2);
		DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_OUTPUT);
		/*setting initial value for LCD Pins*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, PIN_LOW);
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, PIN_LOW);
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, PIN_LOW);
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, PIN_LOW);
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, PIN_LOW);
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, PIN_LOW);
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_LOW);
		/*set status of the function*/
		State = LCD_Pin_Initializing;
		break;
	case LCD_Pin_Initializing:
		/*start timer delay in background*/
		TimerRetVal = TIM_DelayStatus(TIMER_2, LCD_SendCommand);
		if(TIMER_E_DELAY_EMPTY == TimerRetVal)
		{
   		TIM_DelayMs(TIMER_2,15, LCD_SendCommand);
		}
		if(TimerRetVal == ((uint8_t)ERROR_OK))
		{
   		/*if timer delay function finished correctly Start the initialization sequence*/
   		State = LCD_Start_Sending_Initialization_Sequence;
		}
		break;
#endif
	case LCD_Start_Sending_Initialization_Sequence:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_Init_CMD_1);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = First_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
	case First_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_Init_CMD_1);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Second_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
	case Second_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_Init_CMD_1);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Third_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
	case Third_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_HOME);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Fourth_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
	case Fourth_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_FUNCSET_6);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Fifth_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
	case Fifth_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_DISPON_CURSBLINK);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Sixth_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
	case Sixth_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_INCREMENTENTRYMODE);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Seventh_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
	case Seventh_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_CLR);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Final_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
	case Final_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_CURS_Position0);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = OperationStarted;
			ErrRetVal = OperationSuccess;
		}
		break;
	default:
		ErrRetVal = OperationFail;
	}
	return ErrRetVal;
}
Std_ReturnType LCD_SendString(const uint8_t* String)
{
	uint8_t ErrRetVal = OperationStarted;
	uint8_t LCD_SendDataRetVal = OperationStarted;
	static uint8_t Number = 0;
	if (String != NULL_PTR) {
		if (String[Number] != NULL_TERMINATOR ) {
			ErrRetVal = OperationRunning;
			LCD_SendDataRetVal = LCD_SendData(String[Number]);
			if(LCD_SendDataRetVal == OperationSuccess)
			{
				Number++;
			}
		}
		else
		{
			Number = 0;
			ErrRetVal = OperationSuccess;
		}
	} else {
		ErrRetVal = OperationFail;
	}
	return ErrRetVal;
}
Std_ReturnType LCD_SendNumber(uint32_t Number)
{
	uint8_t ErrRetVal = OperationStarted;
	uint8_t FunRetVal = OperationStarted;
	uint8_t String[10];
	STR_Number2String((uint32_t)Number,String);
	while(FunRetVal != OperationSuccess)
   {
      FunRetVal = LCD_SendString((uint8_t*)String);
      if(FunRetVal == OperationSuccess)
      {
         ErrRetVal = OperationSuccess;
      }
      else
      {
         ErrRetVal = OperationFail;
      }
   }
	return ErrRetVal;
}
