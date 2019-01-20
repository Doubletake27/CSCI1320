#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue);
void arrayPrint(int arr[], int numEntries);

int main(int argc, char *argv[]){
  string fname = argv[1];

// int main(){  // For easy testing purposes
  // string fname = "numbers.txt";

  int arrLen = 0;
  string num;
  int sArray[100];

  ifstream numberFile;
  numberFile.open(fname);

  if(numberFile.is_open()){
    while(!numberFile.eof()){
      getline(numberFile,num,'\n');
      arrLen = insertIntoSortedArray(sArray,arrLen,stoi(num));
      arrayPrint(sArray, arrLen);
    }

    numberFile.close();
    return 0;
  }else{
    cout << "Failed to open the file." << endl;
    exit(0);
    return -1;
  }
}

int insertIntoSortedArray(int myArray[], int numEntries, int newValue){
  int temp1,temp2;
  int pos = numEntries;
  for(int i = 0; i < numEntries; i++){
    if(newValue < myArray[i]){
      pos = i;
      break;
    }
  }
  temp1= myArray[pos];
  myArray[pos] = newValue;
  for(int i = pos+1; i <= numEntries; i++){
    temp2 = myArray[i];
    myArray[i] = temp1;
    temp1 = temp2;
  }
  return ++numEntries;
}

void arrayPrint(int arr[], int numEntries){
  for(int i = 0; i < numEntries-1; i++){
    cout << arr[i] << ",";
  }
  cout << arr[numEntries-1]<< endl;
}
