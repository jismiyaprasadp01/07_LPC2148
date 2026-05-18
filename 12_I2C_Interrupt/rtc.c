#include <LPC21xx.h>
#include "i2c.h"
#include "rtc.h"

unsigned char BCD_To_Dec(unsigned char data)
{
    return ((data/16)*10)+(data%16);
}
