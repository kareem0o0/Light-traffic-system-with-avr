
#include "../Utilities/types.h"
#include "../Utilities/register.h"
#include "../Utilities/BIT_MATH.h"

#include "../MCAL/DIO Driver/dio.h"
#include "../MCAL/INTERRUPT Driver/Interrupt.h"
#include "../MCAL/TIMER0 Driver/Timer0.h"

#include "../HALL/LED Driver/led.h"

#include "Application.h"

uint8_t Long_Press = 0;





state App_TurnOn5SLed(LED_t L) // turn on the led for only 5 seconds
{
	MTimer0_init(0);
	HLED_LedOn(&L);
	MTimer0_Delay_14_equal_second(70); // approximately equivalent to 5 seconds delay 
	HLED_LedOff(&L);
	return works;
}
state App_TurnOn5S_blinkLed(LED_t L) // to blink for five seconds 
{
	MTimer0_init(0);
	for(int i=0;i<5;i++)
	{
		HLED_LedOn(&L);
		MTimer0_Delay_14_equal_second(8); //approximately equivalent to 0.5 seconds delay 
		HLED_LedOff(&L);
		MTimer0_Delay_14_equal_second(8);
	}
	return works;
}
state App_TurnOn_5S_2Leds(LED_t L1, LED_t L2)	// turn on the 2 leds for only 5 seconds
{
	
	MTimer0_init(0);
	HLED_LedOn(&L1);   HLED_LedOn(&L2);
	MTimer0_Delay_14_equal_second(70);
	HLED_LedOff(&L1);  HLED_LedOff(&L2);
	return works;
}
state App_TurnOn_5S_2blinkLeds(LED_t L1, LED_t L2)	// blink the 2 leds for only 5 seconds
{
	MTimer0_init(0);
	for(int i=0;i<5;i++)
	{ 
		HLED_LedOn(&L1);   HLED_LedOn(&L2);
		MTimer0_Delay_14_equal_second(8);
		HLED_LedOff(&L1);  HLED_LedOff(&L2);
		MTimer0_Delay_14_equal_second(8);
	}
	return works;
}

LED_t CarsGreenLed,CarsYellowLed,CarsRedLed;   LED_t PEDGreenLed,PEDYellowLed,PEDRedLed;
uint8_t Value;

state AppStart()
{

	// INITIALIZING CAR TRAFFIC LIGHT LEDS

	CarsGreenLed.port = PORT_A;
	CarsYellowLed.port = PORT_A;
	CarsRedLed.port = PORT_A;
	CarsGreenLed.pin = 0;
    CarsYellowLed.pin = 1;
	CarsRedLed.pin = 2;
	
	// INITIALIZING PEDESTRIAN TRAFFIC LIGHT LEDS
	PEDGreenLed.port = PORT_B;
	PEDYellowLed.port = PORT_B; 
	PEDRedLed.port = PORT_B;
	PEDGreenLed.pin = 0; 
	PEDYellowLed.pin = 1; 
	PEDRedLed.pin = 2;
	
	// initializing the LEDS for the cars traffic light
	HLED_voidInit(&CarsGreenLed);  
	HLED_voidInit(&CarsYellowLed);  
	HLED_voidInit(&CarsRedLed);
	
	// initializing the LEDS for the Pedestrians traffic light
	HLED_voidInit(&PEDGreenLed);  
	HLED_voidInit(&PEDYellowLed);  
	HLED_voidInit(&PEDRedLed);
	
	// initializing Timer0 counter register with 0 value 
	MTimer0_init(0);
	
	
	MINTERRUPT_voidExternal_Interrupt_SetTrigger(EXTERNAL_INT_LINE0,FALLING_EDGE_TRIG);
	MINTERRUPT_voidEnableExternalInterrupt(EXTERNAL_INT_LINE0);
	INTERRUPT_Global_Enable ;
	
	
	
	
	while(1)
	{
		 App_TurnOn5SLed(CarsGreenLed);
		 App_TurnOn5S_blinkLed(CarsYellowLed);
		 App_TurnOn5SLed(CarsRedLed);
		 App_TurnOn5S_blinkLed(CarsYellowLed);
	}
}



ISR (VECTOR_ISR_EX0)   // when the button is pushed 
{
	MTimer0_init(0);
	if (MDIO_GetPinValue(PORT_D,2) == HIGH)
	{
		Long_Press = 1 ;
	}  
	else 
	{ 
		Long_Press = 0 ; 
	}
		
	if (MDIO_GetPinValue(PORT_A, 2) == HIGH && Long_Press == 0 )
	{
		HLED_LedOn(&PEDGreenLed);
		App_TurnOn5SLed(CarsRedLed);
		HLED_LedOff(&CarsRedLed);
		App_TurnOn_5S_2blinkLeds(CarsYellowLed,PEDYellowLed);
		HLED_LedOff(&PEDGreenLed);
		HLED_LedOn(&PEDRedLed);
		App_TurnOn5SLed(CarsGreenLed);
		HLED_LedOff(&PEDRedLed);
		App_TurnOn5SLed(CarsYellowLed);
		App_TurnOn5SLed(CarsRedLed);
	}
		
	else if ((MDIO_GetPinValue(PORT_A, 0) == 1 || MDIO_GetPinValue(PORT_A, 1) == 1)&& Long_Press == 0 )
		{
			HLED_LedOff(&CarsGreenLed);  HLED_LedOff(&CarsYellowLed);
			HLED_LedOn(&PEDRedLed);
			App_TurnOn_5S_2blinkLeds(CarsYellowLed,PEDYellowLed);
			HLED_LedOff(&PEDRedLed);
			HLED_LedOn(&PEDGreenLed);
			App_TurnOn5SLed(CarsRedLed);
			HLED_LedOff(&CarsRedLed);
			App_TurnOn_5S_2blinkLeds(CarsYellowLed,PEDYellowLed);
			HLED_LedOff(&PEDGreenLed);
			HLED_LedOn(&CarsGreenLed);
			App_TurnOn5S_blinkLed(PEDYellowLed);
			HLED_LedOff(&CarsGreenLed);
	}
	
}