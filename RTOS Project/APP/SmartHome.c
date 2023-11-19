
#include "Bit_utils.h"
#include "Std_types.h"
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "semphr.h"
#include "Port.h"
#include "Dio.h"
#include "lcdd_prv.h"
#include "lcdd_cfg.h"
#include "lcdd.h"
#include "ADC.h"
#include "KPD_interface.h"
#include "SmartHome.h"

/*functions prototypes*/
u8 CheckPassword(const u8* a_enteredPassword, const u8* a_userPassword);
void GetPassword(u8* a_ptr2input);


#define ENTER_BUTTON    '+'   /* button to enter the password */
#define RIGHT            1
#define WRONG            0

u8 Entered_password;
u8 password[10] ="1234";
u8 checked =0;
u8 pass_state=0; // password is right or wrong
u16 Result = 0; // output of Temperature sensor after conversion



/* Define Tasks Priorities */

#define  Display_Temp_PRIORITY  	3
#define  Login_PRIORITY			5
#define  systemInit_PRIORITY    	9
#define  Display_ADC			1

/*tasks codes prototypes */

void system_init ( void* pvParamter);
void Login( void* pvParamter);
void Display_Temp (void* pvParamter);
void Display_degree (void* pvParamter);
 
 
 /*Create Task Handles Create */
 xTaskHandle Task1Hand = NULL;
 xTaskHandle Task2Hand = NULL;
 xTaskHandle Task3Hand = NULL;
 xTaskHandle Task4Hand = NULL;

 int main(void)
{
	
	/*Create tasks*/
	xTaskCreate(system_init,(const signed char *)"Task1",200,NULL,systemInit_PRIORITY ,&Task1Hand);
	
	xTaskCreate(Login,(const signed char *)"Task2",200,NULL,Login_PRIORITY,&Task2Hand);
	
	xTaskCreate(Display_Temp,(const signed char *)"Task3",300,NULL,Display_Temp_PRIORITY,&Task3Hand);
	
	xTaskCreate(Display_degree,(const signed char *)"Task4",150,NULL,Display_ADC,&Task4Hand);

	/*start Scheduler */
	vTaskStartScheduler();

	/*Never Enter Here */
	return 0;
}

/*Task1 Code */

void system_init ( void* pvParamter){
	
	while (1){
		
		SetPinMode(0,INPUT_PULLUP);
		Port_enuSetPinDirection( RS , OUT_PIN);
		Port_enuSetPinDirection( EN , OUT_PIN);
		Port_enuSetPinDirection( pin8 , OUT_PIN);
		Port_enuSetPinDirection( pin9 , OUT_PIN);
		Port_enuSetPinDirection( pin10, OUT_PIN);
		Port_enuSetPinDirection( pin12 , OUT_PIN);
		
		sendCommand(LCD_4_BIT_2_LINES_INIT1_COMMAND);
		sendCommand(LCD_4_BIT_2_LINES_INIT2_COMMAND);
		sendCommand(LCD_4_BIT_2_LINES_SET_COMMAND);

		sendCommand(LCD_CURSOR_OFF_COMMAND);
		sendCommand(LCD_CLEAR_SCREEN_COMMAND);
		
		ADC_voidInit();
		KEYPAD_INIT();
		
		vTaskDelete(Task1Hand);
	}
}

 void Login( void* pvParamter){
	
	vTaskDelay(200);
	for (;;)
	{		
		if (checked == 0){   // if the password haven't been checked yet or it's wrong password
				LCD_moveCursor(1,1);
				displayString((u8 *) "Enter password");
				GetPassword(&Entered_password);
				pass_state = CheckPassword(&Entered_password,&password);
				LCD_clearScreen();
				vTaskDelay(500);
	}
		else {
			vTaskDelete(Task2Hand);
	}
		}
 }
 void Display_Temp( void* pvParamter){

	vTaskDelay(200);
	for (;;)
		{
			if (pass_state==RIGHT){  // if it's right password display temperature word and assign (checked) variable to 1
						
				LCD_moveCursor(1,1);
				displayString((u8 *)"temperature:");
						
				checked=1;
				vTaskDelay(portMAX_DELAY);
	
				}
			else if (pass_state==WRONG){ // if it's wrong password assign (checked) variable to 0 
				 checked=0;
				 vTaskDelay(500); // this state enters block state to initiate the login task
			}	
			}
	
		}

void Display_degree( void* pvParamter){

	vTaskDelay(200);

	while(1){
		
		if (checked==1){   // if entered password is checked and it's right display the result of temperature sensor after conversion
			
				LCD_moveCursor(2,5);
				ADC_u8GetResultSync(ADC_CHANNEL0,&Result);
				Result =   (Result *5000 ) /1024;
				Result =Result/10;
				SendNumber(Result);
		}
		else{
			vTaskDelay(500);
		}
		}
}


void GetPassword(u8* a_ptr2input)
{
	u8 LOC_byteCounter = 0;
	u8 LOC_pressedKey = '\0';

	LCD_moveCursor(3,1);

	do
	{
		LOC_pressedKey = KEYPAD_u8GetButton();

		if((LOC_pressedKey != '\0') && (LOC_pressedKey != ENTER_BUTTON))
		{
			*(a_ptr2input + LOC_byteCounter) = LOC_pressedKey;
			sendData('*');
			LOC_byteCounter++;

			LOC_pressedKey = KEYPAD_u8GetButton();
		}

	}while(LOC_pressedKey != ENTER_BUTTON);

	*(a_ptr2input + LOC_byteCounter) = '\0';
}


u8 CheckPassword(const u8* a_enteredPassword, const u8* a_userPassword)
{
	u8 LOC_passwordState = RIGHT;
	char LOC_byteCounter = 0;

	for(; (*(a_enteredPassword + LOC_byteCounter) != '\0') && (*(a_userPassword + LOC_byteCounter) != '\0'); LOC_byteCounter++)
	{
		if(*(a_enteredPassword + LOC_byteCounter) != *(a_userPassword + LOC_byteCounter))
		{
			LOC_passwordState = WRONG;
			break;
		}
	}

	if(*(a_enteredPassword + LOC_byteCounter) != *(a_userPassword + LOC_byteCounter))
	{
		LOC_passwordState = WRONG;
	}

	return LOC_passwordState;
}



