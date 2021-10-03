/*
 * MCU_To_MCU_Bluetooth_Communication.c
 *
 * Created: 9/5/2021 2:53:30 PM
 * Author : vetmo
 */ 

#include "SSD_Display.h"
#include "HMI.h"
#include "Indicator.h"
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

void SSD_Display_Task( void *pvParameters )
{
   portTickType xLastWakeTime;
   xLastWakeTime=xTaskGetTickCount();
   
   for( ;; )
   {
      SSD_Display_MainFunction();
      vTaskDelayUntil(&xLastWakeTime, 10);
   }
}

#if 1
#include "SSD_Display_Interface.h"
void NumberChange_Task( void *pvParameters )
{
   portTickType xLastWakeTime;
   xLastWakeTime=xTaskGetTickCount();
   
   static uint8_t Number = 1;
   vTaskDelayUntil(&xLastWakeTime, 100);
   for( ;; )
   {
      SSD_Display_SetSevenSegment(Number);
      Number++;
      if(Number > 99)
      {
         Number = 0;
      }
      vTaskDelayUntil(&xLastWakeTime, 100);
   }
}
#endif

int main(void)
{   
   xTaskCreate( HMI_Task, "HMI", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   xTaskCreate( Feedback_Task, "Indicator", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   xTaskCreate( SSD_Display_Task, "SevenSegment", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   xTaskCreate( NumberChange_Task, "number", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   
   vTaskStartScheduler();
   while(1)
   {
      
   }
   return 0;
}