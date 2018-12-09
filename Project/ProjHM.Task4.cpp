// Henry Meyerson
// 109190761
// CSCI 1320 - 112
// Project

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

struct wordPairs
{
   string word1;
   string word2;
   int noOccurances;
};

int numWords(string fname); // Initializing Num Words Function
void sortArr(wordPairs arr[], long int len); // Initalizing Sort function
int isUnique(wordPairs list[], long int len, string word1, string word2); // This needs to be a pass by reference
  // Is unique will either return the next value if its is unique or the location if it is not

int main(){
  long int t = time(NULL);
  string fname = "HungerGames.txt";
  string word1;
  string word2;
  long int j=0; // Will represent position in wordBank to place new unique words
  long int pos;
  long int len = numWords(fname); // this is a long int such that it runs well when fname ="HungerGames.txt"
  // cout << len << endl;
  cout << "len = " << len << endl;

  //  Create Array of Structs
  wordPairs wordBank[len];
  // Open file
  ifstream clean;
  clean.open(fname);

  clean >> word1;
  // Loop Through Entire Array of words to check if unique
  for(int i=0; i < (len-2);i++){
    clean >> word2;
    pos = isUnique(wordBank,j,word1,word2); // Calls isUnique on each word
    if(pos==j){ // Createst
      wordBank[j].word1 = word1;
      wordBank[j].word2 = word2;
      wordBank[j++].noOccurances = 1;
    }else{
      wordBank[pos].noOccurances++;
    }
    word1 = word2;
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
  cout << j << " unique word pairs" << endl;

  cout << endl << "The Ten Most Unique Words Pairs:" << endl;
  for(int i=0;i<10;i++){
    cout << wordBank[i].word1 << " " << wordBank[i].word2 << " x" << wordBank[i].noOccurances << endl;
  }
  // Prints Bottom 10
  cout << endl << "The Ten Least Unique Word Pairs:" << endl;
  for(int i=j-10;i<j;i++){
    cout << wordBank[i].word1 << " " << wordBank[i].word2 << " x" << wordBank[i].noOccurances << endl;
  }
  cout << "Time Elapsed: " << (time(NULL)-t) << " seconds" << endl;
  return 0;
}

int isUnique(wordPairs list[], long int len, string word1, string word2){ // Switch to pass by reference
  int i = 0;
  bool match = 0;

  while((i<len)&&(match!=1)){ // While still in the array of things that exist and not yet found a match
    if((word1 == list[i].word1)&&(word2 == list[i].word2)){
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
void sortArr(wordPairs arr[], long int len){
  wordPairs temp; // Initializing a temporary variable
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
