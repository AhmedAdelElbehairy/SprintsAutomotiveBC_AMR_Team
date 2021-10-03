/*- INCLUDES----------------------------------*/
#include "BIT_MATH.h"
#include "UART.h"
#include "GLOBAL_Interrupt.h"
#include "STORAGE.h"
#include "Indicator_Interface.h"
#include "BLUETOOTH_Mng.h"

/*- LOCAL MACROS------------------------------*/
#define BT_STATE_INIT							(uint8_t)(0)
#define BT_STATE_SELFTEST						(uint8_t)(1)
#define BT_STATE_CHECKEEPROM					(uint8_t)(2)
#define BT_STATE_CRC16							(uint8_t)(3)
#define BT_STATE_SCANNING						(uint8_t)(4)
#define BT_STATE_SCANNING_END					(uint8_t)(5)
#define BT_STATE_LINKING						(uint8_t)(6)
#define BT_STATE_HANDSHAKE						(uint8_t)(7)
#define BT_STATE_DEVICEDATA					(uint8_t)(8)
#define BT_STATE_CONNECTED						(uint8_t)(9)
#define BT_STATE_ERROR							(uint8_t)(10)
#define BT_INIT_PENDING                         (uint8_t)(11)

#define STATE_CHECKING							(uint8_t)(0)
#define STATE_SENDING_KD						(uint8_t)(1)
#define STATE_SENDING_PC						(uint8_t)(2)

#define BLUETOOTH_BAUDRATE_NUMBERS       		(uint8_t) (6)

#define BLUETOOTH_START_OF_MAC   				(uint8_t) (5)

/*Buffer lengths*/	
#define BLUETOOTH_RX_BUFFER_LEN	         		(uint8_t) (50)
#define BLUETOOTH_MAC_BUFFER_LEN	     		(uint8_t) (20)
#define BLUETOOTH_RX_ARRAY_SIZE					(uint8_t) (8)

/*Rx States*/
#define BLUETOOTH_RX_PENDING         	 		(uint8_t) (0)
#define BLUETOOTH_RX_COMPLETE	     	 		(uint8_t) (1)
#define BLUETOOTH_MNG_MAX_RETIRES 	     	 	(uint8_t) (5)

#define BLUETOOTH_HEADER_INDEX	     	 		(uint8_t) (0x00)
#define BLUETOOTH_TYPE_INDEX	     	 					(uint8_t) (0x01)
#define BLUETOOTH_DATA_INDEX	     	 					(uint8_t) (0x03)

#define BLUETOOTH_PACKET_HEADER	     	 					(uint8_t) (0xAA)

/*Handshake Packet*/
#define BLUETOOTH_HANDSHAKE_PACKET_LEN	 					(uint8_t) (9)
#define BLUETOOTH_HS_PACKET_TYPE	     	 				(uint8_t) (0x01)
#define BLUETOOTH_HS_DATA_LEN     	 						(uint8_t) (0x03)
#define BLUETOOTH_HS_PACKET_DATA_1	     	 				(uint8_t) (0x41)
#define BLUETOOTH_HS_PACKET_DATA_2	     	 				(uint8_t) (0x45)
#define BLUETOOTH_HS_PACKET_DATA_3	     	 				(uint8_t) (0x48)

/*Device Data Packet*/
#define BLUETOOTH_DD_PACKET_LEN	 						(uint8_t) (25)
#define BLUETOOTH_DD_PACKET_TYPE	     	 			(uint8_t) (0x02)
#define BLUETOOTH_DD_DATA_LEN	     	 				(uint8_t) (0x13)

#define BLUETOOTH_DD_PACKET_START_OF_MAC	     	 		(uint8_t) (10)

/*Keypad Data Packet*/
#define BLUETOOTH_KD_PACKET_LEN	 							(uint8_t) (7)
#define BLUETOOTH_KD_PACKET_TYPE	     	 				(uint8_t) (0x03)
#define BLUETOOTH_KD_DATA_LEN	     	 					(uint8_t) (0x01)

