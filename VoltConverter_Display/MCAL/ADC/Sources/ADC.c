/*
 * ADC.c
 */

#include "Std_types.h"
#include "Bit_utils.h"

#include "ADC_prv.h"
#include "ADC.h"
#include "ADC_cfg.h"
#include "Port.h"



/*Global pointer to carry the conversion result in the Asynchronous execution*/
static u16 * ADC_pu16AsynchConversionResult = NULL;

/*Global pointer to function to carry the notification function called by ISR*/
static void (* ADC_pvNotificationFunc)(void)= NULL;


static u8 ADC_u8State= IDLE ;

//=====================================================================================================================

void ADC_voidInit(void)
{
	/*Select the voltage reference*/
	#if ADC_VREF == AREF
		CLR_BIT(ADMUX , 6) ;
		CLR_BIT(ADMUX , 7) ;

	#elif ADC_VREF == AVCC
		SET_BIT(ADMUX , 6) ;
		CLR_BIT(ADMUX , 7) ;

	#elif ADC_VREF == INTERNAL_2_56
		SET_BIT(ADMUX , 6) ;
		SET_BIT(ADMUX , 7) ;

	#else
		#error "Wrong ADC_VREF config"

	#endif

	/*Enable ADC Peripheral*/
	#if ADC_STATUS == ADC_DISABLE
	CLR_BIT(ADCSRA , ADSAR_ADEN) ;
	#elif ADC_STATUS == ADC_ENABLE
	SET_BIT(ADCSRA , ADSAR_ADEN) ;
	#endif

	
	#if ADC_TRIGGERING_SOURCE ==ADC_SINGLE_CONVERSION
	
	
	CLR_BIT(ADCSRA,5);
	
	#elif ADC_TRIGGERING_SOURCE == ADC_FREE_RUNNING 
	//SET_BIT(ADCSRA,7);
	//SET_BIT(ADCSRA,6);
	SET_BIT(ADCSRA,5);
	CLR_BIT(SFIOR,7); CLR_BIT(SFIOR,6); CLR_BIT(SFIOR,5);

    #elif ADC_TRIGGERING_SOURCE == ADC_EXTI0
	
	SET_BIT(ADCSRA,5);
	CLR_BIT(SFIOR,7); SET_BIT(SFIOR,6); CLR_BIT(SFIOR,5);
	
	#elif ADC_TRIGGERING_SOURCE == ADC_TIM0_OVF
	
	SET_BIT(ADCSRA,5);
	SET_BIT(SFIOR,7);  CLR_BIT(SFIOR,6);  CLR_BIT(SFIOR,5);
	#endif
	/*Set Prescaler Value*/
	//ADCSRA &= 0xF8 ;
	SET_BIT(ADCSRA,0) ;
	SET_BIT(ADCSRA,1) ;
	SET_BIT(ADCSRA,2) ;

	/* ENABLE The Peripheral & Interrupt  */


	/*Enable ADC Interrupt*/
	#if INT_STATUS == INT_DISABLE
		CLR_BIT(ADCSRA , ADSAR_ADIE) ;
	#elif INT_STATUS == INT_ENABLE
		SET_BIT(ADCSRA , ADSAR_ADIE) ;
	#else
	#error "Wrong INT_STATUS config"
	#endif

}


void ADC_voidEnable (void)
{
	SET_BIT(ADCSRA , ADSAR_ADEN) ;
}



void ADC_voidDisable (void)
{
	CLR_BIT(ADCSRA , ADSAR_ADEN) ;
}



void ADC_voidInterruptEnable (void)
{
	SET_BIT(ADCSRA , ADSAR_ADIE) ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void ADC_voidInterruptDisable (void)
{
	CLR_BIT(ADCSRA , ADSAR_ADIE) ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

u8 ADC_u8SetPrescaler (u8 Copy_u8Prescaler)
{
	Adc_tenu_ErrorStatus Local_u8ErrorState = enuok ;

	if (Copy_u8Prescaler < 8)
	{
		/*Set Prescaler Value*/
		ADCSRA &= ADC_PRE_MASK ;
		ADCSRA |= Copy_u8Prescaler ;
	}

	return Local_u8ErrorState ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
 
void ADC_u8GetResultSync (u8 Copy_u8Channel , u16 * Copy_pu16Result)
{

	u8 Loc_u8Counter  = 200 ;
	
		ADMUX &= 0xE0;

		ADMUX |= Copy_u8Channel ;

			//Start Conversion
			SET_BIT(ADCSRA , 6) ;

			//Waiting until the conversion is complete
			while( (GET_BIT(ADCSRA, 4) == 1) && (Loc_u8Counter > 0))
			{
				Loc_u8Counter--;
			}
			

				//Return Conversion Result
				#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
					*Copy_pu16Result = (ADCL|(ADCH << 8))  ;

				#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
					*Copy_pu16Result = ADCH ;
				#else
					#error "Wrong ADC_ADJUSTMENT config"

				#endif
				
					//Clear the interrupt flag
					CLR_BIT(ADCSRA , 4) ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

Adc_tenu_ErrorStatus ADC_u8StartConversionAsynch (u8 Copy_u8Channel , u16 * Copy_pu16Result , void (*Copy_pvNotificationFunc)(void))
{
	Adc_tenu_ErrorStatus Local_u8ErrorState = enuok ;

	if ((Copy_pu16Result != NULL) && (Copy_pvNotificationFunc != NULL))
	{
		if (ADC_u8State == BUSY)
		{
			/*ADC is now Busy*/
			ADC_u8State = BUSY;

			/*Set ISR State*/

			/*Initialize the global result pointer*/
			ADC_pu16AsynchConversionResult = Copy_pu16Result;

			/*Initialize the global notification function pointer*/
			ADC_pvNotificationFunc= Copy_pvNotificationFunc;

			/*Set required channel*/
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= Copy_u8Channel ;

			/*Start Conversion*/
			SET_BIT(ADCSRA , ADSAR_ADSC) ;

			/*ADC Conversion Complete Interrupt Enable*/
			SET_BIT(ADCSRA , ADSAR_ADIE) ;
		}
		else
		{
			Local_u8ErrorState = BUSY_STATE ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;
}

//----------------------------------------------------------------------------------------------------------------------

/* ISR for ADC conversion complete */
void __vector_16 (void)  __attribute__((signal)) ;
void __vector_16 (void)
{
	
		/*Return Conversion Result*/
				#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
					* ADC_pu16AsynchConversionResult = (ADCL|(ADCH << 8))  ;

				#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
					*ADC_pu16AsynchConversionResult = ADCH ;
				#else
					#error "Wrong ADC_ADJUSTMENT config"

				#endif

		/*ADC is IDLE*/
		ADC_u8State = IDLE ;

		/*Call Notification Function*/
		ADC_pvNotificationFunc() ;

		/*Disable the Conversion Complete Interrupt*/
		CLR_BIT(ADCSRA , ADSAR_ADIE) ;
	
}

