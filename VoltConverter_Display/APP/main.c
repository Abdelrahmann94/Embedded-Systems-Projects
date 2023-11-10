/*
 * main.c
 */ 
#include "Bit_utils.h"
#include "Std_types.h"
#include "Port.h"
#include "Dio.h"
#include "lcdd.h"
#include "ADC.h"
#include "EXTI.h"
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

//                          <<<<<<<<<<<<<<<<<<<< Volt task by two methods : polling method and EXTII method >>>>>>>>>>>>>>>>>>>>>>>>


u32 x,y,z=0;  // variables to divide the result into integer part and float part to convert from mv to volt

u16 result =0; // global variable to carry the result of ADC conversion

u8 flag=1;  // flag for switching between mv and volt
u8 chanel_level; 

// array for clearing the result while conversion
u8 customChar[] = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00
};
u8 chanel_level;

/*void isr (void){
	
	if (flag == 1){
		flag=0;
		}
		else if (flag==0) {
			flag =1;
			}
} */
int main (void){
	LCD_init();
	
	// setting the mode of ADC channel0 and INT0 as input pullup
	SetPinMode(pin0,INPUT_PULLUP);   //ADC channel 0
	SetPinMode(pin26,INPUT_PULLUP);  // pin connected to push button

	/*
	EXTI_voidInit ();
	EXTI_voidSetTriggeringMode( EXTI_FALLING_EDGE , EXTI_LINE0 );
	EXTI_voidEnableInterrupt    ( EXTI_LINE0  );
	EXTI_voidSetCallBack(isr, 0 );
	GIE_INIT(); */
	
	ADC_voidInit();
	LCD_createCustomCharacter( 2, customChar);
	LCD_moveCursor(1, 2);
	LCD_displayString((u8 *)"volt= "); 
	
	
	while (1){
		
		// getting the result of ADC conversion
		ADC_u8GetResultSync (ADC_CHANNEL0, &result ); 
		
		z = result*5;      // stroring the voltage by mv
		x = z %1000;       // storing the number after the dot in x variable ( the float part )
		y = z/1000;       // storing the number before the dot in x variable ( the integer part )
		
		Dio_enuReadChannel (DIO_u8CHANNEL26,&chanel_level); // reading the level of the pin to check if the button is pressed or not
		
				switch (chanel_level){
					
					case DIO_u8LEVEL_HIGH :
					
						if (flag==1){
							
							LCD_moveCursor(1, 14);       // if flag equals 1 which is the initialized value.the result of conversion will be displayed (mv)
							LCD_displayString((u8 *)"mv");
							LCD_moveCursor(1, 6);
							LCD_sendData(2);
							LCD_voidSendNumber (z);
							flag=1;
							}
							
						else if (flag == 0) {
													
							LCD_moveCursor(1, 7);		// if flag equals 0 the value will be displayed but with volt by displaying the integer num then ',' then the float part
							LCD_voidSendNumber (y);
							LCD_moveCursor(1, 8);
							LCD_displayString((u8 *)",");
							LCD_moveCursor(1, 9);
							LCD_voidSendNumber (x);
							LCD_moveCursor(1, 14);
							LCD_displayString((u8 *)" V");
							flag =0;
					             }
						break;
				
				case DIO_u8LEVEL_LOW :
				
						if (flag==1){            // channel level equals low means that the button is pressed and it will convert the result from mv to volt
						
							_delay_ms(50);
							LCD_clearScreen();
							LCD_moveCursor(1, 2);
							LCD_displayString((u8 *)"volt= ");
							LCD_moveCursor(1, 7);
							LCD_voidSendNumber (y);
							LCD_moveCursor(1, 8);
							LCD_displayString((u8 *)",");
							LCD_moveCursor(1, 9);
							LCD_voidSendNumber (x);
							LCD_moveCursor(1, 14);
							LCD_displayString((u8 *)" V");
							flag=0;}
							
						else if (flag == 0) {         // if channel level is low and the flage equal zero that means the value is displayed by volt so, it will be converted to mv
						
							_delay_ms(50);
							LCD_clearScreen();
							LCD_moveCursor(1, 2);
							LCD_displayString((u8 *)"volt= ");
							LCD_moveCursor(1, 14);
							LCD_displayString((u8 *)"mv");
							LCD_moveCursor(1, 6);
							LCD_voidSendNumber (z);
							flag =1;
						}
						break;
					
				default:
				break;
		  }
		}
	}
		 