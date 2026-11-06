
#include "stm32f10x.h"
#include "OLED.h"
#include "Timer.h"

uint16_t Num = 0;
int main (void){
	OLED_Init();
	Timer_Init();
	OLED_ShowString(1,1,"I LOVE YOU *");
	while (1){
		OLED_ShowNum(2,1,Num,8);
		OLED_ShowNum(3,1,TIM_GetCounter(TIM2), 8);
	}
}

















































































