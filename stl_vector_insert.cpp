#include<iostream>
#include<vector>

using namespace std;
int main(){
  int i ;
  vector<int> v;
  int a[]={10 , 20 , 30};
  v.insert(v.begin(), a , a+3);
  v.insert(v.begin(), 1000);
  v.insert(v.begin()+2 , 233);
  v.insert(v.end(),121212 );
  for(int i = 0 ; i < v.size() ; i ++){
    cout << " " << v[i];
  }
  cout << endl;
  v.erase(v.begin()+4);
  for(int i = 0 ; i < v.size() ; i ++){
    cout << " " << v[i];
  }
  cout << endl;
  v.erase(v.begin() , v.begin()+2);
  for(int i = 0 ; i < v.size() ; i ++){
    cout << " " << v[i];
  }
  cout << endl ;
  return 0 ;
}
