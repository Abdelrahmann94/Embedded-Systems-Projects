/*
 * CFile1.c
 
 */ 
#include "Bit_utils.h"
#include "Std_types.h"
#include "lcdd.h"
#include "KPD_interface.h"
#include "Port.h"
#define F_CPU 8000000UL
#include <util/delay.h>

u16 x , y =0;        // first and second operand
u8 num =1;           // flag to specify where the input number will be stored in x or y
u8 r=1;              // row of LCD
u8 c=0;              // column of LCD
char op= '0';        // mathematical operation " +,-,*,/ "
s32 z=0;             // result of the mathematical operation
u16 button ;
int main (void){
	
	LCD_init();
	
	while(1){
		
		LCD_moveCursor(r,c);
		_delay_ms(50);        // delay for buttons bouncing
		button = KEYPAD_u8GetButton();
		switch (button){
			case '0':
			
				if  (num==1){   // checking if the num is first operand
					x*=10;
					LCD_displayCharacter(button);
					c++;       // go to the next column
					}	
				else if (num==2){ // checking if the num is second operand
					y*=10;
					LCD_displayCharacter(button);
					c++;
				}
				break;
					
			case '1':
			
				if (num ==1){
					x = x*10+1;
					LCD_displayCharacter(button);
					c++;
			}
				else if (num==2){
					y = y*10+1;
					LCD_displayCharacter(button);
					c++;
			}
				break;

			case '2':
			
				if (num ==1){
					x = x*10+2;
					LCD_displayCharacter(button);
					c++;
				}
				else if (num==2){
					y = y*10+2;
					LCD_displayCharacter(button);
					c++;
				}
				break;
				
			case '3':
			
					if (num ==1){
						x = x*10+3;
						LCD_displayCharacter(button);
						c++;
				}
				else if (num==2){
						y = y*10+3;
						LCD_displayCharacter(button);
						c++;
				}
				break;
				
			case '4':
			
				if (num ==1){
					x = x*10+4;
					LCD_displayCharacter(button);
					c++;
				}
				else if (num==2){
					y = y*10+4;
					LCD_displayCharacter(button);
					c++;
				}
				break;
				
			case '5':
			
				if (num ==1){
					x = x*10+5;
					LCD_displayCharacter(button);
					c++;
				}
				else if (num==2){
					y = y*10+5;
					LCD_displayCharacter(button);
					c++;
				}
				break;
				
			case '6':
			
				if (num ==1){
					x = x*10+6;
					LCD_displayCharacter(button);
					c++;
				}
				else if (num==2){
					y = y*10+6;
					LCD_displayCharacter(button);
					c++;
				}
				break;
				
			case '7':
				
				if (num ==1){
					x = x*10+7;
					LCD_displayCharacter(button);
					c++;
					}
				else if (num==2){
					y = y*10+7;
					LCD_displayCharacter(button);
					c++;
					}
					break;
					
			case '8':
				
				if (num ==1){
					x = x*10+8;
					LCD_displayCharacter(button);
					c++;
					}
				else if (num==2){
					y = y*10+8;
						LCD_displayCharacter(button);
						c++;
						}
				break;
						
			case '9':
				
				if (num ==1){
						x = x*10+9;
						LCD_displayCharacter(button);
						c++;
						}
				else if (num==2){
						y = y*10+9;
						LCD_displayCharacter(button);
							c++;
							}
				break;
					
			case '+':      // in case of the character is (+ or - or * or /) the flag will equal 2 indicating that the next num will be operand 2
				num =2;
				op='+';
				LCD_displayCharacter(button);
				c++;
				break;
					
			case '-':
				num=2;
				op= '-';
				LCD_displayCharacter(button);
				c++;
				break;
					
			case '/':
				num=2;
				op= '/';
				LCD_displayCharacter(button);
				c++;
				break;
					
			case '*':
				num=2;
				op= '*';
				LCD_displayCharacter(button);
				c++;
				break;
					
			case 'c' :     // in case of the input character is c , the calculator will reset
				 LCD_clearScreen();
				 x=0;
				 num =1;
				 r=1;
				 c=0;
				 y=0;
				 op='0';
				break;
					 
			case '=' :
				LCD_moveCursor(r+2,11);
				if (op == '0'){               // if there is no math operation, show the input num
					LCD_voidSendNumber(z);
				}
				else if (op == '+'){
					z = x + y;
					LCD_voidSendNumber(z);    // showing the result of summation
				}
					
				else if (op == '-'){
						if (x < y){          // displaying the negative results
							z = y-x;
							LCD_displayCharacter('-');
							LCD_voidSendNumber(z);}
							else{							
						z = x - y;
						LCD_voidSendNumber(z);}
					}
					else if (op == '/'){
						if ((x>0) && (y==0)){   // giving an error if the num is divided by 0
							LCD_moveCursor(r+2,9);
							LCD_displayString("error");
						}
						else{
						z = x / y;
						LCD_voidSendNumber(z);}
					}
					else if (op == '*'){
							z = x * y;
						LCD_voidSendNumber(z);
					}
					break;
				}
		}
	}