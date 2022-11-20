/*
 * Interrupt.h
 *
 * Created: 9/19/2022 5:25:16 PM
 *  Author: SquareError99
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define VECTOR_ISR_EX0	__vector_1
#define VECTOR_ISR_EX1	__vector_2
#define VECTOR_ISR_EX2	__vector_3

#define ISR(INT_VECT)void  INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

#define INTERRUPT_Global_Enable     (Set_Bit(SREG,7))
#define INTERRUPT_Global_Disable    (Clr_Bit(SREG,7))

enum INTERRUPT_EXTERNAL_TYPE{EXTERNAL_INT_LINE0,EXTERNAL_INT_LINE1};
enum INTERRUPT_TEXTERNAL_TRIGGER{LOW_LEVEL_TRIG,LOGICAL_CHANGE_TRIG,FALLING_EDGE_TRIG,RISING_EDGE_TRIG};

void MINTERRUPT_voidEnableExternalInterrupt(enum INTERRUPT_EXTERNAL_TYPE Interrupt);
void MINTERRUPT_voidDisableExternalInterrupt(enum INTERRUPT_EXTERNAL_TYPE Interrupt);
void MINTERRUPT_voidExternal_Interrupt_SetTrigger(enum INTERRUPT_EXTERNAL_TYPE Interrupt, enum INTERRUPT_TEXTERNAL_TRIGGER Trigger ) ;

#endif /* INTERRUPT_H_ */