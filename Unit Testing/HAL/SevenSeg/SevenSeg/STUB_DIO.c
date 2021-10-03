/*
 * STUB_DIO.c
 *
 * Created: 9/2/2021 1:50:41 PM
 *  Author: Mohamed Wagdy
 */

 /*- INCLUDES
 ----------------------------------------------*/
#include "STUB_DIO.h"

uint8_t PORTB = 0x00;
uint8_t PORTD = 0x00;

uint8_t DDRB = 0x00;
uint8_t DDRD = 0x00;

/*- APIs IMPLEMENTATION
-----------------------------------*/
ERROR_STATE_t DIO_SetPinDirection(uint8_t PortName, uint8_t PinNo, uint8_t PinDirection)
{
   if (PIN_OUTPUT == PinDirection)
   {
      switch (PortName)
      {
      case PORT_B:
         DDRB |= (1 << PinNo);
         break;
      case PORT_D:
         DDRD |= (1 << PinNo);
         break;
      }
   }
   else
   {
      switch (PortName)
      {
      case PORT_B:
         DDRB &= ~(1 << PinNo);
         break;
      case PORT_D:
         DDRD &= ~(1 << PinNo);
         break;
      }
   }

   return ERROR_OK;
}

ERROR_STATE_t DIO_WritePin(uint8_t PortName, uint8_t PinNo, uint8_t PinValue)
{
   if (PIN_HIGH == PinValue)
   {
      switch (PortName)
      {
         case PORT_B:
            PORTB |= (1 << PinNo);
            break;
         case PORT_D:
            PORTD |= (1 << PinNo);
            break;
      }
   }
   else
   {
      switch (PortName)
      {
         case PORT_B:
            PORTB &= ~(1 << PinNo);
            break;
         case PORT_D:
            PORTD &= ~(1 << PinNo);
            break;
      }
   }
   
   return ERROR_OK;
}