#include "stm32f10x.h"                  // Device header
#include "DMA.h"

uint16_t MyDMA_Size;

void MyDMA_Init(uint32_t AddrA,uint32_t AddrB, uint16_t Size){
     MyDMA_Size = Size;
    //RCC开启DMA时钟
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    //结构体配置DMA
    DMA_InitTypeDef DMA_InitStructure;
    //选择传输次数
    DMA_InitStructure.DMA_BufferSize = Size;
    //外设站点选择作为发出源还是目的地  这里选择源
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    //选择软件触发
    DMA_InitStructure.DMA_M2M = DMA_M2M_Enable;
    //配置转运到的的存储器地址 通过传入的地址
    DMA_InitStructure.DMA_MemoryBaseAddr = AddrB;
    //数据大小
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    //是否自增
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    //指定传输器是否自动重装  这里不用  选择正常
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    //配置原始的要转运的地址 通过传入的地址
    DMA_InitStructure.DMA_PeripheralBaseAddr = AddrA;
    //传入的数据大小 选择字节
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    //选择是否自增
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
    //选择优先级 这里不重要 因为只有一个
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    //选择DMA和通道  传入配置好的结构体
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);
    //先失能DMA
    DMA_Cmd(DMA1_Channel1, DISABLE);
}
//这个函数使DMA转运
void MyDMA_Tansfer(void){
    //先失能
    DMA_Cmd(DMA1_Channel1, DISABLE);
    //赋值
    DMA_SetCurrDataCounter(DMA1_Channel1, MyDMA_Size);
    //再次赋值
    DMA_Cmd(DMA1_Channel1, ENABLE);
    //查看标志位 等待转运完成  若未完成就一直循环等待
    while (DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);
    //手动清除标志位
    DMA_ClearFlag(DMA1_FLAG_TC1);
}
//const常量数据存储在Flash里面






















































































