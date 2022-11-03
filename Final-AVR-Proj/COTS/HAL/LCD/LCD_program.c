#include <util/delay.h>

#include "../../../COTS/LIB/BIT_MATH.h"
#include "../../../COTS/LIB/STD_TYPES.h"
#include "../../../COTS/MCAL/DIO/DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"



void LCD_vInit(void)
{
	DIO_vPortSetDirection(LCD_DATA_PORT , DIO_HIGH);
	DIO_vWritePinDirection(LCD_CTRL_PORT,LCD_RS_CTRL_PIN, DIO_HIGH);//Set first three bits in port A as Output.
	DIO_vWritePinDirection(LCD_CTRL_PORT,LCD_RW_CTRL_PIN, DIO_HIGH);
	DIO_vWritePinDirection(LCD_CTRL_PORT,LCD_EN_CTRL_PIN, DIO_HIGH);
	_delay_ms(50);

	LCD_vSendCommand(LCD_FUNCTION_SET);
	_delay_ms(1);
	LCD_vSendCommand(DISPLAY_CTRL);
	_delay_ms(1);
	LCD_vSendCommand(DISPLAY_CLR);
	_delay_ms(2);
	LCD_vSendCommand(ENTRY_MODE_SET);
	_delay_ms(1);


}

void LCD_vSendCommand(u8 Command)
{
	DIO_vWritePinValue(LCD_CTRL_PORT , LCD_RS_CTRL_PIN , DIO_LOW);
	DIO_vWritePinValue(LCD_CTRL_PORT , LCD_RW_CTRL_PIN , DIO_LOW);

	DIO_vPortSetValue(LCD_DATA_PORT , Command);

	DIO_vWritePinValue(LCD_CTRL_PORT ,LCD_EN_CTRL_PIN, DIO_HIGH);//EN = 1
	_delay_ms(1);
	DIO_vWritePinValue(LCD_CTRL_PORT ,LCD_EN_CTRL_PIN, DIO_LOW );//EN= 0
	_delay_ms(1);

}

void LCD_vSendChar(u8 dt_Char)
{
	DIO_vWritePinValue(LCD_CTRL_PORT ,LCD_RS_CTRL_PIN, DIO_HIGH);//RS = 1
	DIO_vWritePinValue(LCD_CTRL_PORT ,LCD_RW_CTRL_PIN, DIO_LOW );//RW = 0

	DIO_vPortSetValue(LCD_DATA_PORT , dt_Char);

	DIO_vWritePinValue(LCD_CTRL_PORT , LCD_EN_CTRL_PIN, DIO_HIGH);//set EN PIN
	_delay_ms(1);

	DIO_vWritePinValue(LCD_CTRL_PORT , LCD_EN_CTRL_PIN, DIO_LOW);//Clear EN PIN
	_delay_ms(1);
}

void LCD_vPrintSTR(u8 str[])
{
	while(*str != '\0')
	{
		LCD_vSendChar(*str);
		str++;
	}
}

/*remaining few lines/
to cover to test cases/
for 0 in the left and Negative Values */

void LCD_vPrintNum(s32 num)
{	// Input Reversing
	u32 Rev = 0 ;
//	u32 Iteration_Counter = 0;
	u32 counter = 0;
	u32 flag = 0;
	if(num < 0)
	{
		LCD_vSendChar('-');
	}
	if((num % 10) == 0)
	{
		flag = 1;
	}

	while(num > 0)
	{
		if(flag == 1)
		{
			flag = 0;
			counter++;
		}
		Rev = (Rev * 10) + (num % 10);

		num /= 10 ;//Finally Reversed num
	}
	while(Rev > 0)
	{
		u32 Last_Digit = Rev % 10;
		Rev /= 10;

		LCD_vSendChar(Last_Digit+'0');
	}
	for(u32 i = counter ; i> 0; i--)
	{
		LCD_vSendChar('0');
	}
}

void LCD_vDisplayCustomChar(u8 CharId)
{
	if(CharId < CHAR_WIDTH)
	{
		LCD_vSendCommand(DDRAM_ID);//Set DataRegister to Send to DDRAM

		LCD_vSendChar(CharId);
	}
}
void LCD_vSaveChar(u8 CharArr[], u8 CharId)
{
	if(CharId < CHAR_WIDTH)
	{
		LCD_vSendCommand(CGRAM_ID + (8*CharId));//Set DataRegister to Send to CGRAM

		for(int i=0; i< CHAR_WIDTH; i++)
		{
			LCD_vSendChar(CharArr[i]);
		}
		LCD_vSendCommand(DDRAM_ID);//Return DataRegister Setting to Send to DDRAM
	}
}

void LCD_vSetCursorPosition(u8 LinePos ,u8 LineNo)
{
	switch(LineNo)
	{
		case 1: LCD_vSendCommand(0x80 + LinePos);
		break;

		case 2: LCD_vSendCommand(0x80 + (LinePos + 0x40));
		break;
	}
}
