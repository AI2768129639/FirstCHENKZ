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
	OLED_ShowString(1,1,"Freq:00000Hz");
	OLED_ShowString(2,1,"Duty:00%");
	//设置好PWM输出到PA0
	PSC_Change(7200 - 1);
	OC_Change(50);
	//PA0通过导线连接到PA6
	//PA6连接好TIMM的通道1
	//通道1连接配置好的输入捕获流程 得到频率
	//通道2连接好输入捕获 得到占空比
	//在循环中不断刷新显示频率 占空比
	while (1){
		OLED_ShowNum(1,6,IC_GetFrequency(), 5);
		OLED_ShowNum(2,6,IC_GetDuty(), 2);
	}
}


