/*Password Change Packet*/
#define BLUETOOTH_PC_PACKET_LEN	 							(uint8_t) (6)
#define BLUETOOTH_PC_PACKET_TYPE	     	 				(uint8_t) (0x04)
#define BLUETOOTH_PC_DATA_LEN	     	 					(uint8_t) (0x00)

/*- GLOBAL EXTEN VARIABLES-------------------------------*/
extern STR_BLUETOOTH_config_t gastr_BLUETOOTH_Config[BLUETOOTH_NUMBERS];/*Bluetooth modules config*/
extern STR_BLUETOOTH_Mng_config_t gastr_BLUETOOTH_Mng_Config[BLUETOOTH_NUMBERS];

/*- LOCAL FUNCTIONS PROTOTYPES----------------------------*/
static ERROR_STATE_t BLUETOOTH_Mng_Init(void);
static void BLUETOOTH_Mng_RxCallback(void);
static ERROR_STATE_t BT_Mng_SelfTest(void);
static ERROR_STATE_t BT_Mng_SetConfig(void);
static ERROR_STATE_t BT_Mng_SendHandShake(void);
static ERROR_STATE_t BT_Mng_SendDeviceData(void);

static ERROR_STATE_t BT_Mng_ExtractMAC(ptr_uint8_t ScanedMAC,ptr_uint8_t MACBuffer);
static void BT_Mng_InsertMAC(uint8_t StartIndex,ptr_uint8_t DeviceDataPacket,ptr_uint8_t ExtractedMac);

/*- GLOBAL STATIC VARIABLES-------------------------------*/
const static STR_BAUDRATE_CFG_t gastr_BuadRate_CFG[BLUETOOTH_BAUDRATE_NUMBERS]={
																					{ BLUETOOTH_UART_PARAM_9600   , BAUDRATE_9600  },
																					{ BLUETOOTH_UART_PARAM_19200  , BAUDRATE_19200 },
																					{ BLUETOOTH_UART_PARAM_38400  , BAUDRATE_38400 },
																					{ BLUETOOTH_UART_PARAM_57600  , BAUDRATE_57600 },
																					{ BLUETOOTH_UART_PARAM_115200 , BAUDRATE_115200},
																					{ BLUETOOTH_UART_PARAM_230400 , BAUDRATE_230400}
																				};

volatile static uint8_t gu8_RX_Buffer_Counter=BLUETOOTH_INQ_DEVICES_NUMBERS;

static uint8_t gau8_BLUETOOTH_RX_Buf[BLUETOOTH_RX_ARRAY_SIZE][BLUETOOTH_RX_BUFFER_LEN]={{NULL_TERMINATOR}};

static uint8_t gu8_BLUETOOTH_MACAddressBuf[BLUETOOTH_MAC_BUFFER_LEN]={NULL_TERMINATOR};

static uint8_t gu8_BLUETOOTH_HandShakePacket[BLUETOOTH_HANDSHAKE_PACKET_LEN]={
																					BLUETOOTH_PACKET_HEADER,
																					BLUETOOTH_HS_PACKET_TYPE,
																					BLUETOOTH_HS_DATA_LEN,
																					BLUETOOTH_HS_PACKET_DATA_1,
																					BLUETOOTH_HS_PACKET_DATA_2,
																					BLUETOOTH_HS_PACKET_DATA_3,
																					NULL_TERMINATOR
																				};
static uint8_t gu8_BLUETOOTH_DeviceDataPacket[BLUETOOTH_DD_PACKET_LEN]={
																					BLUETOOTH_PACKET_HEADER,
																					BLUETOOTH_DD_PACKET_TYPE,
																					BLUETOOTH_DD_DATA_LEN,
																					NULL_TERMINATOR
																				};
static uint8_t gu8_BLUETOOTH_PasswordChangePacket[BLUETOOTH_PC_PACKET_LEN]={
																					BLUETOOTH_PACKET_HEADER,
																					BLUETOOTH_PC_PACKET_TYPE,
																					BLUETOOTH_PC_DATA_LEN,
																					NULL_TERMINATOR
																					};	
