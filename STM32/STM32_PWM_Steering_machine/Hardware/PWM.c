#include "stm32f10x.h"                  // Device header

/*
PWM频率 = CK_PSC/(PSC + 1)/(ARR + 1)
PWM占空比 = CCR/(ARR + 1)
PWM分辨率 = 1/(ARR + 1)
*/

void PWM_Init(void){
	//初始化GPIO 使PWM波形在PA0引脚输出
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//打开时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	//开启内部时钟
	TIM_InternalClockConfig(TIM2);
	//初始化时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	//CNT加到20000时清零 每1微秒加1 所以周期为20ms
	TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1;    //ARR
	//将72MHz分频为1MHz
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;  //PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	//初始化输出比较单元
	TIM_OCInitTypeDef TIM_OCInitStructure;
	//为结构体赋初始值 因为该结构体下面赋值不完整
	TIM_OCStructInit(&TIM_OCInitStructure);
	//更改需要的值
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;                 //CCR  固定的值  也就是PWM波形占空比不变 亮度不变
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	//启动定时器 
	TIM_Cmd(TIM2, ENABLE);
}
void OC_Change(uint16_t Compare){
	TIM_SetCompare2(TIM2, Compare);
}
	
















































