#include <iostream>
using namespace std;

#include "binaryST.h"

int main(){
	BinaryST bst0;

	bst0.insert( 9 );
	bst0.insert( 10 );
	bst0.insert( 2 );
	bst0.insert( 10 );
	bst0.insert( 7 );
	bst0.insert( 0 );

/*
        9
       /  \
      2   10
     / \    \
    0   7   10
*/

	cout << "display in-order: " << endl;
	bst0.disp("in-order");

	Node *sNode = bst0.search(7);
	if(sNode != nullptr){
		cout << "sKey: " << sNode -> key << endl;
	}

	return 0;
}
