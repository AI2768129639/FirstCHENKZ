#ifndef __LED_H
#define __LED_H
#include "stm32f10x.h"// Device header
void LED_Init(void);
void LED_Reverse (GPIO_TypeDef* GPIOX, uint16_t GPIO_Pin);
#endif
