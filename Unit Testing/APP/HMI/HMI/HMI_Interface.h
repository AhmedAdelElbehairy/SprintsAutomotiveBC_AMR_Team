/*
 * HMI_Interface.h
 *
 * Created: 9/5/2021 6:39:27 PM
 * Author: Mohamed Wagdy
 */ 


#ifndef __HMI_INTERFACE_H__
#define __HMI_INTERFACE_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"

/*- ERRORS DEFINITIONS--------------------------------------*/

/**
* @brief: Module ID.
*/
#define           E_HMI_ID                            (ERROR_STATE_t)( 0xD0 )

/**
* @brief: This return value indicate that a function got an
* uninitialized pointer.
*/
#define           E_HMI_NULL_PTR                      (ERROR_STATE_t)( 1 )

/**
* @brief: This return value indicate that a function got an
* invalid value.
*/
#define           E_HMI_INVALID_VAL                   (ERROR_STATE_t)( 2 )

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* HMI Interface Getters */
/* Return Device Erase Flag Value. */
extern ERROR_STATE_t HMI_GetDeviceEraseFlag(uint8_t * Flag);

/* Return Password Change Flag Value. */
extern ERROR_STATE_t HMI_GetPasswordChangeFlag(uint8_t * Flag);

/* Return Key Pressed Value. */
extern ERROR_STATE_t HMI_GetKeyPressed(uint8_t * Value);

/* HMI Interface Setters */
/* Set Device Erase Flag Value. */
extern ERROR_STATE_t HMI_SetDeviceEraseFlag(void);

/* Set Password Change Flag Value. */
extern ERROR_STATE_t HMI_SetPasswordChangeFlag(void);

/* Set Key Pressed Value. */
extern ERROR_STATE_t HMI_SetKeyPressed(uint8_t Value);

#endif /* __HMI_INTERFACE_H__ */