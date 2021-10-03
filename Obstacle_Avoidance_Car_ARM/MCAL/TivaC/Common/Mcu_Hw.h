/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef __MCU_HW_H__
#define __MCU_HW_H__

/*- INCLUDES -----------------------------------------------*/
#include "Std_Types.h"
#include "Mcu_HwTags.h"

/*- CONSTANTS ----------------------------------------------*/
#define CORTEXM4_PERI_BASE_ADDRESS      (uint32_t)(0xE000E000)

/*- Systick Timer Registers---------------------------------*/
#define STCTRL                          (*((volatile STCTRL_Tag *)(CORTEXM4_PERI_BASE_ADDRESS+0x010)))
#define STRELOAD                        (*((volatile STRELOAD_Tag *)(CORTEXM4_PERI_BASE_ADDRESS+0x014)))
#define STCURRENT                       (*((volatile STCURRENT_Tag *)(CORTEXM4_PERI_BASE_ADDRESS+0x018)))

/* NVIC Registers */
#define EN0                             (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x100)))
#define EN1                             (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x104)))
#define EN2                             (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x108)))
#define EN3                             (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x10C)))
#define EN4                             (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x110)))
#define DIS0                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x180)))
#define DIS1                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x184)))
#define DIS2                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x188)))
#define DIS3                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x18C)))
#define DIS4                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x190)))
#define PRI0                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x400)))
#define PRI1                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x404)))
#define PRI2                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x408)))
#define PRI3                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x40C)))
#define PRI4                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x410)))
#define PRI5                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x414)))
#define PRI6                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x418)))
#define PRI7                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x41C)))
#define PRI8                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x420)))
#define PRI9                            (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x424)))
#define PRI10                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x428)))
#define PRI11                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x42C)))
#define PRI12                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x430)))
#define PRI13                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x434)))
#define PRI14                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x438)))
#define PRI15                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x43C)))
#define PRI16                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x440)))
#define PRI17                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x444)))
#define PRI18                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x448)))
#define PRI19                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x44C)))
#define PRI20                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x450)))
#define PRI21                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x454)))
#define PRI22                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x458)))
#define PRI23                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x45C)))
#define PRI24                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x460)))
#define PRI25                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x464)))
#define PRI26                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x468)))
#define PRI27                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x46C)))
#define PRI28                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x470)))
#define PRI29                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x474)))
#define PRI30                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x478)))
#define PRI31                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x47C)))
#define PRI32                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x480)))
#define PRI33                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x484)))
#define PRI34                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0x488)))

#define APINT                           (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C)))
#define INTCTRL                         (*((volatile uint32_t *)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)))

/*- System Control Registers--------------------------------*/
#define SYSCTL_BASE_ADDRESS             (uint32_t)(0x400FE000)
#define SYSCTL_RCGC_OFFSET              (uint32_t)(0x600)
#define SYSCTL_RIS                      (*((volatile uint32_t *)(SYSCTL_BASE_ADDRESS+0x050)))
#define SYSCTL_RESC                     (*((volatile uint32_t *)(SYSCTL_BASE_ADDRESS+0x05C)))
#define SYSCTL_RCC                      (*((volatile uint32_t *)(SYSCTL_BASE_ADDRESS+0x060)))
#define SYSCTL_RCC2                     (*((volatile uint32_t *)(SYSCTL_BASE_ADDRESS+0x070)))
#define SYSCTL_RCGCGPIO                 (*((volatile uint32_t *)(SYSCTL_BASE_ADDRESS+0x608)))
#define SYSCTL_PRGPIO                   (*((volatile uint32_t *)(SYSCTL_BASE_ADDRESS+0xA08)))

/*- GPIO APB Registers------------------------------------------*/
/*- GPIO APB Registers base addresses---------------------------*/
#define PORTA_APB_BASE_ADDRESS          (uint32_t)(0x40004000)
#define PORTB_APB_BASE_ADDRESS          (uint32_t)(0x40005000)
#define PORTC_APB_BASE_ADDRESS          (uint32_t)(0x40006000)
#define PORTD_APB_BASE_ADDRESS          (uint32_t)(0x40007000)
#define PORTE_APB_BASE_ADDRESS          (uint32_t)(0x40024000)
#define PORTF_APB_BASE_ADDRESS          (uint32_t)(0x40025000)

