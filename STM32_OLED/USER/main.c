//OLED使用
#include "stm32f10x.h"
#include "OLED.h"
int main (void){
	OLED_Init();
	OLED_ShowChar(1,1,'I');
	OLED_ShowString(1,3,"LOVE");
	OLED_ShowString(1,8,"YOU !");
	OLED_ShowString(2,1,"STM32");
	//OLED_ShowNum(2,1,1314,4);
	//OLED_ShowSignedNum(2,6,520,3);
	OLED_ShowHexNum(3,1,99,4);
	OLED_ShowBinNum(4,1,99,16);
	
	//OLED_Clear();
	while (1){
		
	}
}

//上状态栏放大镜中有红d的是调试模式
//上窗口为汇编语言
//下窗口为c语言
//左窗口为寄存器状态


















































































