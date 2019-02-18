#include <iostream>
#include <string>
#include "RPNCalculator.hpp"

using namespace std;

RPNCalculator::RPNCalculator(){
  stackHead = nullptr;
}

RPNCalculator::~RPNCalculator(){
  while(!isEmpty()){
    Operand *temp = stackHead -> next;
    pop();
    stackHead = temp;
  }
  stackHead = nullptr;
}

bool RPNCalculator::isEmpty(){
  if(stackHead==nullptr){
    return true;
  }else{
    return false;
  }
}

void RPNCalculator::push(float number){
  Operand *temp = new Operand;
  temp -> next = stackHead;
  temp -> number = number;
  stackHead = temp;
}

void RPNCalculator::pop(){
  if(isEmpty()){
    cout << "Stack empty, cannot pop an item." << endl;
  }else{
    Operand * temp = stackHead-> next;
    delete stackHead;
    stackHead = temp;
  }
}

Operand* RPNCalculator::peek(){
  if(isEmpty()){
    cout << "Stack empty, cannot peek." << endl;
    return nullptr;
  }else{
    return stackHead;
  }
}

bool RPNCalculator::compute(std::string symbol){
  if(symbol == "+"){
    if(!isEmpty()){
      float a = peek() -> number;
      pop();
      if(!isEmpty()){
        Operand* b = peek();
        b -> number = b -> number + a;
      }else{
        push(a);
        cout << "err: not enough operands" << endl;
        return false;
      }

    }else{
      cout << "err: not enough operands" << endl;
      return false;
    }
  }else{
    if(symbol == "*"){
      if(!isEmpty()){
        float a = peek() -> number;
        pop();
        if(!isEmpty()){
          Operand* b = peek();
          b -> number = b -> number * a;
        }else{
          push(a);
          cout << "err: not enough operands" << endl;
          return false;
        }

      }else{
        cout << "err: not enough operands" << endl;
        return false;
      }
    }else{
      cout << "err: invalid operation" << endl;
      return false;
    }
  }

}
