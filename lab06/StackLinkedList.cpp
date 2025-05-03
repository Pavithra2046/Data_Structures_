//Program to implement stack ADT using linked list

#include<iostream>
using namespace std;

class StackLinkedList{
    private:
    struct node{
        int data;
        struct node *next;
    }*top;
    public:
    StackLinkedList(){
        top = NULL;
    }

    void push(int);
    int pop();
    int peek();
};

int main(void){
    StackLinkedList stack;
    int choice;
    int value;
    while(1){
        
        cout<<"Menu: "<<endl;
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Peek"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter the character: ";
            cin>>value;
            stack.push(value);
        }
        if(choice == 2){
            stack.pop();
        }
        if(choice == 3){
            stack.peek();
        }
        if(choice==4){
            cout<<"Code Exit."<<endl;
            break;
        }

    }

}

//Function to push an element in the stack.
void StackLinkedList::push(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        cout<<"Memory allocation failed"<<endl;
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;

}

//Function to pop the element in the stack.
int StackLinkedList::pop() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    int popped = top->data; 
    struct node *temp = top;
    top = top->next;
    free(temp); 
    cout << "Popped element: " << popped << endl;
    return popped;
}

//Function to check the top element in the stack.
int StackLinkedList::peek(){
    if(top==NULL){
        cout<<"Stack is empty."<<endl;
        return -1;
    }
    cout<<"Top element: "<< top->data<<endl;

    return top->data;
}