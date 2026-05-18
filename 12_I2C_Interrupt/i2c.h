#ifndef __I2C_H__
#define __I2C_H__

#include <LPC21xx.h>

#define SI      (1<<3)
#define STA     (1<<5)
#define STO     (1<<4)
#define I2EN    (1<<6)

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(unsigned char data);
unsigned char I2C_Read(void);

void EEPROM_Write(unsigned int addr,unsigned char data);
unsigned char EEPROM_Read(unsigned int addr);

#endif