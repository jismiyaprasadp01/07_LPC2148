#include <lpc214x.h>
#include "spi.h"

void delay(void);
void SPI0_ISR(void) __irq;

unsigned char data_array[4] = {0xAA,0x55,0xF0,0x0F};

int index = 0;

int main()
{
    // P0.10 as interrupt indication LED
    IO0DIR |= (1<<10);

    IO0CLR = (1<<10);

    init_spi();

    // Enable SPI Interrupt
    VICIntSelect = 0x00;

    VICVectCntl0 = 0x20 | 10;

    VICVectAddr0 = (unsigned long)SPI0_ISR;

    VICIntEnable = (1<<10);

    // Enable SPI interrupt bit
    S0SPCR |= (1<<7);

    // Send first data
    spi_tx(data_array[index]);

    while(1);
}

void SPI0_ISR(void) __irq
{
    unsigned char dummy;

    dummy = S0SPDR;

    // Latch Pulse
    IO0SET = (1<<7);

    IO0CLR = (1<<7);

    // Interrupt LED ON
    IO0SET = (1<<10);

    delay();

    IO0CLR = (1<<10);

    index++;

    if(index >= 4)
    {
        index = 0;
    }

    // Send next pattern
    spi_tx(data_array[index]);

    // Clear interrupt
    VICVectAddr = 0;
}

void delay(void)
{
    int i,j;

    for(i=0;i<200;i++)
    {
        for(j=0;j<5000;j++);
    }
}