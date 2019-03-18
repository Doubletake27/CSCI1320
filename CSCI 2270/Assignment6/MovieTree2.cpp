// Movie Tree 2 CPP
#include <iostream>
#include <string>
using namespace std;

#include "MovieTree.hpp"

// Helper Functions
// --PRINTING--
void printLinkedList(LLMovieNode *root);
void recurPrint(TreeNode *root);
// --ADDING MOVIE--
LLMovieNode *addMovieNode(LLMovieNode * root, int ranking, std::string title, int year, float rating);
// --DELETING MOVIE--
TreeNode *getMin(TreeNode*n);
TreeNode *delTreeNode(TreeNode * currNode, char title);
LLMovieNode *delMovieNode(LLMovieNode *root, std::string title);
TreeNode* searchRecur(TreeNode *n, char title);
TreeNode* searchTree(TreeNode * root, std::string title);
// --Destructor --
void destructTree(TreeNode * m);
void destructLL(LLMovieNode * head);


MovieTree::MovieTree(){
  root = nullptr;
}

/// -- Destructor --
MovieTree::~MovieTree(){
  destructTree(root);
}

void destructTree(TreeNode * m){
  if(m!=nullptr){
    destructTree(m->leftChild);
    destructTree(m->rightChild);
    destructLL(m->head);
    delete m;
    m=nullptr;
  }
}

void destructLL(LLMovieNode * head){
  LLMovieNode *tmp, *current = head;
  while(current != nullptr){
    tmp = current->next;
    delete current;
    current = tmp;
  }
  head = nullptr;
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
  // Locate Tree Node
  TreeNode * n = searchTree(root,title);
  if(n == nullptr){ // Check if exists
    cout << "Movie: " << title << " not found, cannot delete." << endl;
  }else{
    if(n -> head -> next != nullptr){   // Determine if there is more than one value in linked list
      n -> head = delMovieNode(n->head,title);
    }else{  // Else delete node in linked list, then delete tree node
      delete n->head; // Deletes the solitary node in linked list
      //Delete node from tree
      root = delTreeNode(root,title[0]);
    }
  }
  n = nullptr;
}

TreeNode *getMin(TreeNode*n){
	//Iterate down to left most node
	while(n-> leftChild!=nullptr){
		n = n-> leftChild;
	}
	return n;
}

TreeNode *delTreeNode(TreeNode * currNode, char title){

    if(currNode == nullptr)
    {
      return nullptr;
    }
    else if(title < currNode->titleChar)
    {
      currNode->leftChild = delTreeNode(currNode->leftChild, title);
    }
    else if(title > currNode->titleChar)
    {
      currNode->rightChild = delTreeNode(currNode->rightChild, title);
    }
    // We found the node with the value
    else
    {
      // No child
      if(currNode->leftChild == nullptr && currNode->rightChild == nullptr)
      {
        delete currNode;
        currNode = nullptr;
      }
      // Only right child
      else if(currNode->leftChild == nullptr)
      {
        TreeNode * temp = currNode;
        temp = temp-> rightChild;
        delete currNode;
        currNode = temp;
      }
      // Only left child
      else if(currNode->rightChild == nullptr)
      {
        TreeNode * temp = currNode;
        temp = temp-> leftChild;
        delete currNode;
        currNode = temp;
      }
      // Both left and Right child
      else
      {
        ///Replace with Minimum from right subtree
        TreeNode * min = getMin(currNode-> rightChild);
        currNode -> titleChar = min -> titleChar;
        delTreeNode(currNode->rightChild,min->titleChar);
      }

    }
  return currNode;
}

// Delete Movie Node
LLMovieNode *delMovieNode(LLMovieNode *root, std::string title){
  LLMovieNode * temp = root;
  if(root->title==title){
    root = root -> next;
    delete temp;
  }else{
    LLMovieNode * prev = nullptr;
    while(title != temp -> title){
      prev = temp;
      temp = temp-> next;
    }
    prev -> next = temp -> next;
    delete temp;
    temp = nullptr;
  }
  return root;
}

// Searching Tree For Letter Node
TreeNode* searchTree(TreeNode * root, std::string title){
	return searchRecur(root, title[0]);
}

TreeNode* searchRecur( TreeNode *n , char title){
  char searchKey = title;
	if(n!= nullptr){
		if(n->titleChar == searchKey){
			return n;
		}else{
			if(n->titleChar > searchKey){
				return searchRecur(n->leftChild,searchKey);
			}else{
				return searchRecur(n->rightChild,searchKey);
			}
		}
	}else{
		return nullptr;
	}
}
