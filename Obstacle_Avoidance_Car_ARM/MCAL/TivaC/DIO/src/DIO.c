/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.c
 *       Module:  DIO
 *
 *  Description:  source file for DIO module.
 *
 *********************************************************************************************************************/
/*- INCLUDES
----------------------------------------------*/
#include "DIO.h"
#include "Mcu_Hw.h"
#include "Bit_Math.h"

/*- LOCAL MACROS
------------------------------------------*/
#define INVALID_PORT_ID         (uint8_t)(6)
#define INVALID_PIN_ID          (uint8_t)(8)
#define BIT_MASKING_OFFSET      (uint8_t)(2)
#define BIT_MASK_ALL_PINS       (uint8_t)(0xFF)
#define PORT_ID_DIV             (uint8_t)(0xF)
#define PIN_ID_AND              (uint8_t)(0xF)

/*- LOCAL Dataypes
----------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
----------------------------*/

/*- GLOBAL STATIC VARIABLES
-------------------------------*/

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/

/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------*/

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of the DIO Channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Read a DIO channel.
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    /* Variable to store port base address. */
    volatile uint32_t * ptru32_Port = NULL_PTR;
    /* Function to store function return value. */
    Dio_LevelType RetVal = STD_LOW;

    /* Extract port and pin from channel ID. */
    uint8_t u8_PortID = ChannelId/PORT_ID_DIV;
    uint8_t u8_PinID = ChannelId & PIN_ID_AND;

    /* In-case there are no errors */
    if(u8_PortID >= INVALID_PORT_ID)
    {
        /* invalid port */
    }
    else if(u8_PinID >= INVALID_PIN_ID)
    {
        /* invalid pin */
    }
    else
    {
        /* Point to the correct PORT register according to the Port Id */
        switch(u8_PortID)
        {
            case DIO_PORT_A:
                ptru32_Port = &PORTA_DATA;
                break;
            case DIO_PORT_B:
                ptru32_Port = &PORTB_DATA;
                break;
            case DIO_PORT_C:
                ptru32_Port = &PORTC_DATA;
                break;
            case DIO_PORT_D:
                ptru32_Port = &PORTD_DATA;
                break;
            case DIO_PORT_E:
                ptru32_Port = &PORTE_DATA;
                break;
            case DIO_PORT_F:
                ptru32_Port = &PORTF_DATA;
                break;
        }

        /* Read the required channel */
        if(BIT_IS_SET(*((volatile uint8_t *)ptru32_Port + (STD_HIGH << (u8_PinID + BIT_MASKING_OFFSET))),u8_PinID))
        {
            RetVal = STD_HIGH;
        }
        else
        {
            RetVal = STD_LOW;
        }
    }
    return RetVal;
}

/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of the DIO Channel.
* Parameters (in): Level     - Level to write on the DIO Channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Write a level on a DIO channel.
************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    /* Variable to store port base address. */
    volatile uint32_t * ptru32_Port = NULL_PTR;

    /* Extract port and pin from channel ID. */
    uint8_t u8_PortID = ChannelId/PORT_ID_DIV;
    uint8_t u8_PinID = ChannelId & PIN_ID_AND;

    /* In-case there are no errors */
    if(u8_PortID >= INVALID_PORT_ID)
    {
        /* invalid port */
    }
    else if(u8_PinID >= INVALID_PIN_ID)
    {
        /* invalid pin */
    }
    else
    {
        /* Point to the correct PORT register according to the Port Id */
        switch(u8_PortID)
        {
            case DIO_PORT_A:
                ptru32_Port = &PORTA_DATA;
                break;
            case DIO_PORT_B:
                ptru32_Port = &PORTB_DATA;
                break;
            case DIO_PORT_C:
                ptru32_Port = &PORTC_DATA;
                break;
            case DIO_PORT_D:
                ptru32_Port = &PORTD_DATA;
                break;
            case DIO_PORT_E:
                ptru32_Port = &PORTE_DATA;
                break;
            case DIO_PORT_F:
                ptru32_Port = &PORTF_DATA;
                break;
        }

        /* Write the required value */
        if(Level == STD_HIGH)
        {
            /* Write Logic High */
            SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)ptru32_Port + PORT_DATA_ALL_PINS_OFFSET)), u8_PinID);
        }
        else if(Level == STD_LOW)
        {
            /* Write Logic Low */
            CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)ptru32_Port + PORT_DATA_ALL_PINS_OFFSET)), u8_PinID);
        }
        else
        {
            /* Invalid level. */
        }
    }
}

