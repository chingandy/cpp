#include<iostream>

using namespace std;
template <class type> type maxof(type a, type b){
  return a > b ? a : b ;
}

int main(){
  int a , b;
  double c ,d ;
  char s ,t ;
  cin >> a >> b ;
  cout << maxof(a, b) << "\n";
  cin >> c >> d ;
  cout << maxof(c ,d)<<"\n";
  cin >> s >> t ;
  cout << "s = " << s ;
  cout << "t = " << t ;
  cout << maxof(s, t) << "\n" ; 
  return 0 ;
}
