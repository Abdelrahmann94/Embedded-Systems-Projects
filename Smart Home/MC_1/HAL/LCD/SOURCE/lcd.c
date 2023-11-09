/*
=======================================================================================================================
Author       : Mamoun
Module       : LCD
File Name    : lcd.c
Date Created : Oct 21, 2023
Description  : Source file for the LCD driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../LIB/Include/std_types.h"
#include "../../../LIB/Include/common_macros.h"
#include "../../../MCAL/DIO/INCLUDES/dio.h"
#include "../INCLUDES/lcd_prv.h"
#include "../INCLUDES/lcd_cfg.h"
#include "../INCLUDES/lcd.h"
#include <util/delay.h>

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : LCD_init
 * [Description]   : Initialize the LCD by sending initialization command.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_init(void)
{
	#if(LCD_DATA_BIT_MODE == LCD_4_BIT_MODE)

	LCD_sendCommand(LCD_4_BIT_2_LINES_INIT1_COMMAND);
	LCD_sendCommand(LCD_4_BIT_2_LINES_INIT2_COMMAND);
	LCD_sendCommand(LCD_4_BIT_2_LINES_SET_COMMAND);

	#elif(LCD_DATA_BIT_MODE == LCD_8_BIT_MODE)

	LCD_sendCommand(LCD_8_BIT_2_LINES_SET_COMMAND);

	#endif

	LCD_sendCommand(LCD_CURSOR_OFF_COMMAND);
	LCD_sendCommand(LCD_CLEAR_SCREEN_COMMAND);
}

/*=====================================================================================================================
 * [Function Name] : LCD_sendCommand
 * [Description]   : Send a specific command to the LCD.
 * [Arguments]     : <a_command>      -> Indicates to the required command.
 * [return]        : The function returns void.
 ====================================================================================================================*/
static void LCD_sendCommand(uint8 a_command)
{
	DIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,DIO_LOW_PIN);
	_delay_ms(LCD_SETUP_TIME_DELAY);
	DIO_writePin(LCD_EN_PORT_ID,LCD_EN_PIN_ID,DIO_HIGH_PIN);
	_delay_ms(LCD_SETUP_TIME_DELAY);

	#if(LCD_DATA_BIT_MODE == LCD_4_BIT_MODE)

	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN4_ID,GET_BIT(a_command,4));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN5_ID,GET_BIT(a_command,5));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN6_ID,GET_BIT(a_command,6));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN7_ID,GET_BIT(a_command,7));

	_delay_ms(LCD_SETUP_TIME_DELAY);
	DIO_writePin(LCD_EN_PORT_ID,LCD_EN_PIN_ID,DIO_LOW_PIN);
	_delay_ms(LCD_SETUP_TIME_DELAY);
	DIO_writePin(LCD_EN_PORT_ID,LCD_EN_PIN_ID,DIO_HIGH_PIN);
	_delay_ms(LCD_SETUP_TIME_DELAY);

	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN4_ID,GET_BIT(a_command,0));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN5_ID,GET_BIT(a_command,1));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN6_ID,GET_BIT(a_command,2));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN7_ID,GET_BIT(a_command,3));

	#elif(LCD_DATA_BIT_MODE == LCD_8_BIT_MODE)

	DIO_writePort(LCD_DATA_PORT_ID,a_command);

	#endif

	_delay_ms(LCD_SETUP_TIME_DELAY);
	DIO_writePin(LCD_EN_PORT_ID,LCD_EN_PIN_ID,DIO_LOW_PIN);
	_delay_ms(LCD_SETUP_TIME_DELAY);
}

/*=====================================================================================================================
 * [Function Name] : LCD_sendData
 * [Description]   : Display a specific data on the LCD data lines.
 * [Arguments]     : <a_data>      -> Indicates to the required data.
 * [return]        : The function returns void.
 ====================================================================================================================*/
