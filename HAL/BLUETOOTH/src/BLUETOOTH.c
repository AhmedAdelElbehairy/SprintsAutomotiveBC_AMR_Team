/*INCLUDES-------------------------------*/
#include "BLUETOOTH.h"

/*LOCAL MACROS--------------------------*/
#define BLUETOOTH_MODE_IDLE           	(uint8_t)( 0 )
#define BLUETOOTH_MODE_AT           	(uint8_t)( 1 )
#define BLUETOOTH_MODE_DATA				(uint8_t)( 2 )
#define BLUETOOTH_STATE_CMD				(uint8_t)( 0 )				
#define BLUETOOTH_STATE_PARAM			(uint8_t)( 1 )				
#define BLUETOOTH_STATE_EOS				(uint8_t)( 2 )				

/*----GLOBAL STATIC VARIABLES----*/
static uint8_t gu8_InitFlag = NOT_INIT;
static uint8_t gu8_BluetoothMode = BLUETOOTH_MODE_IDLE;
static ptr_uint8_t gu8_BluetoothEOS = (ptr_uint8_t)"\r\n";

/*----GLOBAL EXTERN VARIABLES----*/
extern const STR_BLUETOOTH_config_t gastr_BLUETOOTH_Config[BLUETOOTH_NUMBERS];

/*- FUNCTION DECLARATIONS ----------------------------------*/
static ERROR_STATE_t BLUETOOTH_SetATMode(uint8_t BluetoothNumber);

/*- FUNCTION IMPLEMENTATION ----------------------------------*/
static ERROR_STATE_t BLUETOOTH_SetATMode(uint8_t BluetoothNumber)
{
	uint8_t u8_ErrorState=ERROR_OK;
	/*AT Mode Sequance*/
	/*set the power pin low*/
	DIO_WritePin(
					gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_POWER_PORT,
					gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_POWER_PIN,
					PIN_LOW
				);		
	/*set the enable pin high*/
	DIO_WritePin(
					gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_ENABLE_PORT,
					gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_ENABLE_PIN,
					PIN_LOW
				);
	/*set the power pin high*/
	DIO_WritePin(
					gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_POWER_PORT,
					gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_POWER_PIN,
					PIN_HIGH
				);
				
	/*set the enable pin high*/
	DIO_WritePin(
					gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_ENABLE_PORT,
					gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_ENABLE_PIN,
					PIN_HIGH
				);			

	gu8_BluetoothMode=BLUETOOTH_MODE_AT;
	return u8_ErrorState ;	
}

/*----------APIs IMPLEMENTATION-----------*/
/*
 * this API initialize the bluetooth
 */
 
 ERROR_STATE_t BLUETOOTH_SetDataMode(uint8_t BluetoothNumber)
 {
	uint8_t u8_ErrorState=ERROR_OK;
	gu8_BluetoothMode=BLUETOOTH_MODE_DATA;
	return u8_ErrorState ; 	 
 }

ERROR_STATE_t BLUETOOTH_Init(void)
{
	uint8_t u8_ErrorState=ERROR_OK;
	/*check if bluetooth has been initialized*/
	if (NOT_INIT == gu8_InitFlag) //if bluetooth is not initialized
	{
		/*set the power pin as an output*/
		DIO_SetPinDirection(
							gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_POWER_PORT,
							gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_POWER_PIN,
							PIN_OUTPUT
							);		
		/*set the power pin as an output*/
		DIO_SetPinDirection(
							gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_ENABLE_PORT,
							gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_ENABLE_PIN,
							PIN_OUTPUT
							);
		/*init the uart ch_0*/
		UART_Init(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH);
		
		gu8_InitFlag = INIT;
		u8_ErrorState=ERROR_OK;
	} 
	/*if bluetooth is initialized*/
	else if (INIT == gu8_InitFlag) 
	{
		u8_ErrorState = ERROR_NOK; 
	} 
	else 
	{
		//Do Nothing
	}
	return u8_ErrorState ;
}

