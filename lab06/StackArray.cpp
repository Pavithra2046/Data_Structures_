//Program to implement stack ADT using an array.

#include<iostream>
using namespace std;

#define SIZE 5

class StackArray{
    private:
    char arr[SIZE];
    int top;

    public:
    StackArray(){
        top = -1;
    }

    void push(char);
    int pop();
    int peek();

};

int main(void){
    StackArray Stack;
    int choice;
    while(1){
        cout<<"Menu: "<<endl;
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Peek"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice == 1){
            char value;
            cout<<"Enter the character: ";
            cin>>value;
            cout<<endl;
            Stack.push(value);
        }
        if(choice == 2){
            Stack.pop();
        }
        if(choice == 3){
            Stack.peek();
        }
        if(choice == 4){
            cout<<"Code Exit."<<endl;
            break;
        }

    }
}

//Function to push a value in the stack
void StackArray::push(char value){
    if(top >=SIZE-1){
        cout<<"Stack overflow."<<endl;
        return;
    }
    arr[++top]=value;
}

//Function to pop a value in the stack
int StackArray::pop(){
    if(top<0){
        cout<<"Stack underflow."<<endl;
        return 0;
    }
    char poppedvalue = arr[top];
    top--;
    return poppedvalue;
    

}

//Function to check the top element in stack
int StackArray::peek(){
    if(top<0){
        cout<<"Stack is empty."<<endl;
        return 0;
    }
    return arr[top];
}