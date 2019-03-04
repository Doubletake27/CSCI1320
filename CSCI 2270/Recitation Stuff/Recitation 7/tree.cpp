#include <iostream>
#include "tree.hpp"
using namespace std;
#define COUNT 10


/*
Constructor for a Tree object
*/
Tree::Tree()
{
  this->root = NULL;
}

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void Tree::print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

void Tree::preOrderTraverse(Node *node)
{
  if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    preOrderTraverse(node->left);

    /* now recur on right subtree */
    preOrderTraverse(node->right);
}


/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Implement this function
            This function deletes all the nodes in the tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
void Tree::deleteTree(Node *node)
{
    if (node == NULL) return;

    /*TODO first delete both subtrees */
    if(node->left !=nullptr){
      deleteTree(node-> left);
    }
    Node *temp = node->right;
    cout<<"\n Deleting node:"<< node->data;
    delete node;


    if(temp != nullptr){
      deleteTree(temp);
    }

    /* TODO then delete the node */
}

/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Implement this function
          This function gives the sum of all the nodes in the tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
int Tree::sumNodes(Node *node)
{
  int sum = 0;
//TODO Base case
// if (node == NULL) return;

/*TODO first delete both subtrees */
if(node->left !=nullptr){
  sum = sum + sumNodes(node-> left);
}

  sum = sum + node-> data;

if(node->right != nullptr){
  sum = sum + sumNodes(node->right);
}
//TODO Implement Sum of all nodes

  return sum;
}

/*
 Creates a tree of 7 elements
 */
void Tree::createTree()
{
  Node *root         = new Node(1);
  root->left         = new Node(2);
  root->right        = new Node(3);
  root->left->left   = new Node(4);
  root->left->right  = new Node(5);
  root->right->left  = new Node(6);
  root->right->right = new Node(7);
  this->root = root;
}
