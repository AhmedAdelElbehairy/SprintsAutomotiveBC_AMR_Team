
/*
 * DISPLAY.c
 *
 * Created: 9/7/2021 6:37:39 PM
 *  Author: Ahmed Adel
 */ 
#include "LCD_DISPLAY.h"
/*Macros*/
#define DISPLAY_WIDTH					(16)
#define SystemLoading_StringWidth		(14)
#define Welcome_StringWidth				(7 )
#define EnterPass_StringWidth			(10)
#define CorrectPass_StringWidth			(7 )
#define WrongPass_StringWidth			(10)
#define Waiting_StringWidth				(7 )
#define SystemOn_StringWidth			(12)
#define ChangePassword_StringWidth		(13)
#define MainFunction_Periodicity		(50Ul)
#define TenSeconds						(10000Ul)
#define TwoSeconds						(2000Ul)

uint8_t Position = 0;
/*Moving to the interface files*/
uint8_t Number_of_Asteriks = 0;
uint8_t Shifting_State = OperationStarted;//OperationStarted
uint8_t LastShiftingState = OperationStarted;
uint8_t WrongPassEntries = 0;
uint32_t RemainingSeconds = 0;

void DISPLAY_MainFunction(void)
{
	uint8_t static Last_state = OperationStarted;
	uint8_t static Counter = 0;
	uint8_t State =0;
	DISPLAY_GetNumber_of_Asterisk(&Number_of_Asteriks);
	DISPLAY_GetState(&State);
	if((Last_state == CorrectPassword || Last_state == WrongPassword || Last_state == Waiting)&&(Counter!=0))
	{
		State = Last_state;
	}
	switch(State)
	{
		case SystemLoading:
			if(Last_state != State)
			{
				Position = 0;
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while(LCD_SendString((uint8_t*)"System Loading") != OperationSuccess);
				Shifting_State = ShiftingRight;
			}
			DISPLAY_START_SHIFTING(SystemLoading_StringWidth,0);
			break;
		case Welcome:
			if(Last_state != State)
			{
				Position = 0;
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while(LCD_SendString((uint8_t*)"WELCOME") != OperationSuccess);
				Shifting_State = ShiftingRight;
			}
			DISPLAY_START_SHIFTING(Welcome_StringWidth,0);
			break;
		case PassEntering:
			if(Last_state != State)
			{
				Position = DISPLAY_WIDTH-EnterPass_StringWidth;
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendCommand(LCD_CURS_Position0|Position)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"Enter Pass") != OperationSuccess);
				Shifting_State = ShiftingLeft;
				while (LCD_SendCommand(LCD_CURS_LINE2)!=OperationSuccess);
				for(uint8_t i = 0; i < Number_of_Asteriks; i++)
				{
					while(LCD_SendData('*')!= OperationSuccess);
					if (i>5)
					{
						break;
					}
				}
			}
			DISPLAY_START_SHIFTING(EnterPass_StringWidth,Number_of_Asteriks);
			break;
		case CorrectPassword:
			if(Last_state != State)
			{
				Position = 0;
				DISPLAY_SetNumber_of_Asterisk(0);
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"Pass OK") != OperationSuccess);
				Shifting_State = ShiftingRight;
			}
			DISPLAY_START_SHIFTING(CorrectPass_StringWidth,0);
			Counter ++;
			if(Counter == (uint8_t)(TwoSeconds/MainFunction_Periodicity))
			{
				WrongPassEntries = 0;
				Counter = 0;
				DISPLAY_SetState(SevenSegments);
			}
			break;
		/*Counter*/
		case WrongPassword:
			if(Last_state != State)
			{
				Position = 0;
				DISPLAY_SetNumber_of_Asterisk(0);
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"Wrong Pass") != OperationSuccess);
				Shifting_State = ShiftingRight;
			}
			DISPLAY_START_SHIFTING(WrongPass_StringWidth,0);
			Counter ++;
			if(Counter == (uint8_t)(TwoSeconds/MainFunction_Periodicity))
			{
				Counter = 0;
				WrongPassEntries++;
				if(WrongPassEntries==3)
					DISPLAY_SetState(Waiting);
				else
					DISPLAY_SetState(PassEntering);
			}
			break;
		case Waiting:
			if(Last_state != State)
			{
				Position = DISPLAY_WIDTH - Waiting_StringWidth;
				DISPLAY_SetNumber_of_Asterisk(0);
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendCommand(LCD_CURS_Position0|Position)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"Waiting") != OperationSuccess);
				Shifting_State = ShiftingLeft;
				LastShiftingState = Shifting_State;
				while (LCD_SendCommand(LCD_CURS_LINE2)!=OperationSuccess);
			}
			RemainingSeconds = ((TenSeconds-(Counter*MainFunction_Periodicity))/1000);
			Counter ++;
			DISPLAY_START_SHIFTING(Waiting_StringWidth,0);
			if((Shifting_State == ShiftingLeft) && (LastShiftingState == ShiftingLeft))
			{
				while(LCD_SendCommand(LCD_SHIFTCURSRIGHT)!=OperationSuccess);
				LCD_SendNumber(RemainingSeconds);
				if(RemainingSeconds/10)
				{
					while(LCD_SendData(' ')!=OperationSuccess);/**/
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				}
				else
				{
					while(LCD_SendData(' ')!=OperationSuccess);/**/
					while(LCD_SendData(' ')!=OperationSuccess);/**/
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				}
			}
			else if ((Shifting_State == ShiftingRight) && (LastShiftingState == ShiftingRight))
			{
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				LCD_SendNumber(RemainingSeconds);
				if(RemainingSeconds/10)
				{
					while(LCD_SendData(' ')!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				}
				else
				{
					while(LCD_SendData(' ')!=OperationSuccess);
					while(LCD_SendData(' ')!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				}
			}
			else if ((Shifting_State == ShiftingRight) && (LastShiftingState == ShiftingLeft))
			{
				while(LCD_SendCommand(LCD_SHIFTCURSRIGHT)!=OperationSuccess);
				LCD_SendNumber(RemainingSeconds);
				if(RemainingSeconds/10)
				{
					while(LCD_SendData(' ')!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				}
				else
				{
					while(LCD_SendData(' ')!=OperationSuccess);
					while(LCD_SendData(' ')!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				}
			}
			else if ((Shifting_State == ShiftingLeft) && (LastShiftingState == ShiftingRight))
			{
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				LCD_SendNumber(RemainingSeconds);
				if(RemainingSeconds/10)
				{
					while(LCD_SendData(' ')!=OperationSuccess);/**/
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				}
				else
				{
					while(LCD_SendData(' ')!=OperationSuccess);/**/
					while(LCD_SendData(' ')!=OperationSuccess);/**/
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
					while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				}
			}
			LastShiftingState = Shifting_State;
			//if(Counter == (uint8_t)((TenSeconds/MainFunction_Periodicity)-1))
			if(RemainingSeconds == 0)
			{
				WrongPassEntries = 0;
				Counter = 0;
				DISPLAY_SetState(PassEntering);
			}
			break;
		case SevenSegments:
			if(Last_state != State)
			{
				Position = 0;
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"System is ON") != OperationSuccess);
				Shifting_State = ShiftingRight;
			}
			DISPLAY_START_SHIFTING(SystemOn_StringWidth,0);
			break;
		case ChangePassword:
			if(Last_state != State)
			{
				Position = DISPLAY_WIDTH-ChangePassword_StringWidth;
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendCommand(LCD_CURS_Position0|Position)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"Changing Pass") != OperationSuccess);
				Shifting_State = ShiftingLeft;
				while (LCD_SendCommand(0xc0)!=OperationSuccess);
				for(uint8_t i = 0; i < Number_of_Asteriks; i++)
				{
					while(LCD_SendData('*')!= OperationSuccess);
					if (i>5)
					{
						break;
					}
				}
			}
			break;
		default:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			break;
	}
	Last_state = State;
}

