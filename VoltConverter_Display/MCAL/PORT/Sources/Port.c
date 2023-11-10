/*
 * Port.c
 */
#include "Bit_utils.h"
#include "Std_types.h"
#include "Port.h"
#include "Port_cfg.h"
#include "Port_prv.h"
#include <avr/io.h>


void Port_init (void){

#undef OUTPUT_LOW
#undef OUTPUT_HIGH
#undef INPUT_PULLUP
#undef INPUT_FLOATING

#define OUTPUT_LOW      1
#define OUTPUT_HIGH     1
#define INPUT_PULLUP    0
#define INPUT_FLOATING  0

DDRA = CONC(PORT_PinMode7, PORT_PinMode6, PORT_PinMode5, PORT_PinMode4, PORT_PinMode3, PORT_PinMode2, PORT_PinMode1, PORT_PinMode0);
DDRB = CONC(PORT_PinMode15,PORT_PinMode14,PORT_PinMode13,PORT_PinMode12,PORT_PinMode11, PORT_PinMode10, PORT_PinMode9, PORT_PinMode8);
DDRC = CONC(PORT_PinMode23,PORT_PinMode22,PORT_PinMode21,PORT_PinMode20,PORT_PinMode19, PORT_PinMode18, PORT_PinMode17, PORT_PinMode16);
DDRD = CONC(PORT_PinMode31,PORT_PinMode30,PORT_PinMode29,PORT_PinMode28,PORT_PinMode27, PORT_PinMode26, PORT_PinMode25, PORT_PinMode24);


#undef OUTPUT_LOW
#undef OUTPUT_HIGH
#undef INPUT_PULLUP
#undef INPUT_FLOATING

#define OUTPUT_LOW      0
#define OUTPUT_HIGH     1
#define INPUT_PULLUP    1
#define INPUT_FLOATING  0

PORTA = CONC(PORT_PinMode7,PORT_PinMode6,PORT_PinMode5,PORT_PinMode4,PORT_PinMode3,PORT_PinMode2,PORT_PinMode1,PORT_PinMode0);
PORTB = CONC(PORT_PinMode15,PORT_PinMode14,PORT_PinMode13,PORT_PinMode12,PORT_PinMode11,PORT_PinMode10,PORT_PinMode9,PORT_PinMode8);
PORTC = CONC(PORT_PinMode23,PORT_PinMode22,PORT_PinMode21,PORT_PinMode20,PORT_PinMode19,PORT_PinMode18,PORT_PinMode17,PORT_PinMode16);
PORTD = CONC(PORT_PinMode31,PORT_PinMode30,PORT_PinMode29,PORT_PinMode28,PORT_PinMode27,PORT_PinMode26,PORT_PinMode25,PORT_PinMode24);

#undef OUTPUT_LOW
#undef OUTPUT_HIGH
#undef INPUT_PULLUP
#undef INPUT_FLOATING

#define OUTPUT_LOW      0
#define OUTPUT_HIGH     1
#define INPUT_PULLUP    2
#define INPUT_FLOATING  3
}


