/*
 * UART.h
 *
 * Created: 7/13/2021 2:54:45 PM
 *  Author: Mohamed Wagdy
 */ 

#ifndef __UART_H__
#define __UART_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"
#include "BIT_MATH.h"
#include "UART_Config.h"

/* UART_CH_0 */
#define UART_CH_0                   (uint8_t)(0)


#define BAUDRATE_9600               (uint32_t)(9600)
#define BAUDRATE_19200              (uint32_t)(19200)
#define BAUDRATE_38400              (uint32_t)(38400)
#define BAUDRATE_57600              (uint32_t)(57600)
#define BAUDRATE_115200             (uint32_t)(115200)
#define BAUDRATE_230400             (uint32_t)(230400)

#define RX_INT                      (uint8_t)(0x80)
#define TX_INT                      (uint8_t)(0x40)

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Function that initialize UART. */
ERROR_STATE_t UART_Init(uint8_t UartNumber);

/* Function that writes character to transmit buffer. */
ERROR_STATE_t UART_TransmitChar(uint8_t UartNumber, uint8_t TxChar);

/* Function that reads character from receive buffer. */
ERROR_STATE_t UART_ReceiveChar(uint8_t UartNumber, uint8_t * RxChar);

/* Function that writes characters in transmit buffer in order. */
ERROR_STATE_t UART_TransmitString(uint8_t UartNumber, uint8_t * TxString);

/* Function that receives characters from receive buffer in order. */
ERROR_STATE_t UART_ReceiveString(uint8_t UartNumber, uint8_t * RxString);

/* Function that enables UART interrupt */
ERROR_STATE_t UART_EnableInterrupt(uint8_t UartNumber,uint8_t UartInterruptType);

/* Function that disables UART interrupt */
ERROR_STATE_t UART_DisableInterrupt(uint8_t UartNumber,uint8_t UartInterruptType);

/* Function that sets interrupt callback function */
ERROR_STATE_t UART_SetCallback(uint8_t UartNumber, uint8_t UartInterruptType, Ptr_VoidFuncVoid_t Callback);

/* Function that set data in the UART data register */
ERROR_STATE_t UART_SetData(uint8_t UartNumber,uint8_t TxChar);

/* Function that get data from the UART data register */
ERROR_STATE_t UART_GetData(uint8_t UartNumber,uint8_t * RxChar);

/* Function that set the UART Baudrate */
ERROR_STATE_t UART_SetBaudRate(uint8_t UartNumber,uint32_t UartBaudrate);

ERROR_STATE_t UART_IsDataAvailableToWrite(uint8_t UARTNumber);

ERROR_STATE_t UART_IsDataAvailableToRead(uint8_t UARTNumber);

#endif /* __UART_H__ */