/*
 * STUB_DIO.h
 *
 * Created: 9/2/2021 1:50:18 PM
 *  Author: Mohamed Wagdy
 */


#ifndef __STUB_DIO_H__
#define __STUB_DIO_H__

 /*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"

/* Ports */
#define  PORT_A                     (uint8_t)( 0 )
#define  PORT_B                     (uint8_t)( 1 )
#define  PORT_C                     (uint8_t)( 2 )
#define  PORT_D                     (uint8_t)( 3 )

/* Pins */
#define  PIN0                       (uint8_t)( 0 )
#define  PIN1                       (uint8_t)( 1 )
#define  PIN2                       (uint8_t)( 2 )
#define  PIN3                       (uint8_t)( 3 )
#define  PIN4                       (uint8_t)( 4 )
#define  PIN5                       (uint8_t)( 5 )
#define  PIN6                       (uint8_t)( 6 )
#define  PIN7                       (uint8_t)( 7 )

/* Directions */
#define  PIN_OUTPUT                 (uint8_t)( 1 )
#define  PIN_INPUT                  (uint8_t)( 0 )

/* Values */
#define  PIN_HIGH                   (uint8_t)( 1 )
#define  PIN_LOW                    (uint8_t)( 0 )

/*- FUNCTION DECLARATIONS ----------------------------------*/
ERROR_STATE_t DIO_SetPinDirection(uint8_t PortName, uint8_t PinNo, uint8_t PinDirection);
ERROR_STATE_t DIO_WritePin(uint8_t PortName, uint8_t PinNo, uint8_t PinValue);

#endif /* __STUB_DIO_H__ */