/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 20 Oct 2023                                                           */
/************************************************************************************/
#ifndef PORT_INTERFACE_H
#define PORT_INTERFACE_H

typedef enum 
{
	PORT_DIRECTION_OK,
	PORT_DIRECTION_NOK,
	PORT_MODE_OK,
	PORT_MODE_NOK,
}PortEnum; 

/* Macros for Ports  */
#define PORT_u8_PORTA              0
#define PORT_u8_PORTB              1
#define PORT_u8_PORTC              2
#define PORT_u8_PORTD              3

/* Macros for Pins   */
#define PORT_u8_PIN0               0
#define PORT_u8_PIN1               1
#define PORT_u8_PIN2               2
#define PORT_u8_PIN3               3
#define PORT_u8_PIN4               4
#define PORT_u8_PIN5               5
#define PORT_u8_PIN6               6
#define PORT_u8_PIN7               7

/* Macros for Pin Direction  */
#define PORT_u8_OUTPUT             1
#define PORT_u8_INPUT              0

/* Macros for Pin Mode   */
#define PORT_u8_LOW                0
#define PORT_u8_HIGH               1
#define PORT_u8_PULLUP             2
#define PORT_u8_FLOATING           3

void PORT_voidInit(void);

PortEnum PORT_PortEnumSetPinDirection(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8Direction);

PortEnum PORT_PortEnumSetPinMode(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8Mode);

#endif