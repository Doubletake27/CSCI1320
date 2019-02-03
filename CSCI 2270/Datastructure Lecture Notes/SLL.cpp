// Sll.cpp
#include <iostream>
using namespace std;

# include "SLL.h"

SLL::SLL(){
  head = nullptr;
  tail = nullptr;
}
SLL::~SLL(){
  Node *tmp, *current = head;
  while(current != nullptr){
    tmp = current->next;
    delete current;
    current = tmp;
  }
  head = nullptr;
  tail = nullptr;
}

void SLL::appendNode(string newItem){
  if(head ==nullptr){
    head = new Node;
    head -> key = newItem;
    head -> next = nullptr;
    tail = head;
  }else{
    Node *temp = new Node;
    temp -> key = newItem;
    tail -> next = temp;
    tail = temp;
    tail -> next = nullptr;
  }
}

void SLL::displayList(){
  Node *current = head;
  int count = 0;
  cout << "Display entire linked list: " << endl;
  while(current !=nullptr){
    cout << "node " << count++ << " " << current ->key << endl;
    current = current -> next;
   }
}

Node *SLL::search(string sKey){
  Node  *returnNode = nullptr;
  Node *tmp = head;

  bool found = false;

  while(!found && tmp!=nullptr){
    if(tmp ->key ==sKey){
      found = true;
      returnNode = tmp;
    }else{
      tmp = tmp->next;
    }
  }
  return returnNode;
}