/************************************************************************************
* Service Name: Dio_ReadPort
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of the DIO Port.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Read a DIO Port.
************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    /* Variable to store port base address. */
    volatile uint32_t * ptru32_Port = NULL_PTR;
    /* variable to store function return value. */
    Dio_LevelType RetVal = STD_LOW;

    /* In-case there are no errors */
    if(PortId >= INVALID_PORT_ID)
    {
        /* invalid port */
    }
    else
    {
        /* Point to the correct PORT register according to the Port Id */
        switch(PortId)
        {
            case DIO_PORT_A:
                ptru32_Port = &PORTA_DATA;
                break;
            case DIO_PORT_B:
                ptru32_Port = &PORTB_DATA;
                break;
            case DIO_PORT_C:
                ptru32_Port = &PORTC_DATA;
                break;
            case DIO_PORT_D:
                ptru32_Port = &PORTD_DATA;
                break;
            case DIO_PORT_E:
                ptru32_Port = &PORTE_DATA;
                break;
            case DIO_PORT_F:
                ptru32_Port = &PORTF_DATA;
                break;
        }

        /* Set return variable with port value. */
        RetVal = *((volatile uint8_t *)ptru32_Port + PORT_DATA_OFFSET +(BIT_MASK_ALL_PINS << BIT_MASKING_OFFSET));
    }
    return RetVal;
}

/************************************************************************************
* Service Name: Dio_WritePort
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of the DIO Port.
* Parameters (in): Level  - Level to write on the DIO Port.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Write a value on a DIO Port.
************************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    /* Variable to store port base address. */
    volatile uint32_t * ptru32_Port = NULL_PTR;

    /* In-case there are no errors */
    if(PortId >= INVALID_PORT_ID)
    {
        /* invalid port */
    }
    else
    {
        /* Point to the correct PORT register according to the Port Id */
        switch(PortId)
        {
            case DIO_PORT_A:
                ptru32_Port = &PORTA_DATA;
                break;
            case DIO_PORT_B:
                ptru32_Port = &PORTB_DATA;
                break;
            case DIO_PORT_C:
                ptru32_Port = &PORTC_DATA;
                break;
            case DIO_PORT_D:
                ptru32_Port = &PORTD_DATA;
                break;
            case DIO_PORT_E:
                ptru32_Port = &PORTE_DATA;
                break;
            case DIO_PORT_F:
                ptru32_Port = &PORTF_DATA;
                break;
        }

        /* Write the required value */
        *((volatile uint8_t *)ptru32_Port + (BIT_MASK_ALL_PINS << BIT_MASKING_OFFSET)) = Level;
    }
}

/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of the DIO Channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Toggle a DIO Channel.
************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{

    /* Variable to store port base address. */
    volatile uint32_t * ptru32_Port = NULL_PTR;
    /* variable to store function return value. */
    Dio_LevelType RetVal = STD_LOW;
    /* Extract port and pin from channel ID. */
    uint8_t u8_PortID = ChannelId/PORT_ID_DIV;
    uint8_t u8_PinID = ChannelId & PIN_ID_AND;

    /* In-case there are no errors */
    if(u8_PortID >= INVALID_PORT_ID)
    {
        /* invalid port */
    }
    else if(u8_PinID >= INVALID_PIN_ID)
    {
        /* invalid pin */
    }
    else
    {
        /* Point to the correct PORT register according to the Port Id */
        switch(u8_PortID)
        {
            case DIO_PORT_A:
                ptru32_Port = &PORTA_DATA;
                break;
            case DIO_PORT_B:
                ptru32_Port = &PORTB_DATA;
                break;
            case DIO_PORT_C:
                ptru32_Port = &PORTC_DATA;
                break;
            case DIO_PORT_D:
                ptru32_Port = &PORTD_DATA;
                break;
            case DIO_PORT_E:
                ptru32_Port = &PORTE_DATA;
                break;
            case DIO_PORT_F:
                ptru32_Port = &PORTF_DATA;
                break;
        }

        /* Toggle the required Channel */
        if(BIT_IS_SET(*((volatile uint8_t *)ptru32_Port + (STD_HIGH << (u8_PinID + BIT_MASKING_OFFSET))),u8_PinID))
        {
            /* Write Logic Low */
            CLEAR_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)ptru32_Port + PORT_DATA_ALL_PINS_OFFSET)), u8_PinID);
            /* Set return value to Low */
            RetVal = STD_LOW;
        }
        else
        {
            /* Write Logic High */
            SET_BIT_PER_BB((*(volatile uint32_t *)((volatile uint8_t *)ptru32_Port + PORT_DATA_ALL_PINS_OFFSET)), u8_PinID);
            /* Set return value to High */
            RetVal = STD_HIGH;
        }
    }
    return RetVal;
}
