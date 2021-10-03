/**
 * EEPROM.h
 *
 * Created: 9/6/2021 6:07:42 AM
 * Author: Ahmed Adel
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "MC_REGISTERS.h"
#include "LIB.h"

/*Need to be added to the MC_REGISTERS.h*/
/*
#define SPMCR *((volatile ptr_uint8_t)(0X57))
#define SPMEN BIT0*/
uint8_t EEPROM_Read(uint8_t * Data,uint16_t Address);
uint8_t EEPROM_Write(uint8_t Data,uint16_t Address);

#endif /* EEPROM_H_ */