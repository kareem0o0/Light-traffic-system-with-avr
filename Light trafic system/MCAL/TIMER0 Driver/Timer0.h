


#ifndef TIMER0_H_
#define TIMER0_H_

//#define NUMBER_OF_OVERFLOWS 2000
enum Timer0ClouckSource{TIMER0_STOP,TIMER0_PRESCALER1,TIMER0_PRESCALER8,TIMER0_PRESCALER64,TIMER0_PRESCALER256,TIMER0_PRESCALER1024};


EN_TIMER_error_t MTimer0_init(uint8_t InitialValue );
EN_TIMER_error_t MTimer0_Delay_14_equal_second(uint16_t NumberOfOverlfows );

#endif /* TIMER0_H_ */