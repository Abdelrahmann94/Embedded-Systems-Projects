/*
LCD.c
*/


#include "Bit_utils.h"
#include "Std_types.h"
#include "Port.h"
#include "Dio.h"
#include "lcdd.h"
#include "lcdd_prv.h"
#include "lcdd_cfg.h"

#define  F_CPU 1000000UL
#include <util/delay.h>

void LCD_init(void)
{
	Port_enuSetPinDirection( RS , OUT_PIN);
	Port_enuSetPinDirection( EN , OUT_PIN);
	Port_enuSetPinDirection( pin8 , OUT_PIN);
	Port_enuSetPinDirection( pin9 , OUT_PIN);
	Port_enuSetPinDirection( pin10, OUT_PIN);
	Port_enuSetPinDirection( pin12 , OUT_PIN);
	
	#if(LCD_DATA_BIT_MODE == LCD_4_BIT_MODE)

	LCD_sendCommand(LCD_4_BIT_2_LINES_INIT1_COMMAND);
	LCD_sendCommand(LCD_4_BIT_2_LINES_INIT2_COMMAND);
	LCD_sendCommand(LCD_4_BIT_2_LINES_SET_COMMAND);

	#elif(LCD_DATA_BIT_MODE == LCD_8_BIT_MODE)

	LCD_sendCommand(LCD_8_BIT_2_LINES_SET_COMMAND);

	#endif

	LCD_sendCommand(LCD_CURSOR_OFF_COMMAND);
	LCD_sendCommand(LCD_CLEAR_SCREEN_COMMAND);
}

//--------------------------------------------------------------------------------------------
void LCD_sendCommand(u8 a_command)
{
	Dio_enuWriteChannel( RS , DIO_u8LEVEL_LOW );
	_delay_ms(LCD_SETUP_TIME_DELAY);
	Dio_enuWriteChannel( EN , DIO_u8LEVEL_HIGH );
	_delay_ms(LCD_SETUP_TIME_DELAY);

	#if(LCD_DATA_BIT_MODE == LCD_4_BIT_MODE)

	Dio_enuWriteChannel( DIO_u8CHANNEL08 ,  GET_BIT(a_command,4) );
	Dio_enuWriteChannel( DIO_u8CHANNEL09 ,  GET_BIT(a_command,5) );
	Dio_enuWriteChannel( DIO_u8CHANNEL10 ,  GET_BIT(a_command,6) );
	Dio_enuWriteChannel( DIO_u8CHANNEL12 ,  GET_BIT(a_command,7) );

	_delay_ms(LCD_SETUP_TIME_DELAY);
	Dio_enuWriteChannel (EN ,DIO_u8LEVEL_LOW );
	_delay_ms(LCD_SETUP_TIME_DELAY);
	Dio_enuWriteChannel (EN ,DIO_u8LEVEL_HIGH );
	_delay_ms(LCD_SETUP_TIME_DELAY);

	Dio_enuWriteChannel( DIO_u8CHANNEL08 ,  GET_BIT(a_command,0) );
	Dio_enuWriteChannel( DIO_u8CHANNEL09 ,  GET_BIT(a_command,1) );
	Dio_enuWriteChannel( DIO_u8CHANNEL10 ,  GET_BIT(a_command,2) );
	Dio_enuWriteChannel( DIO_u8CHANNEL12 ,  GET_BIT(a_command,3) );


	#elif(LCD_DATA_BIT_MODE == LCD_8_BIT_MODE)

	Dio_enuWriteChannel( DIO_u8CHANNEL12 ,  GET_BIT(a_command,3) );

	#endif

	_delay_ms(LCD_SETUP_TIME_DELAY);
	Dio_enuWriteChannel (EN ,DIO_u8LEVEL_LOW );
	_delay_ms(LCD_SETUP_TIME_DELAY);
}


