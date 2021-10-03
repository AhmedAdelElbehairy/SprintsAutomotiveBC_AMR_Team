/*
 * OS.c
 *
 * Created: 08/29/2021 7:56:24 PM
 *  Author: REHAB
 */ 
#include "Mcu_Hw.h"
#include "PORT.h"
#include "MCU.h"
#include "MONITORING.h"
#include "OS.h"


static uint8_t num = 1;
TaskHandler_t MonitoringTaskHandler;
TaskHandler_t IncrementTaskHandler;

extern const STR_Mcu_ConfigType STR_MCUClockConfig[CLOCK_SETTINGS_NUM];
extern const Port_ConfigType STR_PortsConfig[PORT_PINS_NUM];

Std_ReturnType SENSING_Get(float64_t * Num)
{
    *Num = num;

    return E_OK;
}

void MonitoringTask(void);
void IncrementTask(void);

void MonitoringTask(void)
{
	MONITOR_MainFunction();
}

void IncrementTask(void)
{
    num++;
    if(num == 255)
    {
        num = 1;
    }
}

int main(void)
{
    Mcu_Init(STR_MCUClockConfig);
    Mcu_InitClock(0);

    Port_Init(STR_PortsConfig);

	OS_Init();

	OS_CreateTask(0,0,1,MonitoringTask,&MonitoringTaskHandler);
	OS_CreateTask(1,0,1000,IncrementTask,&IncrementTaskHandler);
	OS_Run();

    while(1)
    {
        //TODO:: Please write your application code
    }
}

//#include "LCD.h"
//#include "PORT.h"
//#include "Mcu_Hw.h"
//
//extern const Port_ConfigType STR_PortsConfig[PORT_PINS_NUM];
//
//void main(void) {
//
//    /* Start PortF Clock */
//    SYSCTL_RCGCGPIO |= 0x3F;
//    /* Wait till clock is running */
//    while((SYSCTL_PRGPIO & 0x3F) != 0x3F);
//
//    Port_Init(STR_PortsConfig);
//
//    while(0 != LCD_Init());
//
//    while(0 != LCD_SendString("ya rab !"));
//
//    while(1);
//}

