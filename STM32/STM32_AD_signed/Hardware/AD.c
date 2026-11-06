#include "stm32f10x.h"                  // Device header


void AD_Init(void){
	//初始化GPIO 在PB1引脚输入
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//模拟输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	//开启ADC时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	//预分频 使ADCCLK = 12MHz
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	//配置ADC  通道  规则组序列  采样时间
	ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1,ADC_SampleTime_55Cycles5);
	//初始化ADC
	ADC_InitTypeDef ADC_InitStructure;
	//配置独立模式
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	//数据对齐
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	//选择触发控制的触发源
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	//选择单次转换模式
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	//连续转换模式
	//ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	//选择否扫描模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	//指定规则组通道数目
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &ADC_InitStructure);
	//开启ADC电源
	ADC_Cmd(ADC1, ENABLE);
	//校准
	ADC_ResetCalibration(ADC1);
	while (ADC_GetResetCalibrationStatus(ADC1) == SET);
	ADC_StartCalibration(ADC1);
	while (ADC_GetCalibrationStatus(ADC1) == SET);	
	//连续转化就只需要这一行 触发一次
	//ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}
//得到转换完的值
uint16_t Get_ADC(void){
	//触发软件转换
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	//获取标志位状态 等待转换完成
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
	//读取值 (若使用连续转换就只需要这一行)
	return ADC_GetConversionValue(ADC1);
}





















