//中断
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
		OLED_ShowNum(4,1,TIM_GetCounter(TIM2),8);
	}
}




/*


中断

每个外设有16个优先级
0~16 数字越小 越紧急

外设中断
EXTI
TIM
ADC
USART
SPI
I2C
RTC

内核中断
复位中断  不可屏蔽中断



                EXTI
				
				
				
NVIC  内核外设
接受外部或内部中断 多个输入  单个输出
按序输出中断
管理中断 分配优先级



中断优先级
抢占强制中断  响应插队中断




中断嵌套

优先级高的先做 再做低优先级中断


EXTI 外部中断

检测GPIO的电平变化  向NVIC发出中断申请
支持所有GPIO  相同的Pin号不能相同
中断响应  直接向CPU申请
事件响应  直接向其他外设发送指令


结构

1.GPIO接口

2.AFIO
中断引脚选择 每个PinX选择1个口 发到EXTI
复用功能引脚重映射  中断引脚选择

3.EXTI  发向中断 / 外设
选择上升沿/下降沿  触发
触发中断 会有挂起寄存器  查看哪个通道触发中断
触发事件  发射脉冲  控制外设



4.NVIC





               TIM
	
定时中断  计数
产生PWM波形
一般72MHz  最大59.65s计时


时基单元：
16位计数器        计数
预分频器          分频
自动重装寄存器    计数的目标值

级联模式 一个TIM的输出当作下一个TIM的输入

内外时钟源选择

定时器
高级TIM1/8 APB2  通用TIM2/3/4/5 APB1  基本TIM6/7 APB1


基本
 
 
内部时钟CK_INT 72MHz



PSC预分频器         写x 输出的频率就除以（x + 1）

CNT计数器           计数  自增运行/自减/中央对齐

ARR自动重装寄存器   存储目标值 到达后重置
会产生更新中断      输向NVIC -》CPU
      更新事件      产生动作
	  
	  
	 
	 
主模式触发DAC
	  
把更新事件映射到输出TRGO 触发DAC 使定时器更新	  
	  
	  
	  
	  
	  
通用

内部时钟CK_INT 72MHz
外部时钟 TIMx_ETR         外部时钟2 
         TRGI             外部时钟1
         ITR其他时钟的输入
         CHx引脚


     IC                  CC                  OC
输入捕获电路  -   捕获/比较寄存器   -   输出比较电路


输入捕获 和 输出比较不能同时使用





高级 
重复次数计数器  达到多次目标值才更新
DTG 死区生成电路
刹车输入  保护电路







定时中断结构


1.GPIO

2.RCC内部时钟  内部
  ETR外部时钟    外部模式2/1
  ITRx定时器     外部模式1
  TIx捕获通道    编码模式

3. 时基单元 PSC ARR CNT


4.中断输出控制


CK_PSC  ->   CK_CNT   ->   计数器寄存器   ->   更新事件

预分频寄存器  修改分频
预分频缓冲器  执行完一次定时 再延迟改变
预分频计数器  输出脉冲











输出比较 OC

比较CNT计数器 CCR寄存器的关系
对输出电平至0 1 翻转 的操作
输出有一定频率  占空比  的PWM波
等效于输出模拟波
修改频率 占空比可以使波等效于某种波

频率： 1/t（周期）
占空比：on（作用电平）/t（周期）
分辨率：占空比步距


REf  
 0  无反应
 1  反转是否

寄存器配置
CNT=CCR 冻结 REF有效 无效 反转
CNTCCR无效时 REF强制为无效电频
PWM1模式 向上计数  CNT<CCR REF值有效  反之无效
PWM2  就是取反极性


时基单元  ->  CNT运行  ->  CCR比较（比较后改变极性）  ->  REF极性选择 输出使能  ->  GPIO输出





























*/












































































