#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#include "stack.h"

const std::string fileName = "text.lisp";

int numberBrackets;
Stack bracketsStack;
bool foundClosedBracket;

std::string getFileString() {
    std::ifstream fin(fileName);
    return std::string((std::istreambuf_iterator<char>(fin)),
                  (std::istreambuf_iterator<char>()));
}

void print() {
    if (numberBrackets < 1) {
        std::cout << "No parentheses in the lisp program." << "\n";
    } else if (!foundClosedBracket && bracketsStack.empty()) {
            std::cout << "OK. Balanced parentheses" << "\n";
    } else if (!bracketsStack.empty()) {
            std::cout << "\nClose " << bracketsStack.size() << " parentheses. \n";
    }
}

void solve() {
    try {
        std::string file = getFileString();
        int length = (int) file.length();
        for (int i = 0; i < length; ++i) {
            char ch = file[i];
            if (ch == '(') {
                bracketsStack.push(i);
                ++numberBrackets;
            } else if (ch == ')') {
                if (bracketsStack.empty()) {
                     if (!foundClosedBracket) {
                        foundClosedBracket = true;
                        std::cout << "First mismatched closed parenthesis on position: " << i << "\n";
                     }
                } else {
                    bracketsStack.pop();
                }
                ++numberBrackets;
            }
        }

    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }
}

int main() {
    solve();
    print();
    return 0;
}
