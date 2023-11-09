/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 20 Oct 2023                                                           */
/************************************************************************************/

#include "../../../LIB/Include/Std_types.h"
#include "../../../LIB/Include/Bit_utils.h"

#include "../Include/DIO_interface.h"
#include "../Include/DIO_private.h"
#include "../Include/DIO_config.h"

DioEnum DIO_DioEnumWriteChannel(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8Level)
{
	DioEnum local_DioEnumErrorState = DIO_WRITE_OK;
	/* check about input parameters  */
	if((copy_u8PortId <= DIO_u8_PORTD) && (copy_u8PinId <= DIO_u8_PIN7))
	{
		/* step1: check about which port you want to configure */
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:  // PORTA
			/* step2: check about which level you want to configure */
			switch(copy_u8Level)
			{
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTA_REG,copy_u8PinId);     break;
				case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTA_REG,copy_u8PinId);     break;
			}
			break;
			case DIO_u8_PORTB:  // PORTB
			/* step2: check about which level you want to configure */
			switch(copy_u8Level)
			{
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTB_REG,copy_u8PinId);     break;
				case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTB_REG,copy_u8PinId);     break;
			}
			break;
			case DIO_u8_PORTC:  // PORTC
			/* step2: check about which level you want to configure */
			switch(copy_u8Level)
			{
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTC_REG,copy_u8PinId);     break;
				case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTC_REG,copy_u8PinId);     break;
			}
			break;
			case DIO_u8_PORTD:  // PORTD
			/* step2: check about which level you want to configure */
			switch(copy_u8Level)
			{
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTD_REG,copy_u8PinId);     break;
				case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTD_REG,copy_u8PinId);     break;
			}
			break;
		}
	}
	else
	{
		local_DioEnumErrorState = DIO_WRITE_NOK;
	}
	return local_DioEnumErrorState;
}

DioEnum DIO_DioEnumReadChannel(u8 copy_u8PortId,u8 copy_u8PinId,pu8 copy_pu8ReadChannel)
{
	DioEnum local_DioEnumErrorState = DIO_READ_OK;
	/* local variable to store in value of the pin */
	u8 local_u8GetValue;
	/* check about input parameters  */
	if((copy_u8PortId <= DIO_u8_PORTD) && (copy_u8PinId <= DIO_u8_PIN7) && (copy_pu8ReadChannel != NULL))
	{
		/* step1: check about which port you want to read */
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:  // PORTA
			/* to get the pin value */
			local_u8GetValue = GET_BIT(DIO_u8_PINA_REG,copy_u8PinId);
			if(local_u8GetValue == 0)
			{
				*copy_pu8ReadChannel = DIO_u8_LOW;
			}
			else
			{
				*copy_pu8ReadChannel = DIO_u8_HIGH;
			}
			break;
			case DIO_u8_PORTB:  // PORTB
			/* to get the pin value */
			local_u8GetValue = GET_BIT(DIO_u8_PINB_REG,copy_u8PinId);
			if(local_u8GetValue == 0)
			{
				*copy_pu8ReadChannel = DIO_u8_LOW;
			}
			else
			{
				*copy_pu8ReadChannel = DIO_u8_HIGH;
			}
			break;
			case DIO_u8_PORTC:  // PORTC
			/* to get the pin value */
			local_u8GetValue = GET_BIT(DIO_u8_PINC_REG,copy_u8PinId);
			if(local_u8GetValue == 0)
			{
				*copy_pu8ReadChannel = DIO_u8_LOW;
			}
			else
			{
				*copy_pu8ReadChannel = DIO_u8_HIGH;
			}
			break;
			case DIO_u8_PORTD:  // PORTD
			/* to get the pin value */
			local_u8GetValue = GET_BIT(DIO_u8_PIND_REG,copy_u8PinId);
			if(local_u8GetValue == 0)
			{
				*copy_pu8ReadChannel = DIO_u8_LOW;
			}
			else
			{
				*copy_pu8ReadChannel = DIO_u8_HIGH;
			}
			break;
		}
	}
	else
	{
		local_DioEnumErrorState = DIO_READ_NOK;
	}
	return local_DioEnumErrorState;
}

DioEnum DIO_DioEnumWritePort(u8 copy_u8PortId,u8 copy_u8Value)
{
	DioEnum local_DioEnumErrorState = DIO_WPORT_OK;
	/* check about input parameters  */
	if(copy_u8PortId <= DIO_u8_PORTD)
	{
		/* check about which port you want to write into the value */
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA: DIO_u8_PORTA_REG = copy_u8Value;      break;
			case DIO_u8_PORTB: DIO_u8_PORTB_REG = copy_u8Value;      break;
			case DIO_u8_PORTC: DIO_u8_PORTC_REG = copy_u8Value;      break;
			case DIO_u8_PORTD: DIO_u8_PORTD_REG = copy_u8Value;      break;
		}
	}
	else
	{
		local_DioEnumErrorState = DIO_WPORT_NOK;
	}
	return local_DioEnumErrorState;
}

DioEnum DIO_DioEnumReadPort(u8 copy_u8PortId,pu8 copy_pu8ReadPort)
{
	DioEnum local_DioEnumErrorState = DIO_RPORT_OK;
	/* check about input parameters  */
	if((copy_u8PortId <= DIO_u8_PORTD) && (copy_pu8ReadPort != NULL))
	{
		/* check about which port you want to read this value */
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA: *copy_pu8ReadPort = DIO_u8_PINA_REG;      break;
			case DIO_u8_PORTB: *copy_pu8ReadPort = DIO_u8_PINB_REG;      break;
			case DIO_u8_PORTC: *copy_pu8ReadPort = DIO_u8_PINC_REG;      break;
			case DIO_u8_PORTD: *copy_pu8ReadPort = DIO_u8_PIND_REG;      break;
		}
	}
	else
	{
		local_DioEnumErrorState = DIO_RPORT_NOK;
	}
	return local_DioEnumErrorState;
}

DioEnum DIO_DioEnumFlibChannel(u8 copy_u8PortId,u8 copy_u8PinId)
{
	DioEnum local_DioEnumErrorState = DIO_FLIB_OK;
	/* check about input parameters  */
	if((copy_u8PortId <= DIO_u8_PORTD) && (copy_u8PinId <= DIO_u8_PIN7))
	{
		/* check about which port you want to TGLgle your pins */
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA: TGL_BIT(DIO_u8_PORTA_REG,copy_u8PinId);       break;
			case DIO_u8_PORTB: TGL_BIT(DIO_u8_PORTA_REG,copy_u8PinId);       break;
			case DIO_u8_PORTC: TGL_BIT(DIO_u8_PORTA_REG,copy_u8PinId);       break;
			case DIO_u8_PORTD: TGL_BIT(DIO_u8_PORTA_REG,copy_u8PinId);       break;
		}
	}
	else
	{
		local_DioEnumErrorState = DIO_FLIB_NOK;
	}
	return local_DioEnumErrorState;
}
