/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 29 Oct 2023                                                           */
/************************************************************************************/

#include "../../../LIB/Include/Std_types.h"
#include "../../../LIB/Include/Bit_utils.h"

#include "../Include/SPI_interface.h"
#include "../Include/SPI_private.h"
#include "../Include/SPI_config.h"

void SPI_voidMasterInit(void)
{
    /* select the clk prescaler */
    #if   SPI_u8_CLK_PRESCALING == SPI_CLK_PRESC_4
        CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
        CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
    #elif SPI_u8_CLK_PRESCALING == SPI_CLK_PRESC_16
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
        CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
    #elif SPI_u8_CLK_PRESCALING == SPI_CLK_PRESC_64
        CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
    #elif SPI_u8_CLK_PRESCALING == SPI_CLK_PRESC_128
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT);
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT);
    #endif
    /* select the clock phase */
    #if   SPI_u8_CLOCK_PHASE == SPI_SAMPLE_SETUP
        CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_CPHA_BIT);
    #elif SPI_u8_CLOCK_PHASE == SPI_SETUP_SAMPLE
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_CPHA_BIT);
    #endif
    /* select the clock polarity */
    #if   SPI_u8_CLOCK_POLARITY == SPI_RISING_FALLING
        CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_CPOL_BIT);
    #elif SPI_u8_CLOCK_POLARITY == SPI_FALLING_RISING
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_CPOL_BIT);
    #endif
    /* select the shifting register */
    #if   SPI_u8_SHIFTING_MODE == SPI_SHIFTING_LSB
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_DORD_BIT);
    #elif SPI_u8_SHIFTING_MODE == SPI_SHIFTING_MSB
        CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_DORD_BIT);
    #endif
    /* initial as master */
    SET_BIT(SPI_u8_SPCR_REG,SPI_u8_MSTR_BIT);
    /* enable SPI */
    SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPE_BIT);
}

void SPI_voidSlaveInit(void)
{
    /* select the clock phase */
    #if   SPI_u8_CLOCK_PHASE == SPI_SAMPLE_SETUP
        CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_CPHA_BIT);
    #elif SPI_u8_CLOCK_PHASE == SPI_SETUP_SAMPLE
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_CPHA_BIT);
    #endif
    /* select the clock polarity */
    #if   SPI_u8_CLOCK_POLARITY == SPI_RISING_FALLING
        CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_CPOL_BIT);
    #elif SPI_u8_CLOCK_POLARITY == SPI_FALLING_RISING
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_CPOL_BIT);
    #endif
    /* select the shifting register */
    #if   SPI_u8_SHIFTING_MODE == SPI_SHIFTING_LSB
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_DORD_BIT);
    #elif SPI_u8_SHIFTING_MODE == SPI_SHIFTING_MSB
        CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_DORD_BIT);
    #endif
    /* initial as slave */
    CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_MSTR_BIT);
    /* enable SPI */
    SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPE_BIT);
}
SPIEnum SPI_SPIEnumSendReceiveData(u8 copy_u8SendData,pu8 copy_pu8ReceiveData)
{
    SPIEnum local_u8SPIEnumErrorState = SPI_SR_BYTE_OK;
    u16 local_u16TimeCount = 0;
    if((copy_u8SendData <= 255) && (copy_pu8ReceiveData != NULL))
    {
        /* send the Data */
        SPI_u8_SPDR_REG = copy_u8SendData;
        /*  wait until transmition is completed => non blocking mechanism*/
        while((GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT)==0) && (local_u16TimeCount < SPI_TIME_OUT))
        {
            local_u16TimeCount++;
        }
        /* receive the data */
        *copy_pu8ReceiveData = SPI_u8_SPDR_REG;
    }
    else
    {
        local_u8SPIEnumErrorState = SPI_SR_BYTE_NOK;
    }
    return local_u8SPIEnumErrorState;
}

