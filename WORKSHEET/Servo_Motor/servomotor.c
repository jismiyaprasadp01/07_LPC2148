#include<LPC21xx.h>

#define MOTOR (1<<0)

void delay_ms(unsigned int ms)
{
	T0PR = 15000-1;
	T0TCR = 0x01;

	while(T0TC < ms);

	T0TCR = 0x03;
	T0TCR = 0x00;
}

int main()
{
	PINSEL0 = 0x00000000;

	IODIR0 |= MOTOR;

	while(1)
	{
		/* MOTOR ON */

		IOSET0 = MOTOR;

		delay_ms(3000);

		/* MOTOR OFF */

		IOCLR0 = MOTOR;

		delay_ms(3000);
	}
}