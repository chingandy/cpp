#include<iostream>

using namespace std;

class Square{
public:
  Square(int n ){
    len = n ;
  }
  int getlen(){
    return len;
  }
  int area(){
    return len * len ;
  }
  friend class Ruler;
private:
  int len;

};

class Ruler{
public:
  Ruler(int n){
    len =n ;
  }
  void compareSquare(Square &s1, Square &s2){
    if(len < s1.len || len < s2.len){
      cout << "the ruler is too short!"<<endl;
    }
    else{
      if(s1.len > s2.len){
        cout << "s1 is bigger!\n";
      }
      else if(s1.len == s2.len){
        cout << "s1 is as big as s2.\n";
      }
      else{
        cout<< "s2 is bigger!\n";

      }

    }

  }
private:
  int len ;
};

int main(){
  Square s1(10) ;
  Square s2(15) ;
  Ruler r1(10) , r2(20);

  r1.compareSquare(s1, s2);
  r2.compareSquare(s1, s2);

  return 0;
}
