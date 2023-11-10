/*
 * ADC.h
 */

#ifndef MCAL_ADC_INCLUDES_ADC_H_
#define MCAL_ADC_INCLUDES_ADC_H_

/* ADC_STATE */
#define BUSY                    0
#define IDLE                    1

#define ADC_DISABLE             0
#define ADC_ENABLE              1

#define INT_DISABLE             0
#define INT_ENABLE              1

#define AREF                    0
#define AVCC                    1
#define INTERNAL_2_56           2



#define RIGHT_ADJUSTMENT        0
#define LEFT_ADJUSTMENT         1

#define ADC_CHANNEL0            0
#define ADC_CHANNEL1            1
#define ADC_CHANNEL2            2
#define ADC_CHANNEL3            3
#define ADC_CHANNEL4            4
#define ADC_CHANNEL5            5
#define ADC_CHANNEL6            6
#define ADC_CHANNEL7            7

#define ADC_SINGLE_CONVERSION   0
#define ADC_FREE_RUNNING        1
#define ADC_ANALOG_COMPARATOR   2
#define ADC_EXTI0               3
#define ADC_TIM0_CTC            4
#define ADC_TIM0_OVF            5
#define ADC_TIM1_CTC_CHANNEL_B  6
#define ADC_TIM1_OVF            7
#define ADC_TIM1_ICU            8


#define ADC_PRE_2               0
#define ADC_PRE_4               2
#define ADC_PRE_8               3
#define ADC_PRE_16              4
#define ADC_PRE_32              5
#define ADC_PRE_64              6
#define ADC_PRE_128             7


typedef enum
{
	enuok,
	wrongchannel,
	TimeOutState,
	BUSY_STATE,
	NULL_POINTER
	
	
}Adc_tenu_ErrorStatus;


void ADC_voidInit             (void);
void ADC_u8GetResultSync ( u8 Copy_u8Channel , u16* Copy_pu16Result );
Adc_tenu_ErrorStatus ADC_u8StartConversionAsynch( u8 Copy_u8Channel , u16* Copy_pu16Reading , void(*Copy_pvNotificationFunc)(void) );
void ADC_voidEnable           (void);
void ADC_voidDisable          (void);
void ADC_voidInterruptEnable  (void);
void ADC_voidInterruptDisable (void);
u8 ADC_u8SetPrescaler (u8 Copy_u8Prescaler);



#endif /* MCAL_ADC_INCLUDES_ADC_H_ */
