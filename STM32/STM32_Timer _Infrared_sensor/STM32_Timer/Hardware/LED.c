#include "stm32f10x.h"// Device header
extern void Delay(volatile unsigned int count);
//LED初始化
void LED_Init(void){
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
//LED开关函数
void LED_Reverse (GPIO_TypeDef* GPIOX, uint16_t GPIO_Pin){
	if (GPIO_ReadOutputDataBit(GPIOX, GPIO_Pin) == 0){
		GPIO_SetBits(GPIOX, GPIO_Pin);
	}else{
		GPIO_ResetBits(GPIOX, GPIO_Pin);
	}
}








































