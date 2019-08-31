/*
 * timer2.c
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */
#include "timer2.h"

void Timer2_init(void)
{
	TCNT2=0;
	TCCR2= (1<<0)|(1<<1)|(1<<2);
}
void Timer2_deinit(void)
{
	TCNT2=0;
	TCCR2=0;
}
