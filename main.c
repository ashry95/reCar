/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */


#include"MACROS.h"
#include"REGISTER.h"
#include"std_types.h"
#include"timer0.h"
#include "timer2.h"
#include <util/delay.h>
#include "avr/interrupt.h"
#include "external_interrupt.h"
#include"dio.h"
#include "lcd.h"
//#include"icu_new.h"
#define inA1 pd2
#define inB1 pd6
#define inA2 pd3
#define inB2 pd7
#define en1 pd4
#define en2 pd5
#define WGM11 1
#define WGM10 0
#define WGM13 4
#define WGM12 3
#define COM1A1 7
#define CS10 0
#define CS11 1
void Timer1_Fast_PWM_Init(unsigned short duty_cycle);
void Timer0_PWM_Init(unsigned char set_duty_cycle);
uint16 ultasonic(void);
void Forward(void);
void Backward(void);
void Right(void);
void Left(void);
void Stop(void);
volatile uint8 g_timer2=0;
volatile uint8 g_tick=0;
int main(void)
{

	sei();

	DIO_SetPinDirection(inA1,output);
	DIO_SetPinDirection(inA2,output);
	DIO_SetPinDirection(inB1,output);
	DIO_SetPinDirection(inB2,output);
	DIO_WritePin(inA1,low);
	DIO_WritePin(inA2,low);
	DIO_WritePin(inB1,low);
	DIO_WritePin(inB2,low);
	DIO_SetPinDirection(pb0,output);
	DIO_SetPinDirection(pb5,output);
	DIO_SetPinDirection(pb6,output);
	external_interrupt_init(interrupt2,rising_edge);

	while(1)
	{
		Forward();
	}

}
void Timer0_PWM_Init(unsigned char set_duty_cycle){

	TCNT0 = 0; // Timer initial value

	OCR0  = set_duty_cycle; //compare value

	DIO_SetPinDirection(pb3,output); //set OC0 as output pin --> pin where the PWM signal is generated from MC

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

void Timer1_Fast_PWM_Init(unsigned short duty_cycle)
{
	DIO_SetPinDirection(pd5,output);
	TCNT1 = 0;		/* Set timer1 initial count to zero */
	ICR1 = 2499;	/* Set TOP count for timer1 in ICR1 register */
	OCR1A = duty_cycle; /* Set the compare value */
	TCCR1A = (1<<WGM11) | (1<<COM1A1);
	TCCR1B = (1<<WGM12) | (1<<WGM13) | (1<<CS10) | (1<<CS11);
}
void Forward(void)
{
	uint16 distance;
	distance=ultasonic();
	if(distance==10)
	{
		Stop();
	}
	else if(distance>=60)
	{
		Timer0_PWM_Init(255);
		DIO_WritePin(inA1,high);
		DIO_WritePin(inA2,low);
		DIO_WritePin(inB1,high);
		DIO_WritePin(inB2,low);
	}
	else if((distance<=60)&&(distance>=40))
	{
		Timer0_PWM_Init(153);
		DIO_WritePin(inA1,high);
		DIO_WritePin(inA2,low);
		DIO_WritePin(inB1,high);
		DIO_WritePin(inB2,low);
	}
	else if((distance<=60)&&(distance>=40))
	{
		Timer0_PWM_Init(153);
		DIO_WritePin(inA1,high);
		DIO_WritePin(inA2,low);
		DIO_WritePin(inB1,high);
		DIO_WritePin(inB2,low);
	}
	else if((distance<=40)&&(distance>=20))
	{
		Timer0_PWM_Init(76);
		DIO_WritePin(inA1,high);
		DIO_WritePin(inA2,low);
		DIO_WritePin(inB1,high);
		DIO_WritePin(inB2,low);
	}
	else if(distance<20)
	{
		Right();
	}
}
void Backward(void)
{
	DIO_WritePin(inA1,low);
	DIO_WritePin(inA2,high);
	DIO_WritePin(inB1,low);
	DIO_WritePin(inB2,high);
}
void Right(void)
{
	DIO_WritePin(inA1,high);
	DIO_WritePin(inA2,low);
	DIO_WritePin(inB1,low);
	DIO_WritePin(inB2,high);
}
void Left(void)
{
	DIO_WritePin(inA1,low);
	DIO_WritePin(inA2,high);
	DIO_WritePin(inB1,high);
	DIO_WritePin(inB2,low);
}
void Stop(void)
{
	DIO_WritePin(inA1,low);
	DIO_WritePin(inA2,low);
	DIO_WritePin(inB1,low);
	DIO_WritePin(inB2,low);
}
uint16 ultasonic(void)
{
	uint16 dist;
	uint16 time;
	DIO_WritePin(pb6,low);
	DIO_WritePin(pb0,low);
	_delay_ms(2);
	DIO_WritePin(pb0,high);
	_delay_us(10);
	DIO_WritePin(pb0,low);
	//DIO_WritePin(pb6,high);
	time=g_timer2;
	dist=time*2.176;
	return dist;
}
ISR(INT2_vect)
{

	g_tick++;
	if(g_tick==1)
	{
		Timer2_init();
		external_interrupt_init(interrupt2,falling_edge);
	}
	else if(g_tick==2)
	{
		g_timer2=TCNT2;
		external_interrupt_init(interrupt2,rising_edge);
		Timer2_deinit();
		g_tick=0;
	}
}
