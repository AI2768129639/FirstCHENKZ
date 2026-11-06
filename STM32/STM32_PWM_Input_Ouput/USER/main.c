#include "stm32f10x.h"
#include "OLED.h"
#include "PWM.h"
#include "Delay.h"
#include "IC.h"

int main (void){
	//初始化所有
	OLED_Init();
	PWM_Init();
	IC_Init();
	//初始化显示屏
	OLED_ShowString(1,1,"Frequency:");
	//设置好PWM输出到PA0
	PSC_Change(720 - 1);
	OC_Change(50);
	//PA0通过导线连接到PA6
	//PA6连接好TIMM的通道1
	//通道1连接配置好的输入捕获流程 得到频率
	//在循环中不断刷新显示频率
	while (1){
		OLED_ShowNum(2,1,IC_GetFrequency(), 16);
	}
}


























