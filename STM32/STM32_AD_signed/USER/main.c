#include "stm32f10x.h"
#include "OLED.h"
#include "AD.h"
uint16_t ADValue;
float Vv;
int main (void){
	OLED_Init();
	AD_Init();
	while (1){
		ADValue = Get_ADC();
		OLED_ShowString(1, 1, "ADValue:");
		OLED_ShowString(3, 1, "V:");
		//换算显示电压
		Vv = (float)ADValue/4095 * 3.3;
		OLED_ShowNum(2, 1, ADValue, 6);
		OLED_ShowNum(4, 1, Vv, 2);
		OLED_ShowString(4, 3, ".");
		OLED_ShowNum(4, 4, (uint16_t)(Vv * 100) % 100, 2);
		OLED_ShowString(4, 6, "V");
	}
}




















































































