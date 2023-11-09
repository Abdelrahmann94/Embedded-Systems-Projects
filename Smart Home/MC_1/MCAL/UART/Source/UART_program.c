/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 28 Oct 2023                                                           */
/************************************************************************************/

#include "../../../LIB/Include/std_types.h"
#include "../../../LIB/Include/BIT_MATH.h"

#include "../Include/UART_interface.h"
#include "../Include/UART_private.h"
#include "../Include/UART_config.h"

void UART_voidInit(void)
{
    uint8 local_uint8TempReg = 0x80;
    uint16 local_uint16BuadValue = 51;
    /* config boad rate */
    CLR_BIT(UART_uint8_UCSRA_REG,UART_uint8_U2X_BIT);
    UART_uint8_UBRRL_REG = (uint8)local_uint16BuadValue;
    UART_uint8_UBRRH_REG = (uint8)(local_uint16BuadValue>>8);
    /* disable to MPCM */
    CLR_BIT(UART_uint8_UCSRA_REG,UART_uint8_MPCM_BIT);
    /* config the UART mode */
    #if   UART_uint8_MODE == UART_ASYNCH_MODE  // in case synch mode
        CLR_BIT(local_uint8TempReg,UART_uint8_UMSEL_BIT);
    #elif UART_uint8_MODE == UART_SYNCH_MODE  // in case asynch mode
        SET_BIT(local_uint8TempReg,UART_uint8_UMSEL_BIT);
        CLR_BIT(local_uint8TempReg,UART_uint8_UCPOL_BIT);
    #endif
    /* config the parity mode */
    #if   UART_uint8_PARITY_MODE == UART_EVEN_PARITY  // in case even parity
        CLR_BIT(local_uint8TempReg,UART_uint8_UPM0_BIT);
        SET_BIT(local_uint8TempReg,UART_uint8_UPM1_BIT);
    #elif UART_uint8_PARITY_MODE == UART_ODD_PARITY  // in case odd parity
        SET_BIT(local_uint8TempReg,UART_uint8_UPM0_BIT);
        SET_BIT(local_uint8TempReg,UART_uint8_UPM1_BIT);
    #elif UART_uint8_PARITY_MODE == UART_DISABLED_PARITY  // in case disabled
        CLR_BIT(local_uint8TempReg,UART_uint8_UPM0_BIT);
        CLR_BIT(local_uint8TempReg,UART_uint8_UPM1_BIT);
    #endif
    /* config the stop bit mode */
    #if   UART_uint8_STOP_MODE == UART_STOP_BIT_1  // in case 1 bit
        CLR_BIT(local_uint8TempReg,UART_uint8_USBS_BIT);
    #elif UART_uint8_STOP_MODE == UART_STOP_BIT_2  // in case 2 bit
        SET_BIT(local_uint8TempReg,UART_uint8_USBS_BIT);
    #endif
    /* config the data bit */
    #if   UART_uint8_DATA_BIT == UART_DATA_5_BIT  // in case 5 bit data
        CLR_BIT(local_uint8TempReg,UART_uint8_UCSZ0_BIT);
        CLR_BIT(local_uint8TempReg,UART_uint8_UCSZ1_BIT);
        CLR_BIT(UART_uint8_UCSRB_REG,UART_uint8_UCSZ2_BIT);
    #elif UART_uint8_DATA_BIT == UART_DATA_6_BIT  // in case 6 bit data
        SET_BIT(local_uint8TempReg,UART_uint8_UCSZ0_BIT);
        CLR_BIT(local_uint8TempReg,UART_uint8_UCSZ1_BIT);
        CLR_BIT(UART_uint8_UCSRB_REG,UART_uint8_UCSZ2_BIT);
    #elif UART_uint8_DATA_BIT == UART_DATA_7_BIT  // in case 7 bit data
        CLR_BIT(local_uint8TempReg,UART_uint8_UCSZ0_BIT);
        SET_BIT(local_uint8TempReg,UART_uint8_UCSZ1_BIT);
        CLR_BIT(UART_uint8_UCSRB_REG,UART_uint8_UCSZ2_BIT);
    #elif UART_uint8_DATA_BIT == UART_DATA_8_BIT  // in case 8 bit data
        SET_BIT(local_uint8TempReg,UART_uint8_UCSZ0_BIT);
        SET_BIT(local_uint8TempReg,UART_uint8_UCSZ1_BIT);
        CLR_BIT(UART_uint8_UCSRB_REG,UART_uint8_UCSZ2_BIT);
    #elif UART_uint8_DATA_BIT == UART_DATA_9_BIT  // in case 9 bit data
        SET_BIT(local_uint8TempReg,UART_uint8_UCSZ0_BIT);
        SET_BIT(local_uint8TempReg,UART_uint8_UCSZ1_BIT);
        SET_BIT(UART_uint8_UCSRB_REG,UART_uint8_UCSZ2_BIT);
    #endif
    /* set local variable in the UCSRC register */
    UART_uint8_UCSRC_REG = local_uint8TempReg;
    /* Enable Transmitter and Receiver */
    SET_BIT(UART_uint8_UCSRB_REG,UART_uint8_TXEN_BIT);
    SET_BIT(UART_uint8_UCSRB_REG,UART_uint8_RXEN_BIT);
}

