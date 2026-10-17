#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// 求素数 的个数以及其和

/*
int main()
{
	int max_num;
	int min_num;

	printf("input max_num and min_num :\n");
	scanf("%d %d", &max_num, &min_num);
	int sum = 0;
	int count = 0;

	int i;

	if (min_num == 1) {
		min_num = 2;
	}
	for (i = min_num; i <= max_num; i++) {

		int q = 1;
		int j;
		for (j = 2; j < i - 1; j++) {
			if (i % j == 0) {
				q = 0;
				break;
			}
		}
		if (q == 1) {
			sum += i;
			count++;
		}
	}
	printf(" all sushu = %d number = %d", sum, count);

	return 0;
}
*/




// 定义函数
/*
int q(int i) {
	int m = 1; 
	int j;
	for (j = 2; j < i - 1; j++) {
		if (i % j == 0) {
			m = 0;
			break;
		}
	}
	return m;
}
int main()
{
	int max_num;
	int min_num;

	printf("input min_num and max_num :\n");
	scanf("%d %d", &min_num, &max_num);
	int sum = 0;
	int count = 0;

	int i;

	if (min_num == 1) {
		min_num = 2;
	}
	for (i = min_num; i <= max_num; i++) {
		if (q(i) == 1) {
			sum += i;
			count++;

		}
	}
	printf(" all sushu = %d number = %d", sum, count);

	return 0;
}
*/








// 求和函数 自己定义函数减少重复函数
/*
void sum(int begin, int end) {

	int i;
	int sum = 0;
	for (i = begin; i <= end; i++) {
		sum += i;
	}
	printf("%d to %d sum = %d ", begin, end, sum);
}
int main() {
	int begin;
	int end;
	printf("input begin and end :\n");
	scanf("%d %d", &begin, &end);
	sum(begin, end);

	return 0;
}
*/



// 函数定义及其基础语法

//void/*返回类型*/ sum/*函数名*/(int begin, int end/*参数表*/)/* 函数头*/ {    //括号内是函数体
//
//	int i;
//	int sum = 0;
//	for (i = begin; i <= end; i++) {
//		sum += i;
//	}
//	printf("%d to %d sum = %d ", begin, end, sum);
//}



//void指不返回任何类型 其他要返回的就是 int double char float long short long long 等等
// 调用函数要加括号  例如 sum(1, 10) 这样调用函数  若函数没有参数 也要加括号 例如 sum() 这样调用函数






// 函数的返回
//return 会停止函数的执行 并返回一个值 例如 return 0; 这样就会返回一个整数0
//当然 也可以返回一个变量 例如 return sum; 这样就会返回一个整数sum
//return 也可以返回一个表达式 例如 return a + b; 这样就会返回一个整数a + b
//return 也可以返回一个函数 例如 return sum(a, b); 这样就会返回一个整数sum(a, b)
//return 也可以返回一个指针 例如 return &a; 这样就会返回一个指针&a
//return 也可以返回一个结构体 例如 return s; 这样就会返回一个结构体s
//return 也可以返回一个联合体 例如 return u; 这样就会返回一个联合体u
//return 也可以返回一个枚举 例如 return e; 这样就会返回一个枚举e
//return 也可以返回一个数组 例如 return a; 这样就会返回一个数组a
//return 也可以返回一个函数指针 例如 return &sum; 这样就会返回一个函数指针&sum
//return 也可以返回一个 void 指针 例如 return NULL; 这样就会返回一个 void 指针NULL
//return 也可以返回一个 const 指针 例如 return &a; 这样就会返回一个 const 指针&a
//return 也可以返回一个 volatile 指针 例如 return &a; 这样就会返回一个 volatile 指针&a
//return 也可以返回一个 restrict 指针 例如 return &a; 这样就会返回一个 restrict 指针&a
//return 也可以返回一个 _Atomic 指针 例如 return &a; 这样就会返回一个 _Atomic 指针&a
//return 也可以返回一个 _Noreturn 指针 例如 return &a; 这样就会返回一个 _Noreturn 指针&a
//return 也可以返回一个 _Thread_local 指针 例如 return &a; 这样就会返回一个 _Thread_local 指针&a
//return 也可以返回一个 _Alignas 指针 例如 return &a; 这样就会返回一个 _Alignas 指针&a
//return 也可以返回一个 _Alignof 指针 例如 return &a; 这样就会返回一个 _Alignof 指针&a
//return 也可以返回一个 _Static_assert 指针 例如 return &a; 这样就会返回一个 _Static_assert 指针&a
//所以return可以只当作结束 也就是 return; 这样就会结束函数的执行 但是不会返回任何值 也就是返回void
//如果要返回值 那就在后面加上要返回的值 例如 return sum; 这样就会返回一个整数sum
// 一个函数可以有多个return语句 但是只能有一个return语句被执行 也就是函数执行到return语句就会结束函数的执行 也就是return语句后面的代码不会被执行
// 保持单一出口原则 也就是一个函数只有一个return语句 这样可以提高代码的可读性和可维护性 也可以减少错误的发生 也可以提高代码的性能

/*
int number(int a){
	return a;
}
int main() {
	int a;
	printf("input a :\n");
	scanf("%d", &a);
	number(a);//直接调用
	int m = number(a);//赋值给变量
	printf("number = %d", number(a));//传递给函数

	return 0;
}

//void 函数没有返回值 也就是不需要返回任何值 也就是不需要return语句 也就是不需要return语句后面的值 
*/







//函数的原型声明
//当一个函数在main下面时 还想去调用的话 就必须在main函数上面 声明函数原型

/*
int sum(int a, int b);//原型声明 原型声明可以不加变量名 只留类型 例如 int sum(int, int);

int main() {//主函数 调用函数
	int a;
	int b;
	scanf("%d %d", &a, &b);

	return 0;
}

int sum(int a, int b) {// 函数定义
		return a + b;
}	
*/


// c语言在调用函数时 会自动转换你需要的类型 例如 int sum(int a, int b); 你传递的是float类型 也会自动转换为int类型 但是会丢失精度 例如 float a = 1.5; float b = 2.5; sum(a, b); 会自动转换为 int sum(int a, int b); 也就是 sum(1, 2); 这样就会丢失精度

// C语言在调用函数时 只是传值给函数 而不会去修改原始变量

// 例如一个交换数字的函数 并不会去交换数字
/*
int main() {
	int a;
	int b;
	scanf("%d %d", &a, &b);

	swap(a, b);

	printf("a = %d b = %d", a, b);

	return 0;

}

// 交换数字的函数中 a，b 和main函数里的a，b 不是一个东西 两对a，b没有任何关联
void swap(int a, int b) {
	int t;
	t = a;
	a = b;
	b = t;
}
*/

