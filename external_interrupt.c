/*
 * external_interrupt.c
 *
 *  Created on: ???/???/????
 *      Author: Mina
 *
 */
#include "external_interrupt.h"
void external_interrupt_init(uint8 external_INT_num, uint8 edge)
{
	SREG |=(1<<7);
	if(external_INT_num == interrupt0)
	{
		MCUCR =( MCUCR & 0xfc) | (edge & 0x03);
		GICR |= (1<<INt0);
		DIO_SetPinDirection(pd2,input);
	}
	else if(external_INT_num == interrupt1)
	{
		MCUCR =( MCUCR & 0xf3) | (edge & 0x0c);
		GICR |= (1<<INt1);
		DIO_SetPinDirection(pd3,input);
	}
	else if(external_INT_num == interrupt2)
	{
		if(edge == falling_edge)
		{
			MCUCSR &=~(1<<ISC2);
		}
		else
		{
			MCUCSR |=(1<<ISC2);
		}
		GICR |= (1<<INt2);
		DIO_SetPinDirection(pb2,input);
	}


}



