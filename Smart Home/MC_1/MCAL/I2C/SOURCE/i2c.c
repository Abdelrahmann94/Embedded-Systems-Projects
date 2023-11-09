/*
=======================================================================================================================
Author       : Mamoun
Module       : I2C
File Name    : i2c.c
Date Created : Oct 30, 2023
Description  : Source file for the ATmega32 I2C driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../LIB/Include/std_types.h"
#include "../../../LIB/Include/common_macros.h"
#include "../INCLUDES/i2c_prv.h"
#include "../INCLUDES/i2c_cfg.h"
#include "../INCLUDES/i2c.h"
#include <avr/io.h>

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : I2C_init
 * [Description]   : Initialize the I2C peripheral SCL frequency and set its slave address.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void I2C_init(void)
{

	TWBR = (uint8)((uint32)((F_CPU / I2C_SCL_FREQUENCY) - 16) / 2);    /* Set bit rate value.            */
    TWAR = ((TWAR & 0X01) | (I2C_DEVICE_ADDRESS << 1));                /* Set this device slave address. */
    TWSR = (TWSR & 0XFC);                                              /* Set the prescaler value to 1.  */
    SET_BIT(TWCR,TWEN);                                                /* Enable the I2C peripheral.     */
}

/*=====================================================================================================================
 * [Function Name] : I2C_sendStartBit
 * [Description]   : Send the start bit condition on the I2C bus.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void I2C_sendStartBit(void)
{
    TWCR = ((1 << TWINT) | (1 << TWSTA) | (1 << TWEN));
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

/*=====================================================================================================================
 * [Function Name] : I2C_sendAddress
 * [Description]   : Send the address of the required slave on the I2C bus.
 * [Arguments]     : <a_slaveAddress>   -> The address of the required slave.
 *                   <a_direction>      -> The message direction control bit [Read or Write].
 * [return]        : The function returns void
 ====================================================================================================================*/
void I2C_sendAddress(uint8 a_slaveAddress, I2C_messageDirection a_direction)
{
	TWDR = ((a_slaveAddress << 1) | (a_direction & 0X01));
	TWCR = ((1 << TWINT) | (1 << TWEN));
	while(BIT_IS_CLEAR(TWCR,TWINT));
}

/*=====================================================================================================================
 * [Function Name] : I2C_sendByte
 * [Description]   : Send a byte on the I2C bus.
 * [Arguments]     : <a_byte>   -> The required byte to be transmitted.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void I2C_sendByte(uint8 a_byte)
{
    TWDR = a_byte;
    TWCR = ((1 << TWINT) | (1 << TWEN));
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

/*=====================================================================================================================
 * [Function Name] : I2C_receiveByteWithACK
 * [Description]   : Receive a byte and send ACK to the slave on the I2C bus.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 I2C_receiveByteWithACK(void)
{
    TWCR = ((1 << TWINT) | (1 << TWEA) | (1 << TWEN));
    while(BIT_IS_CLEAR(TWCR,TWINT));
    return TWDR;
}

/*=====================================================================================================================
 * [Function Name] : I2C_receiveByteWithNACK
 * [Description]   : Receive a byte without sending ACK to the slave on the I2C bus.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 I2C_receiveByteWithNACK(void)
{
    TWCR = ((1 << TWINT) | (1 << TWEN));
    while(BIT_IS_CLEAR(TWCR,TWINT));
    return TWDR;
}

/*=====================================================================================================================
 * [Function Name] : I2C_sendStoptBit
 * [Description]   : Send the stop bit on the I2C bus.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void I2C_sendStoptBit(void)
{
    TWCR = ((1 << TWINT) | (1 << TWSTO) | (1 << TWEN));
}

/*=====================================================================================================================
 * [Function Name] : I2C_getStatus
 * [Description]   : Get the status of the I2C bus.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the I2C bus status.
 ====================================================================================================================*/
uint8 I2C_getStatus(void)
{
    return (TWSR & 0XF8);
}
