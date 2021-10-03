/*
 * SevenSeg.c
 *
 * Created: 7/25/2021 4:47:13 PM
 * Author: Mohamed Wagdy
 */ 

/*- INCLUDES
----------------------------------------------*/
#include "SevenSeg.h"

/*- LOCAL MACROS
------------------------------------------*/
#define DATA_PINS_NUMBER      (uint8_t)(4)
#define MAX_DISPLAY_NUMBER    (uint8_t)(9)

/*- LOCAL FUNCTIONS PROTOTYPES
----------------------------*/
static void SevenSeg_ClearEnable(void);

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t gu8_IsInit[SEVEN_SEG_NUMBERS] = {NOT_INIT};
   
/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const STR_SEVEN_SEG_config_t aSTR_SevenSegConfig[SEVEN_SEG_NUMBERS];

/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------*/
/**
* @brief: This function Clear all Segments Enable Bits.
*/
static void SevenSeg_ClearEnable(void)
{
   /* Loop on all channels */
   for(uint8_t u8_ChannelCounter = 0; u8_ChannelCounter < SEVEN_SEG_NUMBERS; u8_ChannelCounter++)
   {
      /* Set enable pin to low. */
      DIO_WritePin(aSTR_SevenSegConfig[u8_ChannelCounter].u8_EnPort, aSTR_SevenSegConfig[u8_ChannelCounter].u8_EnPin, PIN_LOW);
   }
}

/*- APIs IMPLEMENTATION
-----------------------------------*/
/**
* @brief: This function initializes a Seven segment channel.
*
* @param [in]  Channel   -  Channel number.
*
* @return function error state.
*/
extern ERROR_STATE_t SevenSeg_Init(const uint8_t Channel)
{
   /* Variable to store function error state. */
   ERROR_STATE_t SevenSeg_ErrorState;
   
   /* Validate valid Parameters are passed. */
   if(SEVEN_SEG_INVALID_CH <= Channel)
   {
      /* Set invalid channel error. */
      SevenSeg_ErrorState = (E_SEVEN_SEG_ID | E_SEVEN_SEG_INVALID_CH);
   }
   else if(INIT == gu8_IsInit[Channel])
   {
      /* Set initialized before error. */
      SevenSeg_ErrorState = (E_SEVEN_SEG_ID | E_SEVEN_SEG_INIT_BEFORE);
   }
   else
   {
      /* Set enable pin direction to output. */
      DIO_SetPinDirection(aSTR_SevenSegConfig[Channel].u8_EnPort, aSTR_SevenSegConfig[Channel].u8_EnPin, PIN_OUTPUT);
      /* loop on data pins. */
      for(uint8_t u8_DataPinsCounter = 0; u8_DataPinsCounter < DATA_PINS_NUMBER; u8_DataPinsCounter++)
      {
         /* Set the data pin direction to output. */
         DIO_SetPinDirection(
            aSTR_SevenSegConfig[Channel].u8_DataPort, 
            (aSTR_SevenSegConfig[Channel].u8_DataPinStart + u8_DataPinsCounter), 
            PIN_OUTPUT
         );
      }    
      /* Set channel to initialized. */    
      gu8_IsInit[Channel] = INIT;
      SevenSeg_ErrorState = ERROR_OK;
   }
   
   /* return Error state. */
   return SevenSeg_ErrorState;
}

/**
* @brief: This function gets the pressed button value on the keypad.
*
* @param [in]  KP_CH    -  Keypad channel number.
* @param [out] Data     -  Pressed Key Value.
*
* @return function error state.
*/
ERROR_STATE_t SevenSeg_Display(const uint8_t Channel, const uint8_t Number)
{
   /* Variable to store function error state. */
   ERROR_STATE_t SevenSeg_ErrorState;
   
   /* Validate valid Parameters are passed. */
   if(SEVEN_SEG_INVALID_CH <= Channel)
   {
      /* Set invalid channel error. */
      SevenSeg_ErrorState = (E_SEVEN_SEG_ID | E_SEVEN_SEG_INVALID_CH);
   }
   else if(INIT != gu8_IsInit[Channel])
   {
      /* Set not initialized error. */
      SevenSeg_ErrorState = (E_SEVEN_SEG_ID | E_SEVEN_SEG_NOT_INIT);
   }
   else if(MAX_DISPLAY_NUMBER < Number)
   {
      /* Set invalid number error. */
      SevenSeg_ErrorState = (E_SEVEN_SEG_ID | E_SEVEN_SEG_INVALID_NUMBER);
   }
   else
   {
      /* Clear all enable pins */
      SevenSeg_ClearEnable();
      /* Loop on data pins. */
      for(uint8_t u8_DataPinsCounter = 0; u8_DataPinsCounter < DATA_PINS_NUMBER; u8_DataPinsCounter++)
      {
         /* Write the pin value. */
         DIO_WritePin(
         aSTR_SevenSegConfig[Channel].u8_DataPort,
         (aSTR_SevenSegConfig[Channel].u8_DataPinStart + u8_DataPinsCounter),
         ((Number >> u8_DataPinsCounter) & (1))
         );
      }
      /* Set enable pin to high. */
      DIO_WritePin(aSTR_SevenSegConfig[Channel].u8_EnPort, aSTR_SevenSegConfig[Channel].u8_EnPin, PIN_HIGH);
      SevenSeg_ErrorState = ERROR_OK;
   }
   
   /* return Error state. */
   return SevenSeg_ErrorState;
}