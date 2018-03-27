#include "bracket.h"

Bracket::Bracket() : position(), next() {}

Bracket::Bracket(int position) : position(position) {}

Bracket::Bracket(int position, Bracket* next) : position(position), next(next) {}

int Bracket::getPosition() {
    return position;
}

Bracket* Bracket::getNext() {
    return next;
}

void Bracket::setNext(Bracket* next) {
    this->next = next;
}
