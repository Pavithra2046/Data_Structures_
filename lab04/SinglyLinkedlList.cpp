// Implementing LIST ADT using singly linked list

#include <iostream>
using namespace std;

class list {

    private:
    struct node {
        int data;                       
        struct node *next;              
    }*head;

    public:

    list()
    {{head=NULL;}};
    
    int cur=0;
    void insertbeginning(int);          
    void insertend(int);                
    void insertpos(int, int);       
    int deletebeginning();                  
    int deleteend(); 
    int deletepos(int);
    int search(int);                       
    void display();
    void recursive(struct node*);
    void displayreverse();
    void reverse();
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
             << "9. Display reverse\n"
             << "10. Reverse the linked list\n"
             << "11. Exit\n";

        cout << "Enter user choice: ";
        cin >> choice;

        switch(choice){

            case 1:
            cout << "Enter the element to be inserted at the beginning: ";
            cin >> num;
            l1.insertbeginning(num);
            break;

            case 2:
            cout << "Enter the element to be inserted at the end: ";
            cin >> num;
            l1.insertend(num);
            break;

            case 3:
            cout << "Enter the element to be inserted at the end: ";
            cin >> num;
            cout << "Enter the position (position starts from 1): ";
            cin >> pos;
            l1.insertpos(num,pos);
            break;

            case 4:
            result=l1.deletebeginning();
            if (result!=0){
                cout << "The element " << result << " has been removed from the beginning" << endl;
            }
            else{
                cout << "It is an empty list!" << endl;
            }
            break;

            case 5:
            result=l1.deleteend();
            if (result!=0){
                cout << "The element " << result << " has been removed from the end!" << endl;
            }
            else{
                cout << "It is an empty list!" << endl;
            }
            break;

            case 6:
            cout << "Enter the position (position starts from 1): ";
            cin >> pos;
            result=l1.deletepos(pos);
            if (result!=0){
                cout << "The element " << result << " has been removed from position " << pos << endl;
            }
            else{
                cout << "Invalid position!" << endl;
            }
            break;

            case 7:
            cout << "Enter the target element: ";
            cin >> target;
            result=l1.search(target);
            if (result==-1){
                cout << "The element is not there in the list" << endl;
            }
            else if (result == 0){
                cout << "It is an empty list!" << endl;
            }
            else{
                cout << "The element has been found in position " << result << endl;
            }
            break;

            case 8:
            l1.display();
            break;

            case 9:
            cout << "The elements in reverse are: ";
            l1.displayreverse();
            cout << endl;
            break;

            case 10:
            l1.reverse();
            break;

            case 11:
            stop=1;
            cout << "You have exited the program! " << endl;
            break;

            default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    return 0;
}


// this function inserts the element at the beginning of the linked list
void list::insertbeginning(int num){

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next=head;
    head=newnode;
    cout << "The element " << num << " has been inserted at the beginning!" << endl;
    cur++;
    return;

}


// this function inserts the element at the end of the linked list
void list::insertend(int num){

    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    if (head==NULL){
        insertbeginning(num);
        return;
    }

    struct node *temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    cur++;
    cout << "The element " << num << " has been inserted at the end!" << endl;
    return;

}

 
// this function inserts the element at a given position
void list::insertpos(int num, int pos){

    if (pos<1){
        cout << "Invalid position!" << endl;
        return;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *temp=head;
    newnode->data=num;
    newnode->next=NULL;

    if (pos==1){
        insertbeginning(num);
        return;
    }

    int count=1;
    while (temp->next!=NULL && count<pos-1){
        temp=temp->next;
        count++;
    }
    if (temp==NULL){
        cout << "Invalid position!" << endl;
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    cur++;
    cout << "The element " << num << " has been inserted at position " << pos << endl;
    return;
}


// this function deletes the first element of the linked list
int list::deletebeginning(){

    if (head==NULL){
        return 0; 
    }
    struct node *temp=head;
    head=temp->next;
    int dlt = temp->data;
    free(temp);
    temp=NULL;
    cur--;
    return dlt;
}


// this function deletes the last element of the linked list
int list::deleteend(){

    if (head==NULL){
        return 0;
    }

    int dlt;
    struct node *temp=head;

    if (head->next==NULL){
        dlt = head->data;
        free(head);
        head=NULL;
        cur--;
        return dlt;
    }
    while (temp->next->next!=NULL){
        temp=temp->next;
    }
    dlt = temp->next->data;
    free(temp->next);
    temp->next=NULL;
    cur--;
    return dlt;

}


// this function deletes the element from a particular position
int list::deletepos(int pos){

    if (pos<1){
        cout << "Invalid position!" << endl;
        return 0;
    }
    int dlt;
    struct node *temp=head;
    if (pos==1){
        dlt = deletebeginning();
        return dlt; 
    }

    int count=1;

    while (temp->next!=NULL && count<pos-1){
        temp=temp->next;
        count++;
    }
    if (temp==NULL || temp->next==NULL){
        return 0;
    }
    struct node *todelete = temp->next;
    temp->next=todelete->next;
    dlt = todelete->data;
    cur--;
    free(todelete);
    return dlt;
}

//searches for an element and returns its position
int list::search(int target){
    
    if (head==NULL){
        cout << "The list is empty!" << endl;
        return 0;
    }

    struct node *temp = head;
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

// displays the elements of the linked list
void list::display(){

    struct node *temp=head;
    if (head==NULL){
        cout << "The list is empty!" << endl;
        return;
    }
    cout << "The elements of the list are: ";
    while(temp){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
    return;
    
}
void list::recursive(node *temp) {
    if (temp == nullptr)
    
    recursive(temp->next); 
    cout << temp->data << " "; 
}

// This function displays the list in reversed form
void list::displayreverse(){

    recursive(head);
    return;

}

// reversing the linked list

void list::reverse(){

    struct node *prev=NULL;
    struct node *next=NULL;
    while(head!=NULL){
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    head=prev;
    cout << "Your list has been successfully reversed! Enter 8 to display" << endl;
}