static uint8_t gu8_BLUETOOTH_KeypadDataPacket[BLUETOOTH_KD_PACKET_LEN]={
																					BLUETOOTH_PACKET_HEADER,
																					BLUETOOTH_KD_PACKET_TYPE,
																					BLUETOOTH_KD_DATA_LEN,
																					NULL_TERMINATOR
																					};																				
static uint8_t gu8_BLUETOOTH_RXCOM_FLAG=BLUETOOTH_RX_PENDING;

/*- LOCAL FUNCTIONS IMPLEMENTATION------------------------*/
/**
* @brief: This function Extract MAC from scaned data.
*/
/******************************************************************************/
static void BT_Mng_InsertMAC(uint8_t StartIndex,ptr_uint8_t DeviceDataPacket,ptr_uint8_t ExtractedMac)
{
		uint8_t u8_ExtractedMAC_counter=ZERO;
		uint8_t u8_DeviceDataCounter=StartIndex;

		while(END_OF_STRING!=ExtractedMac[u8_ExtractedMAC_counter])
		{
			if(COMMA==ExtractedMac[u8_ExtractedMAC_counter])
			{
				u8_ExtractedMAC_counter++;
			}
			else
			{
				DeviceDataPacket[u8_DeviceDataCounter]=ExtractedMac[u8_ExtractedMAC_counter];
				u8_ExtractedMAC_counter++;
				u8_DeviceDataCounter++;

			}
		}
		DeviceDataPacket[u8_DeviceDataCounter]=END_OF_STRING;
}
static ERROR_STATE_t BT_Mng_ExtractMAC(ptr_uint8_t ScanedMAC,ptr_uint8_t MACBuffer)
{
	ERROR_STATE_t u8_ErrorState = ERROR_OK;
	uint8_t u8_ScanedMAC_counter=BLUETOOTH_START_OF_MAC;
    uint8_t u8_BufferCounter=ZERO;

    while(COMMA!=ScanedMAC[u8_ScanedMAC_counter])
    {
        if(COLON!=ScanedMAC[u8_ScanedMAC_counter])
        {
            MACBuffer[u8_BufferCounter]=ScanedMAC[u8_ScanedMAC_counter];

        }
        else
        {
             MACBuffer[u8_BufferCounter]=COMMA;

        }
        u8_ScanedMAC_counter++;
        u8_BufferCounter++;
    }
    MACBuffer[u8_BufferCounter]=END_OF_STRING;
	return u8_ErrorState;
}
/******************************************************************************/
/**
* @brief: This function make a selftest.
*/
static void BLUETOOTH_Mng_RxCallback(void)
{
	if(BLUETOOTH_RX_ARRAY_SIZE==gu8_RX_Buffer_Counter)
	{
		gu8_RX_Buffer_Counter=BLUETOOTH_INQ_DEVICES_NUMBERS;
		gu8_BLUETOOTH_RXCOM_FLAG=ZERO;
	}
	/*check if the receive has been done*/
	if(ERROR_OK==BLUETOOTH_ReceiveData(BLUETOOTH_0,gau8_BLUETOOTH_RX_Buf[gu8_RX_Buffer_Counter]))
	{
		/*Set the flag for the current buffer*/
		SET_BIT(gu8_BLUETOOTH_RXCOM_FLAG,gu8_RX_Buffer_Counter);
		/*increament the counter*/
		gu8_RX_Buffer_Counter++;
	}
	else
	{
		/*Do Nothing*/
	}	
}
/**
* @brief: This function make a selftest
*/
static ERROR_STATE_t BT_Mng_SelfTest(void)
{
	ERROR_STATE_t u8_ErrorState = ERROR_OK;
	ERROR_STATE_t u8_BaudCounter = ZERO;
	/*First check if the bluetooth is already configured to the desired*/
	UART_SetBaudRate((gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH),
					(gastr_BuadRate_CFG[u8_BaudCounter].u32_UART_BUADRATE));
	/*Send AT to bluetooth*/					
	BLUETOOTH_ATModeGetCommand(BLUETOOTH_0,(ptr_uint8_t)BLUETOOTH_CMD_AT);
	/*Wait for flag to set or for timeout*/
	/*(TIMEOUT) WITH RTOS*/
	if(BLUETOOTH_RX_PENDING==GET_BIT(gu8_BLUETOOTH_RXCOM_FLAG,(gu8_RX_Buffer_Counter-ONE)))
	{
		/*IF NOTHING HAS BEEN RECEIVED WAIT TILL TIME OUT THEN BREAK*/
		for(u8_BaudCounter=ZERO;u8_BaudCounter<BLUETOOTH_BAUDRATE_NUMBERS;u8_BaudCounter++)
		{
			UART_SetBaudRate((gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH),
							(gastr_BuadRate_CFG[u8_BaudCounter].u32_UART_BUADRATE));	
			BLUETOOTH_ATModeGetCommand(	BLUETOOTH_0,(ptr_uint8_t)BLUETOOTH_CMD_AT);
			/*IF NOTHING HAS BEEN RECEIVED WAIT TILL TIME OUT THEN BREAK*/
			/*(TIMEOUT) WITH RTOS*/
			if(BLUETOOTH_RX_COMPLETE==GET_BIT(gu8_BLUETOOTH_RXCOM_FLAG,(gu8_RX_Buffer_Counter-ONE)))
			{
				/*set the bluetooth baudrate to the current element in the arrray for the selftest*/
				while(ERROR_OK!=BLUETOOTH_ATModeSetCommand(	BLUETOOTH_0,(ptr_uint8_t)BLUETOOTH_CMD_SET_UART,
															(gastr_BLUETOOTH_Mng_Config[BLUETOOTH_0].STR_BLUETOOTH_Mng_BAUDRATE_Cng.au8_BLUETOOTH_BAUDRATE)));
				/*set the uart baudrate*/
				UART_SetBaudRate((gastr_BLUETOOTH_Config[BLUETOOTH_0].u8_BLUETOOTH_UART_CH),(gastr_BLUETOOTH_Mng_Config[BLUETOOTH_0].STR_BLUETOOTH_Mng_BAUDRATE_Cng.u32_UART_BUADRATE));
				break;	
			}
			else
			{
				/*Do Nothing.*/
			}

		}
		/*Bluetooth module does not respond to any buadrate*/
		u8_ErrorState = ERROR_NOK;		
	}
	else
	{
		/*Do Nothing*/
	}
	return u8_ErrorState;
}
/**
* @brief: This function Send handshake packet
*/
static ERROR_STATE_t BT_Mng_SendHandShake(void)
{
	ERROR_STATE_t u8_ErrorState = ERROR_NOK;
	uint8_t u8_RetiresCounter  = ZERO;
	for(u8_RetiresCounter=ZERO;u8_RetiresCounter<BLUETOOTH_MNG_MAX_RETIRES;u8_RetiresCounter++)
	{
		/*Send handshake pattern*/
		while(ERROR_NOK==BLUETOOTH_SendData(BLUETOOTH_0,gu8_BLUETOOTH_HandShakePacket));/*Send and wait for the transmission complete */
		/*(TIMEOUT 200 ms) WITH RTOS*/
		if(BLUETOOTH_RX_COMPLETE==GET_BIT(gu8_BLUETOOTH_RXCOM_FLAG,(gu8_RX_Buffer_Counter-ONE)))
		{
			if(TRUE==StringCompare(gau8_BLUETOOTH_RX_Buf[gu8_RX_Buffer_Counter-ONE],gu8_BLUETOOTH_HandShakePacket))
			{
				u8_ErrorState = ERROR_OK;
				break;
			}
			else
			{
				/*Do nothing*/
			}		
			CLR_BIT(gu8_BLUETOOTH_RXCOM_FLAG,(gu8_RX_Buffer_Counter-ONE));			
		}
		else
		{
				/*Do nothing*/
		}
				
	}
	return u8_ErrorState;	
}

