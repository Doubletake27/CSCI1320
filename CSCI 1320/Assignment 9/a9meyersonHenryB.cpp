// Assignment 9:  Version - B

#include <iostream>
#include <ctime>
using namespace std;

void randArrays(int arr[], int len); // Initialize randArrays Function
void dispArray(int arr[], int len); // Initialize dispArray Function
void sortArr(int arr[], int len, bool dir); // Initialize sortArr Function
void swap2(int j, int arr[]); // Initialize the Swap2 function

int main(){
  srand(time(NULL)); // Seed Random generation of values
  const int n = 10; // This can later be changed to a cin

  int ArrA[n];
  int ArrB[n];

  cout << "Array A: " << endl;
  randArrays(ArrA,n); // Fills Array A with random numbers
  dispArray(ArrA,n); // Displays Array A
  sortArr(ArrA,n,0); // Sort Array A in the Ascending direction
  dispArray(ArrA,n); // Displays SORTED Array A

  cout << "Array B: " << endl;
  randArrays(ArrB,n); // Fills Array B with random numbers
  dispArray(ArrB,n); // Displays Array B
  sortArr(ArrB,n,1); // Sort Array B in the Desceing direction
  dispArray(ArrB,n); // Displays SORTED Array B

}

void randArrays(int arr[], int len){
  for(int i= 0; i < len;i++){
    arr[i] = rand()%1001; // Fills all values of matrix with rand numbers b/w 0-1000
  }
  // No return as it is aready editing the data at where it is stored.
}

void dispArray(int arr[], int len){
  for(int i=0;i<len;i++)
  cout << arr[i] << " ";
  cout << endl;
}

void sortArr(int arr[], int len, bool dir){
  if(dir == 0){
    // Ascending Implementation
    for(int i = len-1; i>0; i--){
      for(int j = 0; j < i; j++){
        if(arr[j]>arr[j+1]){ // This is the swap 2 function start
          swap2(j,arr);
        } //this is the swap 2 function end
      }
    }
  }else{
    // Descending Impleentation
    for(int i = len-1; i>0; i--){
      for(int j = 0; j < i; j++){
        if(arr[j]<arr[j+1]){ // This is the swap 2 function start
          swap2(j,arr);
        } //this is the swap 2 function end
      }
    }
  }
}

void swap2(int j, int arr[]){
  int temp; // Initializing a temporary variable
  temp = arr[j];
  arr[j] = arr[j+1];
  arr[j+1] = temp;
}
