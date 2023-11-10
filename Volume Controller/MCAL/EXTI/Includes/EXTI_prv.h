/*
 * EXTI_prv.h
 */ 


#ifndef EXTI_PRV_H_
#define EXTI_PRV_H_


#define MCUCR_REG   *((volatile u8 *)0x55)
#define MCUCSR_REG  *((volatile u8 *)0x54)
#define GICR  *((volatile u8 *)0x5b)
#define GIFR    *((volatile u8 *)0x5A)
#define SREG		*((volatile u8 *)0x5F)
#define ENABLE_GIE     1
#define DISABLE_GIE     0
//#define NULL 0


#endif /* EXTI_PRV_H_ */