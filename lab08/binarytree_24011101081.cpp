#include <iostream>
#include <queue>

using namespace std;

class BinaryTree {
private:
    struct Node {
        char data;
        Node* left;
        Node* right;
        Node(char value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(char value);
    void preorderTraversal(Node* node);
    void inorderTraversal(Node* node);
    void postorderTraversal(Node* node);
    bool search(char value);

    Node* getRoot() { return root; }
};

int main() {
    BinaryTree tree;
    int choice;
    char value;

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
                cout << "Enter the character to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                tree.preorderTraversal(tree.getRoot());
                cout << endl;
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.inorderTraversal(tree.getRoot());
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorderTraversal(tree.getRoot());
                cout << endl;
                break;
            case 5:
                cout << "Enter the character to search: ";
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

    return 0;
}

// Inserts a new node in level-order
void BinaryTree::insert(char value) {
    Node* newNode = new Node(value);
    if (!root) {
        root = newNode;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode;
            return;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = newNode;
            return;
        } else {
            q.push(temp->right);
        }
    }
}

// Performs Preorder Traversal (Root → Left → Right)
void BinaryTree::preorderTraversal(Node* node) {
    if (node) {
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

// Performs Inorder Traversal (Left → Root → Right)
void BinaryTree::inorderTraversal(Node* node) {
    if (node) {
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

// Performs Postorder Traversal (Left → Right → Root)
void BinaryTree::postorderTraversal(Node* node) {
    if (node) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
}

// Searches for a value in the tree (level-order search)
bool BinaryTree::search(char value) {
    if (!root) return false;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->data == value) return true;

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    return false;
}
