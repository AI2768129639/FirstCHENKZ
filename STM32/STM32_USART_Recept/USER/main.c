#include "stm32f10x.h"
#include "OLED.h"
#include "chuankou.h"
uint8_t Rxdata = 0;
int main (void){
	OLED_Init();
	chuankou_Init();
	while (1){
        OLED_ShowString(1,1,"Rxdata:");
        //判断自己的标志位
        if(chuankou_GetRXFlag() == 1){
            //得到数据
            Rxdata = chuankou_GetRXData();
            //OLED显示
            OLED_ShowHexNum(1,8,Rxdata,2);
            //结果回传到串口显示器
            chuankou_Output(Rxdata);
        }
	}
}














































































