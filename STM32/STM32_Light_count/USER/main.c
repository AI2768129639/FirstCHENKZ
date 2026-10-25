//OLED使用
#include "stm32f10x.h"
#include "OLED.h"
#include "CountSensor.h"
void Delay(unsigned int count) {
    for(; count != 0; count--);
}
int main (void){
	OLED_Init();
	LED_Init();
	CountSensor_Init();
	OLED_ShowString(1,1,">_<");
	OLED_ShowString(2,1,"I MISS YOU!*");
	OLED_ShowString(3,1,"Do you love me?");
	OLED_ShowString(4,1,"-YES!");
	GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	while (1){
		OLED_ShowNum(2,13,Num_Get(),4);
	}
}

















































































