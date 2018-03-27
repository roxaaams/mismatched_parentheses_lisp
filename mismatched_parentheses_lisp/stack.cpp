#include "bracket.h"
#include "stack.h"

Stack::Stack(): sizeStack(0), head(), tail() {}

bool Stack::empty(){
    return head == nullptr;
}

int Stack::size() {
    return sizeStack;
}

void Stack::push(const int& position) {
   if (position < 0)
      throw "Negative position of parenthesis. Cannot push.";

    if (tail == nullptr) {
        head = tail = new Bracket(position);
    } else {
        tail->setNext(new Bracket(position));
        tail = tail->getNext();
    }

    sizeStack++;
}

int Stack::top() {
    if (empty())
        throw "Empty stack. Cannot get top.";

    return tail->getPosition();
}

void Stack::pop() {
    if (empty())
        throw "Empty stack. Cannot pop out.";

    if (head == tail) {
        head = tail = nullptr;
    } else if (head->getNext() == tail) {
        head->setNext(nullptr);
        tail = head;
    } else {
        Bracket* temp = head;
        while (temp->getNext() !=  tail) {
            temp = temp->getNext();
            if (temp->getNext() == tail) {
                temp->setNext(nullptr);
                tail = temp;
                delete temp;
            }
        }
    }

    sizeStack--;
}
