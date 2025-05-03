// Implementing Queue ADT using singly linked list

#include <iostream>
using namespace std;

class queue{

    private:
    struct node {
        int data;
        struct node *next;
    }*head;

    public:
    queue(){
        head=NULL;
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


void queue::enqueue(int data){

    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;

    if (head==NULL){
        head=newnode;
        newnode->next=NULL;
        return;
    }

    struct node *temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return;
}

int queue::dequeue(){

    if (head==NULL){
        return -1;
    }
    struct node *temp=head;
    head=temp->next;
    int dlt = temp->data;
    free(temp);
    temp=NULL;
    return dlt;
}

int queue::peek(){

    if (head==NULL){
        return -1;
    }
    return head->data;
}
