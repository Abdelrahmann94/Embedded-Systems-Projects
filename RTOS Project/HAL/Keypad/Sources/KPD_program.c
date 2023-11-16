#include "Std_types.h"
#include "Bit_utils.h"

#include "Port.h"
#include "Dio.h"

#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/**
 * This function writes the bits of the given pattern to the corresponding row pins of a keypad.
 * 
 * @param Copy_u8Patter represents the pattern of bits to be written to the keypad row pins. 
 * Each bit in the pattern corresponds to a specific row pin on the keypad.
 */
void KEYPAD_INIT(void){
	
	        Port_enuSetPinDirection(pin16,OUT_PIN);
	        Port_enuSetPinDirection(pin17,OUT_PIN);
	        Port_enuSetPinDirection(pin18,OUT_PIN);
	        Port_enuSetPinDirection(pin19,OUT_PIN);
	        
	        SetPinMode(pin24,INPUT_PULLUP);
	        SetPinMode(pin25,INPUT_PULLUP);
	        SetPinMode(pin26,INPUT_PULLUP);
	        SetPinMode(pin27,INPUT_PULLUP);
	
	
}

void static KEYPAD_prvWritePins(u8 Copy_u8Pattern){
	

    Dio_enuWriteChannel(KEYPAD_PIN_ROW_0, GET_BIT(Copy_u8Pattern, 0));
    Dio_enuWriteChannel(KEYPAD_PIN_ROW_1, GET_BIT(Copy_u8Pattern, 1));
    Dio_enuWriteChannel(KEYPAD_PIN_ROW_2, GET_BIT(Copy_u8Pattern, 2));
    Dio_enuWriteChannel(KEYPAD_PIN_ROW_3, GET_BIT(Copy_u8Pattern, 3));
}

/**
 * This function reads the values of the keypad column pins and stores them in a pattern variable.
 * 
 * @param Copy_pu8Pattern is a pointer to an unsigned 8-bit integer. It is used to
 * store the pattern read from the keypad pins.
 */
void static KEYPAD_prvReadPins(pu8 Copy_pu8Pattern){
    u8 temp = 0x00;
    *Copy_pu8Pattern = 0x00;
    Dio_enuReadChannel(KEYPAD_PIN_COL_0, &temp);
    *Copy_pu8Pattern |=  temp << 0;
    Dio_enuReadChannel(KEYPAD_PIN_COL_1, &temp);
    *Copy_pu8Pattern |=  temp << 1;
    Dio_enuReadChannel(KEYPAD_PIN_COL_2, &temp);
    *Copy_pu8Pattern |=  temp << 2;
    Dio_enuReadChannel(KEYPAD_PIN_COL_3, &temp);
    *Copy_pu8Pattern |=  temp << 3;
    if (*Copy_pu8Pattern != 0){
    	_delay_us(200);
    }
}

/**
 * This function reads the state of a keypad and returns the corresponding symbol
 * based on the pressed button.
 * 
 * @return the value of a variable, which represents the button that was pressed on the keypad.
 */
u8 KEYPAD_u8GetButton(void){

    u8 Local_u8PressedButton = 0x00;
    u8 Local_u8Symbol = 0x00 ;
    while (Local_u8Symbol == 0x00){
        for(int i = 0 ; i < 4 ; i++){
            KEYPAD_prvWritePins(TGLWITHOUTASSIGN_BIT(0x0F, i));
            KEYPAD_prvReadPins(&Local_u8PressedButton);
            //_delay_ms(5);
			vTaskDelay(5);
            switch (Local_u8PressedButton){
            case 0b00001110:
                Local_u8Symbol = SYMBOLS[(i*4) + 0]; break;
            case 0b00001101:
                Local_u8Symbol = SYMBOLS[(i*4) + 1]; break;
            case 0b00001011:
                Local_u8Symbol = SYMBOLS[(i*4) + 2]; break;
            case 0b00000111:
                Local_u8Symbol = SYMBOLS[(i*4) + 3]; break;
            }
        }
    }

    return Local_u8Symbol;
}