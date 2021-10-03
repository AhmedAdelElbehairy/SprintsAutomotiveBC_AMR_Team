/*
 * TestCases.c
 *
 * Created: 9/2/2021 9:35:06 AM
 *  Author: Mohamed Wagdy
 */

 /*- INCLUDES
 ----------------------------------------------*/
#include <stdio.h>

#include "HMI.h"
#include "HMI_Interface.h"

 /*- LOCAL MACROS
 ------------------------------------------*/
#define NUMBER_OF_TESTCASES			(uint8_t)(13)
#define INVALID_KEY_VALUE				(uint8_t)(20)

 /*- LOCAL FUNCTIONS PROTOTYPES
 ----------------------------*/
static void TestAssert(uint8_t ID, uint8_t State);
static void TestInterfaceSetters(void);
static void TestInterfaceGetters(void);
static void TestMainFunction(void);

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t u8_ID;
static uint8_t u8_PassedCounter = 0;
static ERROR_STATE_t HMI_ErrorState;

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern uint32_t KP_RetVal;
extern uint8_t gu8_DeviceEraseFlag;
extern uint8_t gu8_PasswordChangeFlag;
extern uint8_t gu8_KeyPressedValue;

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
* @brief: This function tests interface setters functions.
*/
void TestInterfaceSetters(void)
{
	/* Set Device Erase Flag. */
	u8_ID = 1;
	HMI_ErrorState = HMI_SetDeviceEraseFlag();
	TestAssert(
		u8_ID, (ERROR_OK == HMI_ErrorState) &&
		(1 == gu8_DeviceEraseFlag)
	);

	/* Set password change Flag. */
	u8_ID = 2;
	HMI_ErrorState = HMI_SetPasswordChangeFlag();
	TestAssert(
		u8_ID, (ERROR_OK == HMI_ErrorState) &&
		(1 == gu8_PasswordChangeFlag)
	);

	/* Set invalid key pressed. */
	u8_ID = 3;
	HMI_ErrorState = HMI_SetKeyPressed(INVALID_KEY_VALUE);
	TestAssert(
		u8_ID, ((E_HMI_ID | E_HMI_INVALID_VAL) == HMI_ErrorState) &&
		(0 == gu8_KeyPressedValue)
	);

	/* Set Valid key pressed. */
	u8_ID = 4;
	HMI_ErrorState = HMI_SetKeyPressed(4);
	TestAssert(
		u8_ID, (ERROR_OK == HMI_ErrorState) &&
		(4 == gu8_KeyPressedValue)
	);
}

/**
* @brief: This function tests interface getters functions.
*/
static void TestInterfaceGetters(void)
{
	/* Get Device Erase Flag in null pointer */ 
	u8_ID = 5;
	HMI_ErrorState = HMI_GetDeviceEraseFlag(NULL_PTR);
	TestAssert(
		u8_ID, ((E_HMI_ID | E_HMI_NULL_PTR) == HMI_ErrorState)
	);

	/* Get password change Flag in null pointer */
	u8_ID = 6;
	HMI_ErrorState = HMI_GetPasswordChangeFlag(NULL_PTR);
	TestAssert(
		u8_ID, ((E_HMI_ID | E_HMI_NULL_PTR) == HMI_ErrorState)
	);

	/* Get key pressed in null pointer */
	u8_ID = 7;
	HMI_ErrorState = HMI_GetKeyPressed(NULL_PTR);
	TestAssert(
		u8_ID, ((E_HMI_ID | E_HMI_NULL_PTR) == HMI_ErrorState)
	);

	uint8_t Data;
	/* Get Device Erase Flag */
	u8_ID = 8;
	HMI_ErrorState = HMI_GetDeviceEraseFlag(&Data);
	TestAssert(
		u8_ID, (ERROR_OK == HMI_ErrorState) &&
		(1 == Data) && (0 == gu8_DeviceEraseFlag)
	);

	/* Get password change Flag */
	u8_ID = 9;
	HMI_ErrorState = HMI_GetPasswordChangeFlag(&Data);
	TestAssert(
		u8_ID, (ERROR_OK == HMI_ErrorState) &&
		(1 == Data) && (0 == gu8_PasswordChangeFlag)
	);

	/* Get key pressed */
	u8_ID = 10;
	HMI_ErrorState = HMI_GetKeyPressed(&Data);
	TestAssert(
		u8_ID, (ERROR_OK == HMI_ErrorState) &&
		(4 == Data) && (0 == gu8_KeyPressedValue)
	);
}

/**
* @brief: This function tests main function.
*/
void TestMainFunction(void)
{
	/* Device Erase Pattern */
	KP_RetVal = 0x1043;
	u8_ID = 11;
	HMI_MainFunction();
	HMI_MainFunction();
	TestAssert(
		u8_ID, (1 == gu8_DeviceEraseFlag)
	);

	/* Password Change Pattern */
	KP_RetVal = 0x443;
	u8_ID = 12;
	HMI_MainFunction();
	HMI_MainFunction();
	TestAssert(
		u8_ID, (1 == gu8_PasswordChangeFlag)
	);

	/* Single Key Pressed */
	KP_RetVal = 0x8;
	u8_ID = 13;
	HMI_MainFunction();
	HMI_MainFunction();
	TestAssert(
		u8_ID, (3 == gu8_KeyPressedValue)
	);

}

/*- APIs IMPLEMENTATION
-----------------------------------*/
/**
* @brief: This function runs all test cases.
*/
void main(void)
{
	TestInterfaceSetters();

	TestInterfaceGetters();

	TestMainFunction();

	printf("%u/%u TestCases passed.\n", u8_PassedCounter, NUMBER_OF_TESTCASES);

	printf("Press Enter key to close this window . . . \n");

	getchar();
}