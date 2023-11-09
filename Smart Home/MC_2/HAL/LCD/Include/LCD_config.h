/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 21 Oct 2023                                                           */
/************************************************************************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* Macros for configuration mode 8_Bit or 4_Bit */
/*      Options: LCD_u8_MODE_8_BIT
                 LCD_u8_MODE_4_BIT              */
#define LCD_u8_MODE       LCD_u8_MODE_4_BIT

/* macros for LCD Control Port and Data Port    */
/*      Options: DIO_u8_PORTA
                 DIO_u8_PORTB
                 DIO_u8_PORTC
                 DIO_u8_PORTD                   */
#define LCD_u8_CONTROL_PORT        DIO_u8_PORTB
#define LCD_u8_DATA_PORT           DIO_u8_PORTC

/* macros for LCD Control Pins                 */
/*      Options: DIO_u8_PIN0
                 DIO_u8_PIN1
                 DIO_u8_PIN2
                 DIO_u8_PIN3
                 DIO_u8_PIN4
                 DIO_u8_PIN5
                 DIO_u8_PIN6
                 DIO_u8_PIN7                   */
#define LCD_u8_RS_PIN              DIO_u8_PIN0
#define LCD_u8_RW_PIN              DIO_u8_PIN2
#define LCD_u8_EN_PIN              DIO_u8_PIN1

#endif
