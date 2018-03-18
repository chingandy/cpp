#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void print(int n, char c[][128])
{
	int i;
	for(i=0; i<n; i++)
{
	printf("%s ", c[i]);
}
	printf("\n");
}
int LinearSearch(int n, char data[][128], char c[])
{
	int i;
	for(i=0; i< n; i++)
	{
		printf("%d: %s\n",i, data[i] );
		if(strcmp(data[i] , c) == 0)
		{
			return i; // 找到: 傳回資料位置
		}
	}
	return -1; // 找不到: 回
}

int BinarySearch(int n, char data[][128], char c[])
{
	int low=0, high=n, mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		printf("%d: %s\n",mid, data[mid] );
		if(strcmp(data[mid] , c) > 0)//p[mid] > value
			high = mid - 1;
		else if(strcmp(data[mid] , c) < 0)//p[mid] < value
			low = mid+1;
		else
			//printf("%d: %d\n",mid, p[mid] );
			return mid;
	}
	return -1;
}


int main(){

	int op , j;
	char data[10][128];
  char key[128];
	int n = 0;
	while(1){
		/*
		puts("1 加入並排序");
		puts("2 線性搜尋");
		puts("3 二元搜尋");
		puts("4 列印");
		puts("5 離開");
		*/
		scanf("%d" , &op);
		switch(op){

			case 1 :
				scanf("%s", key);
				for(j = n-1 ; j >= 0 && (strcmp(data[j], key) > 0 ); j--){
					//data[j + 1] = data[j] ;
          strcpy(data[j+1] , data[j]);
				}
				//data[j+1] = key;
        strcpy(data[j+1] , key);
				n++;
				break;
			case 2 :
				scanf("%s", key);
				if(LinearSearch(n, data, key) != -1 ){
					printf("found: %s\n", key);
					//printf("%d: %d\n",BinarySearch(n, data, key), key );
				}

				break;
			case 3 :
				scanf("%s", key);
				if(BinarySearch(n, data, key) != -1 ){
					printf("found: %s\n", key);

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