//局部变量的生存期和作用域
//生存期   指只在使用这个函数的时候 这个变量才有用
//作用域   指在定义这个变量的大括号内才可以使用这个变量
// 两个不同函数中的变量不互通 且只影响自身函数内的变量




// 在函数的参数表中放入void 表明不接受参数 如void function(void)



// 计算一组数平均数 并且列出大于平均数的数
/*
int main() {
	int x;
	int count = 0;
	double sum = 0;
	int number[100];
	do {
		scanf("%d", &x);
		if (x != -1) {
			number[count] = x;
			sum += x;
			count++;
		}
	} while (x != -1);

	if (count > 0) {
		printf("%f\n", sum / count);
		int i;
		for (i = 0; i < count; i++) {
			if (number[i] > sum / count){
				printf("%d\n", number[i]);
			}
		}
	}
	return 0;
}
*/


//数组的定义
//格式 ：数组中每个变量的类型  变量名称  【元素数量】；
// 数组单元从0开始 跟python的列表索引是一个道理

//统计个数
/*
int main(void) {
	int x;
	int count[10];
	for (int i = 0; i <= 9; i++) {//初始化数组的每个元素为0
		count[i] = 0;
	}
	
	do {
		printf("input x:");
		scanf("%d", &x);//录入数字
		if (x >= 0 && x <= 9) {
			count[x]++;//计数
		}
	} while (x != -1);

	for ( int i = 0; i <= 9; i++ ) {
		printf("%d have %d times\n", i, count[i]);
	}
	return 0;
}
*/
/*
int main(void) {
	int x;
	int count[10] = { 0 };//初始化数组的每个元素为0
	
	do {
		printf("input x:");
		scanf("%d", &x);//录入数字
		if (x >= 0 && x <= 9) {
			count[x]++;//计数
		}
	} while (x != -1);

	for (int i = 0; i <= 9; i++) {
		printf("%d have %d times\n", i, count[i]);
	}
	return 0;
}
*/

//数组的集成初始化

//当定义数组的时候中括号内写了元素的个数 但同时做集成化 但是集成化的数字不够时 会自动吧后续数字初始化为0 例如 int a[5] = {1, 2}; 那么a[0] = 1, a[1] = 2, a[2] = 0, a[3] = 0, a[4] = 0;

//定义集成数组时  可以用定位初始化 例如 int a[5] = { [0] = 1, [2] = 3 }; 那么a[0] = 1, a[1] = 0, a[2] = 3, a[3] = 0, a[4] = 0;

//sizeof 可以判断数组的大小 数组中每一个元素大小是四个字节 使用总字节/4 得到个数

//把一个数组的值赋给另一个数组 只能遍历








/*
int main(void) {
	int a[] = { 1,3,6,76,5,4,23,56,89,90,2,7,8,9 };
	int x;
	int len;
	int ret = 0;
	printf("input x:");
	scanf("%d", &x);
	len = (sizeof(a) / sizeof(a[0]));
	ret = search(a, x, len);
	if (ret != -1) {
		printf("%d have", x);
	}else {
		printf("%d not have", x);
	}
	return 0;
}
int search(int a[], int key, int len) {
	int ret = -1;
	for (int i = 0; i < len; i++) {
		if (a[i] == key) {
			ret = i;
			break;
		}
	}
	return ret;
}
*/


//判断素数进阶
/*
int main(void) {
	int x;
	scanf("%d", &x);
	if (int isPrime(x) == -1) {
		printf("%d yes sushi", x);
	}
	else {
		printf("%d no sushi", x);
	}
	return 0;
}

int isPrime(int x) {
	int ret = -1;
	int i;
	if (x == 1 || (x % 2 == 0 && x != 2)) {
		ret = 1;
	}
	for (i = 3; i < sqrt(x); i += 2) {
		if (x % i == 0) {
			ret = 1;
			break;
		}
	}
	return ret;
}
*/
/*
int main(void) {
	enum {NUMBER = 12};//构造数组
	int prime[NUMBER] = { 2 };//第一个位置等于2这个素数
	int count = 1;//从数组的第二个位置开始存储素数
	int i = 3;//从三开始判断素数
	
	{//输出表头
		int i;
		printf("\t\t\t");
		for (i = 0; i < NUMBER; i++) {
			printf("%d\t", i);
		}
		printf("\n");
	}

	while (count < NUMBER) {
		if (isPrime(i,prime,count) == -1) {//调用函数
			prime[count++] = i;//依次添加素数
		}
		{
			printf("i = %d\tcount = %d\t", i, count);//输出当前判断的数和素数的个数
			{
				int i;
				for (i = 0; i < NUMBER; i++) {
					printf("%d\t", prime[i]);//输出当前素数数组
				}
				printf("\n");
			}
		}
		i++;//往后判断
	}
	for (i = 0; i < NUMBER; i++) {
		printf("%d\n", prime[i]);//输出素数
	}
	return 0;
}

int isPrime(int x, int prime[], int count) {
	int ret = -1;
	int i;
	for (i = 0; i < count; i++) {
		if (x % prime[i] == 0) {//判断是否为素数
			ret = 1;
			break;
		}
	}
	return ret;
}
*/


/*
//构造素数表 素数代码 ：1表示素数 0表示非素数
int main(void) {
	enum { NUMBER = 1000 };
	int isprime[NUMBER];//构造数组
	int i;
	int x;
	for (i = 0; i < NUMBER; i++) {
		isprime[i] = 1;//初始化数组代码为1 假设全是素数
	}
	for (x = 2; x < NUMBER; x++) {//从数字2开始判断
		if (isprime[x] == 1) {//代码是1的是素数 这样就直接排除非素数
			for (i = 2; i * x < NUMBER; i++) {//找到素数的倍数
				isprime[i * x] = 0;//将素数的倍数代码改为0 
			}
		}
	}
	for (i = 2; i < NUMBER; i++) {//输出素数
		if (isprime[i] == 1) {
			printf("%d\n", i);
		}
	}
	printf("\n");
	return 0;
}
*/


// 多维数组
//二维数组的定义
//格式 ：数组中每个变量的类型  变量名称  【行数】【列数】；
//int a【3】【5】；表示三行五列的矩阵
/*
如:
a[0][0] a[0][1] a[0][2] a[0][3] a[0][4] 
a[1][0] a[1][1] a[1][2] a[1][3] a[1][4] 
a[2][0] a[2][1] a[2][2] a[2][3] a[2][4] 
*/

/*
二维数组的遍历
for (int i = 0; i < 行数; i++) {
	for (int j = 0; j < 列数; j++) {
		// 处理 a[i][j]
	}
}
*/

/*
二维数组的初始化 列数不可以省略 行数可以省略
int a[3][5] = { 
{1,2,3,4,5}, 
{6,7,8,9,10}, 
{11,12,13,14,15}, 
};
*/
/*
还可以这样初始化
int a[3][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
系统会自动按每行5个元素填充 分成三行
*/


