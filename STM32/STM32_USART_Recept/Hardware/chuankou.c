#include "stm32f10x.h"
#include "chuankou.h"
#include "OLED.h"
#include <stdio.h>
#include <stdarg.h>
//初始化函数
    void chuankou_Init(void){
    //开启时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    //初始化GPIO引脚
        //PA9为复用推挽输出 供USART1的TX使用
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
        //PA10为上拉输入 供USART1的RX使用
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    //初始化USART
    USART_InitTypeDef USART_InitStructure;
        //波特率
    USART_InitStructure.USART_BaudRate = 9600;
        //硬件流式控制
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
        //发送/接受模式
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
        //选择校验位
    USART_InitStructure.USART_Parity = USART_Parity_No;
        //选择停止位长度
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
        //字长
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1, &USART_InitStructure);
    //配置输出NVIC中断
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    //配置NVIC
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef NVICInitStructure;
    NVICInitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVICInitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVICInitStructure.NVIC_IRQChannelPreemptionPriority =1;
    NVICInitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVICInitStructure);
    USART_Cmd(USART1, ENABLE);
}//发送的数据可以是字符/编码  接受显示的也可以是字符/编码
//发送字节函数
void chuankou_Output(uint8_t byte){
    //形参数据转到TDR
    USART_SendData(USART1, byte);
    //等待TDR的数据转到移位寄存器   查看标志位
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}
//发送数组的函数
void chuankou_SendArray(uint8_t *Array, uint32_t length){
    uint8_t i = 0;
    for (i = 0; i < length; i++){
         chuankou_Output(Array[i]);
    }
}
//发送字符的函数
void chuankou_SendString(char* string){
    for (uint8_t i = 0; string[i] != '\0'; i++){
        chuankou_Output(string[i]);
    }
}
//发送数字的函数（十进制）
uint32_t cifang(uint32_t X, uint32_t Y){
    uint32_t ret = 1;
    while(Y--){
        ret *= X;
    }
    return ret;
}
uint32_t weishu(uint32_t num){
    uint32_t count = 0;
    do{
        num = num/10;
        count++;
    }while(num > 0);
    return count;
}
void chuankou_SendNum(uint32_t Num){
    uint32_t i = 0;
    for (i = 0; i < weishu(Num); i++){
        chuankou_Output(Num/cifang(10, weishu(Num) - i - 1)%10 + 0x30);
    }
}
//printf函数重定向到串口
int fputc(int ch, FILE* f){
     chuankou_Output(ch);
     return ch;
}
//打印函数封装
void chuankou_printf(char* format, ...){
    char String[500];
    va_list arg;
    //从format位置开始接受参数表
    ///放在arg里面
    va_start(arg, format);
    vsprintf(String, format, arg);
    va_end(arg);
    chuankou_SendString(String);
}
//查询函数
void Inspect (void){
    uint8_t i = 0;
    if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET){
        i = USART_ReceiveData(USART1);
        OLED_ShowHexNum(1,1,i,2);
    }
}
//中断函数
uint8_t chuankou_RXData;
uint8_t chuankou_RXFlag;
//自定义标志位控制程序 此标志位是用于主程序判断的
uint8_t chuankou_GetRXFlag(void){
    if (chuankou_RXFlag == 1){
        chuankou_RXFlag = 0;
        return 1;
    }
    return 0;
}
//得到数据值
uint8_t chuankou_GetRXData(void){
    return chuankou_RXData;
}
void USART1_IRQHandler(void){
    //判断标志位
    //一旦接收到了数据
    if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET){
        //读取数据存入寄存器
        chuankou_RXData = USART_ReceiveData(USART1);
        //至自己定义的标志位表示已有数据
        chuankou_RXFlag = 1;
        //清除标志位挂起
        USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    }
}


































