




#include "timer0.h"


void timer_init(uint8 mode,uint8 prescaler)
{
	if (mode==overFlow)
	{
		TCCR0 |=(1<<7);	//force o/p compare off
		TCCR0 &=~(1<<6); //normal mood waveform generation
		TCCR0 &=~(1<<5); ///disable oc0 channel
		TCCR0 &=~(1<<4); //disable oc0 channel
		TCCR0 &=~(1<<3); ///normal mood waveform generation
		TCCR0|=(prescaler & 0x0f);
#if((interruptEnable == true)&&(mode == overFlow))
		TIMSK |=(1<<TOIE0);// enable overflow interrupt
#elif((interruptEnable == true) && (mode == ctc))
		TIMSK |=(1<<OCIE0);// enable overflow interrupt
#endif
	}
	else if(mode==ctc)
	{
		TCNT0 = 0; //timer initial value
		OCR0  = 249; //compare value
		TCCR0 =  (1<<WGM01) | (prescaler & 0x0f);
		Set_Bit(TIFR,OCF0);
	}

}

void timer_delay(volatile uint32 n)
{
	TCNT0 = 0; //timer initial value
	OCR0  = 249; //compare value
	TCCR0 =  (1<<WGM01) | (1<<CS01) | (1<<CS00);
	n=n/2;
	while(n)
	{
		while((Get_Bit(TIFR,OCF0))==0);
		Set_Bit(TIFR,OCF0);
		TCNT0 = 0;
		n--;
	}
}
void timer_microSecond(volatile uint64 n)
{
	uint64 div,rem;
	if(n<=250)
	{

		//uint16 time;
		TCNT0 = 0; //timer initial value
		OCR0  = n; //compare value
		TCCR0 =  (1<<WGM01) | (1<<CS01);
		while(n--)
		{
			while((Get_Bit(TIFR,OCF0))==0);
			Set_Bit(TIFR,OCF0);
			TCNT0 = 0;
		}
		return;
	}
	else
	{
		div=n/250;
		rem=n%250;
		TCNT0 = 0; //timer initial value
		OCR0  = 249; //compare val
		TCCR0 =  (1<<WGM01) | (1<<CS01);
		while(div--)
		{
			while(Get_Bit(TIFR,OCF0)==0);
			Set_Bit(TIFR,OCF0);
		}
		TCNT0=0;
		OCR0=rem;
		while((Get_Bit(TIFR,OCF0))==0);
		Set_Bit(TIFR,OCF0);
		TCNT0 = 0;
		return;
	}
}

