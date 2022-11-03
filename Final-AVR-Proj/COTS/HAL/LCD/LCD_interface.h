#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_


void LCD_vInit(void);
void LCD_vSendCommand(u8 Command);
void LCD_vSendChar(u8 dt_Char);

void LCD_vPrintSTR(u8 str[]);
void LCD_vPrintNum(s32 num);
void LCD_vDisplayCustomChar(u8 CharId);

void LCD_vSaveChar(u8 CharArr[], u8 CharId);
void LCD_vSetCursorPosition(u8 LinePos ,u8 LineNo);


#endif/* _LCD_INTERFACE_H_ */
