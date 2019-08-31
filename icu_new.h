/*
 * icu.h
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */

#ifndef ICU_H_
#define ICU_H_
#include"REGISTER.h"
#include"std_types.h"
#include "dio.h"
enum
{
	Falling_edge,
	Rising_edge,
};

extern volatile uint64 g_firstHigh;
extern volatile uint64 g_secondHigh;
extern volatile uint64 g_first_Low;
extern volatile uint64 g_SecondLow;
extern volatile uint8 g_edge;
void icu_init(uint8 preScale);
void icu_setEdge(uint8 edge_select);
uint64 Icu_getCapValue(void);
void Icu_clearTimerValue(void);

#endif /* ICU_H_ */
