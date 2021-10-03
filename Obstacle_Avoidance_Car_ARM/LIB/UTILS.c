/*
 * UTILS.c
 *
 *  Created on: Aug 9, 2021
 *      Author: AMR Team
 */
 
/*- INCLUDES
----------------------------------------------*/
#include "Std_Types.h"
#include "UTILS.h"

/*- LOCAL MACROS
------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------*/

/**
* @brief: This function compares if two strings are identical.
*
* @param [in]  str1   -  pointer to the first string.
* @param [in]  str2   -  pointer to the second string.
*
* @return function error state.
*/
uint8_t StringCompare(uint8_t * str1, uint8_t * str2)
{
   uint8_t u8_counter = 0;
   uint8_t u8_isEqual = TRUE;
   
   while(str1[u8_counter] != END_OF_STRING && str1[u8_counter] != NEW_LINE)
   {
      if(str1[u8_counter] != str2[u8_counter])
      {
         u8_isEqual = FALSE;
         u8_counter++;
         break;
      }
      u8_counter++;
   }
   if( str2[u8_counter] != END_OF_STRING )
   {
      u8_isEqual = FALSE;
   }
   return u8_isEqual;
}
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
uint8_t STR_Length(uint8_t* String, uint16_t* StringLength)
{
	*StringLength = 0;
	while(*String!='\0')
	{
		(*StringLength)++;
		String++;
	}
	return 0;
}
uint8_t STR_CharIsNumeric(uint8_t Character, uint8_t* Result)
{
	if(Character>=48 && Character<=57)
	{
		*Result=1;
	}
	else
	{
		*Result=0;
	}
	return 0;
}
uint8_t STR_StringIsNumeric(uint8_t* String, uint8_t* Result)
{
	uint8_t FunRetVal = 0;
	while(*String!='\0')
	{
		STR_CharIsNumeric(*String,&FunRetVal);
		if(!FunRetVal)
		{
			*Result = 0;
			break;
		}
		else
		{
			*Result = 1;
			String++;
			continue;
		}
	}
	return 0;
}
uint8_t STR_CompareString(uint8_t* String_1, uint8_t* String_2, uint8_t* Result)
{
	while(1)
	{
		if(*String_1==*String_2)
		{
			*Result = 1;
			String_1++;
			String_2++;
			if(*String_1=='\0'&&*String_2=='\0')
				break;
			continue;
		}
		else if(*String_1=='\0'&&*String_2=='\0')
		{
			*Result = 1;
			break;
		}
		else
		{
			*Result = 0;
			break;
		}
	}
	return 0;
}
uint8_t STR_String2Number(uint8_t* String, uint16_t* Number)
{
	uint32_t Multiplier=1;
	uint8_t* StartOfString=String;
	*Number=0;
	while(*String!='\0')
	{
		String++;
	}

	do
	{
		String--;
		(*Number)+=((*String-48)*Multiplier);
		Multiplier*=10;
	}while(String!=StartOfString);
	return 0;
}
uint8_t STR_Number2String(uint32_t Number, uint8_t* String)
{
	uint8_t* SringCpy = String;
	if(Number==0)
	{
		*String='0';
	}
	else
	{
		do
		{
			*String = (Number%10)+48;
			String++;
			Number/=10;
		}while(Number);
		*String = NULL_TERMINATOR;
	}
	STR_StringReverse(SringCpy);
	return 0;
}
uint8_t STR_StringReverse(uint8_t* String)
{
	uint8_t* A = String;
	uint8_t* B = String;
	uint8_t Temp = 0;
	while(*B != '\0')
	{
		B++;
	}
	B--;
	while(A<B)
	{
		//swap
		Temp=*A;
		*A=*B;
		*B=Temp;
		A++;B--;
	}
	return 0;
}

