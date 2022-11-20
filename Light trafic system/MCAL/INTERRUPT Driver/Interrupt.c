
#include "../../Utilities/types.h"
#include "../../Utilities/register.h"
#include "../../Utilities/BIT_MATH.h"

#include "../DIO Driver/dio.h"
#include "Interrupt.h"

#include "../../HALL/LED Driver/led.h"


state MINTERRUPT_voidEnableExternalInterrupt(enum INTERRUPT_EXTERNAL_TYPE Interrupt) //enabling the external interrupt
{
	switch (Interrupt)
	{
		case (EXTERNAL_INT_LINE0):   // in case int0 was enabled 
			Set_Bit(GICR,6);
			break;
		case (EXTERNAL_INT_LINE1):	// in case int1 was enabled 
			Set_Bit(GICR,7);
			break;
		default:
			return works ;
	}
	INTERRUPT_Global_Enable ;
	return works;
}
state MINTERRUPT_voidDisableExternalInterrupt(enum INTERRUPT_EXTERNAL_TYPE Interrupt)	//disabling the external interrupt
{
	switch (Interrupt)
	{
		case (EXTERNAL_INT_LINE0):
			Clear_Bit(GICR,6);
			break;
		case (EXTERNAL_INT_LINE1):
			Clear_Bit(GICR,7);
			break;
		default:
			return works;
	}
	return works;
}
state MINTERRUPT_voidExternal_Interrupt_SetTrigger(enum INTERRUPT_EXTERNAL_TYPE Interrupt, enum INTERRUPT_TEXTERNAL_TRIGGER Trigger )
{
	
	switch(Interrupt){
		//FOLLOWING THE INSTRUCTIONS IN THE DATA SHEET
		case EXTERNAL_INT_LINE0:
			MCUCR &= ~3; // 3 in binary is 00000011 and ~3 is 11111100 this way we can clear the first 2 bits in one step
			MCUCR |= Trigger;///
		break;
		
		case EXTERNAL_INT_LINE1:
			MCUCR &= ~12; // 12 in binary is 00001100 this way we can set the required bits in one step
			MCUCR |= Trigger;
		break;
		
		default:
		break;
	}
	return works;
}
                           
             