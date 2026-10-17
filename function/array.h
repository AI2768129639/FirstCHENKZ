#pragma once
#include <stdio.h>
#include <stdlib.h>
#ifndef _ARRAY_H_
#define _ARRAY_H_


//可变数组

typedef struct {
	int* data;
	int size;
} Array;
Array array_create(int input_size);
void array_free(Array* p);
int array_inquire_size(const Array* p);
int* array_at(Array* p, int index);
int array_get(Array* p, int index);
Array* array_input(Array* p);
void array_inflate(Array* a, int more_size);
#endif


	

























































































