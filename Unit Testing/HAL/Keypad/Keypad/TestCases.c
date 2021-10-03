/*
 * TestCases.c
 *
 * Created: 9/2/2021 9:35:06 AM
 *  Author: Mohamed Wagdy
 */

 /*- INCLUDES
 ----------------------------------------------*/
#include <stdio.h>
#include "Keypad.h"

 /*- LOCAL MACROS
 ------------------------------------------*/
#define NUMBER_OF_TESTCASES			(uint8_t)(5)
#define INVALID_CHANNEL					(uint8_t)(20)

 /*- LOCAL FUNCTIONS PROTOTYPES
 ----------------------------*/
static void TestAssert(uint8_t ID, uint8_t State);
static void TestInit(void);
static void TestRead(void);

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t u8_ID;
static uint8_t u8_PassedCounter = 0;
static ERROR_STATE_t KP_ErrorState;

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern uint8_t PORTC;
extern uint8_t DDRC;
extern uint8_t PINC;

/*- LOCAL FUNCTIONS IMPLEMENTATION
------------------------*/

/**
* @brief: This function Prints the Test State and increament Passed Tests if passed.
*
* @param [in]  ID		-  ID of the test.
* @param [in]  State	-  State of the test.
*/
void TestAssert(uint8_t ID, uint8_t State)
{
	if (State)
	{
		printf("Test Case ID: %u - PASSED \n", u8_ID);
		u8_PassedCounter++;
	}
	else
	{
		printf("Test Case ID: %u - FAILED \n", u8_ID);
	}
}

/**
* @brief: This function tests init function.
*/
void TestInit(void)
{
	/* Initialize With Invalid Channel. */
	u8_ID = 1;
	KP_ErrorState = KP_Init(INVALID_CHANNEL);
	TestAssert(
		u8_ID, ( (E_KEYPAD_ID|E_KEYPAD_INVALID_CH) == KP_ErrorState)
	);

	/* Initialize With valid data */
	u8_ID = 2;
	KP_ErrorState = KP_Init(KP_CH_0);
	TestAssert(
		u8_ID, (ERROR_OK == KP_ErrorState) &&
		( 0x00 == DDRC )
	);
}

/**
* @brief: This function tests keypad read API.
*/
static void TestRead(void)
{
	/* Null Pointer */
	u8_ID = 3;
	KP_ErrorState = KP_GetPressedValue(KP_CH_0, NULL_PTR);
	TestAssert(
		u8_ID, ((E_KEYPAD_ID | E_KEYPAD_NULL_PTR) == KP_ErrorState)
	);
	
	uint32_t Data;

	/* Invalid Channel */
	u8_ID = 4;
	KP_ErrorState = KP_GetPressedValue(INVALID_CHANNEL, &Data);
	TestAssert(
		u8_ID, ((E_KEYPAD_ID | E_KEYPAD_INVALID_CH) == KP_ErrorState)
	);

	/* Valid Data */
	/* Second button in row is pressed. */
	PINC = 0x1A;

	u8_ID = 5;
	KP_ErrorState = KP_GetPressedValue(KP_CH_0, &Data);
	TestAssert(
		u8_ID, (ERROR_OK == KP_ErrorState) &&
		(0x71 == Data)
	);
}


/*- APIs IMPLEMENTATION
-----------------------------------*/
/**
* @brief: This function runs all test cases.
*/
void main(void)
{
	TestInit();

	TestRead();

	printf("%u/%u TestCases passed.\n", u8_PassedCounter, NUMBER_OF_TESTCASES);

	printf("Press Enter key to close this window . . . \n");

	getchar();
}