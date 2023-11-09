/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 21 Oct 2023                                                           */
/************************************************************************************/

#include "../../../LIB/Include/Std_types.h"
#include "../../../LIB/Include/Bit_utils.h"

#include "../../../MCAL/PORT/Include/PORT_interface.h"
#include "../../../MCAL/DIO/Include/DIO_interface.h"

#include "../Include/LCD_interface.h"
#include "../Include/LCD_private.h"
#include "../Include/LCD_config.h"
#define F_CPU    8000000UL
#include <util/delay.h>

void LCD_voidInit(void)
{
    /* delay more than 30 msec */
    _delay_ms(50);
    LCD_voidSendCommand(LCD_u8_CURSOR_HOME);
    /* configuration of mode 8_Bit or 4_Bit */
    #if   LCD_u8_MODE == LCD_u8_MODE_8_BIT
        /* function set => call send_command func */
        LCD_voidSendCommand(LCD_u8_8B_Mode);
    #elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
        /* function set => call send_command func */
        LCD_voidSendCommand(LCD_u8_4B_Mode);
    #endif 
    /* display clear => call send_command func */
    LCD_voidSendCommand(LCD_u8_DISPLAY_CLEAR);
    _delay_ms(4);
    /* entry mode => call send_command func */
    LCD_voidSendCommand(LCD_u8_ENTRY_Mode);
    _delay_ms(1);  
    /* display uursor on/off control => call send_command func */
    LCD_voidSendCommand(LCD_u8_DISPLAY_CURSOR_ON);
    _delay_ms(1);  
}

void LCD_voidSendCommand(u8 copy_u8Comand)
{
    /* write 0 to RS pin */
    DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
    /* write 0 to RW pin */
    DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
    /* write 1 to enable pin */
    DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
    /* configuration of mode 8_Bit or 4_Bit */
    #if   LCD_u8_MODE == LCD_u8_MODE_8_BIT
        /* write the command to Data Port */
        DIO_DioEnumWritePort(LCD_u8_DATA_PORT,copy_u8Comand);
        /* set enable pin */
        DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
        /* delay 1msec */
        _delay_ms(1);
        /* reset enable pin */
        DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
    #elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
        /* write the command to Data Port => 4_Bit high */
//        DIO_DioEnumWritePort(LCD_u8_DATA_PORT,copy_u8Comand);
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN4,GET_BIT(copy_u8Comand,4));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN5,GET_BIT(copy_u8Comand,5));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN6,GET_BIT(copy_u8Comand,6));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN7,GET_BIT(copy_u8Comand,7));
        /* reset enable pin */
        DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
        /* delay 1msec */
        _delay_ms(1);
        /* write the command to Data Port => 4_Bit low */
//        DIO_DioEnumWritePort(LCD_u8_DATA_PORT,copy_u8Comand<<4);
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN4,GET_BIT(copy_u8Comand,0));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN5,GET_BIT(copy_u8Comand,1));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN6,GET_BIT(copy_u8Comand,2));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN7,GET_BIT(copy_u8Comand,3));
        /* set enable pin */
        DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
        /* delay 1msec */
        _delay_ms(1);
        /* reset enable pin */
        DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
    #endif 
}

void LCD_voidDisplayCharacter(u8 copy_u8Data)
{
    /* write 1 to RS pin */
    DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
    /* write 0 to RW pin */
    DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
    /* write 1 to enable pin */
    DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
    /* configuration of mode 8_Bit or 4_Bit */
    #if   LCD_u8_MODE == LCD_u8_MODE_8_BIT
        /* write the character to Data Port */
        DIO_DioEnumWritePort(LCD_u8_DATA_PORT,copy_u8Data);
        /* set enable pin */
        DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
        /* delay 1msec */
        _delay_ms(1);
        /* reset enable pin */
        DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
    #elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
        /* write the character to Data Port => 4_Bit high */
//        DIO_DioEnumWritePort(LCD_u8_DATA_PORT,copy_u8Data);
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN4,GET_BIT(copy_u8Data,4));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN5,GET_BIT(copy_u8Data,5));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN6,GET_BIT(copy_u8Data,6));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN7,GET_BIT(copy_u8Data,7));
        /* reset enable pin */
        DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
        /* delay 1msec */
        _delay_ms(1);
        /* write the character to Data Port => 4_Bit low */
//        DIO_DioEnumWritePort(LCD_u8_DATA_PORT,copy_u8Data<<4);
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN4,GET_BIT(copy_u8Data,0));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN5,GET_BIT(copy_u8Data,1));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN6,GET_BIT(copy_u8Data,2));
        DIO_DioEnumWriteChannel(LCD_u8_DATA_PORT,DIO_u8_PIN7,GET_BIT(copy_u8Data,3));
        /* set enable pin */
        DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
        /* delay 1msec */
        _delay_ms(1);
        /* reset enable pin */
        DIO_DioEnumWriteChannel(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);
    #endif
}

void LCD_voidCreateCustomCharacter(pu8 copy_pu8Character,u8 copy_u8PatternIndex,u8 copy_u8Row,u8 copy_u8Col)
{
    u8 local_u8Count;
    /* to set CGRAM Address: 1- Index * 8 */
    u8 local_u8Adress = copy_u8PatternIndex * 8;
    /* 2- set the address in the last special character */
    LCD_voidSendCommand(local_u8Adress + 64);
    /* to write the data to CGRAM or DDRAM */
    for(local_u8Count = 0;local_u8Count <8;local_u8Count++)
    {
        LCD_voidDisplayCharacter(copy_pu8Character[local_u8Count]);
    }
    /* set DDRAM address */
    LCD_voidGoToXY(copy_u8Row,copy_u8Col);
    /* display the pattern */
    LCD_voidDisplayCharacter(copy_u8PatternIndex);
}

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col)
{
    /* to select the row and the column*/
    LCD_voidSendCommand(LCD_u8_ADRESS + copy_u8Row + copy_u8Col);
}

u8 LCD_u8DisplayString(pu8 copy_pu8String)
{
    u8 local_u8ErrorState = 0;
    u8 local_u8Count = 0;
    if(copy_pu8String != NULL)
    {
        /* check to the end of the string */
        while(copy_pu8String[local_u8Count] != '\0')
        {
            /* diplay the first character in the string */
           LCD_voidDisplayCharacter(copy_pu8String[local_u8Count]);
           local_u8Count++; 
        }
    }
    else
    {
        local_u8ErrorState = 1;
    }
    return local_u8ErrorState;
}

void LCD_voidDisplayNumber(s32 copy_u32Number)
{
    s32 local_u8Reserved = 0;
    s32 mult = 1,i=0;
    if(copy_u32Number == 0)
    {
        LCD_voidDisplayCharacter('0');
    }
    else if(copy_u32Number < 0)
    {
    	LCD_voidDisplayCharacter('-');
    	copy_u32Number = copy_u32Number * (-1);
    }
    while(copy_u32Number != 0)
    {
    	local_u8Reserved = (local_u8Reserved * 10) + (copy_u32Number % 10);
    	if(local_u8Reserved == 0)
    	{
    		mult *= 10;
    	}
        copy_u32Number /= 10;
    }
    while(local_u8Reserved != i)
    {
    	LCD_voidDisplayCharacter((local_u8Reserved % 10) + '0');
        local_u8Reserved /= 10;
        if((local_u8Reserved == 0) && (mult >= 10))
        {
        	i = 1;
        	local_u8Reserved = mult;
        }
    }
}

void LCD_voidDisplayClear(void)
{
	LCD_voidSendCommand(0x01);
}
