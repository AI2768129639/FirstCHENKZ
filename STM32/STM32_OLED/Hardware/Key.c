#include "stm32f10x.h"// Device header
extern void Delay(volatile unsigned int count);
//按键初始化
void Key_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
//按键通断函数
uint8_t Key_GetNum(void){
	//定义执行代表变量
	uint8_t GetNum = 0;
	//检测按键是否按下
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0){
		//触发延迟消抖
		Delay(80000);
		//再次确认按键是否按下
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0){
			//改变定义代表变量
			GetNum = 1;
			//松手检测触发
			while ((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)) == 0);
			//触发延迟消抖
		Delay(80000);
		}
	}
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0){
		Delay(80000);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0){
			GetNum = 2;
			while ((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)) == 0);
			Delay(80000);
		}
	}
	return GetNum;
}



















