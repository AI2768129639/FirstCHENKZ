#include <stdio.h>


// only one index
// every sentences need \n and ;

/*
mutipule index
*/





















/*
int main() {
    printf("Hello World\n");
    printf("1 + 2 = %d\n",1 + 2) ;
    printf("999 * 91 = %d" , 999 * 91\n)
    ;
    return 0;
}
*/

/*
int main()
{
	int price = 0;
	printf("yours_price:");// output some datas
	scanf("%d",&price);// input some datas The symbol & mast be added before the datas
	int return_price = 100 - price;
	printf("return you %d dollars\n",return_price);		
	return 0;		
}
*/




























// CH变量要初始化 否则该变量不为初始值
//  CH类名 加 变量名 等于 初始值 （格式）

//  CH单个变量定义
//int a = 1

//  CH 多个变量定义
//int b = 2,c = 3

/*
int main()
{
	int a = 0,b = 1;
	scanf("%d,%d", &a, &b);// Whatever data appear in the (scanf("")) you mast input it
	printf("%d,%d\n", a, b);
	return 0;
}
*/

// Constant no change
// CH  格式  const + 类型 + 全大写变量名

/*
int main()
{
	const int AMOUNT = 100;
	int price = 0;
	printf("price:");
	scanf("%d",&price);
	int price_return = AMOUNT - price;
	printf("return_price for you %d",price_return);
	return 0;
	
}
*/

/*
int main()
{
	 int amount = 0;
	int price = 0;
	printf("price:\n");
	scanf("%d",&price);
	printf("your_money:\n");
	scanf("%d",&amount);
	int price_return = amount - price;
	printf("return_price for you %d",price_return);
	return 0;
	
}
*/

/*
int main()
{
	int a = 0;
	int b = 0;
	printf("two number:");
	scanf("%d %d",&a,&b);
	printf("%d + %d = %d\n", a,b,a + b);
	return 0;
}
*/

// double == float
/*
int main()
{
	const float A = 0.3048;
	const float B = 12.0;
	float chi = 0;
	float cun = 0;
	printf(" chi:\n");
	scanf("%f",&chi);
	printf("cun:\n");
	scanf("%f",&cun);
	float meter = (chi + cun / B) * A;
	printf("high:%f meters", meter);
	return 0;
	
}
*/

/*
int main()
{
	const double A = 0.3048;
	const float B = 12.0;
	double chi = 0;
	double cun = 0;
	printf(" chi:\n");
	scanf("%lf",&chi);
	printf("cun:\n");
	scanf("%lf",&cun);
	float meter = (chi + cun / B) * A;
	printf("high:%f meters", meter);
	return 0;
	
}
*/

/*
int main()
{
	int hour1,minute1;
	int hour2,minute2;
	
	printf("time1:(more than time2)");
	scanf("%d %d",&hour1,&minute1);
	
	printf("time2:(less than time1)");
	scanf("%d %d",&hour2,&minute2);
	
	int diferent_time = (hour1 * 60 + minute1) - (hour2 * 60 + minute2);
	int diferent_hour = diferent_time / 60;
	int diferent_minute = diferent_time % 60;
	
	printf("hour%d minute%d",diferent_hour,diferent_minute);
	
	return 0;
}
*/

/*
int main()
{
	int hour1, minute1;
	int hour2, minute2;

scanf("%d %d", &hour1, &minute1);
scanf("%d %d", &hour2, &minute2);

int t1 = hour1 * 60 + minute1;
int t2 = hour2 * 60 + minute2;

int t = t2 - t1;

printf("hour%d minute%d", t/60, t%60);

return 0;
}
*/

/*
int main()
{
	int a , b;
	scanf("%d %d", &a ,&b);
	double c = (a + b) / 2.0;
	printf("%f",c);
	return 0;
}
*/

/*
int main()
{
	int a = 1;
	int b = 2;
	int c;
	c = a;
	a = b;
	b = c;
	printf("%d %d", a,b);
	return 0;
}
*/







































// a += b / 2  ==  a = a + b / 2
// a *= b + c  ==  a = a * (b + c)
//  more  count++  ==  count += 1  ==  count = count + 1
//  less  count--  ==  count -= 1  ==  count = count - 1
// CH                    a++ 是先使用再加1  ++a 是先加1再使用   

