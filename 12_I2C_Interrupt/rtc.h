#ifndef __RTC_H__
#define __RTC_H__

void RTC_Read(void);
void RTC_SetTime(void);
unsigned char BCD_To_Dec(unsigned char data);

#endif