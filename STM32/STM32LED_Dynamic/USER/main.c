//LED 流水灯实现
//用按位 | 来实现设置多个引脚

#include "stm32f10x.h"

void Delay (volatile unsigned int num){
	for (; num != 0; num--){
		
	}
}

int main(void) {

	GPIO_InitTypeDef GPIO_InitStructure;
	//开启总开关 选择GPIOA的区域
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//推挽输出模式开启
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//选择引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	//选择速度
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	//写入库函数
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	while(1){
		//配置端口输出  ~按位取反时只有选中的端口为0 低电平点亮
		GPIO_Write(GPIOA, ~0x0001);//0000 0001
		Delay(1000000);
		GPIO_Write(GPIOA, ~0x0002);//0000 0010
		Delay(1000000);
		GPIO_Write(GPIOA, ~0x0004);//0000 0100
		Delay(1000000);
		GPIO_Write(GPIOA, ~0x0008);//0000 1000
		Delay(1000000);
	}
}

























































































