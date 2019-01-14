// Henry Meyerson
// 109190761
// CSCI 1320 - 112
// Project - Extra Credit

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

int lookUp(string words[], int len, string word);

int main(){
  long int t = time(NULL);
  // This will be the length and width of the 2D array because it is square
  // const int D = 7732; // This is for Length of AllWords
  const int D = 7682; // This is for length of CleanedWords

  string fname = "cleanedText.txt";
  string word1;
  string word2;
  long int j=0; // Will represent position in wordBank to place new unique words

  // Creates Indexing Array called words
  string words[D];
  // This will come from either "sortedAllWords.txt" or "sortedCleanWords.txt"
  ifstream wordList;
  wordList.open("sortedCleanWords.txt");
  for(int i = 0; i< D; i++){ // I normally would make this a while loop but we already have the length
    wordList >> words[i];
  }

  // Create 2D array to replace the array of structs of dimentions d x d
  // int wordBank2D[D][D]; // This created a seg Fault so I had to do some reseach
  int **wordBank2D = new int*[D];
  for(int i = 0; i < D; ++i) {
      wordBank2D[i] = new int[D];
  }
  // End of mildly sketchy array declaration

  // Fill Array with 0s
  for(int i = 0; i<D; i++){
    for(int j = 0; j<D; j++){
      wordBank2D[i][j] = 0;
    }
  }

  // Open file
  ifstream clean;
  clean.open(fname);

  clean >> word1;
  // Loop Through Entire Array of words to check if unique
  int test = 0;
  while(!clean.eof()){
    clean >> word2;
    wordBank2D[lookUp(words,D,word1)][lookUp(words,D,word2)]++;
    test++;
    word1 = word2;
  }
  // Close File
  clean.close();

  // ---- Locate Highest Occuring Values
  // Create 3x10 array to store x, y, occurances of 10 most popular
  int pop[3][10];
  // Fill Array with 0s
  for(int i = 0; i<3; i++){
    for(int j = 0; j<10; j++){
      pop[i][j] = 0;
    }
  }

  int bigPos;
  // Find most
  for(int i = 0; i<D; i++){
    for(int j = 0; j<D; j++){ // Loops Through wordBank2D Array
      bigPos=0;
      for(int k = 0; k <10; k++){
        if(wordBank2D[i][j]>pop[2][k]){
          bigPos=k;
        }else{
          break;
        }
      }
      if(bigPos!=0){ // shifts everything down
        for(int p = 0; p<bigPos; p++){
          pop[2][p] = pop[2][p+1];
          pop[1][p] = pop[1][p+1];
          pop[0][p] = pop[0][p+1];
        }
        pop[2][bigPos] = wordBank2D[i][j];
        pop[1][bigPos] = j;
        pop[0][bigPos] = i;
      }
    }
  }

  cout << "Most Popular Combos: " << endl;
  for(int i = 0; i<10; i++){
    cout << words[pop[0][i]]<< " " << words[pop[1][i]] << " x" << pop[2][i] <<endl;
  }
  // ---- Done Locating High Values

  // Cannot locate least values with this method as there are many 0s and 1s in the array too many to be special
  // Additionally they will not be found by the method I did

  // Cleaning Up Sketchy Array that I don't understand
  for(int i = 0; i < D; ++i) {
      delete [] wordBank2D[i];
  }
  delete [] wordBank2D;
  /// Finished cleaning up sketchy Array

  cout << "Time Elapsed: " << (time(NULL)-t) << " seconds" << endl;

  return 0;
} // END OF MAIN

int lookUp(string words[],int len,string word){
  int pos = 6969;
  for(int i = 0; i < len; i++){
    if(words[i]==word){
      pos = i;
      break;
    }
  }
  return pos;
}