SPIEnum SPI_SPIEnumSendData(u8 copy_u8SendData)
{
    SPIEnum local_u8SPIEnumErrorState = SPI_SR_BYTE_OK;
    u16 local_u16TimeCount = 0;
    if(copy_u8SendData <= 255)
    {
        /* send the Data */
        SPI_u8_SPDR_REG = copy_u8SendData;
        /*  wait until transmition is completed => non blocking mechanism*/
        while((GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT)==0) && (local_u16TimeCount < SPI_TIME_OUT))
        {
            local_u16TimeCount++;
        }
    }
    else
    {
        local_u8SPIEnumErrorState = SPI_SR_BYTE_NOK;
    }
    return local_u8SPIEnumErrorState;
}

SPIEnum SPI_SPIEnumReceiveData(pu8 copy_pu8ReceiveData)
{
    SPIEnum local_u8SPIEnumErrorState = SPI_SR_BYTE_OK;
    u16 local_u16TimeCount = 0;
    if(copy_pu8ReceiveData != NULL)
    {
        /*  wait until transmition is completed => non blocking mechanism*/
        while((GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT)==0) && (local_u16TimeCount < SPI_TIME_OUT))
        {
            local_u16TimeCount++;
        }
        /* receive the data */
        *copy_pu8ReceiveData = SPI_u8_SPDR_REG;
    }
    else
    {
        local_u8SPIEnumErrorState = SPI_SR_BYTE_NOK;
    }
    return local_u8SPIEnumErrorState;
}

SPIEnum SPI_SPIEnumSendReceiveString(pu8 copy_pu8SendString,pu8 copy_pu8ReceiveString)
{
    SPIEnum local_u8SPIEnumErrorState = SPI_SR_STRING_OK;
    u8 local_u8SendCounter = 0;
    u16 local_u16TimeCounter = 0;
    if((copy_pu8SendString != NULL) && (copy_pu8ReceiveString != NULL))
    {
        /* send the string */
        while(copy_pu8SendString[local_u8SendCounter] != '\0')
        {
            SPI_u8_SPDR_REG = copy_pu8SendString[local_u8SendCounter];
            /*  wait until transmition is completed => non blocking mechanism*/
            while((GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT)==0) && (local_u16TimeCounter < SPI_TIME_OUT))
            {
                local_u16TimeCounter++;
            }
            copy_pu8ReceiveString[local_u8SendCounter] = SPI_u8_SPDR_REG;
            local_u8SendCounter++;
        }
    }
    else
    {
        local_u8SPIEnumErrorState = SPI_SR_STRING_NOK;
    }
    return local_u8SPIEnumErrorState;
}

SPIEnum SPI_SPIEnumSendString(pu8 copy_pu8SendString)
{
    SPIEnum local_u8SPIEnumErrorState = SPI_SR_STRING_OK;
    u8 local_u8SendCounter = 0;
    u16 local_u16TimeCounter = 0;
    if(copy_pu8SendString != NULL)
    {
        /* send the string */
        while(copy_pu8SendString[local_u8SendCounter] != '\0')
        {
            SPI_u8_SPDR_REG = copy_pu8SendString[local_u8SendCounter];
            /*  wait until transmition is completed => non blocking mechanism*/
            while((GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT)==0) && (local_u16TimeCounter < SPI_TIME_OUT))
            {
                local_u16TimeCounter++;
            }
            local_u8SendCounter++;
        }
    }
    else
    {
        local_u8SPIEnumErrorState = SPI_SR_STRING_NOK;
    }
    return local_u8SPIEnumErrorState;
}
SPIEnum SPI_SPIEnumReceiveString(pu8 copy_pu8ReceiveString,u8 copy_u8StringLen)
{
    SPIEnum local_u8SPIEnumErrorState = SPI_SR_STRING_OK;
    u8 local_u8ReceiveCounter = 0;
    u16 local_u16TimeCounter = 0;
    if(copy_pu8ReceiveString != NULL)
    {
   	while(local_u8ReceiveCounter < copy_u8StringLen)
    {
    	/*  wait until transmition is completed => non blocking mechanism*/
    	while((GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT)==0) && (local_u16TimeCounter < SPI_TIME_OUT))
    	{
    		local_u16TimeCounter++;
    	}
    	copy_pu8ReceiveString[local_u8ReceiveCounter] = SPI_u8_SPDR_REG;
    	local_u8ReceiveCounter++;
    }
    }
    else
    {
        local_u8SPIEnumErrorState = SPI_SR_STRING_NOK;
    }
    return local_u8SPIEnumErrorState;
}
