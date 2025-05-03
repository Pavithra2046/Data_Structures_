// Implementing ListADT using an array of size 5

#include <iostream>
using namespace std;

#define maxsize 5

class list {
private:
    int arr[maxsize];
    int cur; 

public:

    list(){
        cur=0;
    };
    int insertbeginning(int); 
    int insertend(int); 
    int insertpos(int, int);
    int deletebeginning(); 
    int deleteend();
    int deletepos(int); 
    int search(int); 
    void display(); 
    int rotate(int);

};


int main(){

    int choice,stop=0;
    list l1;
    int num,pos=0;
    int result;
    int target;
    int k;
    while(stop==0){

        cout << "The Menu\n1. Insert element in the beginning\n2. Insert element in the end\n3. Insert element in some position\n4. Delete element from the begining\n5. Delete element from the end\n6. Delete element from some position\n7. Search\n8. Display\n9. Rotate\n10. Exit" << endl;
        cout << "Enter the choice: ";
        cin>>choice;

        switch(choice){

            case 1:
            cout << "Enter the element to be inserted in the beginning: ";
            cin >> num;
            result=l1.insertbeginning(num);
            if (result==0){
                cout << "List is full cannot insert more elements!" << endl;
            }
            if (result==1){
                cout << "Element has been inserted at the beginning! Enter 8 to display" << endl;
            }
            break;

            case 2:
            cout << "Enter the element to be inserted in the end: ";
            cin >> num;
            result=l1.insertend(num);
            if (result==0){
                cout << "List is full cannot insert more elements!" << endl;
            }
            if (result==1){
                cout << "Element has been inserted at the end! Enter 8 to display" << endl;
            }
            break;

            case 3:
            cout << "Enter the element to be inserted in the end: ";
            cin >> num;
            cout << "Enter the position/index to be inserted at: ";
            cin >> pos;
            result=l1.insertpos(num,pos);
            if (result==0){
                cout << "List is full or invalid position! cannot insert more elements!" << endl;
            }
            if (result==1){
                cout << "Element has been inserted at " << pos << " index! Enter 8 to display" << endl;
            }
            break;

            case 4:
            result=l1.deletebeginning();
            if (result==0){
                cout << "List is empty can't delete elements" << endl;
            }
            else{
                cout << result << " has been deleted" << endl;
            }
            break;

            case 5:
            result=l1.deleteend();
            if (result==0){
                cout << "List is empty can't delete elements" << endl;
            }
            else{
                cout << result << " has been deleted" << endl;
            }
            break;

            case 6:
            cout << "Enter the position/index to be deleted from: ";
            cin >> pos;
            result=l1.deletepos(pos);
            if (result==0){
                cout << "List is empty or invalid position - can't delete elements" << endl;
            }
            else{
                cout << result << " has been deleted" << endl;
            }
            break;

            case 7:
            cout << "Enter target element: ";
            cin >> target;
            result = l1.search(target);
            if (result==0){
                cout << "List empty, can't search for target" << endl;
            }
            if (result!=0 || result!=-1){
                cout << "Target has been found at index " << result << endl;
            }
            else{
                cout << "Target element has not been found." << endl;
            }
            break;

            case 8:
            l1.display();
            break;

            case 9:
            cout << "Enter number of rotations: ";
            cin >> k;
            result = l1.rotate(k);
            if (result==0){
                cout << "List empty can't rotate" << endl;
            }
            if (result==1){
                cout << "List has been rotated, Enter 8 to display" << endl;

            break;

            case 10:
            cout << "Exiting program\n";
            stop=1;
            break;
            
        }
    }
}
}


// function inserts elements at the beginning of the array 
int list::insertbeginning(int num){

    if (cur>=5){
        return 0;
    }
    for (int i=cur; i>0; i--){
        arr[i]=arr[i-1];
    }
    arr[0]=num;
    cur++;
    return 1;
}

// function inserts elements at the end of the array
int list::insertend(int num){

    if (cur>=5){
        return 0;
    }
    arr[cur]=num;
    cur++;
    return 1;
}

// function inserts elements from the given index of the array // pos = index of the element
int list::insertpos(int num, int pos){

    if (cur>=5){
        return 0;
    }
    if (pos<1 || pos>cur){
        return 0;
    }
    for (int i=cur; i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=num;
    cur++;
    return 1;

}

// function deletes elements at the beginning of the array
int list::deletebeginning(){

    if (cur==0){
        return 0;
    }
    int temp = arr[0];
    for (int i = 0; i<cur; i++){
        arr[i]=arr[i+1];
    }
    cur--;
    return temp;
}

// function deletes elements at the end of the array
int list::deleteend(){

    if (cur==0){
        return 0;
    }
    int temp = arr[cur-1];
    cur--;
    return temp;
}

// function deletes elements from the given index of the array
int list::deletepos(int pos){

    if (cur==0){
        return 0;
    }
    int temp = arr[pos];
    for (int i = pos;i<cur;i++){
        arr[i]=arr[i+1];
    }
    cur--;
    return temp;
}

// searches for an element using linear search
int list::search(int target){

    if (cur==0){
        return 0;
    }
    for (int i=0; i<cur;i++){
        if (arr[i]==target){
            return i;
        }
    }return -1;
}

// displays the array
void list::display(){
    
    cout << "The elements of the array are: ";
    for (int i=0; i<cur; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// This fucntion rotates the array by a given value
int list::rotate(int k){
    
    if (cur==0){
        return 0;
    }
    k=k%cur;
    for (int i=0; i<k; i++){
        int temp = arr[cur-1];
        for (int j=cur-1; j>0; j--){
            arr[j]=arr[j-1];
        }
    arr[0]=temp;
    }
    return 1;
}