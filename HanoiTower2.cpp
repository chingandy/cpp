#include<iostream>
#include<vector>
using namespace std;

vector<int> A;
vector<int> B;
vector<int> C;

void hanoi(int n , char from , char mid , char to, int count[] )
{
	int i ;
		//int count[3] = {0};
		if (n == 0 ){
			return ;
		}
		hanoi(n -1 , from , to , mid, count);

		switch(from){
			case 'A':
				if(A.size()!= 0 )
					A.pop_back();
				break;
			case 'B':
				if(B.size()!= 0 )
					B.pop_back();
				break;
			case 'C':
				if(C.size()!= 0 )
					C.pop_back();
				break;
		}
		switch(to){
			case 'A':
				A.push_back(n);
				break;
			case 'B':
				B.push_back(n);
				break;
			case 'C':
				C.push_back(n);
				break;
		}
		cout << "Plate A:";
		for(i = 0 ; i < A.size()  ; i ++){
			cout << A[i] << " ";
		}cout <<"\n";
		cout << "Plate B:";
		for(i = 0 ; i < B.size(); i ++){
			cout << B[i] << " ";
		}cout << "\n" ;
		cout << "Plate C:";
		for(i = 0 ; i < C.size(); i ++){
			cout << C[i] << " ";
		}cout << "\n\n" ;

		//printf("plate %d from %c -> %c\n", n, from , to);
		count[n-1]++;
		hanoi(n-1 , mid, from , to, count);

}

int main(){

	int i,n ;
	cin >> n;


	for(i = n ; i > 0  ; i --){
		A.push_back(i);

	}

	int count[100] = {0};
	hanoi(n , 'A' , 'B', 'C',count);
	cout << endl;
	for(i= 1 ; i < n + 1  ; i++){
		//cout << "plate %d = %d\n", i , count[i-1] );
		cout << "plate " << i << "=" << count[i-1] << endl;
	}

	return 0;
}
