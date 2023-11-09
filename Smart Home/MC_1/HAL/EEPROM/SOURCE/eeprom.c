/*
=======================================================================================================================
Author       : Mamoun
Module       : Extrenal EEPROM
File Name    : eeprom.c
Date Created : Oct 30, 2023
Description  : Source file for the FM24C16 External EEPROM driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../LIB/Include/std_types.h"
#include "../../../LIB/Include/common_macros.h"
#include "../../../MCAL/I2C/INCLUDES/i2c.h"
#include "../INCLUDES/eeprom_prv.h"
#include "../INCLUDES/eeprom_cgf.h"
#include "../INCLUDES/eeprom.h"
#include <util/delay.h>

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : EEPROM_writeByte
 * [Description]   : Write a byte in a specific address on the EEPROM.
 * [Arguments]     : <a_address>    -> Indicates to the required address to write the byte.
 *                   <a_byte>       -> Indicates to the required byte to be written.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Address Error.
 ====================================================================================================================*/
EEPROM_errorStatus EEPROM_writeByte(uint16 a_address, uint8 a_byte)
{
    EEPROM_errorStatus LOC_errorStatus = EEPROM_NO_ERRORS;

    if(a_address > EEPROM_MAX_MEMORY_ADDRESS)
    {
        LOC_errorStatus = EEPROM_ADDRESS_ERROR;
    }

    else
    {
    	uint8 LOC_slaveAddress = (((a_address & 0X0700) | (0X5000)) >> 8);
        uint8 LOC_memoryAddress = ((uint8)a_address);

        I2C_sendStartBit();
        if(I2C_getStatus() != I2C_START_BIT_SENT)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendAddress(LOC_slaveAddress,I2C_MASTER_WRITE);
        if(I2C_getStatus() != I2C_SLAVE_ADDRESS_WRITE_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendByte(LOC_memoryAddress);
        if(I2C_getStatus() != I2C_DATA_WRITE_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }
        
        I2C_sendByte(a_byte);
        if(I2C_getStatus() != I2C_DATA_WRITE_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendStoptBit();
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : EEPROM_readByte
 * [Description]   : Write a byte from a specific address on the EEPROM.
 * [Arguments]     : <a_address>       -> Indicates to the required address to read from.
 *                   <a_ptr2byte>      -> Pointer to variable to store the byte.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Address Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
EEPROM_errorStatus EEPROM_readByte(uint16 a_address, uint8* a_ptr2byte)
{
    EEPROM_errorStatus LOC_errorStatus = EEPROM_NO_ERRORS;

    if(a_ptr2byte == NULL_PTR)
    {
        LOC_errorStatus = EEPROM_NULL_PTR_ERROR;
    }

    else if(a_address > EEPROM_MAX_MEMORY_ADDRESS)
    {
        LOC_errorStatus = EEPROM_ADDRESS_ERROR;
    }

    else
    {
    	uint8 LOC_slaveAddress = (((a_address & 0X0700) | (0X5000)) >> 8);
    	uint8 LOC_memoryAddress = ((uint8)a_address);

        I2C_sendStartBit();
        if(I2C_getStatus() != I2C_START_BIT_SENT)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendAddress(LOC_slaveAddress,I2C_MASTER_WRITE);
        if(I2C_getStatus() != I2C_SLAVE_ADDRESS_WRITE_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendByte(LOC_memoryAddress);
        if(I2C_getStatus() != I2C_DATA_WRITE_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendStartBit();
        if(I2C_getStatus() != I2C_REPEATED_START_BIT_SENT)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendAddress(LOC_slaveAddress,I2C_MASTER_READ);
        if(I2C_getStatus() != I2C_SLAVE_ADDRESS_READ_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }
        
        *a_ptr2byte = I2C_receiveByteWithNACK();

        I2C_sendStoptBit();
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : EEPROM_writeChunk
 * [Description]   : Write a contiguous chunk at a specific base address on the EEPROM.
 * [Arguments]     : <a_address>     -> Indicates to the chaunk base address.
 *                   <a_ptr2data>    -> Pointer to the required array to be written.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Address Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
EEPROM_errorStatus EEPROM_writeChunk(uint16 a_address, uint8* a_ptr2data)
{
    EEPROM_errorStatus LOC_errorStatus = EEPROM_NO_ERRORS;

    if(a_ptr2data == NULL_PTR)
    {
        LOC_errorStatus = EEPROM_NULL_PTR_ERROR;
    }

    else if((a_address < EEPROM_MIN_MEMORY_ADDRESS) || (a_address > EEPROM_MAX_MEMORY_ADDRESS))
    {
        LOC_errorStatus = EEPROM_ADDRESS_ERROR;
    }

    else
    {
    	uint8 LOC_slaveAddress = (((a_address & 0X0700) | (0X5000)) >> 8);
    	uint8 LOC_memoryAddress = ((uint8)a_address);

        I2C_sendStartBit();
        if(I2C_getStatus() != I2C_START_BIT_SENT)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendAddress(LOC_slaveAddress,I2C_MASTER_WRITE);
        if(I2C_getStatus() != I2C_SLAVE_ADDRESS_WRITE_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendByte(LOC_memoryAddress);
        if(I2C_getStatus() != I2C_DATA_WRITE_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }
        
        for(uint8 iterator = 0; *(a_ptr2data + iterator) != '\0'; iterator++)
        {
            I2C_sendByte(*(a_ptr2data + iterator));
            if(I2C_getStatus() != I2C_DATA_WRITE_ACK)
            {
                LOC_errorStatus = EEPROM_FRAME_ERROR;
                break;
            }

            _delay_ms(EEPROM_WRITE_TIME);
        }

        I2C_sendByte(EEPROM_CHUNK_TERMINATOR);
        if(I2C_getStatus() != I2C_DATA_WRITE_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendStoptBit();
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : EEPROM_readChunk
 * [Description]   : Read a contiguous chunk from a specific base address on the EEPROM.
 * [Arguments]     : <a_address>       -> Indicates to the chaunk base address.
 *                   <a_ptr2buffer>    -> Pointer to array to store the chunk.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Address Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
EEPROM_errorStatus EEPROM_readChunk(uint16 a_address, uint8* a_ptr2buffer)
{
    EEPROM_errorStatus LOC_errorStatus = EEPROM_NO_ERRORS;
    uint8 LOC_receivedByte = EEPROM_CHUNK_TERMINATOR;
    uint8 LOC_byteCounter = 0;

    if(a_ptr2buffer == NULL_PTR)
    {
        LOC_errorStatus = EEPROM_NULL_PTR_ERROR;
    }

    else if((a_address < EEPROM_MIN_MEMORY_ADDRESS) || (a_address > EEPROM_MAX_MEMORY_ADDRESS))
    {
        LOC_errorStatus = EEPROM_ADDRESS_ERROR;
    }

    else
    {
    	uint8 LOC_slaveAddress = (((a_address & 0X0700) | (0X5000)) >> 8);
    	uint8 LOC_memoryAddress = ((uint8)a_address);

        I2C_sendStartBit();
        if(I2C_getStatus() != I2C_START_BIT_SENT)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendAddress(LOC_slaveAddress,I2C_MASTER_WRITE);
        if(I2C_getStatus() != I2C_SLAVE_ADDRESS_WRITE_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendByte(LOC_memoryAddress);
        if(I2C_getStatus() != I2C_DATA_WRITE_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendStartBit();
        if(I2C_getStatus() != I2C_REPEATED_START_BIT_SENT)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }

        I2C_sendAddress(LOC_slaveAddress,I2C_MASTER_READ);
        if(I2C_getStatus() != I2C_SLAVE_ADDRESS_READ_ACK)
        {
            LOC_errorStatus = EEPROM_FRAME_ERROR;
        }
        
        LOC_receivedByte = I2C_receiveByteWithACK();

        while(LOC_receivedByte != EEPROM_CHUNK_TERMINATOR)
        {
            *(a_ptr2buffer + LOC_byteCounter) = LOC_receivedByte;
            LOC_byteCounter++;

            LOC_receivedByte = I2C_receiveByteWithACK();
        }

        *(a_ptr2buffer + LOC_byteCounter) = '\0';
        I2C_receiveByteWithNACK();

        I2C_sendStoptBit();
    }

    return LOC_errorStatus;
}
