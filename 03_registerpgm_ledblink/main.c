#include <LPC214x.h>
#include "gpio.h"

int main()
{
    while(1)
    {
        pinWrite(16,1);
        delay(500);

        pinWrite(16,0);
        delay(500);

        portWrite(0,0xAA);
        delay(1000);

        portWrite(0,0x00);
        delay(1000);
    }
}