/*
3 x 3 的井字游戏判断输赢
*/
/*
enum { SIZE = 3 };//3 * 3 的井字游戏
int board[SIZE][SIZE];//写出矩阵
int num_X = 0;
int num_O = 0;
int len = 0;
int result = 0;// 0 没人赢； 1 X赢； 2 O赢；
int main(void) {//输入棋盘
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	
	for (int i = 0; i < SIZE; i++) {//检查横排
		num_X = 0;
		num_O = 0;
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 1) {
				num_X++;
			}
			else if (board[i][j] == 2) {
				num_O++;
			}
		}
		if (num_X == SIZE) {
			result = 1;
		}
		else if (num_O == SIZE){
			result = 2;
		}
		
	}
	
	for (int j = 0; j < SIZE; j++) {//检查竖排
		num_X = 0;
		num_O = 0;
		for (int i = 0; i < SIZE; i++) {
			if (board[i][j] == 1) {
				num_X++;
			}
			else if (board[i][j] == 2) {
				num_O++;
			}	
		}
		if (num_X == SIZE) {
			result = 1;
		}
		else if (num_O == SIZE) {
			result = 2;
		}
	}
	{
		num_X = 0;
		num_O = 0;
		for (int i = 0; i < SIZE; i++) {//检查正对角线

			if (board[i][i] == 1) {
				num_X++;
			}
			else if (board[i][i] == 2) {
				num_O++;
			}
		if (num_X == SIZE) {
			result = 1;
		}
		else if (num_O == SIZE) {
			result = 2;
		}
		}
	}
	{
		num_X = 0;
		num_O = 0;
		for (int i = 0; i < SIZE; i++) {//检查反对角线
			if (board[i][SIZE - i - 1] == 1) {
				num_X++;
			}
			else if (board[i][SIZE - i - 1] == 2) {
				num_O++;
			}
		if (num_X == SIZE) {
			result = 1;
		}
		else if (num_O == SIZE) {
			result = 2;
		}
		}
	}
	if (result == 0) {//判定输赢
		printf("X=O");
	}
	else if (result == 1){
		printf("X win");
	}
	else if (result == 2){
		printf("O win");
	}
	return 0;
}
*/





//运算符&  获取变量的地址
//32位 64位 的取地址不一定一样
//输出一个变量的地址用%p  printf("%p", &i);
//&不能对没有地址的东西取地址
//堆栈 先写的变量在上
//相邻变量的地址是紧挨着的 例如两个int类型的变量相邻的话其内存就相差4个字节
//一个数组中相邻的单元的内存距离是4
/*
int main() {
	int a[10];

	printf("%p\n", &a);
	printf("%p\n", a);
	printf("%p\n", &a[0]);
	printf("%p\n", &a[1]);

	return 0;
}
*/

//指针  用于保存地址类型的变量 用p表示

/*
int main() {
	int i;  //定义一个整数类型的变量
	int* p = &i;//将这个整数类型的变量的地址提取并存储到p这个指针中
	int* p, i;//这种写法的意思同上
	// 当指针p的内容是变量i的地址时 我们称p指向i
}
*/



/*
int main(void) {
	int i = 6;
	printf("&i = %p\n", &i);
	f(&i);
	g(i);
	return 0;
}

void f(int* p) {//获取了i这个变量的地址 使得p指向i 联系起了i和p
	printf("p = %p\n", p);//输出地址
	printf("*p = %d\n", *p);//输出这个地址的值
	*p = 7;//i这个变量的地址是p 所以*p就完全等于i变量 而不是仅仅是值相同 
	//所以改变*p 就是改变了i变量  而不是简单的变量值的传递 
	
}

void g(int k) {//仅仅只是传递了i变量的值给k i 与 k 无关 只是值相同
	printf("k = %d", k);
}
*/



//* 是一个运算符 用来访问一个指针的值所表示的地址所对应的变量 
// 也就是说指针p存放地址  而*p相当于这个地址所对应的变量值





// 指针应用 当函数返回值不止一个时 这时return就不够用了 就只能用指针传参

// 交换变量值
/*
void swap(int* pa, int* pb);

int main(void) {
	int a = 1;
	int b = 2;
	swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}

void swap(int* pa, int* pb) {
	int t = *pa;
	*pa = *pb;
	*pb = t;
}
*/


/*
void f(int a[], int len, int* min, int* max);

int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9,0, };
	int min, max;
	f(a, sizeof(a) / sizeof(a[0]), &min, &max);
	printf("min = %d max = %d", min,max);

	return 0;
}
*/
/*
void f(int a[], int len, int* min, int* max) {
	int i;
	*min = *max = a[0];
	for (i = 1; i < len; i++) {
		if (a[i] < *min) {
			*min = a[i];
		}
		if (a[i] > *max) {
			*max = a[i];
		}
	}
}
*/

/*
int divide(double a, double b, double* output);

int main(void) {
	double a;
	double b;
	double c;
	scanf("%lf", &a);
	scanf("%lf", &b);
	if (divide(a, b, &c) == 0) {
		printf("result = %.3lf", c);
	}
	else {
		printf("error");
	}
	return 0;
}

int divide(double a, double b, double* output) {
	int ret = 0;
	if (b == 0) {
		ret = -1;
	}
	else {
		*output = (a / b);
	}
	return ret;
}
*/



//函数参数表里的数组其实就是指针也就是在 void f(int a[])中 可以写成void f(int *a)


//数组变量本身就是特殊的指针 表达的是地址
//int a[10]; int* p = a; 取数组的地址不需要用&取地址符号
//但是数组中的单元是变量 要用取地址符&
//一个数组的地址就是第0个索引的单元的地址
// 也就是说数组和指针是等价的
//当我们用*p来代表一个指针时 也可以把这个指针当作一个长度为1的数组
// 于是我们可以使用  p[0] == *p
// 反过来 一个数组的地址表达可以用 a[0] 和 *a



//数组是常量const指针 所以不能被赋值如a[] = b 只能定义

//指针加上const 表示该指针是常量了 如 int* const q = &i;
//以后这个指针就永远只能指向这个地址了

/*
指针不可修改

int* const q = &i;
此时i这个变量不是常量
所以可以让*q = 100;
也就是相当于改变了i的值 但未改变地址 改变了此地址上的值

所以 加上const后 地址不能改变 地址上的值可以改变

也就是说q代表一个地址 q是常量 q只能指向&i这个地址
但是*q不是地址 是q这个地址上的值 而这个值可以改变*/


/*
通过指针不可修改

const int* p = &i;
或
int const* p = &i;

等价


是指*p不能改变
依然可以用i去赋值 用p去取地址
不能用*p去赋值*/




/*
数组本身就是const
如果在数组前再加const
就代表这个数组中每个元素都是const
这样可以保护数组不被修改*/




