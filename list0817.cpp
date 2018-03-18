#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

bool f(int x ){
  return (x >= 30 && x <= 60);
}

bool g(int x) {
  return (x >= 10 && x <= 30 ) || (x>= 70 && x <= 80);

}
void ary_disp( int a[] , int n , bool func (int x)){
  for(int i = 0 ; i < n ; i++){
    if(func(a[i])){
      cout << "★";
    }
    else{
      cout << "☆" ;
    }
    cout << "a[" << i<< "] =" << a[i] << '\n';
  }

}

int main(){
  srand(time(NULL));
  int a[10];
  for(int i = 0 ; i < 10 ; i ++){
    a[i] = rand()%100;

  }
  ary_disp(a , 10 , f);
  cout <<"-----------------------\n";
  ary_disp(a , 10 , g);

  return 0 ;
}
