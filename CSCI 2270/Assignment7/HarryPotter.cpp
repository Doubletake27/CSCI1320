// Harry Potter Hash Table Functions
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "HashTable.hpp"

void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable);
bool isStopWord(std::string word, HashTable &stopWordsTable);

// Public Member Functions
HashTable::HashTable(int hashTableSize){
  cout << "constructor called " << endl;
  numCollisions = 0;
  numItems = 0;
  // hashTableSize = hashTableSize;
  // *hashTable = nullptr;
  wordItem arrayTemp = new wordItem[hashTableSize];
  *hashTable = arrayTemp;
  // for(int i = 0; i<hashTableSize;i++){
  //   hashTable[i] = nullptr;
  // }
  cout << "built" << endl;
}

HashTable::~HashTable(){
  wordItem * temp;
  wordItem * prev;
  for(int i = 0; i < hashTableSize; i++){
    temp = hashTable[i];
    while(temp!=nullptr){
      prev = temp;
      temp = temp->next;
      delete prev;
    }
  }
}

void HashTable::addWord(std::string word){
  // Generates new WordItem Node
  cout << "Adding: " << word << endl;
  wordItem * n = new wordItem;
  n -> word = word;
  n -> count = 1;
  n -> next = nullptr;

  //insertion
  unsigned int index = getHash(word);
  cout << "got Hash" << endl;
  wordItem * temp = searchTable(word);
  cout << "found" << endl;
  if(temp==nullptr){
    n->next = hashTable[index];
    hashTable[index] = n;
    numItems++;
    if(n->next != nullptr){
      numCollisions++;
    }
  }else{
    temp -> count++;
  }
}


bool HashTable::isInTable(std::string word){
  cout <<" searching" << endl;
  wordItem * temp = searchTable(word);

  if(temp==nullptr){
    return false;
  }else{
    return true;
  }
}

void HashTable::incrementCount(std::string word){
  searchTable(word) -> count++;
}

void HashTable::printTopN(int n){
  int totalNumberofWords = getTotalNumWords();
  wordItem * top[n]; // 0 is highest, n-1 is lowest
  wordItem * temp = nullptr;

  for(int i =0; i <n; i++){
    top[i] = new wordItem;
    top[i] -> count = 0;
  }

  // Locating Top N
  int bigPos;
  for(int i = 0; i<hashTableSize; i++){ // Loop through Hash Table

    // loop Throught Linked List
    temp = hashTable[i];
    while(temp!=nullptr){
      bigPos = 0;
      for(int j = 0; j < n; j++){
        if(temp-> count > top[j]-> count){
          bigPos = j;
        }else{
          break;
        }
      }
      if(bigPos!=0){
        // delete top[0];
        for(int k = 0; k<bigPos; k++){
          top[k] = top[k+1];
        }
        top[bigPos] = temp;
      }
      temp = temp -> next;
    }
  }

  // Printing Top N
  wordItem * w;
  for(int i = 0;i<n;i++){
    w = top[n-i-1];
    cout << (float)w->count/totalNumberofWords << " - " << w->word << endl;
    // cout << setprecision(4) << fixed << (float)w->count/totalNumberofWords << " - " << w->word << endl;
  }
}

int HashTable::getNumCollisions(){
  return numCollisions;
}

int HashTable::getNumItems(){
  return numItems;
}

int HashTable::getTotalNumWords(){
  wordItem * temp = nullptr;
  int count = 0;
  for(int i = 0;i<hashTableSize;i++){
    temp = hashTable[i];
    while(temp != nullptr){
      count += temp-> count;
      temp = temp->next;
    }
  }
  return count;
}

// Private Member Functions
unsigned int HashTable::getHash(std::string word){
  unsigned int hashValue = 5381;
  int length = word.length();
  for(int i = 0; i< length; i++){
    hashValue = ((hashValue<<5)+hashValue) + word[i];
  }
  hashValue = hashValue % hashTableSize;

  return hashValue;
}

wordItem* HashTable::searchTable(std::string word){
  //Compute the index by using the hash function
  unsigned int indy = getHash(word);
  int index = indy;
  cout << hashTableSize << " > " << index << endl;
  cout << "got hash in search" << endl;
  if(index > hashTableSize){
    cout << "Z index iz t2 beeg" << endl;
  }else{
    cout << "Shh calm down" << endl;
  }
  cout << hashTable[index] << "ptr "<< endl;
  wordItem * temp = hashTable[index];
  cout << "found index in search" << endl;
  while(temp != nullptr && temp-> word != word){
    temp = temp -> next;
  }
  if(temp!= nullptr && temp -> word == word){
    return temp;
  }else{
    return nullptr;
  }
}

// Additional Helper Functions
void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable){
  cout << "getting stop words" << endl;
  ifstream stop;
  stop.open(ignoreWordFileName);

  string word;
  while(!stop.eof()){
    getline(stop,word,'\n');
    cout << word << endl;
    stopWordsTable.addWord(word);
  }
  stop.close();
  cout << "Get Got" << endl;
}

bool isStopWord(std::string word, HashTable &stopWordsTable){
  if(stopWordsTable.isInTable(word)){
    return true;
  }else{
    return false;
  }
}
