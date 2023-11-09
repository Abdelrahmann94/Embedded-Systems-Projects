
#include "../LIB/Include/std_types.h"
#include "../LIB/Include/common_macros.h"
#include "../LIB/Include/BIT_MATH.h"
#include "../MCAL/PORT/INCLUDES/port.h"
#include "../MCAL/DIO/INCLUDES/dio.h"
#include "../MCAL/I2C/INCLUDES/i2c.h"
#include "../MCAL/UART/Include/UART_interface.h"
#include "../MCAL/SPI/Include/SPI_interface.h"
#include "../HAL/LCD/INCLUDES/lcd.h"
#include "../HAL/KEYPAD/INCLUDES/keypad.h"
#include "../HAL/EEPROM/INCLUDES/eeprom.h"
#include "SmartHomeSystem.h"
//#define F_CPU     8000000UL
#include <util/delay.h>

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

static void (*G_ptr2runningFunction)(void) = NULL_PTR;
static UserType* G_ptr2headUser = NULL_PTR;
static uint8 G_wrongLoginCounter = 0;
uint8 Temp ;
uint8 Fan;
uint8 index =1;


int main(void)
{
    InitSystem();

    while(1)
    {
        if(G_ptr2runningFunction != NULL_PTR)
        {
            G_ptr2runningFunction();
        }
    }
}


// ====================================================================================================================
void InitSystem(void)
{
    PORT_init();
    UART_voidInit();
    SPI_voidSlaveInit();
    LCD_init();
	LCD_createCustomCharacter(customChar,index);
    I2C_init();
    InitDataBase();

    G_ptr2runningFunction = WelcomeMenu;
}

//=====================================================================================================================

void InitDataBase(void)
{
    UserData LOC_defaultUserData = {"1234","1234"};
	CreateNewUser(&LOC_defaultUserData);
}

//====================================================================================================================

void CreateNewUser(UserData* a_UserData)
{
	UserType* LOC_newUser = (UserType*)(calloc(1,sizeof(UserType)));

	if(LOC_newUser != NULL_PTR)
	{
		LOC_newUser->user_data = *a_UserData;

		if(G_ptr2headUser != NULL_PTR)
		{
			LOC_newUser->next = G_ptr2headUser;
		}
		else
		{
			LOC_newUser->next = NULL_PTR;
		}

		G_ptr2headUser = LOC_newUser;
	}

	else
	{
		/* Do Nothing. */
	}
}

//====================================================================================================================

void WelcomeMenu(void)
{
    LCD_displayStringRowColumn((uint8*)"Hello, World!",LCD_ROW_2_ID,LCD_COLUMN_04_ID);
    _delay_ms(1000);

    G_ptr2runningFunction = LoginMenu;
}


 //====================================================================================================================
void LoginMenu(void)
{
    UserData LOC_loginData;
    UserDataStateType LOC_loginDataState = WRONG;
    
    DisplayLoginMenu();
    GetUserName(LOC_loginData.user_name);
    GetPassword(LOC_loginData.password);

    LOC_loginDataState = CheckClientData(&LOC_loginData);

    switch (LOC_loginDataState)
    {
    case RIGHT:
        G_wrongLoginCounter = 0;
        G_ptr2runningFunction = ControlMenu;
        break;
    
    case WRONG:
    	G_wrongLoginCounter++;

        if(G_wrongLoginCounter == 3)
        {
            G_wrongLoginCounter = 0;
            G_ptr2runningFunction = BlockSystemMenu;
        }

        else
        {
            G_ptr2runningFunction = WrongPasswordMenu;
        }
        break;
    
    default:
        /* Do Nothing. */
        break;
    }
}

//=====================================================================================================================

void DisplayLoginMenu(void)
{
    LCD_clearScreen();

    LCD_displayStringRowColumn((uint8*)"Please Login..",LCD_ROW_1_ID,LCD_COLUMN_01_ID);
    LCD_displayStringRowColumn((uint8*)"User-name: ",LCD_ROW_3_ID,LCD_COLUMN_01_ID);
    LCD_displayStringRowColumn((uint8*)"Password : ",LCD_ROW_4_ID,LCD_COLUMN_01_ID);
}

//=====================================================================================================================

void GetUserName(uint8* a_ptr2input)
{
    uint8 LOC_byteCounter = 0;
	uint8 LOC_pressedKey = '\0';

	LCD_moveCursor(LCD_ROW_3_ID,LCD_COLUMN_12_ID);

	do
	{
		KEYPAD_getPressedKey(&LOC_pressedKey);

		if((LOC_pressedKey != '\0') && (LOC_pressedKey != ENTER_BUTTON))
		{
            *(a_ptr2input + LOC_byteCounter) = LOC_pressedKey;
			LCD_displayCharacter(LOC_pressedKey);
            LOC_byteCounter++;

            KEYPAD_getPressedKey(&LOC_pressedKey);
		}

	}while(LOC_pressedKey != ENTER_BUTTON);

	*(a_ptr2input + LOC_byteCounter) = '\0';
}

//=====================================================================================================================

