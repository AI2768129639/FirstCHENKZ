#include <stdio.h>











int main ()
{
	int max_num ;
	int min_num ;
	
	printf("input max_num and min_num :\n");
	scanf("%d %d", &max_num,&min_num);
	int sum = 0;
	int count = 0;
	
	int i;
	
	if (min_num == 1){
		min_num = 2;
	}
	for (i = min_num ; i <= max_num ; i++){
		
		int q = 1;
		int j;
		for (j = 2 ; j < i - 1 ; j++){
			if (i%j == 0){
				q = 0;
				break;
			}
		}
		if ( q == 1){
			sum += i;
			count++;
		}
	}
	printf(" all sushu = %d number = %d", sum,count);
	
	return 0;
}




























































































