

#include <iostream>
using namespace std;

class BinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* insertRec(Node* node, int value);
    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);
    bool searchRec(Node* node, int value);
    void freeRec(Node* node);

public:
    BinaryTree();
    void insert(int value);
    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();
    bool search(int value);
    void freeTree();
};

int main() {
    BinaryTree tree;
    int choice, value;

    do {
        cout << "\nBinary Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the integer to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                tree.preorderTraversal();
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.inorderTraversal();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorderTraversal();
                break;
            case 5:
                cout << "Enter the integer to search: ";
                cin >> value;
                if (tree.search(value)) {
                    cout << value << " found in the tree.\n";
                } else {
                    cout << value << " not found in the tree.\n";
                }
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    tree.freeTree();

    return 0;
}

BinaryTree::BinaryTree() : root(nullptr) {}

// Function inserts a new node into the tree
void BinaryTree::insert(int value) {
    root = insertRec(root, value);
}

// Function traverses through the tree in preorder traversal
void BinaryTree::preorderTraversal() {
    preorder(root);
    cout << endl;
}

// Function traverses through the tree in inorder traversal
void BinaryTree::inorderTraversal() {
    inorder(root);
    cout << endl;
}

// Function traverses through the tree in postorder traversal
void BinaryTree::postorderTraversal() {
    postorder(root);
    cout << endl;
}

// Functions checks if an element is present in the tree
bool BinaryTree::search(int value) {
    return searchRec(root, value);
}

void BinaryTree::freeTree() {
    freeRec(root);
    root = nullptr;
}

// Function inserts a new node into the tree
BinaryTree::Node* BinaryTree::insertRec(Node* node, int value) {
    if (node == nullptr) {
        node = new Node{value, nullptr, nullptr};
        return node;
    }
    if (value < node->data)
        node->left = insertRec(node->left, value);
    else
        node->right = insertRec(node->right, value);
    return node;
}

// Function traverses through the tree in preorder traversal
void BinaryTree::preorder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

// Function traverses through the tree in inorder traversal
void BinaryTree::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

// Function traverses through the tree in postorder traversal
void BinaryTree::postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

// Functions checks if an element is present in the tree
bool BinaryTree::searchRec(Node* node, int value) {
    if (node == nullptr) return false;
    if (node->data == value) return true;
    if (value < node->data) return searchRec(node->left, value);
    return searchRec(node->right, value);
}

void BinaryTree::freeRec(Node* node) {
    if (node) {
        freeRec(node->left);
        freeRec(node->right);
        delete node;
    }
}
