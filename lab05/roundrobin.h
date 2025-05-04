#include <iostream>
using namespace std;

class roundrobinschedule {
private:
    int fixedtime;

    struct node {
        int time;
        struct node* next;
    } *head;

public:
    roundrobinschedule() {
        head = NULL;
    }

    void settime(int);
    void insertend(int);
    void execute();
};

// the function sets a fixed time for each task
void roundrobinschedule::settime(int time) {
    fixedtime = time;
}

// the function inserts a task at the end
void roundrobinschedule::insertend(int num) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->time = num;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        cout << "Insertion successful" << endl;
        return;
    }

    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;

    cout << "Insertion successful" << endl;
}

// the function executes a task
void roundrobinschedule::execute() {
    if (head == NULL) {
        cout << "No processes to execute.\n";
        return;
    }

    struct node* temp = head;
    cout << "Executing process with time " << temp->time << endl;
    temp->time -= fixedtime;

    if (temp->time <= 0) {
        cout << "Process completed.\n";
        if (temp->next == head) {
            free(temp);
            head = NULL;
        } else {
            struct node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            free(temp);
        }
    } else {
        cout << "Process not completed, remaining time: " << temp->time << "\n";
        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = temp;
        temp->next = head;
    }
}
