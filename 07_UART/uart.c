#include <lpc214x.h>
#include "uart.h"

void init_uart0(void)
{
    PINSEL0 |= 0x00000005;

    U0LCR = 0x83;

    U0DLL = 97;
    U0DLM = 0;

    U0LCR = 0x03;
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

void uart0_tx_number(int num)
{
    uart0_tx_char(num + '0');
}