#include <iostream>
using namespace std;

int min(int x, int y) {cout<<"min"<<endl; return x < y ? x : y; }
int max(int x, int y) {cout<<"max"<<endl; return x < y ? y : x; }
void incr(int *xp, int v) {cout<<"incr"<<endl; *xp += v; }
int square(int x) {cout<<"sq"<<endl; return x*x; }

int main(){
  int x = 10;
  int y = 100;
  int low = min(x,y);
  int high = max(x,y);
  int t = 0;
  for (int i = low; i < high; incr(&i, 1))
    t += square(i);
}
