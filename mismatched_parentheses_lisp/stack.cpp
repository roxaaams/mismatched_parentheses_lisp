#include "stack.h"

Stack::Stack(): brackets() {}

Stack::bool empty() const {
    return brackets.empty();
}

Stack::int size() const {
    return brackets.size();
}

Stack::void push() {
    brackets.push_back('(');
}

Stack::void pop() {
    if (empty())
        throw UnderflowException();

    brackets.pop_back();
}
