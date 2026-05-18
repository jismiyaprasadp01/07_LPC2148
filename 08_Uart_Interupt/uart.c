#include <lpc214x.h>
#include "uart.h"

void init_uart0(void)
{
    PINSEL0 |= 0x00000005;     // P0.0 = TXD0, P0.1 = RXD0

    U0LCR = 0x83;              // 8-bit, 1 stop bit, DLAB = 1

    U0DLL = 97;                // 9600 baud rate
    U0DLM = 0;

    U0LCR = 0x03;              // DLAB = 0

    U0IER = 0x01;              // Enable UART RX interrupt
}

void uart0_tx_char(char ch)
{
    while(!(U0LSR & (1<<5)));

    U0THR = ch;
}

void uart0_tx_string(char *str)
{
    while(*str)
    {
        uart0_tx_char(*str++);
    }
}