/*- GPIO APB Data Control Registers offsets---------------------*/
#define PORT_DATA_OFFSET                (uint32_t)(0x000)
#define PORT_DATA_ALL_PINS_OFFSET       (uint32_t)(0x3FC)
#define PORT_DIR_OFFSET                 (uint32_t)(0x400)
/*- GPIO APB Commit Control Registers offsets-------------------*/
#define PORT_LOCK_OFFSET                (uint32_t)(0x520)
#define PORT_CR_OFFSET                  (uint32_t)(0x524)
/*- GPIO APB Port Control Registers offsets---------------------*/
#define PORT_PCTL_OFFSET                (uint32_t)(0x52C)
/*- GPIO APB Mode Control Registers offsets---------------------*/
#define PORT_AFSEL_OFFSET               (uint32_t)(0x420)
#define PORT_ADCCTL_OFFSET              (uint32_t)(0x530)
#define PORT_DMACTL_OFFSET              (uint32_t)(0x534)
/*- GPIO APB Pad Control Registers offsets----------------------*/
#define PORT_DR2R_OFFSET                (uint32_t)(0x500)
#define PORT_DR4R_OFFSET                (uint32_t)(0x504)
#define PORT_DR8R_OFFSET                (uint32_t)(0x508)
#define PORT_SLR_OFFSET                 (uint32_t)(0x518)
#define PORT_PUR_OFFSET                 (uint32_t)(0x510)
#define PORT_PDR_OFFSET                 (uint32_t)(0x514)
#define PORT_ODR_OFFSET                 (uint32_t)(0x50C)
#define PORT_DEN_OFFSET                 (uint32_t)(0x51C)
#define PORT_AMSEL_OFFSET               (uint32_t)(0x528)
/*- GPIO APB Interrupt Control Registers offsets----------------*/
#define PORT_IS_OFFSET                  (uint32_t)(0x404)
#define PORT_IBE_OFFSET                 (uint32_t)(0x408)
#define PORT_IEV_OFFSET                 (uint32_t)(0x40C)
#define PORT_IM_OFFSET                  (uint32_t)(0x410)
#define PORT_RIS_OFFSET                 (uint32_t)(0x414)
#define PORT_MIS_OFFSET                 (uint32_t)(0x418)
#define PORT_ICR_OFFSET                 (uint32_t)(0x41C)

/*- PortA APB Registers--------------------------------*/
#define PORTA_DATA                      (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_DATA_OFFSET)))
#define PORTA_DIR                       (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_DIR_OFFSET)))
#define PORTA_LOCK                      (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_LOCK_OFFSET)))
#define PORTA_CR                        (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_CR_OFFSET)))
#define PORTA_PCTL                      (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_PCTL_OFFSET)))
#define PORTA_AFSEL                     (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_AFSEL_OFFSET)))
#define PORTA_ADCCTL                    (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_ADCCTL_OFFSET)))
#define PORTA_DMACTL                    (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_DMACTL_OFFSET)))
#define PORTA_DR2R                      (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_DR2R_OFFSET)))
#define PORTA_DR4R                      (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_DR4R_OFFSET)))
#define PORTA_DR8R                      (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_DR8R_OFFSET)))
#define PORTA_SLR                       (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_SLR_OFFSET)))
#define PORTA_PUR                       (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_PUR_OFFSET)))
#define PORTA_PDR                       (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_PDR_OFFSET)))
#define PORTA_ODR                       (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_ODR_OFFSET)))
#define PORTA_DEN                       (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_DEN_OFFSET)))
#define PORTA_AMSEL                     (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_AMSEL_OFFSET)))
#define PORTA_IS                        (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_IS_OFFSET)))
#define PORTA_IBE                       (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_IBE_OFFSET)))
#define PORTA_IEV                       (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_IEV_OFFSET)))
#define PORTA_IM                        (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_IM_OFFSET)))
#define PORTA_RIS                       (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_RIS_OFFSET)))
#define PORTA_MIS                       (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_MIS_OFFSET)))
#define PORTA_ICR                       (*((volatile uint32_t *)(PORTA_APB_BASE_ADDRESS+PORT_ICR_OFFSET)))

