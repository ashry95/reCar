/*
 * REGISTER.h
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */

#ifndef REGISTER_H_
#define REGISTER_H_
#define DDRA *((volatile uint8*)(0x3A))
#define DDRB *((volatile uint8*)(0x37))
#define DDRC *((volatile uint8*)(0x34))
#define DDRD *((volatile uint8*)(0x31))
#define PORTA *((volatile uint8*)(0x3B))
#define PORTB *((volatile uint8*)(0x38))
#define PORTC *((volatile uint8*)(0x35))
#define PORTD *((volatile uint8*)(0x32))
#define PINA *((volatile uint8*)(0x39))
#define PINB *((volatile uint8*)(0x36))
#define PINC *((volatile uint8*)(0x33))
#define PIND *((volatile uint8*)(0x30))
#define TCCR0 (*((volatile uint8*)0x53))
#define TIMSK (*((volatile uint8*)0x59))
#define TIFR  (*((volatile uint8*)0x58))
#define OCR0  (*((volatile uint8*)0x5c))
#define TCNT0 (*((volatile uint8*)0x52))
#define SREG  (*((volatile uint8*)0x5f))
#define MCUCR  (*((volatile uint8*)0x55))
#define MCUCSR  (*((volatile uint8*)0x54))
#define GICR  (*((volatile uint8*)0x5B))
#define GIFR  (*((volatile uint8*)0x5A))
#define TCCR1A  (*((volatile uint8*)0x4F))
#define TCCR1B  (*((volatile uint8*)0x4E))
#define TCNT1H  (*((volatile uint8*)0x4D))
#define TCNT1L  (*((volatile uint8*)0x4C))
#define TCNT1   (*((volatile uint16*)0x4C))
#define OCR1AH  (*((volatile uint8*)0x4B))
#define OCR1AL  (*((volatile uint8*)0x4A))
#define OCR1BH  (*((volatile uint8*)0x49))
#define OCR1BL  (*((volatile uint8*)0x48))
#define ICR1H  (*((volatile uint8*)0x47))
#define ICR1L  (*((volatile uint8*)0x46))
#define ICR1  (*((volatile uint16*)0x46))
#define TIMSK  (*((volatile uint8*)0x59))
#define TIFR  (*((volatile uint8*)0x58))
#define OCR1A  (*((volatile uint8*)0x4A))
#define TCCR2  (*((volatile uint8*)0x45))
#define TCNT2  (*((volatile uint8*)0x44))
#define OCR2  (*((volatile uint8*)0x43))


enum
{
	input,
	output
};
enum
{
	low,
	high
};

typedef enum
{
	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7,
	pin8,
	pin9,
	pin10,
	pin11,
	pin12,
	pin13,
	pin14,
	pin15,
	pin16,
	pin17,
	pin18,
	pin19,
	pin20,
	pin21,
	pin22,
	pin23,
	pin24,
	pin25,
	pin26,
	pin27,
	pin28,
	pin29,
	pin30,
	pin31
}pin;
typedef enum
{
	pa0,pa1,pa2,pa3,pa4,pa5,pa6,pa7,
	pb0,pb1,pb2,pb3,pb4,pb5,pb6,pb7,
	pc0,pc1,pc2,pc3,pc4,pc5,pc6,pc7,
	pd0,pd1,pd2,pd3,pd4,pd5,pd6,pd7,
}pins;

#endif /* REGISTER_H_ */