/*
当我们再指针上加一时 实则是加了一个这个指针类型的sizeof  比如int加4  char加1
因为数组是指针 且地址默认是数组[0] 若用*p表示数组[0] 那么*(p + 1)就是数组[1]
所以  *(p + n) <==> 数组[n]
同理 指针的 ++ ——  -=  +=  +-  道理相同
int main() {
	char ac[] = { 0,1,2,3,4,5,6,7,8,9, };
	char* p = ac;
	int ai[] = { 0,1,2,3,4,5,6,7,8,9, };
	int* q = ai;
	long long al[] = { 0,1,2,3,4,5,6,7,8,9, };
	long long* r = al;
	printf("p = %p\n", p);
	printf("p + 1 = %p\n", p + 1);
	printf("q = %p\n", q);
	printf("q + 1 = %p\n", q +  1);
	printf("r = %p\n", r);
	printf("r + 1 = %p\n", r + 1);
	printf("*p = %d\n", *p);
	printf("*(p + 1) = %d\n", *(p + 1));

	return 0;
}
*/


/*
两个地址相减
就是两个地址的16进制的值相减
然后再除以这两个地址的sizeof
相当于告诉你这两个地址中间有多少个单元
*/


//地址++的用法  遍历

/*
int main(void) {
	int ai[] = { 0,1,2,3,4,5,6,7,8,9,-1, };
	int i;
	int* p = ai;
	for (i = 0; i < sizeof(ai) / sizeof(ai[0]); i++) {
		if (ai[i] != -1) {
			printf("%d\n", ai[i]);
		}
	}
	for (p = ai; *p != -1; ) {
		printf("%d\n", *p++);
	}

	return 0;
	
}
*/


//指针可以比较大小 == 《=  》= 比较的是地址
//0地址非常特殊  用NULL来代表指针的初始化




//指针的类型转换  不推荐
//void*表示不知道指向什么的指针  计算时当作char类型



// 动态内存分配
// 向malloc申请的空间是字节类型  所以要乘sizeof(类型)
//malloc函数返回void类型 用来定义数组的位数的话要看数组接受的是什么类型的元素
// 并且要做类型转换
/*
#include<stdlib.h>

int main() {
	int num;
	int* p = 0;
	int* q = 0;
	printf("input numbers");
	scanf("%d", &num);
	p = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num - 1; i++) {
		printf("input numbers(%d)", i);
		scanf("%d", &p[i]);    
	}
	p[num - 1] = -1;
	for (q = p;*q != -1;) {
		printf("%d\t", *q++);
	}
	free(p);
	return 0;
}
*/
//free函数与malloc配套  你malloc了什么地址  就要free什么地址
// 不可以说malloc了一个 p free一个 p++  这是不行的
//同理 也不可以free一个没有malloc的地址

//字符串
/*
char word[] = { 'H','e','l','l','o','\0' };
char word[] = { 'H','e','l','l','o',0 };
//以0或‘\0’结尾的字符串才是字符串  0 '\0'代表字符串的结束 但不是字符串的部分
//计算字符串的长度时不包含0
//字符串以数组形式存在 用数组或指针访问

//字符串的变量
char* str = "Hello";
char word[] = "Hello";
char line[10] = "Hello";
*/
//字符串会自动在字符串后面加上'\0'  所以会多占一个字节
//c语言的字符串以字符数组形式存在
//不能用运算符对字符串做运算
//通过数组的方式可以遍历字符串

//char* s = "Hello";
//s是一个指针  初始化指向一个字符串常量
//这个字符串被存在一个只能读不能写的地方  所以实际上s是const char* s

//如果想对字符串修改  用数组
//char s[] = "Hello";

//总结
//用指针定义字符串 不可修改 因为指针指向这个字符串的地方在常量处
//用数组定义字符串 可以修改 因为字符串就在数组那里

/*
int main() {
	char* s = "Hello";
	char* s1 = "Hello";
	char a[] = "Hello";
	printf("s = %p\n", s);
	printf("s1 = %p\n", s1);
	printf("a = %p", a[0]);

	return 0;
}
*/

/*
因此
构造字符串用数组
处理字符串用指针
当字符串作为函数参数传入时用指针
动态分配内存时用指针*/

//字符串的输入和输出 用%s  scanf读字符时  读到空格或tab  就会停下

//scanf时 为了防止数组越界 可以在%和s中间加上最大字符个数
//比如 一个字符数组 char [8] 那么scanf时可以%7s
//使用指针定义字符串时 需要把指针初始化为0

//char buffer[] = "" 这样写是错误的  这样这个数组的长度就是1 且给了 '\0' 无意义
//定义空字符串可以 char buffer[n] = ""   n可以是任意常数

// char ** a  意思是a是一个指针 指向了另一个指针  那另一个指针指向了字符（串）

//char a[][10] 表示从a[0]到a[n]行  每行有一个char[10]这个字符串 界限为9字节
//char* a[] 表示从a[0]到a[n]都是一个一个的指针  每个指针都指向某处地址
/*
int main(int argc, char const* argv[]) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%d:%s\n", i, argv[i]);
	}
	return 0;
}
*/




/*
putchar 函数
int putchar(int c);
读取int类型
返回int类型
返回的int指的是写了几个字符
EOF(-1)表示失败

getchar 函数
int getchar(void)*/


