#include <iostream>
#include <cmath>
using namespace std;

int gcdr(int x , int y){
  if(y == 0 ) {return x ;}
  if(y > x) {
    return gcdr(y , x);
  }
  else {
    return gcdr(x%y , y);
  }
}

int gg(int a){
  ;
}


int gcde ( int a, int b )
{
  if ( a==0 ) return b;
  return gcde( b%a, a );
}
int main(){

  int a , b ;
  cin >> a >> b ;
  cout << "gcdr of "<<a << " and " <<b <<" is :" << gcdr(a , b) << '\n';
  cout << "gg(a) = "<<gg(a)<<'\n';
  //cout << "gcd of "<<a << " and " <<b <<" is :" << gcd(a , b) << '\n';

  return 0 ;
}
