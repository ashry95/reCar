/*
 * icu.c
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */
#include "icu_new.h"
#include "timer0.h"
#include "avr/interrupt.h"

volatile uint8 g_edge=0;
volatile uint8 g_ovf=0;
volatile uint64 g_firstHigh=0;
volatile uint64 g_secondHigh=0;
volatile uint64 g_first_Low=0;
volatile uint64 g_SecondLow=0;

void icu_init(uint8 preScale)
{

	DIO_SetPinDirection(pd6,input);

//	TCCR1A = (1<<FOC1A) | (1<<FOC1B);
	TCCR1B = (TCCR1B & 0xBF) | (Rising_edge & 0x40);
	TCNT1=0;
	TIMSK |=(1<<TICIE1)|(1<<TOIE1);
	TCCR1B = (TCCR1B & 0xF8) | (preScale & 0x07);
}
void icu_setEdge(uint8 edge_select)
{
	TCCR1B = (TCCR1B & 0xBF) | (edge_select & 0x40);
}
uint64 Icu_getCapValue(void)
{
	uint64 time=0;
	time= (0.125*ICR1);
	return time;
}
void Icu_clearTimerValue(void)
{
	TCNT1 = 0;
}

ISR(TIMER1_CAPT_vect)
{
	g_firstHigh=0;
	g_firstHigh=Icu_getCapValue();
}
