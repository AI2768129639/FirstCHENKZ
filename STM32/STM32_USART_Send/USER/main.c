#include "stm32f10x.h"
#include "OLED.h"
#include "chuankou.h"
int main (void){
	OLED_Init();
	chuankou_Init();

    //打印案例
    chuankou_Output(0x41);
    uint8_t my_Array[] = {0x42, 0x43, 0x44, 0x45};
    chuankou_SendArray(my_Array, sizeof(my_Array)/sizeof(my_Array[0]));
    chuankou_SendString("\r\nYES");
    chuankou_SendNum(1989964);
    printf("\r\n");
    printf("NUM = %d", 666);
    chuankou_printf("\r\nnum = %d", 666);
    char Sting[100];
    sprintf(Sting, "\r\nNum = %d", 555);
    chuankou_SendString(Sting);

	while (1){

	}
}














































































