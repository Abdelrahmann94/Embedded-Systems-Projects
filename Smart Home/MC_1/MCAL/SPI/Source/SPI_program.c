/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 29 Oct 2023                                                           */
/************************************************************************************/

#include "../../../LIB/Include/std_types.h"
#include "../../../LIB/Include/BIT_MATH.h"

#include "../Include/SPI_interface.h"
#include "../Include/SPI_private.h"
#include "../Include/SPI_config.h"

void SPI_voidMasterInit(void)
{
    /* select the clk prescaler */
    #if   SPI_uint8_CLK_PRESCALING == SPI_CLK_PRESC_4
        CLR_BIT(SPI_uint8_SPCR_REG,SPI_uint8_SPR0_BIT);
        CLR_BIT(SPI_uint8_SPCR_REG,SPI_uint8_SPR1_BIT);
    #elif SPI_uint8_CLK_PRESCALING == SPI_CLK_PRESC_16
        SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_SPR0_BIT);
        CLR_BIT(SPI_uint8_SPCR_REG,SPI_uint8_SPR1_BIT);
    #elif SPI_uint8_CLK_PRESCALING == SPI_CLK_PRESC_64
        CLR_BIT(SPI_uint8_SPCR_REG,SPI_uint8_SPR0_BIT);
        SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_SPR1_BIT);
    #elif SPI_uint8_CLK_PRESCALING == SPI_CLK_PRESC_128
        SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_SPR0_BIT);
        SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_SPR1_BIT);
    #endif
    /* select the clock phase */
    #if   SPI_uint8_CLOCK_PHASE == SPI_SAMPLE_SETUP
        CLR_BIT(SPI_uint8_SPCR_REG,SPI_uint8_CPHA_BIT);
    #elif SPI_uint8_CLOCK_PHASE == SPI_SETUP_SAMPLE
        SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_CPHA_BIT);
    #endif
    /* select the clock polarity */
    #if   SPI_uint8_CLOCK_POLARITY == SPI_RISING_FALLING
        CLR_BIT(SPI_uint8_SPCR_REG,SPI_uint8_CPOL_BIT);
    #elif SPI_uint8_CLOCK_POLARITY == SPI_FALLING_RISING
        SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_CPOL_BIT);
    #endif
    /* select the shifting register */
    #if   SPI_uint8_SHIFTING_MODE == SPI_SHIFTING_LSB
        SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_DORD_BIT);
    #elif SPI_uint8_SHIFTING_MODE == SPI_SHIFTING_MSB
        CLR_BIT(SPI_uint8_SPCR_REG,SPI_uint8_DORD_BIT);
    #endif
    /* initial as master */
    SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_MSTR_BIT);
    /* enable SPI */
    SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_SPE_BIT);
}

void SPI_voidSlaveInit(void)
{
    /* select the clock phase */
    #if   SPI_uint8_CLOCK_PHASE == SPI_SAMPLE_SETUP
        CLR_BIT(SPI_uint8_SPCR_REG,SPI_uint8_CPHA_BIT);
    #elif SPI_uint8_CLOCK_PHASE == SPI_SETUP_SAMPLE
        SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_CPHA_BIT);
    #endif
    /* select the clock polarity */
    #if   SPI_uint8_CLOCK_POLARITY == SPI_RISING_FALLING
        CLR_BIT(SPI_uint8_SPCR_REG,SPI_uint8_CPOL_BIT);
    #elif SPI_uint8_CLOCK_POLARITY == SPI_FALLING_RISING
        SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_CPOL_BIT);
    #endif
    /* select the shifting register */
    #if   SPI_uint8_SHIFTING_MODE == SPI_SHIFTING_LSB
        SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_DORD_BIT);
    #elif SPI_uint8_SHIFTING_MODE == SPI_SHIFTING_MSB
        CLR_BIT(SPI_uint8_SPCR_REG,SPI_uint8_DORD_BIT);
    #endif
    /* initial as slave */
    CLR_BIT(SPI_uint8_SPCR_REG,SPI_uint8_MSTR_BIT);
    /* enable SPI */
    SET_BIT(SPI_uint8_SPCR_REG,SPI_uint8_SPE_BIT);
}
SPIEnum SPI_SPIEnumSendReceiveData(uint8 copy_uint8SendData,puint8 copy_puint8ReceiveData)
{
    SPIEnum local_uint8SPIEnumErrorState = SPI_SR_BYTE_OK;
    uint16 local_uint16TimeCount = 0;
    if((copy_uint8SendData <= 255) && (copy_puint8ReceiveData != NULL_PTR))
    {
        /* send the Data */
        SPI_uint8_SPDR_REG = copy_uint8SendData;
        /*  wait until transmition is completed => non blocking mechanism*/
        while((GET_BIT(SPI_uint8_SPSR_REG,SPI_uint8_SPIF_BIT)==0) && (local_uint16TimeCount < SPI_TIME_OUT))
        {
            local_uint16TimeCount++;
        }
        /* receive the data */
        *copy_puint8ReceiveData = SPI_uint8_SPDR_REG;
    }
    else
    {
        local_uint8SPIEnumErrorState = SPI_SR_BYTE_NOK;
    }
    return local_uint8SPIEnumErrorState;
}