ERROR_STATE_t BLUETOOTH_SendData(uint8_t BluetoothNumber,ptr_uint8_t Data)
{
	uint8_t u8_ErrorState=ERROR_OK;
	static uint8_t u8_DataCounter=ZERO;
	if(ERROR_OK==UART_IsDataAvailableToWrite(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH))
	{
		if(NULL_PTR!=Data)
		{
			if(BLUETOOTH_MODE_DATA==gu8_BluetoothMode)
			{
				switch(BluetoothNumber)
				{
				  case BLUETOOTH_0:
					if(NULL_TERMINATOR==Data[u8_DataCounter])
					{
						UART_SetData(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH , Data[u8_DataCounter]);
						u8_ErrorState=ERROR_OK;
						u8_DataCounter=ZERO;
					}
					else
					{
						UART_SetData(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH , Data[u8_DataCounter]);
						u8_DataCounter++;
						u8_ErrorState=ERROR_NOK;
					}
					break;
				  default:
					u8_ErrorState=ERROR_UNSUPPORTED_CH;
					break;
				}	
			}
		}
		else
		{
			u8_ErrorState=ERROR_NULL_PTR;
		}
	}
	return u8_ErrorState ;	
}

ERROR_STATE_t BLUETOOTH_ReceiveData(uint8_t BluetoothNumber,ptr_uint8_t RxData)
{
	uint8_t u8_ErrorState=ERROR_NOK;
	static uint8_t u8_DataCounter=ZERO;
	if(NULL_PTR!=RxData)
	{
		switch(BluetoothNumber)
		{
		  case BLUETOOTH_0:
			UART_GetData(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH,(RxData+u8_DataCounter));
			if((NULL_TERMINATOR==RxData[u8_DataCounter]))
			{
				RxData[u8_DataCounter]=NULL_TERMINATOR;
				u8_ErrorState=ERROR_OK;
				u8_DataCounter=ZERO;
			}
			else if ('\n'==RxData[u8_DataCounter])
			{
				RxData[u8_DataCounter]='\n';
				u8_DataCounter++;
				RxData[u8_DataCounter]=NULL_TERMINATOR;
				u8_ErrorState=ERROR_OK;
				u8_DataCounter=ZERO;
			}
			else
			{
				u8_DataCounter++;
			}
			
			break;
		  default:
			u8_ErrorState=ERROR_UNSUPPORTED_CH;
			break;
		}		
	}
	else
	{
		u8_ErrorState=ERROR_NULL_PTR;
	}

	return u8_ErrorState ;	
}

ERROR_STATE_t BLUETOOTH_ATModeGetCommand(uint8_t BluetoothNumber,ptr_uint8_t CMD)
{
	static uint8_t u8_CMDState=BLUETOOTH_STATE_CMD;
	ERROR_STATE_t u8_ErrorState=ERROR_NOK;
	static uint8_t u8_CMDCounter=ZERO;
	if(ERROR_OK==UART_IsDataAvailableToWrite(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH))
	{
		if(NULL_PTR!=CMD)
		{
			if(BLUETOOTH_MODE_AT!=gu8_BluetoothMode)
			{
				/*AT Mode Sequance*/
				BLUETOOTH_SetATMode(BluetoothNumber);
			}
			else
			{
				/*Do Nothing*/
			}
			if(BLUETOOTH_MODE_AT==gu8_BluetoothMode)
			{
				switch(BluetoothNumber)
				{
				  case BLUETOOTH_0:
					if(BLUETOOTH_STATE_CMD==u8_CMDState)
					{
						if(NULL_TERMINATOR!=CMD[u8_CMDCounter])
						{
							UART_SetData(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH , CMD[u8_CMDCounter]);
							u8_CMDCounter++;
						}
						else
						{
							u8_CMDState=BLUETOOTH_STATE_EOS;
							u8_CMDCounter=ZERO;
						}
					}
					else
					{
						/*Do Nothing*/
					}				
					if(BLUETOOTH_STATE_EOS==u8_CMDState)
					{
						if(NULL_TERMINATOR!=gu8_BluetoothEOS[u8_CMDCounter])
						{
							UART_SetData(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH , gu8_BluetoothEOS[u8_CMDCounter]);
							u8_CMDCounter++;

						}
						else
						{
							u8_CMDState=BLUETOOTH_STATE_CMD;
							u8_CMDCounter=ZERO;
						}
					}
					else
					{
						/*Do Nothing*/
					}
					break;
				  default:
					u8_ErrorState=ERROR_UNSUPPORTED_CH;
					break;
				}
			}
		}
	}
	return u8_ErrorState;
}

