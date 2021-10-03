/*
 * MCU_To_MCU_Bluetooth_Communication.c
 *
 * Created: 9/5/2021 2:53:30 PM
 * Author : vetmo
 */ 

#include "SSD_Display.h"
#include "Indicator.h"
#include "LCD_DISPLAY.h"
#include "FreeRTOS.h"
#include "task.h"

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

#include "LCD_DISPLAY_Interface.h"
void LCD_Display_Task( void *pvParameters )
{
   portTickType xLastWakeTime;
   xLastWakeTime=xTaskGetTickCount();
   DISPLAY_SetState(PassEntering);
   for( ;; )
   {
      DISPLAY_MainFunction();
      vTaskDelayUntil(&xLastWakeTime, 50);
   }
}

#if 1
#include "SSD_Display_Interface.h"
void NumberChange_Task( void *pvParameters )
{
   portTickType xLastWakeTime;
   xLastWakeTime=xTaskGetTickCount();
   
   static uint8_t Number = 1;
   static uint8_t ast = 2;
   vTaskDelayUntil(&xLastWakeTime, 1000);
   for( ;; )
   {
      DISPLAY_SetNumber_of_Asterisk(ast);
      SSD_Display_SetSevenSegment(Number);
      Number++;
      ast++;
      if(Number > 99)
      {
         Number = 0;
      }
      vTaskDelayUntil(&xLastWakeTime, 1000);
   }
}
#endif

int main(void)
{   
   while(ERROR_OK != LCD_Init());
   
   xTaskCreate( Feedback_Task, "Indicator", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   xTaskCreate( SSD_Display_Task, "SevenSegment", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   xTaskCreate( NumberChange_Task, "number", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   xTaskCreate( LCD_Display_Task, "LCD", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   
   vTaskStartScheduler();
   while(1)
   {
      
   }
   return 0;
}