/*
int main()
{
	int a;
	a = 1;
	
	printf("a++ = %d\n", a++);
	printf("a = %d\n", a);
	
	printf("++a = %d\n", ++a);
	printf("a = %d\n", a);
	
	return 0; 
	
}
*/

/*
int main()
{
	int cm = 0;
	scanf("%d", &cm);
	double total = cm/30.48;
	int foot = (int)total;
	double inch = (total - foot)*12;
	printf("foot%d inch%.1f", foot,inch);
	return 0;

}
*/

/*
int main()
{
	int a = 0;
	int b = 0;
	printf("time now is :\n");
	scanf("%d", &a);

	printf("minutes :\n");
	scanf("%d", &b);

	int hour_minute = a / 100;
	int minute_minute = a % 100;

	int hour = b / 60;
	int minute = b %60;

	int all_minute = (minute + minute_minute) % 60;
	int more_hour = (minute + minute_minute) / 60;

	int time_now = (hour_minute + hour + more_hour) *100 + all_minute;
	printf("now time is :%d", time_now);
	return 0;

}
*/

// double and float use %f when printf()     double use %lf and float use %f when scanf()

/*
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf("order the number:");
	scanf("%d %d %d", &a,&b,&c);
	
	int x = a * 100 + b * 10 + c;
	printf("right:%d", x);
	
	int y = c * 100 + b * 10 + a;
	printf("left:%d", y);
	
	return 0;
	
}
*/













































// if sentence

/*
int main()
{
	int hour1, minute1;
	int hour2, minute2;

scanf("%d %d", &hour1, &minute1);
scanf("%d %d", &hour2, &minute2);

int hour = hour2 - hour1;
int minute = minute2 - minute1;

if (minute < 0){
	minute = minute + 60;
	hour --;
}

printf("hour%d minute%d\n", hour,minute);

return 0;
}
*/

// CH  判断 ==        !=          <             >           <=             >= 

/*
int main()
{
	printf("%d\n", 5 == 3);
	printf("%d\n", 5 >= 3);
	
	return 0;
}
*/

// CH  优先级排序:  （从左到右 由大到小）  (* / %)  (+ -)  (< > <= >=)  (== !=)  (=)   

//     CH        if + else  两种写法
/*
int main()
{
	int price = 0;
	int money = 0;

	printf("price :\n");
	scanf("%d", &price);

	printf("money :\n");
	scanf("%d",&money);

	int return_money = money - price;

	if (money < price){
		printf("not enough!\n");
	}

	else {
		printf("return you %d\n", return_money);
	}
	
	return 0;

}
*/

/*
int main()
{
	int price = 0;
	int money = 0;

	printf("price :\n");
	scanf("%d", &price);

	printf("money :\n");
	scanf("%d",&money);

	int return_money = money - price;

	if (money < price)
		printf("not enough!\n");

	else 
		printf("return you %d\n", return_money);

	return 0;

}
*/     

//CH  C语言中else是最近的if的  不是看缩进  而是看距离!!!!!!!!!!!!!!!!!!!!!!!!!

/*
int main()
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int m = 0;

	printf("num1 = ");
	scanf("%d", &num1);

	printf("num2 = ");
	scanf("%d", &num2);

	printf("num3 = ");
	scanf("%d", &num3);

	if (num1 > num2){
		if (num1 > num3){
			m = num1;
		}
		else
			m = num3;
	}
	else{
		if (num2 > num3){
			m = num2;
		}
		else{
			m = num3;
		}
	}
	
	printf("max%d", m);

	return 0;
}
*/

/*
int main()
{
	int x = 0;
	printf("x = ?");
	scanf("%d", &x);
	if (x < 0){
		printf("<");
	}	
	else if(x == 0){
		printf("=");
	}
	else{
		printf(">");
	}
	return 0;
}
*/








































// CH 必须要有break才会停下 把case当作站牌 输入几 就从几开始往下运行 没有break就会一直向下运行直到遇到break

