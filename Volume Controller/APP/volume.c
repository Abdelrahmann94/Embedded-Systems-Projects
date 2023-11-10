/*
 * main.c
 */ 
#include "Bit_utils.h"
#include "Std_types.h"
#include "Port.h"
#include "Dio.h"
#include "lcdd.h"
#include "ADC.h"
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

// global variable for storing the result of conversion by V
float y=0; 

 // global variable carrying the result of ADC conversion
u16 result = 0 ;

// initialization of custom characters to display on LCD
u8 customChar1[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x1F,
  0x1F};
  
 u8 customChar2[] = {
	 0x00,
	 0x00,
	 0x00,
	 0x00,
	 0x1F,
	 0x1F,
	 0x1F,
	 0x1F
  };
  u8 customChar3[] = {
	 0x00,
	 0x00,
	 0x1F,
	 0x1F,
	 0x1F,
	 0x1F,
	 0x1F,
	 0x1F
  };
  u8 customChar4[]= 
  { 0x1F,
	  0x1F,
	  0x1F,
	  0x1F,
	  0x1F,
	  0x1F,
	  0x1F,
	  0x1F
  };
  u8 customChar[]=
  {   0x00,
	  0x00,
	  0x00,
	  0x00,
	  0x00,
	  0x00,
	  0x00,
	  0x00
  };

int main (void){
	
	LCD_init(); 
	SetPinMode(pin0,INPUT_PULLUP); // set mode of ADC channel 0 as input pullup
	ADC_voidInit();
	LCD_createCustomCharacter( 1, customChar1);
	LCD_createCustomCharacter( 2, customChar2);
	LCD_createCustomCharacter( 3, customChar3);
	LCD_createCustomCharacter( 4, customChar4);
	LCD_createCustomCharacter( 0, customChar);
	LCD_moveCursor(1, 2);
	LCD_displayString((u8 *)"VOLUME ");

	

	while (1){
		
		// getting the result of ADC conversion and storing it in the global variable
		ADC_u8GetResultSync (ADC_CHANNEL0, &result );
	
		// converting the result to volt
		y= result*5/1000;

		/* 4 conditions for displaying 4 levels of volume based on the value of voltage */
	
			if ((y >= 1) && (y < 2 )){   
				
				LCD_moveCursor(3, 4);
				LCD_sendData(0);
				LCD_moveCursor(3, 5);
				LCD_sendData(0);
				LCD_moveCursor(3, 6);
				LCD_sendData(0);
				LCD_moveCursor(3, 3);
				LCD_sendData(1);
				_delay_ms(50) ;
}
			else if ((y >= 2) && (y < 3 )) {
				LCD_moveCursor(3, 5);
				LCD_sendData(0);
				LCD_moveCursor(3, 6);
				LCD_sendData(0);
				LCD_moveCursor(3, 3);
				LCD_sendData(1);
				LCD_moveCursor(3, 4);
				LCD_sendData(2);
				_delay_ms(50) ;
			}
			else if ((y >= 3) && (y < 4 )) {
			
				LCD_moveCursor(3, 6);
				LCD_sendData(0);
				LCD_moveCursor(3, 3);
				LCD_sendData(1);
				LCD_moveCursor(3, 4);
				LCD_sendData(2);	
				LCD_moveCursor(3, 5);
				LCD_sendData(3);
				_delay_ms(50) ;
				}
				
			else if ((y >= 4) && (y < 5)) {
					
				LCD_moveCursor(3, 3);
				LCD_sendData(1);
				LCD_moveCursor(3, 4);
				LCD_sendData(2);
				LCD_moveCursor(3, 5);
				LCD_sendData(3);
				LCD_moveCursor(3, 6);
				LCD_sendData(4);
				_delay_ms(50) ;
				}
			_delay_ms(50) ;
		
	}
}