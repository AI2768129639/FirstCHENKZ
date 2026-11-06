#include "stm32f10x.h"                  // Device header
//定义在SRAM的数组作为传输的目的地
uint16_t AD_Value[4];
void AD_Init(void){
	//初始化GPIO 在PB1引脚输入
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//模拟输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//模拟输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    //开启ADC时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	//预分频 使ADCCLK = 12MHz
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
    //指定通道
    ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1,ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2,ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3,ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 4,ADC_SampleTime_55Cycles5);
	//RCC开启DMA时钟
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    //结构体配置DMA
    DMA_InitTypeDef DMA_InitStructure;
    //选择传输次数 因为有四个数据
    DMA_InitStructure.DMA_BufferSize = 4;
    //外设站点选择作为发出源还是目的地  这里选择发出源
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    //选择硬件触发也就是外设触发
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    //配置转运到的的存储器地址 为SRAM
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)AD_Value;
    //数据大小
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    //接受的存储器是否自增 因为有多个数据 所以要自增
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    //指定传输器自动重装 不断循环到重装置 再清零 实现实时读取数据
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    //配置原始的要转运的地址 ADC_DR的地址
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
    //传入的数据大小 选择字节
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    //选择是否自增 因为ADC把四个通道的数据传入了一个寄存器中 所以输出端不需要自增
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    //选择优先级 这里不重要 因为只有一个
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
    //选择DMA和通道  传入配置好的结构体
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);
    //使能DMA
    DMA_Cmd(DMA1_Channel1, ENABLE);
    //初始化ADC
	ADC_InitTypeDef ADC_InitStructure;
	//配置独立模式
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	//数据对齐
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	//选择触发控制的触发源
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	//选择连续转换模式 配合DMA的循环转化
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	//选择扫描模式  因为有多个数据
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	//指定规则组通道数目
	ADC_InitStructure.ADC_NbrOfChannel = 4;
    //将初始化参数传入地址
	ADC_Init(ADC1, &ADC_InitStructure);
    //开启ADC的DMA模式
    ADC_DMACmd(ADC1, ENABLE);
	//使能ADC
	ADC_Cmd(ADC1, ENABLE);
    // 增加毫秒或微秒级延时，确保硬件上电稳定
    for(volatile uint32_t i = 0; i < 1000; i++);
	//校准ADC
	ADC_ResetCalibration(ADC1);
	while (ADC_GetResetCalibrationStatus(ADC1) == SET);
	ADC_StartCalibration(ADC1);
	while (ADC_GetCalibrationStatus(ADC1) == SET);
    //ADC触发
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}


//单次触发的代码
/*
//DMA转运与ADC转换同时工作
void Get_Value (void){//ADC和DMA都是单次模式 所以都需要单独开启
    //先失能
    DMA_Cmd(DMA1_Channel1, DISABLE);
    //赋值
    DMA_SetCurrDataCounter(DMA1_Channel1, 4);
    //再次赋值
    DMA_Cmd(DMA1_Channel1, ENABLE);
    //开启ADC
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
    //因为DMA转运完成就代表ADC转化也完成了 所以只需要查看DMA的标志位
    //查看标志位 等待转运完成  若未完成就一直循环等待
    while (DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);
    //手动清除标志位
    DMA_ClearFlag(DMA1_FLAG_TC1);
}
*/




















