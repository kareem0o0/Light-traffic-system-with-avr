
#include "../../Utilities/types.h"
#include "led.h"
#include "../../MCAL/DIO Driver/dio.h"



state HLED_voidInit (LED_t *Led) // led initilization
{
	MDIO_voidInit(Led->port,Led->pin,OUTPUT);
	return works;
}
state HLED_LedOn (LED_t *Led) // opening the led
{
	MDIO_voidWrite(Led->port,Led->pin,HIGH);
	return works;
}
state HLED_LedOff (LED_t *Led) // closing the led
{
	MDIO_voidWrite(Led->port,Led->pin,LOW);
	return works;
}
state HLED_voidledToggle (LED_t *Led) // toggling the led
{
	MDIO_voidToggle(Led->port,Led->pin);
	return works;
}