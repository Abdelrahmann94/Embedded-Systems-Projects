/*
=======================================================================================================================
Author       : Mamoun
Module       : LCD
File Name    : lcd_prv.h
Date Created : Oct 21, 2023
Description  : Private file for the LCD driver.
=======================================================================================================================
*/


#ifndef HAL_LCD_INCLUDES_LCD_PRV_H_
#define HAL_LCD_INCLUDES_LCD_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* LCD data bit modes: [8-bit or 4-bit]. */
#define LCD_4_BIT_MODE                                 (4U)
#define LCD_8_BIT_MODE                                 (8U)

/* LCD column sizes: [16 or 20]. */
#define LCD_16_COLUMNS                                 (16U)
#define LCD_20_COLUMNS                                 (20U)

/* The base address of every row in the LCD [16 or 20 columns size]. */
#define LCD_16_COLUMNS_1ST_ROW_BASE_ADDRESS            (0X00)
#define LCD_16_COLUMNS_2ND_ROW_BASE_ADDRESS            (0X40)
#define LCD_16_COLUMNS_3RD_ROW_BASE_ADDRESS            (0X10)
#define LCD_16_COLUMNS_4TH_ROW_BASE_ADDRESS            (0X50)
#define LCD_20_COLUMNS_1ST_ROW_BASE_ADDRESS            (0X00)
#define LCD_20_COLUMNS_2ND_ROW_BASE_ADDRESS            (0X40)
#define LCD_20_COLUMNS_3RD_ROW_BASE_ADDRESS            (0X14)
#define LCD_20_COLUMNS_4TH_ROW_BASE_ADDRESS            (0X54)

/* The most common command for LCD. */
#define LCD_4_BIT_1_LINE_SET_COMMAND                   (0X20)
#define LCD_4_BIT_2_LINES_INIT1_COMMAND                (0X33)
#define LCD_4_BIT_2_LINES_INIT2_COMMAND                (0X32)
#define LCD_4_BIT_2_LINES_SET_COMMAND                  (0X28)
#define LCD_8_BIT_1_LINE_SET_COMMAND                   (0X30)
#define LCD_8_BIT_2_LINES_SET_COMMAND                  (0X38)
#define LCD_CLEAR_SCREEN_COMMAND                       (0X01)
#define LCD_RETURN_HOME_COMMAND                        (0X02)
#define LCD_CURSOR_OFF_COMMAND                         (0X0C)

/* Minimum time delay used in LCD set-up. */
#define LCD_SETUP_TIME_DELAY                           (1U)

/* The number of rows in the created special pattern [5x8 pattern]. */
#define LCD_SPECIAL_PATTERN_NUM_OF_ROWS                (8U)

/* The base address of CGRAM and DDRAM in the LCD. */
#define LCD_CGRAM_BASE_ADDRESS                         (0X40)
#define LCD_DDRAM_BASE_ADDRESS                         (0X80)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

#define LCD_MOVE_CURSOR_COMMAND(ADDRESS)               ((ADDRESS & 0X7F) | (0X80))

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : LCD_sendCommand
 * [Description]   : Send a specific command to the LCD.
 * [Arguments]     : <a_command>      -> Indicates to the required command.
 * [return]        : The function returns void.
 ====================================================================================================================*/
static void LCD_sendCommand(uint8 a_command);

/*=====================================================================================================================
 * [Function Name] : LCD_sendData
 * [Description]   : Display a specific data on the LCD data lines.
 * [Arguments]     : <a_data>      -> Indicates to the required data.
 * [return]        : The function returns void.
 ====================================================================================================================*/
static void LCD_sendData(uint8 a_data);

#endif /* HAL_LCD_INCLUDES_LCD_PRV_H_ */
