#include<iostream>
#include<list>
using namespace std;


int main(){
  list<double> L1, L2;
  list<double>::iterator it;
  L1.push_back(3.1);
  L1.push_back(2.2);
  L1.push_back(2.9);
  L2.push_back(3.7);
  L2.push_back(7.1);
  L2.push_back(1.4);
  L1.merge(L2);
  L2.push_back(2.1);
  L1.merge(L2);
  for(it = L1.begin() ; it != L1.end() ; it++){
    cout << *it <<endl;
  }
  return 0;

}
