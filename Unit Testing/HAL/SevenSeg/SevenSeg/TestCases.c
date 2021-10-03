/*
 * TestCases.c
 *
 * Created: 9/2/2021 9:35:06 AM
 *  Author: Mohamed Wagdy
 */

 /*- INCLUDES
 ----------------------------------------------*/
#include <stdio.h>
#include "SevenSeg.h"

 /*- LOCAL MACROS
 ------------------------------------------*/
#define NUMBER_OF_TESTCASES			(uint8_t)(8)
#define INVALID_CHANNEL					(uint8_t)(20)

 /*- LOCAL FUNCTIONS PROTOTYPES
 ----------------------------*/
static void TestAssert(uint8_t ID, uint8_t State);
static void TestBeforeInit(void);
static void TestInit(void);
static void TestDisplay(void);

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t u8_ID;
static uint8_t u8_PassedCounter = 0;
static ERROR_STATE_t SevenSeg_ErrorState;

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern uint8_t PORTB;
extern uint8_t PORTD;
extern uint8_t DDRB;
extern uint8_t DDRD;

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
* @brief: This function tests calling other functions before init function.
*/
void TestBeforeInit(void)
{
	u8_ID = 1;
	SevenSeg_ErrorState = SevenSeg_Display(SEVEN_SEG_CH_0, 0);
	TestAssert(
		u8_ID, ((E_SEVEN_SEG_ID | E_SEVEN_SEG_NOT_INIT) == SevenSeg_ErrorState)
	);
}

/**
* @brief: This function tests init function.
*/
void TestInit(void)
{
	/* Initialize With Invalid Channel. */
	u8_ID = 2;
	SevenSeg_ErrorState = SevenSeg_Init(INVALID_CHANNEL);
	TestAssert(
		u8_ID, ( (E_SEVEN_SEG_ID|E_SEVEN_SEG_INVALID_CH) == SevenSeg_ErrorState)
	);

	/* Initialize With valid data */
	u8_ID = 3;
	SevenSeg_ErrorState = SevenSeg_Init(SEVEN_SEG_CH_0);
	TestAssert(
		u8_ID, (ERROR_OK == SevenSeg_ErrorState) &&
		( 0x0F == DDRB ) && ( 0x04 == DDRD )
	);

	/* Initialize again */
	u8_ID = 4;
	SevenSeg_ErrorState = SevenSeg_Init(SEVEN_SEG_CH_0);
	TestAssert(
		u8_ID, ( (E_SEVEN_SEG_ID | E_SEVEN_SEG_INIT_BEFORE) == SevenSeg_ErrorState) &&
		(0x0F == DDRB) && (0x04 == DDRD)
	);
}

/**
* @brief: This function tests displaying API.
*/
static void TestDisplay(void)
{
	/* Invalid channel */
	u8_ID = 5;
	SevenSeg_ErrorState = SevenSeg_Display(INVALID_CHANNEL, 0);
	TestAssert(
		u8_ID, ((E_SEVEN_SEG_ID | E_SEVEN_SEG_INVALID_CH) == SevenSeg_ErrorState)
	);

	/* Invalid Number */
	u8_ID = 6;
	SevenSeg_ErrorState = SevenSeg_Display(SEVEN_SEG_CH_0, 10);
	TestAssert(
		u8_ID, ((E_SEVEN_SEG_ID | E_SEVEN_SEG_INVALID_NUMBER) == SevenSeg_ErrorState)
	);

	/* Valid Number 9 */
	u8_ID = 7;
	SevenSeg_ErrorState = SevenSeg_Display(SEVEN_SEG_CH_0, 9);
	TestAssert(
		u8_ID, (ERROR_OK == SevenSeg_ErrorState) &&
		(9 == PORTB) && (0x04 == PORTD)
	);

	/* Valid Number 0 */
	u8_ID = 8;
	SevenSeg_ErrorState = SevenSeg_Display(SEVEN_SEG_CH_0, 0);
	TestAssert(
		u8_ID, (ERROR_OK == SevenSeg_ErrorState) &&
		(0 == PORTB) && (0x04 == PORTD)
	);
}


/*- APIs IMPLEMENTATION
-----------------------------------*/
/**
* @brief: This function runs all test cases.
*/
void main(void)
{
	TestBeforeInit();

	TestInit();

	TestDisplay();

	printf("%u/%u TestCases passed.\n", u8_PassedCounter, NUMBER_OF_TESTCASES);

	printf("Press Enter key to close this window . . . \n");

	getchar();
}