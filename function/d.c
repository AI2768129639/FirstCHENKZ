#define _CRT_SECURE_NO_WARNINGS

//宏定义
//编译预处理指令
//#define  定义宏
//#include  引入头文件

//如   #define PI 3.1415926  PI是一个宏的名字  3.1415926是这个宏的值
//如   #define EOF -1

//相当于代号  便于理清

//格式  名字必须是一个单词  值可以是任何东西

//在编译之前  预处理程序会把程序中的宏的名字换成对应的值

//宏中有宏  后面的宏也会被替换

//宏定义的值超过一行  最后一行之前的航模要加\

//没有值的宏 可以用来做判断
/*
#include <stdio.h>
#define PI 3.14
#define PI2 PI*2
#define FORMAT "%f\n"
#define P printf("%f\n", PI);\
		  printf("%f\n", PI2)
int main() {
	printf(FORMAT, PI2);
	P;
	return 0;
}
*/




//带参数的宏  所有的参数都要有括号  反正就是全部打括号
/*
#define cube(x) ((x)*(x)*(x))//所有边长为X的立方体的体积

int main() {
	int i;
	scnaf("%d", &i);
	printf("%d\n", cube(i));

	return 0;
}
*/







//include  引入头文件  <>写系统自带的头文件   ""写自己编写的头文件
//函数主体写到一个.c里    原型说明写到同名的.h里         在主文件里用#include调用


//全局变量可以在多个.c之间共享  在函数或全局变量前加上static 就可以使其只能在其所在的编译单元中使用




//全局变量的共享
//在一个a.c文件里定义了一个全局变量int A = 1;          那么就要在a.h里声明    extern int A;
//同样的在a.c里写了一个函数或结构程序 也要在a.h进行声明


//防止重复定义的标准头文件结构    在.h文件引入
#ifndef A
#define A

//代码
//代码
//.........

#endif 






//函数指针
//每个函数有地址
//单独的一个函数名字就是其地址
//用一个指针可以指向函数的地址
//这个指针的类型是void的类型
//格式为  void指针类型 (*p指针) (该函数的参数表) = function函数名;
//这样通过*p就可以像函数名一样调用函数

/*
void f(int i) {
	printf("%d\n", i);
}
int main() {
	void(*p)(void) = main;
	printf("%p\n", main);
	printf("%p\n", p);

	void(*q)(int) = f;
	f(10);
	(*q)(10);

	//函数指针的应用



	return 0;
}
*/



/*
#include<stdio.h>
void f() {
	printf("use 1");
}
void g() {
	printf("use 2");
}
void h() {
	printf("use 3");
}
void j() {
	printf("use 4");
}
void k() {
	printf("use 5");
}


int main(void) {
	int i = 0;
	void(*p[])() = { f,g,h,j,k, };

	scanf("%d", &i);
	if (i >= 0 && i < sizeof(p) / sizeof(p[0])) {
		(*p[i]);
	}
	return 0;
}
*/



//函数指针可以满足单一出口的原则
// 比如 有很多加减乘除的函数需要调用
// 这时就写一个接受这类型函数的函数
// 这样每次运算就要经过单一函数出口
//加法函数
/*
#include<stdio.h>

int plus(int a, int b) {
	int c = 0;
	c = a + b;

	return c;
}
int minus(int a, int b) {
	int c = 0;
	c = a - b;

	return c;
}
void output(int (*p)(int, int)) {//一个叫做output的函数用来接受函数的操作
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", (*p)(a, b));
}
int main() {
	output(plus);
	output(minus);

	return 0;
}
*/







//格式化的输入输出
/*
printf("%9d"， 123)表示输出123时要占据9个字符的空间  123前面用空位填充
printf("%-9d"， 123)表示输出123时要占据9个字符的空间 但是要把有意义的数字向左对齐
printf("%+9d"， 123)表示输出123时要占据9个字符的空间 输出+123
printf("%09d"， 123)表示输出123时要占据9个字符的空间 123前面用0填充
printf("%9.2f"， 123)表示输出123.00时要占据9个字符的空间 输出时保留2位小数
printf("%*d"，6, 123)表示输出123时要占据6个字符的空间  6对应*  123对应d
*/

//输出类型
/*
| `i` 或 `d` | `int`                       | `g` | `float` |
| `u` | `unsigned int`                     | `G` | `float` |
| `o` | 八进制                             | `a` 或 `A` | 十六进制浮点 |
| `x` | 十六进制                           | `c` | `char` |
| `X` | 字母大写的十六进制                 | `s` | 字符串 |
| `f` 或 `F` | `float, 6`                  | `p` | 指针 |
| `e` 或 `E` | 指数                        | `n` | 读入/写出的个数 |

**说明**：最上面的格式是 `%[flags][width][.prec][hIL]type`，你平时用最多的是 `%d`（整数）、`%f`（浮点数）、`%c`（字符）、`%s`（字符串）和 `%p`（指针）。

*/

//scanf("*%d%d")表示跳过第一个读入的数 只读入第二个数
//scanf("%d")
//scanf printf  是有返回值的 scanf返回读入了几个数据  printf返回输出多少字符 包括\n '\0' 等







//文件操作
/*
#include<stdio.h>

int main() {
	FILE* fp = fopen("", "r");//第一个参数是你要打开的文件名因为我没有就先空着
	//第二个参数是要执行的东西
	if (fp != NULL) {
		int num;
		fscanf(fp, "%d", &num);
		printf("%d\n", num);
		fclose(fp);
	}else {
		printf("Can not open file");
	}

	return 0;
}
*/
/*
fopen 模式表：第二参数

r：打开只读

r+：打开读写，从文件头开始

w：打开只写。如果不存在则新建，如果存在则清空

w+：打开读写。如果不存在则新建，如果存在则清空

a：打开追加。如果不存在则新建，如果存在则从文件尾开始

...x：只新建，如果文件已存在则不能打开
*/





//逻辑运算  按位运算
//逻辑运算相当于把所有非0值变成1  再做按位运算

//按位运算在c语言书本上有知识 不详细注释

//例

#include<stdio.h>

int main(int argc, char* argv[]) {
	int num;
	scanf("%d", &num);
	unsigned int mask = 1u << 31;
	for (;mask; mask >>= 1) {
		printf("%d", num & mask ? 1 : 0);
	}
	printf("\n");

	return 0;
}











































































































