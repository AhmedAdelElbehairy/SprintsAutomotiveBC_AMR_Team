/*
 * STORAGE.h
 *
 * Created: 9/8/2021 7:17:40 PM
 *  Author: Ahmed Adel
 */ 


#ifndef STORAGE_H_
#define STORAGE_H_

#define STARTING_ADD_MAC			(uint16_t)0
#define ENDING_ADD_MAC				(uint16_t)16
#define STARTING_ADD_DataPacket		(uint16_t)20
#define ENDING_ADD_DataPAcket		(uint16_t)50
#define STARTING_ADD_Password		(uint16_t)60
#define ENDING_ADD_Password			(uint16_t)80


#include "EEPROM_Proxy.h"

ERROR_STATE_t STORAGE_MAC_Save(uint8_t* CharArr);
ERROR_STATE_t STORAGE_MAC_Load(uint8_t* CharArr);
ERROR_STATE_t STORAGE_MAC_ERASE(uint8_t* CharArr);

ERROR_STATE_t STORAGE_DataPacket_Save(uint8_t* CharArr);
ERROR_STATE_t STORAGE_DataPacket_Load(uint8_t* CharArr);

ERROR_STATE_t STORAGE_Password_Save(uint8_t* CharArr);
ERROR_STATE_t STORAGE_Password_Load(uint8_t* CharArr);

#endif /* STORAGE_H_ */