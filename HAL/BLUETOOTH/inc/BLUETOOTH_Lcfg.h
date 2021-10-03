#ifndef BLUETOOTH_LCFG_H_
#define BLUETOOTH_LCFG_H_
/*- INCLUDES
----------------------------------------------*/
#include "STD_TYPES.h"
#include "DIO.h"
#include "UART.h"

/*- LOCAL MACROS------------------------------------------*/
#define BLUETOOTH_NUMBERS              	 (uint8_t)(1)

#define BLUETOOTH_POWER_PIN     			PIN2
#define BLUETOOTH_POWER_PORT   				PORT_D
#define BLUETOOTH_ENABLE_PIN     			PIN3
#define BLUETOOTH_ENABLE_PORT   			PORT_D


/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_BLUETOOTH_config
{
   uint8_t  u8_BLUETOOTH_UART_CH;
   uint8_t  u8_BLUETOOTH_POWER_PIN;
   uint8_t  u8_BLUETOOTH_POWER_PORT;
   uint8_t  u8_BLUETOOTH_ENABLE_PIN;
   uint8_t  u8_BLUETOOTH_ENABLE_PORT;
} STR_BLUETOOTH_config_t;

#endif /* BLUETOOTH_LCFG_H_ */
