/*
=======================================================================================================================
Author       : Mamoun
Module       : I2C
File Name    : i2c.h
Date Created : Oct 30, 2023
Description  : Header file for the ATmega32 I2C driver.
=======================================================================================================================
*/


#ifndef MCAL_I2C_INCLUDES_I2C_H_
#define MCAL_I2C_INCLUDES_I2C_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#if((I2C_DEVICE_ADDRESS < I2C_MIN_SLAVE_ADDRESS) || (I2C_DEVICE_ADDRESS > I2C_MAX_SLAVE_ADDRESS))
#error "Invalid I2C device address, the I2C device address range is [1 - 127]"
#endif

#if((I2C_SCL_FREQUENCY < I2C_MIN_SCL_FREQUENCY) || (I2C_SCL_FREQUENCY > I2C_MAX_SCL_FREQUENCY))
#error "Invalid I2C SCL frequency, the SCL frequency range is [0 KHz - 400 KHz]"
#endif

/* Master Transmitter Status Codes. */
#define I2C_SLAVE_ADDRESS_WRITE_ACK                     (0X18)
#define I2C_SLAVE_ADDRESS_WRITE_NACK                    (0X20)
#define I2C_DATA_WRITE_ACK                              (0X28)
#define I2C_DATA_WRITE_NACK                             (0X30)

/* Master Receiver Status Codes. */
#define I2C_SLAVE_ADDRESS_READ_ACK                      (0X40)
#define I2C_SLAVE_ADDRESS_READ_NACK                     (0X48)
#define I2C_DATA_READ_ACK                               (0X50)
#define I2C_DATA_READ_NACK                              (0X58)

/* Common Status Codes. */
#define I2C_START_BIT_SENT                              (0X08)
#define I2C_REPEATED_START_BIT_SENT                     (0X10)
#define I2C_ARBITRATION_LOST                            (0X38)

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    I2C_NO_ERRORS,
    I2C_SLAVE_ADDRESS_ERROR,
    I2C_MESSAGE_DIRECTION_ERROR,
}I2C_errorStatus;

typedef enum
{
    I2C_MASTER_WRITE,
    I2C_MASTER_READ
}I2C_messageDirection;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : I2C_init
 * [Description]   : Initialize the I2C peripheral SCL frequency and set its slave address.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void I2C_init(void);

/*=====================================================================================================================
 * [Function Name] : I2C_sendStartBit
 * [Description]   : Send the start bit condition on the I2C bus.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void I2C_sendStartBit(void);

/*=====================================================================================================================
 * [Function Name] : I2C_sendAddress
 * [Description]   : Send the address of the required slave on the I2C bus.
 * [Arguments]     : <a_slaveAddress>   -> The address of the required slave.
 *                   <a_direction>      -> The message direction control bit [Read or Write].
 * [return]        : The function returns void
 ====================================================================================================================*/
void I2C_sendAddress(uint8 a_slaveAddress, I2C_messageDirection a_direction);

/*=====================================================================================================================
 * [Function Name] : I2C_sendByte
 * [Description]   : Send a byte on the I2C bus.
 * [Arguments]     : <a_byte>   -> The required byte to be transmitted.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void I2C_sendByte(uint8 a_byte);

/*=====================================================================================================================
 * [Function Name] : I2C_receiveByteWithACK
 * [Description]   : Receive a byte and send ACK to the slave on the I2C bus.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 I2C_receiveByteWithACK(void);

/*=====================================================================================================================
 * [Function Name] : I2C_receiveByteWithNACK
 * [Description]   : Receive a byte without sending ACK to the slave on the I2C bus.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 I2C_receiveByteWithNACK(void);

/*=====================================================================================================================
 * [Function Name] : I2C_sendStoptBit
 * [Description]   : Send the stop bit on the I2C bus.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void I2C_sendStoptBit(void);

/*=====================================================================================================================
 * [Function Name] : I2C_getStatus
 * [Description]   : Get the status of the I2C bus.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the I2C bus status.
 ====================================================================================================================*/
uint8 I2C_getStatus(void);

#endif /* MCAL_I2C_INCLUDES_I2C_H_ */
