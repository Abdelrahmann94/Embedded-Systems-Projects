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

#define  F_CPU 8000000UL
#include <util/delay.h>

void sendCommand(u8 a_command)
{

	Dio_enuWriteChannel( RS , DIO_u8LEVEL_LOW );
	vTaskDelay(2);
	Dio_enuWriteChannel( EN , DIO_u8LEVEL_HIGH );
	

	send_step1( a_command);
	
	Dio_enuWriteChannel (EN ,DIO_u8LEVEL_LOW );
	vTaskDelay(2);
	Dio_enuWriteChannel (EN ,DIO_u8LEVEL_HIGH );
	
	send_step2( a_command);
	
	vTaskDelay(2);
	Dio_enuWriteChannel (EN ,DIO_u8LEVEL_LOW );
	

}

void sendData(u8 a_data)
{
	Dio_enuWriteChannel( RS , DIO_u8LEVEL_HIGH );
	vTaskDelay(2);
	Dio_enuWriteChannel( EN , DIO_u8LEVEL_HIGH );
	
	send_step1( a_data);
	
	Dio_enuWriteChannel (EN ,DIO_u8LEVEL_LOW );
	vTaskDelay(2);
	Dio_enuWriteChannel (EN ,DIO_u8LEVEL_HIGH );
	
	send_step2(a_data);
	
	vTaskDelay(2);
	Dio_enuWriteChannel (EN ,DIO_u8LEVEL_LOW );
	
	

}

void send_step1(u8 command){
	
	Dio_enuWriteChannel( DIO_u8CHANNEL08 ,  GET_BIT(command,4) );
	Dio_enuWriteChannel( DIO_u8CHANNEL09 ,  GET_BIT(command,5) );
	Dio_enuWriteChannel( DIO_u8CHANNEL10 ,  GET_BIT(command,6) );
	Dio_enuWriteChannel( DIO_u8CHANNEL12 ,  GET_BIT(command,7) );

}

void send_step2(u8 data){
	
	Dio_enuWriteChannel( DIO_u8CHANNEL08 ,  GET_BIT(data,0) );
	Dio_enuWriteChannel( DIO_u8CHANNEL09 ,  GET_BIT(data,1) );
	Dio_enuWriteChannel( DIO_u8CHANNEL10 ,  GET_BIT(data,2) );
	Dio_enuWriteChannel( DIO_u8CHANNEL12 ,  GET_BIT(data,3) );

}

void SendNumber   ( u32 Copy_u64Number ){

	u32 LOC_u64Reversed = 1 ;

	if( Copy_u64Number == 0 ){ sendData('0'); }

	else{

		while( Copy_u64Number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u64Number % 10 );
			Copy_u64Number /= 10 ;

		}
		while( LOC_u64Reversed != 1 ){

			sendData( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}
}


void displayString(u8* a_ptr2string)
{
	if(a_ptr2string != NULL)
	{
		for(u8 counter = 0; *(a_ptr2string + counter) != '\0'; counter++)
		{
			sendData(*(a_ptr2string + counter));
			
		}
	}
	else
	{
		/* Do Nothing. */
	}
}
 //----------------------------------------------------------------------------------------------------------------------------

