/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 28 Oct 2023                                                           */
/************************************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/* Regisrers Definition */
#define UART_u8_UDR_REG                 *((volatile u8 *)0x2C)
#define UART_u8_UBRRH_REG               *((volatile u8 *)0x40)
#define UART_u8_UBRRL_REG               *((volatile u8 *)0x29)
#define UART_u8_UCSRA_REG               *((volatile u8 *)0x2B)
#define UART_u8_UCSRB_REG               *((volatile u8 *)0x2A)
#define UART_u8_UCSRC_REG               *((volatile u8 *)0x40)

/* Macros for Register's Bits */
// UCSRA
#define UART_u8_MPCM_BIT               0
#define UART_u8_U2X_BIT                1
#define UART_u8_UDRE_BIT               5
#define UART_u8_TXC_BIT                6
#define UART_u8_RXC_BIT                7

/* Macros for Register's Bits */
// UCSRB
#define UART_u8_TXB8_BIT               0
#define UART_u8_RXB8_BIT               1
#define UART_u8_UCSZ2_BIT              2
#define UART_u8_TXEN_BIT               3
#define UART_u8_RXEN_BIT               4
#define UART_u8_UDRIE_BIT              5
#define UART_u8_TXCIE_BIT              6
#define UART_u8_RXCIE_BIT              7

/* Macros for Register's Bits */
// UCSRC
#define UART_u8_UCPOL_BIT               0
#define UART_u8_UCSZ0_BIT               1
#define UART_u8_UCSZ1_BIT               2
#define UART_u8_USBS_BIT                3
#define UART_u8_UPM0_BIT                4
#define UART_u8_UPM1_BIT                5
#define UART_u8_UMSEL_BIT               6
#define UART_u8_URSEL_BIT               7

/* macros for config mode */
#define UART_SYNCH_MODE           0
#define UART_ASYNCH_MODE          1

/* macros for config parity mode */
#define UART_EVEN_PARITY              0
#define UART_ODD_PARITY               1
#define UART_DISABLED_PARITY          2

/* macros for config stop mode */
#define UART_STOP_BIT_1          0
#define UART_STOP_BIT_2          1

/* macros for data bit */
#define UART_DATA_5_BIT          0
#define UART_DATA_6_BIT          1
#define UART_DATA_7_BIT          2
#define UART_DATA_8_BIT          3
#define UART_DATA_9_BIT          4

#endif