// Merging list
#include <iostream>
using namespace std;

class list {

    private:
    struct node {
        int data;
        struct node *next;
    }*head;

    struct node* gethead(){
        return head;
    }

    public:
    list()
    {{head=NULL;}};

    void insertasc(int);
    void mergelist(list&, list&, list&);
    void display();
};

// inserting the elements into the list in ascending order
void list::insertasc(int num){

    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;

    if (head==NULL || num<head->data){
        newnode->next=head;
        head=newnode;
        return;
    }

    struct node *temp=head;
    while (temp->next!=NULL && num > temp->next->data){
        temp=temp->next;
    }

    newnode->next=temp->next;
    temp->next=newnode;
    return; 

}

// merging the list in ascending order
void list::mergelist(list& l1, list& l2, list& l3){

    struct node *temp1=l1.gethead();
    struct node *temp2=l2.gethead();

    while(temp1!=NULL){
        l3.insertasc(temp1->data);
        temp1=temp1->next;
    }

    while(temp2!=NULL){
        l3.insertasc(temp2->data);
        temp2=temp2->next;
    }
}

// display the list
void list::display(){

    struct node *temp=head;
    while (temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}