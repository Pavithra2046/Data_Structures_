// StackLinkedList.h
#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

#include <iostream>
using namespace std;

class StackLinkedList {
    private:
    struct node {
        int data;
        struct node *next;
    } *top;

    public:
    StackLinkedList() {
        top = NULL;
    }

    void push(int);
    int pop();
    int peek();
};

// Function to push an element in the stack.
void StackLinkedList::push(int value) {
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
int StackLinkedList::pop() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    int popped = top->data; 
    struct node *temp = top;
    top = top->next;
    free(temp); 
    return popped;
}

// Function to check the top element in the stack.
int StackLinkedList::peek() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return top->data;
}

#endif // STACKLINKEDLIST_H
