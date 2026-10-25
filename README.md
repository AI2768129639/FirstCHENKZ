# FirstCHENKZ

成都大学 人工智能专业 2026 级 · 学习代码仓库

## 目录

| 目录 | 内容 |
|---|---|
| `Basic_grammar/`、`function/`、`boss/` | C 语言练习（翁恺课程，Visual Studio 工程） |
| `STM32/` | STM32 学习代码（江科大教程，Keil MDK + AC6，STM32F103C8T6） |

## STM32 工程

`STM32/` 下共 7 个 Keil 工程：

- `STM32LED_begin` — 点灯
- `STM32LED_Dynamic` — 流水灯
- `STM32_GPIO_input` — 按键输入
- `STM32_Sound` — 蜂鸣器
- `STM32_lightcontrol_sound` — 光敏传感器控制蜂鸣器
- `STM32_Light_count` — 计数传感器 + OLED
- `STM32_OLED` — OLED 显示（江科大 4-1 驱动）

打开方式：Keil 打开对应工程目录下的 `beginproject.uvprojx`，F7 编译。

仓库只保存源码与工程文件；编译产物（`Objects/`、`Listings/` 等）已用 `.gitignore` 排除。

## 说明

- 本仓库用于保存学习代码与备份，按学习进度逐步添加。
- 本地上传目录：`D:\work\Code\STM32_projects`（STM32）、`D:\work\Code\C_language`（C 语言）。
- 原学习目录 `D:\STM32Project` 保持原样，不作为 git 仓库。
