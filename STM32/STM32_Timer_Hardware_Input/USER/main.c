#include "stm32f10x.h"
#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"
#include "Delay.h"
int main (void){
	OLED_Init();
	Encoder_Init();
	//Timer_Init();
	while (1){
		OLED_ShowString(1,1,"Speed:");
		OLED_ShowSignedNum(1,7,Encoder_Get(),5);
		Delay_ms(1000);
	}
}
//速度为脉冲个数/s

/*
想要调转极性
1.跳线互换
2.修改TIM_EncoderInterfaceConfig参数极性
3.交换通道
*/














































































