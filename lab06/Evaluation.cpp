//Program to evaluate the infix postfix expression.

#include "StackLinkedList.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int precedence(char);
string infixToPostfix(string);
int evaluatePostfix(string);

int main() {
    string infix, postfix;
    int choice;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Get Infix\n";
        cout << "2. Convert Infix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter a valid infix expression: ";
                getline(cin, infix);
                break;
            case 2:
                if (infix.empty()) {
                    cout << "No infix expression entered.\n";
                } else {
                    postfix = infixToPostfix(infix);
                    cout << "Postfix expression: " << postfix << endl;
                }
                break;
            case 3:
                if (postfix.empty()) {
                    cout << "No postfix expression available for evaluation.\n";
                } else {
                    cout << "Result: " << evaluatePostfix(postfix) << endl;
                }
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

//Function to check the precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '=') return 0;
    return -1;
}

//Function to convert infix to postfix.
string infixToPostfix(string infix) {
    StackLinkedList stack;
    string postfix = "";
    int i = 0;

    while (i < infix.length()) {
        if (isdigit(infix[i])) {  
            while (i < infix.length() && isdigit(infix[i])) {
                postfix += infix[i];
                i++;
            }
            postfix += " ";  
            continue; 
        } 
        
        else if (infix[i] == '(') {
            stack.push(infix[i]);
        } 
        
        else if (infix[i] == ')') {
            while (stack.peek() != '(' && stack.peek() != -1) {
                postfix += stack.pop();
                postfix += " "; 
            }
            stack.pop(); 
        } 
        
        else {  
            while (stack.peek() != -1 && precedence(stack.peek()) >= precedence(infix[i])) {
                postfix += stack.pop();
                postfix += " ";
            }
            stack.push(infix[i]);
        }
        i++;
    }

    while (stack.peek() != -1) {
        postfix += stack.pop();
        postfix += " ";
    }

    return postfix;
}

//Function to evaluate postfix.
int evaluatePostfix(string postfix) {
    StackLinkedList stack;
    cout << "Evaluating Postfix: " << postfix << endl;

    int i = 0;
    while (i < postfix.length()) {
        if (isdigit(postfix[i])) {  
            int num = 0;
            while (i < postfix.length() && isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            stack.push(num);
            cout << "Pushed: " << num << endl;
        } 
        
        else if (postfix[i] == ' ') { 
            i++;
            continue;
        } 
        
        else {  
            int val2 = stack.pop();
            int val1 = stack.pop();
            cout << "Popped: " << val1 << " and " << val2 << " for operation " << postfix[i] << endl;

            switch (postfix[i]) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        cout << "Error: Division by zero." << endl;
                        return -1;
                    }
                    stack.push(val1 / val2);
                    break;
                default:
                    cout << "Invalid operator detected!" << endl;
            }
        }
        i++;  
    }
    return stack.pop();
}


