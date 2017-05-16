#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARD 52
#define NUMBER 13
#define SUIT 4
#define PEOPLE 4

#define MAX_SIZE 52

// 堆疊結構的宣告
int stack[MAX_SIZE];
int top=-1;


// 堆疊資料的存入
int push(int value)
{
  if(top == MAX_SIZE - 1){
    return -1;
  }
  top += 1 ;
  stack[top] = value;
  return 1 ;
}

//堆疊資料的取出
int pop()
{
  if(top == -1){
    return -1;
  }
  int temp ;
  temp = stack[top];
  stack[top] =  0 ;
  top -- ;
  return temp ;
}

void InsertionSort(int n, int *data)
{
  int i , j ;
  int pos;
  for(i = 0 ; i < n ; i ++){
    pos = data[i];
    j = i;
    while(data[j-1] > pos){
      data[j] = data[j-1];
      j -- ;
    }
    data[j] = pos;
  }
}

void reshuffle()
{
  int pos;
	int i;
	int card[CARD]={0};
	srand(time(NULL));
	i=0;
	while(i!=CARD)
	{
		pos = rand()%CARD;
		if(card[pos]==0)
		{
			push(pos);
			card[pos]=1;
			i++;
		}
	}
}

void displayCard(int n, int *card)
{
  int i;

	printf("Player%d:\n", n+1);
	for(i=0; i<CARD/PEOPLE; i++)
	{
		printf("[%c%2d] ", card[i]/NUMBER+3, card[i]%NUMBER+1);
	}
	printf("\n");
}

// 主程式
int main()
{
	// 宣告
	int i, j;
	int player[PEOPLE][CARD/PEOPLE];

	// 洗牌
	reshuffle();

	// 發牌
	for(i=0; i<CARD/PEOPLE; i++)
	{
		for(j=0; j<PEOPLE; j++)
		{
			player[j][i] = pop();
		}
	}

	// 看牌
	for(i=0; i<PEOPLE; i++)
		displayCard(i, player[i]);
	printf("\n");

	// 排序
	for(i=0; i<PEOPLE; i++)
	{
		InsertionSort(CARD/PEOPLE, player[i]);
		displayCard(i, player[i]);
	}
	system("pause");
	return 0;
}