/*
int main()
{
	int e = 0;
	
	printf("e = ?");
	scanf("%d",&e);
	
	switch( e ) 
	{
		case 0:
	case 1:
		printf("1");
		break;
	case 1+1:
		printf("2");
		break;
	case 3:
		printf("3");
		break;
	case 4:
		printf("4");
		break;
	default:
		printf("fuck you");
			
	}
	
	return 0;
}
*/










































//CH  循环

// CH 判断几位数

/*
int main()
{
	int x = 0;
	int n = 1;
	
	scanf("%d",&x);
	
	if (x >= 1000 && x <= 9999){
		n = 4;
	}else if ( x >= 100 && x <= 999){
		n = 3;
	}else if (x >= 10 && x <= 99){
		n = 2;
	}else if (x >= 1 && x <= 9){
		n = 1;
	}
	
	printf("%dnum", n);
	
	return 0;
}
*/

// CH while是先判断条件再执行  do while是先执行再判断条件 至少会循环一遍

// 1
/*
int main()
{
	int x = 0;
	int n = 0;
	
	printf("input number :");
	scanf("%d", &x);
	
	n++;
	x /= 10;
	
	while (x != 0){
		n++;
		x /= 10;
	}
	printf("%d\n",n);
	
	return 0;
}
*/

// 2
/*
int main()
{
	int x = 0;
	int n = 0;
	
	printf("input number :");
	scanf("%d", &x);
	
	if (n == 0){
		n = 1;
	}else{
		while (n != 0){
			n++;
			x /= 10;
		}
	}
	
	printf("%d", n);
	
	return 0;
}
*/

//  3
/*
int main()
{
    int x = 0;
    int n = 0;

    printf("input number :");
    scanf("%d", &x);

    do {
        n++;
        x /= 10;
    } while (x != 0);

    printf("%d\n", n);

    return 0;
}
*/

/*
#include <stdlib.h>
#include <time.h>

// CH 猜数字游戏
int main()
{
	srand(time(0));
	int number = rand()%1000+1;
	int times = 0;
	int want_num;
	
	do {
		printf("want");
		
		times++;
		scanf("%d", &want_num);
		
		if (want_num > number){
			printf("操你妈的 more");
		}else if (want_num < number){
			printf("死全家 less");
		}
	} while (want_num != number);
	
	printf("NB It's right! The number is %d", number);
	
	return 0;
	
}
*/

// CH 平均数
/*
int main()
{
	int times = 0;
	int numbers ;
	int all = 0 ;
	
	do{
		printf("input your number(When you input -num Get the sum/len)");
		scanf("%d", &numbers);
		
		if (numbers >= 0){
			all += numbers;
			times++;
		}
		 
	} while (numbers >= 0);
	
	double p = (double)all/times;
	
	printf("p = %f", p);
	
	return 0;
}
*/

// CH 每一位数的和
/*
int main ()
{
	int num;
	int count = 0;
	printf("input");
	scanf("%d", &num);
	
	do{
		int a = num%10;
		count += a;
		num /= 10;
	} while (num > 0);
	
	printf("%d", count);
	
	return 0;
}
*/

// CH 反转数字
/*
int main()
{
	int num;
	int num_num;
	int over_num = 0;

	scanf("%d", &num);

	while (num > 0){
			num_num = num%10;
			over_num = over_num*10 + num_num;
			num /= 10;
	}
	printf("%d", over_num);

	return 0;
}
*/


















// CH 阶乘
/*
int main()
{
	int number;
	scanf("%d", &number);
	
	int begin = 1;
	int i = 1;
	
	while (i <= number){
		begin *= i;
		i++;
	}

	printf("number! = %d", begin);

	return 0;
}
*/

/*
int main()
{
	int number;
	int begin = 1;
	scanf("%d",&number);

	for ( int i = 1; i <= number; i++ ){
		begin *= i;
	}
	printf("number! = %d", begin);

	return 0;
}
*/

/*
int main()
{
	int number;
	int begin = 1;
	scanf("%d",&number);

	for ( number = number; number >= 1; number-- ){
		begin *= number;
	}
	printf("number! = %d", begin);
	
	return 0;
}
*/

/*
int main()
{
	int number;
	int begin = 1;
	scanf("%d",&number);

	for ( ; number >= 1; number-- ){
		begin *= number;
	}
	printf("number! = %d", begin);
	
	return 0;
}
*/

