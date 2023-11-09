/*
 * LCD.h
 */ 


#ifndef LCDD_H_
#define LCDD_H_

void LCD_init(void);
void LCD_sendCommand(u8 a_command);
void LCD_sendData(u8 a_data);
void LCD_moveCursor(u8 a_row, u8 a_column);
void LCD_displayCharacter(u8 a_charachter);
void LCD_displayString(u8* a_ptr2string);
void LCD_displayStringRowColumns(u8* a_ptr2string, u8 a_row, u8 a_column);
void LCD_displayInteger(u32 a_integerNumber);
void LCD_createCustomCharacter(u8 location, u8 *pattern);
void LCD_clearScreen(void);
void LCD_returnHome(void);
void LCD_voidSendNumber   ( u64 Copy_u64Number    );



#endif /* LCD_H_ */