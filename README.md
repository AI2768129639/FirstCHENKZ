# FirstCHENKZ

成都大学 人工智能专业 2026 级 · 学习代码仓库

## 目录

| 目录 | 内容 |
|---|---|
| `Basic_grammar/`、`function/`、`boss/` | C 语言练习（翁恺课程，Visual Studio 工程） |
| `STM32/` | STM32 学习代码（江科大教程，Keil MDK + AC6，STM32F103C8T6） |

## STM32 工程

`STM32/` 下共 22 个 Keil 工程（最后同步：2026-11-06），详细列表见 [`STM32/README.md`](STM32/README.md)：

- `STM32_LED_begin` — 点灯 / 闪烁
- `STM32_LED_Dynamic` — 流水灯
- `STM32_GPIO_input` — 按键输入
- `STM32_Sound` — 蜂鸣器
- `STM32_lightcontrol_sound` — 光敏传感器控制蜂鸣器
- `STM32_Light_count` — 计数传感器 + OLED
- `STM32_OLED` — OLED 显示
- `STM32_Timer` — 定时器中断
- `STM32_Timer _Infrared_sensor` — 定时器中断（进阶）
- `STM32_Timer_Hardware_Input` — 定时器编码器接口
- `STM32_PWM_LED_Breath` — PWM 呼吸灯
- `STM32_PWM_Input_Ouput` — PWM 输入捕获
- `STM32_PWM_Input_Ouput_pro` — PWM 输入捕获（进阶）
- `STM32_PWM_Sprial` — PWM 调速练习
- `STM32_PWM_Steering_machine` — PWM 舵机
- `STM32_AD_signed` — ADC 采集 + 电压显示
- `STM32_AD_multiple` — ADC 多通道
- `STM32_DMA_Inside_Transport` — DMA 内存转运
- `STM32_DMA_AD_Transport` — DMA + ADC
- `STM32_USART_Send` — 串口发送
- `STM32_USART_Recept` — 串口接收
- `______________CODE_CONTENT` — 课程笔记

打开方式：Keil 打开对应工程目录下的 `beginproject.uvprojx`，F7 编译。

仓库只保存源码与工程文件；编译产物（`Objects/`、`Listings/` 等）已用 `.gitignore` 排除。

## 说明

- 本仓库用于保存学习代码与备份，按学习进度逐步添加。
- 本地上传目录：`D:\work\Code\STM32_projects`（STM32）、`D:\work\Code\C_language`（C 语言）。
- 原学习目录 `D:\STM32Project` 保持原样，不作为 git 仓库。
