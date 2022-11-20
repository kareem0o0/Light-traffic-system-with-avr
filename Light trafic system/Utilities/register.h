


#ifndef REGISTER_H_
#define REGISTER_H_

//PortA reg
#define PORTA *((volatile uint8_t*)(0x3B))
#define DDRA *((volatile uint8_t*)(0x3A))
#define PINA *((volatile uint8_t*)(0x39))

//PortB reg
#define PORTB *((volatile uint8_t*)(0x38))
#define DDRB *((volatile uint8_t*)(0x37))
#define PINB *((volatile uint8_t*)(0x36))

//PortC reg
#define PORTC *((volatile uint8_t*)(0x35))
#define DDRC *((volatile uint8_t*)(0x34))
#define PINC *((volatile uint8_t*)(0x33))

//PortD reg
#define PORTD *((volatile uint8_t*)(0x32))
#define DDRD *((volatile uint8_t*)(0x31))
#define PIND *((volatile uint8_t*)(0x30))


//Timer reg
#define TCCR0 *((volatile uint8_t *)0x53)
#define TCNT0 *((volatile uint8_t *)0x52)
#define OCR0  *((volatile uint8_t *)0x5C)
#define TIMSK *((volatile uint8_t *)0x59)
#define TIFR  *((volatile uint8_t *)0x58)


//interrupt reg
#define MCUCR  *((volatile uint8_t *)0x55)
#define MCUCSR *((volatile uint8_t *)0x54)
#define GICR   *((volatile uint8_t *)0x5B)
#define GIFR   *((volatile uint8_t *)0x5A)
#define SREG   *((volatile uint8_t *)0x5F)


#endif /* REGISTER_H_ */