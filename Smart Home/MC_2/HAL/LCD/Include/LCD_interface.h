/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 21 Oct 2023                                                           */
/************************************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/* Macros for Row */
#define LCD_u8_ROW1         0x00
#define LCD_u8_ROW2         0x40
#define LCD_u8_ROW3         0x14
#define LCD_u8_ROW4         0x54        

/* Macros for Col */
#define LCD_u8_COL0         0x00
#define LCD_u8_COL1         0x01
#define LCD_u8_COL2         0x02
#define LCD_u8_COL3         0x03
#define LCD_u8_COL4         0x04
#define LCD_u8_COL5         0x05
#define LCD_u8_COL6         0x06
#define LCD_u8_COL7         0x07
#define LCD_u8_COL8         0x08
#define LCD_u8_COL9         0x09
#define LCD_u8_COL10        0x0A
#define LCD_u8_COL11        0x0B
#define LCD_u8_COL12        0x0C
#define LCD_u8_COL13        0x0D
#define LCD_u8_COL14        0x0E
#define LCD_u8_COL15        0x0F
#define LCD_u8_COL16        0x10
#define LCD_u8_COL17        0x11
#define LCD_u8_COL18        0x12
#define LCD_u8_COL19        0x13


void LCD_voidInit(void);
void LCD_voidSendCommand(u8 copy_u8Comand);
void LCD_voidDisplayCharacter(u8 copy_u8Data);
void LCD_voidCreateCustomCharacter(pu8 copy_pu8Character,u8 copy_u8PatternIndex,u8 copy_u8Row,u8 copy_u8Col);
void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col);
u8   LCD_u8DisplayString(pu8 copy_pu8String);
void LCD_voidDisplayNumber(s32 copy_u32Number);
void LCD_voidDisplayClear(void);

#endif
