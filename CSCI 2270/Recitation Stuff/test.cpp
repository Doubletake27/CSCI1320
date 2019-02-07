#include <iostream>
using namespace std;

int main(){
  int x = 5;
  int &y=x;
  x = 20;
  y = 10;
  cout << x << ","<<y<<endl;
}
