/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 20 Oct 2023                                                           */
/************************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

typedef enum 
{
	DIO_WRITE_OK,
	DIO_WRITE_NOK,
	DIO_READ_OK,
	DIO_READ_NOK,
	DIO_WPORT_OK,
	DIO_WPORT_NOK,
	DIO_RPORT_OK,
	DIO_RPORT_NOK,
	DIO_FLIB_OK,
	DIO_FLIB_NOK,
}DioEnum; 

/* Macros for Ports  */
#define DIO_u8_PORTA              0
#define DIO_u8_PORTB              1
#define DIO_u8_PORTC              2
#define DIO_u8_PORTD              3

/* Macros for Pins   */
#define DIO_u8_PIN0               0
#define DIO_u8_PIN1               1
#define DIO_u8_PIN2               2
#define DIO_u8_PIN3               3
#define DIO_u8_PIN4               4
#define DIO_u8_PIN5               5
#define DIO_u8_PIN6               6
#define DIO_u8_PIN7               7

/* Macros for Pin Level   */
#define DIO_u8_HIGH               1
#define DIO_u8_LOW                0

DioEnum DIO_DioEnumWriteChannel(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8Level);

DioEnum DIO_DioEnumReadChannel(u8 copy_u8PortId,u8 copy_u8PinId,pu8 copy_pu8ReadChannel);

DioEnum DIO_DioEnumWritePort(u8 copy_u8PortId,u8 copy_u8Value);

DioEnum DIO_DioEnumReadPort(u8 copy_u8PortId,pu8 copy_pu8ReadPort);

DioEnum DIO_DioEnumFlibChannel(u8 copy_u8PortId,u8 copy_u8PinId);




#endif