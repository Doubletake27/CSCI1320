#include <iostream>
using namespace std;

int main()
{
  const int arrSize = 5;
  int score[arrSize];
  int i, max;

  cout << "Enter 5 scores: " << endl;

  for(i=0; i < arrSize; i++) // Take inputs
    cin >> score[i];

  max = score[0];
  for(i = 0; i < arrSize; i++)
    if(max < score[i])
      max = score[i];

  cout << " Max Score: " << max <<endl;

  return 0;
}
