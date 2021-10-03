/*
 * MCU_To_MCU_Bluetooth_Communication.c
 *
 * Created: 9/5/2021 2:53:30 PM
 * Author : AMR Team
 */ 

#include "HMI.h"
#include "Indicator.h"
#include "BLUETOOTH_Mng.h"
#include "FreeRTOS.h"
#include "task.h"

void HMI_Task( void *pvParameters )
{
   portTickType xLastWakeTime;
   xLastWakeTime=xTaskGetTickCount();
   
   for( ;; )
   {
      HMI_MainFunction();
      vTaskDelayUntil(&xLastWakeTime, 50);
   }
}

void Feedback_Task( void *pvParameters )
{  
   for( ;; )
   {
      Indicator_MainFunction();
   }
}

void Bluetooth_Task( void *pvParameters )
{
   for( ;; )
   {
      BLUETOOTH_Mng_MainFunction();
   }
}

int main(void)
{   
   xTaskCreate( HMI_Task, "HMI", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   xTaskCreate( Feedback_Task, "Indicator", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   xTaskCreate( Bluetooth_Task, "Bluetooth", configMINIMAL_STACK_SIZE, NULL_PTR, 2, NULL_PTR );
   
   vTaskStartScheduler();
   while(1)
   {
      
   }
   return 0;
}