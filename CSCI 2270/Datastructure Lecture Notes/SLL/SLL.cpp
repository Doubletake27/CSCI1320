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
  Node *returnNode = nullptr;
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

void SLL::insert(string afterMe, string newValue){
  if(afterMe==""){
    // Assume that if afterMe is an empty string, the node is to be made head
    Node *temp = new Node;
    temp-> key = newValue;
    temp-> next = head;
    head = temp;
    temp = nullptr;
  }else{
    Node *last = search(afterMe);
    if(last==nullptr){
      cout << "node not found, new node not inserted" << endl;
    }else if(last->next == nullptr){
      appendNode(newValue);
    }else{ // last is somehwere in the middle
      Node *temp = new Node;
      temp-> key = newValue;
      temp -> next = last ->next;
      last -> next = temp;
      temp = nullptr; // Same as temp = NULL; // Same as temp = 0;
    }
  }
}

void SLL::deleteNode(string sKey){
  Node *tmp;
  if(head -> key == sKey){
    // IF at the head
    tmp = head;
    head = tmp -> next;
    delete tmp;
    tmp = nullptr;
  }else{
    bool found = false;
    Node *last = head;
    tmp = head-> next;
    while(!found && tmp!=nullptr){
      if(tmp->key == sKey){
        found = true;
      }else{
        last = tmp;
        tmp = tmp->next;
      }
    }
    if(found){
      if(tmp-> next == nullptr){
        // If deleting tail
        last -> next = nullptr;
        tail = last -> next;
      }else{
        // If in the middle
        last -> next = tmp-> next;
      }
      delete tmp;
      tmp = nullptr;
      last = nullptr;
    }
  }
}
