#include "stm32f10x.h"
#include "OLED.h"
#include "DMA.h"
#include "Delay.h"
//定义原始要转运的数据
uint8_t DataA[] = {0x01, 0x02, 0x07, 0x0f};
uint8_t DataB[] = {0, 0, 0, 0};

int main (void){
	//初始化
    OLED_Init();
    MyDMA_Init((uint32_t)DataA, (uint32_t)DataB, 4);
    //显示实时数据 数据地址

	while (1){
        //时刻变化数据
        DataA[0] ++;
        DataA[1] ++;
        DataA[2] ++;
        DataA[3] ++;
        //显示实时数据 数据地址
        OLED_ShowString(1,1,"DataA");
        OLED_ShowString(3,1,"DataB");
        OLED_ShowHexNum(1,7,(uint32_t)DataA, 8);
        OLED_ShowHexNum(3,7,(uint32_t)DataB, 8);
        OLED_ShowHexNum(2,1,DataA[0], 2);
        OLED_ShowHexNum(2,4,DataA[1], 2);
        OLED_ShowHexNum(2,7,DataA[2], 2);
        OLED_ShowHexNum(2,10,DataA[3], 2);
        OLED_ShowHexNum(4,1,DataB[0], 2);
        OLED_ShowHexNum(4,4,DataB[1], 2);
        OLED_ShowHexNum(4,7,DataB[2], 2);
        OLED_ShowHexNum(4,10,DataB[3], 2);
        Delay_ms(1000);
        MyDMA_Tansfer();
        OLED_ShowString(1,1,"DataA");
        OLED_ShowString(3,1,"DataB");
        OLED_ShowHexNum(1,7,(uint32_t)DataA, 8);
        OLED_ShowHexNum(3,7,(uint32_t)DataB, 8);
        OLED_ShowHexNum(2,1,DataA[0], 2);
        OLED_ShowHexNum(2,4,DataA[1], 2);
        OLED_ShowHexNum(2,7,DataA[2], 2);
        OLED_ShowHexNum(2,10,DataA[3], 2);
        OLED_ShowHexNum(4,1,DataB[0], 2);
        OLED_ShowHexNum(4,4,DataB[1], 2);
        OLED_ShowHexNum(4,7,DataB[2], 2);
        OLED_ShowHexNum(4,10,DataB[3], 2);
        Delay_ms(1000);
	}
}



















































