// CH 判断素数
/*
int main()
{
	int x;
	scanf("%d", &x);

	int s = 1;

	if ( x == 0 ){
		s = 2;
	}else{
		for ( int i = 2; i <= (x - 1); i++ ){
			int a = x % i;
			if ( a == 0 ){
				s = 0;
				break;
			}else if ( a != 0 ){
				continue;
			}
		}
	}
	
	if ( s == 1 ){
		printf("sushu");
	}else if ( s == 0 ){
		printf("no sushu");
	}else if ( s == 2 ){
		printf("error");
	}
	
	return 0;
}
*/

/*
int main()
{
	int m;
	int x;
	scanf("%d", &m);

	for ( x = 2 ; x < m ; x++ ){

		int s = 1;
	
		for ( int i = 2; i <= (x - 1); i++ ){
			int a = x % i;
			if ( a == 0 ){
				s = 0;
				break;
			}
		}
		if ( s == 1 ){
			printf("%d\n",x);
		}
	
	}

	return 0;
	
}
*/

// CH 用1叫2叫5叫 来凑钱的方法
/*
int main()
{
	int x;
	int one , two , five;
	
	printf("input money:")
	scanf("%d", &x);
	for ( one = 1 ; one < x*10 ; one++ ){
		for (two = 1 ; two < x*10/2 ; two++ ){
			for ( five = 1 ; five < x*10/5 ; five++){
				if  (one + two*2 + five*5 == x*10 ){
					printf("%done + %dtwo + %dfive = 10yuan\n",one,two,five);
				}
			}
		}
	}
	return 0;
}
*/


// CH   goto 从嵌套循环内层跳到外层  也可以有其他用途
/*
int main()
{
	int x;
	int one , two , five;

	printf("input money:");
	scanf("%d", &x);
	for ( one = 1 ; one < x*10 ; one++ ){
		for (two = 1 ; two < x*10/2 ; two++ ){
			for ( five = 1 ; five < x*10/5 ; five++){
				if  (one + two*2 + five*5 == x*10 ){
					printf("%done + %dtwo + %dfive = 10yuan\n",one,two,five);
					goto out;
				}
			}
		}
	}
out:
	return 0;
}
*/

// CH 1分之1 一直加到 n分之1
/*
int main ()
{
	int a = 1;
	int n;
	printf("input n:");
	scanf ("%d", &n);
	double total = 0.0;

	for (int count = 1; count <= n; count++){
		total += (double)a/count;
	}
	printf("%f", total);
	
	return 0;

}
*/

// CH 修改加减 穿插
/*
int main ()
{
	int a = 1;
	int n;
	printf("input n:");
	scanf ("%d", &n);
	double total = 0.0;

	for (int count = 1; count <= n; count++){
		if (count%2 == 0){
			total -= (double)a/count;
		}else{
			total += (double)a/count;
		}
	}
	printf("%f", total);
	
	return 0;

}
*/

/*
int main ()
{
	int a = 1;
	int n;
	printf("input n:");
	scanf ("%d", &n);
	double total = 0.0;
	sign = 1;

	for (int count = 1; count <= n; count++){
		total += sign*(double)a/count;
		sign = -sign;
	}
	printf("%f", total);
	
	return 0;

}
*/

// CH 正序输出
/*
int main()
{
	int x;
	scanf("%d", &x);
	int y = 0;

	do{
		int a = x%10;
		y = y*10 + a;
		x /= 10;
		
	} while ( x > 0 );
	
	do{
		int b = y%10;
		printf("%d", b);
		y /= 10;

	} while ( y > 0 );

	printf("\n");
	
	return 0;
}
*/
// CH 正序输出
/*
int main ()
{
	int x ;
	printf("input number:");
	scanf("%d", &x);

	int z = x;

	int m = 1;
	int count = 0;

	do{
		z /= 10;
		count++;
		
	} while (z > 0);
	
	while (count > 1){
		m *= 10;
		count--;
	}
	
	do{
		int y = x / m;
		
		printf("%d\n", y);
	
		x %= m;
		m /= 10;
	
	} while (m > 0);
	
	return 0;
}
*/

