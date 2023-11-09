/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 22 Oct 2023                                                           */
/************************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Registers Definition */
#define EXTI_u8_GICR_REG             *((volatile u8 *)0x5B)
#define EXTI_u8_GIFR_REG             *((volatile u8 *)0x5A)
#define EXTI_u8_MCUCR_REG            *((volatile u8 *)0x55)
#define EXTI_u8_MCUCSR_REG           *((volatile u8 *)0x54)

/* Macros for Register's Bits */
// MCUCR
#define EXTI_u8_ISC00_BIT             0
#define EXTI_u8_ISC01_BIT             1
#define EXTI_u8_ISC10_BIT             2
#define EXTI_u8_ISC11_BIT             3
// MCUCSR
#define EXTI_u8_ISC2_BIT              6
// GICR
#define EXTI_u8_INT2_BIT              5
#define EXTI_u8_INT0_BIT              6
#define EXTI_u8_INT1_BIT              7
// GIFR
#define EXTI_u8_INTF2_BIT              5
#define EXTI_u8_INTF0_BIT              6
#define EXTI_u8_INTF1_BIT              7


#endif