void DISPLAY_START_SHIFTING(uint8_t stringLength, uint8_t passWordLength)
{
	uint8_t volatile StringMotionRange = DISPLAY_WIDTH - stringLength;
	switch (Shifting_State)
	{
		case ShiftingLeft:
			if(passWordLength!=0)
			{
				while(LCD_SendData('*')!= OperationSuccess);
			}
			while(LCD_SendCommand(LCD_SHIFTDISPLEFT)!= OperationSuccess);
			Position--;
			if (Position == 0)
			{
				Shifting_State = ShiftingRight;
			}
			break;
		case ShiftingRight:
			if(passWordLength!=0)
			{
				while (LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendData(' ')!= OperationSuccess);
				while (LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
			while(LCD_SendCommand(LCD_SHIFTDISPRIGHT)!= OperationSuccess);
			Position++;
			if (Position >= StringMotionRange)
			{
				Shifting_State = ShiftingLeft;
			}
			break;
	}
}



#if 0
void DISPLAY_MainFunction(void)
{
	uint8_t static Last_state = OperationStarted;
	uint8_t static Counter = 0;
	uint8_t State =0;
	DISPLAY_GetNumber_of_Asterisk(&Number_of_Asteriks);
	DISPLAY_GetState(&State);
	if((Last_state == CorrectPassword || Last_state == WrongPassword || Last_state == Waiting)&&(Counter!=0))
	{
		State = Last_state;
	}
	switch(State)
	{
		case SystemLoading:
			if(Last_state != State)
			{
				Position = 0;
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while(LCD_SendString((uint8_t*)"System Loading") != OperationSuccess);
				Shifting_State = ShiftingRight;
			}
			DISPLAY_START_SHIFTING(SystemLoading_StringWidth,0);
			break;
		case Welcome:
			if(Last_state != State)
			{
				Position = 0;
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while(LCD_SendString((uint8_t*)"WELCOME") != OperationSuccess);
				Shifting_State = ShiftingRight;
			}
			DISPLAY_START_SHIFTING(Welcome_StringWidth,0);
			break;
		case PassEntering:
			if(Last_state != State)
			{
				Position = DISPLAY_WIDTH-EnterPass_StringWidth;
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendCommand(LCD_CURS_Position0|Position)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"Enter Pass") != OperationSuccess);
				Shifting_State = ShiftingLeft;
				while (LCD_SendCommand(LCD_CURS_LINE2)!=OperationSuccess);
				for(uint8_t i = 0; i < Number_of_Asteriks; i++)
				{
					while(LCD_SendData('*')!= OperationSuccess);
					if (i>5)
					{
						break;
					}
				}
			}
			DISPLAY_START_SHIFTING(EnterPass_StringWidth,Number_of_Asteriks);
			break;
		case CorrectPassword:
			if(Last_state != State)
			{
				Position = 0;
				DISPLAY_SetNumber_of_Asterisk(0);
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"Pass OK") != OperationSuccess);
				Shifting_State = ShiftingRight;
			}
			DISPLAY_START_SHIFTING(CorrectPass_StringWidth,0);
			
			Counter ++;
			if(Counter == (uint8_t)(TwoSeconds/MainFunction_Periodicity))
			{
				WrongPassEntries = 0;
				Counter = 0;
				DISPLAY_SetState(SevenSegments);
			}
			break;
		/*Counter*/
		case WrongPassword:
			if(Last_state != State)
			{
				Position = 0;
				DISPLAY_SetNumber_of_Asterisk(0);
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"Wrong Pass") != OperationSuccess);
				Shifting_State = ShiftingRight;
			}
			DISPLAY_START_SHIFTING(WrongPass_StringWidth,0);
			Counter ++;
			if(Counter == (uint8_t)(TwoSeconds/MainFunction_Periodicity))
			{
				Counter = 0;
				WrongPassEntries++;
				if(WrongPassEntries==3)
					DISPLAY_SetState(Waiting);
				else
					DISPLAY_SetState(PassEntering);
			}
			break;
		case Waiting:
			if(Last_state != State)
			{
				Position = DISPLAY_WIDTH - Waiting_StringWidth;
				DISPLAY_SetNumber_of_Asterisk(0);
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"Waiting") != OperationSuccess);
				Shifting_State = ShiftingLeft;
				while (LCD_SendCommand(LCD_CURS_LINE2|4)!=OperationSuccess);
			}
			LCD_SendNumber((10000-(Counter*50))/1000);
			DISPLAY_START_SHIFTING(Waiting_StringWidth,0);
