/*
=======================================================================================================================
Author       : Mamoun
Module       : DIO
File Name    : dio.c
Date Created : Oct 20, 2023
Description  : Source file for the ATmega32 DIO driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../LIB/Include/std_types.h"
#include "../../../LIB/Include/common_macros.h"
#include "../INCLUDES/dio_prv.h"
#include "../INCLUDES/dio_cfg.h"
#include "../INCLUDES/dio.h"
#include <avr/io.h>

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : DIO_writePin
 * [Description]   : Write a certain value (High or Low) in a certain pin.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 *                   <a_value>       -> Indicates to the value [High - Low].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port Number Error.
 *                                                          - Pin Number Error.
 *                                                          - Invalid Level Error.
 ====================================================================================================================*/
DIO_errorStatus DIO_writePin(uint8 a_portID, uint8 a_pinID, DIO_pinStatus a_value)
{
    DIO_errorStatus LOC_errorStatus = DIO_NO_ERRORS;

    if(a_portID >= DIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = DIO_PORT_NUM_ERROR;
    }

    else if(a_pinID >= DIO_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = DIO_PIN_NUM_ERROR;
    }

    else if((a_value != DIO_HIGH_PIN) && (a_value != DIO_LOW_PIN))
    {
        LOC_errorStatus = DIO_LEVEL_ERROR;
    }

    else
    {
        switch (a_portID)
        {
        case DIO_PORTA_ID:
            WRITE_BIT(PORTA,a_pinID,a_value);
            break;

        case DIO_PORTB_ID:
            WRITE_BIT(PORTB,a_pinID,a_value);
            break;

        case DIO_PORTC_ID:
            WRITE_BIT(PORTC,a_pinID,a_value);
            break;

        case DIO_PORTD_ID:
            WRITE_BIT(PORTD,a_pinID,a_value);
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : DIO_writePort
 * [Description]   : Write a certain value in a certain port.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_value>       -> Indicates to the value of the port [0 ~ 255].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port Number Error.
 *                                                          - Invalid Level Error.
 ====================================================================================================================*/
DIO_errorStatus DIO_writePort(uint8 a_portID, uint8 a_value)
{
    DIO_errorStatus LOC_errorStatus = DIO_NO_ERRORS;

    if(a_portID >= DIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = DIO_PORT_NUM_ERROR;
    }

    else if(a_value > DIO_REGISTERS_MAX_VALUE)
    {
        LOC_errorStatus = DIO_LEVEL_ERROR;
    }

    else
    {
        switch (a_portID)
        {
        case DIO_PORTA_ID:
            PORTA = a_value;
            break;

        case DIO_PORTB_ID:
            PORTB = a_value;
            break;

        case DIO_PORTC_ID:
            PORTC = a_value;
            break;

        case DIO_PORTD_ID:
            PORTD = a_value;
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : DIO_readPin
 * [Description]   : Read the value of a certain pin [High - LOW].
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 *                   <a_ptr2value>   -> Pointer to variable to store the value of the pin.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port Number Error.
 *                                                          - Pin Number Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
DIO_errorStatus DIO_readPin(uint8 a_portID, uint8 a_pinID, DIO_pinStatus* a_ptr2value)
{
    DIO_errorStatus LOC_errorStatus = DIO_NO_ERRORS;

    if(a_portID >= DIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = DIO_PORT_NUM_ERROR;
    }

    else if(a_pinID >= DIO_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = DIO_PIN_NUM_ERROR;
    }

    else if(a_ptr2value == NULL_PTR)
    {
        LOC_errorStatus = DIO_NULL_PTR_ERROR;
    }

    else
    {
        switch (a_portID)
        {
        case DIO_PORTA_ID:
            *a_ptr2value = GET_BIT(PINA,a_pinID);
            break;

        case DIO_PORTB_ID:
            *a_ptr2value = GET_BIT(PINB,a_pinID);
            break;

        case DIO_PORTC_ID:
            *a_ptr2value = GET_BIT(PINC,a_pinID);
            break;

        case DIO_PORTD_ID:
            *a_ptr2value = GET_BIT(PIND,a_pinID);
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : DIO_readPort
 * [Description]   : Read the value of a certain port.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_value>       -> Pointer to variable to store the value of the port.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port Number Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
DIO_errorStatus DIO_readPort(uint8 a_portID, uint8* a_ptr2value)
{
    DIO_errorStatus LOC_errorStatus = DIO_NO_ERRORS;

    if(a_portID >= DIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = DIO_PORT_NUM_ERROR;
    }

    else if(a_ptr2value == NULL_PTR)
    {
        LOC_errorStatus = DIO_NULL_PTR_ERROR;
    }

    else
    {
        switch (a_portID)
        {
        case DIO_PORTA_ID:
            *a_ptr2value = PINA;
            break;

        case DIO_PORTB_ID:
            *a_ptr2value = PINB;
            break;

        case DIO_PORTC_ID:
            *a_ptr2value = PINC;
            break;

        case DIO_PORTD_ID:
            *a_ptr2value = PIND;
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : DIO_togglePin
 * [Description]   : Toggle the value of a certain pin.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port Number Error.
 *                                                          - Pin Number Error.
 ====================================================================================================================*/
DIO_errorStatus DIO_togglePin(uint8 a_portID, uint8 a_pinID)
{
    DIO_errorStatus LOC_errorStatus = DIO_NO_ERRORS;

    if(a_portID >= DIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = DIO_PORT_NUM_ERROR;
    }

    else if(a_pinID >= DIO_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = DIO_PIN_NUM_ERROR;
    }

    else
    {
        switch (a_portID)
        {
        case DIO_PORTA_ID:
            TOGGLE_BIT(PORTA,a_pinID);
            break;

        case DIO_PORTB_ID:
            TOGGLE_BIT(PORTB,a_pinID);
            break;

        case DIO_PORTC_ID:
            TOGGLE_BIT(PORTC,a_pinID);
            break;

        case DIO_PORTD_ID:
            TOGGLE_BIT(PORTD,a_pinID);
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}
