//光敏蜂鸣器
#include "stm32f10x.h"
#include "Buzzer.h"
#include "Light_control.h"
void Delay(volatile unsigned int count) {
    for(; count != 0; count--){
	}
}
int main (void){
	//初始化
	Buzzer_Init();
	Light_control_Init();
	//通过光的变化控制蜂鸣器发声
	while (1){
		if ((Light_control_Get()) == 1){
			Buzzer_ON();
		}else{
			Buzzer_OFF();
		}
	}
}




















































































