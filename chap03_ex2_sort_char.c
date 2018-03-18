#include <stdlib.h>
#include <stdio.h>
#define N 6

void swap(int *a , int *b ){
  int temp = *a;
  *a = *b ;
  *b = temp;

}

void print(int n, int *ary)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("%d ", ary[i]);
    }
    printf("\n");
}


void bsort (int n , int *data){
  int i , j ;
  for(i=n; i>1; i--)
    {
        for(j=0; j<i-1; j++)
        {
            if(data[j+1] < data[j])
            {
               swap(&data[j+1], &data[j]);
            }
        }
        print(n, data);
    }


}
void ssort(int n, int *data)
{

    int i, j, pos;  // pos: 紀錄目前最小值位置
    for(i=0; i<n-1; i++)
    {
        pos = i;
        for(j=i+1; j<n; j++)
        {
            if(data[j] < data[pos])
                pos = j;
        }
        swap(&data[i], &data[pos]);
        print(n, data);
    }


}
void isort(int n, int *data)
{
    int i, j;
    int key;

    for( i=1; i<n; i++)
    {
        key=data[i];
        for(j=i-1; j>=0 && data[j]>key; j--)
        {
            data[j+1] = data[j];
        }
        data[j+1] = key;  //將key插入
        print(n, data);
    }

}


int main (){
  int ary[N];
	int i;
	int op;
	for(i=0;i<N;i++){
		scanf("%d", &ary[i]);
	}

	scanf("%d", &op);
	switch(op)
	{
		case 1:
			bsort(N, ary);
			break;
		case 2:
			ssort(N, ary);
			break;
		case 3:
			isort(N, ary);
			break;
	}
	print(N, ary);




  return 0;
}
