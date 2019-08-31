/*
 * dio.h
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */

#ifndef DIO_H
#define DIO_H
#include "std_types.h"
#include "REGISTER.h"
#include "MACROS.h"
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_WritePin (uint8 PinNum , uint8 PinValue);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);
#endif
