/*
 * UTILS.h
 *
 *  Created on: Aug 9, 2021
 *      Author: AMR Team
 */

#ifndef __UTILS__
#define __UTILS__

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* dummy delay for nearly 50ms */
void dummy_delay(void);

/* compares two strings if identical */
uint8_t StringCompare(ptr_uint8_t str1, ptr_uint8_t str2);
uint8_t STR_Length(ptr_uint8_t String, ptr_uint16_t StringLength);
uint8_t STR_CharIsNumeric(uint8_t Character, ptr_uint8_t Result);
uint8_t STR_StringIsNumeric(ptr_uint8_t String, ptr_uint8_t Result);
uint8_t STR_CompareString(ptr_uint8_t String_1, ptr_uint8_t String_2, ptr_uint8_t Result);
uint8_t STR_String2Number(ptr_uint8_t String, ptr_uint16_t Number);
uint8_t STR_Number2String(uint32_t Number,ptr_uint8_t String);
uint8_t STR_StringReverse(ptr_uint8_t String);
void STR_StringConcatenate(ptr_uint8_t destination,const ptr_uint8_t source);
void STR_StringCopy(ptr_uint8_t destination,const ptr_uint8_t source);

uint8_t CRC_16_Calc (ptr_uint8_t STRING);
uint8_t CRC_16_Chk (ptr_uint8_t STRING);

#endif
