// dogAge
// 10-29-18

#include <iostream>
#include <string> // allows us to use strings
using namespace std;

int main()
{
  string dogName;
  const double D2H_FACTOR = 7.4;
  int actualAge;
  double humanAge;

  cout << "How many years old is your dog? " << endl;
  cin >> actualAge;
  humanAge = actualAge*D2D2H_FACTOR;

  cout << "What is you dog's name? "
  cin >> dogName;

  cout << dogName << "'s age is approximately equivalent to a " << humanAge << year old human." << endl;

  return 0;
}
