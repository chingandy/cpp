#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(){

  char a[100];
  char b[100];
  int i ;
  scanf("%s" , a);
  scanf("%s" , b);

  printf("a = %s\n" , a);
  printf("b = %s\n" , b);
  printf("strcmp = %d \n" , strcmp(a ,b));
  strcpy(a , b);
  printf("a = %s\n" , a);
  printf("b = %s\n" , b);
  printf("strcmp = %d \n" , strcmp(a ,b));
  return 0;
}
