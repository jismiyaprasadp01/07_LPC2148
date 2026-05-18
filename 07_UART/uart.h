#ifndef __UART_H__
#define __UART_H__

void init_uart0(void);
void uart0_tx_char(char ch);
void uart0_tx_string(char *str);
void uart0_tx_number(int num);

#endif