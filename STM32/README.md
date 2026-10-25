# STM32 学习代码（江科大教程）

- 开发板：STM32F103C8T6（江科大套件）
- 环境：Keil MDK 5.43 + ARM Compiler 6（AC6）
- 上传日期：2026-10-25
- 说明：只包含源码与 Keil 工程文件；已经排除 `Objects/`、`Listings/` 等编译产物和窗口布局文件（见 `.gitignore`）。
- 打开方式：用 Keil 打开各工程目录下的 `beginproject.uvprojx`，直接 F7 编译。

| 工程 | 内容 |
|---|---|
| `STM32LED_begin` | GPIO 输出入门：点灯 |
| `STM32LED_Dynamic` | LED 流水灯 |
| `STM32_GPIO_input` | GPIO 输入：按键控制 LED |
| `STM32_Sound` | 蜂鸣器 |
| `STM32_lightcontrol_sound` | 光敏传感器控制蜂鸣器 |
| `STM32_Light_count` | 计数传感器 + OLED 显示 |
| `STM32_OLED` | OLED 显示（江科大 4-1 驱动） |

> 各工程具体功能以对应 `USER/main.c` 和 `Hardware/` 下的代码为准。
