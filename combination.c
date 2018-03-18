#include <stdlib.h>
#include <stdio.h>

int combination(int n , int m){
  if(n == m || m == 0)
    return 1;
  return combination(n - 1 , m) + combination(n -1 , m -1);
}


int main(){
  int n , m ;
  scanf("%d" , &n);
  scanf("%d" , &m);
  if( m > n){
    printf("input error\n");
    return 0 ;
  }
  printf("%d\n" , combination(n , m ));

  return 0;
}
