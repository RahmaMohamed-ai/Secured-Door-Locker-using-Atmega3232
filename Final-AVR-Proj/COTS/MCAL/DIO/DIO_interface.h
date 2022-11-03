#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

/* ***************************** DIO APIs ******************************** */

void DIO_vWritePinValue(u8 A_u8PortId, u8 A_u8PinNO, u8 PinValue);
void DIO_vWritePinDirection(u8 A_u8PortId, u8 A_u8PinNO, u8 A_u8Direction);
u8 DIO_u8ReadPinValue(u8 A_u8PortId, u8 A_u8PinNO);
void DIO_vTogPinValue(u8 A_u8PortId, u8 A_u8PinNO);

void DIO_vPortSetDirection(u8 A_u8PortId, u8 A_u8Direction);
void DIO_vPortSetValue(u8 A_u8PortId, u8 A_u8PortValue);
/* ----------------------------------------------------------------------- */

#define DIO_LOW		0
#define DIO_HIGH	1

#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3



#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7





#endif/*_DIO_INTERFACE_H_*/
