/*Include*/
#include "LCD.h"

/*LCD_Cfg.h*/
#define LCD_4_BIT	(1)
/*Cfg_End*/

/*Local Macros*/
/*functions states*/
#define Sending_First_Nibble								(1)
#define First_Nibble_Sent									(2)
#define Sending_Second_Nibble								(3)
#define Second_Nibble_Sent									(4)
#define LCD_Pin_Initializing								(5)
#define LCD_Start_Sending_Initialization_Sequence			(6)
#define LCD_Sent_Initialization_Sequence					(7)
#define First_Cmd_In_Initialization_Sequence_Is_Sent		(8)
#define Second_Cmd_In_Initialization_Sequence_Is_Sent		(9)
#define Third_Cmd_In_Initialization_Sequence_Is_Sent		(10)
#define Fourth_Cmd_In_Initialization_Sequence_Is_Sent		(11)
#define Fifth_Cmd_In_Initialization_Sequence_Is_Sent		(12)
#define Sixth_Cmd_In_Initialization_Sequence_Is_Sent		(13)
#define Seventh_Cmd_In_Initialization_Sequence_Is_Sent		(14)
#define Final_Cmd_In_Initialization_Sequence_Is_Sent		(15)
#define Reading_First_Nibble								(16)
#define Reading_Second_Nibble								(17)
#define Reading_Second_Nibble_Done							(18)
#define Sending_Character_Location							(19)
#define CMD_Sending											(20)
#define CMD_Sent											(21)

/*Externed global variables*/
extern const STR_LCD_config_t gastr_LCD_Config[LCD_NUMBER];
extern const STR_LCD_8_config_t gastr_LCD_8_Config[LCD_NUMBER];

/*functions Implementations*/
ERROR_STATE_t LCD_SendCommand(uint8_t CMD)
{
	/*function starting*/
	uint8_t ErrRetVal = OperationStarted;
	/*setting the functions state*/
	uint8_t static State = OperationStarted;
	/*declaring a variable for the timer return*/
	uint8_t TimerRetVal = 1;
	#if LCD_4_BIT
	switch(State)
	{
	case OperationStarted:
		/*sending control signals with configurations of selection of control reg. and write process*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, PIN_LOW);
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, PIN_LOW);
		/*copying upper nibble of the command to the pins*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, READ_BIT(CMD, BIT_4));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, READ_BIT(CMD, BIT_5));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, READ_BIT(CMD, BIT_6));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, READ_BIT(CMD, BIT_7));
		/*writing data to the register by pulling the enable pin high for 1 Us*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_HIGH);
		/*set status of the function*/
		State = Sending_First_Nibble;
		break;
	case Sending_First_Nibble:
		/*start timer delay in background*/
		if(TIMER_E_DELAY_EMPTY == TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand))
		{
   		TIM_DelayUs(TIMER_0, 1, (void (*)(void))LCD_SendCommand);
         while(ERROR_OK != TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand));
         /*if timer delay function finished correctly pull enable pin low*/
         DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_LOW);
         /*update the function's state*/
         State = First_Nibble_Sent;
		}
		break;
	case First_Nibble_Sent:
		/*sending control signals with configurations of selection of control reg. and write process*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port,gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs,PIN_LOW);
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port,gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw,PIN_LOW);
		/*copying lower nibble of the command to the pins*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port,gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4,READ_BIT(CMD,BIT_0));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port,gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5,READ_BIT(CMD,BIT_1));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port,gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6,READ_BIT(CMD,BIT_2));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port,gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7,READ_BIT(CMD,BIT_3));
		/*writing data to the register by pulling the enable pin high for 1 Us*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port,gastr_LCD_Config[LCD_Channel_0].u8_LCD_En,PIN_HIGH);
		/*set status of the function*/
		State = Sending_Second_Nibble;
		break;
	case Sending_Second_Nibble:
		/*start timer delay in background*/
      if(TIMER_E_DELAY_EMPTY == TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand))
      {
         TIM_DelayUs(TIMER_0, 1, (void (*)(void))LCD_SendCommand);
         while(ERROR_OK != TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand));
         /*if timer delay function finished correctly pull enable pin low*/
         DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port,gastr_LCD_Config[LCD_Channel_0].u8_LCD_En,PIN_LOW);
		 /*set status of the function*/
		 State = Second_Nibble_Sent;
      }
		break;
	case Second_Nibble_Sent:
		/*start timer delay in background*/
      TimerRetVal = TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand);
      if(TIMER_E_DELAY_EMPTY == TimerRetVal)
      {
         TIM_DelayMs(TIMER_0,2, (void (*)(void))LCD_SendCommand);
      }         
		if(TimerRetVal == ((uint8_t)ERROR_OK))
		{
			/*reset the function's state*/
			State = OperationStarted;
			/*process finished successfully*/
			ErrRetVal = OperationSuccess;
		}
		break;
	default:
		ErrRetVal = OperationFail;
	}
	/************************************************************************/
	/*						IF LCD is IN 8_BIT MODE                         */
	/************************************************************************/
	#else
	switch (State)
	{
		case OperationStarted:
			/*sending control signals with configurations of selection of control reg. and write process*/
			DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, PIN_LOW);
			DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, PIN_LOW);
			/*Setting the lcd pins*/
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D0,READ_BIT(CMD,BIT_0));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D1,READ_BIT(CMD,BIT_1));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D2,READ_BIT(CMD,BIT_2));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D3,READ_BIT(CMD,BIT_3));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D4,READ_BIT(CMD,BIT_4));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D5,READ_BIT(CMD,BIT_5));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D6,READ_BIT(CMD,BIT_6));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D7,READ_BIT(CMD,BIT_7));
			/*writing data to the register by pulling the enable pin high for 1 Us*/
			DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_HIGH);
			State = CMD_Sending;
			break;
		case CMD_Sending:
			/*start timer delay in background*/
			if(TIMER_E_DELAY_EMPTY == TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand))
			{
				TIM_DelayUs(TIMER_0, 1,(void (*)(void)) LCD_SendCommand);
				while(ERROR_OK != TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand));
				/*if timer delay function finished correctly pull enable pin low*/
				DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_LOW);
				/*update the function's state*/
				State = CMD_Sent;
			}
			break;
		case CMD_Sent:
			/*start timer delay in background*/
			TimerRetVal = TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand);
			if(TIMER_E_DELAY_EMPTY == TimerRetVal)
			{
				TIM_DelayMs(TIMER_0,2, (void (*)(void))LCD_SendCommand);
			}
			if(TimerRetVal == ((uint8_t)ERROR_OK))
			{
				ErrRetVal = OperationSuccess;
				State = OperationStarted;
			}
			break;
		default:
			ErrRetVal = OperationFail;
			break;
	}
	#endif
	/*return from function*/
	return ErrRetVal;
}



