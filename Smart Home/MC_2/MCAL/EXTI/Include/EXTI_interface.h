/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 22 Oct 2023                                                           */
/************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum{
    EXTI_Enable_OK,
    EXTI_Enable_NOK,
    EXTI_Disable_OK,
    EXTI_Disable_NOK,
    EXTI_Callback_OK,
    EXTI_Callback_NOK,
}EXTIEnum;

/* Choosing Interrupt Index */
#define EXTI_u8_INT_0           0
#define EXTI_u8_INT_1           1
#define EXTI_u8_INT_2           2

/* Choosing Interrupt Mode */
#define EXTI_u8_RISING            0
#define EXTI_u8_FALLING           1
#define EXTI_u8_LOW_LEVEL         2
#define EXTI_u8_ON_CHANGE         3

EXTIEnum EXTI_EXTIEnumEnable(u8 copy_u8IntIndex,u8 copy_u8IntMode);
EXTIEnum EXTI_EXTIEnumDisable(u8 copy_u8IntIndex);
EXTIEnum EXTI_EXTIEnumSetCallback(u8 copy_u8IntIndex,void (*copy_pf)(void));


#endif