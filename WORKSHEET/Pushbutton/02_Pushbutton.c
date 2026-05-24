#include <LPC214x.h>

void delay(void)
{
    int i,j;

    for(i=0;i<1000;i++)
    {
        for(j=0;j<1000;j++);
    }
}

int main()
{
    IO0DIR |= (1<<0);

    IO0DIR &= ~(1<<1);

    while(1)
    {
        if(IO0PIN & (1<<1))
        {
            IO0SET = (1<<0);
        }
        else
        {
            IO0CLR = (1<<0);
        }
    }
}