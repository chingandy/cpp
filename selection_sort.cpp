#include<iostream>

using namespace std;


void swap(int &x, int &y){
  int temp;
  temp = x ;
  x = y ;
  y = temp ;
}
void selection_sort(int a[] , int n){
  int pos;

  for(int i = 0 ; i <  n ; i ++){
    pos = i ;
    for(int j = i + 1 ; j < n ; j++){
      if(a[pos] > a[j])
        pos =  j;
    }
    swap(a[pos] , a[i]);
  }


}

int main(){

  int a[5] ;
  for(int i = 0 ; i  < 5 ; i++){
    cin >> a[i];
  }

  for(int i = 0 ; i  < 5 ; i++){
    cout << a[i] << " ";
  }
  cout << endl;
  selection_sort(a , 5);
  for(int i = 0 ; i  < 5 ; i++){
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
