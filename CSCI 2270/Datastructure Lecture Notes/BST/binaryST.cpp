#include <iostream>
using namespace std;

#include "binaryST.h"

BinaryST::BinaryST()
{
	root = nullptr;
}

// Insert new node
void BinaryST::insert( int newValue )
{
	// create a pointer to keep track of previous Node
	Node *prev = nullptr;

	// pointer for traversing the tree. Start with Root
	Node * temp = root;

	// create new Node
	Node *n = new Node;
	// Set n
	n-> parent = nullptr;
	n-> leftChild = nullptr;
	n-> rightChild = nullptr;
	n-> key = newValue;

	while(temp!= nullptr){
		prev = temp; // tracks last Node
		// chech which way to go
		if(n-> key < temp -> key){
			temp = temp-> leftChild;
		}else{ // if n-> key is greater than or equal to
			temp = temp -> rightChild;
		}
	}
	// At this point parent has been found
	if(prev == nullptr){ // Empty tree
		root = n;
	}else if(n -> key < prev -> key){
		prev -> leftChild = n;
		n -> parent = prev;
	}else{
		prev -> rightChild = n;
		n-> parent = prev;
	}

}

void BinaryST::disp( string Order )
{
	if(Order == "pre-order"){
		dispPreOrd(root);
	}else if(Order == "in-order"){
		dispInOrd(root);
	}

}

void BinaryST::dispPreOrd( Node *n )
{

}

void BinaryST::dispInOrd( Node *n )
{
	if(n->leftChild != nullptr){
		dispInOrd(n->leftChild);
	}

	cout << n-> key << endl;

	if(n->rightChild != nullptr){
		dispInOrd(n->rightChild);
	}

}

Node* BinaryST::search( int value )
{
	return nullptr;
}

Node* BinaryST::searchRecur( Node *n , int searchKey )
{
	return nullptr;
}

Node* BinaryST::findMin()
{
	return getMin( root );
}

Node* BinaryST::getMin( Node *n )
{
	return nullptr;

}


void BinaryST::deleteNode( int value )
{

}
