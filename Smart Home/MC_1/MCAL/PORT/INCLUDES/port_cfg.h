/*
=======================================================================================================================
Author       : Mamoun
Module       : PORT
File Name    : port_cfg.h
Date Created : Oct 20, 2023
Description  : Configuration file for the ATmega32 PORT driver.
=======================================================================================================================
*/


#ifndef MCAL_PORT_INCLUDES_PORT_CFG_H_
#define MCAL_PORT_INCLUDES_PORT_CFG_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/*=====================================================================================================================
You can set the mode of any pin with only these values:
1- PORT_INPUT_FLOAT_PIN
2- PORT_INPUT_PULLUP_PIN
3- PORT_OUTPUT_LOW_PIN
4- PORT_OUTPUT_HIGH_PIN
=====================================================================================================================*/

/* PORTA Configurations. */
#define PORT_PORTA_PIN0_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTA_PIN1_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTA_PIN2_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTA_PIN3_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTA_PIN4_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTA_PIN5_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTA_PIN6_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTA_PIN7_PIN_MODE                    PORT_OUTPUT_LOW_PIN

/* PORTB Configurations. */
#define PORT_PORTB_PIN0_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTB_PIN1_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTB_PIN2_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTB_PIN3_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTB_PIN4_PIN_MODE                    PORT_INPUT_PULLUP_PIN
#define PORT_PORTB_PIN5_PIN_MODE                    PORT_INPUT_PULLUP_PIN
#define PORT_PORTB_PIN6_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTB_PIN7_PIN_MODE                    PORT_INPUT_PULLUP_PIN

/* PORTC Configurations. */
#define PORT_PORTC_PIN0_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTC_PIN1_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTC_PIN2_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTC_PIN3_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTC_PIN4_PIN_MODE                    PORT_INPUT_PULLUP_PIN
#define PORT_PORTC_PIN5_PIN_MODE                    PORT_INPUT_PULLUP_PIN
#define PORT_PORTC_PIN6_PIN_MODE                    PORT_INPUT_PULLUP_PIN
#define PORT_PORTC_PIN7_PIN_MODE                    PORT_INPUT_PULLUP_PIN

/* PORTD Configurations. */
#define PORT_PORTD_PIN0_PIN_MODE                    PORT_INPUT_PULLUP_PIN
#define PORT_PORTD_PIN1_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTD_PIN2_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTD_PIN3_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTD_PIN4_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTD_PIN5_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTD_PIN6_PIN_MODE                    PORT_OUTPUT_LOW_PIN
#define PORT_PORTD_PIN7_PIN_MODE                    PORT_OUTPUT_LOW_PIN

#endif /* MCAL_PORT_INCLUDES_PORT_CFG_H_ */
