/*
 * TIMER.c
 *
 * Created: 10/27/2023 12:26:56 PM
 *  Author: ASUS
 */ 
#include "../../../LIB/Include/Std_types.h"
#include "../../../LIB/Include/Bit_utils.h"
#include "../Include/MemMap.h"
#include "../Include/TIMER.h"

//static void (*TIMER0_OC_Fptr) (void)=NULL;
static void (*TIMER0_OV_Fptr) (void)=NULL;

void Timer_Normalvoidinit(void){
	TCCR0=0b00000101;
	TIMSK=0b00000011;
}
void Timer_FASTPWMvoidinit(void){
	TCCR0=0b01111010;
	TIMSK=0b00000011;
}
void Timer_PhaseCorrectPWMvoidinit(void){
	TCCR0=0b01110010;
	TIMSK=0b00000011;
}

void Timer_voidsetPWM(u8 copy_cmpvalue){
	OCR0=copy_cmpvalue;
}
void Timer_getTimer1countervalue(u16 *copy_countervalue){
	*copy_countervalue=TCNT0;
}
u8 Timer_getPWMonperiod(void){
	return OCR0;
}
u8 Timer_getPWMdutycycle(){
	
		u16 timeon=OCR0*100;
		
	u8 duty=(u16)timeon/255;
	duty=100-duty;
	return duty;
}
//void Timer_setcallback(void(*copy_PF)(void),TIMER_Interrupt copy_Timerindex){
//
//	switch(copy_Timerindex){
//		case TIMER0_OC:
//		TIMER0_OC_Fptr=copy_PF;
//		break;
//		case TIMER0_OV:
//		TIMER0_OV_Fptr=copy_PF;
//		break;
//
//	}
//}


//void WDT_enable(WDT_period period){
//	WDTCR|=period;
//	SET_BIT(WDTCR,WDE);
//}
//void WDT_disable(void){
//	WDTCR=0xC0;
//}




ISR(TIMER0_OV_vect)
{
	if (*TIMER0_OV_Fptr!=NULL)
	{
		TIMER0_OV_Fptr();
	}
	
 }








// void ICUSW_voidEnable(void){
// 	
// 	EXI_Enable(EX_INT0);
// 	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
// 	while(flagT!=2);
// 		t1=TCNT0+(counter*256);
// 	   EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
// 	   counter=0;
// 	while(flagT!=3);
// 		t2=TCNT0+(counter*256);
// }
