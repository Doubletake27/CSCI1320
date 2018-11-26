//swap2 function

#include <iostream>
#include <ctime>
using namespace std;

void swap2(int j, int arr[]); // Initialize swap2 Function
void dispArray(int arr[], int len); // Initialize dispArray Function

int main(){
  const int n = 5; // This can later be changed to a cin
  int j = 2; // This variable is for the position of the two values to be swapped

  int ArrA[] = {0, 4, 90, 3, 253};

  cout << "Array A Initial: " << endl;
  dispArray(ArrA,n); // Displays Array A
  swap2(j,ArrA); // Swaps Values of index j and j+1 in array A
  dispArray(ArrA,n); // Displays Array A

}

void swap2(int j, int arr[]){
  int temp; // Initializing a temporary variable
  temp = arr[j];
  arr[j] = arr[j+1];
  arr[j+1] = temp;
}

void dispArray(int arr[], int len)
{
  // This is an auxiliary function. Not the function being tested.
  for(int i=0;i<len;i++)
  cout << arr[i] << " ";
  cout << endl;
}
