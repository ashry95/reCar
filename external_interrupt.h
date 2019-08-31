/*
 * external_interrupt.h
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_
#include "REGISTER.h"
#include "std_types.h"
#include "MACROS.h"
#include "dio.h"
enum
{
	interrupt0,
	interrupt1,
	interrupt2
};
//enum
//{
//	ISC00,
//	ISC01,
//	ISC10,
//	ISC11,
//	SM0,
//	SM1,
//	SM2,
//	SE
//};
enum
{
	low_lvl,
	any_logic_lvl,
	falling_edge,
	rising_edge
};

#define ISC2 6

enum
{
	INt2=5,
	INt0,
	INt1
};

//enum
//{
//	INTF2=5,
//	INTF0,
//	INTF1
//};

void external_interrupt_init(uint8 external_INT_num, uint8 edge);

#endif /* EXTERNAL_INTERRUPT_H_ */
