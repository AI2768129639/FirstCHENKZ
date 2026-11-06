#include "stm32f10x.h"
extern uint16_t Num;
/*
计算定时时间
CK_PSC 原始时钟频率  内部为72MHz = 72000000Hz
PSC 预分频器 经过后的频率为CK_PSC /（PSC + 1）
ARR 自动重装载寄存器
最终频率 = CK_PSC/（PSC + 1）/ （ARR + 1）
*/
void Timer_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	//红外传感器连接在Pin0上
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//开启 RCC供电总开关
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	//开启 外部
	TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x0f);
	//初始化时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 10 - 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 1 - 1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	//清除开始时进中断的数值
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	//使能更新中断
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	//配置NVIC
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_Init(&NVIC_InitStructure);
	//启动定时器
	TIM_Cmd(TIM2, ENABLE);
}
uint16_t Timer_Get(void){
	return TIM_GetCounter(TIM2);
}
void TIM2_IRQHandler(void){
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET){
		Num++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}


























