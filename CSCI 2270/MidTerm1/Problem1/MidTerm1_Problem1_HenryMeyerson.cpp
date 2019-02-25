// Henry Meyerson
// Midterm 1, problem 1
#include <iostream>
#include <cmath>
using namespace std;

struct Node{
	int key;
	Node *next;
};

class LinkedList{
  private:
    Node *head, *tail;
  public:
    LinkedList();
    ~LinkedList();
    void append(int newInt);
    void displayList();
    Node* getStackHead() { return head; }
};

int sumEvens(Node *head); // Sum Evens Function

int main(){
  LinkedList test;
  int len = 0;
  int inp = 0;
  int repeat = 0;

  cout << "Number of Test Cases: ";
  cin >> repeat;

  for(int j = 0; j<repeat; j++){
    cout << "---------------" << endl;
    cout << "Case " << j+1 << endl;
    cout << "Number of Values: ";
    cin >> len;
    if(len>=0){

      for(int i = 0; i < len; i++){
        cout << "Value " << i+1 << ": ";
        cin >> inp;
        test.append(inp);
      }

      test.displayList();
      cout << "Even Sum = "<< sumEvens(test.getStackHead()) << endl;
    }else{
      cout << "Number of values must be greater than or equal to 0" << endl;
    }
    test.~LinkedList();
  }


  // int values[] = {7,4,6,2,0,3,9,2};
  // len = 8;
  // for(int i = 0; i < len; i++){
  //   test.append(values[i]);
  // }
  // cout << "Even Sum = "<< sumEvens(test.getStackHead()) << endl;



  return 0;
}

int sumEvens(Node *head){
  Node *temp = head;
  int sum = 0;
  while(temp!= nullptr){
      if(temp->key%2 == 0){
        sum+=temp->key;
      }
      temp = temp -> next;
  }
  return sum;
}


LinkedList::LinkedList(){
  head = nullptr;
  tail = nullptr;
}

LinkedList::~LinkedList(){
  Node *tmp, *current = head;
  while(current != nullptr){
    tmp = current->next;
    delete current;
    current = tmp;
  }
  head = nullptr;
  tail = nullptr;
}

void LinkedList::append(int newInt){
  if(head ==nullptr){
    head = new Node;
    head -> key = newInt;
    head -> next = nullptr;
    tail = head;
  }else{
    Node *temp = new Node;
    temp -> key = newInt;
    tail -> next = temp;
    tail = temp;
    tail -> next = nullptr;
  }
}

void LinkedList::displayList(){
  Node *current = head;
  cout << endl << "Linked List: " << endl;
  if(current!= nullptr){
    while(current !=nullptr){
      cout << current ->key << " -> ";
      current = current -> next;
     }
     cout << "Null" << endl << endl;
  }else{
    cout << "empty " << endl << endl;
  }
}
