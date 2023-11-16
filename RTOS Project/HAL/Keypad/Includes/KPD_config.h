/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 21 Oct 2023                                                           */
/************************************************************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

/* configure row pins */
#define KEYPAD_PIN_ROW_0                        DIO_u8CHANNEL16  
#define KEYPAD_PIN_ROW_1                        DIO_u8CHANNEL17  
#define KEYPAD_PIN_ROW_2                        DIO_u8CHANNEL18  
#define KEYPAD_PIN_ROW_3                        DIO_u8CHANNEL19  

/* configure column pins */
#define KEYPAD_PIN_COL_0                        DIO_u8CHANNEL24  
#define KEYPAD_PIN_COL_1                        DIO_u8CHANNEL25 
#define KEYPAD_PIN_COL_2                        DIO_u8CHANNEL26  
#define KEYPAD_PIN_COL_3                        DIO_u8CHANNEL27 

/* configure each button symbol */
#define KEYPAD_KEY_1_SYMBOL                     '7'
#define KEYPAD_KEY_2_SYMBOL                     '8'
#define KEYPAD_KEY_3_SYMBOL                     '9'
#define KEYPAD_KEY_4_SYMBOL                     '/'

#define KEYPAD_KEY_5_SYMBOL                     '4'
#define KEYPAD_KEY_6_SYMBOL                     '5'
#define KEYPAD_KEY_7_SYMBOL                     '6'
#define KEYPAD_KEY_8_SYMBOL                     '*'

#define KEYPAD_KEY_9_SYMBOL                     '1'
#define KEYPAD_KEY_10_SYMBOL                    '2'
#define KEYPAD_KEY_11_SYMBOL                    '3'
#define KEYPAD_KEY_12_SYMBOL                    '-'

#define KEYPAD_KEY_13_SYMBOL                    'c'
#define KEYPAD_KEY_14_SYMBOL                    '0'
#define KEYPAD_KEY_15_SYMBOL                    '='
#define KEYPAD_KEY_16_SYMBOL                    '+'

#endif
