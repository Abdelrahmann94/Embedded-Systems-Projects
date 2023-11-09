/*
=======================================================================================================================
Author       : Mamoun
Module       : Extrenal EEPROM
File Name    : eeprom.h
Date Created : Oct 30, 2023
Description  : Header file for the FM24C16 External EEPROM driver.
=======================================================================================================================
*/


#ifndef HAL_EEPROM_INCLUDES_EEPROM_H_
#define HAL_EEPROM_INCLUDES_EEPROM_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    EEPROM_NO_ERRORS,
    EEPROM_ADDRESS_ERROR,
    EEPROM_FRAME_ERROR,
    EEPROM_NULL_PTR_ERROR
}EEPROM_errorStatus;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : EEPROM_writeByte
 * [Description]   : Write a byte in a specific address on the EEPROM.
 * [Arguments]     : <a_address>    -> Indicates to the required address to write the byte.
 *                   <a_byte>       -> Indicates to the required byte to be written.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Address Error.
 ====================================================================================================================*/
EEPROM_errorStatus EEPROM_writeByte(uint16 a_address, uint8 a_byte);

/*=====================================================================================================================
 * [Function Name] : EEPROM_readByte
 * [Description]   : Write a byte from a specific address on the EEPROM.
 * [Arguments]     : <a_address>       -> Indicates to the required address to read from.
 *                   <a_ptr2byte>      -> Pointer to variable to store the byte.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Address Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
EEPROM_errorStatus EEPROM_readByte(uint16 a_address, uint8* a_ptr2byte);

/*=====================================================================================================================
 * [Function Name] : EEPROM_writeChunk
 * [Description]   : Write a contiguous chunk at a specific base address on the EEPROM.
 * [Arguments]     : <a_address>     -> Indicates to the chaunk base address.
 *                   <a_ptr2data>    -> Pointer to the required array to be written.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Address Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
EEPROM_errorStatus EEPROM_writeChunk(uint16 a_address, uint8* a_ptr2data);

/*=====================================================================================================================
 * [Function Name] : EEPROM_readChunk
 * [Description]   : Read a contiguous chunk from a specific base address on the EEPROM.
 * [Arguments]     : <a_address>       -> Indicates to the chaunk base address.
 *                   <a_ptr2buffer>    -> Pointer to array to store the chunk.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Address Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
EEPROM_errorStatus EEPROM_readChunk(uint16 a_address, uint8* a_ptr2buffer);

#endif /* HAL_EEPROM_INCLUDES_EEPROM_H_ */