static void LCD_sendData(uint8 a_data)
{
	DIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,DIO_HIGH_PIN);
	_delay_ms(LCD_SETUP_TIME_DELAY);
	DIO_writePin(LCD_EN_PORT_ID,LCD_EN_PIN_ID,DIO_HIGH_PIN);
	_delay_ms(LCD_SETUP_TIME_DELAY);

	#if(LCD_DATA_BIT_MODE == LCD_4_BIT_MODE)

	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN4_ID,GET_BIT(a_data,4));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN5_ID,GET_BIT(a_data,5));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN6_ID,GET_BIT(a_data,6));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN7_ID,GET_BIT(a_data,7));

	_delay_ms(LCD_SETUP_TIME_DELAY);
	DIO_writePin(LCD_EN_PORT_ID,LCD_EN_PIN_ID,DIO_LOW_PIN);
	_delay_ms(LCD_SETUP_TIME_DELAY);
	DIO_writePin(LCD_EN_PORT_ID,LCD_EN_PIN_ID,DIO_HIGH_PIN);
	_delay_ms(LCD_SETUP_TIME_DELAY);

	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN4_ID,GET_BIT(a_data,0));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN5_ID,GET_BIT(a_data,1));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN6_ID,GET_BIT(a_data,2));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DATA_PIN7_ID,GET_BIT(a_data,3));

	#elif(LCD_DATA_BIT_MODE == LCD_8_BIT_MODE)

	DIO_writePort(LCD_DATA_PORT_ID,a_data);

	#endif

    _delay_ms(LCD_SETUP_TIME_DELAY);
    DIO_writePin(LCD_EN_PORT_ID,LCD_EN_PIN_ID,DIO_LOW_PIN);
	_delay_ms(LCD_SETUP_TIME_DELAY);
}

/*=====================================================================================================================
 * [Function Name] : LCD_moveCursor
 * [Description]   : Move the cursor to a specific position on the LCD.
 * [Arguments]     : <a_row>      -> Indicates to the row number of the required position.
 *                   <a_column>   -> Indicates to the column number of the required position.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_moveCursor(LCD_rowID a_row, LCD_columnID a_column)
{
	#if(LCD_NUM_OF_COLUMNS == LCD_16_COLUMNS)

	uint8 LOC_memoryAddress = LCD_16_COLUMNS_1ST_ROW_BASE_ADDRESS;

	switch (a_row)
	{
	case LCD_ROW_1_ID:
		LOC_memoryAddress = (LCD_16_COLUMNS_1ST_ROW_BASE_ADDRESS + a_column);
		break;

	case LCD_ROW_2_ID:
		LOC_memoryAddress = (LCD_16_COLUMNS_2ND_ROW_BASE_ADDRESS + a_column);
		break;

	case LCD_ROW_3_ID:
		LOC_memoryAddress = (LCD_16_COLUMNS_3RD_ROW_BASE_ADDRESS + a_column);
		break;

	case LCD_ROW_4_ID:
		LOC_memoryAddress = (LCD_16_COLUMNS_4TH_ROW_BASE_ADDRESS + a_column);
		break;

	default:
		LOC_memoryAddress = LCD_16_COLUMNS_1ST_ROW_BASE_ADDRESS;
		break;
	}

	#elif(LCD_NUM_OF_COLUMNS == LCD_20_COLUMNS)

	uint8 LOC_memoryAddress = LCD_20_COLUMNS_1ST_ROW_BASE_ADDRESS;

	switch (a_row)
	{
	case LCD_ROW_1_ID:
		LOC_memoryAddress = (LCD_20_COLUMNS_1ST_ROW_BASE_ADDRESS + a_column);
		break;

	case LCD_ROW_2_ID:
		LOC_memoryAddress = (LCD_20_COLUMNS_2ND_ROW_BASE_ADDRESS + a_column);
		break;

	case LCD_ROW_3_ID:
		LOC_memoryAddress = (LCD_20_COLUMNS_3RD_ROW_BASE_ADDRESS + a_column);
		break;

	case LCD_ROW_4_ID:
		LOC_memoryAddress = (LCD_20_COLUMNS_4TH_ROW_BASE_ADDRESS + a_column);
		break;

	default:
		LOC_memoryAddress = LCD_20_COLUMNS_1ST_ROW_BASE_ADDRESS;
		break;
	}

	#endif

	LCD_sendCommand(LCD_MOVE_CURSOR_COMMAND(LOC_memoryAddress));
}

/*=====================================================================================================================
 * [Function Name] : LCD_displayCharacter
 * [Description]   : Display a specific character on the LCD at the cursor position.
 * [Arguments]     : <a_charachter>      -> Indicates to the required character.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayCharacter(uint8 a_charachter)
{
	LCD_sendData(a_charachter);
}

/*=====================================================================================================================
 * [Function Name] : LCD_displayCharacterRowColumn
 * [Description]   : Display a specific character in a specific position on the LCD.
 * [Arguments]     : <a_charachter>  -> Indicates to the required character.
 *                   <a_row>         -> Indicates to the row number of the required position.
 *                   <a_column>      -> Indicates to the column number of the required position.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayCharacterRowColumn(uint8 a_charachter, uint8 a_row, uint8 a_column)
{
	LCD_moveCursor(a_row,a_column);
	LCD_sendData(a_charachter);
}

/*=====================================================================================================================
 * [Function Name] : LCD_displayString
 * [Description]   : Display a specific string on the LCD at the cursor position.
 * [Arguments]     : <a_ptr2string>      -> Pointer points to the required string.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayString(uint8* a_ptr2string)
{
	if(a_ptr2string != NULL_PTR)
	{
		for(uint8 counter = 0; *(a_ptr2string + counter) != '\0'; counter++)
		{
			LCD_displayCharacter(*(a_ptr2string + counter));
		}
	}
	else
	{
		/* Do Nothing. */
	}
}

