/*
 * UTILS.h
 *
 *  Created on: Aug 9, 2021
 *      Author: AMR Team
 */

#ifndef __UTILS__
#define __UTILS__

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* dummy delay for nearly 50ms */
void dummy_delay(void);

/* compares two strings if identical */
uint8_t StringCompare(uint8_t * str1, uint8_t * str2);
uint8_t STR_Length(uint8_t* String, uint16_t* StringLength);
uint8_t STR_CharIsNumeric(uint8_t Character, uint8_t* Result);
uint8_t STR_StringIsNumeric(uint8_t* String, uint8_t* Result);
uint8_t STR_CompareString(uint8_t* String_1, uint8_t* String_2, uint8_t* Result);
uint8_t STR_String2Number(uint8_t* String, uint16_t* Number);
uint8_t STR_Number2String(uint32_t Number, uint8_t* String);
uint8_t STR_StringReverse(uint8_t* String);

#endif
