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
UARTEnum UART_UARTEnumSendData(u8 copy_u8Data);
UARTEnum UART_UARTEnumReceiveData(pu8 copy_pu8Data);
UARTEnum UART_UARTEnumSendString(pu8 copy_pu8String);
UARTEnum UART_UARTEnumReceiveString(pu8 copy_pu8ReceiveString,u8 copy_u8StringLenth);


#endif