// StackLinkedList.h
#include <iostream>
using namespace std;

class stack {
    private:
    struct node {
        char data;
        struct node *next;
    } *top;

    public:
    stack() {
        top = NULL;
    }

    void push(char);
    char pop();
    char peek();
    void display();
    void recursive(struct node*);
};

// Function to push an element in the stack.
void stack::push(char value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        cout << "Memory allocation failed" << endl;
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

// Function to pop the element in the stack.
char stack::pop() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return '\0';
    }
    char popped = top->data; 
    struct node *temp = top;
    top = top->next;
    free(temp); 
    return popped;
}

// Function to check the top element in the stack.
char stack::peek() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return '\0';
    }
    return top->data;
}

// Function to implement recursion in stack
void stack::recursive(node *temp) {
    if (temp == nullptr){
        return;
    }
    
    recursive(temp->next); 
    cout << temp->data;
}

// This function displays the stack in reverse (start to end)
void stack::display(){

    recursive(top);
    return;

}

