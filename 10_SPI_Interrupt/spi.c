#include <lpc214x.h>
#include "spi.h"

#define LATCH (1<<7)

void init_spi(void)
{
    // P0.4 = SCK0
    // P0.6 = MOSI0

    PINSEL0 &= ~(3<<14);     // P0.7 as GPIO

    PINSEL0 |= (1<<8);       // P0.4 = SCK0
    PINSEL0 |= (1<<12);      // P0.6 = MOSI0

    IO0DIR |= LATCH;

    // SPI Master mode
    S0SPCR = 0x20;

    // SPI Clock
    S0SPCCR = 8;
}

void spi_tx(unsigned char data)
{
    S0SPDR = data;

    while(!(S0SPSR & (1<<7)));

    data = S0SPDR;

    // Latch pulse
    IO0SET = LATCH;

    IO0CLR = LATCH;
}