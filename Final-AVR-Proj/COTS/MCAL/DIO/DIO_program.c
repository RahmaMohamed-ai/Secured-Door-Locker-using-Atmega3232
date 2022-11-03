#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"


void DIO_vWritePinDirection(u8 A_u8PortId, u8 A_u8PinNO, u8 A_u8Direction)
{
	if(A_u8Direction == DIO_HIGH)
	{
		switch(A_u8PortId)
		{
		case DIO_PORTA:
			SET_BIT(DDRA, A_u8PinNO);
			break;
		case DIO_PORTB:
			SET_BIT(DDRB, A_u8PinNO);
			break;
		case DIO_PORTC:
			SET_BIT(DDRC, A_u8PinNO);
			break;
		case DIO_PORTD:
			SET_BIT(DDRD, A_u8PinNO);
			break;
		}
	}
	else if(A_u8Direction == DIO_LOW)
	{
		switch(A_u8PortId)
		{
		case DIO_PORTA:
			CLR_BIT(DDRA, A_u8PinNO);
			break;
		case DIO_PORTB:
			CLR_BIT(DDRB, A_u8PinNO);
			break;
		case DIO_PORTC:
			CLR_BIT(DDRC, A_u8PinNO);
			break;
		case DIO_PORTD:
			CLR_BIT(DDRD, A_u8PinNO);
			break;
		}
	}
}

void DIO_vWritePinValue(u8 A_u8PortId, u8 A_u8PinNO, u8 PinValue)
{
	if(PinValue == DIO_HIGH)
	{
		switch(A_u8PortId)
		{
		case DIO_PORTA:
			SET_BIT(PORTA, A_u8PinNO);
			break;
		case DIO_PORTB:
			SET_BIT(PORTB, A_u8PinNO);
			break;
		case DIO_PORTC:
			SET_BIT(PORTC, A_u8PinNO);
			break;
		case DIO_PORTD:
			SET_BIT(PORTD, A_u8PinNO);
			break;
		}
	}
	else if(PinValue == DIO_LOW)
	{
		switch(A_u8PortId)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA, A_u8PinNO);
			break;
		case DIO_PORTB:
			CLR_BIT(PORTB, A_u8PinNO);
			break;
		case DIO_PORTC:
			CLR_BIT(PORTC, A_u8PinNO);
			break;
		case DIO_PORTD:
			CLR_BIT(PORTD, A_u8PinNO);
			break;
		}
	}
}

u8 DIO_u8ReadPinValue(u8 A_u8PortId, u8 A_u8PinNO)
{
	u8 PinValue = 0;

	switch(A_u8PortId)
	{
	case DIO_PORTA:
		PinValue = GET_BIT(PINA, A_u8PinNO);
		break;
	case DIO_PORTB:
		PinValue = GET_BIT(PINB, A_u8PinNO);
		break;
	case DIO_PORTC:
		PinValue = GET_BIT(PINC, A_u8PinNO);
		break;
	case DIO_PORTD:
		PinValue = GET_BIT(PINC, A_u8PinNO);
		break;
	}

	return PinValue;
}

void DIO_vTogPinValue(u8 A_u8PortId, u8 A_u8PinNO)
{
	switch(A_u8PortId)
	{
	case DIO_PORTA:
		TOG_BIT(PORTA, A_u8PinNO);
		break;
	case DIO_PORTB:
		TOG_BIT(PORTB, A_u8PinNO);
		break;
	case DIO_PORTC:
		TOG_BIT(PORTC, A_u8PinNO);
		break;
	case DIO_PORTD:
		TOG_BIT(PORTD, A_u8PinNO);
		break;
	}
}

void DIO_vPortSetDirection(u8 A_u8PortId, u8 A_u8Direction)
{
	if(A_u8Direction == DIO_HIGH)
		{
			switch(A_u8PortId)
			{
			case DIO_PORTA:
				DDRA = 0xff;
				break;
			case DIO_PORTB:
				DDRB = 0xff;
				break;
			case DIO_PORTC:
				DDRC = 0xff;
				break;
			case DIO_PORTD:
				DDRD = 0xff;
				break;
			}
		}
		else if(A_u8Direction == DIO_LOW)
		{
			switch(A_u8PortId)
			{
			case DIO_PORTA:
				DDRA = 0x00;
				break;
			case DIO_PORTB:
				DDRB = 0x00;
				break;
			case DIO_PORTC:
				DDRC = 0x00;
				break;
			case DIO_PORTD:
				DDRD = 0x00;
				break;
			}
		}
}

void DIO_vPortSetValue(u8 A_u8PortId, u8 A_u8PortValue)
{
	if(A_u8PortValue == DIO_HIGH)
	{
		switch(A_u8PortId)
		{
		case DIO_PORTA:
			PORTA = 0xff;
			break;
		case DIO_PORTB:
			PORTB = 0xff;
			break;
		case DIO_PORTC:
			PORTC = 0xff;
			break;
		case DIO_PORTD:
			PORTD = 0xff;
			break;
		}
	}
	else if(A_u8PortValue == DIO_LOW)
	{
		switch(A_u8PortId)
		{
		case DIO_PORTA:
			PORTA = 0x00;
			break;
		case DIO_PORTB:
			PORTB = 0x00;
			break;
		case DIO_PORTC:
			PORTC = 0x00;
			break;
		case DIO_PORTD:
			PORTD = 0x00;
			break;
		}
	}
	else
	{
		switch(A_u8PortId)
		{
		case DIO_PORTA:
			PORTA = A_u8PortValue;
			break;
		case DIO_PORTB:
			PORTB = A_u8PortValue;
			break;
		case DIO_PORTC:
			PORTC = A_u8PortValue;
			break;
		case DIO_PORTD:
			PORTD = A_u8PortValue;
			break;
		}
	}
}