SPIEnum SPI_SPIEnumSendData(uint8 copy_uint8SendData)
{
    SPIEnum local_uint8SPIEnumErrorState = SPI_SR_BYTE_OK;
    uint16 local_uint16TimeCount = 0;
    if(copy_uint8SendData <= 255)
    {
        /* send the Data */
        SPI_uint8_SPDR_REG = copy_uint8SendData;
        /*  wait until transmition is completed => non blocking mechanism*/
        while((GET_BIT(SPI_uint8_SPSR_REG,SPI_uint8_SPIF_BIT)==0) && (local_uint16TimeCount < SPI_TIME_OUT))
        {
            local_uint16TimeCount++;
        }
    }
    else
    {
        local_uint8SPIEnumErrorState = SPI_SR_BYTE_NOK;
    }
    return local_uint8SPIEnumErrorState;
}

SPIEnum SPI_SPIEnumReceiveData(puint8 copy_puint8ReceiveData)
{
    SPIEnum local_uint8SPIEnumErrorState = SPI_SR_BYTE_OK;
    uint16 local_uint16TimeCount = 0;
    if(copy_puint8ReceiveData != NULL_PTR)
    {
        /*  wait until transmition is completed => non blocking mechanism*/
        while((GET_BIT(SPI_uint8_SPSR_REG,SPI_uint8_SPIF_BIT)==0) && (local_uint16TimeCount < SPI_TIME_OUT))
        {
            local_uint16TimeCount++;
        }
        /* receive the data */
        *copy_puint8ReceiveData = SPI_uint8_SPDR_REG;
    }
    else
    {
        local_uint8SPIEnumErrorState = SPI_SR_BYTE_NOK;
    }
    return local_uint8SPIEnumErrorState;
}

SPIEnum SPI_SPIEnumSendReceiveString(puint8 copy_puint8SendString,puint8 copy_puint8ReceiveString)
{
    SPIEnum local_uint8SPIEnumErrorState = SPI_SR_STRING_OK;
    uint8 local_uint8SendCounter = 0;
    uint16 local_uint16TimeCounter = 0;
    if((copy_puint8SendString != NULL_PTR) && (copy_puint8ReceiveString != NULL_PTR))
    {
        /* send the string */
        while(copy_puint8SendString[local_uint8SendCounter] != '\0')
        {
            SPI_uint8_SPDR_REG = copy_puint8SendString[local_uint8SendCounter];
            /*  wait until transmition is completed => non blocking mechanism*/
            while((GET_BIT(SPI_uint8_SPSR_REG,SPI_uint8_SPIF_BIT)==0) && (local_uint16TimeCounter < SPI_TIME_OUT))
            {
                local_uint16TimeCounter++;
            }
            copy_puint8ReceiveString[local_uint8SendCounter] = SPI_uint8_SPDR_REG;
            local_uint8SendCounter++;
        }
    }
    else
    {
        local_uint8SPIEnumErrorState = SPI_SR_STRING_NOK;
    }
    return local_uint8SPIEnumErrorState;
}

SPIEnum SPI_SPIEnumSendString(puint8 copy_puint8SendString)
{
    SPIEnum local_uint8SPIEnumErrorState = SPI_SR_STRING_OK;
    uint8 local_uint8SendCounter = 0;
    uint16 local_uint16TimeCounter = 0;
    if(copy_puint8SendString != NULL_PTR)
    {
        /* send the string */
        while(copy_puint8SendString[local_uint8SendCounter] != '\0')
        {
            SPI_uint8_SPDR_REG = copy_puint8SendString[local_uint8SendCounter];
            /*  wait until transmition is completed => non blocking mechanism*/
            while((GET_BIT(SPI_uint8_SPSR_REG,SPI_uint8_SPIF_BIT)==0) && (local_uint16TimeCounter < SPI_TIME_OUT))
            {
                local_uint16TimeCounter++;
            }
            local_uint8SendCounter++;
        }
    }
    else
    {
        local_uint8SPIEnumErrorState = SPI_SR_STRING_NOK;
    }
    return local_uint8SPIEnumErrorState;
}
SPIEnum SPI_SPIEnumReceiveString(puint8 copy_puint8ReceiveString,uint8 copy_uint8StringLen)
{
    SPIEnum local_uint8SPIEnumErrorState = SPI_SR_STRING_OK;
    uint8 local_uint8ReceiveCounter = 0;
    uint16 local_uint16TimeCounter = 0;
    if(copy_puint8ReceiveString != NULL_PTR)
    {
   	while(local_uint8ReceiveCounter < copy_uint8StringLen)
    {
    	/*  wait until transmition is completed => non blocking mechanism*/
    	while((GET_BIT(SPI_uint8_SPSR_REG,SPI_uint8_SPIF_BIT)==0) && (local_uint16TimeCounter < SPI_TIME_OUT))
    	{
    		local_uint16TimeCounter++;
    	}
    	copy_puint8ReceiveString[local_uint8ReceiveCounter] = SPI_uint8_SPDR_REG;
    	local_uint8ReceiveCounter++;
    }
    }
    else
    {
        local_uint8SPIEnumErrorState = SPI_SR_STRING_NOK;
    }
    return local_uint8SPIEnumErrorState;
}
