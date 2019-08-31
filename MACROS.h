/*
 * MACROS.h
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */

#ifndef MACROS_H_
#define MACROS_H_
#define Set_Bit(REGISTER,BIT) (REGISTER|=(1<<BIT))
#define Clear_Bit(REGISTER,BIT) (REGISTER&=(~(1<<BIT)))
#define Toggle_Bit(REGISTER,BIT) (REGISTER^=(1<<BIT))
#define Get_Bit(REGISTER,BIT) (REGISTER&(1<<BIT))

#endif /* MACROS_H_ */
