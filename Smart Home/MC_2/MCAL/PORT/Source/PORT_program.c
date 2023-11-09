/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 20 Oct 2023                                                           */
/************************************************************************************/

#include "../../../LIB/Include/Std_types.h"
#include "../../../LIB/Include/Bit_utils.h"

#include "../Include/PORT_interface.h"
#include "../Include/PORT_private.h"
#include "../Include/PORT_config.h"


void PORT_voidInit(void)
{
	/* Initialization Direction for all Pins */
	// PORTA
	PORT_u8_DDRA_REG = CONC(PORT_u8_PA7_DIRECTION,PORT_u8_PA6_DIRECTION,PORT_u8_PA5_DIRECTION,PORT_u8_PA4_DIRECTION,
	                        PORT_u8_PA3_DIRECTION,PORT_u8_PA2_DIRECTION,PORT_u8_PA1_DIRECTION,PORT_u8_PA0_DIRECTION);
	// PORTB
	PORT_u8_DDRB_REG = CONC(PORT_u8_PB7_DIRECTION,PORT_u8_PB6_DIRECTION,PORT_u8_PB5_DIRECTION,PORT_u8_PB4_DIRECTION,
	                        PORT_u8_PB3_DIRECTION,PORT_u8_PB2_DIRECTION,PORT_u8_PB1_DIRECTION,PORT_u8_PB0_DIRECTION);
	// PORTC
	PORT_u8_DDRC_REG = CONC(PORT_u8_PC7_DIRECTION,PORT_u8_PC6_DIRECTION,PORT_u8_PC5_DIRECTION,PORT_u8_PC4_DIRECTION,
							PORT_u8_PC3_DIRECTION,PORT_u8_PC2_DIRECTION,PORT_u8_PC1_DIRECTION,PORT_u8_PC0_DIRECTION);
	// PORTD
	PORT_u8_DDRD_REG = CONC(PORT_u8_PD7_DIRECTION,PORT_u8_PD6_DIRECTION,PORT_u8_PD5_DIRECTION,PORT_u8_PD4_DIRECTION,
							PORT_u8_PD3_DIRECTION,PORT_u8_PD2_DIRECTION,PORT_u8_PD1_DIRECTION,PORT_u8_PD0_DIRECTION);
					
	/* Initialization Value for all Pins  */
	// PORTA
	PORT_u8_PORTA_REG = CONC(PORT_u8_PA7_VALUE,PORT_u8_PA6_VALUE,PORT_u8_PA5_VALUE,PORT_u8_PA4_VALUE,
							 PORT_u8_PA3_VALUE,PORT_u8_PA2_VALUE,PORT_u8_PA1_VALUE,PORT_u8_PA0_VALUE);
	// PORTB
	PORT_u8_PORTB_REG = CONC(PORT_u8_PB7_VALUE,PORT_u8_PB6_VALUE,PORT_u8_PB5_VALUE,PORT_u8_PB4_VALUE,
							 PORT_u8_PB3_VALUE,PORT_u8_PB2_VALUE,PORT_u8_PB1_VALUE,PORT_u8_PB0_VALUE);
	// PORTC
	PORT_u8_PORTC_REG = CONC(PORT_u8_PC7_VALUE,PORT_u8_PC6_VALUE,PORT_u8_PC5_VALUE,PORT_u8_PC4_VALUE,
							 PORT_u8_PC3_VALUE,PORT_u8_PC2_VALUE,PORT_u8_PC1_VALUE,PORT_u8_PC0_VALUE);
	// PORTD
	PORT_u8_PORTD_REG = CONC(PORT_u8_PD7_VALUE,PORT_u8_PD6_VALUE,PORT_u8_PD5_VALUE,PORT_u8_PD4_VALUE,
							 PORT_u8_PD3_VALUE,PORT_u8_PD2_VALUE,PORT_u8_PD1_VALUE,PORT_u8_PD0_VALUE);
}

