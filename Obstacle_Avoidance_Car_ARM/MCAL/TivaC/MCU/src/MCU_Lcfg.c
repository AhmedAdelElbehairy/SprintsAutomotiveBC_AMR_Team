/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MCU_Lcfg.c
 *       Module:  MCU
 *
 *  Description:  source file for MCU module linking configurations.
 *
 *********************************************************************************************************************/
/*- INCLUDES
----------------------------------------------*/
#include "MCU_Lcfg.h"

const STR_Mcu_ConfigType STR_MCUClockConfig[CLOCK_SETTINGS_NUM] = {
    {STD_OFF, OSCSRC_PIOSC, 16000},
    {STD_OFF, OSCSRC_PIOSC_DIV_4, 1000},
    {STD_ON, OSCSRC_MOSC, 60000},
};

const uint16_t au16_ClockGates[CONFIGURED_CLOCK_GATES] = {
    CG_PORTA,
    CG_PORTB,
    CG_PORTC,
    CG_PORTD,
    CG_PORTE,
    CG_PORTF,
};
