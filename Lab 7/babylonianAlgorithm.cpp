#include <iostream>
using namespace std;

int main(){
  double guess,r,n;
  cout << "Square Root of: ";
  cin >> n;
  guess = n/2;
  for(int i = 0 ; i < 5 ; i++){
    r = n/guess;
    guess = (guess+r)/2;
    cout << guess << endl;
  }
  return 0;
}
