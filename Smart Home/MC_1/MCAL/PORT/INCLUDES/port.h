/*
=======================================================================================================================
Author       : Mamoun
Module       : PORT
File Name    : port.h
Date Created : Oct 20, 2023
Description  : Header file for the ATmega32 PORT driver.
=======================================================================================================================
*/


#ifndef MCAL_PORT_INCLUDES_PORT_H_
#define MCAL_PORT_INCLUDES_PORT_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define PORT_NUM_OF_PORTS                  (4U)
#define PORT_NUM_OF_PINS_PER_PORT          (8U)

#define PORT_PORTA_ID                      (0U)
#define PORT_PORTB_ID                      (1U)
#define PORT_PORTC_ID                      (2U)
#define PORT_PORTD_ID                      (3U)

#define PORT_PIN0_ID                       (0U)
#define PORT_PIN1_ID                       (1U)
#define PORT_PIN2_ID                       (2U)
#define PORT_PIN3_ID                       (3U)
#define PORT_PIN4_ID                       (4U)
#define PORT_PIN5_ID                       (5U)
#define PORT_PIN6_ID                       (6U)
#define PORT_PIN7_ID                       (7U)

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    PORT_NO_ERRORS,
	PORT_PORT_NUM_ERROR,
	PORT_PIN_NUM_ERROR,
	PORT_DIRECTION_ERROR
}PORT_errorStatus;

typedef enum
{
    PORT_INPUT_PIN,
    PORT_OUTPUT_PIN
}PORT_pinDirection;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : PORT_init
 * [Description]   : Initialize all pins with spicific static configurations.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void PORT_init(void);

/*=====================================================================================================================
 * [Function Name] : PORT_setPinDirection
 * [Description]   : Set the direction of a certain pin [Input - Output].
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 *                   <a_direction>   -> Indicates to the direction [INPUT - OUTPUT].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port Number Error.
 *                                                          - Pin Number Error.
 *                                                          - Invalid Direction Error.
 ====================================================================================================================*/
PORT_errorStatus PORT_setPinDirection(uint8 a_portID, uint8 a_pinID, PORT_pinDirection a_direction);

#endif /* MCAL_PORT_INCLUDES_PORT_H_ */
