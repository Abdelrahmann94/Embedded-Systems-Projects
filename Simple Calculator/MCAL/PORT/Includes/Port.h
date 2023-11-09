/*
 * Port.h
 */


#ifndef MCAL_PORT_INCLUDES_PORT_H_
#define MCAL_PORT_INCLUDES_PORT_H_



#define OUTPUT_LOW      0
#define OUTPUT_HIGH     1
#define INPUT_PULLUP    2
#define INPUT_FLOATING  3


#define OUT_PIN  1
#define IN_PIN   0

#define pin0  0
#define pin1  1
#define pin2  2
#define pin3  3
#define pin4  4
#define pin5  5
#define pin6  6
#define pin7  7
#define pin8  8
#define pin9  9
#define pin10 10
#define pin11 11
#define pin12 12
#define pin13 13
#define pin14 14
#define pin15 15
#define pin16 16
#define pin17 17
#define pin18 18
#define pin19 19
#define pin20 20
#define pin21 21
#define pin22 22
#define pin23 23
#define pin24 24
#define pin25 25
#define pin26 26
#define pin27 27
#define pin28 28
#define pin29 29
#define pin30 30
#define pin31 31

typedef enum{

	Port_enuOk,
	Port_enuPinError,
	Port_enuDirectionError

}Port_tenuErrorStatus;

void Port_init(void);
Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_Num , u8 Copy_PinDir);
Port_tenuErrorStatus SetPinMode (u8 Copy_Num , u8 Copy_mode );






#endif /* MCAL_PORT_INCLUDES_PORT_H_ */
