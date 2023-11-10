/*
 * EXTI.h

 */ 


#ifndef EXTI_H_
#define EXTI_H_

/* 
 I assumed that EXTILINE0 , EXTILINE1 ,EXTILINE2 equal 6,7,5 because of their bits position in these registers (GICR,GIFR ....)	

 */
#define EXTI_LINE0   6
#define EXTI_LINE1   7
#define EXTI_LINE2   5

#define EXTI_FALLING_EDGE  0
#define EXTI_RISING_EDGE   1
#define EXTI_LOW_LEVEL     2
#define EXTI_ON_CHANGE     3

//#define NULL 0

void EXTI_voidInit              ( void );
void EXTI_voidSetTriggeringMode  ( u8 Copy_u8SenseMode , u8 Copy_u8Line  );
void EXTI_voidDisableInterrupt  ( u8 Copy_u8Line);
void EXTI_voidEnableInterrupt   ( u8 Copy_u8Line);
void EXTI_voidClearFlag         ( u8 Copy_u8Line );
void EXTI_voidSetCallBack       ( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine );
void GIE_INIT(void);






#endif /* EXTI_H_ */