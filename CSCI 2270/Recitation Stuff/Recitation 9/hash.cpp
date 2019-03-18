// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    //TODO: Search the list at that specific index and return the node if found
    node * temp = table[index];
    while(temp != nullptr && temp-> key != key){
      temp = temp -> next;
    }
    if(temp!= nullptr && temp -> key == key){
      return temp;
    }else{
      return nullptr;
    }
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key){
  // cout << key << " ";
  node * n = createNode(key, nullptr);
  // n-> key = key;
  // n-> next = nullptr;
  int index = hashFunction(key);

    if(searchItem(key)!=nullptr){
        table[index] = n;
     }else{
      n -> next = table[index];
      table[index] = n;
      if(n -> next != nullptr)
        cout<<"duplicate entry: "<<key<<endl;
      return false;
    }

}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        node * temp = table[i];
        while(temp != nullptr){
          cout << temp-> key << " ";
          temp = temp-> next;
        }
        cout << endl;
    }

 }
