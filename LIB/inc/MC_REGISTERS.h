/*
 * File Name: MC_REGISTERS.h
 * Creation Date: 07/20/2020
 * Author: Rehab
 * Description: Header File for registers' addresses of ATMAGA32, bits' names....
 */ 

#ifndef __MC_REGISTERS__
#define __MC_REGISTERS__

#define F_CPU 16000000ul

//FILES INCLUDING
#include "STD_TYPES.h"

//BITS
#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

/************************************************************************/
/*                         GENERAL REGISTERS                            */
/************************************************************************/
//GENERAL REGISTERS
#define SFIOR *((volatile ptr_uint8_t)(0X50))
#define SREG *((volatile ptr_uint8_t)(0X5F))
#define MCUCSR *((volatile ptr_uint8_t)(0X54))


//SFIOR REGISTER BITS
#define ACME BIT3
#define ADTS0 BIT5
#define ADTS1 BIT6
#define ADTS2 BIT7
//SREG REGISTER BITS
#define I BIT7
//MCUCSR REGISTER BITS
#define PORF BIT0
#define EXTRF BIT1
#define BORF BIT2
#define WDRF BIT3
#define JTRF BIT4
/************************************************************************/
/*                         GPIO REGISTERS                               */
/************************************************************************/
//PORTA REGISTERS
#define PORTA_BASE 0X39
#define PINA *((volatile ptr_uint8_t)(PORTA_BASE))
#define DDRA *((volatile ptr_uint8_t)(PORTA_BASE+1))
#define PORTA *((volatile ptr_uint8_t)(PORTA_BASE+2))

//PORTB REGISTERS 
#define PORTB_BASE 0X36
#define PINB *((volatile ptr_uint8_t)(PORTB_BASE))
#define DDRB *((volatile ptr_uint8_t)(PORTB_BASE+1))
#define PORTB *((volatile ptr_uint8_t)(PORTB_BASE+2))

//PORTC REGISTERS
#define PORTC_BASE 0X33
#define PINC *((volatile ptr_uint8_t)(PORTC_BASE))
#define DDRC *((volatile ptr_uint8_t)(PORTC_BASE+1))
#define PORTC *((volatile ptr_uint8_t)(PORTC_BASE+2))

//PORTD REGISTERS
#define PORTD_BASE 0X30
#define PIND *((volatile ptr_uint8_t)(PORTD_BASE))
#define DDRD *((volatile ptr_uint8_t)(PORTD_BASE+1))
#define PORTD *((volatile ptr_uint8_t)(PORTD_BASE+2))
/************************************************************************/
/*                          ADC REGISTERS                               */
/************************************************************************/
//ADC REGISTERS
#define ADCL *((volatile ptr_uint8_t)(0X24))
#define ADCH *((volatile ptr_uint8_t)(0X25))
#define ADC *((volatile ptr_uint16_t)(0X24))
#define ADCSRA *((volatile ptr_uint8_t)(0X26))
#define ADMUX *((volatile ptr_uint8_t)(0X27))


//ADMUX REGISTER BITS
#define MUX0 BIT0
#define MUX1 BIT1
#define MUX2 BIT2
#define MUX3 BIT3
#define MUX4 BIT4
#define ADLAR BIT5
#define REFS0 BIT6
#define REFS1 BIT7
//ADCSRA REGISTER BITS
#define ADPS0 BIT0
#define ADPS1 BIT1
#define ADPS2 BIT2
#define ADIE BIT3
#define ADIF BIT4
#define ADATE BIT5
#define ADSC BIT6
#define ADEN BIT7
/************************************************************************/
/*                        EXTERNAL INTERRUPT REGISTERS                  */
/************************************************************************/
//EXTERNAL INTERRUPT REGISTERS
#define GICR *((volatile ptr_uint8_t)(0X5B))
#define GIFR *((volatile ptr_uint8_t)(0X5A))
#define MCUCR *((volatile ptr_uint8_t)(0X55))
#define MCUCSR *((volatile ptr_uint8_t)(0X54))


//GICR REGISTER BITS
#define INT2 BIT5
#define INT0 BIT6
#define INT1 BIT7
//GIFR REGISTER BITS
#define INTF2 BIT5
#define INTF0 BIT6
#define INTF1 BIT7
//MCUCR REGISTER BITS
#define ISC00 BIT0
#define ISC01 BIT1
#define ISC10 BIT2
#define ISC11 BIT3
//MCUCSR REGISTER BITS
#define ISC2 BIT6
/************************************************************************/
/*                      WATCHDOG TIMER REGISTERS                        */
/************************************************************************/
//WATCHDOG TIMER REGISTERS  
#define WDTCR *((volatile ptr_uint8_t)(0X41))


