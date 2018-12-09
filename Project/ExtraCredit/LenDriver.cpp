// File Len Driver

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int numWords(string fname); // Initializing Num Words Function

int main(){
  string fnames[] = {"allWords.txt","cleanWords.txt","sortedAllWords.txt","sortedCleanWords.txt"};
  int len = 4;

  for(int i = 0; i<len; i++)
    cout << fnames[i] << " has " << numWords(fnames[i]) << " words" << endl;

  return 0;
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