ERROR_STATE_t LCD_SendData(uint8_t Character)
{
	/*function starting*/
	uint8_t ErrRetVal = OperationStarted;
	/*setting the functions state*/
	uint8_t static State = OperationStarted;
	#if LCD_4_BIT
	switch (State) {
	case OperationStarted:
		/*sending control signals with configurations of selection of control reg. and write process*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, PIN_HIGH);
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, PIN_LOW);
		/*copying upper nibble of the command to the pins*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, READ_BIT(Character, BIT_7));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, READ_BIT(Character, BIT_6));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, READ_BIT(Character, BIT_5));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, READ_BIT(Character, BIT_4));
		/*writing data to the register by pulling the enable pin high for 1 Us*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_HIGH);
		/*set status of the function*/
		State = Sending_First_Nibble;
		break;
	case Sending_First_Nibble:
		/*start timer delay in background*/
      if(TIMER_E_DELAY_EMPTY == TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand))
      {
         TIM_DelayUs(TIMER_0, 1,(void (*)(void)) LCD_SendCommand);
         while(ERROR_OK != TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand));
         /*if timer delay function finished correctly pull enable pin low*/
         DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_LOW);
         /*update the function's state*/
         State = First_Nibble_Sent;
      }
		break;
	case First_Nibble_Sent:
		/*sending control signals with configurations of selection of control reg. and write process*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, PIN_HIGH);
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, PIN_LOW);
		/*copying lower nibble of the command to the pins*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, READ_BIT(Character, BIT_3));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, READ_BIT(Character, BIT_2));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, READ_BIT(Character, BIT_1));
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, READ_BIT(Character, BIT_0));

		/*writing data to the register by pulling the enable pin high for 1 Us*/
		DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_HIGH);
		/*set status of the function*/
		State = Sending_Second_Nibble;
		break;
	case Sending_Second_Nibble:
		/*start timer delay in background*/
      if(TIMER_E_DELAY_EMPTY == TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand))
      {
         TIM_DelayUs(TIMER_0, 1, (void (*)(void))LCD_SendCommand);
         while(ERROR_OK != TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand));
         /*if timer delay function finished correctly pull enable pin low*/
         DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_LOW);
         /*reset the function's state*/
         State = OperationStarted;
         /*process finished successfully*/
         ErrRetVal = OperationSuccess;
      }
		break;
	default:
		ErrRetVal = OperationFail;
	}
	/************************************************************************/
	/*                     8_Bit Mode send data Function                    */
	/************************************************************************/
	#else
	switch (State)
	{
		case OperationStarted:
			/*sending control signals with configurations of selection of control reg. and write process*/
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_CTRL_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_Rs, PIN_HIGH);
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_CTRL_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_Rw, PIN_LOW);
			/*Setting the lcd pins*/
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D0,READ_BIT(Character,BIT_0));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D1,READ_BIT(Character,BIT_1));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D2,READ_BIT(Character,BIT_2));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D3,READ_BIT(Character,BIT_3));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D4,READ_BIT(Character,BIT_4));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D5,READ_BIT(Character,BIT_5));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D6,READ_BIT(Character,BIT_6));
			DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port,gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D7,READ_BIT(Character,BIT_7));
			/*writing data to the register by pulling the enable pin high for 1 Us*/
			DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_HIGH);
			State = CMD_Sending;
			break;
		case CMD_Sending:
			/*start timer delay in background*/
			if(TIMER_E_DELAY_EMPTY == TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand))
			{
				TIM_DelayUs(TIMER_0, 1, (void (*)(void))LCD_SendCommand);
				while(ERROR_OK != TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand));
				/*if timer delay function finished correctly pull enable pin low*/
				DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_LOW);
				/*reset the function's state*/
				State = OperationStarted;
				/*process finished successfully*/
				ErrRetVal = OperationSuccess;
			}
			break;
		default:
		ErrRetVal = OperationFail;
		break;
	}
	#endif
	/*return from function*/
	return ErrRetVal;
}




