// Henry Meyerson
// 109190761
// CSCI 1320 - 112
// Lab 10

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int asciiSum(string word); // Initializes ASCII Sum
void sortArr(string arr[], int len); // Initialize sortArr Function
void swap2(int j, string arr[]); // Initialize the Swap2 function

int main(){
  // Read in Text file
  ifstream testFile;
  testFile.open("lab10test.txt");

  string word; // Initialize Variable that each word will be stored in
  string temp; // Stores Previous Word
  int len = 0; // Initialize counting variable
  int sum; // Ascii Sum

  testFile >> word;
  // Loop through every word  -- While loop
  do{
    // cout << "Word " << ++len << " = " << word << ", "<< asciiSum(word) << endl; // Prints Word Info
    len++;
    temp = word;

    // Pull New Word
    testFile >> word;
  }while(word != temp);
  // Prints file length
  cout << len << " words in file" << endl;

  cout << " - - - - - - - " << endl;

  // Stop Reading
  testFile.close();
  testFile.open("lab10test.txt");

  string sentence[len]; // Creates a string array with a length of len
  for(int i = 0; i < len; i++) // Populates Array
    testFile >> sentence[i];

  // Sort Words by ASCII Sum
  sortArr(sentence,len);

  // Displays New Array W/ ASCII Sum
  for(int j = 0; j < len; j++)
    cout << sentence[j] << " " << asciiSum(sentence[j]) << endl;

  return 0;
}

// Calclates ASCII sum
int asciiSum(string word){
  int sum = 0;
  for(int i=0;i<word.length();i++){
    //cout << "  " << i << " " << word[i] << " = " << int(word[i]) << endl;
    sum += int(word[i]);
  }
  return sum;
}

// Bubble Sort Words
void sortArr(string arr[], int len){
  for(int i = len-1; i>0; i--){
    for(int j = 0; j < i; j++){
      if(asciiSum(arr[j])>asciiSum(arr[j+1])){
        swap2(j,arr);
      }
    }
  }
}

void swap2(int j, string arr[]){
  string temp; // Initializing a temporary variable
  temp = arr[j];
  arr[j] = arr[j+1];
  arr[j+1] = temp;
}
