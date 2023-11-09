/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 20 Oct 2023                                                           */
/************************************************************************************/
#ifndef PORT_CONFIG_H
#define PORT_CONFIG_H

/* Selection  Initialization Direction for all Pins 
	Options: PORT_u8_INITIAL_OUTPUT
			 PORT_u8_INITIAL_INPUT         */
			 
// PORTA 
#define PORT_u8_PA0_DIRECTION             PORT_u8_INITIAL_INPUT
#define PORT_u8_PA1_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PA2_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PA3_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PA4_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PA5_DIRECTION             PORT_u8_INITIAL_INPUT
#define PORT_u8_PA6_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PA7_DIRECTION             PORT_u8_INITIAL_OUTPUT
// PORTB 
#define PORT_u8_PB0_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PB1_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PB2_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PB3_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PB4_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PB5_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PB6_DIRECTION             PORT_u8_INITIAL_INPUT
#define PORT_u8_PB7_DIRECTION             PORT_u8_INITIAL_OUTPUT
// PORTC 
#define PORT_u8_PC0_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PC1_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PC2_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PC3_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PC4_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PC5_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PC6_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PC7_DIRECTION             PORT_u8_INITIAL_OUTPUT
// PORTD 
#define PORT_u8_PD0_DIRECTION             PORT_u8_INITIAL_INPUT
#define PORT_u8_PD1_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PD2_DIRECTION             PORT_u8_INITIAL_INPUT
#define PORT_u8_PD3_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PD4_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PD5_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PD6_DIRECTION             PORT_u8_INITIAL_OUTPUT
#define PORT_u8_PD7_DIRECTION             PORT_u8_INITIAL_OUTPUT

/* Selection  Initialization Value for all Pins 
	Options: PORT_u8_OUTPUT_HIGH
			 PORT_u8_OUTPUT_LOW
			 PORT_u8_INPUT_PULLUP
			 PORT_u8_INPUT_FLOATING           */
			 
// PORTA 
#define PORT_u8_PA0_VALUE             PORT_u8_INPUT_FLOATING
#define PORT_u8_PA1_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PA2_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PA3_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PA4_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PA5_VALUE             PORT_u8_INPUT_PULLUP
#define PORT_u8_PA6_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PA7_VALUE             PORT_u8_OUTPUT_LOW
// PORTB                              
#define PORT_u8_PB0_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PB1_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PB2_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PB3_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PB4_VALUE             PORT_u8_OUTPUT_HIGH
#define PORT_u8_PB5_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PB6_VALUE             PORT_u8_INPUT_PULLUP
#define PORT_u8_PB7_VALUE             PORT_u8_OUTPUT_LOW
// PORTC                              
#define PORT_u8_PC0_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PC1_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PC2_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PC3_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PC4_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PC5_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PC6_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PC7_VALUE             PORT_u8_OUTPUT_LOW
// PORTD                              
#define PORT_u8_PD0_VALUE             PORT_u8_INPUT_PULLUP
#define PORT_u8_PD1_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PD2_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PD3_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PD4_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PD5_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PD6_VALUE             PORT_u8_OUTPUT_LOW
#define PORT_u8_PD7_VALUE             PORT_u8_OUTPUT_LOW



/* Macros for Concatination */
#define CONC(B7,B6,B5,B4,B3,B2,B1,B0)             CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)        0b##B7##B6##B5##B4##B3##B2##B1##B0

#endif
