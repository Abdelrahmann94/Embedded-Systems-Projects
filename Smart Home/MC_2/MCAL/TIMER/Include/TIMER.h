/*
 * TIMER.h
 *
 * Created: 10/27/2023 12:27:14 PM
 *  Author: ASUS
 */ 


#ifndef TIMER_H_
#define TIMER_H_


typedef enum{
	TIMER0_OC,
	TIMER0_OV
}TIMER_Interrupt;



void Timer_Normalvoidinit(void);//done
void Timer_FASTPWMvoidinit(void);//done
void Timer_PhaseCorrectPWMvoidinit(void);//done
void Timer_setcallback(void(*copy_PF)(void),u8 copy_Timerindex);//done
void Timer_voidsetPWM(u8 copy_cmpvalue);//done
void Timer_getTimer1countervalue(u16 *copy_countervalue);//done
u8 Timer_getPWMonperiod(void);//done
u8 Timer_PWMtotalperiod(u32 *copy_totalperiod);
u8 Timer_getPWMdutycycle(void);
void ICUSW_voidEnable(void);
void ICUSW_voidDisable(void);
u8 ICUSW_u8Getonperiod(void);
u8 ICUSW_u8Gettotalperiod(void);
u8 ICUSW_u8Getduty(void);

typedef enum{
	ms16,
	ms32,
	ms65,
	s13,
	s26,
	s52,
	s100,
	s210
	}WDT_period;

void WDT_enable(WDT_period period);
void WDT_disable(void);

#endif /* TIMER_H_ */