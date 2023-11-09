/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 28 Oct 2023                                                           */
/************************************************************************************/

#include "../../../LIB/Include/Std_types.h"
#include "../../../LIB/Include/Bit_utils.h"

#include "../Include/UART_interface.h"
#include "../Include/UART_private.h"
#include "../Include/UART_config.h"

void UART_voidInit(void)
{
    u8 local_u8TempReg = 0x80;
    u16 local_u16BuadValue = 51;
    /* config boad rate */
    CLR_BIT(UART_u8_UCSRA_REG,UART_u8_U2X_BIT);
    UART_u8_UBRRL_REG = (u8)local_u16BuadValue;
    UART_u8_UBRRH_REG = (u8)(local_u16BuadValue>>8);
    /* disable to MPCM */
    CLR_BIT(UART_u8_UCSRA_REG,UART_u8_MPCM_BIT);
    /* config the UART mode */
    #if   UART_u8_MODE == UART_ASYNCH_MODE  // in case synch mode
        CLR_BIT(local_u8TempReg,UART_u8_UMSEL_BIT);
    #elif UART_u8_MODE == UART_SYNCH_MODE  // in case asynch mode
        SET_BIT(local_u8TempReg,UART_u8_UMSEL_BIT);
        CLR_BIT(local_u8TempReg,UART_u8_UCPOL_BIT);
    #endif
    /* config the parity mode */
    #if   UART_u8_PARITY_MODE == UART_EVEN_PARITY  // in case even parity
        CLR_BIT(local_u8TempReg,UART_u8_UPM0_BIT);
        SET_BIT(local_u8TempReg,UART_u8_UPM1_BIT);
    #elif UART_u8_PARITY_MODE == UART_ODD_PARITY  // in case odd parity
        SET_BIT(local_u8TempReg,UART_u8_UPM0_BIT);
        SET_BIT(local_u8TempReg,UART_u8_UPM1_BIT);
    #elif UART_u8_PARITY_MODE == UART_DISABLED_PARITY  // in case disabled
        CLR_BIT(local_u8TempReg,UART_u8_UPM0_BIT);
        CLR_BIT(local_u8TempReg,UART_u8_UPM1_BIT);
    #endif
    /* config the stop bit mode */
    #if   UART_u8_STOP_MODE == UART_STOP_BIT_1  // in case 1 bit
        CLR_BIT(local_u8TempReg,UART_u8_USBS_BIT);
    #elif UART_u8_STOP_MODE == UART_STOP_BIT_2  // in case 2 bit
        SET_BIT(local_u8TempReg,UART_u8_USBS_BIT);
    #endif
    /* config the data bit */
    #if   UART_u8_DATA_BIT == UART_DATA_5_BIT  // in case 5 bit data
        CLR_BIT(local_u8TempReg,UART_u8_UCSZ0_BIT);
        CLR_BIT(local_u8TempReg,UART_u8_UCSZ1_BIT);
        CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSZ2_BIT);
    #elif UART_u8_DATA_BIT == UART_DATA_6_BIT  // in case 6 bit data
        SET_BIT(local_u8TempReg,UART_u8_UCSZ0_BIT);
        CLR_BIT(local_u8TempReg,UART_u8_UCSZ1_BIT);
        CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSZ2_BIT);
    #elif UART_u8_DATA_BIT == UART_DATA_7_BIT  // in case 7 bit data
        CLR_BIT(local_u8TempReg,UART_u8_UCSZ0_BIT);
        SET_BIT(local_u8TempReg,UART_u8_UCSZ1_BIT);
        CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSZ2_BIT);
    #elif UART_u8_DATA_BIT == UART_DATA_8_BIT  // in case 8 bit data
        SET_BIT(local_u8TempReg,UART_u8_UCSZ0_BIT);
        SET_BIT(local_u8TempReg,UART_u8_UCSZ1_BIT);
        CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSZ2_BIT);
    #elif UART_u8_DATA_BIT == UART_DATA_9_BIT  // in case 9 bit data
        SET_BIT(local_u8TempReg,UART_u8_UCSZ0_BIT);
        SET_BIT(local_u8TempReg,UART_u8_UCSZ1_BIT);
        SET_BIT(UART_u8_UCSRB_REG,UART_u8_UCSZ2_BIT);
    #endif
    /* set local variable in the UCSRC register */
    UART_u8_UCSRC_REG = local_u8TempReg;
    /* Enable Transmitter and Receiver */
    SET_BIT(UART_u8_UCSRB_REG,UART_u8_TXEN_BIT);
    SET_BIT(UART_u8_UCSRB_REG,UART_u8_RXEN_BIT);
}

UARTEnum UART_UARTEnumSendData(u8 copy_u8Data)
{
    UARTEnum local_UARTEnumErrorState = UART_TX_OK;
    if(copy_u8Data <= 255)
    {
        /* wait until the register is empty */
        while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_UDRE_BIT) == 0);
        /* send the data */
        UART_u8_UDR_REG = copy_u8Data;
    }
    else
    {
        local_UARTEnumErrorState = UART_TX_NOK;
    }
    return local_UARTEnumErrorState;
}

UARTEnum UART_UARTEnumReceiveData(pu8 copy_pu8Data)
{
    UARTEnum local_UARTEnumErrorState = UART_RX_OK;
    if(copy_pu8Data != NULL)
    {
        /* wait until the receive is completed */
        while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_RXC_BIT) == 0);
        /* receive the data */
        *copy_pu8Data = UART_u8_UDR_REG ;
    }
    else
    {
        local_UARTEnumErrorState = UART_RX_NOK;
    }
    return local_UARTEnumErrorState;
}

UARTEnum UART_UARTEnumSendString(pu8 copy_pu8SendString)
{
    UARTEnum local_UARTEnumErrorState = UART_TXSTR_OK;
    u8 local_u8Count = 0;
    if(copy_pu8SendString != NULL)
    {
        /* wait until the register is empty */
        while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_UDRE_BIT) == 0);
        while(copy_pu8SendString[local_u8Count] != '\0')
        {
            /* send the data */
            UART_u8_UDR_REG = copy_pu8SendString[local_u8Count];
            /* wait until the transmitter is completed */
            while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_UDRE_BIT) == 0);
            local_u8Count++;
        }
    }
    else
    {
        local_UARTEnumErrorState = UART_TXSTR_NOK;
    }
    return local_UARTEnumErrorState;
}

UARTEnum UART_UARTEnumReceiveString(pu8 copy_pu8ReceiveString,u8 copy_u8StringLenth)
{
    UARTEnum local_UARTEnumErrorState = UART_RXSTR_OK;
    u8 local_u8Count = 0;
    if(copy_pu8ReceiveString != NULL)
    {
    	while(local_u8Count < copy_u8StringLenth)
    	{
			/* wait until the receive is completed */
			while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_RXC_BIT) == 0);
    		/* receive the data */
    		copy_pu8ReceiveString[local_u8Count] = UART_u8_UDR_REG;
    		local_u8Count++;
    	}
    }
    else
    {
        local_UARTEnumErrorState = UART_RXSTR_NOK;
    }
    return local_UARTEnumErrorState;
}