/*
int main()
{
    int x;
    scanf("%d", &x);

    int t = x;         
    int m = 1;

    while (t > 9) {
        t /= 10;
        m *= 10;
    }

    do {
        int d = x / m;
        printf("%d", d);

        x %= m;
        m /= 10;
        
    } while (m > 0);

    printf("\n");
    return 0;
}
*/

// CH 最小公约数
/*
int main ()
{
	int a,b ;
	printf("input two number:");
	scanf("%d %d", &a,&b);

	int min;

	if (a < b){
		min = a;
	}else{
		min = b;
	}
	
	int m = 0;
	for ( int i = 1; i < min; i++){
		if ( a%i == 0){
			if ( b%i == 0){
				m = i;
			}
		}
	}
	
	printf("min uttle_number:%d", min);
	
	return 0;
}
*/



// CH 辗转相除法
/*
int main ()
{
	int a,b;
	scanf("%d %d", &a,&b);
	int t;

	do{
		if (b == 0){
			printf("max number uttle:%d", a);
			break;
		}else{
			t = a;
			a = b;
			b = t%b;
		}	
	} while ( a > 0);
	
	return 0;
}
*/

/*
int main ()
{
	int a,b;
	int t;
	scanf("%d %d", &a,&b);

	while ( b!= 0){
		t = a%b;
		a = b;
		b = t;
	
	}
	printf("%d", a);
	
	return 0;
}
*/

// CH 输出无重复数字的三位数
/*
int main ()
{
	int a;
	printf("input number:");
	
	scanf("%d", &a);

	int i , j , k;

	int count = 0;
	 
	i = a;
	while ( i <= a + 3){
		j = a;
		while (j <= a + 3){
			k = a;
			while ( k <= a + 3){
				if ( i != j ){
					if ( i != k ){
						if ( k != j ){
							printf("%d%d%d", i,j,k);
							count++;
							if (count == 6){
								printf("\n");
								count = 0;
							}else{
								printf("  ");
							}
						}
					}
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
*/

/*
int main ()
{
	int n;

	printf(" input n :\n")   ;
	scanf("%d", &n);

	int i = 1;
	int first_n = 1;

	for ( i = 1; i < n; ++i){
		first_n *= 10 ;
	}

	int a = first_n;
	while ( a < first_n *10){
		int x = a;
		int sum = 0;
		do {
			int t = x%10;
			x /= 10;
			
			int p = t;
			int g = 1;
			while (g < n){
				p *= t;
				g++;
			}
			sum += p;
			
		}while ( x > 0 );
		if (sum == a){
			printf("%d\n", a);
		}
		a++;
	}
	
	return 0;
}
*/

/*
int main ()
{
	int a = 1;
	int b = 1;
	int c;

	for ( a = 1; a <= 9; a++){
		for (b = 1; b <= a; b++){
			c = a * b ;
			printf("%d * %d = %d",b,a,c);
			if (a == b){
				printf("\n");
			}else{
				printf("   ");
			}
		}
	}
	return 0;
}
*/


/*
int main()
{
	int m,n ;
	int i;
	scanf("%d %d",&m,&n);
	int sum = 0;
	int cnt = 0;

	for (i=m; m <= n; i++){
		int x = 1;
		int k ;
		for (k = 2; k <i - 1; k++){
			if (i%k == 0){
				x = 0;
				break;
			}
		}
		if ( x = 1 ){
			cnt++;
			sum += i;
		}
	}
	printf("%d %d", cnt,sum);
	return 0;
}
*/

/*
int main ()
{
	int n;
	scanf("%d", &n);
	
	double sum = 0.0;
	
	int i = 1;
	double a = 2;
	double b = 1;
	double c ;
	
	for (i = 1; i <= n; i++){
		sum += a/b;
		c = a;
		a = a + b;
		b = c;
		
	}
	printf("%.2f\n", sum);
	return 0;
}
*/

/*
int main ()
{
	int a;
	int b;
	scanf("%d", &a);
	scanf("%d", &b);

	int i = 1;
	int sum = 0;
	int c = 0;
	
	for ( i = 1; i <= b; i++){
		c = c*10 + a;
		sum += c;
	}
	printf("%d",sum);
	
	return 0;
}
*/



















































































































































































































































































































































































































































































































