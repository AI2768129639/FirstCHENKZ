//GPIO的输入
#include "stm32f10x.h"
#include "LED.h"
#include "Key.h"
uint8_t KeyNum;
void Delay(volatile unsigned int count) {
    for(; count != 0; count--){
	}
}
int main (void){
	//初始化
	LED_Init();
	Key_Init();
	while (1){
		KeyNum = Key_GetNum();
		if (KeyNum == 1){
			LED_Reverse (GPIOA, GPIO_Pin_3);
		}else if (KeyNum == 2){
			LED_Reverse (GPIOA, GPIO_Pin_4);
		}
	}
}




















































































