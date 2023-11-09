/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 22 Oct 2023                                                           */
/************************************************************************************/
#include "../../../LIB/Include/Std_types.h"
#include "../../../LIB/Include/Bit_utils.h"

#include "../Include/EXTI_interface.h"
#include "../Include/EXTI_private.h"
#include "../Include/EXTI_config.h"

/* Array of Pointer to Function */
static void (*EXTI_Apf[3])(void);

EXTIEnum EXTI_EXTIEnumEnable(u8 copy_u8IntIndex,u8 copy_u8IntMode)
{
    EXTIEnum local_EXTIEnumErrorState = EXTI_Enable_OK;
    if((copy_u8IntIndex <= EXTI_u8_INT_2) && (copy_u8IntMode <= EXTI_u8_ON_CHANGE))
    {
        /* choosing which interrupt needed */
        switch(copy_u8IntIndex)
        {
            case EXTI_u8_INT_0:  // Interrupt 0
            /* choosing which mode needed */
            switch(copy_u8IntMode)
            {
                case EXTI_u8_RISING   :  // in case rising edge
                SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC00_BIT);
                SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC01_BIT);        break;
                case EXTI_u8_FALLING  : // in case falling edge
                CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC00_BIT);
                SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC01_BIT);        break;
                case EXTI_u8_LOW_LEVEL: // in case low level
                CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC00_BIT);
                CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC01_BIT);        break;
                case EXTI_u8_ON_CHANGE: // in case any logical change
                SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC00_BIT);
                CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC01_BIT);        break;
            }
            /* enable EXTI0 */
            SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT0_BIT);
            break;
            case EXTI_u8_INT_1:  // Interrupt 1
            switch(copy_u8IntMode)
            {
                case EXTI_u8_RISING   : // in case rising edge
                SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC10_BIT);
                SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC11_BIT);        break;
                case EXTI_u8_FALLING  : // in case falling edge
                CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC10_BIT);
                SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC11_BIT);        break;
                case EXTI_u8_LOW_LEVEL: // in case low level
                CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC10_BIT);
                CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC11_BIT);        break;
                case EXTI_u8_ON_CHANGE: // in case any logical change
                SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC10_BIT);
                CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC11_BIT);        break;
            }
            /* enable EXTI1 */
            SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT1_BIT);
            break;
            case EXTI_u8_INT_2:  // Interrupt 2
            switch(copy_u8IntMode)
            {
                case EXTI_u8_RISING   : // in case rising edge
                SET_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_ISC2_BIT);        break;
                case EXTI_u8_FALLING  : // in case falling edge
                CLR_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_ISC2_BIT);        break;
                default: local_EXTIEnumErrorState = EXTI_Enable_NOK; break;
            }
            /* enable EXTI2 */
            SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT2_BIT);
            break;
        }
    }
    else
    {
        local_EXTIEnumErrorState = EXTI_Enable_NOK;
    }
    return local_EXTIEnumErrorState;
}

EXTIEnum EXTI_EXTIEnumDisable(u8 copy_u8IntIndex)
{
    EXTIEnum local_EXTIEnumErrorState = EXTI_Disable_OK;
    if(copy_u8IntIndex <= EXTI_u8_INT_2)
    {
        switch(copy_u8IntIndex)
        {
            case EXTI_u8_INT_0:
            /* disable EXTI0 */
            CLR_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT0_BIT);       break;
            case EXTI_u8_INT_1:
            /* disable EXTI1 */
            CLR_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT1_BIT);       break;
            case EXTI_u8_INT_2:
            /* disable EXTI2 */
            CLR_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT2_BIT);       break;
        }
    }
    else
    {
        local_EXTIEnumErrorState = EXTI_Disable_NOK;
    }
    return local_EXTIEnumErrorState;
}

EXTIEnum EXTI_EXTIEnumSetCallback(u8 copy_u8IntIndex,void (*copy_pf)(void))
{
    EXTIEnum local_EXTIEnumErrorState = EXTI_Disable_OK;
    if((copy_u8IntIndex <= EXTI_u8_INT_2) && (copy_pf != NULL))
    {
        /* update the global pointer to function */
        EXTI_Apf[copy_u8IntIndex] = copy_pf;
    }
    else
    {
        local_EXTIEnumErrorState = EXTI_Disable_NOK;
    }
    return local_EXTIEnumErrorState;
}

/* ISR function for EXTI0 */
void __vector_1(void)     __attribute__((signal));
void __vector_1(void)
{
    if(EXTI_Apf[EXTI_u8_INT_0] != NULL)
    {
        /* call the global pointer to function */
        EXTI_Apf[EXTI_u8_INT_0]();
    }
}

/* ISR function for EXTI1 */
void __vector_2(void)     __attribute__((signal));
void __vector_2(void)
{
    if(EXTI_Apf[EXTI_u8_INT_1] != NULL)
    {
        /* call the global pointer to function */
        EXTI_Apf[EXTI_u8_INT_1]();
    }
}

/* ISR function for EXTI2 */
void __vector_3(void)     __attribute__((signal));
void __vector_3(void)
{
    if(EXTI_Apf[EXTI_u8_INT_2] != NULL)
    {
        /* call the global pointer to function */
        EXTI_Apf[EXTI_u8_INT_2]();
    }
}
