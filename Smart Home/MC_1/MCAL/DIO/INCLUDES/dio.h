/*
=======================================================================================================================
Author       : Mamoun
Module       : DIO
File Name    : dio.h
Date Created : Oct 20, 2023
Description  : Header file for the ATmega32 DIO driver.
=======================================================================================================================
*/


#ifndef MCAL_DIO_INCLUDES_DIO_H_
#define MCAL_DIO_INCLUDES_DIO_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define DIO_NUM_OF_PORTS                  (4U)
#define DIO_NUM_OF_PINS_PER_PORT          (8U)

#define DIO_PORTA_ID                      (0U)
#define DIO_PORTB_ID                      (1U)
#define DIO_PORTC_ID                      (2U)
#define DIO_PORTD_ID                      (3U)

#define DIO_PIN0_ID                       (0U)
#define DIO_PIN1_ID                       (1U)
#define DIO_PIN2_ID                       (2U)
#define DIO_PIN3_ID                       (3U)
#define DIO_PIN4_ID                       (4U)
#define DIO_PIN5_ID                       (5U)
#define DIO_PIN6_ID                       (6U)
#define DIO_PIN7_ID                       (7U)

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    DIO_NO_ERRORS,
	DIO_PORT_NUM_ERROR,
	DIO_PIN_NUM_ERROR,
	DIO_LEVEL_ERROR,
	DIO_NULL_PTR_ERROR
}DIO_errorStatus;

typedef enum
{
    DIO_LOW_PIN,
    DIO_HIGH_PIN
}DIO_pinStatus;

/*=====================================================================================================================
                                         < Functions Prototypes >
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
DIO_errorStatus DIO_writePin(uint8 a_portID, uint8 a_pinID, DIO_pinStatus a_value);

/*=====================================================================================================================
 * [Function Name] : DIO_writePort
 * [Description]   : Write a certain value in a certain port.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_value>       -> Indicates to the value of the port [0 ~ 255].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port Number Error.
 *                                                          - Invalid Level Error.
 ====================================================================================================================*/
DIO_errorStatus DIO_writePort(uint8 a_portID, uint8 a_value);

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
DIO_errorStatus DIO_readPin(uint8 a_portID, uint8 a_pinID, DIO_pinStatus* a_ptr2value);

/*=====================================================================================================================
 * [Function Name] : DIO_readPort
 * [Description]   : Read the value of a certain port.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_value>       -> Pointer to variable to store the value of the port.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port Number Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
DIO_errorStatus DIO_readPort(uint8 a_portID, uint8* a_ptr2value);

/*=====================================================================================================================
 * [Function Name] : DIO_togglePin
 * [Description]   : Toggle the value of a certain pin.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port Number Error.
 *                                                          - Pin Number Error.
 ====================================================================================================================*/
DIO_errorStatus DIO_togglePin(uint8 a_portID, uint8 a_pinID);

#endif /* MCAL_DIO_INCLUDES_DIO_H_ */
