/*
 * File Name: BIT_MATH.h
 * Creation Date: 08/09/2021
 * Author: AMR Team
 * Description: Header File for Bit Math....
 */ 

#ifndef __BIT_MATH__
#define __BIT_MATH__
/********************************************************************************************************************/ 
/********************************************************************************************************************/ 
/**********************************************************Rehab*****************************************************/ 
/********************************************************************************************************************/ 

/*****************************************************GENERAL MACROS*************************************************/
//GENERAL MACROS
#define BIT_0 0
#define BIT_1 1
#define BIT_2 2
#define BIT_3 3
#define BIT_4 4
#define BIT_5 5
#define BIT_6 6
#define BIT_7 7


#define BIT_LOW 			0
#define TWO_BITS_LOW 		0
#define THREE_BITS_LOW 		0
#define FOUR_BITS_LOW 		0
#define FIVE_BITS_LOW 		0
#define SIX_BITS_LOW 		0
#define SEVEN_BITS_LOW 		0
#define EIGHT_BITS_LOW 		0


#define BIT_HIGH 			1
#define TWO_BITS_HIGH 		3
#define THREE_BITS_HIGH 	7
#define FOUR_BITS_HIGH 		15
#define FIVE_BITS_HIGH 		31
#define SIX_BITS_HIGH 		63
#define SEVEN_BITS_HIGH 	127
#define EIGHT_BITS_HIGH 	255
/********************************************************************************************************************/

/**************************************************MACROS_LIKE_FUNCTIONS*********************************************/
//MACROS_LIKE_FUNCTIONS
#define BIT_WRITE(REG,BITNO,VAL) REG=(REG&(~(BIT_HIGH<<BITNO)))|(VAL<<BITNO)
#define TWO_BITS_WRITE(REG,FIRSTBITNO,VAL) REG=(REG&(~(TWO_BITS_HIGH<<FIRSTBITNO)))|(VAL<<FIRSTBITNO)
#define THREE_BITS_WRITE(REG,FIRSTBITNO,VAL) REG=(REG&(~(THREE_BITS_HIGH<<FIRSTBITNO)))|(VAL<<FIRSTBITNO)
#define FOUR_BITS_WRITE(REG,FIRSTBITNO,VAL) REG=(REG&(~(FOUR_BITS_HIGH<<FIRSTBITNO)))|(VAL<<FIRSTBITNO)
#define FIVE_BITS_WRITE(REG,FIRSTBITNO,VAL) REG=(REG&(~(FIVE_BITS_HIGH<<FIRSTBITNO)))|(VAL<<FIRSTBITNO)
#define SIX_BITS_WRITE(REG,FIRSTBITNO,VAL) REG=(REG&(~(SIX_BITS_HIGH<<FIRSTBITNO)))|(VAL<<FIRSTBITNO)
#define SEVEN_BITS_WRITE(REG,FIRSTBITNO,VAL) REG=(REG&(~(SEVEN_BITS_HIGH<<FIRSTBITNO)))|(VAL<<FIRSTBITNO)
#define EIGHT_BITS_WRITE(REG,FIRSTBITNO,VAL) REG=(REG&(~(EIGHT_BITS_HIGH<<FIRSTBITNO)))|(VAL<<FIRSTBITNO)

#define REG_WRITE(REG,VAL) REG=VAL

//BIT_GET TO KNOW THE BIT VALUE
#define BIT_GET(REG,BITNO) ((REG>>BITNO)&BIT_HIGH)
#define TWO_BITS_GET(REG,FIRSTBITNO) ((REG>>FIRSTBITNO)&TWO_BITS_HIGH)
#define FIVE_BITS_GET(REG,FIRSTBITNO) ((REG>>FIRSTBITNO)&FIVE_BITS_HIGH)

//REG_GET TO KNOW THE VALUE IN THE REGISTER 
#define REG_GET(REG) (REG)

#define BIT_TOGGLE(REG,BITNO) REG^=(BIT_HIGH<<BITNO)
#define REG_TOGGLE(REG) REG=~REG
/********************************************************************************************************************/ 
/********************************************************************************************************************/ 
/**********************************************************Essam*****************************************************/ 
/********************************************************************************************************************/ 
/* Set_Bit --> Sets any bit ( ON )*/
/* To set a bit, We use (Inclusive OR) as ( 0 --> Makes No change ) and ( 1 --> Sets ON )   */
#define SET_BIT(REG,BIT)             (REG|=((uint8_t)1<<BIT))
#define SET_LOW_NIBBLE(REG)          (REG|=((uint8_t)0X0F))
#define SET_HIGH_NIBBLE(REG)         (REG|=((uint8_t)0XF0))
#define SET_BYTE(REG)                (REG=((uint8_t)0XFF))

/* Clr_Bit --> Sets any bit ( OFF ) == ( Clear any bit )*/
/* To clear a bit, We use ( And ) as ( 1 --> Makes No change ) and ( 0 --> Sets OFF )   */
#define CLR_BIT(REG,BIT)             (REG&=~((uint8_t)1<<BIT))
#define CLR_LOW_NIBBLE(REG)          (REG&=((uint8_t)0xF0))
#define CLR_HIGH_NIBBLE(REG)         (REG&=((uint8_t)0x0F))
#define CLR_BYTE(REG)                (REG=((uint8_t)0x00))


/* Toggle_Bit --> Flip any bit  */
/* To Flip a bit, We use ( Exclusive OR ) as ( 0 --> Makes No change ) and ( 1 --> Toggle )   */
#define TOGGLE_BIT(REG,BIT)         (REG^=((uint8_t)1<<BIT))
#define TOGGLE_LOW_NIBBLE(REG)      (REG^=((uint8_t)0X0F))
#define TOGGLE_HIGH_NIBBLE(REG)     (REG^=((uint8_t)0XF0))
#define TOGGLE_BYTE(REG)            (REG^=((uint8_t)0XFF))


/* Get_Bit --> Gets any bit */
/* To get a bit, We use ( AND ) as ( 1 --> Makes No change ) and ( 0 --> Sets OFF )  */
#define GET_BIT(REG,BIT)            (((REG>>BIT)&(uint8_t)(0x01)))
#define GET_LOW_NIBBLE(REG)         ((REG&(uint8_t)0X0F))
#define GET_HIGH_NIBBLE(REG)        ((REG>>(uint8_t)4))
/********************************************************************************************************************/ 
/********************************************************************************************************************/ 
/**********************************************************Ahmed*****************************************************/ 
/********************************************************************************************************************/ 
#define Bit(x) (1<<(x))
//#define SET_BIT(REG, BIT)     ((REG) |=   (Bit(BIT)))
	
#define CLEAR_BIT(REG, BIT)   ((REG) &=  ~(Bit(BIT)))

#define READ_BIT(REG, BIT)    (((REG) &   (Bit(BIT))) >> (BIT))

#define TOG_BIT(REG,BIT) 	  ((REG) ^=   (Bit(BIT)))

#define CLEAR_REG(REG)        ((REG)  =   (Bit(BIT)))

#define TOG_BIT(REG,BIT)      ((REG) ^=   (Bit(BIT)))

#define WRITE_REG(REG, VAL)   ((REG)  =   (VAL))

#define TOG_REG(REG,VAL) 	  ((REG) ^=   (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))
/********************************************************************************************************************/ 
#endif
