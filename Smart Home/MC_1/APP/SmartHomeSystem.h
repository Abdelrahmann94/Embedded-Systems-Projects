/*
=======================================================================================================================
Author       : Mamoun
Module       : 
File Name    : SmartHomeSystem.h
Date Created : Nov 3, 2023
Description  : 
=======================================================================================================================
*/


#ifndef APP_SMARTHOMESYSTEM_H_
#define APP_SMARTHOMESYSTEM_H_

/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/



/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define ENTER_BUTTON                    'D'

/*=====================================================================================================================
                                       < Shared Global Variables >
=====================================================================================================================*/



/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
	uint8 user_name[20];
	uint8 password[20];
}UserData;

typedef struct admin
{
	UserData user_data;
	struct admin* next;
}UserType;

typedef enum
{
	WRONG,RIGHT
}UserDataStateType;

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/



/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

void InitSystem(void);
void InitDataBase(void);
void CreateNewUser(UserData* a_UserData);
void WelcomeMenu(void);
void LoginMenu(void);
void DisplayLoginMenu(void);
void GetUserName(uint8* a_ptr2input);
void GetPassword(uint8* a_ptr2input);
UserDataStateType CheckClientData(UserData* a_enteredData);
UserData* FindUserData(uint8* a_username);
UserDataStateType CheckPassword(const uint8* a_enteredPassword, const uint8* a_userPassword);
void ControlMenu(void);
void DispalyControlMenu(void);
void WrongPasswordMenu(void);
void BlockSystemMenu(void);

#endif /* APP_SMARTHOMESYSTEM_H_ */
