/*
=======================================================================================================================
Author       : Mamoun
Module       : Extrenal EEPROM
File Name    : eeprom_prv.h
Date Created : Oct 30, 2023
Description  : Private file for the FM24C16 External EEPROM driver.
=======================================================================================================================
*/


#ifndef HAL_EEPROM_INCLUDES_EEPROM_PRV_H_
#define HAL_EEPROM_INCLUDES_EEPROM_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The minimum and the maximum memory address value for the FM24C16 EEPROM. */
#define EEPROM_MIN_MEMORY_ADDRESS                              (0UL)
#define EEPROM_MAX_MEMORY_ADDRESS                              (2047UL)

/* The FM24C16 EEPROM requires 10mS to perform the write. */
#define EEPROM_WRITE_TIME                                     (10)

/* EEPROM chunk terminator. */
#define EEPROM_CHUNK_TERMINATOR                                ';'

#endif /* HAL_EEPROM_INCLUDES_EEPROM_PRV_H_ */
