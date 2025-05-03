#ifndef BALANCEDPARENTHESES_H
#define BALANCEDPARENTHESES_H

#include <iostream>
#include <string>
#include "StackLinkedList.h"

using namespace std;

// Function to check if a string of parentheses is balanced
inline bool isBalanced(string expr) {
    StackLinkedList stack;

    for (char ch : expr) {
        if (ch == '(') {
            stack.push(int(ch));
        } 
        else if (ch == ')') {
            if (stack.pop() == -1) { 
                return false;
            }
        }
    }
    
    return stack.peek() == -1;
}

#endif // BALANCEDPARENTHESES_H
