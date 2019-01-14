// Array Merge Driver

#include <iostream>
#include <ctime>
using namespace std;

void arrayMerge(int a[], int b[], int c[], int len); // Initialize Array Merge Function
void dispArray(int arr[], int len); // Initialize dispArray Function

int main(){
  const int n = 5; // This can later be changed to a cin

  int ArrA[] = {0, 4, 90, 3, 253};
  int ArrB[] = {95, 2, 56, 65, 1};
  int ArrC[(2*n)];

  cout << "Array A Initial: " << endl;
  dispArray(ArrA,n); // Displays Array A
  dispArray(ArrB,n); // Displays Array B
  arrayMerge(ArrA,ArrB,ArrC,n); // Calls arry merge on A and B
  dispArray(ArrC,(n*2)); // Displays Array C

}

void arrayMerge(int a[], int b[], int c[], int len){
  for(int i=0;i<len;i++)
    c[i]=a[i];
  for(int i=0;i<len;i++)
    c[i+len]=b[i];
}

void dispArray(int arr[], int len)
{
  // This is an auxiliary function. Not the function being tested.
  for(int i=0;i<len;i++)
  cout << arr[i] << " ";
  cout << endl;
}
