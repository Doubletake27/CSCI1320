// Priority Queue Functions
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "PriorityQueue.hpp"

// Helper Functions
void swap(GroupNode *a, GroupNode *b){ // Helper for repairUpward
  GroupNode temp = *a;
  *a = *b;
  *b = temp;
}

int parent(int index)
{
  return (index-1)/2;
}

// Public
PriorityQueue::PriorityQueue(int queueSize){
  maxQueueSize = queueSize();
  currentQueueSize = 0;
  priorityQueue = new GroupNode[queueSize];
}

PriorityQueue::~PriorityQueue(){
  for(int i = 0; i )
}

void PriorityQueue::enqueue (std::string _groupName, int _groupSize, int _cookingTime){
  if(currentQueueSize!=maxQueueSize){

    priorityQueue[currentQueueSize].groupName = _groupName;
    priorityQueue[currentQueueSize].groupSize = _groupSize;
    priorityQueue[currentQueueSize].cookingTime = _cookingTime;
    repairUpward(currentQueueSize);
    currentQueueSize++;

  }else{
    // some form of error
    cout << "Heap full, cannot enqueue" << endl;
  }

}

void PriorityQueue::dequeue(){

}

GroupNode PriorityQueue::peek(){
  return priorityQueue[0];
}

bool PriorityQueue::isFull(){
  if(maxQueueSize==currentSize){
    return true;
  }else{
    return false;
  }
}

bool PriorityQueue::isEmpty(){
  if(priorityQueue[0]==nullptr){
    return true;
  }else{
    return false;
  }
}

// Private Functions
// void PriorityQueue::repairUpward(int nodeIndex){
//   while(nodeIndex != 0 && ((priorityQueue[parent(nodeIndex)].groupSize < priorityQueue[nodeIndex].groupSize)||((priorityQueue[parent(nodeIndex)].groupSize == priorityQueue[nodeIndex].groupSize)&&(priorityQueue[parent(nodeIndex)].cookingTime > priorityQueue[nodeIndex].cookingTime)))){
//        swap(&priorityQueue[nodeIndex], &priorityQueue[parent(nodeIndex)]);
//        nodeIndex = parent(nodeIndex);
//     }
// }

void PriorityQueue::repairUpward(int nodeIndex){
    while (nodeIndex != 0 && priorityQueue[(nodeIndex-1)/2].groupSize > priorityQueue[nodeIndex].groupSize){
        swap(&priorityQueue[nodeIndex], &priorityQueue[(nodeIndex-1)/2]);
        nodeIndex = (nodeIndex-1)/2;
    }
    if(nodeIndex != 0 && priorityQueue[(nodeIndex-1)/2].groupSize == priorityQueue[nodeIndex].groupSize && priorityQueue[(nodeIndex-1)/2].cookingTime > priorityQueue[nodeIndex].cookingTime){
        swap(&priorityQueue[nodeIndex], &priorityQueue[(nodeIndex-1)/2]);
        nodeIndex = (nodeIndex-1)/2;
    }
}

void PriorityQueue::repairDownward(int nodeIndex){

}