/**
* @brief: This function Send device data
*/
static ERROR_STATE_t BT_Mng_SendDeviceData(void)
{
	ERROR_STATE_t u8_ErrorState = ERROR_NOK;
	uint8_t u8_RetiresCounter  = ZERO;
	for(u8_RetiresCounter=ZERO;u8_RetiresCounter<BLUETOOTH_MNG_MAX_RETIRES;u8_RetiresCounter++)
	{		
		/*Send handshake pattern*/
		while(ERROR_NOK==BLUETOOTH_SendData(BLUETOOTH_0,gu8_BLUETOOTH_DeviceDataPacket));/*Send and wait for the transmission complete */
		/*(TIMEOUT 200 ms) WITH RTOS*/
		if(BLUETOOTH_RX_COMPLETE==GET_BIT(gu8_BLUETOOTH_RXCOM_FLAG,(gu8_RX_Buffer_Counter-ONE)))
		{
			if(BLUETOOTH_DD_PACKET_TYPE==gau8_BLUETOOTH_RX_Buf[gu8_RX_Buffer_Counter-ONE][BLUETOOTH_TYPE_INDEX])
			{
				if(ERROR_OK==CRC_16_Chk(gau8_BLUETOOTH_RX_Buf[gu8_RX_Buffer_Counter-ONE]))
				{
					u8_ErrorState = ERROR_OK;
					break;
				}
				else
				{
					/*Do nothing*/
				}		
			}
			else
			{
				/*Do nothing*/
			}
			CLR_BIT(gu8_BLUETOOTH_RXCOM_FLAG,(gu8_RX_Buffer_Counter-ONE));
		}
		else
		{
			/*Do nothing*/
		}
	}
	return u8_ErrorState;
}
/**
* @brief: This function Set the configuration
*/

