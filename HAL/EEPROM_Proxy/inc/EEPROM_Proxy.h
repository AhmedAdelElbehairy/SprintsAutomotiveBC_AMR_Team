/*
 * EEPROM_Proxy.h
 *
 * Created: 9/8/2021 8:37:05 AM
 *  Author: Ahmed Adel
 */ 


#ifndef EEPROM_PROXY_H_
#define EEPROM_PROXY_H_

#include "EEPROM.h"

#define MemoryEmpty (uint8_t)(5)

ERROR_STATE_t EEPROM_ProxySaveToMemory(uint8_t* CharArr, uint16_t Starting_position, uint16_t* EndingPosition);
ERROR_STATE_t EEPROM_ProxyLoadFromMemory(uint16_t StartingPosition, uint16_t EndingPosition, uint8_t* CharArr);
ERROR_STATE_t EEPROM_EraseSection(uint16_t StartingPosition);

#endif /* EEPROM_PROXY_H_ */