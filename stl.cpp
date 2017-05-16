#include<iostream>
#include<vector>

using namespace std;
int main(){
  vector<int> v1;
  vector<int> v2;
  v1.push_back(100);
  v1.push_back(200);
  v1.push_back(300);
  int sum = 0;

  while(!v1.empty() ){
    sum += v1.back();
    cout << v1.back()<<" ";
    v1.pop_back();
  }
  cout << endl;
  cout << "sum = " << sum<<endl;
  return 0 ;
}
