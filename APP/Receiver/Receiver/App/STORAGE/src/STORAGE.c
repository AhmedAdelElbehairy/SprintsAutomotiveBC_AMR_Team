/*
 * STORAGE.c
 *
 * Created: 9/8/2021 7:17:57 PM
 *  Author: Ahmed Adel
 */ 
#include "STORAGE.h"

ERROR_STATE_t STORAGE_MAC_Save(uint8_t* CharArr)
{
		uint8_t ErrRetVal = OperationStarted;
		uint16_t EndingPosition = 0;
		ErrRetVal = EEPROM_ProxySaveToMemory(CharArr,STARTING_ADD_MAC, &EndingPosition);
		if(EndingPosition > ENDING_ADD_MAC)
			ErrRetVal = OperationFail;
		return ErrRetVal;
}
ERROR_STATE_t STORAGE_MAC_Load(uint8_t* CharArr)
{
	uint8_t ErrRetVal = OperationStarted;
	ErrRetVal = EEPROM_ProxyLoadFromMemory(STARTING_ADD_MAC, ENDING_ADD_MAC, CharArr);
	return ErrRetVal;
}
ERROR_STATE_t STORAGE_DataPacket_Save(uint8_t* CharArr)
{
	uint8_t ErrRetVal = OperationStarted;
	uint16_t EndingPosition = 0;
	ErrRetVal = EEPROM_ProxySaveToMemory(CharArr,STARTING_ADD_DataPacket, &EndingPosition);
	if(EndingPosition > ENDING_ADD_DataPAcket)
		ErrRetVal = OperationFail;
	return ErrRetVal;
}
ERROR_STATE_t STORAGE_DataPacket_Load(uint8_t* CharArr)
{
	uint8_t ErrRetVal = OperationStarted;
	ErrRetVal = EEPROM_ProxyLoadFromMemory(STARTING_ADD_DataPacket, ENDING_ADD_DataPAcket, CharArr);
	return ErrRetVal;
}
ERROR_STATE_t STORAGE_Password_Save(uint8_t* CharArr)
{
	uint8_t ErrRetVal = OperationStarted;
	uint16_t EndingPosition = 0;
	ErrRetVal = EEPROM_ProxySaveToMemory(CharArr,STARTING_ADD_Password, &EndingPosition);
	if(EndingPosition > ENDING_ADD_Password)
		ErrRetVal = OperationFail;
	return ErrRetVal;
}
ERROR_STATE_t STORAGE_Password_Load(uint8_t* CharArr)
{
	uint8_t ErrRetVal = OperationStarted;
	ErrRetVal = EEPROM_ProxyLoadFromMemory(STARTING_ADD_Password, ENDING_ADD_Password, CharArr);
	return ErrRetVal;
}
ERROR_STATE_t STORAGE_MAC_ERASE(uint8_t* CharArr)
{
	uint8_t ErrRetVal = OperationStarted;
	ErrRetVal = EEPROM_EraseSection(STARTING_ADD_MAC);
	return ErrRetVal;
}