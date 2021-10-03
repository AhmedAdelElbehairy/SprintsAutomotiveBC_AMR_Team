/*
 * LCD_Cfg.h
 *
 * Created: 8/11/2021 3:25:06 PM
 *  Author: zoldeyck
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_NUMBER (1)
typedef struct STR_LCD_config_t{
   uint8_t u8_LCD_Rs;
   uint8_t u8_LCD_Rw;
   uint8_t u8_LCD_En;
   uint8_t u8_LCD_D7;
   uint8_t u8_LCD_D6;
   uint8_t u8_LCD_D5;
   uint8_t u8_LCD_D4;   
} STR_LCD_config_t;


#endif /* LCD_CFG_H_ */
