#include "stm32f10x.h"                  // Device header
#include "PWM.h"
void SP_Init(void){
	//设置输出
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	PWM_Init();
}
//调整速度方向
//2接收到的速度判断方向 再调用函数
void SP_Con(int8_t speed){
	if (speed >= 0){
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		OC_Change(speed);
	}
	else{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		OC_Change(-speed);
	}
}


















