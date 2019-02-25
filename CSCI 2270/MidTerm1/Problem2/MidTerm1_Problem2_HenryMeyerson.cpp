// Henry Meyerson
// Midterm 1, problem 2
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
    Node* getStackHead() { return head; }
};

void print(Node *listHead);

int main(){
  LinkedList main;
	LinkedList odd;
	LinkedList even;
  int len = 0;
  int inp = 0;
  int repeat = 0;
	Node *temp = nullptr;

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
				main.append(inp);
      }
			// Split
			temp = main.getStackHead();
			while(temp != nullptr){
				if(temp-> key%2 == 0){
					even.append(temp->key);
				}else{
					if(temp-> key%1 == 0){
						odd.append(temp->key);
					}
				}
				temp = temp-> next;
			}

			cout << "Initial List: " << endl;
			print(main.getStackHead());
			cout << "Even List: " << endl;
			print(even.getStackHead());
			cout << "Odd List: " << endl;
			print(odd.getStackHead());

    }else{
      cout << "Number of values must be greater than or equal to 0" << endl;
    }
    main.~LinkedList();
		even.~LinkedList();
		odd.~LinkedList();
  }


  return 0;
}

void print(Node *listHead){
  Node *current = listHead;
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

LinkedList::LinkedList(){
  head = nullptr;
  tail = nullptr;
}

LinkedList::~LinkedList(){
	// Deletes Original Linked List
  Node *tmp, *current = head;
  while(current != nullptr){
    tmp = current->next;
    delete current;
    current = tmp;
  }
  head = nullptr;
  tail = nullptr;
}
