/*
=======================================================================================================================
Author       : Mamoun
Module       : PORT
File Name    : port.c
Date Created : Oct 20, 2023
Description  : Source file for the ATmega32 PORT driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../LIB/Include/std_types.h"
#include "../../../LIB/Include/common_macros.h"
#include "../INCLUDES/port_prv.h"
#include "../INCLUDES/port_cfg.h"
#include "../INCLUDES/port.h"
#include <avr/io.h>

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : PORT_init
 * [Description]   : Initialize all pins with specific static configurations.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void PORT_init(void)
{
    #undef  PORT_INPUT_PULLUP_PIN
    #define PORT_INPUT_PULLUP_PIN  0

    #undef  PORT_OUTPUT_LOW_PIN
    #define PORT_OUTPUT_LOW_PIN    1

    #undef  PORT_OUTPUT_HIGH_PIN
    #define PORT_OUTPUT_HIGH_PIN   1

    DDRA = CONCAT(PORT_PORTA_PIN7_PIN_MODE,PORT_PORTA_PIN6_PIN_MODE,PORT_PORTA_PIN5_PIN_MODE,PORT_PORTA_PIN4_PIN_MODE,PORT_PORTA_PIN3_PIN_MODE,PORT_PORTA_PIN2_PIN_MODE,PORT_PORTA_PIN1_PIN_MODE,PORT_PORTA_PIN0_PIN_MODE);
    DDRB = CONCAT(PORT_PORTB_PIN7_PIN_MODE,PORT_PORTB_PIN6_PIN_MODE,PORT_PORTB_PIN5_PIN_MODE,PORT_PORTB_PIN4_PIN_MODE,PORT_PORTB_PIN3_PIN_MODE,PORT_PORTB_PIN2_PIN_MODE,PORT_PORTB_PIN1_PIN_MODE,PORT_PORTB_PIN0_PIN_MODE);
    DDRC = CONCAT(PORT_PORTC_PIN7_PIN_MODE,PORT_PORTC_PIN6_PIN_MODE,PORT_PORTC_PIN5_PIN_MODE,PORT_PORTC_PIN4_PIN_MODE,PORT_PORTC_PIN3_PIN_MODE,PORT_PORTC_PIN2_PIN_MODE,PORT_PORTC_PIN1_PIN_MODE,PORT_PORTC_PIN0_PIN_MODE);
    DDRD = CONCAT(PORT_PORTD_PIN7_PIN_MODE,PORT_PORTD_PIN6_PIN_MODE,PORT_PORTD_PIN5_PIN_MODE,PORT_PORTD_PIN4_PIN_MODE,PORT_PORTD_PIN3_PIN_MODE,PORT_PORTD_PIN2_PIN_MODE,PORT_PORTD_PIN1_PIN_MODE,PORT_PORTD_PIN0_PIN_MODE);

    #undef  PORT_INPUT_PULLUP_PIN
    #define PORT_INPUT_PULLUP_PIN  1

    #undef  PORT_OUTPUT_LOW_PIN
    #define PORT_OUTPUT_LOW_PIN    0

    #undef  PORT_OUTPUT_HIGH_PIN
    #define PORT_OUTPUT_HIGH_PIN   1

    PORTA = CONCAT(PORT_PORTA_PIN7_PIN_MODE,PORT_PORTA_PIN6_PIN_MODE,PORT_PORTA_PIN5_PIN_MODE,PORT_PORTA_PIN4_PIN_MODE,PORT_PORTA_PIN3_PIN_MODE,PORT_PORTA_PIN2_PIN_MODE,PORT_PORTA_PIN1_PIN_MODE,PORT_PORTA_PIN0_PIN_MODE);
    PORTB = CONCAT(PORT_PORTB_PIN7_PIN_MODE,PORT_PORTB_PIN6_PIN_MODE,PORT_PORTB_PIN5_PIN_MODE,PORT_PORTB_PIN4_PIN_MODE,PORT_PORTB_PIN3_PIN_MODE,PORT_PORTB_PIN2_PIN_MODE,PORT_PORTB_PIN1_PIN_MODE,PORT_PORTB_PIN0_PIN_MODE);
    PORTC = CONCAT(PORT_PORTC_PIN7_PIN_MODE,PORT_PORTC_PIN6_PIN_MODE,PORT_PORTC_PIN5_PIN_MODE,PORT_PORTC_PIN4_PIN_MODE,PORT_PORTC_PIN3_PIN_MODE,PORT_PORTC_PIN2_PIN_MODE,PORT_PORTC_PIN1_PIN_MODE,PORT_PORTC_PIN0_PIN_MODE);
    PORTD = CONCAT(PORT_PORTD_PIN7_PIN_MODE,PORT_PORTD_PIN6_PIN_MODE,PORT_PORTD_PIN5_PIN_MODE,PORT_PORTD_PIN4_PIN_MODE,PORT_PORTD_PIN3_PIN_MODE,PORT_PORTD_PIN2_PIN_MODE,PORT_PORTD_PIN1_PIN_MODE,PORT_PORTD_PIN0_PIN_MODE);

    #undef  PORT_OUTPUT_LOW_PIN
    #define PORT_OUTPUT_LOW_PIN    2

    #undef  PORT_OUTPUT_HIGH_PIN
    #define PORT_OUTPUT_HIGH_PIN   3
}

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
PORT_errorStatus PORT_setPinDirection(uint8 a_portID, uint8 a_pinID, PORT_pinDirection a_direction)
{
    PORT_errorStatus LOC_errorStatus = PORT_NO_ERRORS;

    if(a_portID >= PORT_NUM_OF_PORTS)
    {
        LOC_errorStatus = PORT_PORT_NUM_ERROR;
    }

    else if(a_pinID >= PORT_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = PORT_PIN_NUM_ERROR;
    }

    else if((a_direction != PORT_INPUT_PIN) && (a_direction != PORT_OUTPUT_PIN))
    {
        LOC_errorStatus = PORT_DIRECTION_ERROR;
    }

    else
    {
        switch (a_portID)
        {
        case PORT_PORTA_ID:
            WRITE_BIT(DDRA,a_pinID,a_direction);
            break;

        case PORT_PORTB_ID:
            WRITE_BIT(DDRB,a_pinID,a_direction);
            break;

        case PORT_PORTC_ID:
            WRITE_BIT(DDRC,a_pinID,a_direction);
            break;

        case PORT_PORTD_ID:
            WRITE_BIT(DDRD,a_pinID,a_direction);
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}
