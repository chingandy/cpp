#include<iostream>
using namespace std;

int main(){
  int size = 0 ;
  int* x = new int[size];
  int* y = new int(1000);
  cin >> size ;
  for (int i = 0 ; i < size ; i ++){
    x[i] = i ;
  }
  for(int j = 0 ; j < size ; j ++){
    cout << x[j] << '\n';
  }
  cout << "y = " << y << '\n';
  cout << "*y = " << *y << '\n';
  cout << "y[0] = " << y[0] << '\n';
  return 0 ;
}
