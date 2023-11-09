/*
 * ADC.c
 *
 * Created: 10/26/2023 5:55:12 PM
 *  Author: ASUS
 */ 
#include "../../../LIB/Include/Std_types.h"
#include "../../../LIB/Include/Bit_utils.h"
#include "../Include/MemMap.h"
#include "../Include/ADC.h"
void ADC_init(ADC_VoltRef_type REF,ADC_Prescaler_type prescaler){
	
	switch(REF)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_256V:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	
	ADCSRA=prescaler;

	SET_BIT(ADCSRA,ADEN); //adc enable 

	
}
u16 ADC_Read(ADC_CH copy_u8pin){
	ADMUX=ADMUX|copy_u8pin;

	SET_BIT(ADCSRA,ADSC); // start conversion 

	while(GET_BIT(ADCSRA,ADSC)); //ADSC will read as one as long as a conversion is in progress. When the conversion is complete, it returns to zero. Writing zero to this bit has no effect.
	
	return (ADC/2);
	
}

void ADC_disable(void){
	ADCSRA=0X00;	
 }





