#include <iostream>
using namespace std;

#define DEBUG 1

int main(){

  int a = 5 ;
  int x = 1 ;

  #if DEBUG == 1
    a = x;
  #endif

    cout << "a的值為" << a <<"。\n";
  return 0 ;
}
