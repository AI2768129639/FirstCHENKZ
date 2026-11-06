#include "stm32f10x.h"
#include "OLED.h"
#include "AD.h"
uint16_t V_1;
uint16_t V_2;
uint16_t V_3;
uint16_t V_4;
float Vv_1;
float Vv_2;
float Vv_3;
float Vv_4;
int main (void){
	OLED_Init();
	AD_Init();
	while (1){
		OLED_ShowString(1, 1, "V:");
		OLED_ShowString(2, 1, "V:");
		OLED_ShowString(3, 1, "V:");
		OLED_ShowString(4, 1, "V:");
		V_1 = Get_ADC(ADC_Channel_0);
		V_2 = Get_ADC(ADC_Channel_1);
		V_3 = Get_ADC(ADC_Channel_2);
		V_4 = Get_ADC(ADC_Channel_9);
		Vv_1 = (float)V_1/4095 * 3.3;
		Vv_2 = (float)V_2/4095 * 3.3;
		Vv_3 = (float)V_3/4095 * 3.3;
		Vv_4 = (float)V_4/4095 * 3.3;
		OLED_ShowNum(1, 3, Vv_1, 1);
		OLED_ShowNum(2, 3, Vv_2, 1);
		OLED_ShowNum(3, 3, Vv_3, 1);
		OLED_ShowNum(4, 3, Vv_4, 1);
		OLED_ShowString(1, 4, ".");
		OLED_ShowString(2, 4, ".");
		OLED_ShowString(3, 4, ".");
		OLED_ShowString(4, 4, ".");
		OLED_ShowNum(1, 5, (uint16_t)(Vv_1 * 100) % 100, 2);
		OLED_ShowNum(2, 5, (uint16_t)(Vv_2 * 100) % 100, 2);
		OLED_ShowNum(3, 5, (uint16_t)(Vv_3 * 100) % 100, 2);
		OLED_ShowNum(4, 5, (uint16_t)(Vv_4 * 100) % 100, 2);
		OLED_ShowString(1, 7, "V");
		OLED_ShowString(2, 7, "V");
		OLED_ShowString(3, 7, "V");
		OLED_ShowString(4, 7, "V");
		OLED_ShowString(1, 9, "light");
		OLED_ShowString(2, 9, "infrare");
		OLED_ShowString(3, 9, "tept");
		OLED_ShowString(4, 9, "inside");
	}
}




















































































