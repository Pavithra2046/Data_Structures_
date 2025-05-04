// Hasing - Separate Chaining
#include <iostream>
#include <cstdlib>
using namespace std;

const int size = 10;

struct Node {
    int data;
    Node* next;
};

class HashTable {
private:
    Node* table[size];
    int hashkey(int key);

public:
    HashTable();
    void insert(int key);
    int remove(int key);
    bool search(int key);
};

int main() {
    int choice, key, result;
    bool stop = false;
    HashTable ht;

    while (!stop) {
        cout << "The Menu\n"
             << "1. Insert\n"
             << "2. Delete\n"
             << "3. Search\n"
             << "4. Exit\n";
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
                if (result != -1)
                    cout << result << " deleted successfully." << endl;
                else
                    cout << "Key not found!" << endl;
                break;

            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                if (ht.search(key))
                    cout << "Key found!" << endl;
                else
                    cout << "Key not found!" << endl;
                break;

            case 4:
                stop = true;
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

// constructor to initialize all heads to NULL
HashTable::HashTable() {
    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }
}

// this function returns the hash key
int HashTable::hashkey(int key) {
    return key % size;
}

// inserts a key into the hash table using separate chaining
void HashTable::insert(int key) {
    int index = hashkey(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = table[index];

    table[index] = newNode;

    cout << key << " inserted at index " << index << endl;
}

// removes a key from the hash table and returns it, or -1 if not found
int HashTable::remove(int key) {
    int index = hashkey(key);
    Node* current = table[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == key) {
            if (prev == NULL)
                table[index] = current->next;
            else
                prev->next = current->next;

            int deletedValue = current->data;
            free(current);
            return deletedValue;
        }
        prev = current;
        current = current->next;
    }

    return -1;
}

// searches for a key in the hash table
bool HashTable::search(int key) {
    int index = hashkey(key);
    Node* current = table[index];

    while (current != NULL) {
        if (current->data == key)
            return true;
        current = current->next;
    }

    return false;
}
