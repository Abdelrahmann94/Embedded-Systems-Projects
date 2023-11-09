/*
=======================================================================================================================
Author       : Mamoun
Module       : Keypad
File Name    : keypad.c
Date Created : Oct 23, 2023
Description  : Source file for the keypad driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../LIB/Include/std_types.h"
#include "../../../LIB/Include/common_macros.h"
#include "../../../MCAL/DIO/INCLUDES/dio.h"
#include "../INCLUDES/keypad_prv.h"
#include "../INCLUDES/keypad_cfg.h"
#include "../INCLUDES/keypad.h"

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

#if(KEYPAD_NUM_OF_COLUMNS == KEYPAD_3_COLUMNS_SIZE)

static uint8 LOC_columnsPinsID[KEYPAD_NUM_OF_COLUMNS] = {KEYPAD_COL0_PIN_ID,KEYPAD_COL1_PIN_ID,KEYPAD_COL2_PIN_ID};
static uint8 g_keypad_sympols[KEYPAD_NUM_OF_ROWS][KEYPAD_NUM_OF_COLUMNS] = {{KEYPAD_ROW0_COL0_SYMPOL,KEYPAD_ROW0_COL1_SYMPOL,KEYPAD_ROW0_COL2_SYMPOL},
                                                                            {KEYPAD_ROW1_COL0_SYMPOL,KEYPAD_ROW1_COL1_SYMPOL,KEYPAD_ROW1_COL2_SYMPOL},
                                                                            {KEYPAD_ROW2_COL0_SYMPOL,KEYPAD_ROW2_COL1_SYMPOL,KEYPAD_ROW2_COL2_SYMPOL},
                                                                            {KEYPAD_ROW3_COL0_SYMPOL,KEYPAD_ROW3_COL1_SYMPOL,KEYPAD_ROW3_COL2_SYMPOL}};

#elif(KEYPAD_NUM_OF_COLUMNS == KEYPAD_4_COLUMNS_SIZE)

static uint8 LOC_columnsPinsID[KEYPAD_NUM_OF_COLUMNS] = {KEYPAD_COL0_PIN_ID,KEYPAD_COL1_PIN_ID,KEYPAD_COL2_PIN_ID,KEYPAD_COL3_PIN_ID};
static uint8 g_keypad_sympols[KEYPAD_NUM_OF_ROWS][KEYPAD_NUM_OF_COLUMNS] = {{KEYPAD_ROW0_COL0_SYMPOL,KEYPAD_ROW0_COL1_SYMPOL,KEYPAD_ROW0_COL2_SYMPOL,KEYPAD_ROW0_COL3_SYMPOL},
                                                                            {KEYPAD_ROW1_COL0_SYMPOL,KEYPAD_ROW1_COL1_SYMPOL,KEYPAD_ROW1_COL2_SYMPOL,KEYPAD_ROW1_COL3_SYMPOL},
                                                                            {KEYPAD_ROW2_COL0_SYMPOL,KEYPAD_ROW2_COL1_SYMPOL,KEYPAD_ROW2_COL2_SYMPOL,KEYPAD_ROW2_COL3_SYMPOL},
                                                                            {KEYPAD_ROW3_COL0_SYMPOL,KEYPAD_ROW3_COL1_SYMPOL,KEYPAD_ROW3_COL2_SYMPOL,KEYPAD_ROW3_COL3_SYMPOL}};

#endif

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : KEYPAD_getPressedKey
 * [Description]   : Scan the keypad matrix and return the pressed key value.
 * [Arguments]     : <a_ptr2keyValue>      -> Pointer to variable to store the pressed key value.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void KEYPAD_getPressedKey(uint8* a_ptr2keyValue)
{
    *a_ptr2keyValue = '\0';
    KEYPAD_buttonStatus LOC_ButtonState = KEYPAD_NOT_PRESSED;

    for(uint8 rows_iterator = 0; rows_iterator < KEYPAD_NUM_OF_ROWS; rows_iterator++)
    {
    	KEYPAD_writeRowsPattern(rows_iterator);

    	for(uint8 columns_iterator = 0; columns_iterator < KEYPAD_NUM_OF_COLUMNS; columns_iterator++)
    	{
    		DIO_readPin(KEYPAD_COLS_PORT_ID,*(LOC_columnsPinsID + columns_iterator),(DIO_pinStatus*)&LOC_ButtonState);

    		if(LOC_ButtonState == KEYPAD_PRESSED)
    		{
    			while(LOC_ButtonState == KEYPAD_PRESSED)
    			{
    				DIO_readPin(KEYPAD_COLS_PORT_ID,*(LOC_columnsPinsID + columns_iterator),(DIO_pinStatus*)&LOC_ButtonState);
    			}

    			*a_ptr2keyValue = *(*(g_keypad_sympols + rows_iterator) + columns_iterator);
    			return;
    		}

    		else
    		{
    			/* Do Nothing. */
    		}
    	}
    }
}

static void KEYPAD_writeRowsPattern(uint8 a_index)
{
    #if(KEYPAD_CONNECTION_TYPE == KEYPAD_PULLUP_CONNECTION)

    uint8 LOC_rowsPattern = KEYPAD_CREATE_PATTERN_PULLUP(a_index);

    #elif(KEYPAD_CONNECTION_TYPE == KEYPAD_PULLDOWN_CONNECTION)

    uint8 LOC_rowsPattern = KEYPAD_CREATE_PATTERN_PULLDOWN(a_index);

    #endif

    DIO_writePin(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW0_PIN_ID,GET_BIT(LOC_rowsPattern,0));
    DIO_writePin(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW1_PIN_ID,GET_BIT(LOC_rowsPattern,1));
    DIO_writePin(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW2_PIN_ID,GET_BIT(LOC_rowsPattern,2));
    DIO_writePin(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW3_PIN_ID,GET_BIT(LOC_rowsPattern,3));
}