static ERROR_STATE_t BT_Mng_SetConfig(void)
{
	ERROR_STATE_t u8_ErrorState = ERROR_OK;
	
	//NAME
	while(ERROR_OK!=BLUETOOTH_ATModeGetCommand(	BLUETOOTH_0,(ptr_uint8_t)BLUETOOTH_CMD_GET_NAME));
	while(BLUETOOTH_RX_PENDING==GET_BIT(gu8_BLUETOOTH_RXCOM_FLAG,(gu8_RX_Buffer_Counter-ONE)));
	if(TRUE!=StringCompare(	gau8_BLUETOOTH_RX_Buf[gu8_RX_Buffer_Counter-ONE],
								gastr_BLUETOOTH_Mng_Config[BLUETOOTH_0].au8_BLUETOOTH_Mng_NAME))
	{
		while(ERROR_OK!=BLUETOOTH_ATModeSetCommand(	BLUETOOTH_0,
													(ptr_uint8_t)BLUETOOTH_CMD_SET_NAME,
													gastr_BLUETOOTH_Mng_Config[BLUETOOTH_0].au8_BLUETOOTH_Mng_NAME
													)
			);	
	}
	//ROLE
	while(ERROR_OK!=BLUETOOTH_ATModeGetCommand(	BLUETOOTH_0,(ptr_uint8_t)BLUETOOTH_CMD_GET_ROLE));
	while(BLUETOOTH_RX_PENDING==GET_BIT(gu8_BLUETOOTH_RXCOM_FLAG,(gu8_RX_Buffer_Counter-ONE)));
	if(TRUE!=StringCompare(	gau8_BLUETOOTH_RX_Buf[gu8_RX_Buffer_Counter-ONE],
								gastr_BLUETOOTH_Mng_Config[BLUETOOTH_0].u8_BLUETOOTH_Mng_MODE))
	{
		while(ERROR_OK!=BLUETOOTH_ATModeSetCommand(	BLUETOOTH_0,
													(ptr_uint8_t)BLUETOOTH_CMD_SET_ROLE,
													gastr_BLUETOOTH_Mng_Config[BLUETOOTH_0].u8_BLUETOOTH_Mng_MODE
													)
			);	
	}
	
	//PIN
	while(ERROR_OK!=BLUETOOTH_ATModeGetCommand(	BLUETOOTH_0,(ptr_uint8_t)BLUETOOTH_CMD_GET_PSWD));
	while(BLUETOOTH_RX_PENDING==GET_BIT(gu8_BLUETOOTH_RXCOM_FLAG,(gu8_RX_Buffer_Counter-ONE)));
	if(TRUE!=StringCompare(	gau8_BLUETOOTH_RX_Buf[gu8_RX_Buffer_Counter-ONE],
								gastr_BLUETOOTH_Mng_Config[BLUETOOTH_0].au8_BLUETOOTH_Mng_PASSWORD))
	{
		while(ERROR_OK!=BLUETOOTH_ATModeSetCommand(	BLUETOOTH_0,
													(ptr_uint8_t)BLUETOOTH_CMD_SET_PSWD,
													gastr_BLUETOOTH_Mng_Config[BLUETOOTH_0].au8_BLUETOOTH_Mng_PASSWORD
													)
			);	
	}
	/*Send at cmd to get the bluetooth mac address*/
	while(ERROR_OK!=BLUETOOTH_ATModeGetCommand(	BLUETOOTH_0,(ptr_uint8_t)BLUETOOTH_CMD_GET_ADD));
	/*wiat for the flag to set*/
	while(BLUETOOTH_RX_PENDING==GET_BIT(gu8_BLUETOOTH_RXCOM_FLAG,(gu8_RX_Buffer_Counter-ONE)));
	/*Get the address and save it in the buffer*/
	BT_Mng_ExtractMAC(gau8_BLUETOOTH_RX_Buf[gu8_RX_Buffer_Counter-ONE],gu8_BLUETOOTH_MACAddressBuf);
	/*Set the address in the packet*/
	BT_Mng_InsertMAC(BLUETOOTH_DD_PACKET_START_OF_MAC,gu8_BLUETOOTH_DeviceDataPacket,gu8_BLUETOOTH_MACAddressBuf);
	return u8_ErrorState;	
}

