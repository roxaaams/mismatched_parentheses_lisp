#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#include "stack.h"

std::string getFileString(){
    std::ifstream fin("text.lisp");
    return std::string((std::istreambuf_iterator<char>(fin)),
                  (std::istreambuf_iterator<char>()));
}

int main() {
    try {
        std::string file = getFileString();

        Stack bracketsStack;
        std::map<int, int> bracketPairs;

        bool foundClosedBracket;
        int length = file.length();
        for (size_t i = 0; i < length; ++i) {
            char ch = file[i];
            if (ch == '(') {
                bracketsStack.push(i);
            } else if (ch == ')') {
                if (bracketsStack.empty()) {
                     bracketPairs[i] = -1;
                     if (!foundClosedBracket) {
                        foundClosedBracket = true;
                        std::cout << "First mismatched closed parenthesis on position: " << bp.first << "\n";
                     }
                } else {
                    bracketPairs[bracketsStack.top()] = index;
                    bracketPairs[index] = bracketsStack.top();
                    bracketsStack.pop();
                }
            }
        }


        if (!bracketsStack.empty()) {
            std::cout << "Close " << bracketsStack.size() << "parentheses \n";
            return 0;
        }

        std::cout << "OK" << "\n";
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}