/*

### 🌟 第一部分：为什么要有 `getchar` 和 `putchar`？

**因为快，而且省内存！**

`printf` 和 `scanf` 是“重型武器”。它们要处理各种格式（`%d`、`%s`、`%f`），要解析字符串，要分配缓冲区，非常消耗CPU和内存。

`getchar` 和 `putchar` 是“轻量级小刀”。
- `getchar()`：从键盘/文件输入流里，**只抠出来一个字符**。
- `putchar(c)`：向屏幕/文件输出流里，**只扔出去一个字符**。

以后你写单片机、Linux驱动、串口通信，如果为了打印一个调试字符还要用 `printf`，整个系统可能直接卡死。所以必须用 `putchar`，它短小精悍。

---

### 🌟 第二部分：为什么 `getchar` 返回 `int`，不返回 `char`？

这是你最大的困惑点。原因是：**为了能装下一个特殊的值——`EOF`（End of File，文件结束标志）。**

`EOF` 在C语言里被定义为 `-1`。
- 假设 `char` 是有符号的（VS默认）。它的范围是 `-128` 到 `127`。
- 你输入一个字符，如果是ASCII码，正常范围是 `0` 到 `127`。
- 但如果你输入了 `-1`，编译器就分不清这到底是你输入的合法字符，还是“文件结束”的 `EOF`。

**所以，C语言的设计者老奸巨猾，让 `getchar` 返回 `int`。**
它把一个正常的字符**强转提升**成 `int` 返回。比如你输入 `'A'`（ASCII码65），它返回 `65`。你输入文件结束标志，它返回 `-1`。
这样，只要判断 `if (c == -1)`，就知道是读完了，还是真的读到了这个字符。

---

### 🌟 第三部分：`Ctrl+C` 和 `Ctrl+Z` 到底有啥区别？

你被Windows和Linux的差异搞混了，现在分开讲：

**1. `Ctrl+C`（强制终止）：**
你按下 `Ctrl+C`，操作系统会向程序发送 **`SIGINT`（中断信号）**。
这相当于**警察直接一枪把你击毙**。程序立刻停止运行，什么收尾工作都不做。你以前在控制台跑死循环，按 `Ctrl+C` 就直接死了。

**2. `Ctrl+Z`（暂停/挂起）：**
在Linux里，按 `Ctrl+Z` 是发送 **`SIGTSTP`**，相当于**警察把你铐起来，关进小黑屋**。程序没死，只是暂停了。你可以用 `fg` 命令让它继续跑。
**但在Windows的控制台里（你用的VS）**，`Ctrl+Z` 不是用来暂停程序的，它是**告诉程序“输入流到此结束了”（相当于按了EOF）**。所以你写 `while ((c = getchar()) != EOF)`，在Windows下按 `Ctrl+Z` + 回车，程序就会以为输入结束了，跳出循环，正常退出。

**总结：**
- **`Ctrl+C`** = 暴力强杀，不给面子。
- **`Ctrl+Z`** = 在Linux是暂停，在Windows是告诉程序“我输入完了”。

---

### 🌟 第四部分：你该怎么用？

记住这三个铁律：
1. **必须用 `int` 来接 `getchar` 的返回值！**
   `int c; while ((c = getchar()) != EOF) { putchar(c); }`
   写成 `char c;` 在某些编译器上会变成死循环（因为它永远等不到 `-1`）。

2. **`EOF` 就是一个值为 `-1` 的宏。** 它存在于 `<stdio.h>` 里。

3. **在VS里测试时**：输入一堆字符，按回车，再按 `Ctrl+Z`，最后按回车。这就是告诉程序“我打完字了”，程序才会把缓冲区里的字符处理完并退出。

---

### 🚨 一、什么是“宏”（Macro）？为什么会有 `EOF`？

**“宏”说白了，就是个无脑的“文本替换”工具。**

C语言在正式编译你的代码之前，会先跑一个叫“预处理器”的东西。
`EOF` 不是一个变量，也不是个函数。它在 `<stdio.h>` 这个头文件里，其实就是长这样的一行代码：
```c
#define EOF (-1)
```
这行代码的意思就是告诉预处理器：“**以后你在代码里看到 `EOF`，就直接把它替换成 `-1`**”。

**为什么要有 `EOF`？**
因为程序经常要从文件里读数据，或者从键盘接收输入。你怎么知道数据读完了？
系统设计者就规定：用一个**专属的数字 `-1`** 来表示“数据读完了，没有更多内容了”。
为了让你写代码时看得懂，别满屏幕写 `-1`，就发明了 `EOF`（End Of File）这个宏。**它就是个代号，换汤不换药。**

---

### 🚨 二、你说用 `int` 来接 `getchar` 返回值，对不对？

**完全正确！你悟了！**

为什么要这样搞？因为 `char` 这个类型有两种：
*   在VS里默认是 `signed char`，范围是 `-128 ~ 127`。
*   在某些编译器里是 `unsigned char`，范围是 `0 ~ 255`。

如果你用 `char` 来接 `getchar()`：
*   遇到正常字符 `'A'`（ASCII 65），没问题。
*   遇到文件结束，系统返回 `-1`。如果 `char` 是无符号的，`-1` 就会被强行转成 `255`。
*   这时候你写 `if (c == EOF)`，就成了 `if (255 == -1)`，永远不成立，程序陷入**死循环**。

**所以，必须用 `int` 来接！**
用 `int` 接住 `-1`，那么 `-1` 就是 `-1`，判断 `if (c == EOF)` 永远准确。

---

### 🚨 三、ASCII码是个什么东西？

**ASCII码，就是一张“字符和数字的对照表”。**

电脑这破机器只认识 0 和 1（二进制）。你敲键盘输入一个字母 `'A'`，电脑听不懂，它只会问：“你他妈给我个数字，我才认。”

于是，美国佬就牵头搞了这么一张表（American Standard Code for Information Interchange）：
*   字母 `'A'` = 数字 **65**
*   字母 `'a'` = 数字 **97**
*   字母 `'0'` = 数字 **48**
*   空格 `' '` = 数字 **32**

你看，一共就 0 到 127 这 128 个数字，刚好用一个字节（8位）就能装下。

**你写 C 语言时：**
```c
char c = 'A';   // 实际上是 c = 65
printf("%d", c); // 输出 65
printf("%c", c); // 输出 A
```
电脑存的是 65，用 `%c` 打印时，系统去查表，发现 65 对应 'A'，就给你显示出来。

**为什么 `getchar` 返回 `int` 就是基于这个表？**
因为 ASCII 码最大是 127，都是正数。`getchar` 读取到字符就返回 0~127 之间的数字；如果读到结尾，就返回 `-1`（EOF）。所以只要用 `int` 接，就能完美区分“读到了什么字符”和“读到文件尾巴了”。






你基本懂了，但有一个极其关键的细节被你误解了，必须纠正。

你说“相当于输入了一串字符，这串字符直接被存到C这个变量里面”——**错！大错特错！**

`c` 是一个 `int` 变量，它**一次只能装得下一个字符**。你输入的那一整串字符，不是一下子全塞进 `c` 里的，而是**一个一个排队，一次喂给 `c` 一个**。

给你把这个“万恶循环”彻底拆开：

### 代码：
```c
int c;  // 注意：必须用int
while ((c = getchar()) != EOF) {
	putchar(c);
}
```

### 电脑执行的真实过程：

假设你输入了一串字符：`abc`，然后按了回车，最后按了 `Ctrl+Z`（发送EOF）。

1. **第一次循环**：
   * `getchar()` 从键盘缓冲区里拿走了第一个字符 `'a'`。
   * 把 `'a'` 赋值给 `c`（此时 `c = 97`）。
   * 判断 `97 != EOF`（也就是 `97 != -1`）成立。
   * 执行 `putchar(c)`，屏幕上打印出 `a`。

2. **第二次循环**：
   * `getchar()` 接着从缓冲区拿走第二个字符 `'b'`。
   * 把 `'b'` 赋值给 `c`（此时 `c = 98`）。
   * 判断 `98 != -1` 成立。
   * 执行 `putchar(c)`，屏幕上打印出 `b`。

3. **第三次循环**：
   * `getchar()` 拿走第三个字符 `'c'`，赋值给 `c`，判断成立，打印 `c`。

4. **第四次循环**：
   * `getchar()` 拿走你按回车产生的 `'\n'`（换行符），赋值给 `c`，判断成立，打印一个换行。

5. **第五次循环**：
   * `getchar()` 遇到 `Ctrl+Z`，拿到 `EOF`（-1）。
   * 把 `-1` 赋值给 `c`。
   * 判断 `-1 != -1` **不成立**（也就是 `false`）。
   * **循环结束！** `while` 后面的花括号不再执行。

### 总结你的理解：
*   `getchar()` 括号里是 `void`，意思是**不需要你给它任何参数**，它自己会去输入流里抓一个字符。
*   它抓到的字符，**通过“返回值”这个通道扔出来**，而不是塞到某个地址里。
*   你用一个变量 `c` 接住这个返回值。
*   因为 `c` 每次只接住一个字符，所以想处理一整串字符，**必须靠 `while` 循环反复调用 `getchar()`**。
*   只要 `c` 不是 `EOF`（-1），循环就继续；一旦遇到 `EOF`，循环就结束。

这就是“输入流”的本质：**它是一条水管，`getchar` 是你每次拿一个小杯子去接一杯，而不是一次性把整条河的水都倒进你的杯子里。**

懂了这个，你以后学文件操作（`fopen`、`fgetc`）就一通百通了。去VS里把这个循环跑一遍，看看是不是我描述的过程！


又他妈打错字了，是 **`printf`**，不是“print f f”！

**结论先甩你脸上：完全可以用！而且你以后写代码，99%的情况下都会用 `printf`，而不是 `putchar`。** 它们俩混用，屁事没有，程序绝对不报错。

给你把底层逻辑彻底扒开：

### 1. 为什么可以混用？
因为 `getchar` 管的是**输入**，`printf` 管的是**输出**，这俩是两条独立的高速公路，各走各的。
*   `getchar()`：从输入流里抠出来一个字符，赋值给 `c`。
*   `printf()`：把 `c` 按照你给的格式串，打印到屏幕上。

### 2. 会发生什么？（直接看代码）
你用 `getchar` 读入，用 `printf` 输出，代码长这样：

```c
#include <stdio.h>
int main() {
	int c;
	printf("请输入一串字母:\n");
	while ((c = getchar()) != EOF) {
		printf("我读到了：%c \n", c);  // 注意这里用 %c
	}
	return 0;
}
```
你输入 `A`，屏幕上就会打印：`我读到了：A`。
你输入 `B`，屏幕上就会打印：`我读到了：B`。
**这就是 `printf` 的优势——你可以往里塞各种废话、提示词、换行符，比 `putchar` 灵活一万倍！**

### 3. `printf` 和 `putchar` 的区别（划重点）

*   **`putchar(c)`**：纯爷们，只能硬巴巴地打出一个字符。没换行，没提示，没法打印别的类型，只能打字符。
*   **`printf("%c", c)`**：万能工具人。可以加换行 `\n`，可以加文字 `"你输入的是："`，还可以用 `%d` 打出字符的 ASCII 码（比如打印 `65`）。

**你以后百分之百会抛弃 `putchar`，全用 `printf`。**

### 4. 一个极其容易踩的坑（必须记死）
`getchar()` 返回的是 **`int`** 类型，你接的时候用 **`int c;`**。
但你在 `printf` 输出的时候，千万别写错了：
*   如果写 `printf("%c", c);` —— 打印出字符（比如 `A`）。
*   如果写 `printf("%d", c);` —— 打印出数字（比如 `65`，ASCII码）。
*   如果是用 `scanf` 输入的，中间没问题，但 `printf` 这里的 `%c` 和 `%d` 不要搞混。

### 💥 终极结论
你写 `while ((c = getchar()) != EOF) { printf("%c", c); }` 和写 `putchar(c)` 效果在屏幕上看是一样的，但 `printf` 能让你加 `\n`，能让你加文字说明。**所以，放心大胆地用 `printf`！**

别他妈光问了，去VS里把上面那段代码敲一遍，把 `printf` 里的 `%c` 改成 `%d` 试试，看看输出了什么！
*/


