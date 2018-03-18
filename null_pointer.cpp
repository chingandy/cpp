#include <cstddef>
#include <iostream>
using namespace std;

int main(){
  int asize ;
  cout << "元素數：";
  cin >> asize ;

  int* a = new(nothrow) int[asize];

  if(a == NULL){
    cout << "因為產生陣列失敗，所以終止程式。\n";
    return 1 ;
  }
  for (int i = 0 ; i < asize ; i++){
    a[i]=i;
  }
  for (int i = 0 ; i < asize ; i ++){
    cout << "a[" << i <<"] = " << a[i] <<'\n';

  }
  delete[] a ;
  return 0 ;
}
