#include "Heap.hpp"
#include <iostream>
// #include <limits.h>
using namespace std;


void swap(int *a, int *b) //HELPER
{
  int* temp = a;
  a = b;
  b = temp;
}

int Heap::leftChild(int nodeIndex){ //returns the index of the left Child
  return ((2*nodeIndex)+1);
}

int Heap::rightChild(int nodeIndex){// returns the index of the right Child.
  return ((2*nodeIndex)+2);
}
int Heap::parent(int nodeIndex){ //Returns the index of the parent.
  return ((nodeIndex-1)/2);
}

Heap::Heap(int size){
  heapSize = size;
  currentSize = 0;
  heap = new int[heapSize];
}

Heap::~Heap(){
  delete[] heap;
}


void Heap::printHeap()
{
    //cout<<heap[0]<<endl;
  int i = 0;
  while(i < currentSize)
  {
    cout<<heap[i]<<" ";
    i ++;
  }
  cout<<endl;
}


void Heap:: addToHeap (int value){
    //cout<<"adding: "<<value<<endl;
  int capacity = heapSize;

  if(currentSize == capacity)
  {
    cout<<"Maximum heap size reached. Cannot insert anymore"<<endl;
    return;
  }

  currentSize = currentSize + 1;
  int index = currentSize - 1;
  heap[index] = value;
  //cout<<"added: "<<heap[currentSize-2]<<endl;
  //cout<<currentSize<<endl;
  repairUpward(index);
  //repairDownward(0);
  //printHeap();
}

int Heap::removeFromHeap(){
    int save = heap[0];
    swap(heap[0],heap[--currentSize]);
    repairDownward(0);
    return save;
}

int Heap::peekValue(){
  if(currentSize != 0)
    return heap[0];
  else
    return 0;
}

/*void Heap::repairDownward(int nodeIndex){ ////FOR A MAX HEAP - might need to change slightly.
  int l = leftChild(nodeIndex);
  int r = rightChild(nodeIndex);
  int smallest = nodeIndex;

  if(l < currentSize && heap[l] <heap[nodeIndex])
  smallest = l;
  if(r < currentSize && heap[r]<heap[smallest])
  smallest = r;

  if(smallest !=nodeIndex){
    swap(heap[nodeIndex],heap[smallest]);
    repairDownward(smallest);

  }
}*/

void Heap::repairUpward(int nodeIndex){
    if(heap[nodeIndex]<heap[parent(nodeIndex)]){
        swap(heap[nodeIndex], heap[parent(nodeIndex)]);
        repairUpward(parent(nodeIndex));
    }
    //else{cout<<"moved: "<<heap[nodeIndex]<<endl;}
}

void Heap::repairDownward(int nodeIndex){//FOR A MIN HEAP
    int left = leftChild(nodeIndex); //left child
    int right = rightChild(nodeIndex); //right child
    int smallest = nodeIndex;

    if(left < currentSize && heap[left] < heap[nodeIndex] )
        smallest = left;
    if(right < currentSize && heap[right] < heap[smallest] )
        smallest = right;
    if(smallest != nodeIndex )
    {
    swap (heap[nodeIndex] , heap[smallest]); //include & if of other data type.
    repairDownward (smallest);
    }
}
