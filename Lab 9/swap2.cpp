/////////// THIS NEEDS TO STILL BE FINISHED ////////

////
///

///
//
//
//







//swap2 function

#include <iostream>
#include <ctime>
using namespace std;

void swap2(int arrA[], int len); // Initialize sortArr Function
void dispArray(int arr[], int len); // Initialize dispArray Function

int main(){
  const int n = 10; // This can later be changed to a cin

  int ArrA[10];
  int ArrB[n];
  // Call Rand Arrays for n values

  randArrays(ArrA,n); // Fills Array A with random numbers
  dispArray(ArrA,n); // Displays Array A

  randArrays(ArrB,n); // Fills Array B with random numbers
  dispArray(ArrB,n); // Displays Array B

}

void sortArr(int arr[], int len){
  // Function Stub, just fills A with random numbers for right now
  for(int i= 0; i < len;i++){
    arr[i] = rand()%1001; // Fills all values of matrix with rand numbers b/w 0-1000
  }
  // No return as it is aready editing the data at where it is stored.
}

void dispArray(int arr[], int len)
{
  // This is an auxiliary function. Not the function being tested.
  for(int i=0;i<len;i++)
  cout << arr[i] << " ";
  cout << endl;
}