/*
int main() {
	int c;
	printf("input");
	while ( ( c = getchar() )  != EOF) {
		putchar(c);  // 把读到的字符原样打印出来
	}
	printf("\n读到 EOF，循环结束，程序退出！\n");
	return 0;
}
*/


//size_t 是无符号整型  用于表示内存的大小 表示长度或大小
//用%zu输出size_t类型的变量



/*
p 指针只存了首字母 'H' 的地址（一个门牌号）。

printf("%s", p) 接收到这个门牌号后，它就像个推土机，顺着地址往后一个个读字符，直到读到 \0（0）才刹车。
把 "Hello" 想象成一列火车。

火车车厢是连着的：'H'-'e'-'l'-'l'-'o'-'\0'。

指针 p 不是整个火车，它只是一个火车头（第一节车厢 'H'）的挂钩位置。

你拿住这个挂钩（p），顺着往后拉，就能把整列火车（整个字符串）都拉出来。
#include <stdio.h>
int main() {
	char *p = "Hello";
	printf("p 的地址：%p\n", p);        // 这是 'H' 的地址
	printf("p+1 的地址：%p\n", p + 1);  // 这是 'e' 的地址（比 p 大了 1 个字节）
	printf("首地址的字符：%c\n", *p);   // 解引用，输出 'H'
	return 0;
}
*/



/*
1.strlen 输出字符串长度 返回size_t
*/
/*
#include <string.h>

int main(int argc, char *argv[]) {
	char line[] = "Hello";
	printf("strlen = %zu\n", strlen(line));
	printf("sizeof = %zu\n", sizeof(line));

	return 0;

}
*/
//因为字符串数组末尾有一个'\0' 所以strlen输出的长度是5  而sizeof输出的长度是6
//构建一个自己的函数mylen代替strlen
/*
#include <string.h>

int mylen(const char* s) {
	int cnt = 0;
	for (; *s != '\0'; s++) {
		cnt++;
	}
	return cnt;
}
int main() {
	char line[] = "Hello";
	printf("strlen = %zu\n", mylen(line));
	printf("sizeof = %zu\n", sizeof(line));

	return 0;
}
*/




/*
2.strcmp 比较字符串 返回  0==   1>   -1<
*/
//不能用== 直接比较字符串 只能用strcmp函数 ==比较的是地址不是值

/*
#include <string.h>

int main(void) {
	char s1[] = "Hello";
	char s2[] = "Hello";
	printf("%d\n", strcmp(s1, s2));

	return 0;
}
*/
//自己写函数mycmp代替strcmp
/*
include <string.h>


int mycmp(const char* s1, const char* s2) {
	while (*s1 == *s2 && *s1 != '\0') {
		s1++;
		s2++;
		}
	return (*s1 - *s2);
}

int main(int argc, char const* argv[]) {
	char;
	char;
	printf("%d\n", mycmp(argv[1], argv[2]));
}
*/





