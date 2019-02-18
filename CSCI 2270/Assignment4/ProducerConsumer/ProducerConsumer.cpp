#include <iostream>
#include <string>
#include "ProducerConsumer.hpp"

using namespace std;

ProducerConsumer::ProducerConsumer(){
  queueFront = -1;
  queueEnd = -1;
}

bool ProducerConsumer::isEmpty(){
  if(queueEnd == -1){
    return true;
  }else{
    return false;
  }
}

bool ProducerConsumer::isFull(){
  if(queueFront == queueEnd + 1){
    return true;
  }else{
    if((queueEnd == SIZE-1 )&&(queueFront==0)){
      return true;
    }else{
      return false;
    }
  }
}

void ProducerConsumer::enqueue(string player){
  if(!isFull()){
    if(isEmpty()){
      queueFront = 0;
    }

    if(queueEnd!= SIZE -1){
      queueEnd ++;
    }else{
      queueEnd = 0;
    }
    queue[queueEnd] = player;
  }else{
    cout << "Queue full, cannot add new item" << endl;
  }
}

void ProducerConsumer::dequeue(){
  if(!isEmpty()){
    if(queueFront == queueEnd){
      queueFront = -1;
      queueEnd = -1;
    }else{
      // queue[queueFront] = "";
      if(queueFront != SIZE -1){
        queueFront++;
      }else{
        queueFront = 0;
      }
    }
  }else{
    cout << "Queue empty, cannot dequeue an item" << endl;
  }
}

int ProducerConsumer::queueSize(){
  if(!isEmpty()){
    if(queueEnd>=queueFront){
      return (queueEnd - queueFront + 1);
    }else{
      return (SIZE - queueFront + queueEnd +1);
    }
  }else{
    return 0;
  }
}

string ProducerConsumer::peek(){
  if(!isEmpty()){
    return queue[queueFront];
  }else{
    cout << "Queue empty, cannot peek" << endl;
    return "";
  }
}
