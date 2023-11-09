/*
 * Keypad.h
 
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Port.h"
#include "Dio.h"

#define NOTPRESSED 0xff

void KPD_Init(void);
u8   KPD_u8GetPressed( void );

#define KPD_ROW_END    DIO_u8CHANNEL19
#define KPD_ROW_INIT  DIO_u8CHANNEL16

#define KPD_COL_END   DIO_u8CHANNEL27
#define KPD_COL_INIT  DIO_u8CHANNEL24


                         /* C0   C1  C2  C3  */
u8 KPD_u8Buttons[4][4] = { {'7','8','9','/'}, 
						   {'4','5','6','*'}, 
						   {'1','2','3','-'}, 
						   {'c','0','=','+'} };







#define KPD_R3   DIO_u8CHANNEL19  
#define KPD_R2   DIO_u8CHANNEL18 
#define KPD_R1   DIO_u8CHANNEL17
#define KPD_R0   DIO_u8CHANNEL16



#define KPD_C3  DIO_u8CHANNEL27
#define KPD_C2  DIO_u8CHANNEL26
#define KPD_C1  DIO_u8CHANNEL25
#define KPD_C0  DIO_u8CHANNEL24 



#endif /* KEYPAD_H_ */