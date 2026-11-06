# STM32 学习代码（江科大教程）

- 开发板：STM32F103C8T6（江科大套件）
- 环境：Keil MDK 5.43 + ARM Compiler 6（AC6）+ 标准外设库 V3.5.0
- 最后同步：2026-11-06（共 22 个 Keil 工程）
- 说明：只包含源码、Keil 工程文件与 VS Code 跳转配置；已排除 `Objects/`、`Listings/` 等编译产物和窗口布局文件（见仓库根的 `.gitignore`）。
- 打开方式：用 Keil 打开各工程目录下的 `beginproject.uvprojx`，直接 F7 编译。

| 工程 | 内容 |
|---|---|
| `STM32_LED_begin` | GPIO 输出入门：点灯 / 闪烁 |
| `STM32_LED_Dynamic` | GPIO 输出：流水灯 |
| `STM32_GPIO_input` | GPIO 输入：按键控制 LED |
| `STM32_Sound` | 蜂鸣器发声 |
| `STM32_lightcontrol_sound` | 光敏传感器控制蜂鸣器 |
| `STM32_Light_count` | 计数传感器 + OLED 显示 |
| `STM32_OLED` | OLED 显示（江科大 4-1 驱动） |
| `STM32_Timer` | 定时器中断：计数与显示 |
| `STM32_Timer _Infrared_sensor` | 定时器中断练习（进阶） |
| `STM32_Timer_Hardware_Input` | 定时器编码器接口（硬件输入） |
| `STM32_PWM_LED_Breath` | PWM 输出：LED 呼吸灯 |
| `STM32_PWM_Input_Ouput` | PWM 输入捕获：测频率 |
| `STM32_PWM_Input_Ouput_pro` | PWM 输入捕获进阶：频率 + 占空比 |
| `STM32_PWM_Sprial` | PWM 调速练习（按键 + 多路输出） |
| `STM32_PWM_Steering_machine` | PWM 控制舵机 |
| `STM32_AD_signed` | ADC 单通道采集 + 电压换算显示 |
| `STM32_AD_multiple` | ADC 多通道采集（4 路） |
| `STM32_DMA_Inside_Transport` | DMA 存储器到存储器转运 |
| `STM32_DMA_AD_Transport` | DMA + ADC 多通道转运 |
| `STM32_USART_Send` | 串口发送（含 printf 重定向） |
| `STM32_USART_Recept` | 串口接收（中断）+ OLED 十六进制显示 |
| `______________CODE_CONTENT` | 课程笔记（`USER/main.c` 为各章笔记注释） |

> 各工程具体功能以对应 `USER/main.c` 和 `Hardware/` 下的代码为准。
>
> 另：`STM32_Timer _Infrared_sensor`、`STM32_Timer_Hardware_Input` 目录内各带一份 `STM32_Timer/` 子目录副本，为本地原样保留。
