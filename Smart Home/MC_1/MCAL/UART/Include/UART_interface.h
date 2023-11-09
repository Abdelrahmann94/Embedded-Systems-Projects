/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 28 Oct 2023                                                           */
/************************************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

typedef enum{
    UART_TX_OK,
    UART_TX_NOK,
    UART_RX_OK,
    UART_RX_NOK,
    UART_TXSTR_OK,
    UART_TXSTR_NOK,
    UART_RXSTR_OK,
    UART_RXSTR_NOK,
}UARTEnum;

void UART_voidInit(void);
UARTEnum UART_UARTEnumSendData(uint8 copy_uint8Data);
UARTEnum UART_UARTEnumReceiveData(puint8 copy_puint8Data);
UARTEnum UART_UARTEnumSendString(puint8 copy_puint8String);
UARTEnum UART_UARTEnumReceiveString(puint8 copy_puint8ReceiveString,uint8 copy_uint8StringLenth);


#endif
