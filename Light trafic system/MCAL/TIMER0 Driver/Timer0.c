


#include "../../Utilities/register.h"
#include "../../Utilities/types.h"
#include "../../Utilities/BIT_MATH.h"

#include "../DIO Driver/dio.h"
#include "Timer0.h"

uint16_t overflowCounter=0;

EN_TIMER_error_t MTimer0_init(uint8_t InitValue ) // initiate Timer0
{
	if (InitValue >255 || InitValue < 0) // in case of error input
	return TIMER_WRONG_INIT_VALUE;
	TCCR0 = 0x00 ; //Normal mode
	TCNT0 = InitValue ; //Timer set initial value 
	return TIMER_OK;
}
EN_TIMER_error_t MTimer0_Delay_14_equal_second(uint16_t NUMBER_OF_OVERFLOWS )
{
	if (NUMBER_OF_OVERFLOWS < 0) // in case of error input
	return TIMER_WRONG_NO_OF_OVERFLOWS;
	
	//Timer Start -> Setting the clock source
	TCCR0 |= TIMER0_PRESCALER256; 
	while (overflowCounter < NUMBER_OF_OVERFLOWS)
	{
		// wait until the overflow flag to be set
		while ((TIFR & 1) ==0)
	{}
		//clear the overflow flag
		TIFR |= 1;
		overflowCounter++;
	}
	overflowCounter =0;
	//Timer stop
	TCCR0 = 0x00;
	return TIMER_OK;
}




