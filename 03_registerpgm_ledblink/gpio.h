#ifndef GPIO_H
#define GPIO_H

#include <LPC214x.h>

void pinWrite(int pinNumber, int pinValue);

void portWrite(int portno, int portvalue);

int pinRead(int pinNumber);

void delay(int count);

#endif