/*
=======================================================================================================================
Author       : Mamoun
Module       : Keypad
File Name    : keypad_cfg.h
Date Created : Oct 23, 2023
Description  : Configuration file for the keypad driver.
=======================================================================================================================
*/


#ifndef HAL_KEYPAD_INCLUDES_KEYPAD_CFG_H_
#define HAL_KEYPAD_INCLUDES_KEYPAD_CFG_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The keypad only has two column sizes: [KEYPAD_3_COLUMNS_SIZE - KEYPAD_4_COLUMNS_SIZE]. */
#define KEYPAD_NUM_OF_COLUMNS                              (KEYPAD_4_COLUMNS_SIZE)

/* The keypad only has two connection types: [KEYPAD_PULLUP_CONNECTION - KEYPAD_PULLDOWN_CONNECTION]. */
#define KEYPAD_CONNECTION_TYPE                             (KEYPAD_PULLUP_CONNECTION)

/* Keypad rows port and pin IDs. */
#define KEYPAD_ROWS_PORT_ID                                (DIO_PORTB_ID)
#define KEYPAD_ROW0_PIN_ID                                 (DIO_PIN0_ID)
#define KEYPAD_ROW1_PIN_ID                                 (DIO_PIN1_ID)
#define KEYPAD_ROW2_PIN_ID                                 (DIO_PIN2_ID)
#define KEYPAD_ROW3_PIN_ID                                 (DIO_PIN3_ID)

/* Keypad columns port and pin IDs. */
#define KEYPAD_COLS_PORT_ID                                (DIO_PORTC_ID)
#define KEYPAD_COL0_PIN_ID                                 (DIO_PIN4_ID)
#define KEYPAD_COL1_PIN_ID                                 (DIO_PIN5_ID)
#define KEYPAD_COL2_PIN_ID                                 (DIO_PIN6_ID)

/* Incase the keypad is a 4 columns size, define the 3rd column pin ID. */
#if(KEYPAD_NUM_OF_COLUMNS == KEYPAD_4_COLUMNS_SIZE)
#define KEYPAD_COL3_PIN_ID                                 (DIO_PIN7_ID)
#endif

/* Keypad sympols: */
#define KEYPAD_ROW0_COL0_SYMPOL                            '7'
#define KEYPAD_ROW0_COL1_SYMPOL                            '8'
#define KEYPAD_ROW0_COL2_SYMPOL                            '9'
#define KEYPAD_ROW0_COL3_SYMPOL                            'A' /* Not used in 3-columns size. */
#define KEYPAD_ROW1_COL0_SYMPOL                            '4'
#define KEYPAD_ROW1_COL1_SYMPOL                            '5'
#define KEYPAD_ROW1_COL2_SYMPOL                            '6'
#define KEYPAD_ROW1_COL3_SYMPOL                            'B' /* Not used in 3-columns size. */
#define KEYPAD_ROW2_COL0_SYMPOL                            '1'
#define KEYPAD_ROW2_COL1_SYMPOL                            '2'
#define KEYPAD_ROW2_COL2_SYMPOL                            '3'
#define KEYPAD_ROW2_COL3_SYMPOL                            'C' /* Not used in 3-columns size. */
#define KEYPAD_ROW3_COL0_SYMPOL                            '*'
#define KEYPAD_ROW3_COL1_SYMPOL                            '0'
#define KEYPAD_ROW3_COL2_SYMPOL                            '#'
#define KEYPAD_ROW3_COL3_SYMPOL                            'D' /* Not used in 3-columns size. */

#endif /* HAL_KEYPAD_INCLUDES_KEYPAD_CFG_H_ */
