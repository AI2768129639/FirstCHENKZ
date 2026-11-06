#include "stm32f10x.h"
#include "OLED.h"
#include "SM.h"
#include "Delay.h"
#include "GK.h"
uint8_t KeyNum;
//设置角度
float angle;
int main (void){
	OLED_Init();
	Key_Init();
	OLED_ShowString(1,1,"Angle:");
	SM_Init();
	//初始化角度
	SM_AngleChange(90);
	while (1){
		//不断读取按键传回的值
		//按键只控制是否工作
		//
		KeyNum = Key_GETNUM();
		//控制舵机旋转
		if (KeyNum == 1){
			angle += 30;
		}
		if (angle > 180){
			angle = 0;
		}
		SM_AngleChange(angle);
		OLED_ShowNum(2,1,angle,3);
	}
}






