/*=====================================================================================================================
 * [Function Name] : LCD_displayStringRowColumn
 * [Description]   : Display a specific string in a specific position on the LCD.
 * [Arguments]     : <a_ptr2string>  -> Pointer points to the required string.
 *                   <a_row>         -> Indicates to the row number of the required position.
 *                   <a_column>      -> Indicates to the column number of the required position.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayStringRowColumn(uint8* a_ptr2string, uint8 a_row, uint8 a_column)
{
	LCD_moveCursor(a_row,a_column);
	LCD_displayString(a_ptr2string);
}

/*=====================================================================================================================
 * [Function Name] : LCD_displayInteger
 * [Description]   : Convert a specific integer value to string and display it on the LCD.
 * [Arguments]     : <a_integerNumber>      -> Indicates to the required integer number.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayInteger(uint64 a_integerNumber)
{
	if(a_integerNumber == 0)
	{
		LCD_displayCharacter('0');
	}

	else
	{
		uint64 LOC_reversedNumber = 1;
		
		while(a_integerNumber != 0)
		{
			LOC_reversedNumber = (LOC_reversedNumber * 10) + (a_integerNumber % 10);
			a_integerNumber /= 10;
		}

		while(LOC_reversedNumber != 1)
		{
			LCD_displayCharacter((LOC_reversedNumber % 10) + '0');
			LOC_reversedNumber /= 10;
		}
	}
}

/*=====================================================================================================================
 * [Function Name] : 
 * [Description]   : 
 * [Arguments]     : <>      -> 
 *                   <>      -> 
 * [return]        : The function returns void.
 ====================================================================================================================*/
 /* void LCD_displayFloat(float32 a_floatNumber){} */

/*=====================================================================================================================
 * [Function Name] : LCD_displayHEX
 * [Description]   : Convert a specific decimal byte to HEX and display this HEX on the LCD.
 * [Arguments]     : <a_decimalNumber>      -> Indicates to the decimal byte.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_displayHEX(uint8 a_decimalNumber)
{
	uint8 LOC_byteNIB = GET_H_NIB(a_decimalNumber);

	if(LOC_byteNIB > 9)
	{
		LCD_displayCharacter('A' + (LOC_byteNIB % 10));
	}

	else
	{
		LCD_displayCharacter('0' + LOC_byteNIB);
	}

	LOC_byteNIB = GET_L_NIB(a_decimalNumber);

	if(LOC_byteNIB > 9)
	{
		LCD_displayCharacter('A' + (LOC_byteNIB % 10));
	}

	else
	{
		LCD_displayCharacter('0' + LOC_byteNIB);
	}
}

/*=====================================================================================================================
 * [Function Name] : LCD_createCustomCharacter
 * [Description]   : Create a custom character and store it in the LCD CGRAM.
 * [Arguments]     : <a_ptr2map>      -> Pointer to the array that holds the character map.
 *                   <a_index>        -> Indicates to the index number in the CGRAM to store the character in.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_createCustomCharacter(uint8* a_ptr2map, uint8 a_index)
{
	uint8 LOC_addressCGRAM = (LCD_CGRAM_BASE_ADDRESS + (a_index * LCD_SPECIAL_PATTERN_NUM_OF_ROWS));

	LCD_sendCommand(LOC_addressCGRAM);

	for(uint8 iterator = 0; iterator < LCD_SPECIAL_PATTERN_NUM_OF_ROWS; iterator++)
	{
		LCD_sendData(*(a_ptr2map + iterator));
	}

	LCD_sendCommand(LCD_DDRAM_BASE_ADDRESS);
}

/*=====================================================================================================================
 * [Function Name] : LCD_clearScreen
 * [Description]   : Clear the LCD screen.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_SCREEN_COMMAND);
}

/*=====================================================================================================================
 * [Function Name] : LCD_clearScreen
 * [Description]   : Return to the first column in the first row on the LCD screen.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void LCD_returnHome(void)
{
	LCD_sendCommand(LCD_RETURN_HOME_COMMAND);
}