/*			if(Shifting_State == ShiftingLeft)
			{
				while (LCD_SendCommand(LCD_SHIFTCURSRIGHT)!=OperationSuccess);
				while(LCD_SendNumber(Counter)!=OperationStarted);
			}
			else
			{
				while (LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendNumber(Counter)!= OperationSuccess);
				while (LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}*/
			Counter ++;
			if(Counter == (uint8_t)(TenSeconds/MainFunction_Periodicity))
			{
				WrongPassEntries = 0;
				Counter = 0;
				DISPLAY_SetState(PassEntering);
			}
			break;
		case SevenSegments:
			if(Last_state != State)
			{
				Position = 0;
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"System is ON") != OperationSuccess);
				Shifting_State = ShiftingRight;
			}
			DISPLAY_START_SHIFTING(SystemOn_StringWidth,0);
			break;
		case ChangePassword:
			if(Last_state != State)
			{
				Position = DISPLAY_WIDTH-ChangePassword_StringWidth;
				while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
				while (LCD_SendCommand(LCD_HOME)!=OperationSuccess);
				while (LCD_SendCommand(LCD_CURS_Position0|Position)!=OperationSuccess);
				while (LCD_SendString((uint8_t*)"Changing Pass") != OperationSuccess);
				Shifting_State = ShiftingLeft;
				while (LCD_SendCommand(0xc0)!=OperationSuccess);
				for(uint8_t i = 0; i < Number_of_Asteriks; i++)
				{
					while(LCD_SendData('*')!= OperationSuccess);
					if (i>5)
					{
						break;
					}
				}
			}
			break;
		default:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			break;
	}
	Last_state = State;
}

