// Harry Potter Hash Table Driver
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "HashTable.hpp"


int main(int argc, char *argv[]){
  // Command Line Arguments
  const int N = stoi(argv[1]); // Top N to print
  string fname = argv[2]; // File Name
  char * igName = argv[3]; // Ignore Words File Name
  const int L = stoi(argv[4]); // Length of HP Hash Table

  HashTable hphash(L);
  HashTable ig(50);

  string word;

  if(argv[4] == NULL){  // If wrong number of command line Arguments
    cout << "Usage: <number of words> <input filename.txt> <ignoreWordsfilename.txt> <hash table size>" << endl;
  }else{
    getStopWords(igName,ig); // Gets Stop Words

    ifstream hp;
    hp.open(fname);
    while(!hp.eof()){
      getline(hp,word,' ');
      if(!isStopWord(word,ig)){
        if(hphash.isInTable(word)){
          hphash.incrementCount(word);
        }else{
          hphash.addWord(word);
        }
      }
    }
    hphash.printTopN(N);
    cout << "#" << endl;
    cout << "Number of collisions: " << hphash.getNumCollisions() << endl;
    cout << "#" << endl;
    cout << "Unique non-stop words: " << hphash.getNumItems() << endl;
    cout << "#" << endl;
    cout << "Total non-stop words: " << hphash.getTotalNumWords() << endl;
  }


  return 0;
}
