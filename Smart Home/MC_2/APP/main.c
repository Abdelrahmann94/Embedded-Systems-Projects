#include "../LIB/Include/Std_types.h"
#include "../LIB/Include/Bit_utils.h"
#include "../MCAL/PORT/Include/PORT_interface.h"
#include "../MCAL/DIO/Include/DIO_interface.h"
#include "../MCAL/GIE/Include/GIE_interface.h"
#include "../MCAL/UART/Include/UART_interface.h"
#include "../MCAL/SPI/Include/SPI_interface.h"
#include "../MCAL/ADC/Include/ADC.h"
#include "../MCAL/TIMER/Include/TIMER.h"
#include "../HAL/LCD/Include/LCD_interface.h"
#define F_CPU     8000000UL
#include <util/delay.h>

void fan_crtl(void){

	Temperature_u16Value = ADC_Read(CH_0);
	LCD_voidGoToXY(LCD_u8_ROW1,14);
	LCD_voidDisplayNumber(Temperature_u16Value);
	u8 level=Temperature_u16Value/templvl;
	
	switch(level){
		
		case 0:
		
			Timer_voidsetPWM(255);
			Fan_u16Speed=Timer_getPWMdutycycle();
			SPI_SPIEnumSendData(Fan_u16Speed);
			break;
		
		case 1:
		
			Timer_voidsetPWM(200);
			Fan_u16Speed=Timer_getPWMdutycycle();
			SPI_SPIEnumSendData(Fan_u16Speed);
			break;
		
		case 2:
		
			Timer_voidsetPWM(150);
			Fan_u16Speed=Timer_getPWMdutycycle();
			SPI_SPIEnumSendData(Fan_u16Speed);
			break;
		
		case 3:
		
			Timer_voidsetPWM(100);
			Fan_u16Speed=Timer_getPWMdutycycle();
			SPI_SPIEnumSendData(Fan_u16Speed);
			break;
		
		case 4:
		
			Timer_voidsetPWM(50);
			Fan_u16Speed=Timer_getPWMdutycycle();
			SPI_SPIEnumSendData(Fan_u16Speed);
			break;
		
		case 5:
		
			Timer_voidsetPWM(50);
			Fan_u16Speed=Timer_getPWMdutycycle();
			SPI_SPIEnumSendData(Fan_u16Speed);
			break;
	}

}


void Receive_from_Master_MC(void)
{
	Temperature_u16Value = ADC_Read(CH_0);
	LCD_voidGoToXY(LCD_u8_ROW1,14);
	LCD_voidDisplayNumber(Temperature_u16Value);
	/* receive the data from the user */
	UART_UARTEnumReceiveData(&Receive_u8Data);
	
	switch(Receive_u8Data)
	{
		case 1:  DIO_DioEnumWriteChannel(DIO_u8_PORTC,DIO_u8_PIN0,DIO_u8_HIGH);  break;
		case 2:  DIO_DioEnumWriteChannel(DIO_u8_PORTC,DIO_u8_PIN0,DIO_u8_LOW);   break;
		case 3:  DIO_DioEnumWriteChannel(DIO_u8_PORTC,DIO_u8_PIN1,DIO_u8_HIGH);  break;
		case 4:  DIO_DioEnumWriteChannel(DIO_u8_PORTC,DIO_u8_PIN1,DIO_u8_LOW);   break;
		case 5:  DIO_DioEnumWriteChannel(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_HIGH);  break;
		case 6:  DIO_DioEnumWriteChannel(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_LOW);   break;
	}
}


u8 Receive_u8Data;
volatile u16 Temperature_u16Value;
volatile u8 Fan_u16Speed;

#define LED_1                 1
#define LED_2                 2
#define LED_3                 3

#define   LED_OFF             0
#define   LED_ON              1
#define templvl               20

int main(void)
{

	PORT_voidInit();
    UART_voidInit();
	SPI_voidMasterInit();
    LCD_voidInit();
	ADC_init(VREF_AREF,ADC_PRESCALER_64);
	Timer_FASTPWMvoidinit();
	
	
	while(1)
	{
		    Temperature_u16Value = ADC_Read(CH_0);
			DIO_DioEnumWriteChannel(DIO_u8_PORTD,DIO_u8_PIN6,DIO_u8_LOW);
			DIO_DioEnumWriteChannel(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_LOW);
			while(Temperature_u16Value >= 70){
				
				DIO_DioEnumWriteChannel(DIO_u8_PORTD,DIO_u8_PIN6,DIO_u8_HIGH);
				DIO_DioEnumWriteChannel(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
				Timer_voidsetPWM(0);
				LCD_voidGoToXY(LCD_u8_ROW2,1);
				LCD_u8DisplayString("ALARM ! ! !");
				Temperature_u16Value = ADC_Read(CH_0);
			}
			LCD_voidDisplayClear();
			
			while(Temperature_u16Value < 70){
				
				LCD_voidGoToXY(LCD_u8_ROW1,0);
				LCD_u8DisplayString("TEMPERATURE =     c");
				LCD_voidGoToXY(LCD_u8_ROW1,14);
				LCD_voidDisplayNumber(Temperature_u16Value);
				LCD_voidGoToXY(LCD_u8_ROW2,0);
				LCD_u8DisplayString("FIRE STATE:");
				LCD_voidGoToXY(LCD_u8_ROW2,12);
				LCD_u8DisplayString("STABLE");
				fan_crtl();
				Temperature_u16Value = ADC_Read(CH_0);
				Receive_from_Master_MC();
			}
	}
	return 0;
}











