#include <iostream>
using namespace std;


int main(){
    int x[5];
    double y[3] ;
    for(int i = 0 ; i < 5 ; i++){
        cout << "x[" << i << "] = "<< &x[i] << '\n';
    }
    for(int j = 0 ; j < 3 ; j++){
        cout << "y[" << j << "] = "<< &y[j] << '\n';
      }

    return 0 ;

}
