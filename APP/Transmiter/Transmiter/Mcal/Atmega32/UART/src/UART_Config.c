/*
 * UART_Config.c
 *
 * Created: 8/1/2021 6:29:38 PM
 *  Author: Mohamed Wagdy
 */ 
/*- INCLUDES
----------------------------------------------*/
#include "UART_Config.h"

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
/* UART_CH_0 */
const uint8_t UART_CH_0_CONTROL = (ENABLE_RX | ENABLE_TX);
const uint8_t UART_CH_0_CONTROL_2 = (SET_PARITY_STOP_AND_DATA_SIZE | NO_PARITY | STOP_1_BIT | DATA_8_BITS);
const uint16_t UART_CH_0_BaudRate = CLK_8_MHZ_19k_BAUD;