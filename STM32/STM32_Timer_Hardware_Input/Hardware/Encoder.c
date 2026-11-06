#include "stm32f10x.h"                  // Device header

void Encoder_Init(void){
	//开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	//GPIO初始化 Pin6/7上拉输入
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//TIM初始化
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 65536 - 1;    //ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 1 - 1;  //PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	//配置输入捕获通道 滤波器 边沿检测器
	//初始化 先定义结构体
	TIM_ICInitTypeDef TIM_ICInitstructure;
	//赋初始值 再单独更改需要的参数
	TIM_ICStructInit(&TIM_ICInitstructure);
	//选择通道1
	TIM_ICInitstructure.TIM_Channel = TIM_Channel_1;
	//配置滤波器
	TIM_ICInitstructure.TIM_ICFilter = 0xF;
	//再传参
	TIM_ICInit(TIM3, &TIM_ICInitstructure);
	//选择通道2
	TIM_ICInitstructure.TIM_Channel = TIM_Channel_2;
	//配置滤波器
	TIM_ICInitstructure.TIM_ICFilter = 0xF;
	//再传参
	TIM_ICInit(TIM3, &TIM_ICInitstructure);
	//配置编码器接口 选择在TI1和TI2都计数 极性都不反相
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	//开启定时器
	TIM_Cmd(TIM3, ENABLE);	
}
//得到编码器计数
int16_t Encoder_Get(void){
	int16_t Temp;
	//读取CNT
	Temp = TIM_GetCounter(TIM3);
	//清零CNT
	TIM_SetCounter(TIM3, 0);
	return Temp;
}











































