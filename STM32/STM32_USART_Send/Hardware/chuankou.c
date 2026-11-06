#include "stm32f10x.h"
#include "chuankou.h"
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
    //初始化USART
    USART_InitTypeDef USART_InitStructure;
        //波特率
    USART_InitStructure.USART_BaudRate = 9600;
        //硬件流式控制
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
        //发送/接受模式
    USART_InitStructure.USART_Mode = USART_Mode_Tx;
        //选择校验位
    USART_InitStructure.USART_Parity = USART_Parity_No;
        //选择停止位长度
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
        //字长
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1, &USART_InitStructure);
    USART_Cmd(USART1, ENABLE);
}//发送的数据可以是字符/编码  接受显示的也可以是字符/编码
//发送数据函数
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
//发送数字的函数
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
//使printf函数重定向到串口
int fputc(int ch, FILE* f){
     chuankou_Output(ch);
     return ch;
}
//对打印函数进行封装
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





































