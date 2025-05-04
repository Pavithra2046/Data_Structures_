// Hashing - Quadratic Probing
#include <iostream>
using namespace std;

const int size = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[size];
    int hashkey(int key);

public:
    HashTable();
    void insert(int key);
    int remove(int key);
    int search(int key);
    void display();
};

int main() {
    int choice, key, result;
    bool stop = false;
    HashTable ht;

    while (!stop) {
        cout << "The Menu\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                ht.insert(key);
                break;

            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                result = ht.remove(key);
                if (result != -3)
                    cout << result << " deleted" << endl;
                else
                    cout << "Key not found!" << endl;
                break;

            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                result = ht.search(key);
                if (result != -1)
                    cout << key << " found at index " << result << endl;
                else
                    cout << "Key not found!" << endl;
                break;

            case 4:
                ht.display();
                break;

            case 5:
                stop = true;
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

// constructor to initialize the table with EMPTY
HashTable::HashTable() {
    for (int i = 0; i < size; i++) {
        table[i] = EMPTY;
    }
}

// this function returns the hash key
int HashTable::hashkey(int key) {
    return key % size;
}

// inserts the key into the hash table using quadratic probing
void HashTable::insert(int key) {
    int index = hashkey(key);
    int i = 0;

    while (i < size) {
        int newIndex = (index + i * i) % size;
        if (table[newIndex] == EMPTY || table[newIndex] == DELETED) {
            table[newIndex] = key;
            cout << key << " inserted at index " << newIndex << endl;
            return;
        }
        i++;
    }
    cout << "Hash table is full!" << endl;
}

// deletes the key from the hash table
int HashTable::remove(int key) {
    int index = hashkey(key);
    int i = 0;

    while (i < size) {
        int newIndex = (index + i * i) % size;
        if (table[newIndex] == key) {
            table[newIndex] = DELETED;
            return key;
        }
        if (table[newIndex] == EMPTY) break;
        i++;
    }
    return -3;
}

// searches for a key in the hash table
int HashTable::search(int key) {
    int index = hashkey(key);
    int i = 0;

    while (i < size) {
        int newIndex = (index + i * i) % size;
        if (table[newIndex] == key) return newIndex;
        if (table[newIndex] == EMPTY) break;
        i++;
    }
    return -1;
}

// displays the hash table
void HashTable::display() {
    for (int i = 0; i < size; i++) {
        if (table[i] == EMPTY)
            cout << "empty ";
        else if (table[i] == DELETED)
            cout << "deleted ";
        else
            cout << table[i] << " ";
    }
    cout << endl;
}