/*- PortB APB Registers--------------------------------*/
#define PORTB_DATA                      (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_DATA_OFFSET)))
#define PORTB_DIR                       (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_DIR_OFFSET)))
#define PORTB_LOCK                      (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_LOCK_OFFSET)))
#define PORTB_CR                        (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_CR_OFFSET)))
#define PORTB_PCTL                      (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_PCTL_OFFSET)))
#define PORTB_AFSEL                     (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_AFSEL_OFFSET)))
#define PORTB_ADCCTL                    (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_ADCCTL_OFFSET)))
#define PORTB_DMACTL                    (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_DMACTL_OFFSET)))
#define PORTB_DR2R                      (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_DR2R_OFFSET)))
#define PORTB_DR4R                      (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_DR4R_OFFSET)))
#define PORTB_DR8R                      (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_DR8R_OFFSET)))
#define PORTB_SLR                       (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_SLR_OFFSET)))
#define PORTB_PUR                       (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_PUR_OFFSET)))
#define PORTB_PDR                       (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_PDR_OFFSET)))
#define PORTB_ODR                       (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_ODR_OFFSET)))
#define PORTB_DEN                       (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_DEN_OFFSET)))
#define PORTB_AMSEL                     (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_AMSEL_OFFSET)))
#define PORTB_IS                        (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_IS_OFFSET)))
#define PORTB_IBE                       (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_IBE_OFFSET)))
#define PORTB_IEV                       (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_IEV_OFFSET)))
#define PORTB_IM                        (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_IM_OFFSET)))
#define PORTB_RIS                       (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_RIS_OFFSET)))
#define PORTB_MIS                       (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_MIS_OFFSET)))
#define PORTB_ICR                       (*((volatile uint32_t *)(PORTB_APB_BASE_ADDRESS+PORT_ICR_OFFSET)))

/*- PortC APB Registers--------------------------------*/
#define PORTC_DATA                      (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_DATA_OFFSET)))
#define PORTC_DIR                       (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_DIR_OFFSET)))
#define PORTC_LOCK                      (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_LOCK_OFFSET)))
#define PORTC_CR                        (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_CR_OFFSET)))
#define PORTC_PCTL                      (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_PCTL_OFFSET)))
#define PORTC_AFSEL                     (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_AFSEL_OFFSET)))
#define PORTC_ADCCTL                    (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_ADCCTL_OFFSET)))
#define PORTC_DMACTL                    (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_DMACTL_OFFSET)))
#define PORTC_DR2R                      (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_DR2R_OFFSET)))
#define PORTC_DR4R                      (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_DR4R_OFFSET)))
#define PORTC_DR8R                      (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_DR8R_OFFSET)))
#define PORTC_SLR                       (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_SLR_OFFSET)))
#define PORTC_PUR                       (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_PUR_OFFSET)))
#define PORTC_PDR                       (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_PDR_OFFSET)))
#define PORTC_ODR                       (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_ODR_OFFSET)))
#define PORTC_DEN                       (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_DEN_OFFSET)))
#define PORTC_AMSEL                     (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_AMSEL_OFFSET)))
#define PORTC_IS                        (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_IS_OFFSET)))
#define PORTC_IBE                       (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_IBE_OFFSET)))
#define PORTC_IEV                       (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_IEV_OFFSET)))
#define PORTC_IM                        (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_IM_OFFSET)))
#define PORTC_RIS                       (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_RIS_OFFSET)))
#define PORTC_MIS                       (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_MIS_OFFSET)))
#define PORTC_ICR                       (*((volatile uint32_t *)(PORTC_APB_BASE_ADDRESS+PORT_ICR_OFFSET)))

/*- PortD APB Registers--------------------------------*/
#define PORTD_DATA                      (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_DATA_OFFSET)))
#define PORTD_DIR                       (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_DIR_OFFSET)))
#define PORTD_LOCK                      (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_LOCK_OFFSET)))
#define PORTD_CR                        (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_CR_OFFSET)))
#define PORTD_PCTL                      (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_PCTL_OFFSET)))
#define PORTD_AFSEL                     (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_AFSEL_OFFSET)))
#define PORTD_ADCCTL                    (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_ADCCTL_OFFSET)))
#define PORTD_DMACTL                    (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_DMACTL_OFFSET)))
#define PORTD_DR2R                      (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_DR2R_OFFSET)))
#define PORTD_DR4R                      (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_DR4R_OFFSET)))
#define PORTD_DR8R                      (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_DR8R_OFFSET)))
#define PORTD_SLR                       (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_SLR_OFFSET)))
#define PORTD_PUR                       (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_PUR_OFFSET)))
#define PORTD_PDR                       (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_PDR_OFFSET)))
#define PORTD_ODR                       (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_ODR_OFFSET)))
#define PORTD_DEN                       (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_DEN_OFFSET)))
#define PORTD_AMSEL                     (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_AMSEL_OFFSET)))
#define PORTD_IS                        (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_IS_OFFSET)))
#define PORTD_IBE                       (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_IBE_OFFSET)))
#define PORTD_IEV                       (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_IEV_OFFSET)))
#define PORTD_IM                        (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_IM_OFFSET)))
#define PORTD_RIS                       (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_RIS_OFFSET)))
#define PORTD_MIS                       (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_MIS_OFFSET)))
#define PORTD_ICR                       (*((volatile uint32_t *)(PORTD_APB_BASE_ADDRESS+PORT_ICR_OFFSET)))

