/*
 * USONIC.h
 *
 *  Created on: Aug 9, 2021
 *      Author: Ahmed
 */

#ifndef USONIC_H_
#define USONIC_H_
/*INCLUDES-------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GLOBAL_Interrupt.h"

#include "ICU.h"
#include "USONIC_Lcfg.h"

/*- LOCAL MACROS
------------------------------------------*/
#define USONIC1    (uint8_t)0

/*
		This Happens when API do what is suppose to do
 */
#define           USONIC_SUCCESS             (ERROR_STATE_t)( 0 )

/*
		This Error happens if USONIC is already initialized before
*/
#define           USONIC_SEC_INIT             (ERROR_STATE_t)( -1 )
/*
 *     This Error happens if USONIC is not  initialized before
 */
#define           USONIC_NOT_INIT             (ERROR_STATE_t)(- 2 )

/*
 *     This Error happens if pointer is null
 */
#define           USONIC_NULL_POINTER         (ERROR_STATE_t)( -3 )
/*
*      This Error happens if USONIC didn't finish a job
*/
#define           USONIC_PENDING      (ERROR_STATE_t)( -4 )

/*APIs DECLARATIONS------------------------*/
ERROR_STATE_t USONIC_Init(void);
ERROR_STATE_t USONIC_GetDistance(ptr_double64_t distance);


#endif /* USONIC_H_ */