void GetPassword(uint8* a_ptr2input)
{
    uint8 LOC_byteCounter = 0;
	uint8 LOC_pressedKey = '\0';

	LCD_moveCursor(LCD_ROW_4_ID,LCD_COLUMN_12_ID);

	do
	{
		KEYPAD_getPressedKey(&LOC_pressedKey);

		if((LOC_pressedKey != '\0') && (LOC_pressedKey != ENTER_BUTTON))
		{
            *(a_ptr2input + LOC_byteCounter) = LOC_pressedKey;
			LCD_displayCharacter('*');
            LOC_byteCounter++;

            KEYPAD_getPressedKey(&LOC_pressedKey);
		}

	}while(LOC_pressedKey != ENTER_BUTTON);

	*(a_ptr2input + LOC_byteCounter) = '\0';
}

//=====================================================================================================================

UserDataStateType CheckClientData(UserData* a_enteredData)
{
	UserDataStateType data_state = WRONG;

	UserData* ptr2User = FindUserData(a_enteredData->user_name);

	if(ptr2User != NULL_PTR)
	{
		UserDataStateType password_state = WRONG;
		password_state = CheckPassword(a_enteredData->password,ptr2User->password);

		if(password_state == RIGHT)
		{
			data_state = RIGHT;
		}
		else
		{
			/* Do Nothing. */
		}
	}
	else
	{
		/* Do Nothing. */
	}

	return data_state;
}

//=====================================================================================================================

{
	UserData* LOC_targetClientRecord = NULL_PTR;

	if(G_ptr2headUser != NULL_PTR)
	{
		UserType* LOC_currentRecord = G_ptr2headUser;
		while(LOC_currentRecord != NULL_PTR)
		{
			if(strcmp(LOC_currentRecord->user_data.user_name,a_username) == 0)
			{
				LOC_targetClientRecord = &LOC_currentRecord->user_data;
				break;
			}

			LOC_currentRecord = LOC_currentRecord->next;
		}
	}

	return LOC_targetClientRecord;
}

//=====================================================================================================================

UserDataStateType CheckPassword(const uint8* a_enteredPassword, const uint8* a_userPassword)
{
	UserDataStateType LOC_passwordState = RIGHT;
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

//----------------------------------------------------------------------------------------------------------------------
void ControlMenu(void)
{
    DispalyControlMenu();

    while(1); /* Just for the simulation, Remove it. */

    /* Receive user input from the keypad here. */
}

void DispalyControlMenu(void)
{
    LCD_clearScreen();
    LCD_displayStringRowColumn((uint8*)"Welcome Home",LCD_ROW_2_ID,LCD_COLUMN_04_ID);
    _delay_ms(1000);
    LCD_clearScreen();

	LCD_moveCursor(0,0);
	LCD_displayString ((uint8 *)"Fan speed:");

	//displaying the initial state of the leds
	LCD_moveCursor(1,0);
	LCD_displayString ((uint8 *)"Led1");
	LCD_moveCursor(1,6);
	LCD_displayString ((uint8 *)"led2");
	LCD_moveCursor(1,11);
	LCD_displayString ((uint8 *)"led3");

	LCD_moveCursor(2,0);
	LCD_displayString ((uint8 *)"off");
	LCD_moveCursor(2,6);
	LCD_displayString ((uint8 *)"off");
	LCD_moveCursor(2,11);
	LCD_displayString ((uint8 *)"off");
	uint8 button ='\0' ;
		

	
		do
		{
			SPI_SPIEnumReceiveData(&Fan);
			
			LCD_moveCursor(0,12);
			LCD_displayInteger(Fan);
			
			KEYPAD_getPressedKey(&button);
			
			//changing the state of the leds based on which button is pressed
			switch (button){

				case '1' :

					LCD_moveCursor(2,0);
					UART_UARTEnumSendData(1);
					LCD_displayString ((uint8 *)"on ");
					break;

				case '2' :

					LCD_moveCursor(2,0);
					UART_UARTEnumSendData(2);
					LCD_displayString ((uint8*)"off");
					break;

				case '3' :
					LCD_moveCursor(2,6);
					UART_UARTEnumSendData(3);
					LCD_displayString ((uint8 *)"on ");
					break;

				case '4' :

					LCD_moveCursor(2,6);
					UART_UARTEnumSendData(4);
					LCD_displayString ((uint8 *)"off");
					break;

				case '5' :

					LCD_moveCursor(2,11);
					UART_UARTEnumSendData(5);
					LCD_displayString ((uint8 *)"on ");
					break;

				case '6' :

					LCD_moveCursor(2,11);
					UART_UARTEnumSendData(6);
					LCD_displayString ((uint8 *)"off");
					break;


				default:
				break;
			}
		}while(button == '\0');
	}
}


void WrongPasswordMenu(void)
{
    LCD_clearScreen();

    for(uint8 iterator = 0; iterator < 3; iterator++)
    {
        LCD_displayStringRowColumn((uint8*)"Wrong Data!",LCD_ROW_2_ID,LCD_COLUMN_05_ID);
        _delay_ms(500);
        LCD_clearScreen();
        _delay_ms(500);
    }

    G_ptr2runningFunction = LoginMenu;
}

void BlockSystemMenu(void)
{
	LCD_clearScreen();

	LCD_displayStringRowColumn((uint8*)"System Is Blocked!",LCD_ROW_2_ID,LCD_COLUMN_01_ID);
	LCD_displayStringRowColumn((uint8*)"For 10 Minutes",LCD_ROW_3_ID,LCD_COLUMN_03_ID);

	_delay_ms(10000);

	G_ptr2runningFunction = LoginMenu;
}

