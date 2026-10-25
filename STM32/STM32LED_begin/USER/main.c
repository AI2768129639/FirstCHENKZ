//LED点亮以及闪烁


#include "stm32f10x.h"                  // Device header

/*
void Delay(unsigned int count) {
    for(; count != 0; count--);
}
int main(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    // 1. 开启 GPIOA 和 GPIOC 的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
    
    // 2. 配置板载灯 PC13 (推挽输出)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // 3. 配置 PA2 (推挽输出)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    // 4. 让PA2一直输出低电平（用来点亮你面包板上的外接灯）
    GPIO_ResetBits(GPIOA, GPIO_Pin_2);

    while(1) {
        // 让板载灯PC13闪烁，证明代码在跑
        GPIO_ResetBits(GPIOC, GPIO_Pin_13); // 亮
        Delay(500000);
        GPIO_SetBits(GPIOC, GPIO_Pin_13);   // 灭
        Delay(500000);
    }
}
*/


/*
void Delay(volatile unsigned int count) {
    for(; count != 0; count--){
		
	}
}
int main(void) {

	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	while (1) {
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		Delay(800000);
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		Delay(800000);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0,Bit_RESET);
		Delay(2000000);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0,Bit_SET);
		Delay(2000000);
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		Delay(800000);
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		Delay(2000000);
	
	}

}
*/


/*
void Delay(unsigned int count) {
    for(; count != 0; count--);
}

int main(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    // 注意：这里必须同时开 GPIOA 和 GPIOC 的时钟！
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
    
    // 配置 PC13 (板载灯)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // 配置 PA2 (外接灯)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; // 确认这里写的是Pin_2
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    while(1) {
        // PA2 输出低电平（外接灯亮），PC13 输出低电平（板载灯亮）
        GPIO_ResetBits(GPIOA, GPIO_Pin_2);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        Delay(5000000);
        
        // PA2 输出高电平（外接灯灭），PC13 输出高电平（板载灯灭）
        GPIO_SetBits(GPIOA, GPIO_Pin_2);
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        Delay(5000000);
    }
}
*/












































