ERROR_STATE_t BLUETOOTH_ATModeSetCommand(uint8_t BluetoothNumber,ptr_uint8_t CMD,ptr_uint8_t Param)
{
	static uint8_t u8_CMDState=BLUETOOTH_STATE_CMD;
	ERROR_STATE_t u8_ErrorState=ERROR_NOK;
	static uint8_t u8_CMDCounter=ZERO;
	if(ERROR_OK==UART_IsDataAvailableToWrite(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH))
	{
		if(NULL_PTR!=CMD)
		{
			if(BLUETOOTH_MODE_AT!=gu8_BluetoothMode)
			{
				/*AT Mode Sequance*/
				BLUETOOTH_SetATMode(BluetoothNumber);
			}
			else
			{
				/*Do Nothing*/
			}
			if(BLUETOOTH_MODE_AT==gu8_BluetoothMode)
			{
				switch(BluetoothNumber)
				{
				  case BLUETOOTH_0:
					if(BLUETOOTH_STATE_CMD==u8_CMDState)
					{
						if(NULL_TERMINATOR!=CMD[u8_CMDCounter])
						{
							UART_SetData(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH , CMD[u8_CMDCounter]);
							u8_CMDCounter++;
						}
						else
						{
							u8_CMDState=BLUETOOTH_STATE_PARAM;
							u8_CMDCounter=ZERO;
						}
					}
					else
					{
						/*Do Nothing*/
					}				
					if(BLUETOOTH_STATE_PARAM==u8_CMDState)
					{
						if(NULL_TERMINATOR!=Param[u8_CMDCounter])
						{
							UART_SetData(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH , Param[u8_CMDCounter]);
							u8_CMDCounter++;
						}
						else
						{
							u8_CMDState=BLUETOOTH_STATE_EOS;
							u8_CMDCounter=ZERO;
						}
					}
					else
					{
						/*Do Nothing*/
					}				
					if(BLUETOOTH_STATE_EOS==u8_CMDState)
					{
						if(NULL_TERMINATOR!=gu8_BluetoothEOS[u8_CMDCounter])
						{
							UART_SetData(gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH , gu8_BluetoothEOS[u8_CMDCounter]);
							u8_CMDCounter++;
						}
						else
						{
							u8_CMDState=BLUETOOTH_STATE_CMD;
							u8_CMDCounter=ZERO;
							u8_ErrorState=ERROR_OK;
						}
					}
					else
					{
						/*Do Nothing*/
					}
					break;
				  default:
					u8_ErrorState=ERROR_UNSUPPORTED_CH;
					break;
				}
			}
		}
	}
	return u8_ErrorState;
}

ERROR_STATE_t BLUETOOTH_Scan(uint8_t BluetoothNumber)
{
	ERROR_STATE_t u8_ErrorState=ERROR_OK;
	BLUETOOTH_ATModeGetCommand(BluetoothNumber,(ptr_uint8_t)BLUETOOTH_CMD_GET_INQ);
	return u8_ErrorState;
}

ERROR_STATE_t BLUETOOTH_Connect(uint8_t BluetoothNumber,ptr_uint8_t DeviceMac)
{
	ERROR_STATE_t u8_ErrorState=ERROR_OK;
	while(ERROR_OK!=BLUETOOTH_ATModeSetCommand(	BluetoothNumber,(ptr_uint8_t)BLUETOOTH_CMD_SET_LINK,DeviceMac));											
	return u8_ErrorState;
}

ERROR_STATE_t BLUETOOTH_Disconnect(uint8_t BluetoothNumber)
{
	ERROR_STATE_t u8_ErrorState=ERROR_OK;
	BLUETOOTH_SetATMode(BluetoothNumber);
	return u8_ErrorState;
}