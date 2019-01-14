// SortArr Driver

#include <iostream>
#include <ctime>
using namespace std;

void sortArr(int arr[], int len); // Initialize sortArr Function
void dispArray(int arr[], int len); // Initialize dispArray Function

int main(){
  const int n = 5; // This can later be changed to a cin

  int ArrA[] = {0, 4, 90, 3, 253};
  int ArrB[] = {95, 2, 56, 65, 1};
  // Call Rand Arrays for n values

  sortArr(ArrA,n); // Sorts Array A
  dispArray(ArrA,n); // Displays Array A

  sortArr(ArrB,n); // Sorts Array B
  dispArray(ArrB,n); // Displays Array B

}

void sortArr(int arr[], int len){
  // Function Stub, just fills a matrix with random numbers for right now
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
