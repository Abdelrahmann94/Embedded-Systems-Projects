/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 29 Oct 2023                                                           */
/************************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

typedef enum{
    SPI_SR_BYTE_OK,
    SPI_SR_BYTE_NOK,
    SPI_SR_STRING_OK,
    SPI_SR_STRING_NOK,
}SPIEnum;

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
SPIEnum SPI_SPIEnumSendReceiveData(u8 copy_u8SendData,pu8 copy_pu8ReceiveData);
SPIEnum SPI_SPIEnumSendData(u8 copy_u8SendData);
SPIEnum SPI_SPIEnumReceiveData(pu8 copy_pu8ReceiveData);
SPIEnum SPI_SPIEnumSendReceiveString(pu8 copy_pu8SendString,pu8 copy_pu8ReceiveString);
SPIEnum SPI_SPIEnumSendString(pu8 copy_pu8SendString);
SPIEnum SPI_SPIEnumReceiveString(pu8 copy_pu8ReceiveString,u8 copy_u8StringLen);

#endif