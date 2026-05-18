#include <LPC21xx.h>
#include "uart.h"
#include "i2c.h"
#include "rtc.h"

unsigned char sec,min,hour;

void delay(void)
{
    int i,j;

    for(i=0;i<100;i++)
    for(j=0;j<6000;j++);
}



void RTC_Read(void)
{
    I2C_Start();

    I2C_Write(0xD0);      // DS1307 write address

    I2C_Write(0x00);      // seconds register

    I2C_Start();

    I2C_Write(0xD1);      // DS1307 read address

    sec  = I2C_Read();
    min  = I2C_Read();
    hour = I2C_Read();

    I2C_Stop();

    sec  = BCD_To_Dec(sec);
    min  = BCD_To_Dec(min);
    hour = BCD_To_Dec(hour);
}

void UART_Number(unsigned char num)
{
    uart0_tx_char((num/10)+'0');
    uart0_tx_char((num%10)+'0');
}

int main()
{
    init_uart0();

    I2C_Init();

    while(1)
    {
        RTC_Read();

        uart0_tx_string("Time : ");

        UART_Number(hour);
        uart0_tx_char(':');

        UART_Number(min);
        uart0_tx_char(':');

        UART_Number(sec);

        uart0_tx_string("\r\n");

        delay();
    }
}