/**
* @brief: This function init the bluetooth manger
*/
static ERROR_STATE_t BLUETOOTH_Mng_Init(void)
{
	static int8_t s8_MAC_Counter=ZERO;
    ERROR_STATE_t u8_ErrorState = BT_INIT_PENDING;
    static ERROR_STATE_t u8_CurrentState = BT_STATE_INIT;
	
	switch(u8_CurrentState){
		case BT_STATE_INIT:/*INIT*/
			/*Initialize the bluetooth*/
			BLUETOOTH_Init();
			/*Enable the uart rx interrupt*/
			UART_EnableInterrupt(UART_CH_0,RX_INT);
			/*Set the call back function in the uart rx isr*/
			UART_SetCallback(UART_CH_0,RX_INT,BLUETOOTH_Mng_RxCallback);
			/*Set the global interrupt bit*/
			GLOBALINTTERUPTS_Enable();
			/*Move to selftest state */
			u8_CurrentState=BT_STATE_SELFTEST;
			break;
		case BT_STATE_SELFTEST:
			if(ERROR_OK==BT_Mng_SelfTest())
			{
				
				STR_StringConcatenate(gu8_BLUETOOTH_DeviceDataPacket,gastr_BLUETOOTH_Mng_Config[BLUETOOTH_0].au8_BLUETOOTH_Mng_NAME);				
				BT_Mng_SetConfig();			
				
				/*Set the indecator to search pattern*/
				Indicator_SetPattern(INDICATOR_SEARCH_PATTERN);
				/*Set state to check eeprom*/
				u8_CurrentState=BT_STATE_CHECKEEPROM;
			}
			else
			{
				/*Set state to error state*/
				u8_CurrentState=BT_STATE_ERROR;
			}
			break;		
		case BT_STATE_CHECKEEPROM:
				/*Check if there already MACs saved in EEPROM*/
				#if 0
				if(ERROR_OK==STORAGE_MAC_Load(gu8_BLUETOOTH_MACAddressBuf))
				{
					/*This state mean bluetooth already connected to a device*/
					/*Connect to this mac address*/
					
					/*Set state to connected*/
					u8_CurrentState=BT_STATE_CONNECTED;
				}
				else
				{
					/*This mean bluetooth isn't saved in the eeprom*/
					u8_CurrentState=BT_STATE_CRC16;
				}
				#endif
			break;
		case BT_STATE_CRC16:
				while(ERROR_OK!=BLUETOOTH_ATModeSetCommand(	BLUETOOTH_0,(ptr_uint8_t)BLUETOOTH_CMD_SET_INQM,(ptr_uint8_t)BLUETOOTH_INQM));
				if(TRUE==StringCompare((ptr_uint8_t)BLUETOOTH_OK,gau8_BLUETOOTH_RX_Buf[gu8_RX_Buffer_Counter-ONE]))
				{
					/*Calc CRC for the handshake pattern packet*/
					CRC_16_Calc(gu8_BLUETOOTH_HandShakePacket);
					/*Calc CRC for the device data pattern packet*/
					CRC_16_Calc(gu8_BLUETOOTH_DeviceDataPacket);
					/*Calc CRC for the device data pattern packet*/
					CRC_16_Calc(gu8_BLUETOOTH_PasswordChangePacket);
					u8_CurrentState=BT_STATE_SCANNING;
				}
				else
				{
					/*Do Nothing*/
				}											
				break;
		case BT_STATE_SCANNING:
				gu8_BLUETOOTH_RXCOM_FLAG=ZERO;
				gu8_RX_Buffer_Counter=ZERO;
				s8_MAC_Counter=ZERO;
				BLUETOOTH_Scan(BLUETOOTH_0);
				u8_CurrentState=BT_STATE_SCANNING_END;
				break;
		case BT_STATE_SCANNING_END:		
				if(BLUETOOTH_RX_COMPLETE==GET_BIT(gu8_BLUETOOTH_RXCOM_FLAG,BLUETOOTH_INQ_DEVICES_NUMBERS))
				{
					/*Move to Linking state*/
					u8_CurrentState=BT_STATE_LINKING;
				}
				else
				{
					/*Do Nothing*/
				}
				break;
		case BT_STATE_LINKING:
				if(s8_MAC_Counter<BLUETOOTH_INQ_DEVICES_NUMBERS)
				{
					/******************************************************************************/
					if(ERROR_OK==BT_Mng_ExtractMAC(gau8_BLUETOOTH_RX_Buf[s8_MAC_Counter],gu8_BLUETOOTH_MACAddressBuf))
					/******************************************************************************/
					{	
						/*Connect to this devices*/
						BLUETOOTH_Connect(BLUETOOTH_0, gu8_BLUETOOTH_MACAddressBuf);
						while(BLUETOOTH_RX_PENDING==GET_BIT(gu8_BLUETOOTH_RXCOM_FLAG,(gu8_RX_Buffer_Counter-ONE)));
						if(TRUE==StringCompare((ptr_uint8_t)BLUETOOTH_OK,gau8_BLUETOOTH_RX_Buf[gu8_RX_Buffer_Counter-ONE]))
						{
							BLUETOOTH_SetDataMode(BLUETOOTH_0);
							/*Set the indecator to verification pattern*/
							Indicator_SetPattern(INDICATOR_VERIFICATION_PATTERN);
							/*Move to handshake state*/
							u8_CurrentState=BT_STATE_HANDSHAKE;	
						}
						else
						{
							/*Do Nothing*/
						}
					}
					else
					{
						/*Do Nothing*/
					}
					s8_MAC_Counter++;
				}
				else
				{
					/*Move to scan state*/
					u8_CurrentState=BT_STATE_SCANNING;
				}
				
			break;
		case BT_STATE_HANDSHAKE:
				if(ERROR_NOK==BT_Mng_SendHandShake())
				{
					/*Need to get fixed*/
					BLUETOOTH_Disconnect(BLUETOOTH_0);
					/*Set the indecator to search pattern*/
					Indicator_SetPattern(INDICATOR_SEARCH_PATTERN);
					/*Move to Linking state*/
					u8_CurrentState=BT_STATE_LINKING;
				}
				else
				{
					/*Set the indecator to connect on pattern*/
					Indicator_SetPattern(INDICATOR_CONNECTED_PATTERN);
					/*Move to device data state*/
					u8_CurrentState=BT_STATE_DEVICEDATA;
				}
			break;
		case BT_STATE_DEVICEDATA:
				
				if(ERROR_NOK==BT_Mng_SendDeviceData())
				{
					/*Need to get fixed*/
					BLUETOOTH_Disconnect(BLUETOOTH_0);
					/*Set the indecator to search pattern*/
					Indicator_SetPattern(INDICATOR_SEARCH_PATTERN);
					/*Move to scan state*/
					u8_CurrentState=BT_STATE_LINKING;
				}
				else
				{
					/*Save to EEPROM*/
					STORAGE_MAC_Save(gu8_BLUETOOTH_MACAddressBuf);
					STORAGE_DataPacket_Save(gau8_BLUETOOTH_RX_Buf[gu8_RX_Buffer_Counter-ONE]);
					/*Move to connected state*/
					u8_CurrentState=BT_STATE_CONNECTED;
				}
			break;
		case BT_STATE_CONNECTED:
				/*Connected*/
				u8_ErrorState = ERROR_OK;
			break;
		case BT_STATE_ERROR:
				/*Set the indecator to malfunction pattern*/
				Indicator_SetPattern(INDICATOR_MALFUNCTION_PATTERN);
				/*Error state*/
				u8_ErrorState = ERROR_NOK;
			break;
		default:
			break;
	}	
   return u8_ErrorState;
}

