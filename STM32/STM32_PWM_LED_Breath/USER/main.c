#include "stm32f10x.h"
#include "OLED.h"
#include "PWM.h"
#include "Delay.h"
uint8_t i;
int main (void){
	OLED_Init();
	PWM_Init();
	//不断循环改变亮度
	while (1){
		for (i = 0; i<= 100; i++){
			//亮度加大
			OC_Change(i);
			Delay_ms(10);
		}
		for (i = 0; i<= 100; i++){
			//亮度减小
			OC_Change(100 - i);
			Delay_ms(10);
		}
	}
}


