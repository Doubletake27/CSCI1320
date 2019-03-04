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
	return searchRecur(root,value);
}

Node* BinaryST::searchRecur( Node *n , int searchKey )
{
	if(n!= nullptr){
		cout << "Node Visited: " << n-> key << endl;
		if(n->key == searchKey){
			return n;
		}else{
			if(n->key > searchKey){
				return searchRecur(n->leftChild,searchKey);
			}else{
				return searchRecur(n->rightChild,searchKey);
			}
		}
	}else{
		return nullptr;
	}
}

Node* BinaryST::findMin()
{
	return getMin( root );
}

Node* BinaryST::getMin( Node *n )
{
	//Iterate down to left most node
	while(n-> leftChild!=nullptr){
		n = n-> leftChild;
	}
	return nullptr;
}


void BinaryST::deleteNode( int value )
{
	Node *n = search(value);
	// Non-Root Case
	if(n!=root){
		// I) The Leaf Case (N is a leaf Node)
		if(n->leftChild== nullptr && rightChild == nullptr){
			// Need to go up to the parent node and update the correct child prointer
			// Check n's relationship to its parents
			// is n the lefft child?
			if(n==n-> parent -> leftChild){
				n-> parent ->leftChild = nullptr;
			}else{
				n-> parent -> rightChild = nullptr;
			}
		}else{ // II) The 2-children case
			if(n-> leftChild != nullptr && n-> rightChild!=nullptr){
				// Find the min of the right sub-tree to replace the deleted node
				Node *min = getMin(n-> rightChild);
				// if min IS the right Child of n
				if(min == n-> rightChild){
					// make parent point ot the min
					// check if node is left child
					if(n== n-> parent -> leftChild){
						n-> parent -> leftChild = min;
					}else{ // otherwise it is the right child
						n-> parent -> rightChild = min;
					}
					// Make min point to the parent
					min -> parent = n-> parent;
					// make min point to n's old child
					min -> leftChild = n-> leftChild;
					// make old LC point to min
					min -> leftChild -> parent = min;
				}else{ // otherwise, min is not the RC of n, meaning it's somewhere in the right subtree
					// min's old right child takes min's spot
					min-> parent -> leftChild = min-> rightChild;
					// new node needs to point back up to min's former parent
					if(min-> rightChild !=nullptr){
						min-> rightChild -> parent = min->parent;
					}
					if(n==n-> parent -> leftChild){
						n-> parent-> leftChild = min;
					}else{
						n-> parent -> rightChild = min;
					}

					min-> parent = n-> parent;
					min-> leftChild = n-> leftChild;
					min-> leftChild -> parent = min;
					min-> rightChild=n -> rightChild;
					min-> rightChild-> parent = min;
				}

			}else{ // III) The one child case
				// 1) the one child is a left child
				if(n->leftChild != nullptr){
					n-> leftChild -> parent = n-> parent;
					if(n==n-> parent->leftChild){
						n-> parent -> leftChild = n -> leftChild;
					}else{
						n-> parent -> rightChild = n-> leftChild;
					}
				}else{ // child is right child
					n->rightChild -> parent  = n-> parent;
					// check if node is left child
					if(n==n-> parent->leftChild){
						n-> parent -> leftChild = n -> rightChild;
					}else{
						n-> parent -> rightChild = n-> rightChild;
					}
				}

			}
		}
	}else{ // The Root Case

	}

}
