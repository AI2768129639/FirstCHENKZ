#include "stm32f10x.h"                  // Device header

void IC_Init(void){
	//配置GPIO TIM3定时器 因为TIM2输出比较了
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	TIM_InternalClockConfig(TIM3);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 65536 - 1;    //ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720 - 1;  //PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	
	//配置输入捕获
	//初始化 先定义结构体
	TIM_ICInitTypeDef TIM_ICInitstructure;
	//选择通道
	TIM_ICInitstructure.TIM_Channel = TIM_Channel_1;
	//配置滤波器
	TIM_ICInitstructure.TIM_ICFilter = 0xF;
	//配置极性 边沿检测 上升/下降
	TIM_ICInitstructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	//触发分频器
	TIM_ICInitstructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	//数据选择器 直连/交叉
	TIM_ICInitstructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	//再传参
	TIM_ICInit(TIM3, &TIM_ICInitstructure);
	
	//触发源选择 选择从模式的信号源 触发从模式
	TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);
	//配置从模式reset
	TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);
	
	//调用TIM开启
	TIM_Cmd(TIM3, ENABLE);
	
}

//计算频率
/*
频率测量：
测频法（高频）
对上/下升沿计次N  除以时间T 时间自己选择
f = N / T
测周法（低频）
两个上升沿内测时间 得到周期t(用已知的标准频率来计算次数N)
f = f标准 / N
就是已知一个频率
在这个频率的一次时间里测量上升沿或下降沿的次数
就得到了一个周期的频率

中界频率
Fm = 根号下  f标准 / T

高于此频率 用测频法  反之测周法
*/

//返回频率值
uint32_t IC_GetFrequency(void){
	//f = f标准 / N
	return 1000000 / (TIM_GetCapture1(TIM3) + 1);
}






































