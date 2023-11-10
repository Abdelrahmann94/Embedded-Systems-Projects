/*
 * EXTI.c
*/

#include "Std_types.h"
#include "Bit_utils.h"

#include "EXTI.h"
#include "EXTI_prv.h"
#include "EXTI_cfg.h"

/* 
	Global Pointer to Function => Carry The Adress of ISR func in the main 
	array of pointers to carry EXTI 0,1,2 according to its index
	
*/ 
void (*EXTI_CallBack[3]) (void) ; 

//---------------------------------------------------------------------------------------------------------------------------------------------------

void EXTI_voidInit      ( void ){

	#ifdef EXTI_LINE

		/*  Check for EXTI line  */
		#if EXTI_LINE == EXTI_LINE1

			/* Check for Sense Mode  */
			#if     EXTI_SENSE_MODE == EXTI_LOW_LEVEL

				CLR_BIT( MCUCR_REG , 2 ); CLR_BIT( MCUCR_REG , 3 );

			#elif     EXTI_SENSE_MODE == EXTI_ON_CHANGE

				SET_BIT( MCUCR_REG , 2 ); CLR_BIT( MCUCR_REG , 3 );

			#elif     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

				CLR_BIT( MCUCR_REG , 2 ); SET_BIT( MCUCR_REG , 3 );

			#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

				SET_BIT( MCUCR_REG , 2 ); SET_BIT( MCUCR_REG , 3 );

			#endif


		#elif EXTI_LINE == EXTI_LINE0

			#if     EXTI_SENSE_MODE == EXTI_LOW_LEVEL

				CLR_BIT( MCUCR_REG , 0 ); CLR_BIT( MCUCR_REG , 1 );

			#elif     EXTI_SENSE_MODE == EXTI_ON_CHANGE

				SET_BIT( MCUCR_REG , 0 ); CLR_BIT( MCUCR_REG , 1 );

			#elif     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

				CLR_BIT( MCUCR_REG , 0 ); SET_BIT( MCUCR_REG , 1 );

			#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

				SET_BIT( MCUCR_REG , 0 ); SET_BIT( MCUCR_REG , 1 );

			#endif

		#elif EXTI_LINE == EXTI_LINE2

				#if     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

					CLR_BIT( MCUCSR_REG , 6 );

				#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

					SET_BIT( MCUCSR_REG , 6 );

				#endif

		#else
				#error "Wrong INT0_SENSE configuration option"
		
		#endif

	#endif

}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*  Description:  A function to set the required sense control of INT0 using postbuild configuration
 * 	Input:	Copy_u8Sense , options are: 1-  LOW_LEVEL
 * 	                                    2-  ON_CHANGE
 * 	                                    3-  FALLING_EDGE
 * 	                                    4-  RISING_EDGE
	*/
void EXTI_voidSetTriggeringMode( u8 Copy_u8SenseMode , u8 Copy_u8Line ){

	/* For EXTI0 & EXTI1 */
	if( Copy_u8Line >= EXTI_LINE0 && Copy_u8Line <= EXTI_LINE1 ){

		Copy_u8Line = ( 6 - Copy_u8Line ) * -2 ;

		switch( Copy_u8SenseMode ){

		/* INT Sense Control (Trigger) For EXTI0 & EXTI1   */
		case EXTI_LOW_LEVEL    : CLR_BIT( MCUCR_REG , Copy_u8Line ); CLR_BIT( MCUCR_REG , (Copy_u8Line + 1) ); break;
		case EXTI_ON_CHANGE    : SET_BIT( MCUCR_REG , Copy_u8Line ); CLR_BIT( MCUCR_REG , (Copy_u8Line + 1) ); break;
		case EXTI_FALLING_EDGE : CLR_BIT( MCUCR_REG , Copy_u8Line ); SET_BIT( MCUCR_REG , (Copy_u8Line + 1) ); break;
		case EXTI_RISING_EDGE  : SET_BIT( MCUCR_REG , Copy_u8Line ); SET_BIT( MCUCR_REG , (Copy_u8Line + 1) ); break;

		}
	}

	/* For EXTI2 */
	else{

		switch( Copy_u8SenseMode ){
		
		/* INT Sense Control (Trigger) For EXTI0 & EXTI1   */
		case EXTI_FALLING_EDGE : CLR_BIT( MCUCSR_REG , 6 );  break;
		case EXTI_RISING_EDGE  : SET_BIT( MCUCSR_REG , 6 );  break;

		}

	}

}
void EXTI_voidDisableInterrupt   ( u8 Copy_u8Line ){

		/* Clear The Required BIT */
		CLR_BIT( GICR , Copy_u8Line );
	
}
void GIE_INIT(void)
{
	switch(GIE_STATE)
	{
		case ENABLE_GIE:
		//SREG=8;
		SET_BIT(SREG,7);
		break;
		case DISABLE_GIE:
		CLR_BIT(SREG,7);
		break;
	}
	
}
void EXTI_voidEnableInterrupt    ( u8 Copy_u8Line ){

		/* Set The Required BIT */
		SET_BIT( GICR , Copy_u8Line );
}

void EXTI_voidClearFlag ( u8 Copy_u8Line ){

	SET_BIT( GIFR, Copy_u8Line );

}

u8 EXTI_u8GetFlag( u8 Copy_u8Line ){

	return GET_BIT( GIFR , Copy_u8Line );

}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Parameters : 
				=> The Adress of ISR Func 
				=> EXTI Line --> [EXTI_LINE0 , EXTI_LINE1 , EXTI_LINE2]

 */
void EXTI_voidSetCallBack( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine ){

	if( Copy_pvoidCallBack != NULL ){

		EXTI_CallBack[Copy_u8EXTILine] = Copy_pvoidCallBack ;

	}

}


/* ISR --> Implementation */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{

	if( EXTI_CallBack[0] != NULL ){

		EXTI_CallBack[0](); /*  Call The Global Pointer to Func   */
		

	}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{

	if( EXTI_CallBack[1] != NULL ){

		EXTI_CallBack[1]();
		

	}

}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{

	if( EXTI_CallBack[2] != NULL ){

		EXTI_CallBack[2]();

	}

}
