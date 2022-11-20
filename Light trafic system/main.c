#define F_CPU  1000000UL

#include "Utilities/types.h"

#include "Utilities/register.h"

#include "Utilities/BIT_MATH.h"

#include "MCAL/DIO Driver/dio.h"

#include "MCAL/INTERRUPT Driver/Interrupt.h"

#include "MCAL/TIMER0 Driver/Timer0.h"

#include "HALL/LED Driver/led.h"

#include "Application/Application.h"




/*----------Test DIO-----------*/

/*int main(void)
{
	MDIO_voidInit(PORT_C,0,OUTPUT);
	MDIO_voidInit(PORT_C,1,INPUT_PULL_UP);
	MDIO_voidWrite(PORT_C,0,HIGH);
	while(1)
	{
		MDIO_voidWrite(PORT_C,0,LOW);
		MDIO_voidWrite(PORT_C,0,HIGH);
	}
}*/


/*----------Test TIMER0-----------*/

/*int main(void)
{
	
	MDIO_voidInit(PORT_C,0,OUTPUT);
	MDIO_voidInit(PORT_C,1,INPUT_PULL_UP);
	MDIO_voidWrite(PORT_C,0,HIGH);
	MTimer0_Delay_14_equal_second(30);
	 while (1)
	 {
		 MDIO_voidWrite(PORT_C,0,LOW);
		 MTimer0_Delay_14_equal_second(30);
		 MDIO_voidWrite(PORT_C,0,HIGH);
		 MTimer0_Delay_14_equal_second(30);
	 }

}*/



/*----------Test LED-----------*/
/*
int main(void)
{
	LED_t l1,l2;
	l1.port = PORT_A;
	l1.pin = 0;
	l2.port = PORT_A;
	l2.pin = 1;
	HLED_voidInit(&l1);
	HLED_voidInit(&l2);
	MTimer0_Delay_14_equal_second(30);
	 while (1)
	 {
		 HLED_LedOn(&l1);
		 HLED_LedOn(&l2);
		 MTimer0_Delay_14_equal_second(30);
		 HLED_LedOff(&l2);
		 HLED_LedOff(&l1);
		 MTimer0_Delay_14_equal_second(30);
	 }

}*/


/*----------Test INTERRUPT--*/
/*
LED_t l1,l2; // global variables to be visible by ISR

int main(void)
{
	l1.port = PORT_A;
	l1.pin = 0;
	l2.port = PORT_A;
	l2.pin = 1;
	HLED_voidInit(&l1);
	HLED_voidInit(&l2);
	MINTERRUPT_voidExternal_Interrupt_SetTrigger(EXTERNAL_INT_LINE0,FALLING_EDGE_TRIG);
	MINTERRUPT_voidEnableExternalInterrupt(EXTERNAL_INT_LINE0);
	
  while (1) 
    {
		HLED_LedOn(&l1);
		MTimer0_Delay_14_equal_second(30);
		HLED_LedOff(&l1);
		MTimer0_Delay_14_equal_second(30);
    }
	
}

	ISR (VECTOR_ISR_EX0)
	{
		HLED_LedOff(&l1);
		HLED_LedOn(&l2);
		MTimer0_Delay_14_equal_second(30);
		HLED_LedOff(&l2);
		MTimer0_Delay_14_equal_second(30);
		
	}*/

int main()
{
	AppStart();
}
