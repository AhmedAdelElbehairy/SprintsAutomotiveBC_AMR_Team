#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_
/*INCLUDES-------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "BLUETOOTH_Lcfg.h"

/*MACROS
------------------------------------------*/
#define BLUETOOTH_0    (uint8_t)(0)

#define BLUETOOTH_CMD_AT 					"AT"
#define BLUETOOTH_CMD_SET_NAME				"AT+NAME="
#define BLUETOOTH_CMD_SET_PSWD				"AT+PSWD="
			
#define BLUETOOTH_CMD_SET_INIT				"AT+INIT"
#define BLUETOOTH_CMD_SET_IAC				"AT+IAC="

#define BLUETOOTH_CMD_SET_CLASS				"AT+CLASS"
#define BLUETOOTH_INQM_PARAM_CLASS     		"0"

#define BLUETOOTH_CMD_SET_INQM				"AT+INQM="

#define BLUETOOTH_CMD_SET_INQC				"AT+ INQC"
			
#define BLUETOOTH_CMD_SET_FSAD				"AT+FSAD=" //searching give MAC
#define BLUETOOTH_CMD_SET_RMAAD				"AT+RMAAD" //Deleting all
			
#define BLUETOOTH_CMD_SET_LINK 				"AT+LINK="
#define BLUETOOTH_CMD_SET_DISC				"AT+DISC"
			
#define BLUETOOTH_CMD_SET_ROLE 				"AT+ROLE="
#define BLUETOOTH_ROLE_PARAM_SLV    		"0"
#define BLUETOOTH_ROLE_PARAM_MSTR   		"1"

#define BLUETOOTH_CMD_SET_UART				"AT+UART="
#define BLUETOOTH_UART_PARAM_9600           "9600,1,0"
#define BLUETOOTH_UART_PARAM_19200          "19200,1,0"
#define BLUETOOTH_UART_PARAM_38400          "38400,1,0"
#define BLUETOOTH_UART_PARAM_57600          "57600,1,0"
#define BLUETOOTH_UART_PARAM_115200         "115200,1,0"
#define BLUETOOTH_UART_PARAM_230400         "230400,1,0"

#define BLUETOOTH_CMD_SET_CMODE			"AT+CMODE="
#define BLUETOOTH_CMODE_PARAM_FIX_ADD   "0"
#define BLUETOOTH_CMODE_PARAM_VAR_ADD   "1"

#define BLUETOOTH_CMD_GET_ADD 	"AT+ADDR?"
#define BLUETOOTH_CMD_GET_ROLE 	"AT+ROLE?"
#define BLUETOOTH_CMD_GET_NAME	"AT+NAME?"
#define BLUETOOTH_CMD_GET_PSWD	"AT+PSWD?"
#define BLUETOOTH_CMD_GET_STATE	"AT+STATE?"
#define BLUETOOTH_CMD_GET_BAUD	"AT+UART?"
#define BLUETOOTH_CMD_GET_ADCN	"AT+ADCN?"
#define BLUETOOTH_CMD_GET_INQ	"AT+INQ"
#define BLUETOOTH_OK	"OK\r\n"
/*APIs DECLARATIONS------------------------*/
ERROR_STATE_t BLUETOOTH_Init(void);
ERROR_STATE_t BLUETOOTH_SetDataMode(uint8_t BluetoothNumber);

ERROR_STATE_t BLUETOOTH_SendData(uint8_t BluetoothNumber,ptr_uint8_t Data);
ERROR_STATE_t BLUETOOTH_ReceiveData(uint8_t BluetoothNumber,ptr_uint8_t RxData);

ERROR_STATE_t BLUETOOTH_ATModeGetCommand(uint8_t BluetoothNumber,ptr_uint8_t CMD);
ERROR_STATE_t BLUETOOTH_ATModeSetCommand(uint8_t BluetoothNumber,ptr_uint8_t CMD,ptr_uint8_t Param);


ERROR_STATE_t BLUETOOTH_Scan(uint8_t BluetoothNumber);
ERROR_STATE_t BLUETOOTH_Connect(uint8_t BluetoothNumber,ptr_uint8_t DeviceMac);
ERROR_STATE_t BLUETOOTH_Disconnect(uint8_t BluetoothNumber);


#endif /* BLUETOOTH_H_ */
