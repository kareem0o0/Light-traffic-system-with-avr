

#include "../../Utilities/types.h"
#include "../../Utilities/register.h"
#include "../../Utilities/BIT_MATH.h"
#include "dio.h"



EN_DIO_error_t MDIO_voidInit(enum DIOPORT_t PortNumber, uint8_t PinNumber, enum DIODirection_t Direction) // pin initiallization
{
	if( PinNumber <0 || PinNumber >7)
	return DIO_WRONG_PIN_NUMBER;
	switch(PortNumber)
	{
		case  PORT_A:
			if (Direction == OUTPUT)
				{
					Set_Bit(DDRA,PinNumber);
				}
			else if (Direction == INPUT)
				{
					Clear_Bit(DDRA,PinNumber);
				}
			else if (Direction == INPUT_PULL_UP)
				{
					Clear_Bit(DDRA,PinNumber);
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
					Clear_Bit(DDRB,PinNumber);
				}
			else if (Direction == INPUT_PULL_UP)
				{
					Clear_Bit(DDRB,PinNumber);
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
					Clear_Bit(DDRC,PinNumber);
				}
			else if (Direction == INPUT_PULL_UP)
				{
					Clear_Bit(DDRC,PinNumber);
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
					Clear_Bit(DDRD,PinNumber);
				}
			else if (Direction == INPUT_PULL_UP)
				{
					Clear_Bit(DDRD,PinNumber);
					Set_Bit(PORTD,PinNumber);
				}
		break;
	}
	return DIO_OK;
}

EN_DIO_error_t MDIO_voidWrite(enum DIOPORT_t PortNumber, uint8_t PinNumber, enum DIOState_t Value) // setting the value of the pin
{
	if( PinNumber <0 || PinNumber >8)
	return DIO_WRONG_PIN_NUMBER;
	switch(PortNumber)
	{
		case PORT_A:
		if (Value == LOW)
		{
			Clear_Bit(PORTA,PinNumber);
		}
		else if (Value == HIGH)
		{
			Set_Bit(PORTA,PinNumber);
		}
		break;
		case PORT_B:
		if (Value == LOW)
		{
			Clear_Bit(PORTB,PinNumber);
		}
		else if (Value == HIGH)
		{
			Set_Bit(PORTB,PinNumber);
		}
		break;
		
		case PORT_C:
		if (Value == LOW)
		{
			Clear_Bit(PORTC,PinNumber);
		}
		else if (Value == HIGH)
		{
			Set_Bit(PORTC,PinNumber);
		}
		break;
		case PORT_D:
		if (Value == LOW)
		{
			Clear_Bit(PORTD,PinNumber);
		}
		else if (Value == HIGH)
		{
			Set_Bit(PORTD,PinNumber);
		}
		break;
}
return DIO_OK;
}

EN_DIO_error_t MDIO_voidToggle(enum DIOPORT_t PortNumber, uint8_t PinNumber) // toggling the value of the pin 
{
	if( PinNumber <0 || PinNumber >8)
	return DIO_WRONG_PIN_NUMBER;
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
}	return DIO_OK;	
}

EN_DIO_error_t MDIO_voidRead(enum DIOPORT_t PortNumber, uint8_t PinNumber, uint8_t *Value) // reading the value of the pin with a pointer
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
}return works;
}



uint8_t MDIO_GetPinValue(enum DIOPORT_t PortNumber, uint8_t PinNumber)	// reading the value of the pin with the return value
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