/*
3.strcpy 拷贝字符串 把后一个字符串拷贝到前一个字符串中 返回char restrict表示 两个字符串不能重叠
*/

/*
#include <string.h>

int main(void) {
	char src[] = "Hello";
	char* dst = (char*)malloc(strlen(src) + 1);
	strcpy(dst, src);

}
*/

//自己写
/*
#include <string.h>

char* mycpy(char dst[], const char* src) {
	char* ret = dst;
	while (*dst++ = *src++ )
	*dst = '\0';  
	return ret;
}
*/


/*
4.strcat 拼接字符串 把后一个字符串拼接到前一个字符串的末尾 返回char* 
*/

/*
5.strchr从左边开始  strrchr从右边开始   在字符串中找字符  返回指针  返回NULL表示没找到
*/

/*
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char line[] = "Hello";
	char* p = strchr(line, 'l'); //返回值给了p这个指针 p这个指针就指向了llo的第一个字母l的地址
	printf("%s\n", p);//输出llo
	char* q = strchr(p + 1, 'l');//找到第二个l的地址
	printf("%s\n", q);//输出lo

	char* t = (char*)malloc(strlen(p) + 1);
	strcpy(t, p);
	printf("%s\n", t);//llo
	free(t);

	char c = *p;
	*p = '\0';
	char* r = (char*)malloc(strlen(line) + 1);
	strcpy(r, line);
	printf("%s\n", r);//he

	free(r);

	return 0;
}
*/
/*
6.strstr  在字符串中找字符串   strcasestr  同样但忽略大小写 */
/*
%c = “给我一块砖头”。你给 *p（也就是那块砖头本身）。

%s = “给我一个仓库地址，我自己去拉货”。你给 p（也就是仓库门牌号）

想打单个字母，却用 %s：printf("%s", *p);
printf 拿到的是 'l'（数字 108），它强行把 108 当成一个“内存地址”，然后去那个地址里翻内存。这叫非法访问，程序直接当场崩溃，或者打出一堆乱码。

想打一整串字符串，却用 %c：printf("%c", p);
printf 拿到的是 p（一个64位的地址）。它却只以为你给它个字符，结果就是打印出一个完全看不懂的、莫名其妙的单个乱码字符

%c（Character，字符）：printf 想要的，是一个单独的字符值。
你给它 *p，*p 算出来是 'l'（ASCII码 108）。printf 拿到 108，去查 ASCII 表，然后把 'l' 打印出来。

%s（String，字符串）：printf 想要的，是一个首地址（指针）。
你给它 p，p 是个内存地址。printf 拿到地址后，才会像推土机一样从那个地址往后推，推一个字符打印一个，直到推到 \0 为止

要用整串字符串（打印字符串、传给字符串函数）：用 p （因为你要给的是首地址）。

printf("%s", p);

strlen(p);

只想要那个单独字符（打印单字符、判断单个字符）：用 *p （因为你要掏里面的内容）
*/












//枚举

//enum 枚举类型  是一种自定义类型  可以用来定义一组相关的常量
//enum 枚举类型名字 {枚举常量1, 枚举常量2, 枚举常量3}
//常量的类型一定是int  从0开始 依次递增  可以手动指定常量的值
// 使用时格式  enum 枚举类型名字 变量名 = 枚举常量1
/*
enum COLOR {red = 2, yellow = 5, blue};

int main(int argc, char const* argv[]) {
	printf("blue = %d\n", blue);

	return 0;
}
*/










/*
//结构

//结构声明放在main函数外面 这样这个结构就可以在整个文件中使用  结构声明放在main函数里面 这个结构只能在main函数中使用

//结构成员是可以是不同类型的 结构体类型是自定义类型  可以用来定义一组相关的变量

//结构用.来访问其成员 结构体变量.成员名
int main(int argc, char const* argv[]) {
	struct date {
		int day;
		int month;
		int year;
	};
	struct date today;//定义today这个变量 这个变量的类型是结构体类型
	struct date thismonth = { .month = 5, .year = 2028 };//指定初始化  只初始化了month和year  day没有初始化  day的值是0
	struct date tomorrow = { 1, 1, 2024 };//定义tomorrow这个变量 这个变量的类型是结构体类型 并且初始化tomorrow这个变量
	printf("input day month year\n");
	scanf("%d %d %d", &today.day, &today.month, &today.year);
	printf("today is %d.day %d.month %d.year\n", today.day, today.month, today.year);
	printf("thismonth is %d.month %d.year\n", thismonth.month, thismonth.year);
	printf("tomorrow is %d.day %d.month %d.year\n", tomorrow.day, tomorrow.month, tomorrow.year);

	return 0;
}



//格式
struct point {
	int x;
	int y;
};

struct point p1, p2;
//p1和p2都是结构体类型的变量  他们的类型是struct point  p1和p2 都分别包含x y 


struct {
	int x;
	int y;

}p1, p2;
//p1和p2都是结构体类型的变量  他们的类型是匿名结构体类型  不能用struct point来定义变量


struct point {
	int x;
	int y;
}p1, p2;
//简写
*/


//运算
//p1 = (struct point){ 1, 2 }; 相当于p1.x = 1; p1.y = 2; 
//p1 = p2; 结构体类型的变量可以直接赋值  但是结构体类型的变量不能用==来比较 只能用memcmp来比较


//结构变量取地址要用&







//结构作为参数传递到函数中
//但跟数组不同的是  是在函数内部新建了一个结构变量只是内容相同

/*
//判断闰年 以及输入今天日期 输出明天日期
#include <stdbool.h>
struct date {
	int year;
	int month;
	int day;
};
bool isLeap(struct date d);
int lastOfDays(struct date d);
int main(int argc, char const* argv[]) {
	struct date today, tomorrow;

	printf("today's date(y,m,d):");
	scanf("%d %d %d", &today.year, &today.month, &today.day);

	if (today.day != lastOfDays(today)) {
		tomorrow.day = today.day + 1;
		tomorrow.month = today.month;
		tomorrow.year = today.year;
	}
	else if (today.month == 12) {
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	}
	else {
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}

	printf("tomorrow's date is %d.%d.%d\n", 
		tomorrow.year, tomorrow.month, tomorrow.day);

	if (isLeap(today)) {
		printf("%d is a leap year\n", today.year);
	}
	else {
		printf("%d is not a leap year\n", today.year);
	}

	return 0;
}
int lastOfDays(struct date d) {
	int day = 0;

	int const lastDayOfMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (d.month == 2 && isLeap(d)) {
		day = 29;
	}
	else {
		day = lastDayOfMonth[d.month - 1];
	}
	return day;
}
bool isLeap(struct date d) {
	bool leap = false;
	if (d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0) {
		leap = true;
	}
	return leap;
}
*/












