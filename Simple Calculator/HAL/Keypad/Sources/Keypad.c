/*
 * Keypad.c
 *
 */
#define F_CPU 1000000UL
#include <util/delay.h>

#include "Std_types.h"
#include "Bit_utils.h"
#include "Keypad.h"
#include "Keypad_prv.h"
#include "Keypad_cfg.h"


void KPD_Init(void){

             Port_enuSetPinDirection(pin16,OUT_PIN);
			Port_enuSetPinDirection(pin17,OUT_PIN);
			Port_enuSetPinDirection(pin18,OUT_PIN);
			Port_enuSetPinDirection(pin19,OUT_PIN);
			
			SetPinMode(pin24,INPUT_PULLUP);
			SetPinMode(pin25,INPUT_PULLUP);
			SetPinMode(pin26,INPUT_PULLUP);
			SetPinMode(pin27,INPUT_PULLUP);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------


u8   KPD_u8GetPressed( void ){

	u8 LOC_u8ReturnData = 0;
	u8 LOC_u8GetPressed ;

	u8 LOC_u8Row ;
	u8 LOC_u8Col ;

	for( LOC_u8Col = 0 + KPD_COL_INIT ; LOC_u8Col < KPD_COL_END +1 ; LOC_u8Col++ ){

		Dio_enuWriteChannel(  LOC_u8Col , DIO_u8LEVEL_LOW);   // Low on the columns

		for( LOC_u8Row = 0 +KPD_ROW_INIT ; LOC_u8Row < KPD_ROW_END+1; LOC_u8Row ++)   {

			Dio_enuReadChannel( LOC_u8Row  , &LOC_u8GetPressed ); // return the row value
			/* 
			if the row is high ....there is no pressed buttons
			if the row is low ....there is pressed button ===>> 
			 */
			if( LOC_u8GetPressed == 0 )
			{

				_delay_ms(50);   // delay for bouncing

				Dio_enuReadChannel(  LOC_u8Row , &LOC_u8GetPressed );   // to make sure that the button is pressed & check again

				if( LOC_u8GetPressed == 0 )

				{

					LOC_u8ReturnData = KPD_u8Buttons[ LOC_u8Row - KPD_ROW_INIT ][ LOC_u8Col - KPD_COL_INIT ];

				}

				
				Dio_enuReadChannel(  LOC_u8Row , &LOC_u8GetPressed );
				while(DIO_u8LEVEL_LOW  == LOC_u8GetPressed ) //  for assurance
				{

					Dio_enuReadChannel(  LOC_u8Row , &LOC_u8GetPressed );

				}

				break ;

			}

		}

		// return this column’s pin to high
		Dio_enuWriteChannel(  LOC_u8Col , DIO_u8LEVEL_HIGH); 

	}

	return LOC_u8ReturnData ;

}