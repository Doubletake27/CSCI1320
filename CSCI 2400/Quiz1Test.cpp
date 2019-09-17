#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int v = 0x2443a858;
  int q = ~( -1 << 2);
  // char * p = "yo?";
  // cout << &p;
  std::cout << std::hex << v&q ;
}
