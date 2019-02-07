// Assignment 2
// CSCI 2270
// Henry Meyerson

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct wordItem{
  string word;
  int count;
};

void resize(wordItem **arrayPtr, int *capacity);
void getStopWords(string ignoreWordFileName, string ignoreWords[]);
bool isStopWord(string word, string ignoreWords[]);
int getTotalNumberNonStopWords(wordItem uniqueWords[],int length);
void arraySort(wordItem *uniqueWords, int length);
void printTopN(wordItem uniqueWords[], int topN, int totalNumWords);

int main(int argc, char *argv[]){
  // Command Line Arguments
  const int N = stoi(argv[1]);
  string fname = argv[2];
  string igName = argv[3];

  string ignoreWords[50];

  string word;
  int arrayLength = 100;
  wordItem *uniqueWords;
  uniqueWords = new wordItem[arrayLength];
  int length = 0; // Length of the used space in the unique words array
  int doubled = 0; // number of times doubled
  bool unique;

  if(argv[3] == NULL){  // If wrong number of command line Arguments
    cout << "Usage: Assignment2Solution <number of words> <input filename.txt> <ignoreWordsfilename.txt>" << endl;
  }else{ // Else Run the rest of the program
    getStopWords(igName,ignoreWords);

    ifstream hp;
    hp.open(fname);

    while(!hp.eof()){ // Loop through entire file
      unique = 1;
      getline(hp,word,' ');

      if(!isStopWord(word,ignoreWords)){

        for(int i = 0; i < length; i ++){
          if(word==uniqueWords[i].word){
            uniqueWords[i].count++;
            unique = 0;
            break;
          }
        }

        if(unique){
          if( length == arrayLength ){ // If too long -> Array Double
            resize(&uniqueWords, &arrayLength);
            doubled++;
          }
          // Creates new array entry
          // cout << length << " " << word << endl;
          uniqueWords[length].word = word;
          uniqueWords[length++].count = 1;
        }

      }
    }
    arraySort(uniqueWords,length);
    hp.close();
    cout << "Array doubled: " << doubled << endl;
    cout << "#" << endl;
    cout << "Unique non-common words: " << length << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << getTotalNumberNonStopWords(uniqueWords,length) << endl;
    cout << "#" << endl;
    cout << "Probabilities of top "<< N <<" most frequent words" << endl;
    cout << "---------------------------------------"<< endl;
    printTopN(uniqueWords,N,getTotalNumberNonStopWords(uniqueWords,length));
  }

  return 0;
}

void getStopWords(string ignoreWordFileName, string ignoreWords[]){
  ifstream stop;
  stop.open(ignoreWordFileName);

  int i = 0;
  while(!stop.eof()){
    getline(stop,ignoreWords[i++],'\n');
  }
  stop.close();
}

bool isStopWord(string word, string ignoreWords[]){
  bool stop = 0;
  for(int i = 0; i<50; i++){
    if(word == ignoreWords[i]){
      stop = 1;
      break;
    }
  }
  return stop;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[],int length){
  int total = 0;
  for(int i = 0; i<length; i++){
    total += uniqueWords[i].count;
  }
  return total;
}

void arraySort(wordItem *uniqueWords, int length){ //Bubble Sort
  wordItem temp; // Initializing a temporary variable
  for(int i = length-1; i>0; i--){
    for(int j = 0; j < i; j++){
      if(uniqueWords[j].count<uniqueWords[j+1].count){
        temp = uniqueWords[j];
        uniqueWords[j] = uniqueWords[j+1];
        uniqueWords[j+1] = temp;
      }
    }
  }
}

void printTopN(wordItem uniqueWords[], int topN, int totalNumWords){
  float prob;
  for(int i = 0; i < topN; i++){
    prob = (float)uniqueWords[i].count/totalNumWords;
    cout.precision(4);
    cout << fixed << prob << " - " << uniqueWords[i].word << endl;
  }
}

void resize(wordItem **arrayPtr, int *capacity)
{
	int newCapacity = *capacity * 2;
	wordItem *newArray = new wordItem[newCapacity];

	for(int i  = 0; i < *capacity; i++){
		newArray[i] = (*arrayPtr)[i];
	}

	delete [] *arrayPtr;

	*arrayPtr = newArray;
	*capacity = newCapacity;
}
