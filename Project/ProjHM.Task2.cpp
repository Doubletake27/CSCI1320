// Henry Meyerson
// 109190761
// CSCI 1320 - 112
// Project

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int numWords(string fname); // Initializing Num Words Function
void txt2array(string arr[],string fname, int len); // Initializing text to array function
bool unique(string word, string cw[],int len);
void clean(string fname, string cw[], int len);

int main(){
  string fname = "HungerGames.txt";
  string iw = "IgnoreWords.txt";
  int n = numWords(iw); //Determines length of the array of words to ignore
  string ign[n]; // PreAllocates Array of words to ignore

  txt2array(ign,iw,n); // Fills Array with words to ignore

  clean(fname,ign,n);

  return 0;
}

void clean(string fname, string cw[], int len){
  bool uni;
  string word;
  string temp;
  ifstream orig;
  ofstream clean;
  orig.open(fname); // Opens Origional File
  clean.open("cleanedText.txt"); // Opens/ Creates Clean File

  while(!orig.eof()){
    orig >> word;
    if(unique(word,cw,len)){
      clean << word;
      clean << " ";
    }
  }

  clean.close(); // Closes New Shorter File
  orig.close(); // Closes Origional File
}

bool unique(string word, string cw[],int len){
  bool a = 1; // is unique
  for(int i = 0; i < len; i++){
    if(word == cw[i]){
      a = 0; // not unique;
    }
  }
  return a;
}

void txt2array(string arr[],string fname, int len){
  ifstream ignore;
  ignore.open(fname);
  for(int i = 0;i<len;i++){
    ignore >> arr[i];
  }
  ignore.close();
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
