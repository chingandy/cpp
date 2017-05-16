#include<stdlib.h>
#include<stdio.h>

void hanoi(int n , char from , char mid , char to, int count[] )
{
		//int count[3] = {0};
		if (n == 0 ){
			return ;
		}
		hanoi(n -1 , from , to , mid, count);
		printf("plate %d from %c -> %c\n", n, from , to);
		count[n-1]++;
		hanoi(n-1 , mid, from , to, count);

}

int main(){

	int i,n ;
	scanf("%d" , &n);
	int count[100] = {0};
	hanoi(n , 'A' , 'B', 'C',count);
	puts("");
	for(i= 1 ; i < n + 1  ; i++){
		printf("plate %d = %d\n", i , count[i-1] );
	}

	return 0;
}
