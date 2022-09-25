/*
 * registers.h
 *
 *  Author: Eyad Hossam
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_	

#include "types.h"

/************************************************************************/
/*                         DIO definitions                              */
/************************************************************************/

//PORT_A
#define DDRA *((volatile uint8_t*)0x3A)
#define PORTA *((volatile uint8_t*)0x3B)
#define PINA *((volatile uint8_t*)0x39)

//PORT_B
#define DDRB *((volatile uint8_t*)0x37)
#define PORTB *((volatile uint8_t*)0x38)
#define PINB *((volatile uint8_t*)0x36)

//PORT_C
#define DDRC *((volatile uint8_t*)0x34)
#define PORTC *((volatile uint8_t*)0x35)
#define PINC *((volatile uint8_t*)0x33)

//PORT_D
#define DDRD *((volatile uint8_t*)0x31)
#define PORTD *((volatile uint8_t*)0x32)
#define PIND *((volatile uint8_t*)0x30)

/************************************************************************/
/*                         TIMER definitions                            */
/************************************************************************/

#define TCCR0 *((volatile uint8_t*)0x53)
#define TIFR  *((volatile uint8_t*)0x58)
#define TCNT0 *((volatile uint8_t*)0x52)

/************************************************************************/
/*                        INTERRUPTS                                    */
/************************************************************************/

#define SREG   *((volatile uint8_t*)0x5F)
#define MCUCR  *((volatile uint8_t*)0x55)
#define GICR   *((volatile uint8_t*)0x5B)
#define MCUCSR *((volatile uint8_t*)0x54)

#endif /* REGISTERS_H_ */