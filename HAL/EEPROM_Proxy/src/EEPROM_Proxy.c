/*
 * EEPROM_Proxy.c
 *
 * Created: 9/8/2021 8:37:23 AM
 *  Author: Ahmed Adel
 */ 
#include "EEPROM_Proxy.h"

ERROR_STATE_t EEPROM_ProxySaveToMemory(uint8_t* CharArr, uint16_t Starting_position, uint16_t* EndingPosition)
{
	/*initialize iterator variable*/
	uint8_t iterator = 0;
	/*return value initializing*/
	uint8_t ErrRetVal = OperationStarted;
	/*calculate the checksum bytes*/
	CRC_16_Calc(CharArr);
	/*Initialize the value of current position which will be returned back through the EndingPosition argument*/
	uint8_t CurrentPosition = Starting_position;
	/*write the bytes with the calculated check sum to the memory*/
	for(;;)
	{
		/*check if Current position is in range (at that moment current position is equals to the starting position)*/
		if(CurrentPosition < 1024)
		{
			/*check if end of the array is reached*/
			if(CharArr[iterator] == NULL_TERMINATOR)
			{
				/*save to EEPROM*/
				EEPROM_Write(CharArr[iterator],CurrentPosition);
				break;
			}
			else
			{
				/*save byte to the EEPROM*/
				EEPROM_Write(CharArr[iterator], CurrentPosition);
				CurrentPosition++;
				iterator++;
			}
		}
		else
		{
			ErrRetVal = OperationFail;
			break;
		}
	}
	return ErrRetVal;
}
ERROR_STATE_t EEPROM_ProxyLoadFromMemory(uint16_t StartingPosition, uint16_t EndingPosition, uint8_t* CharArr)
{
	/*initialize the static data buffer to return data back to the calling function 'retains data'*/
	/*static uint8_t array[255];*///==>this buffer shouldn't be provided from the proxy'
	/*initialize iterator variable*/
	uint8_t iterator = 0;
	/*initialize function return value*/
	uint8_t FunRetVal = OperationStarted;
	/*return value initializing*/
	uint8_t ErrRetVal = OperationStarted;
	/*initialize a variable that hold the current reading position*/
	uint16_t CurrentReadingPosition = StartingPosition;
	/*read the bytes with the calculated check sum to the memory*/
	for(;;)
	{
		if((CurrentReadingPosition<= EndingPosition) && (EndingPosition <= 1023))
		{
			/*load byte from the EEPROM*/
			EEPROM_Read(&(CharArr[iterator]), CurrentReadingPosition);
			CurrentReadingPosition++;
			/*check if end of the data is reached*/
			if(CharArr[iterator] == NULL_TERMINATOR)
			{
				/*load the Null Character*/
				EEPROM_Read(&(CharArr[iterator]), CurrentReadingPosition);
				/*chck the CRC-16*/
				FunRetVal = CRC_16_Chk(CharArr);
				if (FunRetVal == ERROR_NOK)
				{
					ErrRetVal = MemoryEmpty;//corruptedMemory
					break;	
				}				
				else
				{
					ErrRetVal = OperationSuccess;
					break;
				}
			}
			else if (CharArr[iterator] == 0xFF)
			{
				/*the memory is empty*/
				ErrRetVal = MemoryEmpty;
				break;
			}
			else
			{
				iterator++;
			}
		}
		else
		{
			ErrRetVal = OperationFail;
		}	
	}
	return ErrRetVal;
}
ERROR_STATE_t EEPROM_EraseSection(uint16_t StartingPosition)
{
	uint8_t ErrRetVal = OperationStarted;
	ErrRetVal = EEPROM_Write(0xff,StartingPosition);
	return ErrRetVal;
}