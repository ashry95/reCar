/*
 * timer0.h
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */
#include "std_types.h"
#include "MACROS.h"
#include "register.h"
#ifndef TIMER0_H_
#define TIMER0_H_
#define ctc 1
#define overFlow 0
#define delay 2

enum
{
	noclksorce,
	noprescaler,
	scale8,
	scale64,
	scale256,
	scale1024,

};
enum
{
	CS00,CS01,CS02,WGM01,COM00,COM01,WGM00,FOC0
};

enum
{
	TOIE0,
	OCIE0,
};
enum
{
	TOV0,
	OCF0,
};
#define interruptEnable true
void timer_init(uint8 mode,uint8 prescaler);
void timer_delay(uint32 volatile n);
void timer_microSecond(volatile uint64 n);
#endif /* TIMER0_H_ */
