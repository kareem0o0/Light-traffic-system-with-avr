
#ifndef LED_H_
#define LED_H_

typedef struct
{
	uint8_t port;
	uint8_t pin;
	
}LED_t;

state HLED_voidInit (LED_t *Led);
state HLED_LedOn (LED_t *Led);
state HLED_LedOff (LED_t *Led);
state HLED_voidledToggle (LED_t *Led);

#endif /* LED_H_ */