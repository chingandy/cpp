#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

int main()
{
  srand(time(NULL));
  int x = rand();
  int y = rand();

  cout << x <<endl<<y<<endl;

  return 0;
}
