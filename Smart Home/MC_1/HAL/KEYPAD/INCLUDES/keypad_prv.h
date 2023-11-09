/*
=======================================================================================================================
Author       : Mamoun
Module       : Keypad
File Name    : keypad_prv.h
Date Created : Oct 23, 2023
Description  : Private file for the keypad driver.
=======================================================================================================================
*/


#ifndef HAL_KEYPAD_INCLUDES_KEYPAD_PRV_H_
#define HAL_KEYPAD_INCLUDES_KEYPAD_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The keypad only has one row size. */
#define KEYPAD_NUM_OF_ROWS                                 (4U)

/* Keypad column sizes: [3 or 4]. */
#define KEYPAD_3_COLUMNS_SIZE                              (3U)
#define KEYPAD_4_COLUMNS_SIZE                              (4U)

/* Keypad connection types: [Pull-up or Pull-down]. */
#define KEYPAD_PULLUP_CONNECTION                           (0U)
#define KEYPAD_PULLDOWN_CONNECTION                         (1U)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

#define KEYPAD_CREATE_PATTERN_PULLUP(INDEX)   (~((0X01) << INDEX))
#define KEYPAD_CREATE_PATTERN_PULLDOWN(INDEX)  (((0X01) << INDEX))

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

static void KEYPAD_writeRowsPattern(uint8 a_index);

#endif /* HAL_KEYPAD_INCLUDES_KEYPAD_PRV_H_ */
