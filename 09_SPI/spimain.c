#include <lpc214x.h>
#include "spi.h"

void delay(void);

int main()
{
    init_spi();

    while(1)
    {
        spi_tx(0xAA);      // 10101010

        delay();

        spi_tx(0x55);      // 01010101

        delay();

        spi_tx(0xF0);      // 11110000

        delay();

        spi_tx(0x0F);      // 00001111

        delay();
    }
}

void delay(void)
{
    int i,j;

    for(i=0;i<500;i++)
    {
        for(j=0;j<5000;j++);
    }
}