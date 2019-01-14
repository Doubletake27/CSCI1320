//Write a function that takes in a 2D array (MxN and fills it with random integers between 0 and 10)
  // Fill one row of the array by iterating over the second dimension
  // Advance to next row by incrementing 1st dimension iterator

#include <iostream>
#include <ctime>
using namespace std;

const int M = 4;
const int N = 3;

void fillArray(int Arr[][N]);

int main(){
  srand(time(NULL));
  int arr2d[M][N];

  fillArray(arr2d);

  for(int j = 0; j < M; j++){
    for(int i = 0; i < N; i++)
      cout << arr2d[j][i] << " ";
    cout << endl;
  }

  return 0;
}

void fillArray(int Arr[][N]){
  for(int j = 0; j < M; j++)
    for(int i = 0; i < N; i++)
      Arr[j][i] = rand()%11;

}
