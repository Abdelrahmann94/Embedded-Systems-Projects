/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 21 Oct 2023                                                           */
/************************************************************************************/
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H
/* DDRAM address */
#define LCD_u8_ADRESS        0x80

/* macros for configuration of the mode */
#define LCD_u8_MODE_8_BIT        0
#define LCD_u8_MODE_4_BIT        1

/* macros for LCD commands */
#define LCD_u8_CURSOR_HOME                 0x02
#define LCD_u8_4B_Mode                     0x28
#define LCD_u8_8B_Mode                     0x38
#define LCD_u8_ENTRY_Mode                  0x06
#define LCD_u8_DISPLAY_CLEAR               0x01
#define LCD_u8_DISPLAY_CURSOR_ON           0x0C



#endif
