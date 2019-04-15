//TA: Sharat Nimmagadda
#include <iostream>
#include "BST.hpp"
using namespace std;

// Exam HELPER functions
int sumRangeRecur(int min,int max,Node *n);
//

BST::BST()
{
  this->root = NULL;
}

BST::BST(int data)
{
    root = createNode(data);
    cout<< "New tree created with "<<data << " as the root."<<endl;
}

void destructHelp(Node *currNode){
    if(currNode!=NULL){
        destructHelp(currNode->left);
        destructHelp(currNode->right);
        delete currNode;
        currNode = NULL;
    }
}

BST::~BST(){
    destructHelp(root);
}


/// BEGINNING of EXAM function
int BST::sumRange(int min, int max){
  return sumRangeRecur(min,max,root);
}

int sumRangeRecur(int min,int max,Node *n){
  int sum = 0;
  if(n->left!=nullptr){
    sum += sumRangeRecur(min,max,n->left);
  }

  if((n->key >= min) && (n->key <= max)){
    sum += n-> key;
  }

  if(n->right!=nullptr){
    sum+=sumRangeRecur(min,max,n->right);
  }

  return sum;
}

/// END of EXAM function

Node* BST::createNode(int data){
  Node* newN = new Node;
  newN->key = data;
  newN->left = NULL;
  newN->right = NULL;
  return newN;
}

Node* BST::addNodeHelper(Node* currNode, int data){
    if(currNode == NULL)
        return createNode(data);
    else if(currNode->key < data)
        currNode->right = addNodeHelper(currNode->right,data);
    else if(currNode->key > data)
        currNode->left = addNodeHelper(currNode->left,data);
    return currNode;
}

Node* getMinValueNode(Node* newnode){ //HELPER FUNCTION
    while(newnode->left != NULL)
        newnode = newnode->left;
    return newnode;
}

Node* BST::deleteNodeHelper(Node *currNode, int value){
    if(currNode == NULL)
        return NULL;
    else if(value < currNode->key)
        currNode->left = deleteNodeHelper(currNode->left, value);
    else if(value > currNode->key)
        currNode->right = deleteNodeHelper(currNode->right, value);
    else{
        //cout<<"found "<<currNode->key<<endl;
        if(currNode->left == NULL && currNode->right == NULL){
            delete currNode;
            currNode = nullptr;
        }
        else if(currNode->left == NULL){
            Node* temp = currNode;
            currNode = currNode->right;
            delete temp;
            temp = nullptr;
        }
        else if(currNode->right == NULL){
            Node* temp = currNode;
            currNode = currNode->left;
            delete temp;
            temp = nullptr;
        }
        else{
            //cout<<"fuck"<<endl;
            Node* min =  getMinValueNode(currNode->right);
            //cout<<"found min: "<<min->key<<endl;
            currNode->key = min->key;
            currNode->right = deleteNodeHelper(currNode->right,min->key);
        }
    }
    return currNode;
}

Node* BST::searchKeyHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;
    else if(currNode->key == data)
        return currNode;
    else if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);
    else
        return searchKeyHelper (currNode->right, data);
}

void BST::printTreeHelper(Node* currNode){
    if(currNode){
        printTreeHelper(currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper(currNode->right);
    }
}

void BST::print2DUtilHelper(Node *currNode, int space){
    if (currNode == NULL)
        return;
    space += 10;
    print2DUtilHelper(currNode->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);
    print2DUtilHelper(currNode->left, space);
}

void BST::addNode(int data){
    addNodeHelper(root, data);
}

void BST::deleteNode(int data){
    deleteNodeHelper(root, data);
}

bool BST::searchKey(int data){
    Node* tree = searchKeyHelper(root, data);
    if(tree != NULL)
        return true;
    cout<<"Key not present in the tree"<<endl;
    return false;
}

void BST::printTree(){
  printTreeHelper(root);
  cout<<endl;
}

void BST::print2DUtil(int space){
    print2DUtilHelper(root, space);
}

void preOrderTraverse(Node *node){
  if (node == NULL)
        return;
    cout << node->key << " ";
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
}
