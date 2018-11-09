#include <iostream>
using namespace std;

int main()
{
  const int arrSize = 5;
  int score[arrSize];
  int i, max;

  cout << "Enter 5 scores: " << endl;

  for(i=0; i < arrSize; i++)
    cin >> score[i];

  return 0;
}
