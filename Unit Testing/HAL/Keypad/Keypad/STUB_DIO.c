/*
 * STUB_DIO.c
 *
 * Created: 9/2/2021 1:50:41 PM
 *  Author: Mohamed Wagdy
 */

 /*- INCLUDES
 ----------------------------------------------*/
#include "STUB_DIO.h"

uint8_t PORTC = 0x00;
uint8_t DDRC = 0x00;
uint8_t PINC = 0x00;

/*- APIs IMPLEMENTATION
-----------------------------------*/
ERROR_STATE_t DIO_SetPinDirection(uint8_t PortName, uint8_t PinNo, uint8_t PinDirection)
{
   if (PIN_OUTPUT == PinDirection)
   {
      DDRC |= (1 << PinNo);
   }
   else
   {
      DDRC &= ~(1 << PinNo);
   }

   return ERROR_OK;
}

ERROR_STATE_t DIO_WritePin(uint8_t PortName, uint8_t PinNo, uint8_t PinValue)
{
   if (PIN_HIGH == PinValue)
   {
      PORTC |= (1 << PinNo);
   }
   else
   {
      PORTC &= ~(1 << PinNo);
   }
   
   return ERROR_OK;
}

ERROR_STATE_t DIO_ReadPin(uint8_t PortName, uint8_t PinNo, ptr_uint8_t PinData)
{
   *PinData = (PINC >> PinNo) & 1;
   return ERROR_OK;
}

ERROR_STATE_t DIO_EnablePinPullup(uint8_t PortName, uint8_t PinNo)
{
   return ERROR_OK;
}