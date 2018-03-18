#include <stdlib.h>
#include <stdio.h>
void print(int n, int *p)
{
	int i;
	for(i=0; i<n; i++)
{
	printf("%d ", p[i]);
}
	printf("\n");
}
int LinearSearch(int n, int *p, int value)
{
	int i;
	for(i=0; i< n; i++)
	{
		printf("%d: %d\n",i, p[i] );
		if(p[i] == value)
	{
		return i; // 找到: 傳回資料位置
	}
}
return -1; // 找不到: 回
}

int BinarySearch(int n, int *p, int value)
{
	int low=0, high=n, mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		printf("%d: %d\n",mid, p[mid] );
		if(p[mid] > value)
			high = mid - 1;
		else if(p[mid] < value)
			low = mid+1;
		else
			//printf("%d: %d\n",mid, p[mid] );
			return mid;
	}
	return -1;
}


int main(){

	int op , key, j;
	int data[100];
	int n = 0;
	while(1){

		puts("1 加入並排序");
		puts("2 線性搜尋");
		puts("3 二元搜尋");
		puts("4 列印");
		puts("5 離開");
		
		scanf("%d" , &op);
		switch(op){

			case 1 :
				scanf("%d", &key);
				for(j = n-1 ; j >= 0 && data[j] > key ; j--){
					data[j + 1] = data[j] ;
				}
				data[j+1 ] = key;
				n++;
				break;
			case 2 :
				scanf("%d", &key);
				if(LinearSearch(n, data, key) != -1 ){
					printf("found %d\n", key);
					//printf("%d: %d\n",BinarySearch(n, data, key), key );
				}

				break;
			case 3 :
				scanf("%d", &key);
				if(BinarySearch(n, data, key) != -1 ){
					printf("found %d\n", key);

				}
				break;
			case 4 :
				print(n, data);
				break;
			case 5 :
				return 0;
				break;



		}
		system("pause");
		system("cls");
	}




	return 0;
}
