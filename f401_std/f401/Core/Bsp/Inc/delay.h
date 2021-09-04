#ifndef __DELAY_H
#define __DELAY_H
#include "stm32f4xx.h"
void delay_init();
void delay_us(u32 nus);
void delay_ms(u16 nms);
#endif