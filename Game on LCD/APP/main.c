/*
 * main.c
 */

#include "Bit_utils.h"
#include "Std_types.h"
#include "Port.h"
#include "Dio.h"
#include "lcdd.h"
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

// arrays of custom characters to display on LCD
u8 customChar[] = {
  0x0E,
  0x0E,
  0x04,
  0x1F,
  0x04,
  0x0A,
  0x11,
  0x00
};
u8 customChar2[] = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00
};
u8 customChar3[] = {
   0x00,
   0x00,
   0x00,
   0x00,
   0x1F,
   0x00,
   0x00,
   0x00
};
u8 customChar4[] = {
   0x0C,
   0x04,
   0x04,
   0x04,
   0x04,
   0x04,
   0x04,
   0x1F
};
u8 customChar5[] = {
  0x1F,
  0x11,
  0x11,
  0x11,
  0x11,
  0x11,
  0x1F,
  0x00
};
u8 customChar6[] = {
  0x00,
  0x00,
  0x00,
  0x11,
  0x02,
  0x04,
  0x08,
  0x11
};
u8 customChar7[] = {
  0x01,
  0x02,
  0x04,
  0x08,
  0x00,
  0x00,
  0x00,
  0x00
};
u8 customChar8[] = {
  0x04,
  0x04,
  0x04,
  0x04,
  0x04,
  0x04,
  0x04,
  0x00
};


int main (void){

	int col,row = 1;
	int i,j=1; // iterators for displaying two lines on on the LCD
	int iteration =1; // flag for specifying every stage of the game
	
	LCD_init ();
	LCD_createCustomCharacter(1,customChar );
	LCD_createCustomCharacter(2,customChar2 );
	LCD_createCustomCharacter(3,customChar3 );
	LCD_createCustomCharacter(4,customChar4);
	LCD_createCustomCharacter(5,customChar5 );
	LCD_createCustomCharacter(6,customChar6 );
	LCD_createCustomCharacter(7,customChar7 );
	LCD_createCustomCharacter(8,customChar8 );

// 2 loops for displaying the upper road and the lower road where the boy walks
	for ( i=1; i<=16; i++){
		LCD_moveCursor(2,i);
		LCD_sendData(3);
	}
	
	for ( j=1; j<=16; j++){
		LCD_moveCursor(4,j);
		LCD_sendData(3);
	}
	
	while(col <= 16){
	
	LCD_moveCursor (row , col);
	LCD_sendData(1);
	_delay_ms(200);
	LCD_moveCursor (row , col);
	LCD_sendData(2);
	
	if (col ==16 && row ==1 && iteration ==1){
		
		col = 1;
		row = 3;
		LCD_moveCursor (row , col);
		LCD_sendData(1);
		_delay_ms(200);
		LCD_moveCursor (row , col);
		LCD_sendData(2);
		col++; 
		}
		
	else if ((col == 16) && (row == 3) && (iteration ==1)){
		
		row=1;
		col=1;
		LCD_moveCursor (row , col);
		LCD_sendData(1);
		_delay_ms(200);
		LCD_moveCursor (row , col);
		LCD_sendData(2);
		col =1;
		row=1;
		iteration =2;
		LCD_moveCursor (2 , 8);
		LCD_sendData(2);
	}
	else if ((col == 8) && (row == 1) && (iteration ==2)){
		
		col=8;
		row=3;
		LCD_moveCursor (row , col);
		LCD_sendData(1);
		_delay_ms(200);
		LCD_moveCursor (row , col);
		LCD_sendData(2);
		iteration =3;
	}
	else if ((col == 16) && (row == 3) && (iteration ==3)){
		
		col=1;
		row=3;
		LCD_moveCursor (row , col);
		LCD_sendData(1);
		_delay_ms(200);
		LCD_moveCursor (row , col);
		LCD_sendData(2);
		iteration =4;
	}
	else if ((col == 8) && (row == 3) && (iteration ==4)){
		
		LCD_moveCursor (4 , col);
		LCD_sendData(2);
		LCD_sendData(7);
		col=8;
		row=1;
		LCD_moveCursor (row , col);
		LCD_sendData(1);
		_delay_ms(200);
		LCD_moveCursor (row , col);
		LCD_sendData(2);
		iteration =5;
		
	}
	else if ((col == 10) && (row == 1) && (iteration ==5)){
		
		LCD_moveCursor (1 , 11);
		LCD_sendData(2);
		LCD_sendData(8);
		LCD_moveCursor (1 , 10);
		LCD_sendData(1);
		_delay_ms(2000);
		LCD_clearScreen();
		LCD_moveCursor (2 , 1);
		LCD_sendData(4);
		LCD_moveCursor (2 , 4);
		LCD_sendData(5);
		LCD_moveCursor (2 , 7);
		LCD_sendData(5);
		LCD_moveCursor (2 ,10);
		LCD_sendData(6);
		_delay_ms(10000);
		break;
	}
	
	else {
		
		col++;
	 }
	
	}
	return 0 ;
}
	