/*IMPLEMENTING  "Port_enuSetPinDirection" FUNCTION WITH RETURNING DATATYPE "Port_tenuErrorStatus" and parameters "(u8 Copy_u8PinNum, u8 Copy_u8PinDirection)" */
Port_tenuErrorStatus Port_enuSetPinDirection(u8 PinNum , u8 PinDir) {

	/* INTIALIZING A VARIABLE CALLED "LOC_enuReturnStatus" OF DATATYPE "Port_tenuErrorStatus" */
	Port_tenuErrorStatus LOC_enuReturnStatus = Port_enuOk;

	/*DECLARING  LOCAL VARIABLE "LOC_u8Port" */
	u8 LOC_u8Port;

	/*DECLARING  LOCAL VARIABLE "LOC_u8Pin" */
	u8 LOC_u8Pin;

	/*CHECK IF "Copy_u8PinNum" IS GREATER THAN  NUMBER OF PINS OR NOT */
	if (PinNum > 31) {

		/*IF THE CONDITION IS TRUE THEN THE VARIABLE WHICH IS CALLED "LOC_enuReturnStatus " IS EQUAL "Port_enuPinError" */
		LOC_enuReturnStatus = Port_enuPinError;

		/* CHECK IF "Copy_u8PinDirection" IS GREATER THAN  NUMBER OF DIRECTION OR NOT*/
	} else if (PinDir> 1) {

		/*IF THE CONDITION IS TRUE THEN THE VARIABLE WHICH IS CALLED "LOC_enuReturnStatus " IS EQUAL "Port_enuDirectionError" */
		LOC_enuReturnStatus = Port_enuDirectionError;

		/* IF THE TWO PERVIOUS CONDITIONS ARE FALSE THEN... */
	} else {

		/* CALCULATE THIS EQUATION TO  DETECT "Copy_u8PinNum" ON WHICH PORT (A,B,C,D)*/
		LOC_u8Port = PinNum / 8;

		/*CALCULATE THIS EQUATION TO DETECT "Copy_u8PinNum" ON WHICH PIN (0,1,2,3,4,5,6,7)*/
		LOC_u8Pin = PinNum % 8;

		/*SWITCH BETWEEN CASES ACCORDING PORT*/
		switch (LOC_u8Port) {

		/*CASE 0  IF PIN IS ON PORTA*/
		case 0:

			/*CHECK IF THE DIRECTION OF THE GIVEN PIN IS OUTPUT OR NOT*/
			if (PinDir == 1) {

				/*IF THE CONDITION IS TRUE SET THE DDRA BIT TO BE OUTPUT FOR PIN "LOC_u8Pin" */
				SET_BIT(DDRA, LOC_u8Pin);

			} else {

				/*IF THE CONDITION IS NOT TRUE CLEAR THE DDRA BIT TO BE INPUT FOR PIN "LOC_u8Pin" */
				CLR_BIT(DDRA, LOC_u8Pin);
			}
			break;

			/*CASE 1  IF PIN IS ON PORTB*/
		case 1:

			/*CHECK IF THE DIRECTION OF THE GIVEN PIN IS OUTPUT OR NOT*/
			if (PinDir == 1) {

				/*IF THE CONDITION IS TRUE SET THE DDRB BIT TO BE OUTPUT FOR PIN "LOC_u8Pin" */
				SET_BIT(DDRB, LOC_u8Pin);

			} else {

				/*IF THE CONDITION IS NOT TRUE CLEAR THE DDRB BIT TO BE INPUT FOR PIN "LOC_u8Pin" */
				CLR_BIT(DDRB, LOC_u8Pin);
			}

			break;
			/*CASE 2  IF PIN IS ON PORTC*/
		case 2:

			/*CHECK IF THE DIRECTION OF THE GIVEN PIN IS OUTPUT OR NOT*/
			if (PinDir == 1) {

				/*IF THE CONDITION IS TRUE SET THE DDRC BIT TO BE OUTPUT FOR PIN "LOC_u8Pin" */
				SET_BIT(DDRC, LOC_u8Pin);

			} else {

				/*IF THE CONDITION IS NOT TRUE CLEAR THE DDRC BIT TO BE INPUT FOR PIN "LOC_u8Pin" */
				CLR_BIT(DDRC, LOC_u8Pin);

			}

			break;
			/*CASE 3  IF PIN IS ON PORTD*/
		case 3:

			/*CHECK IF THE DIRECTION OF THE GIVEN PIN IS OUTPUT OR NOT*/
			if (PinDir == 1) {

				/*IF THE CONDITION IS TRUE SET THE DDRD BIT TO BE OUTPUT FOR PIN "LOC_u8Pin" */
				SET_BIT(DDRD, LOC_u8Pin);

			} else {

				/*IF THE CONDITION IS NOT TRUE CLEAR THE DDRD BIT TO BE INPUT FOR PIN "LOC_u8Pin" */
				CLR_BIT(DDRD, LOC_u8Pin);

			}

			break;
		}
	}

	/*RETURN ERROR STATUS*/
	return LOC_enuReturnStatus;
}

Port_tenuErrorStatus SetPinMode (u8 Num , u8 mode ){

	Port_tenuErrorStatus LOC_enuReturnStatus = Port_enuOk;
	u8 Pin_port= Num / 8;
    u8 Pin_Num = Num % 8;
    switch (Pin_port){

    case 0:
        if (mode == 0){
            SET_BIT(DDRA,Pin_Num);
            CLR_BIT(PORTA,Pin_Num);}

        else if (mode == 1){
            SET_BIT(DDRA,Pin_Num);
            SET_BIT(PORTA,Pin_Num);}

        else if (mode == 2){
            CLR_BIT(DDRA,Pin_Num);
            SET_BIT(PORTA,Pin_Num);}

        else if (mode == 3){
            CLR_BIT(DDRA,Pin_Num);
            CLR_BIT(PORTA,Pin_Num);
        }
        break;
    case 1:
       if (mode == 0){
            SET_BIT(DDRB,Pin_Num);
            CLR_BIT(PORTB,Pin_Num);}

         else if (mode == 1){
            SET_BIT(DDRB,Pin_Num);
            SET_BIT(PORTB,Pin_Num);}

        else if (mode == 2){
            CLR_BIT(DDRB,Pin_Num);
            SET_BIT(PORTB,Pin_Num);}

         else if (mode == 3){
            CLR_BIT(DDRB,Pin_Num);
            CLR_BIT(PORTB,Pin_Num);
        }
        break;

    case 2:
        if (mode == 0){
            SET_BIT(DDRC,Pin_Num);
            CLR_BIT(PORTC,Pin_Num);
		}

        else if (mode == 1){
            SET_BIT(DDRC,Pin_Num);
            SET_BIT(PORTC,Pin_Num);}

        else if (mode == 2){
            CLR_BIT(PORTC,Pin_Num);
            SET_BIT(PORTC,Pin_Num);}

        else if (mode == 3){
            CLR_BIT(DDRC,Pin_Num);
            CLR_BIT(PORTC,Pin_Num);
        }
         break;

    case 3:
       if (mode == 0){
            SET_BIT(DDRD,Pin_Num);
            CLR_BIT(PORTD,Pin_Num);}

        else if (mode == 1){
            SET_BIT(DDRD,Pin_Num);
            SET_BIT(PORTD,Pin_Num);}

       else if (mode == 2){
            CLR_BIT(DDRD,Pin_Num);
            SET_BIT(PORTD,Pin_Num);}

        else if (mode == 3){
            CLR_BIT(DDRD,Pin_Num);
            CLR_BIT(PORTD,Pin_Num);
        }
        break;

    default :
        break;
    }
return LOC_enuReturnStatus;
}



