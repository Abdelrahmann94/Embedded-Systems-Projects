/*
 * ADC.h
 *
 * Created: 10/26/2023 5:55:27 PM
 *  Author: ASUS
 */ 


#ifndef ADC_H_
#define ADC_H_



typedef enum{
	VREF_AREF,//AREF ,internal vref turned off
	VREF_AVCC,//AVCC with external capacitor at AREF pin
	VREF_256V //internal 2.56v voltage reference with external capacitor at AREF pin
}ADC_VoltRef_type;

typedef enum{
	ADC_PRESCALER_2=1,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128,
}ADC_Prescaler_type;


typedef enum{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7,
}ADC_CH;


void ADC_init(ADC_VoltRef_type REF,ADC_Prescaler_type prescaler);
//using admux first (from left) 2 bits to set the voltage reference 
// using the next bit (adlar ) to adjust the adc read registers (leftmost or right most )
// the last 4 bits are used for selecting which channel to read from and wither we need gain or not (use the table in datasheet then || the number with the reg )
// choose a prescaler and assign it to adsra reg 
u16 ADC_Read(ADC_CH copy_u8pin);
// using adcsra reg
// first bit is used to enable adc 
// second bit is used to start conversion 
// third bit is used to enable auto trigger enable ( you will choose the start event from a table and set it in sfior reg)
// 4th bit is the adc int flag
//5th is the adc int enable 


void ADC_disable(void);
// clr first bit in adcsra


#endif /* ADC_H_ */