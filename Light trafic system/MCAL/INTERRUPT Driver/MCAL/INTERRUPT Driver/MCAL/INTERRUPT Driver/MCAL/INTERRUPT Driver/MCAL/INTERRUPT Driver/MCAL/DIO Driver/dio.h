/*
 * DIO.h
 *
 * Created: 9/12/2022 4:24:58 AM
 *  Author: SquareError99
 */ 


#ifndef DIO_H_
#define DIO_H_


enum DIOPORT_t {PORT_A, PORT_B, PORT_C, PORT_D};
enum DIODirection_t {INPUT, OUTPUT, INPUT_PULL_UP}; 
enum DIOState_t {LOW, HIGH};


void MDIO_voidInit(enum DIOPORT_t portNumber, uint8_t PinNumber, enum DIODirection_t Direction);

void MDIO_voidWrite(enum DIOPORT_t PortNumber, uint8_t PinNumber, enum DIOState_t Value);

void MDIO_voidToggle(enum DIOPORT_t PortNumber, uint8_t PinNumber);

void MDIO_voidRead(enum DIOPORT_t PortNumber, uint8_t PinNumber, uint8_t *Value);

uint8_t MDIO_voidGetPinValue(enum DIOPORT_t PortNumber, uint8_t PinNumber);


#endif /* DIO_H_ */