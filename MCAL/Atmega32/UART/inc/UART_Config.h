/*
 * UART_Config.h
 *
 * Created: 7/15/2021 12:40:45 PM
 *  Author: Mohamed Wagdy
 */ 


#ifndef __UART_CONFIG_H__
#define __UART_CONFIG_H__
/*- INCLUDES
----------------------------------------------*/
#include "STD_types.h"

/*--Configuration Macros------------------------------*/
#define ENABLE_RX                         (uint8_t)(0x10)
#define ENABLE_TX                         (uint8_t)(0x08)

#define SET_PARITY_STOP_AND_DATA_SIZE     (uint8_t)(0x80)

#define EVEN_PARITY                       (uint8_t)(0x20)
#define ODD_PARITY                        (uint8_t)(0x30)
#define NO_PARITY                         (uint8_t)(0x00)

#define STOP_1_BIT                        (uint8_t)(0x00)
#define STOP_2_BIT                        (uint8_t)(0x08)

#define DATA_5_BITS                       (uint8_t)(0x00)
#define DATA_6_BITS                       (uint8_t)(0x02)
#define DATA_7_BITS                       (uint8_t)(0x04)
#define DATA_8_BITS                       (uint8_t)(0x06)

#define MAX_BAUD_VALUE                    (uint8_t)(4095)
#define BAUD_MAX_LOW_BITS                 (uint8_t)(255)
#define BAUD_HIGH_BITS_SHIFT              (uint8_t)(8)

#define CLK_8_MHZ_9600_BAUD               (uint16_t)(51)
#define CLK_8_MHZ_19k_BAUD                (uint16_t)(25)
#define CLK_16_MHZ_500k_BAUD              (uint16_t)(1)
#define CLK_16_MHZ_250k_BAUD              (uint16_t)(3)
#define CLK_16_MHZ_57k_BAUD               (uint16_t)(16)

#define CLK_16_MHZ_9600_BAUD              (uint16_t)(103)
#define CLK_16_MHZ_19200_BAUD             (uint16_t)(51)
#define CLK_16_MHZ_38400_BAUD             (uint16_t)(25)
#define CLK_16_MHZ_57600_BAUD             (uint16_t)(16)
#define CLK_16_MHZ_115200_BAUD            (uint16_t)(8)
#define CLK_16_MHZ_230400_BAUD            (uint16_t)(3)



#define UART_CH_NUMBER                    (uint8_t)(1)

#endif /* __UART_CONFIG_H__ */