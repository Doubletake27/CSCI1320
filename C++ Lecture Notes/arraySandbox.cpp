#include <iostream>
using namespace std;

void myArrFunc(int arr[]);
// int foo();

int main(){
  int myArr[4];
  cout << myArr << endl; // This returns the hexadecimal value of the address of the first element of the array
  myArrFnc(myArr);
  // int x = foo();
  return 0;
}

void myArrFunc(int arr[]){
  cout << "address from myArrFunc()" << arr << endl;
}

// int foo(){
//   int someArray[] = {1,2};
//   return someArray
// }
