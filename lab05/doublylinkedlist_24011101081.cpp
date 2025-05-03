// Implementing a doubly linked list

#include <iostream>
using namespace std;

class list{

    private:
    struct node{
        int data;
        struct node *prev;
        struct node *next;
    }*head,*tail;

    public:
    list()
    {{head=NULL;
     tail=NULL;}};

    void insertbeginning(int);
    void insertend(int);
    void insertpos(int,int);
    int deletebeginning();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();

};

int main(){

    int choice=0;                       
    int stop=0;
    int num=0;
    int pos=0;
    int result=0;
    int target=0;
    list l1;

    while(stop==0){
        cout << "The Menu\n"
             << "1. Insert Beginning\n"
             << "2. Insert end\n"
             << "3. Insert at position\n"
             << "4. Delete beginning\n"
             << "5. Delete end\n"
             << "6. Delete at position\n"
             << "7. Search\n"
             << "8. Display\n"
             << "9. Exit\n";

        cout << "Enter user choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            cout << "Enter the element: ";
            cin >> num;
            l1.insertbeginning(num);
            cout << endl;
            break;

            case 2:
            cout << "Enter the element: ";
            cin >> num;
            l1.insertend(num);
            cout << endl;
            break;

            case 3:
            cout << "Enter the element: ";
            cin >> num;
            cout << "Enter the position (position starts from 1): ";
            cin >> pos;
            l1.insertpos(num,pos);
            cout << endl;
            break;

            case 4:
            result=l1.deletebeginning();
            if (result!=-1){
                cout << result << " has been deleted" << endl;
            }
            else{
                cout << "Empty list!" << endl;
            }
            cout << endl;
            break;

            case 5:
            result=l1.deleteend();
            if (result!=-1){
                cout << result << " has been deleted" << endl;
            }
            else{
                cout << "Empty list!" << endl;
            }
            cout << endl;
            break;

            case 6:
            cout << "Enter the position (position starts from 1): ";
            cin >> pos;
            result=l1.deletepos(pos);
            if (result==-1){
                cout << "Empty list!" << endl;

            }
            else if (result==0){
                cout << "Invalid position!" << endl;

            }
            else{
                cout << result << " has been deleted from position " <<  pos << endl;
            }
            cout << endl;
            break;

            case 7:
            cout << "Enter the target element: ";
            cin >> target;
            result=l1.search(target);
            if (result==0){
                cout << "Empty list!" << endl;
            }
            else if (result==-1){
                cout << "Element has not been found in the linked list" << endl;
            }
            else{
                cout << "The element is at position " << result << endl;
            }
            cout << endl;
            break;

            case 8:
            l1.display();
            cout << endl;
            break;

            case 9:
            stop=1;
            cout << "You have exited the program!" << endl;
            break;

            default:
            cout << "Invalid choice try again!" << endl;
            cout << endl;
            break;
        }
    }
}

//This function inserts the element at the beginning of the linked list
void list::insertbeginning(int num){

    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->prev=NULL;
    newnode->next=head;

    if (head==NULL){
        head=newnode;
        tail=newnode;
        cout << "Element has been inserted!" << endl;
        return;
    }

    head->prev=newnode;
    head=newnode;
    cout << "Element has been inserted!" << endl;
    return;
}

//This function inserts the element at the end of the linked list
void list::insertend(int num){

    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->prev=tail;
    newnode->next=NULL;

    if (head==NULL){
        head=newnode;
        tail=newnode;
        cout << "Element has been inserted!" << endl;
        return;
    }
    tail->next=newnode;
    tail=newnode;
    cout << "Element has been inserted!" << endl;
    return;

}

//This function inserts the element at a given position
void list::insertpos(int num,int pos){

    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    struct node *temp=head;
    int count=0;

    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if (pos<1 || pos>count+1){
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos==1){
        insertbeginning(num);
        return;
    }
    if (pos==count+1){
        insertend(num);
        return;
    }

    int c=1;
    temp=head;
    while(temp!=NULL && c<pos-1){
        temp=temp->next;
        c++;
    }
    newnode->next=temp->next;
    newnode->prev=temp->next->prev;
    temp->next->prev=newnode;
    temp->next=newnode;
    cout << "Element has been inserted!" << endl;
    return;
}

//This function deletes an element from the beginning
int list::deletebeginning(){

    if (head==NULL){
        return -1;
    }
    int dlt=0;
    if (head->next==NULL){
        dlt=head->data;
        free(head);
        head=NULL;
        tail=NULL;
        return dlt;
    }

    struct node *temp=head;
    dlt=temp->data;
    temp->next->prev=NULL;
    head=temp->next;
    free(temp);
    return dlt;
}

//This function deletes an element from the end
int list::deleteend(){

    if (head==NULL){
        return -1;
    }
    int dlt=0;
    if (head->next==NULL){
        dlt=head->data;
        free(head);
        head=NULL;
        tail=NULL;
        return dlt;
    }

    struct node *temp=tail;
    dlt=tail->data;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
    return dlt;
}

// This function deletes an element from the given position
int list::deletepos(int pos){

    if (head==NULL){
        return -1;
    }
    struct node *temp=head;
    int count=0;
    int dlt=0;

    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if (pos<1 || pos>count){
        return 0;
    }
    if (pos==1){
        dlt=deletebeginning();
        return dlt;
    }
    if (pos==count){
        dlt=deleteend();
        return dlt;
    }
    int c=1;
    temp=head;
    while(temp!=NULL && c<pos-1){
        temp=temp->next;
        c++;
    }

    struct node *temp2=temp->next;
    dlt=temp2->data;
    temp->next=temp2->next;
    temp2->next->prev=temp2->prev;
    free(temp2);
    return dlt;

}

// This function searches the linked list for a given element
int list::search(int target){

    if (head==NULL){
        return 0;
    }

    struct node *temp=head;
    int count=0;

    while(temp!=NULL){
        count++;
        if (temp->data==target){
            return count;
        }
        temp=temp->next;
    }
    return -1;
}

// This function displays the elements of the doubly linked list in both forward and backward directions
void list::display(){

    if (head==NULL){
        cout << "It is an empty list!" << endl;
        return;
    }
    struct node *temp=head;
    struct node *temp2=tail;

    cout << "The elements of the doubly linked list in forward direction: ";
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
    cout << "The elements of the doubly linked list in backward direction: ";
    while(temp2!=NULL){
        cout << temp2->data << " ";
        temp2=temp2->prev;
    }
    cout << endl;
    return;
}