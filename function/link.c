
#define _CRT_SECURE_NO_WARNINGS
#include "link.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct node* next;
}node;


typedef struct List {
	node* head; 
	//node* tail;
}list;

void add(list* p, int num);
void output(list* q);
void search(list* q);
void delate(list* q);
void destruct(list* q);

int main(int argc, char const* argv[]) {
	int number = 0;
	list flist;
	flist.head = NULL;// flist.tail = NULL
	do {//制造循环读入数字
		scanf("%d", &number);
		if (number != -1) {
			add(&flist, number);
		}
	} while (number != -1);
	output(&flist);
	search(&flist);
	delate(&flist);

	return 0;
}
void delate(list* q) {
	node* p;
	node* r;
	int num;
	scanf("%d", &num);
	for (r = NULL, p = q->head; p != NULL; r = p, p = p->next) {
		if (p->data == num) {
			if (r != NULL) {
				r->next = p->next;
				free(p);
				printf("free%dpoint", *p);
				break;
			}else {
				q->head = p->next;
				free(p);
				printf("free%dpoint", *p);
				break;
			}
		}
		else {
			printf("erorr!");
		}
	}
}
void search(list* q) {
	node* p;
	int num;
	int found = 0;
	scanf("%d", &num);
	for (p = q->head;p != NULL; p = p->next) {
		if (p->data == num) {
			found = 1;
			printf("num in link");
			break;
		}
	}
	if (found == 0) {
		printf("num not in link");
	}
}
void output(list* q) {
	node* p;
	for (p = q->head; p != NULL; p = p->next) {
		printf("%d\t", (*p).data);
		printf("\n");
	}
}
void add(list* p, int num) {
	node* tp = (node*)malloc(sizeof(node));//每读入一个新节点就malloc一个新地址给这个数字
	tp->data = num;//传入数据
	tp->next = NULL;//使下一个node类型的指针为NULL 保证传入的这个数据是最后一个且后一个为NULL
	node* last = p->head;//建立一个临时指针last 从head所指向的地址开始往后寻找结尾
	if (last != NULL) {//判断last现在所指向的这个地址是否为NULL 如果是证明head也是NULL 跳到else那里
		while (last->next != NULL) {//当last->next不是NULL 证明last还没走到结尾
			last = last->next;//就让last向后走一个
		}last->next = tp;//当last走到了倒数第二个 就让最后一个节点值等于该tp指针所指向的值
	}
	else {
		p->head = tp;//当输入第一个数时 head = last = NULL  所以head直接指向tp这个指针所指向的数字
	}
}
//改进
/*
void add(list* p, int num) {
	node* tp = (node*)malloc(sizeof(node));
	tp->data = num;
	tp->next = NULL;
	if (p->head == NULL) {
		p->head = tp;
		p->tail = tp;
	}
	else {
		p->tail = p->tail->next = tp;
	}
}

void destruct(list* q) {
	node* r = NULL;
	node* p;
	for (p = q->head; p != NULL; p = r) {
		r = p->next;
		free(p);
	}
}
*/



































