/*- APIs IMPLEMENTATION-----------------------------------*/
/**
* @brief: This function.
*/
extern void BLUETOOTH_Mng_MainFunction(void)
{
	static uint8_t u8_BT_INIT_Flag=NOT_INIT;
	static uint8_t u8_BT_MNG_ErrorState=BT_INIT_PENDING;
	static uint8_t u8_BT_PC_Flag=ZERO;
	static uint8_t u8_BT_KP_Data=ZERO;
	static uint8_t u8_BT_State=STATE_CHECKING;
	/*Check if the moduled has been init before*/
	if(NOT_INIT==u8_BT_INIT_Flag)
	{
		u8_BT_INIT_Flag=BLUETOOTH_Mng_Init();
		if(BT_INIT_PENDING!=u8_BT_MNG_ErrorState)
		{
			u8_BT_INIT_Flag=INIT;
		}
		else
		{
			/*Do nothing*/
		}
	}	
	/*If not call the init function*/
	if((INIT==u8_BT_INIT_Flag)&&(ERROR_OK==u8_BT_MNG_ErrorState))
	{
		/*OUR LOGIC*/		
		switch(u8_BT_State)
		{
			case STATE_CHECKING:
				//HMI_GetPasswordChangeFlag(&u8_BT_PC_Flag);
				if(TRUE==u8_BT_PC_Flag)
				{
					u8_BT_State=STATE_SENDING_PC;
				}
				//HMI_GetKeyPressed(&u8_BT_KP_Data);
				if(ZERO!=u8_BT_KP_Data)
				{		
					u8_BT_State=STATE_SENDING_KD;
				}								
				break;
			case STATE_SENDING_KD:
				/*SEND KEYPAD DATA PACKET*/
				/*Store Null after the data for the CRC*/
				gu8_BLUETOOTH_KeypadDataPacket[BLUETOOTH_DATA_INDEX+ONE]=END_OF_STRING;
				/*Store the data in the data index*/
				gu8_BLUETOOTH_KeypadDataPacket[BLUETOOTH_DATA_INDEX]=u8_BT_KP_Data;
				/*calculate the CRC*/
				CRC_16_Calc (gu8_BLUETOOTH_KeypadDataPacket);
				/*Send the packet */
				if(ERROR_OK==BLUETOOTH_SendData(BLUETOOTH_0,gu8_BLUETOOTH_KeypadDataPacket))
				{
					u8_BT_State=STATE_CHECKING;	
				}
				break;
			case STATE_SENDING_PC:
				/*SEND PASSWORD CHANGE PACKET*/
				if(ERROR_OK==BLUETOOTH_SendData(BLUETOOTH_0,gu8_BLUETOOTH_PasswordChangePacket))
				{
					u8_BT_State=STATE_CHECKING;				
				}
				break;	
			default:
				break;												
		}
	}
	else
	{
		/*Set any indecator*/
	}
}