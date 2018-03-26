#ifndef STACK_H_
#define STACK_H_

#include <string>

#include "underflow_exception.h"

class Stack {
  private:
    std::string brackets;

  public:
    Stack();
    bool empty();
    int size();
    void push();
    void pop();
};

#endif