ERROR_STATE_t LCD_Init()
{
	/*function starting*/
	uint8_t ErrRetVal = OperationStarted;
	/*setting the functions state*/
	uint8_t static State = OperationStarted;
	/*declaring a variable for the timer return*/
	uint8_t TimerRetVal = 1;
	uint8_t LCD_SendCommandRetVal = OperationStarted;
	#if LCD_4_BIT
	switch (State) {
	case OperationStarted:
		/*Dio and Timer Initialize for the*/
		TIM_Init(TIMER_0);
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
		TimerRetVal = TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand);
		if(TIMER_E_DELAY_EMPTY == TimerRetVal)
		{
   		TIM_DelayMs(TIMER_0,15, (void (*)(void))LCD_SendCommand);
		}
		if(TimerRetVal == ((uint8_t)ERROR_OK))
		{
   		/*if timer delay function finished correctly Start the initialization sequence*/
   		State = LCD_Start_Sending_Initialization_Sequence;
		}
		break;
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
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_INCREMENTENTRYMODE);//LCD_INCREMENTENTRYMODE/LCD_SHIFTINCREMENTENTRYMODE
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
	/************************************************************************/
	/*                 8_Bit Mode initialization Function                   */
	/************************************************************************/
	#else
	/*Starting the initialization sequence*/
	switch(State)
	{
		case OperationStarted:
		/*Initialize timer2*/
		TIM_Init(TIMER_0);
		/*Initializing the LCD Data Pins*/
		DIO_SetPinDirection(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D7, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D6, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D5, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D4, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D3, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D2, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D1, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D0, PIN_OUTPUT);
		/*Initializing the LCD CTRL Pins*/
		DIO_SetPinDirection(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_CTRL_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_Rs, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_CTRL_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_Rw, PIN_OUTPUT);
		DIO_SetPinDirection(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_CTRL_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_En, PIN_OUTPUT);
		/*setting initial value for LCD Pins*/
		DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D7, PIN_LOW);
		DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D6, PIN_LOW);
		DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D5, PIN_LOW);
		DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D4, PIN_LOW);
		DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D3, PIN_LOW);
		DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D2, PIN_LOW);
		DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D1, PIN_LOW);
		DIO_WritePin(gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_DATA_Port, gastr_LCD_8_Config[LCD_Channel_0].u8_LCD_D0, PIN_LOW);
		State = LCD_Pin_Initializing;
	case LCD_Pin_Initializing:
		/*start timer delay in background*/
		TimerRetVal = TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_SendCommand);
		if(TIMER_E_DELAY_EMPTY == TimerRetVal)
		{
			TIM_DelayMs(TIMER_0,15, (void (*)(void))LCD_SendCommand);
		}
		if(TimerRetVal == ((uint8_t)ERROR_OK))
		{
			/*if timer delay function finished correctly Start the initialization sequence*/
			State = LCD_Start_Sending_Initialization_Sequence;
		}
		break;
		case LCD_Start_Sending_Initialization_Sequence:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_Init_CMD_8_BIT);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = First_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
		case First_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_Init_CMD_8_BIT);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Second_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
		case Second_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_Init_CMD_8_BIT);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Third_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
		case Third_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_FUNCSET_3);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Fourth_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
		case Fourth_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_DISPON_CURSOFF);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Fifth_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
		case Fifth_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_CLR);
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
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_CURS_Position0);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = Final_Cmd_In_Initialization_Sequence_Is_Sent;
		}
		break;
		case Final_Cmd_In_Initialization_Sequence_Is_Sent:
		LCD_SendCommandRetVal = LCD_SendCommand(LCD_HOME);
		if(LCD_SendCommandRetVal == OperationSuccess)
		{
			State = OperationStarted;
			ErrRetVal = OperationSuccess;
		}
		break;
		default:
		ErrRetVal = OperationFail;
		break;
	}
	#endif
	return ErrRetVal;
}




