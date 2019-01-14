#include <iostream>
using namespace std;

int main(){
  int s,m,h;
  cout << "Seconds: ";
  cin >> s;
  h = s / 3600;
  m = (s - (h*3600)) / 60;
  s = s - (3600*h) - (60*m);
  cout << h << " hours, " << m << " minutes, " << s << " seconds";
  return 0;
}
