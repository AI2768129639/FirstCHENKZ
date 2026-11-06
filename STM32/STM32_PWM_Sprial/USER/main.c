#include "stm32f10x.h"
#include "OLED.h"
#include "PWM.h"
#include "Delay.h"
#include "Sprial.h"
#include "GGK.h"
uint8_t KeyNum;
int8_t speed;

int main (void){
	OLED_Init();
	OLED_ShowString(1,1,"Speed:");
	PWM_Init();
	SP_Init();
	Key_Init();
	//判断按键执行操作
	while (1){
		KeyNum = Key_GETNUM();
		if (KeyNum == 1){
			speed += 20;
			Delay_ms(1);
		}
		if (speed > 100){
			speed = -40;
			Delay_ms(1);
		}
		//调用函数调整速度方向
		//1接受速度
		SP_Con(speed);
		OLED_ShowNum(2,1,speed,3);
	}
}


