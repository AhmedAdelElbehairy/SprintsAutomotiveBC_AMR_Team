/*
 * SSD_Display.c
 *
 * Created: 9/7/2021 3:10:35 PM
 * Author: Mohamed Wagdy
 */ 

/*INCLUDES-------------------------------*/
#include "SevenSeg.h"
#include "SSD_Display.h"
#include "SSD_Display_Interface.h"

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const STR_DISPLAY_SEGMENT_config_t STR_DisplaySegmentConfig;

/*APIs IMPLEMENTATION------------------------*/
/**
* @brief: This function is the Display main function.
*
* @return function error state.
*/
extern void SSD_Display_MainFunction(void)
{
   /* Used Local variables */
   static uint8_t u8_Init = 0;  
   uint8_t u8_SevenSegmentNumber; 
   static Enu_SSDDisplayStateMachine State = SSD_Display_FirstNumber;
   
   /* Initialization sequence. */
   if (u8_Init == 0)
   {
      SevenSeg_Init(STR_DisplaySegmentConfig.u8_SegmentCh0);
      SevenSeg_Init(STR_DisplaySegmentConfig.u8_SegmentCh1);
      u8_Init = 1;
   }
   
   /* Get the number to display. */
   SSD_Display_GetSevenSegment(&u8_SevenSegmentNumber);
   
   switch(State)
   {
      case SSD_Display_FirstNumber:
         /* Display the first number. */
         SevenSeg_Display(STR_DisplaySegmentConfig.u8_SegmentCh0, u8_SevenSegmentNumber%10);
         State = SSD_Display_SecondNumber;
         break;
      case SSD_Display_SecondNumber:
         /* Display the second number. */
         SevenSeg_Display(STR_DisplaySegmentConfig.u8_SegmentCh1, u8_SevenSegmentNumber/10);
         State = SSD_Display_FirstNumber;
         break;
   }      
}