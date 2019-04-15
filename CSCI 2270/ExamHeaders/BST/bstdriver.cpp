#include <iostream>
#include "BST.hpp"
using namespace std;

int main (int argc, char* argv[]){
  cout<<"Creating tree"<<endl;

  int min = 8;
  int max = 12;

  BST tree(9);

  tree.addNode(7);
  tree.addNode(16);
  tree.addNode(4);
  tree.addNode(8);
  tree.addNode(11);

  cout << "The Sum of the values between " << min << " and " << max << " is: " << tree.sumRange(min,max) << endl << endl;


  cout<<"----------------The Tree Is ---------------"<<endl<<endl;
  tree.print2DUtil(1);

  // cout<<"----------------Inorder traversal of the tree is ---------------"<<endl<<endl;
  // tree.printTree();

}
