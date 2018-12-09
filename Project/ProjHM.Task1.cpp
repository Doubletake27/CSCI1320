// Henry Meyerson
// 109190761
// CSCI 1320 - 112
// Project

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int numWords(string fname); // Initializing Num Words Function
void firstN(string fname, int n); // Initializing first100 Function

int main(){
  string fname = "HungerGames.txt";
  int len = numWords(fname); // Counts total number of words

  firstN(fname,100); //Writes first 100 words to a text file

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
  cout << "Length: " << len << endl;
  // Close file
  hgFile.close();
  return len;
}

void firstN(string fname, int n){
  string newFname;
  string temp;
  ifstream orig;
  ofstream shorter;
  orig.open(fname); // Opens Origional File
  newFname = "first" + to_string(n) + ".txt"; // Creates name based on len
  shorter.open(newFname); // Opens/ Creates Shorter File
  for(int i = 0; i<n;i++){
    orig >> temp;
    shorter << temp;
    shorter << " ";
  }
  shorter.close(); // Closes New Shorter File
  orig.close(); // Closes Origional File
}
