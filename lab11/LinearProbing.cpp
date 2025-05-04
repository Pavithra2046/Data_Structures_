// Hashing - Linear Probing 
#include <iostream>
using namespace std;


const int size = 10;
const int empty = -1;
const int deleted = -2;

class HashTable{

    private:
    int table[size];
    int hashkey(int);

    public:
    HashTable(){
        for (int i=0; i<size; i++){
            table[i]=empty;
        }
    }

    void insert(int);
    int remove(int);
    int search(int);
    void display();

};

int main(){

    int choice;
    int key;
    int stop=0;
    int result;

    HashTable ht;

    cout << endl;

    while(stop==0){
        cout << "The Menu\n"
             << "1. Insert\n"
             << "2. Delete\n"
             << "3. Search\n"
             << "4. Display\n"
             << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){

            case 1:
            cout << "Enter key: ";
            cin >> key;
            ht.insert(key);
            cout << endl;
            break;


            case 2:
            cout << "Enter key to be deleted: ";
            cin >> key;
            result=ht.remove(key);
            if (result!=-3){
                cout << result << " has been deleted" << endl;
            }
            else{
                cout << "Key not found!" << endl;
            }
            cout << endl;
            break;


            case 3:
            cout << "Enter key to be searched: ";
            cin >> key;
            result=ht.search(key);
            if (result!=-1){
                cout << key << " has been found at index " << result << endl;
            }
            else{
                cout << "Key not found!" << endl;
            }
            cout << endl;

            break;

            case 4:
            ht.display();
            cout << endl;
            break;

            case 5:
            stop=1;
            cout << "Exiting..." << endl;
            cout << endl;
            break;


        }
    }

}

// This function returns the hashkey
int HashTable::hashkey(int key){
    return key%size;
}

// inserts the key into the hash table
void HashTable::insert(int key){

    int index = hashkey(key);
    int start = index;

    do {
        if (table[index]==empty || table[index]==deleted){
            table[index]=key;
            cout << key << " has been inserted at index " << index << endl;
            return;
        }
        index = (index+1)%size;

    }while(index!=start);

    cout << "Hash table is full!" << endl;

}

// deletes the key from the hash table
int HashTable::remove(int key){

    int index = hashkey(key);
    int start = index;

    do {
        if (table[index]==key){
            table[index]=deleted;
            return key;
        }
        index = (index+1)%size;

    }while(index!=start);
    return -3;

}

// searches for a given key in a hash table
int HashTable::search(int key){

    int index = hashkey(key);
    int start = index;

    do {
        if (table[index]==key){
            return index;
        }
        index = (index+1)%size;

    }while(index!=start);
    return -1;

}

// displays the hash table
void HashTable::display(){

    for (int i=0; i<size; i++){
        if (table[i]==empty){
            cout << "empty" << " ";
        }
        else if (table[i]==deleted){
            cout << "deleted" << " ";
        }

        else {
            cout << table[i] << " ";
        }
    }
    cout << endl;
}

