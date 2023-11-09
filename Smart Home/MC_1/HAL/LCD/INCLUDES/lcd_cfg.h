/*
=======================================================================================================================
Author       : Mamoun
Module       : LCD
File Name    : lcd_cfg.h
Date Created : Oct 21, 2023
Description  : Configuration file for the LCD driver.
=======================================================================================================================
*/


#ifndef HAL_LCD_INCLUDES_LCD_CFG_H_
#define HAL_LCD_INCLUDES_LCD_CFG_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The LCD only has two modes: [LCD_4_BIT_MODE - LCD_8_BIT_MODE]. */
#define LCD_DATA_BIT_MODE                                (LCD_4_BIT_MODE)

/* The LCD only has two column sizes: [LCD_16_COLUMNS - LCD_20_COLUMNS]. */
#define LCD_NUM_OF_COLUMNS                               (LCD_20_COLUMNS)

/* LCD RS port and pin IDs. */
#define LCD_RS_PORT_ID                                   (DIO_PORTA_ID)
#define LCD_RS_PIN_ID                                    (DIO_PIN0_ID)

/* LCD EN port and pin IDs. */
#define LCD_EN_PORT_ID                                   (DIO_PORTA_ID)
#define LCD_EN_PIN_ID                                    (DIO_PIN1_ID)

/* LCD data port and pin IDs. */
#define LCD_DATA_PORT_ID                                 (DIO_PORTA_ID)

/* Incase the LCD works in 4-bit mode, define the 4 data pins. */
#if(LCD_DATA_BIT_MODE == LCD_4_BIT_MODE)
#define LCD_DATA_PIN4_ID                                 (DIO_PIN4_ID)
#define LCD_DATA_PIN5_ID                                 (DIO_PIN5_ID)
#define LCD_DATA_PIN6_ID                                 (DIO_PIN6_ID)
#define LCD_DATA_PIN7_ID                                 (DIO_PIN7_ID)
#endif

#endif /* HAL_LCD_INCLUDES_LCD_CFG_H_ */