//读入结构的函数
/*
struct point {
	int x;
	int y;
};

void getstruct(struct point gst);
void outstruct(struct point ost);

void main(int argc, char const* argv[]) {
	struct point st = { 0,0 };
	getstruct(st);
	outstruct(st);
}

void getstruct(struct point gst) {
	scanf("%d", &gst.x);
	scanf("%d", &gst.y);
	printf("%d %d\n", gst.x, gst.y);
}

void outstruct(struct point ost) {
	printf("%d %d", ost.x, ost.y);
}
//因为结构只传值 在函数里的结构的值回不到main里面去
*/















//下面改进
/*
struct point {
	int x;
	int y;
};

struct point getstruct(void);
void outstruct(struct point ost);

void main(int argc, char const* argv[]) {
	struct point st = { 0,0 };
	st = getstruct();
	outstruct(st);
}

struct point getstruct(void) {
	struct point gst;
	scanf("%d", &gst.x);
	scanf("%d", &gst.y);
	printf("%d %d\n", gst.x, gst.y);

	return gst;
}

void outstruct(struct point ost) {
	printf("%d %d", ost.x, ost.y);
}
*/
//先初始化st变量  再调用getstruct函数  修改在getstruct函数中gst的值  最后让st等于gst  这样输入的数据就换到了main中













//终极简洁方法  使用指针
/*
void getstruct(struct point* p) {
	scanf("%d", &p->x);
	scanf("%d", &p->y);
}

// 主函数里调用：
getstruct(&st); // 直接把st的地址传进去，函数里直接修改st的值
*/
/*
struct date {
	int year;
	int month;
	int day;
}days;
int main(void) {
	struct date* p = &days;
	p->month = 12;// 相当于(*p).month = 12
}
*/




/*
struct point {
	int x;
	int y;
};

struct point* getstruct(struct point* p);
void outstruct(const struct point* p);
void print(struct point p);

void main(void) {
	struct point st = { 0,0 };
	getstruct(&st);
	outstruct(getstruct(&st));
	print(*getstruct(&st));
}

struct point* getstruct(struct point* p) {
	scanf("%d", &p->x);
	scanf("%d", &p->y);
	printf("%d %d\n", p->x, p->y);
	return p;
}

void outstruct(const struct point* p) {
	printf("%d %d", p->x, p->y);
}

void print(struct point p) {
	printf("%d %d", p.x, p.y);
}
*/

















//结构数组

/*
struct date {
	int year;
	int month;
	int day;
};
int main(int argc, char const* argv[]) {
	struct date today,tomorrow;
	struct date days[10] = { {2025,1,1}, {2026,1,1}, {2027,1,1} };
	
	return 0;
}
*/

/*
//一秒钟后的时间是多少？
struct time {
	int hour;
	int minute;
	int second;

};
struct time timeupdate(struct time now);
int main(void) {
	struct time testtimes[] = {
		{ 12, 59, 59 },
		{ 14, 15, 20 },
		{ 16, 45, 10 },
		{ 18, 33, 23 },
		{ 20, 30, 15 },
	};
	for (int i = 0; i < sizeof(testtimes) / sizeof(testtimes[0]); i++) {
		printf("time%d: %.2d:%02d:%02d\n", 
			i + 1, testtimes[i].hour, testtimes[i].minute, testtimes[i].second);

		testtimes[i] = timeupdate(testtimes[i]);

		printf("one second later: %.2d:%02d:%02d\n",
			testtimes[i].hour, testtimes[i].minute, testtimes[i].second);
	}

	return 0;
}

struct time timeupdate(struct time now) {
	++now.second;
	if (now.second == 60) {
		++now.minute;
		now.second = 0;
		if (now.minute == 60) {
			++now.hour;
			now.minute = 0;
			if (now.hour == 24) {
				now.hour = 0;
			}
		}
	}
	return now;
}
*/























//结构中的结构
/*
struct date
{
struct date1;
struct date2
};
*/
/*
struct point {
	int x;
	int y;
};
struct rectangle {
	struct point p1;
	struct point p2;
};
struct rectangle r;

就有
r.p1.x
r.p2.x
r.p1.y
r.p2.y


如果还有个指针rp指向r

那么
r.p1.x
rp->p1.x
*rp.p1.x
等价
*/





















//自定义数据类型typedef
//比如 typedef int Length;  那么Length就是int类型的别名  Length == int
/*
//类比上面的typedef int Length;  把 struct point及其大括号中的内容 看成int 后面的date就相当于 Lenth  那么date就是struct point类型的别名  date == struct point
typedef struct point {
	int x;
	int y;
} date;

date p = { 1,2 };//date是结构体类型point的另外的一个名字  p是date这个结构体类型的变量  p的类型是date  date == struct point
*/










/*
//联合体union

union point {
	int x;
	char c;
}p1, p2;

void main(void) {
	p1.x = 1;
	p2.c = 'a';
}
//跟struct不同的是  
// union的所有成员都存储在同一块内存中  
// 所以union的大小是最大成员的大小  
// union的所有成员共享同一块内存  
// 所以union的所有成员的值都是相同的  
// union的所有成员的地址都是相同的
*/


//联合体的使用场景
/*
typedef union {
	int i;
	char ch[sizeof(int)];
} NAME;

int	main(void) {
	NAME num;
	int x;
	num.i = 0x1234;
	for (x = 0; x < sizeof(int); x++) {
		printf("%02x ", num.ch[x]);
	}
	return 0;
} 
*/
// 这个程序的输出结果取决于系统的字节序（endianness）。在小端系统上，输出将是：
// 34 12 00 00
// 在大端系统上，输出将是：
// 00 00 12 34
//也就是说fanguolaile











































/*
//可变数组
#include"Array.h"
int main(int argc, char* argv[]) {
	Array a = array_create(10);
	printf("size = %d\n", array_inquire_size(&a));
	array_input(&a);
	printf("size = %d\n", array_inquire_size(&a));
	array_free(&a);
	return 0;
}
*/
 




//全局变量
//所有函数都可以访问
//全局变量若不初始化 会自动赋值为0  指针会自动赋值为NULL
//全局变量初始化应该一个定值
//若在一个函数或结构内出现一个局部变量与全局变量同名 这个全局变量在这个局部范围里会被隐藏




//静态本地变量  static
//当函数离开时静态本地变量会继续保持其值
//静态本地变量只有第一次进入函数时会初始化 以后再进入函数会保持上一次离开时的值
/*
void f(void);
G = 10;
int main(void) {
	for (int i = 0; i < 10; i++) {
		f();
	}
	return 0;
}

void f(void) {
	static int a = 1;
	printf("in %s a = %d\n", __func__, a);
	a++;
}
*/
//静态本地变量实际上是特殊的全局变量 它们位于相同的内存地址 所以他们生存期相同 但静态本地变量的作用域只有该函数 而全局变量的作用域是整个代码


//返回本地变量的地址是危险的












































































































































































































