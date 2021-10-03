#ifndef __BLUETOOTH_MNG_LCFG_H__
#define __BLUETOOTH_MNG_LCFG_H__

/*- INCLUDES-----------------------------------*/
#include "STD_TYPES.h"
#include "BLUETOOTH.h"

/*-MACROS-------------------------------------*/
#define BLUETOOTH_NAME          		"CU1 - 1"
#define BLUETOOTH_PASSWORD      		"228989"
#define BLUETOOTH_IAC	        		"9e8b55"
#define BLUETOOTH_INQM					"0,2,10"
#define BLUETOOTH_INQ_DEVICES_NUMBERS 	2


#define BLUETOOTH_UART_CFG_LEN		(11)
#define BLUETOOTH_NAME_LEN			(10) 
#define BLUETOOTH_PASS_LEN			(10) 
 
/*- STRUCTS AND UNIONS -----------------------*/
typedef struct STR_BAUDRATE_CFG
{
   uint8_t 	au8_BLUETOOTH_BAUDRATE[BLUETOOTH_UART_CFG_LEN];
   uint32_t u32_UART_BUADRATE;

} STR_BAUDRATE_CFG_t;

typedef struct STR_BLUETOOTH_Mng_config
{
   STR_BAUDRATE_CFG_t 	STR_BLUETOOTH_Mng_BAUDRATE_Cng;
   ptr_uint8_t  u8_BLUETOOTH_Mng_MODE;
   uint8_t  au8_BLUETOOTH_Mng_NAME[BLUETOOTH_NAME_LEN];
   uint8_t  au8_BLUETOOTH_Mng_PASSWORD[BLUETOOTH_PASS_LEN];
  
} STR_BLUETOOTH_Mng_config_t;

#endif /* __BLUETOOTH_MNG_LCFG_H__ */