void DISPLAY_MainFunction(void)
{
	uint8_t static Last_state = OperationStarted;
	uint8_t static Counter = 0;
	DISPLAY_GetNumber_of_Asterisk(&Number_of_Asteriks);
	DISPLAY_GetState(&State);
	if((Last_state == CorrectPassword || Last_state == WrongPassword || Last_state == Waiting)&&(Counter!=0))
	{
		State = Last_state;
	}
	switch(State)
	{
		case SystemLoading:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			DISPLAY_ShiftAndDisplay(14, (uint8_t*)"System Loading");
			break;
		case Welcome:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			DISPLAY_ShiftAndDisplay(7, (uint8_t*)"Welcome");
			break;
		case PassEntering:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			while (LCD_SendCommand(0xc0)!=OperationSuccess);
			for(uint8_t iterator = 0; iterator<Number_of_Asteriks; iterator++)
			{
				if(iterator>6)
				break;
				while(LCD_SendData('*')!=OperationSuccess);
			}
			DISPLAY_ShiftAndDisplay(10,(uint8_t*)"Enter Pass");
			break;
		case CorrectPassword:
			if(Counter == 40)
			{
				WrongPassEntries = 0;
				Counter = 0;
				//State = SevenSegments;
				DISPLAY_SetState(SevenSegments);
				break;
			}
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			DISPLAY_ShiftAndDisplay(10,(uint8_t*)"Pass OK");
			Counter ++;
			break;
			
			/*Counter*/
		case WrongPassword:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			if(Counter == 40)
			{
				Counter = 0;
				WrongPassEntries++;
				if(WrongPassEntries==3)
				DISPLAY_SetState(Waiting);
				else
				DISPLAY_SetState(PassEntering);
				break;
			}
			DISPLAY_ShiftAndDisplay(10,(uint8_t*)"Wrong Pass");
			/*check the counter*/
			Counter ++;
			break;
		case Waiting:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			while (LCD_SendCommand(0xc0)!=OperationSuccess);
			LCD_SendNumber((10000-(Counter*50))/1000);
			if(Counter == 199)
			{
				WrongPassEntries = 0;
				Counter = 0;
				//State = PassEntering;
				DISPLAY_SetState(PassEntering);
				break;
			}
			DISPLAY_ShiftAndDisplay(7,(uint8_t*)"Waiting");
			/*seconds remaining in the second row*/
			Counter ++;
			break;
		case SevenSegments: 
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			DISPLAY_ShiftAndDisplay(12,(uint8_t*)"System is ON");
			/*task of seven segment*/
			break;
		case ChangePassword:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			while (LCD_SendCommand(0xc0)!=OperationSuccess);
			for(uint8_t iterator = 0; iterator<Number_of_Asteriks; iterator++)
			{
				if(iterator>6)
				break;
				while(LCD_SendData('*')!=OperationSuccess);
			}
			DISPLAY_ShiftAndDisplay(13,(uint8_t*)"Changing Pass");
			/*Stars on the second ROW*/
			break;
		default:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			break;
	}
	Last_state = State;
}


