#include <lpc214x.h>
#include "uart.h"

char data;

void uart0_ISR(void) __irq;

int main()
{
    IODIR1 |= (1<<16);         // LED output

    IOSET1 = (1<<16);          // Initially OFF

    init_uart0();

    VICIntSelect = 0x00;

    VICVectCntl0 = 0x26;

    VICVectAddr0 = (unsigned)uart0_ISR;

    VICIntEnable = (1<<6);

    uart0_tx_string("HELLO EIE\r\n");

    while(1);
}

void uart0_ISR(void) __irq
{
    data = U0RBR;              // Receive character

    IOCLR1 = (1<<16);          // LED ON

    VICVectAddr = 0x00;
}