PortEnum PORT_PortEnumSetPinDirection(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8Direction)
{
	PortEnum local_PortEnumErrorState = PORT_DIRECTION_OK;
	/* check about input parameters  */
	if((copy_u8PortId <= PORT_u8_PORTD) && (copy_u8PinId <= PORT_u8_PIN7))
	{
		/* step1: check about which port you want to configure */
		switch(copy_u8PortId)
		{
			case PORT_u8_PORTA:   // PORTA
			/* step2: check about which direction you want to configure */
			switch(copy_u8Direction)
			{
				case PORT_u8_OUTPUT: SET_BIT(PORT_u8_DDRA_REG,copy_u8PinId);     break;
				case PORT_u8_INPUT : CLR_BIT(PORT_u8_DDRA_REG,copy_u8PinId);     break;
			}
			break;
			case PORT_u8_PORTB:   // PORTB
			/* step2: check about which direction you want to configure */
			switch(copy_u8Direction)
			{
				case PORT_u8_OUTPUT: SET_BIT(PORT_u8_DDRB_REG,copy_u8PinId);     break;
				case PORT_u8_INPUT : CLR_BIT(PORT_u8_DDRB_REG,copy_u8PinId);     break;
			}
			break;
			case PORT_u8_PORTC:  // PORTC
			/* step2: check about which direction you want to configure */
			switch(copy_u8Direction)
			{
				case PORT_u8_OUTPUT: SET_BIT(PORT_u8_DDRC_REG,copy_u8PinId);     break;
				case PORT_u8_INPUT : CLR_BIT(PORT_u8_DDRC_REG,copy_u8PinId);     break;
			}
			break;
			case PORT_u8_PORTD:  // PORTD
			/* step2: check about which direction you want to configure */
			switch(copy_u8Direction)
			{
				case PORT_u8_OUTPUT: SET_BIT(PORT_u8_DDRD_REG,copy_u8PinId);     break;
				case PORT_u8_INPUT : CLR_BIT(PORT_u8_DDRD_REG,copy_u8PinId);     break;
			}
			break;
		}
	}
	else
	{
		local_PortEnumErrorState = PORT_DIRECTION_NOK;
	}
	return local_PortEnumErrorState;
}


PortEnum PORT_PortEnumSetPinMode(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8Mode)
{
	PortEnum local_PortEnumErrorState = PORT_MODE_OK;
	/* check about input parameters  */
	if((copy_u8PortId <= PORT_u8_PORTD) && (copy_u8PinId <= PORT_u8_PIN7))
	{
		/* step1: check about which port you want to configure */
		switch(copy_u8PortId)
		{
			case PORT_u8_PORTA:  // PORTA
			/* step2: check about which mode you want to configure */
			switch(copy_u8Mode)
			{
				case PORT_u8_HIGH     : SET_BIT(PORT_u8_PORTA_REG,copy_u8PinId);     break;
				case PORT_u8_LOW      : CLR_BIT(PORT_u8_PORTA_REG,copy_u8PinId);     break;
				case PORT_u8_PULLUP   : SET_BIT(PORT_u8_PORTA_REG,copy_u8PinId);     break;
				case PORT_u8_FLOATING : CLR_BIT(PORT_u8_PORTA_REG,copy_u8PinId);     break;
			}
			break;
			case PORT_u8_PORTB:  // PORTB
			/* step2: check about which mode you want to configure */
			switch(copy_u8Mode)
			{
				case PORT_u8_HIGH     : SET_BIT(PORT_u8_PORTB_REG,copy_u8PinId);     break;
				case PORT_u8_LOW      : CLR_BIT(PORT_u8_PORTB_REG,copy_u8PinId);     break;
				case PORT_u8_PULLUP   : SET_BIT(PORT_u8_PORTB_REG,copy_u8PinId);     break;
				case PORT_u8_FLOATING : CLR_BIT(PORT_u8_PORTB_REG,copy_u8PinId);     break;
			}
			break;
			case PORT_u8_PORTC:  // PORTC
			/* step2: check about which mode you want to configure */
			switch(copy_u8Mode)
			{
				case PORT_u8_HIGH     : SET_BIT(PORT_u8_PORTC_REG,copy_u8PinId);     break;
				case PORT_u8_LOW      : CLR_BIT(PORT_u8_PORTC_REG,copy_u8PinId);     break;
				case PORT_u8_PULLUP   : SET_BIT(PORT_u8_PORTC_REG,copy_u8PinId);     break;
				case PORT_u8_FLOATING : CLR_BIT(PORT_u8_PORTC_REG,copy_u8PinId);     break;
			}
			break;
			case PORT_u8_PORTD:  // PORTD
			/* step2: check about which mode you want to configure */
			switch(copy_u8Mode)
			{
				case PORT_u8_HIGH     : SET_BIT(PORT_u8_PORTD_REG,copy_u8PinId);     break;
				case PORT_u8_LOW      : CLR_BIT(PORT_u8_PORTD_REG,copy_u8PinId);     break;
				case PORT_u8_PULLUP   : SET_BIT(PORT_u8_PORTD_REG,copy_u8PinId);     break;
				case PORT_u8_FLOATING : CLR_BIT(PORT_u8_PORTD_REG,copy_u8PinId);     break;
			}
			break;
		}
	}
	else
	{
		local_PortEnumErrorState = PORT_MODE_NOK;
	}
	return local_PortEnumErrorState;
}
