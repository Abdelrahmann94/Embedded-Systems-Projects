/*
=======================================================================================================================
Author       : Mamoun
Module       : Keypad
File Name    : keypad.h
Date Created : Oct 23, 2023
Description  : Header file for the keypad driver.
=======================================================================================================================
*/


#ifndef HAL_KEYPAD_INCLUDES_KEYPAD_H_
#define HAL_KEYPAD_INCLUDES_KEYPAD_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#if((KEYPAD_NUM_OF_COLUMNS != KEYPAD_3_COLUMNS_SIZE) && (KEYPAD_NUM_OF_COLUMNS != KEYPAD_4_COLUMNS_SIZE))
#error "Invalid keypad size, The keypad has only two column sizes: 3-columns and 4-columns."
#endif

#if((KEYPAD_CONNECTION_TYPE != KEYPAD_PULLUP_CONNECTION) && (KEYPAD_CONNECTION_TYPE != KEYPAD_PULLDOWN_CONNECTION))
#error "Invalid keypad connection type, The keypad has only two connection types: Pull-up and Pull-down."
#endif

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

#if(KEYPAD_CONNECTION_TYPE == KEYPAD_PULLUP_CONNECTION)

typedef enum
{
    KEYPAD_PRESSED,
    KEYPAD_NOT_PRESSED
}KEYPAD_buttonStatus;

#elif(KEYPAD_CONNECTION_TYPE == KEYPAD_PULLDOWN_CONNECTION)

typedef enum
{
    KEYPAD_NOT_PRESSED,
    KEYPAD_PRESSED
}KEYPAD_buttonStatus;

#endif

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : KEYPAD_getPressedKey
 * [Description]   : Scan the keypad matrix and return the pressed key value.
 * [Arguments]     : <a_ptr2keyValue>      -> Pointer to variable to store the pressed key value.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void KEYPAD_getPressedKey(uint8* a_ptr2keyValue);

#endif /* HAL_KEYPAD_INCLUDES_KEYPAD_H_ */
