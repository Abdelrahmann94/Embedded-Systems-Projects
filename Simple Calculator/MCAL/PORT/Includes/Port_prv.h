/*
 * Port_priv.h
 */

#ifndef MCAL_PORT_INCLUDES_PORT_PRIV_H_
#define MCAL_PORT_INCLUDES_PORT_PRIV_H_

/*
 * Port_priv.h
 *
 *  Created on: ???/???/????
 *      Author: EGYPT
 */


#define DDRA  (*((volatile u8*)0x3a))
#define PORTA (*((volatile u8*)0x3b))
#define PINA  (*((volatile u8*)0x39))

#define DDRB  *((volatile u8*)0x37)
#define PORTB *((volatile u8*)0x38)
#define PINB  *((volatile u8*)0x36)

#define DDRC  *((volatile u8*)0x34)
#define PORTC *((volatile u8*)0x35)
#define PINC  *((volatile u8*)0x33)

#define DDRD  *((volatile u8*)0x31)
#define PORTD *((volatile u8*)0x32)
#define PIND  *((volatile u8*)0x30)

#define PORT_u8NUMBER_OF_PINS 				31
#define PORT_u8NUMBER_OF_DIRECTION 			1
#define PORT_u8REGISTER_SIZE 				8
#define PORT_u8PORTA 					    0
#define PORT_u8PORTB					    1
#define PORT_u8PORTC 					    2
#define PORT_u8PORTD					    3




#endif /* MCAL_PORT_INCLUDES_PORT_PRIV_H_ */
