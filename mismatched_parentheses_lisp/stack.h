#ifndef STACK_H_
#define STACK_H_

#include "bracket.h"

class Stack {
  private:
    int sizeStack;
    Bracket* head;
    Bracket* tail;

  public:
    Stack();
    bool empty();
    int size();
    int top();
    void push(const int& position);
    void pop();
};

#endif