void DISPLAY_ShiftAndDisplay(uint8_t StringLength, uint8_t* StringPTR)
{
	uint8_t static State = OperationStarted;
	
	switch(State)
	{
		case OperationStarted:
		if(Position<16-StringLength)
		{
			State = ShiftingRight;
		}
		else if (Position == 15-StringLength)
		{
			State = ShiftingLeft;
		}
		else
		{
			Position = 0;
			State = ShiftingRight;
		}
		break;
		case ShiftingRight:
		while(LCD_SendCommand(0x80|Position) != OperationSuccess);
		while(LCD_SendString(StringPTR) != OperationSuccess);
		while(LCD_SendCommand(0x80|(Position-1)) != OperationSuccess);
		while(LCD_SendData(' ')!= OperationSuccess);
		if (Position == 16-StringLength)
		{
			State = ShiftingLeft;
		}
		Position++;
		break;
		case ShiftingLeft:
		Position--;
		if (Position == 0)
		{
			State = ShiftingRight;
		}
		while(LCD_SendCommand(0x80|Position) != OperationSuccess);
		while(LCD_SendString(StringPTR) != OperationSuccess);
		while(LCD_SendData(' ')!= OperationSuccess);
		break;
		default:
		break;
	}
}


void DISPLAY_ShiftAndDisplay(uint8_t StringLength, uint8_t* StringPTR)
{
	uint8_t static State = OperationStarted;
	
	switch(State)
	{
		case OperationStarted:
		if(Position<16-StringLength)
		{
			State = ShiftingRight;
		}
		else if (Position == 15-StringLength)
		{
			State = ShiftingLeft;
		}
		else
		{
			Position = 0;
			State = ShiftingRight;
		}
		break;
		case ShiftingRight:
		while(LCD_SendCommand(LCD_HOME) != OperationSuccess);
		while(LCD_SendString(StringPTR) != OperationSuccess);
		while(LCD_SendCommand(LCD_SHIFTDISPRIGHT) != OperationSuccess);
		if (Position == 16-StringLength)
		{
			State = ShiftingLeft;
		}
		Position++;
		break;
		case ShiftingLeft:
		Position--;
		if (Position == 0)
		{
			State = ShiftingRight;
		}
		while(LCD_SendCommand(0x80|Position) != OperationSuccess);
		while(LCD_SendString(StringPTR) != OperationSuccess);
		while(LCD_SendCommand(LCD_SHIFTDISPLEFT) != OperationSuccess);
		break;
		default:
		break;
	}
}
#endif