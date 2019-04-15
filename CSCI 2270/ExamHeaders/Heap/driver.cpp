#include "Heap.hpp"
#include <iostream>
using namespace std;

int main()
{
  Heap heap(10);
  heap.addToHeap(9);
  heap.addToHeap(13);
  heap.addToHeap(10);
  heap.addToHeap(14);
  heap.addToHeap(7);
  heap.addToHeap(5);
  heap.addToHeap(11);
  heap.addToHeap(8);

  cout<<"***********Elements in the heap are **********"<<endl;
  heap.printHeap();
  cout<<endl;
  int peek = 0;
  peek = heap.removeFromHeap();
    cout<<"***********Elements after deletion **********"<<endl;
  heap.printHeap();

  // cout << "Smallest element extracted is: "<<heap.extractMin() <<endl<<endl;
  // cout<<"***********Elements in the heap after extracting the smallest element**********"<<endl;
  // heap.print();
  // cout<<endl;

  // int key = 15;
  // cout << "Deleting a key from the heap: "<<endl<<endl;
  // heap.deleteKey(key);
  // cout<<"***********Elements in the heap after deleting the key**********"<<endl;
  // heap.print();

  cout<<endl;
  return 0;
}