/*- PortD APB Registers--------------------------------*/
#define PORTE_DATA                      (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_DATA_OFFSET)))
#define PORTE_DIR                       (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_DIR_OFFSET)))
#define PORTE_LOCK                      (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_LOCK_OFFSET)))
#define PORTE_CR                        (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_CR_OFFSET)))
#define PORTE_PCTL                      (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_PCTL_OFFSET)))
#define PORTE_AFSEL                     (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_AFSEL_OFFSET)))
#define PORTE_ADCCTL                    (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_ADCCTL_OFFSET)))
#define PORTE_DMACTL                    (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_DMACTL_OFFSET)))
#define PORTE_DR2R                      (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_DR2R_OFFSET)))
#define PORTE_DR4R                      (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_DR4R_OFFSET)))
#define PORTE_DR8R                      (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_DR8R_OFFSET)))
#define PORTE_SLR                       (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_SLR_OFFSET)))
#define PORTE_PUR                       (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_PUR_OFFSET)))
#define PORTE_PDR                       (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_PDR_OFFSET)))
#define PORTE_ODR                       (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_ODR_OFFSET)))
#define PORTE_DEN                       (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_DEN_OFFSET)))
#define PORTE_AMSEL                     (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_AMSEL_OFFSET)))
#define PORTE_IS                        (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_IS_OFFSET)))
#define PORTE_IBE                       (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_IBE_OFFSET)))
#define PORTE_IEV                       (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_IEV_OFFSET)))
#define PORTE_IM                        (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_IM_OFFSET)))
#define PORTE_RIS                       (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_RIS_OFFSET)))
#define PORTE_MIS                       (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_MIS_OFFSET)))
#define PORTE_ICR                       (*((volatile uint32_t *)(PORTE_APB_BASE_ADDRESS+PORT_ICR_OFFSET)))

/*- PortF APB Registers--------------------------------*/
#define PORTF_DATA                      (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_DATA_OFFSET)))
#define PORTF_DIR                       (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_DIR_OFFSET)))
#define PORTF_LOCK                      (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_LOCK_OFFSET)))
#define PORTF_CR                        (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_CR_OFFSET)))
#define PORTF_PCTL                      (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_PCTL_OFFSET)))
#define PORTF_AFSEL                     (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_AFSEL_OFFSET)))
#define PORTF_ADCCTL                    (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_ADCCTL_OFFSET)))
#define PORTF_DMACTL                    (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_DMACTL_OFFSET)))
#define PORTF_DR2R                      (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_DR2R_OFFSET)))
#define PORTF_DR4R                      (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_DR4R_OFFSET)))
#define PORTF_DR8R                      (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_DR8R_OFFSET)))
#define PORTF_SLR                       (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_SLR_OFFSET)))
#define PORTF_PUR                       (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_PUR_OFFSET)))
#define PORTF_PDR                       (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_PDR_OFFSET)))
#define PORTF_ODR                       (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_ODR_OFFSET)))
#define PORTF_DEN                       (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_DEN_OFFSET)))
#define PORTF_AMSEL                     (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_AMSEL_OFFSET)))
#define PORTF_IS                        (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_IS_OFFSET)))
#define PORTF_IBE                       (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_IBE_OFFSET)))
#define PORTF_IEV                       (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_IEV_OFFSET)))
#define PORTF_IM                        (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_IM_OFFSET)))
#define PORTF_RIS                       (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_RIS_OFFSET)))
#define PORTF_MIS                       (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_MIS_OFFSET)))
#define PORTF_ICR                       (*((volatile uint32_t *)(PORTF_APB_BASE_ADDRESS+PORT_ICR_OFFSET)))
   
/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/
 
#endif  /* __MCU_HW_H__ */
