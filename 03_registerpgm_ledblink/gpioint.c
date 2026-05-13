#include "gpio.h"

void pinWrite(int pinNumber, int pinValue)
{
    IODIR0 |= (1 << pinNumber);

    if(pinValue == 1)
    {
        IOSET0 = (1 << pinNumber);
    }
    else
    {
        IOCLR0 = (1 << pinNumber);
    }
}

void portWrite(int portno, int portvalue)
{
    if(portno == 0)
    {
        IODIR0 |= 0x000000FF;

        IOSET0 = (portvalue & 0xFF);

        IOCLR0 = (~portvalue & 0xFF);
    }
}

void delay(int count)
{
    int i,j;

    for(i=0;i<count;i++)
    {
        for(j=0;j<1000;j++);
    }
}

int pinRead(int pinNumber)
{
    IODIR0 &= ~(1 << pinNumber);

    if(IOPIN0 & (1 << pinNumber))
    {
        return 1;
    }

    return 0;
}