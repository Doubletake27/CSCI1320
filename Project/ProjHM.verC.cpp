// Henry Meyerson
// 109190761
// CSCI 1320 - 112
// Project

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct UniqueWord
{
   string word;
   int noOccurances;
};

int numWords(string fname); // Initializing Num Words Function
void sortArr(UniqueWord arr[], int len); // Initalizing Sort function
int isUnique(UniqueWord list[],int len, string word); // This needs to be a pass by reference
  // Is unique will either return the next value if its is unique or the location if it is not

int main(){
  string fname = "cleanedText.txt";
  string word;
  int j=0; // Will represent position in wordBank to place new unique words
  int pos;
  int len = numWords(fname);

  //  Create Array of Structs
  UniqueWord wordBank[len];

  // Open file
  ifstream clean;
  clean.open(fname);

  // Loop Through Entire Array of words
  for(int i=0; i < len;i++){
    clean >> word;
    pos = isUnique(wordBank,j,word); // Calls isUnique on each word
    if(pos==j){ // Createst
      wordBank[j].word = word;
      wordBank[j++].noOccurances = 1;
    }else{
      wordBank[pos].noOccurances++;
    }
  }

  // Close File
  clean.close();

  // Sort Ascending
  sortArr(wordBank,j);


  // Prints Everything
  // for(int i=0;i<j;i++){
  //   cout << wordBank[i].word << " x" << wordBank[i].noOccurances << endl;
  // }

  // Prints Top 10
  cout << "The Ten Most Unique Words:" << endl;
  for(int i=0;i<10;i++){
    cout << wordBank[i].word << " x" << wordBank[i].noOccurances << endl;
  }
  // Prints Bottom 10
  cout << endl << "The Ten Least Unique Words:" << endl;
  for(int i=j-10;i<j;i++){
    cout << wordBank[i].word << " x" << wordBank[i].noOccurances << endl;
  }


  return 0;
}

int isUnique(UniqueWord list[], int len, string word){ // Switch to pass by reference
  int i = 0;
  bool match = 0;

  while((i<len)&&(match!=1)){ // While still in the array of things that exist and not yet found a match
    if(word == list[i].word){
      match = 1;
    }else{
      i++;
    }
  }

  if(match){ // if there is a match
    return i; // This is position where the word already exists
  }else{ // if there isn't a match
    return len;  // This will be the next entry
  }
}

// Bubble Sort Words
void sortArr(UniqueWord arr[], int len){
  UniqueWord temp; // Initializing a temporary variable
  for(int i = len-1; i>0; i--){
    for(int j = 0; j < i; j++){
      if(arr[j].noOccurances>arr[j+1].noOccurances){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int numWords(string fname){
  int len = 0;
  string word;
  // Read in Entire file
  ifstream hgFile;
  hgFile.open(fname);

  // Count number of words
  while(!hgFile.eof()){
    hgFile >> word;
    len++;
  }
  // Close file
  hgFile.close();
  return len;
}
