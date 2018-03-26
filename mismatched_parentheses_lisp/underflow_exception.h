#ifndef UNDERFLOW_EXCEPTION_H_INCLUDED
#define UNDERFLOW_EXCEPTION_H_INCLUDED

class UnderflowException : public std::exception {
  public:
    const char* what() const throw() {
        return "Underflow error";
    }
};

#endif