//---------------------------------------------------------------------------------------------
void LCD_sendData(u8 a_data)
{
	Dio_enuWriteChannel( RS , DIO_u8LEVEL_HIGH );
	_delay_ms(LCD_SETUP_TIME_DELAY);
	Dio_enuWriteChannel( EN , DIO_u8LEVEL_HIGH );
	_delay_ms(LCD_SETUP_TIME_DELAY);

	#if LCD_DATA_BIT_MODE == LCD_4_BIT_MODE

	Dio_enuWriteChannel( DIO_u8CHANNEL08 ,  GET_BIT(a_data,4) );
	Dio_enuWriteChannel( DIO_u8CHANNEL09 ,  GET_BIT(a_data,5) );
	Dio_enuWriteChannel( DIO_u8CHANNEL10 ,  GET_BIT(a_data,6) );
	Dio_enuWriteChannel( DIO_u8CHANNEL12 ,  GET_BIT(a_data,7) );

	_delay_ms(LCD_SETUP_TIME_DELAY);
	Dio_enuWriteChannel (EN ,DIO_u8LEVEL_LOW );
	_delay_ms(LCD_SETUP_TIME_DELAY);
	Dio_enuWriteChannel (EN ,DIO_u8LEVEL_HIGH );
	_delay_ms(LCD_SETUP_TIME_DELAY);

	Dio_enuWriteChannel( DIO_u8CHANNEL08 ,  GET_BIT(a_data,0) );
	Dio_enuWriteChannel( DIO_u8CHANNEL09 ,  GET_BIT(a_data,1) );
	Dio_enuWriteChannel( DIO_u8CHANNEL10 ,  GET_BIT(a_data,2) );
	Dio_enuWriteChannel( DIO_u8CHANNEL12 ,  GET_BIT(a_data,3) );

	#elif(LCD_DATA_BIT_MODE == LCD_8_BIT_MODE)

	Dio_enuWriteChannel( DIO_u8CHANNEL12 ,  GET_BIT(a_data,3) );

	#endif

    _delay_ms(LCD_SETUP_TIME_DELAY);
    Dio_enuWriteChannel (EN ,DIO_u8LEVEL_LOW );
	_delay_ms(LCD_SETUP_TIME_DELAY);
}

//----------------------------------------------------------------------------------------------------

void LCD_moveCursor(u8 a_row, u8 a_column)
{

	u8 LOC_memoryAddress = LCD_16_COLUMNS_1ST_ROW_BASE_ADDRESS;

	switch (a_row)
	{
	case 1:
		LOC_memoryAddress = (LCD_16_COLUMNS_1ST_ROW_BASE_ADDRESS + a_column);
		break;

	case 2:
		LOC_memoryAddress = (LCD_16_COLUMNS_2ND_ROW_BASE_ADDRESS + a_column);
		break;

	case 3:
		LOC_memoryAddress = (LCD_16_COLUMNS_3RD_ROW_BASE_ADDRESS + a_column);
		break;

	case 4:
		LOC_memoryAddress = (LCD_16_COLUMNS_4TH_ROW_BASE_ADDRESS + a_column);
		break;

	default:
		LOC_memoryAddress = LCD_16_COLUMNS_1ST_ROW_BASE_ADDRESS;
		break;
	}

	LCD_sendCommand(LCD_MOVE_CURSOR_COMMAND(LOC_memoryAddress));
}

//---------------------------------------------------------------------------------------------------------------------
void LCD_displayCharacter(u8 a_charachter)
{
	LCD_sendData(a_charachter);
}

//---------------------------------------------------------------------------------------------------------------------

void LCD_displayString(u8* a_ptr2string)
{
	if(a_ptr2string != NULL)
	{
		for(u8 counter = 0; *(a_ptr2string + counter) != '\0'; counter++)
		{
			LCD_displayCharacter(*(a_ptr2string + counter));
		}
	}
	else
	{
		/* Do Nothing. */
	}
}

//---------------------------------------------------------------------------------------------------------------------
void LCD_displayStringRowColumns(u8* a_ptr2string, u8 a_row, u8 a_column)
{
	LCD_moveCursor(a_row,a_column);
	LCD_displayString(a_ptr2string);
}

//---------------------------------------------------------------------------------------------------------------------
void LCD_displayInteger(u32 a_integerNumber)
{
	u32 LOC_reversedNumber = 0;

	while(a_integerNumber != 0)
	{
		LOC_reversedNumber = (LOC_reversedNumber * 10) + (a_integerNumber % 10);
		a_integerNumber /= 10;
	}

	while(LOC_reversedNumber != 0)
	{
		LCD_displayCharacter((LOC_reversedNumber % 10) + '0');
		LOC_reversedNumber /= 10;
	}
}

void LCD_voidSendNumber   ( u64 Copy_u64Number    ){

	u64 LOC_u64Reversed = 1 ;

	if( Copy_u64Number == 0 ){ LCD_sendData('0'); }

	else{

		while( Copy_u64Number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u64Number % 10 );
			Copy_u64Number /= 10 ;

		}
		while( LOC_u64Reversed != 1 ){

			LCD_sendData( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}

}

//---------------------------------------------------------------------------------------------------------------------

void LCD_createCustomCharacter(u8 location, u8 *pattern) {
	
	location &= 0x07; 
	LCD_sendCommand(0x40 | (location << 3));

	for (u8 i = 0; i < 8; i++) {
		LCD_sendData(pattern[i]);
	}

	
	LCD_sendCommand(0x80);
}
//---------------------------------------------------------------------------------------------------------------------
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_SCREEN_COMMAND);
}
//---------------------------------------------------------------------------------------------------------------------
void LCD_returnHome(void)
{
	LCD_sendCommand(LCD_RETURN_HOME_COMMAND);
}
