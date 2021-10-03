/*
 * USONIC.c
 *
 *  Created on: Aug 9, 2021
 *      Author: Ahmed
 */
/*INCLUDES-------------------------------*/
#include "USONIC.h"

/*LOCAL MACROS--------------------------*/
#define TRIG_TIME   (uint8_t)10
#define SOUND_SPPED  34300
#define HALF_DISTANCE 2
#define COUNTER_RESET 0
#define TIME_RESET 0
#define PRELOAD_10U 65534
/*----GLOBAL STATIC VARIABLES----*/
static ERROR_STATE_t gu8_ERROR_STATE = ERROR_OK;
static uint8_t gu8_InitFlag = NOT_INIT;
extern const STR_USONIC_config_t gastr_USONIC_Config[USONIC_NUMBER];
extern const uint32_t gu32_USONIC_SystemFreq; 

volatile uint16_t gu16_OverflowCounter=COUNTER_RESET;
volatile static uint8_t gu8_ICU_State=START_STATE;
volatile double64_t TimeOnValue=TIME_RESET;

static void USONIC_OVF1Callback(void);
static void USONIC_ICU1Callback(void);

/*APIs IMPLEMENTATION------------------------*/
/*
 * THIS API INITIALIZE THE ULTRASONIC
 * */
ERROR_STATE_t USONIC_Init(void) {
	/*CHECK IF ULTASONIC HAS BEEN INITIALIZED*/
	if (INIT == gu8_InitFlag) //IF ULTRA SONIC IS INITIALIZED
	{
		gu8_ERROR_STATE = USONIC_SEC_INIT; //STORE SEC INIT IN ERRROR STAT
	} 
	else if (NOT_INIT == gu8_InitFlag) //IF ULTRA SONIC IS NOT INITIALIZED
	{
		DIO_SetPinDirection(gastr_USONIC_Config[USONIC1].USONIC_TRIG_PORT, gastr_USONIC_Config[USONIC1].USONIC_TRIG_PIN, PIN_OUTPUT);//SET THE TRIGGER PIN AS AN OUTPUT
		ICU_Init(ICU_1); //INIT THE ICU CH 1
		
		ICU_SetCallback(ICU_1,ICU1_INPUTCAPTURE_INT,USONIC_ICU1Callback);
		ICU_SetCallback(ICU_1,ICU1_OVERFLOW_INT,USONIC_OVF1Callback);
		GLOBALINTTERUPTS_Enable();
	
		gu8_InitFlag = INIT;
		gu8_ERROR_STATE=ERROR_OK;
	} 
	else 
	{
		//DO NOTHING
	}
	return gu8_ERROR_STATE ;
}

ERROR_STATE_t USONIC_GetDistance(ptr_double64_t distance)
{
	/*CHECK IF ULTASONIC HAS BEEN INITIALIZED*/
	if (NOT_INIT == gu8_InitFlag) //IF ULTRA SONIC IS NOT INITIALIZED
	{ 
		gu8_ERROR_STATE = USONIC_NOT_INIT; //STORE NOT INIT IN ERRROR STAT
	} 
	else if(INIT == gu8_InitFlag) //IF ULTRA SONIC IS INITIALIZED
	{ 
		/* CHECK IF ptr_float32_t distance EQUALS NULL */
		if (NULL_PTR == distance) 
		{
			gu8_ERROR_STATE = USONIC_NULL_POINTER; //STORE NOT INIT IN ERRROR STAT
		} 
		else 
		{
			switch(gu8_ICU_State)
			{
				case START_STATE:
				{
					gu8_ICU_State=WAITING_RISING_EDGE_STATE;
					DIO_WritePin(USONIC_TRIG_PORT, USONIC_TRIG_PIN, PIN_HIGH); //SET TRIGGER PIN
					gu16_OverflowCounter=COUNTER_RESET;
					ICU_SetTCNT1Registert(ICU_1,PRELOAD_10U);
					ICU_EnableInterrupt(ICU_1,ICU1_OVERFLOW_INT);
					while(gu16_OverflowCounter<1);
					DIO_WritePin(USONIC_TRIG_PORT, USONIC_TRIG_PIN, PIN_LOW);
					ICU_Reset(ICU_1,ICU1_RISING_EDGE);
					ICU_EnableInterrupt(ICU_1,ICU1_INPUTCAPTURE_INT);
					gu8_ERROR_STATE=ERROR_NOK;
					break;
				}
				case END_STATE:
				{
					*distance = (((SOUND_SPPED) * TimeOnValue) / HALF_DISTANCE);
					gu8_ERROR_STATE=ERROR_OK;
					gu8_ICU_State=START_STATE;
					break;
				}
				default:
				break;
			}			
		}	
	}					
	else
	{
			
	}
	return gu8_ERROR_STATE;	
}

static void USONIC_ICU1Callback(void)
{
	volatile static  uint64_t CounterNumber;
	volatile static  uint16_t ICR1_Register;
 
	switch(gu8_ICU_State)
	{
			case WAITING_RISING_EDGE_STATE: //Rising 
			{
				gu16_OverflowCounter=0;
				gu8_ICU_State=WAITING_FALLING_EDGE_STATE;
				ICU_Reset(ICU_1,ICU1_FALLING_EDGE);
				break;
			}		 
			case WAITING_FALLING_EDGE_STATE: //Falling
			{
				ICU_GetICR1Registert(ICU_1,&ICR1_Register);
				CounterNumber=(uint64_t)(ICR1_Register+(gu16_OverflowCounter*ICU1_MAX_COUNT));			
				TimeOnValue = (CounterNumber*((double)gastr_ICUConfig[ICU_1].ICUPrescaler/gu32_USONIC_SystemFreq));
				gu8_ICU_State=END_STATE;
				ICU_DisableInterrupt(ICU_1,ICU1_INPUTCAPTURE_INT);
				ICU_DisableInterrupt(ICU_1,ICU1_OVERFLOW_INT);
				break;
			}			
			default:
				break;
	}
}

static void USONIC_OVF1Callback(void)
{
	gu16_OverflowCounter++; 
}