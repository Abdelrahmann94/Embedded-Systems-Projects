/*
=======================================================================================================================
Author       : Mamoun
Module       : LCD
File Name    : lcd.h
Date Created : Oct 21, 2023
Description  : Header file for the LCD driver.
=======================================================================================================================
*/


#ifndef HAL_LCD_INCLUDES_LCD_H_
#define HAL_LCD_INCLUDES_LCD_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#if((LCD_DATA_BIT_MODE != LCD_4_BIT_MODE) && (LCD_DATA_BIT_MODE != LCD_8_BIT_MODE))
#error "Invalid LCD data bit mode, The LCD has only two modes: 8-bits and 4-bits."
#endif

#if ((LCD_NUM_OF_COLUMNS != LCD_16_COLUMNS) && (LCD_NUM_OF_COLUMNS != LCD_20_COLUMNS))
#error "Invalid LCD size, The LCD has only two column sizes: 16-columns and 20-columns."
#endif

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    LCD_ROW_1_ID,
    LCD_ROW_2_ID,
    LCD_ROW_3_ID,
    LCD_ROW_4_ID
}LCD_rowID;

typedef enum
{
    LCD_COLUMN_01_ID,
    LCD_COLUMN_02_ID,
    LCD_COLUMN_03_ID,
    LCD_COLUMN_04_ID,
    LCD_COLUMN_05_ID,
    LCD_COLUMN_06_ID,
    LCD_COLUMN_07_ID,
    LCD_COLUMN_08_ID,
    LCD_COLUMN_09_ID,
    LCD_COLUMN_10_ID,
    LCD_COLUMN_11_ID,
    LCD_COLUMN_12_ID,
    LCD_COLUMN_13_ID,
    LCD_COLUMN_14_ID,
    LCD_COLUMN_15_ID,
    LCD_COLUMN_16_ID,
    LCD_COLUMN_17_ID,
    LCD_COLUMN_18_ID,
    LCD_COLUMN_19_ID,
    LCD_COLUMN_20_ID
}LCD_columnID;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : LCD_init
 * [Description]   : Initialize the LCD by sending initialization command.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_init(void);

/*=====================================================================================================================
 * [Function Name] : LCD_moveCursor
 * [Description]   : Move the cursor to a specific position on the LCD.
 * [Arguments]     : <a_row>      -> Indicates to the row number of the required position.
 *                   <a_column>   -> Indicates to the column number of the required position.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_moveCursor(LCD_rowID a_row, LCD_columnID a_column);

/*=====================================================================================================================
 * [Function Name] : LCD_displayCharacter
 * [Description]   : Display a specific character on the LCD at the cursor position.
 * [Arguments]     : <a_charachter>      -> Indicates to the required character.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayCharacter(uint8 a_charachter);

/*=====================================================================================================================
 * [Function Name] : LCD_displayCharacterRowColumn
 * [Description]   : Display a specific character in a specific position on the LCD.
 * [Arguments]     : <a_charachter>  -> Indicates to the required character.
 *                   <a_row>         -> Indicates to the row number of the required position.
 *                   <a_column>      -> Indicates to the column number of the required position.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayCharacterRowColumn(uint8 a_charachter, uint8 a_row, uint8 a_column);

/*=====================================================================================================================
 * [Function Name] : LCD_displayString
 * [Description]   : Display a specific string on the LCD at the cursor position.
 * [Arguments]     : <a_ptr2string>      -> Pointer points to the required string.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayString(uint8* a_ptr2string);

/*=====================================================================================================================
 * [Function Name] : LCD_displayStringRowColumn
 * [Description]   : Display a specific string in a specific position on the LCD.
 * [Arguments]     : <a_ptr2string>  -> Pointer points to the required string.
 *                   <a_row>         -> Indicates to the row number of the required position.
 *                   <a_column>      -> Indicates to the column number of the required position.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayStringRowColumn(uint8* a_ptr2string, uint8 a_row, uint8 a_column);

/*=====================================================================================================================
 * [Function Name] : LCD_displayInteger
 * [Description]   : Convert a specific integer value to string and display it on the LCD.
 * [Arguments]     : <a_integerNumber>      -> Indicates to the required integer number.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayInteger(uint64 a_integerNumber);

/*=====================================================================================================================
 * [Function Name] : LCD_displayHEX
 * [Description]   : Convert a specific decimal byte to HEX and display this HEX on the LCD.
 * [Arguments]     : <a_decimalNumber>      -> Indicates to the decimal byte.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayHEX(uint8 a_decimalNumber);

/*=====================================================================================================================
 * [Function Name] : LCD_createCustomCharacter
 * [Description]   : Create a custom character and store it in the LCD CGRAM.
 * [Arguments]     : <a_ptr2map>      -> Pointer to the array that holds the character map.
 *                   <a_index>        -> Indicates to the index number in the CGRAM to store the character in.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_createCustomCharacter(uint8* a_ptr2map, uint8 a_index);

/*=====================================================================================================================
 * [Function Name] : LCD_clearScreen
 * [Description]   : Clear the LCD screen.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_clearScreen(void);

/*=====================================================================================================================
 * [Function Name] : LCD_clearScreen
 * [Description]   : Return to the first column in the first row on the LCD screen.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_returnHome(void);

#endif /* HAL_LCD_INCLUDES_LCD_H_ */