UARTEnum UART_UARTEnumSendData(uint8 copy_uint8Data)
{
    UARTEnum local_UARTEnumErrorState = UART_TX_OK;
    if(copy_uint8Data <= 255)
    {
        /* wait until the register is empty */
        while(GET_BIT(UART_uint8_UCSRA_REG,UART_uint8_UDRE_BIT) == 0);
        /* send the data */
        UART_uint8_UDR_REG = copy_uint8Data;
    }
    else
    {
        local_UARTEnumErrorState = UART_TX_NOK;
    }
    return local_UARTEnumErrorState;
}

UARTEnum UART_UARTEnumReceiveData(puint8 copy_puint8Data)
{
    UARTEnum local_UARTEnumErrorState = UART_RX_OK;
    if(copy_puint8Data != NULL_PTR)
    {
        /* wait until the receive is completed */
        while(GET_BIT(UART_uint8_UCSRA_REG,UART_uint8_RXC_BIT) == 0);
        /* receive the data */
        *copy_puint8Data = UART_uint8_UDR_REG ;
    }
    else
    {
        local_UARTEnumErrorState = UART_RX_NOK;
    }
    return local_UARTEnumErrorState;
}

UARTEnum UART_UARTEnumSendString(puint8 copy_puint8SendString)
{
    UARTEnum local_UARTEnumErrorState = UART_TXSTR_OK;
    uint8 local_uint8Count = 0;
    if(copy_puint8SendString != NULL_PTR)
    {
        /* wait until the register is empty */
        while(GET_BIT(UART_uint8_UCSRA_REG,UART_uint8_UDRE_BIT) == 0);
        while(copy_puint8SendString[local_uint8Count] != '\0')
        {
            /* send the data */
            UART_uint8_UDR_REG = copy_puint8SendString[local_uint8Count];
            /* wait until the transmitter is completed */
            while(GET_BIT(UART_uint8_UCSRA_REG,UART_uint8_UDRE_BIT) == 0);
            local_uint8Count++;
        }
    }
    else
    {
        local_UARTEnumErrorState = UART_TXSTR_NOK;
    }
    return local_UARTEnumErrorState;
}

UARTEnum UART_UARTEnumReceiveString(puint8 copy_puint8ReceiveString,uint8 copy_uint8StringLenth)
{
    UARTEnum local_UARTEnumErrorState = UART_RXSTR_OK;
    uint8 local_uint8Count = 0;
    if(copy_puint8ReceiveString != NULL_PTR)
    {
    	while(local_uint8Count < copy_uint8StringLenth)
    	{
			/* wait until the receive is completed */
			while(GET_BIT(UART_uint8_UCSRA_REG,UART_uint8_RXC_BIT) == 0);
    		/* receive the data */
    		copy_puint8ReceiveString[local_uint8Count] = UART_uint8_UDR_REG;
    		local_uint8Count++;
    	}
    }
    else
    {
        local_UARTEnumErrorState = UART_RXSTR_NOK;
    }
    return local_UARTEnumErrorState;
}

