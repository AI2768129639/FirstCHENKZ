#define _CRT_SECURE_NO_WARNINGS
#include"array.h"


//可变数组
/*
typedef struct {
	int* data;
	int size;
} Array;
*/
/*
const BLOCK_SIZE = 10;
Array array_create(int input_size) {
	Array temporary_a;
	temporary_a.size = input_size;
	temporary_a.data = (int*)malloc(temporary_a.size * sizeof(int));
	return temporary_a;
}
void array_free(Array* p) {
	free(p->data);
	p->size = 0;
	p->data = NULL;
}
int array_inquire_size(const Array* p) {
	printf("%d", p->size);
	return p->size;
}
int* array_at(Array* p, int index) {
	if (index >= p->size) {
		array_inflate(p, ((index / BLOCK_SIZE + 1) * BLOCK_SIZE) - (p->size));
	}
	return &(p->data[index]);
}
int array_get(Array* p, int index) {
	return p->data[index];
}
Array* array_input(Array* p) {
	int count = 0;
	for (int i = 0;; i++) {
		int temporary_num = 0;
		printf("input num:(When the num == -1 ,over)");
		scanf("%d", &temporary_num);
		if (temporary_num == -1) {
			break;
		}
		else {
			*array_at(p, count) = temporary_num;
			count++;
		}
	} 
	for (int i = 0; i < count; i++) {
		printf("The %d num is %d\t", i, *array_at(p, i));
	}
	return p;
}
void array_inflate(Array* p, int more_size) {
	int* q = (int*)malloc((sizeof(int)) * (p->size + more_size));//给出一个扩展的新地址
	for (int i = 0; i < p->size; i++) {
		q[i] = (p->data)[i];//传递原地址的数据
	}free(p->data);//释放原地址
	p->data = q;//将data的地址改为新地址的值
	p->size += more_size;//对齐数组大小
}
*/
//可变数组
/*
int main(int argc, char* argv[]) {
	Array a = array_create(10);
	printf("size = %d\n", array_inqure_size(&a));
	array_input(&a);
	array_free(&a);
	return 0;
}
*/
























































