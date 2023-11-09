/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 28 Oct 2023                                                           */
/************************************************************************************/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/* configuration of the UART mode           */
/*      Options: UART_SYNCH_MODE
                 UART_ASYNCH_MODE          */
#define UART_u8_MODE       UART_ASYNCH_MODE 

/* configuration of the parity mode           */
/*      Options: UART_EVEN_PARITY
                 UART_ODD_PARITY 
                 UART_DISABLED_PARITY            */
#define UART_u8_PARITY_MODE       UART_DISABLED_PARITY 

/* configuration of the stop bit mode           */
/*      Options: UART_STOP_BIT_1
                 UART_STOP_BIT_2          */
#define UART_u8_STOP_MODE       UART_STOP_BIT_2 

/* configuration of the data bit           */
/*      Options: UART_DATA_5_BIT
                 UART_DATA_6_BIT 
                 UART_DATA_7_BIT
                 UART_DATA_8_BIT 
                 UART_DATA_9_BIT           */
#define UART_u8_DATA_BIT       UART_DATA_8_BIT 

#endif