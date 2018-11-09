#include <iostream>
using namespace std;

void swapValues(int &var1, int &var2); // must include & for call by reference

int main()
{
  int x,y;
  cout << "values for x and y ";
  cin >> x >> y;

  cout << "pre-swap: x = " << x << " y = " << y << endl;

  // call swap function
  swapValues(x,y);

  cout << "post-swap: x = " << x << " y = " << y << endl;

  return 0;
}

void swapValues(int &var1,int &var2)
{
  int x = var1;
  var1 = var2;
  var2 = x;
}
