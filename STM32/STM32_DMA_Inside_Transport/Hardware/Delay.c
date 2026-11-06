#include "Delay.h"
#include "stm32f10x.h"
/**
  * @brief  微秒级延时 (基于SysTick)
  * @param  xus: 要延时的微秒数 (最大约 233015 us)
  * @retval 无
  * @note   使用 72MHz 主频计算，不依赖中断，纯轮询
  */
void Delay_us(uint32_t xus) {
    uint32_t temp;
    // 设置重装载值 (72MHz下，1us需要计数72次)
    SysTick->LOAD = 72 * xus;
    // 清空当前计数值
    SysTick->VAL = 0x00000000;
    // 配置SysTick：时钟源选择HCLK(72MHz)，启动定时器，关闭中断
    SysTick->CTRL = 0x00000005;

    // 等待计数到 0 (Bit 16 是 COUNTFLAG 标志位)
    do {
        temp = SysTick->CTRL;
    } while((temp & 0x01) && !(temp & (1 << 16))); // 确保定时器还在运行且未到0

    // 关闭定时器
    SysTick->CTRL = 0x00000000;
}

/**
  * @brief  毫秒级延时
  * @param  xms: 要延时的毫秒数
  * @retval 无
  */
void Delay_ms(uint32_t xms) {
    while(xms--) {
        Delay_us(1000); // 每次延时 1000us (即 1ms)
    }
}

/**
  * @brief  秒级延时
  * @param  xs: 要延时的秒数
  * @retval 无
  */
void Delay_s(uint32_t xs) {
    while(xs--) {
        Delay_ms(1000);
    }
}