//WDTCR REGISTER BITS
#define WDP0 BIT0
#define WDP1 BIT1
#define WDP2 BIT2
#define WDE BIT3
#define WDTOE BIT4
/************************************************************************/
/*                         GENERAL TIMERS REGISTERS                     */
/************************************************************************/
//GENERAL TIMERS REGISTERS
#define TIMSK *((volatile ptr_uint8_t)(0X59))
#define TIFR *((volatile ptr_uint8_t)(0X58))


//TIMSKR REGISTER BITS
#define TOIE0 BIT0
#define OCIE0 BIT1
#define TOIE1 BIT2
#define OCIE1B BIT3
#define OCIE1A BIT4
#define TICIE1 BIT5
#define TOIE2 BIT6
#define OCIE2 BIT7
//TIFR REGISTER BITS
#define TOV0 BIT0
#define OCF0 BIT1
#define TOV1 BIT2
#define OCF1B BIT3
#define OCF1A BIT4
#define ICF1 BIT5
#define TOV2 BIT6
#define OCF2 BIT7
/************************************************************************/
/*                         TIMER0 REGISTERS                             */
/************************************************************************/
//TIMER0 REGISTERS 
#define TCCR0 *((volatile ptr_uint8_t)(0X53))
#define TCNT0 *((volatile ptr_uint8_t)(0X52))
#define OCR0 *((volatile ptr_uint8_t)(0X5C))


//TCCR0 REGISTER BITS
#define CS00 BIT0
#define CS01 BIT1
#define CS02 BIT2
#define WGM01 BIT3
#define COM00 BIT4
#define COM01 BIT5
#define WGM00 BIT6
#define FOC0 BIT7
/************************************************************************/
/*                         TIMER1 REGISTERS                             */
/************************************************************************/
//TIMER1 REGISTERS 
#define TCCR1A *((volatile ptr_uint8_t)(0X4F))
#define TCCR1B *((volatile ptr_uint8_t)(0X4E))
#define TCNT1H *((volatile ptr_uint8_t)(0X4D))
#define TCNT1L *((volatile ptr_uint8_t)(0X4C))
#define TCNT1 *((volatile ptr_uint16_t)(0X4C))
#define OCR1AH *((volatile ptr_uint8_t)(0X4B))
#define OCR1AL *((volatile ptr_uint8_t)(0X4A))
#define OCR1A *((volatile ptr_uint16_t)(0X4A))
#define OCR1BH *((volatile ptr_uint8_t)(0X49))
#define OCR1BL *((volatile ptr_uint8_t)(0X48))
#define OCR1B *((volatile ptr_uint16_t)(0X48))
#define ICR1H *((volatile ptr_uint8_t)(0X47))
#define ICR1L *((volatile ptr_uint8_t)(0X46))
#define ICR1 *((volatile ptr_uint16_t)(0X46))

//TCCR1A REGISTER BITS
#define WGM10 BIT0
#define WGM11 BIT1
#define FOC1B BIT2
#define FOC1A BIT3
#define COM1B0 BIT4
#define COM1B1 BIT5
#define COM1A0 BIT6
#define COM1A1 BIT7
//TCCR1B REGISTER BITS
#define CS10 BIT0
#define CS11 BIT1
#define CS12 BIT2
#define WGM12 BIT3
#define WGM13 BIT4
#define ICES1 BIT6
#define ICNC1 BIT7
/************************************************************************/
/*                         TIMER2 REGISTERS                             */
/************************************************************************/
//TIMER2 REGISTERS 
#define TCCR2 *((volatile ptr_uint8_t)(0X45))
#define TCNT2 *((volatile ptr_uint8_t)(0X44))
#define OCR2 *((volatile ptr_uint8_t)(0X43))


//TCCR2 REGISTER BITS
#define CS20 BIT0
#define CS21 BIT1
#define CS22 BIT2
#define WGM21 BIT3
#define COM20 BIT4
#define COM21 BIT5
#define WGM20 BIT6
#define FOC2 BIT7
/************************************************************************/
/*                         EEPROM REGISTERS                             */
/************************************************************************/
//EEPROM REGISTERS
#define EEARH *((volatile uint8_t*)(0X3F))
#define EEARL *((volatile uint8_t*)(0X3E))
#define EEAR *((volatile uint16_t*)(0X3E))
#define EEDR *((volatile uint8_t*)(0X3D))
#define EECR *((volatile uint8_t*)(0X3C))


