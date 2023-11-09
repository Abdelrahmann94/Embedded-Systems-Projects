/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 20 Oct 2023                                                           */
/************************************************************************************/
#ifndef PORT_PRIVARE_H
#define PORT_PRIVARE_H

/* Macros for Registers Definition */
// Registers for Port A
#define PORT_u8_PINA_REG        *((volatile u8 *)0x39)
#define PORT_u8_DDRA_REG        *((volatile u8 *)0x3A)
#define PORT_u8_PORTA_REG       *((volatile u8 *)0x3B)

// Registers for Port B
#define PORT_u8_PINB_REG        *((volatile u8 *)0x36)
#define PORT_u8_DDRB_REG        *((volatile u8 *)0x37)
#define PORT_u8_PORTB_REG       *((volatile u8 *)0x38)

// Registers for Port C
#define PORT_u8_PINC_REG        *((volatile u8 *)0x33)
#define PORT_u8_DDRC_REG        *((volatile u8 *)0x34)
#define PORT_u8_PORTC_REG       *((volatile u8 *)0x35)

// Registers for Port D
#define PORT_u8_PIND_REG        *((volatile u8 *)0x30)
#define PORT_u8_DDRD_REG        *((volatile u8 *)0x31)
#define PORT_u8_PORTD_REG       *((volatile u8 *)0x32)


/* Macros for Initial Direction and Value  */
#define PORT_u8_INITIAL_OUTPUT            1
#define PORT_u8_INITIAL_INPUT             0
#define PORT_u8_OUTPUT_HIGH               1
#define PORT_u8_OUTPUT_LOW                0
#define PORT_u8_INPUT_PULLUP              1
#define PORT_u8_INPUT_FLOATING            0


#endif