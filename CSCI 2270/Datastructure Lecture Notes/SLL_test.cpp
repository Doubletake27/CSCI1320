#include <iostream>
using namespace std;

#include "SLL.h"

int main(){
  //Create an instance of SLL
  SLL l;

  // Define a test string array
  string arr[]={"jeden","dwa","trzy"};
  int arrLen = 3;

  // Test the appendNode function
  for(int i = 0; i< arrLen; i++){
    l.appendNode(arr[i]);
  }
  l.displayList();

  Node *tmp = l.search("dwa");
  cout << "node found " << tmp -> key << endl;

  l.~SLL();
  l.displayList();
}
