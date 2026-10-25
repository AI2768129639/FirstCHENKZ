#include "stm32f10x.h"
uint16_t Num = 0;
extern void Delay(volatile unsigned int count);
void CountSensor_Init(void){
	//配置GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//配置AFIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);
	//配置EXTI
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line14;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	//配置NVIC
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_Init(&NVIC_InitStructure);
}
//中断函数 （不用声明 自动执行）
void EXTI15_10_IRQHandler(void){
	//每执行一次中断就要清除一次
	if (EXTI_GetITStatus(EXTI_Line14) == SET){
		Delay(100000);
		if ((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)){
			Num++;
		}
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}
uint16_t Num_Get(void){
	return Num;
}
void LED_Init(void){
	//配置GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
}


 
























