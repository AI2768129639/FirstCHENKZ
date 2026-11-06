#ifndef __CHUANKOU_H
#define __CHUANKOU_H
#include <stdio.h>
#include <stdarg.h>
void chuankou_Output(uint8_t byte);
void chuankou_Init(void);
void chuankou_SendArray(uint8_t *Array, uint32_t length);
void chuankou_SendString(char* string);
void chuankou_SendNum(uint32_t Num);
#endif
