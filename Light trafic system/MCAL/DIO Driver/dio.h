
#ifndef DIO_H_
#define DIO_H_


enum DIOPORT_t {PORT_A, PORT_B, PORT_C, PORT_D};
enum DIODirection_t {INPUT, OUTPUT, INPUT_PULL_UP}; 
enum DIOState_t {LOW, HIGH};


EN_DIO_error_t MDIO_voidInit(enum DIOPORT_t portNumber, uint8_t PinNumber, enum DIODirection_t Direction);

EN_DIO_error_t MDIO_voidWrite(enum DIOPORT_t PortNumber, uint8_t PinNumber, enum DIOState_t Value);

EN_DIO_error_t MDIO_voidToggle(enum DIOPORT_t PortNumber, uint8_t PinNumber);

EN_DIO_error_t MDIO_voidRead(enum DIOPORT_t PortNumber, uint8_t PinNumber, uint8_t *Value);
\


#endif /* DIO_H_ */