

#ifndef TYPES_H_
#define TYPES_H_


typedef unsigned char uint8_t;
typedef unsigned int  uint16_t;
  
typedef enum state {works,error}state;
	
typedef enum EN_DIO_error_t
{
	DIO_WRONG_PIN_NUMBER,
	DIO_WRONG_PORT_NUMBER, // if that error happen , a debugging error will occur so no logical error caution is required 
	DIO_WRONG_DIRECTION, // if that error happen , a debugging error will occur so no logical error caution is required 
	DIO_OK
}EN_DIO_error_t ;
typedef enum EN_TIMER_error_t
{
	TIMER_WRONG_INIT_VALUE, // if that error happen , a debugging error will occur so no logical error caution is required 
	TIMER_WRONG_NO_OF_OVERFLOWS, // if that error happen , a debugging error will occur so no logical error caution is required 
	TIMER_OK
}EN_TIMER_error_t ;



#endif /* TYPES_H_ */