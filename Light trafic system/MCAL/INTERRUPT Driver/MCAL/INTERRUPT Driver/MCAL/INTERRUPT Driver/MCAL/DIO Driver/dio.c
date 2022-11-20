/*
 * DIO.h
 *
 * Created: 9/12/2022 4:25:12 AM
 *  Author: SquareError99
 */ 





#include "../../Utilities/types.h"
#include "../../Utilities/register.h"
#include "../../Utilities/BIT_MATH.h"
#include "dio.h"



void MDIO_voidInit(enum DIOPORT_t PortNumber, uint8_t PinNumber, enum DIODirection_t Direction)
{
	switch(PortNumber)
	{
		case  PORT_A:
			if (Direction == OUTPUT)
				{
					Set_Bit(DDRA,PinNumber);
				}
			else if (Direction == INPUT)
				{
					Clr_Bit(DDRA,PinNumber);
				}
			else if (Direction == INPUT_PULL_UP)
				{
					Clr_Bit(DDRA,PinNumber);
					Set_Bit(PORTA,PinNumber);
				}
		break;
		case PORT_B:
			if (Direction == OUTPUT)
				{
					Set_Bit(DDRB,PinNumber);
				}
			else if (Direction == INPUT)
				{
					Clr_Bit(DDRB,PinNumber);
				}
			else if (Direction == INPUT_PULL_UP)
				{
					Clr_Bit(DDRB,PinNumber);
					Set_Bit(PORTB,PinNumber);
				}
		break;
		case PORT_C:
			if (Direction == OUTPUT)
				{
					Set_Bit(DDRC,PinNumber);
				}
			else if (Direction == INPUT)
				{
					Clr_Bit(DDRC,PinNumber);
				}
			else if (Direction == INPUT_PULL_UP)
				{
					Clr_Bit(DDRC,PinNumber);
					Set_Bit(PORTC,PinNumber);
				}
		break;
		case PORT_D:
			if (Direction == OUTPUT)
				{
					Set_Bit(DDRD,PinNumber);
				}
			else if (Direction == INPUT)
				{
					Clr_Bit(DDRD,PinNumber);
				}
			else if (Direction == INPUT_PULL_UP)
				{
					Clr_Bit(DDRD,PinNumber);
					Set_Bit(PORTD,PinNumber);
				}
		break;
	}
}

void MDIO_voidWrite(enum DIOPORT_t PortNumber, uint8_t PinNumber, enum DIOState_t Value)
{
	switch(PortNumber)
	{
		case PORT_A:
		if (Value == LOW)
		{
			Clr_Bit(PORTA,PinNumber);
		}
		else if (Value == HIGH)
		{
			Set_Bit(PORTA,PinNumber);
		}
		break;
		case PORT_B:
		if (Value == LOW)
		{
			Clr_Bit(PORTB,PinNumber);
		}
		else if (Value == HIGH)
		{
			Set_Bit(PORTB,PinNumber);
		}
		break;
		
		case PORT_C:
		if (Value == LOW)
		{
			Clr_Bit(PORTC,PinNumber);
		}
		else if (Value == HIGH)
		{
			Set_Bit(PORTC,PinNumber);
		}
		break;
		case PORT_D:
		if (Value == LOW)
		{
			Clr_Bit(PORTD,PinNumber);
		}
		else if (Value == HIGH)
		{
			Set_Bit(PORTD,PinNumber);
		}
		break;
}
}

void MDIO_voidToggle(enum DIOPORT_t PortNumber, uint8_t PinNumber)
{
	switch (PortNumber)
{
		case PORT_A :
			Tog_Bit(PORTA,PinNumber);
		break;
		case PORT_B :
			Tog_Bit(PORTB,PinNumber);
		break;
		case PORT_C :
			Tog_Bit(PORTC,PinNumber);
		break;
		case PORT_D :
			Tog_Bit(PORTD,PinNumber);
		break;	
}		
}

void MDIO_voidRead(enum DIOPORT_t PortNumber, uint8_t PinNumber, uint8_t *Value)
{
	switch(PortNumber)
	{
		case PORT_A:
			*Value = Get_Bit(PINA,PinNumber);		 //(PINA &(1<<PinNumber)) >>PinNumber;                              
		break;
		case PORT_B:
			*Value = Get_Bit(PINB,PinNumber);		//(PINB &(1<<PinNumber)) >>PinNumber;          											
		break;
		case PORT_C:
			*Value = Get_Bit(PINC,PinNumber);	   //(PINC &(1<<PinNumber)) >>PinNumber; 															
		break;
		case PORT_D:
			*Value = Get_Bit(PIND,PinNumber); 		//(PIND &(1<<PinNumber)) >>PinNumber;  														
		break;
}
}



uint8_t MDIO_voidGetPinValue(enum DIOPORT_t PortNumber, uint8_t PinNumber)
{
	switch (PortNumber)
	{
		case PORT_A:
		return Get_Bit(PINA, PinNumber);
		break;

		case PORT_B:
		return Get_Bit(PINB, PinNumber);
		break;

		case PORT_C:
		return Get_Bit(PINC, PinNumber);
		break;

		case PORT_D:
		return Get_Bit(PIND, PinNumber);
		break;

	}
	return 0;
}
