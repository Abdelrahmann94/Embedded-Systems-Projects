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
SPIEnum SPI_SPIEnumSendReceiveData(uint8 copy_uint8SendData,puint8 copy_puint8ReceiveData);
SPIEnum SPI_SPIEnumSendData(uint8 copy_uint8SendData);
SPIEnum SPI_SPIEnumReceiveData(puint8 copy_puint8ReceiveData);
SPIEnum SPI_SPIEnumSendReceiveString(puint8 copy_puint8SendString,puint8 copy_puint8ReceiveString);
SPIEnum SPI_SPIEnumSendString(puint8 copy_puint8SendString);
SPIEnum SPI_SPIEnumReceiveString(puint8 copy_puint8ReceiveString,uint8 copy_uint8StringLen);

#endif
