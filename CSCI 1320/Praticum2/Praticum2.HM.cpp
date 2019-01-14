// Henry Meyerson
// Praticum 2
// 109190761
// Section 112
#include <iostream>
using namespace std;

void finalPrac(int arr[], int aSize, int &x);

int main(){
  int size = 5; // 9, 8, 5
  int test[] = {4,1,5,1,8}; // {4,3,1,5,3,3,1,8,3}, {2,2,7,0,1,8,8,5}, {4,1,5,1,8}
  int split = 3; // 3, 8, 3

  finalPrac(test,size,split);

  cout << "arr = { ";
  for(int i = 0; i < size; i++)
    cout << test[i] << " ";

  cout << "} and x = " << split;
  return 0;
}

void finalPrac(int arr[], int aSize, int &x){
  bool present = 0;
  int loc = 0;
  for(int i = 0; i < aSize; i++){
    if(arr[i]==x){
      present = 1;
      loc = i;
      break;
    }
  }
  if(present){
    for(int i = 0; i < loc; i++){
      arr[i] = 1;
      x+=1;
    }

    for(int i = loc+1; i < aSize; i++){
      arr[i] = -1;
      x+=-1;
    }
  }else{
    x = 0;
  }
}
