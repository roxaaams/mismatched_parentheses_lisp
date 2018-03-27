#ifndef BRACKET_H_
#define BRACKET_H_

class Bracket {
  private:
    int position;
    Bracket* next;

  public:
    Bracket();
    Bracket(int position);
    Bracket(int position, Bracket* next);
    Bracket* getNext();
    void setNext(Bracket* next);
    int getPosition();
};

#endif
