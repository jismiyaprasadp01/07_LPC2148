#include <lpc214x.h>
#include "uart.h"

void delay()
{
    int i,j;

    for(i=0;i<500;i++)
    {
        for(j=0;j<5000;j++);
    }
}

int main()
{
    int i;

    init_uart0();

    while(1)
    {
        for(i = 1; i <= 10; i++)
{
    if(i == 10)
        uart0_tx_string("10");
    else
        uart0_tx_char(i + '0');

    uart0_tx_string("\r\n");

    delay();
}
    }
}