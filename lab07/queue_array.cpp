// Implementing queue ADT with an integer array of size 5

#include <iostream>
using namespace std;

class queue{

    private:
    int arr[5];
    int front;
    int rear;

    public:
    queue(){
        front=-1;
        rear=-1;
    }

    void enqueue(int);
    int dequeue();
    int peek();

};

int main(){

    int choice;
    int stop=0;
    int data;
    int result;

    queue q;

    while(stop==0){
        cout << "The Menu\n" 
             << "1. Enqueue\n"
             << "2. Dequeue\n"
             << "3. Peek\n"
             << "4. Exit\n";
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

            case 1:
            cout << "Enter number: ";
            cin >> data;
            q.enqueue(data);
            cout << endl;
            break;

            case 2:
            result=q.dequeue();
            if (result==-1){
                cout << "Empty queue!" << endl;
            }
            else{

                cout << result << " has been dequeued" << endl;
            }
            cout << endl;
            break;

            case 3:
            result=q.peek();
            if (result==-1){
                cout << "Empty queue!" << endl;
            }
            else{

                cout << result << " is on the top" << endl;
            }
            cout << endl;
            break;

            case 4:
            stop=1;
            cout << "Exiting program!" << endl;
            break;
        }
    }

    return 0;
}

// This function adds an element to the start of the queue
void queue::enqueue(int data){

    if (rear==4){
        cout << "Queue is full!" << endl;
        return;
    }

    if (front==-1){
        front=0;
    }
    arr[++rear]=data;
    return;

}

// This function removes an element from the beginning of the queue
int queue::dequeue(){

    if (front==-1 || front > rear){
        return -1;
    }
    
    int dlt = arr[front];
    front++;

    if (front>rear){
        front=-1;
        rear=-1;
    }
    return dlt;
}

// This function returns the top character of the queue
int queue::peek(){

    if (front==-1 || front > rear){
        return -1;
    }
    return arr[front];
}