//EECR REGISTER BITS
#define EERE BIT0
#define EEWE BIT1
#define EEMWE BIT2
#define EERIE BIT3
/************************************************************************/
/*                          USART REGISTERS                             */
/************************************************************************/
//USART REGISTERS
#define UDR *((volatile ptr_uint8_t)(0X2C))
#define UCSRA *((volatile ptr_uint8_t)(0X2B))
#define UCSRB *((volatile ptr_uint8_t)(0X2A))
#define UCSRC *((volatile ptr_uint8_t)(0X40))
#define UBRRL *((volatile ptr_uint8_t)(0X29))
#define UBRRH *((volatile ptr_uint8_t)(0X40))


//UCSRA REGISTER BITS
#define MPCM BIT0
#define U2X BIT1
#define PE BIT2
#define DOR BIT3
#define FE BIT4
#define UDRE BIT5
#define TXC BIT6
#define RXC BIT7
//UCSRB REGISTER BITS
#define TXB8 BIT0
#define RXB8 BIT1
#define UCSZ2 BIT2
#define TXEN BIT3
#define RXEN BIT4
#define UDRIE BIT5
#define TXCIE BIT6
#define RXCIE BIT7
//UCSRC REGISTER BITS
#define UCPOL BIT0
#define UCSZ0 BIT1
#define UCSZ1 BIT2
#define USBS BIT3
#define UPM0 BIT4
#define UPM1 BIT5
#define UMSEL BIT6
#define URSEL BIT7
/************************************************************************/
/*                           SPI REGISTERS                              */
/************************************************************************/
//SPI REGISTERS
#define SPDR *((volatile ptr_uint8_t)(0X2F))
#define SPSR *((volatile ptr_uint8_t)(0X2E))
#define SPCR *((volatile ptr_uint8_t)(0X2D))


//SPSR REGISTER BITS
#define SPI2X BIT0
#define WCOL BIT6
#define SPIF BIT7
//SPCR REGISTER BITS
#define SPR0 BIT0
#define SPR1 BIT1
#define CPHA BIT2
#define CPOL BIT3
#define MSTR BIT4
#define DORD BIT5
#define SPE BIT6
#define SPIE BIT7
/************************************************************************/
/*                           TWI REGISTERS                              */
/************************************************************************/
//TWI REGISTERS
#define TWCR *((volatile ptr_uint8_t)(0X56))
#define TWDR *((volatile ptr_uint8_t)(0X23))
#define TWAR *((volatile ptr_uint8_t)(0X22))
#define TWSR *((volatile ptr_uint8_t)(0X21))
#define TWBR *((volatile ptr_uint8_t)(0X20))

//TWCR REGISTER BITS
#define TWIE BIT0
#define TWEN BIT2
#define TWWC BIT3
#define TWSTO BIT4
#define TWSTA BIT5
#define TWEA BIT6
#define TWINT BIT7
//TWDR REGISTER BITS
#define TWD0 BIT0
#define TWD1 BIT1
#define TWD2 BIT2
#define TWD3 BIT3
#define TWD4 BIT4
#define TWD5 BIT5
#define TWD6 BIT6
#define TWD7 BIT7
//TWAR REGISTER BITS
#define TWGCE BIT0
#define TWA0 BIT1
#define TWA1 BIT2
#define TWA2 BIT3
#define TWA3 BIT4
#define TWA4 BIT5
#define TWA5 BIT6
#define TWA6 BIT7
//TWSR REGISTER BITS
#define TWPS0 BIT0
#define TWPS1 BIT1
#define TWS3 BIT3
#define TWS4 BIT4
#define TWS5 BIT5
#define TWS6 BIT6
#define TWS7 BIT7
/************************************************************************/
/*                   ANALOG COMPARATOR REGISTERS                        */
/************************************************************************/
//ANALOG COMPARATOR REGISTERS  
#define ACSR *((volatile ptr_uint8_t)(0X28))


//ACSR REGISTER BITS
#define ACIS0 BIT0
#define ACIS1 BIT1
#define ACIC BIT2
#define ACIE BIT3
#define ACI BIT4
#define ACO BIT5
#define ACBG BIT6
#define ACD BIT7
/************************************************************************/
#endif