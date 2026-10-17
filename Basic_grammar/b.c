#include <stdio.h>

// CH sizeof() 来给出某个变量所占据的字节数

/*
int main ()
{
	int a = 9;
	printf("sizeof(double) = %ld", sizeof(double));
	printf("sizeof(a) = %d", sizeof(a));
	return 0;
}
*/


/*
int main()
{
    printf("sizeof(char)=%ld\n", sizeof(char));
    printf("sizeof(short)=%ld\n", sizeof(short));
    printf("sizeof(int)=%ld\n", sizeof(int));
    printf("sizeof(long)=%ld\n", sizeof(long));
    printf("sizeof(long long)=%ld\n", sizeof(long long));
    return 0;
}
*/

/*
int main ()
{
	unsigned char c = 255;
	int a = 255;
	signed char b = 255;
	printf("%d %d %d", c,b,a);
	
	return 0;
}
*/

// CH 表示  比int小的用%d表示  比int大的用%ld表示   unsigned 用%u

// CH科学计数法格式 数字 + e/E + (+ / -) + 10的位数 如0.000001 == 1E-6  1234 == 1.234e+3
// CH 科学计数法可以在输出和输入中使用  在百分号后面写.number 代表要保留多少位小数
// CH 保留位数会四舍五入
/*
int main ()
{
	double f = 1234.56789;
	double a = 1E-10;
	printf("%e\n", f);
	printf("%f\n", f);
	printf("%.20f\n", a);
	printf("%.3f\n", -0.0049);
	printf("%.30f\n", -0.0049);
	printf("%.3f\n", -0.00049);
	return 0;
}
*/




// CH  inf 无限 nan 不存在  浮点数中
/*
int main()
{
	__mingw_printf("%f\n", 12.0/0.0);
	__mingw_printf("%f\n", -12.0/0.0);
	__mingw_printf("%f\n", 0.0/0.0);
	
	return 0;
}
*/

// CH 带小数点的字面量是double而非float  float 需要用f 或F 来在末尾后缀表示

// CH 浮点数计算会有误差 一般不能直接相等 可以用做差跟一个非常小的数比较来判断是否相等

// CH 整数一定是精确的 在严谨运算中要用整数算
/*
int main ()
{
	float a,b;
	
	a = 1.345f;
	b = 1.345f;
	
	if ( fabs(a - b) < 1E-7){
		printf("same");
		
	}
	return 0;
}
*/









// CH 字符 用‘’ 来表示字符  用%c  来输入输出字符
// CH 每一个字符都有自己对应的整数
/*
int main ()
{
	char a;
	char b;
	char c;
	a = 1;
	b = '1';
	c = 'm';
	printf("%d\n", a);
	printf("%c\n", b);
	printf("%d\n", b);
	printf("%c\n", c);
	printf("%d\n", c);
	return 0;
}
*/

// CH 输入字符
// CH 每一个字符在计算机内部都有一个整数去表达它，如果你scanf用的是百分号C，就证明你输入进去的是一个字符  如果你print f百分号C，就证明你要把这个字符给输出出来，如果你print f百分号D就证明你要输出这个字符在计算机内部对应的这个值
// CH 因为每一个字符在计算机内部都有一个整数值所对应，所以说如果我们想要得到某个字符，第一种方法就是输入百分号C输出百分号C第二种方法我们可以输入百分号D，这里的D，我们就手动输入这个字符在计算机内部所用的整数然后的话我们输出用百分号C这个时候，我们就可以根据这个字符在计算机内部所对应的整数来输出这个字符


/*
int main ()
{
	char a;
	scanf("%c", &a);
	
	printf("%c\n", a);
	printf("%d", a);
}
*/

/*
int main ()
{
	char a = '1';
	int b = 49;
	if ( a == b){
		printf("same");
	}
	return 0;
}
*/


// CH 字符也可以做运算 一个字符加减一个数字，得到阿斯克码表中那个数之后的字符如果是两个字符的相减，就得到了它们在表中的距离
/*
int main ()
{
	char a = 'A';
	a++;
	printf("%c\n", a);
	
	int i = 'z' - 'A';
	printf("%d", i);
	
	return 0;
}
*/

// CH 因为两个字符相减是两段距离所以我们可以通过小写的A再加上大写A字符，再减去小写A字符就可以把小写的A转化为大写的A
/*
int main ()
{
	char x = 'a';
	int m = 'A' - 'a';
	char y = 'a' + m;
	printf("%c\n", x);
	printf("%c", y);
	
	return 0;
}
*/

// CH 又因为在阿斯克表中，每一个小写字母和大写字母的距离是相等的，所以说我们可以利用大A减小A的这一个距离不管我们输入任何一个小写字母，我们都可以把它转化为大写字母
/*
int main ()
{
	char x;
	scanf("%c", &x);
	
	int m = 'A' - 'a';
	
	char y = x + m;
	
	printf("%c %c", x,y);
	
	return 0;
}
*/


// CH 逃逸字符 \b回退一格 下一个输出的东西覆盖上一个    \t缩进     \n换行     \r回车     \"双引号    \'    \\本身




// CH 类型转换  当运行中的类型不同 会自动转换成较大的类型 char < short < int < long < long long
//  int < float < double
// CH 强制类型转换如（int）1.2  强制类型转换优先级高于四则运算  使用时要注意范围








//bool  布尔值  #include<stdbool.h> 使用bool true false





// CH  逻辑运算 ! 非  &&  and   ||  or
// CH  优先级 ! > && > ||


// CH 逻辑运算是自左向右进行的，如果左边的结果已经能够决定结果了，就不会做右边的计算。对于And and左边是false时就不做右边了，对于或左边是True时就不做右边了。所以说要注意逻辑运算符的右边尽量不写






// CH 条件运算符 如    count = (count > 20) ? count - 10 : count 分别为条件  条件满足时的值    条件不满足时的值


// CH     （，）是表达式 用于 for循环































































































