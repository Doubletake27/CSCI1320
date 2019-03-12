// Movie Tree 2 CPP
#include <iostream>
#include <string>
using namespace std;

#include "MovieTree.hpp"

// Helper Functions
// --PRINTING--
void printLinkedList(TreeNode *root);
void recurPrint(TreeNode *root){
// --ADDING MOVIE--
LLMovieNode *addMovieNode(LLMovieNode * root, int ranking, std::string title, int year, float rating);
// --DELETING MOVIE--

MovieTree::MovieTree(){
  root = nullptr;
}

MovieTree::~MovieTree(){
  root = nullptr;
}

/// --PRINTING-- ///
void MovieTree::printMovieInventory(){
  if(root!=nullptr){
    recurPrint(root);
  }
}
// Printing Helper Functions:
// In order Tree Traversal
void recurPrint(TreeNode *root){
  if(root -> leftChild != nullptr){
    recurPrint(root->leftChild);
  }
  if(root!=nullptr){
    cout << "Movies starting with letter: " << root->titleChar << endl;
    printLinkedList(root->head);
  }
  if(root-> rightChild != nullptr){
    recurPrint(root->rightChild);
  }
}
// Linked List Traversal
void printLinkedList(LLMovieNode *m){
  while(m != nullptr){
    cout << " >> " << m->title << " " << m->rating << endl;
    m = m->next;
  }
}

/// --ADDING MOVIE-- ///
void MovieTree::addMovie(int ranking, std::string title, int year, float rating){
  char l = title[0]; // pulls first letter
  if(root!=nullptr){
    TreeNode * prev = nullptr;
    // Traverse BST looking for first letter
    TreeNode * temp = root;
    bool found = false;
    while((temp!=nullptr)&&(!found)){
    // while((temp!=nullptr)&& (l != temp -> titleChar)){
      prev = temp;
      if(l == temp->titleChar){
        found = true;
      }else{
        if(l < temp->titleChar){
          temp = temp->leftChild;
        }else{
          temp = temp ->rightChild;
        }
      }
    }
    // If node already exists
    if(found){
      temp -> head = addMovieNode(temp->head, ranking, title, year, rating);
    }else{ // Else Create new Node
      TreeNode * n = new TreeNode;
      n-> parent = nullptr;
      n-> leftChild = nullptr;
      n-> rightChild = nullptr;
      n-> titleChar = l;
      n-> head = addMovieNode(nullptr, ranking, title, year, rating);
      if(prev == nullptr){//empty tree
        root = n;
      }else{
        if(n->titleChar < prev->titleChar){
          prev->leftChild = n;
          n-> parent = prev;
        }else{
          prev -> rightChild = n;
          n->parent = prev;
        }
      }
    }
  }else{// create root
    root = new TreeNode;
    root-> parent = nullptr;
    root-> leftChild = nullptr;
    root-> rightChild = nullptr;
    root-> titleChar = l;
    root-> head = addMovieNode(nullptr, ranking, title, year, rating);
  }
}


// Insert into linkedlist in order
LLMovieNode *addMovieNode(LLMovieNode * root, int ranking, std::string title, int year, float rating){
  // Create new movie node
  LLMovieNode * n = new LLMovieNode;
  n->ranking = ranking;
  n->title = title;
  n->year = year;
  n->rating = rating;
  n->next = nullptr;
  // If list empty
      // create list
  // else
      // in order insertion
      // update root if necessary
  if(root!=nullptr){
    LLMovieNode * temp = root;
    LLMovieNode * prev = nullptr;
    while((temp!=nullptr) && (temp-> title < n-> title)){
      prev = temp;
      temp = temp->next;
    }
    if(temp==root){
      root = n;
      n-> next = temp;
    }else{
      prev-> next = n;
      if(temp != nullptr){
        n-> next = temp;
      }
    }

  }else{ // List empty
    root = n;
  }

  return root;
}

/// --DELETING MOVIE-- ///
void MovieTree::deleteMovie(std::string title){

}
