/*
 * USONIC_Cfg.h
 *
 *  Created on: Aug 9, 2021
 *      Author: Ahmed
 */

#ifndef USONIC_CFG_H_
#define USONIC_CFG_H_
/*- INCLUDES
----------------------------------------------*/
#include "DIO.h"
/*- LOCAL MACROS------------------------------------------*/
#define  USONIC_NUMBER              (uint8_t)( 1 )
#define USONIC_TRIG_PIN     PIN0
#define USONIC_TRIG_PORT    PORT_D
/*- STRUCTS AND UNIONS -------------------------------------*/
typedef struct STR_USONIC_config_t{
   uint8_t USONIC_TRIG_PORT;
   uint8_t USONIC_TRIG_PIN;
} STR_USONIC_config_t;


#endif /* USONICCONIG_H_ */
