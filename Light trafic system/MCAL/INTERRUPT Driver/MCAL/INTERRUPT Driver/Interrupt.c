/*
 * Interrupt.c
 *
 * Created: 9/19/2022 5:24:55 PM
 *  Author: SquareError99
 */ 
#include "../../Utilities/types.h"
#include "../../Utilities/register.h"
#include "../../Utilities/BIT_MATH.h"

#include "../DIO Driver/dio.h"
#include "Interrupt.h"

#include "../../HALL/LED Driver/led.h"


void MINTERRUPT_voidEnableExternalInterrupt(enum INTERRUPT_EXTERNAL_TYPE Interrupt)
{
	switch (Interrupt)
	{
		case (EXTERNAL_INT_LINE0):
			Set_Bit(GICR,6);
			break;
		case (EXTERNAL_INT_LINE1):
			Set_Bit(GICR,7);
			break;
		default:
			return ;
	}
	INTERRUPT_Global_Enable ;
}
void MINTERRUPT_voidDisableExternalInterrupt(enum INTERRUPT_EXTERNAL_TYPE Interrupt)
{
	switch (Interrupt)
	{
		case (EXTERNAL_INT_LINE0):
			Clr_Bit(GICR,6);
			break;
		case (EXTERNAL_INT_LINE1):
			Clr_Bit(GICR,7);
			break;
		default:
			return ;
	}
}
void MINTERRUPT_voidExternal_Interrupt_SetTrigger(enum INTERRUPT_EXTERNAL_TYPE Interrupt, enum INTERRUPT_TEXTERNAL_TRIGGER Trigger )
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
	
}
                           
             