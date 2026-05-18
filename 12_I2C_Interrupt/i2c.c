#include <LPC21xx.h>
#include "i2c.h"

void I2C_Init(void)
{
    PINSEL0 |= 0x00000050;

    I2SCLH = 75;
    I2SCLL = 75;

    I2CONSET = (1<<6);
}

void I2C_Start(void)
{
    I2CONSET = (1<<5);

    while(!(I2CONSET & (1<<3)));

    I2CONCLR = (1<<5);
}

void I2C_Stop(void)
{
    I2CONSET = (1<<4);

    I2CONCLR = (1<<3);
}

void I2C_Write(unsigned char data)
{
    I2DAT = data;

    I2CONCLR = (1<<3);

    while(!(I2CONSET & (1<<3)));
}

void delay_i2c(void)
{
    int i,j;

    for(i=0;i<200;i++)
    for(j=0;j<3000;j++);
}

void EEPROM_Write(unsigned int addr,unsigned char data)
{
    I2C_Start();

    I2C_Write(0xA0);

    I2C_Write(addr);

    I2C_Write(data);

    I2C_Stop();

    delay_i2c();
}

unsigned char I2C_Read(void)
{
    I2CONCLR = (1<<3);

    while(!(I2CONSET & (1<<3)));

    return I2DAT;
}


unsigned char EEPROM_Read(unsigned int addr)
{
    unsigned char data;

    I2C_Start();

    I2C_Write(0xA0);

    I2C_Write(addr);

    I2C_Start();

    I2C_Write(0xA3);

    I2CONCLR = (1<<3);

    while(!(I2CONSET & (1<<3)));

    data = I2DAT;

    I2C_Stop();

    return data;
}