ERROR_STATE_t LCD_SendString(const uint8_t* String)
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





ERROR_STATE_t LCD_SendNumber(uint32_t Number)
{
	/*urgent a blocking function*/
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





ERROR_STATE_t LCD_ReadDispLoc(uint8_t Location, uint8_t* Data)
{
	uint8_t ErrRetVal = OperationStarted;
	uint8_t BitVal = 0;
	uint8_t static State = Sending_Character_Location;
	uint8_t static Character = 0;
	switch(State)
	{
		case Sending_Character_Location:
		if(LCD_SendCommand(Location) == OperationSuccess)
		{
			State = OperationStarted;
		}
		break;
		case OperationStarted:
			Character = 0;
			/*Dio Initialize for the*/
			DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, PIN_INPUT);
			DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, PIN_INPUT);
			DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, PIN_INPUT);
			DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, PIN_INPUT);
			DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, PIN_OUTPUT);
			DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, PIN_OUTPUT);
			DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_OUTPUT);
			/*sending control signals with configurations of selection of control reg. and write process*/
			DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, PIN_HIGH);
			DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, PIN_HIGH);
			/*writing data to the register by pulling the enable pin high for 1 Us*/
			DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_HIGH);
			/*getting first nibble*/
			DIO_ReadPin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, &BitVal);
			(Character) |= BitVal;
			(Character) <<= 1;
			DIO_ReadPin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, &BitVal);
			(Character) |= BitVal;
			(Character) <<= 1;
			DIO_ReadPin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, &BitVal);
			(Character) |= BitVal;
			(Character) <<= 1;
			DIO_ReadPin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, &BitVal);
			(Character) |= BitVal;
			(Character) <<= 1;
			/*set status of the function*/
			State = Reading_First_Nibble;
		case Reading_First_Nibble:
		/*start timer delay in background*/
			if(TIMER_E_DELAY_EMPTY == TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_ReadDispLoc))
			{
				TIM_DelayUs(TIMER_0, 1, (void (*)(void))LCD_ReadDispLoc);
				while(ERROR_OK != TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_ReadDispLoc));
				/*if timer delay function finished correctly pull enable pin low*/
				DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_LOW);
				State = Reading_Second_Nibble;
			}
		break;
		case Reading_Second_Nibble:
			/*sending control signals with configurations of selection of control reg. and write process*/
			DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rs, PIN_HIGH);
			DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_Rw, PIN_HIGH);
			/*writing data to the register by pulling the enable pin high for 1 Us*/
			DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_HIGH);
			/*getting first nibble*/
			DIO_ReadPin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, &BitVal);
			(Character) |= BitVal;
			(Character) <<= 1;
			DIO_ReadPin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, &BitVal);
			(Character) |= BitVal;
			(Character) <<= 1;
			DIO_ReadPin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, &BitVal);
			(Character) |= BitVal;
			(Character) <<= 1;
			DIO_ReadPin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, &BitVal);
			(Character) |= BitVal;
			/*set status of the function*/
			State = Reading_Second_Nibble_Done;
			case Reading_Second_Nibble_Done:
			/*start timer delay in background*/
			if(TIMER_E_DELAY_EMPTY == TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_ReadDispLoc))
			{
				TIM_DelayUs(TIMER_0, 1, (void (*)(void))LCD_ReadDispLoc);
				while(ERROR_OK != TIM_DelayStatus(TIMER_0, (void (*)(void))LCD_ReadDispLoc));
				/*if timer delay function finished correctly pull enable pin low*/
				DIO_WritePin(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_En, PIN_LOW);
				/*reset the function's state*/
				State = Sending_Character_Location;
				/*process finished successfully*/
				ErrRetVal = OperationSuccess;
				DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D7, PIN_OUTPUT);
				DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D6, PIN_OUTPUT);
				DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D5, PIN_OUTPUT);
				DIO_SetPinDirection(gastr_LCD_Config[LCD_Channel_0].u8_LCD_Port, gastr_LCD_Config[LCD_Channel_0].u8_LCD_D4, PIN_OUTPUT);
				*Data = Character;
			}
	}
	return ErrRetVal;
}

			