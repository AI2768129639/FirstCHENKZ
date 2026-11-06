#include "stm32f10x.h"                  // Device header
#include "PWM.h"
void SM_Init(void){
	PWM_Init();
}
//通过PWM波控制角度
//将脉冲时间转化为角度
void SM_AngleChange(float angle){
	//算angle占180°的比例 映射到0.5ms~2ms的差值 0.5ms是0° 所以要加500初始化
	OC_Change(angle / 180 * 2000 + 500);
}






















