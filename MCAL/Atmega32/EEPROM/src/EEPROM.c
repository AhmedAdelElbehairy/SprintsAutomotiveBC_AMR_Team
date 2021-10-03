/*
 * EEPROM.c
 *
 * Created: 9/6/2021 6:08:02 AM
 *  Author: Ahmed Adel
 */ 
#include "EEPROM.h"

uint8_t EEPROM_Read(uint8_t * Data,uint16_t Address)
{
	uint8_t ErrRetVal = OperationStarted;
	uint8_t StatusRegVal = 0;
	/*1. Wait until EEWE becomes zero.*/
	while(READ_BIT(EECR, EEWE));
	/*2. Write new EEPROM address to EEAR (optional).*/
	WRITE_REG(EEAR, Address);
	/*3. Disable the Global Interrupt*/ 
	StatusRegVal = READ_REG(SREG);
	CLEAR_BIT(SREG, I);
	/*4. Start EEPROM read by writing a logical one to EERE bit in EECR*/
	SET_BIT(EECR,EERE);
	/*5. get data from the EEPROM EEDR*/
	*Data = READ_REG(EEDR);
	/*6. Return the state of status register*/
	WRITE_REG(SREG, StatusRegVal);
	/*7. Set function's return*/
	ErrRetVal = OperationSuccess;
	return ErrRetVal;
}
uint8_t EEPROM_Write(uint8_t Data,uint16_t Address)
{
	uint8_t ErrRetVal = OperationStarted;
	uint8_t StatusRegVal = 0;
	/*1. Wait until EEWE becomes zero.*/
	/*2. Wait until SPMEN in SPMCR becomes zero.*/
	while(READ_BIT(EECR, EEWE));
	/*3. Write new EEPROM address to EEAR (optional).*/
	WRITE_REG(EEAR, Address);
	/*4. Write new EEPROM data to EEDR (optional).*/
	WRITE_REG(EEDR, Data);
	/*5. Disable the Global Interrupt*/
	StatusRegVal = READ_REG(SREG);
	CLEAR_BIT(SREG, I);
	/*6. Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR.*/
	SET_BIT(EECR, EEMWE);
	/*7. Within four clock cycles after setting EEMWE, write a logical one to EEWE.*/
	SET_BIT(EECR, EEWE);
	/*8. Return the state of status register*/
	WRITE_REG(SREG, StatusRegVal);
	/*9. Set function's return*/
	ErrRetVal = OperationSuccess;			
	return ErrRetVal;
}
