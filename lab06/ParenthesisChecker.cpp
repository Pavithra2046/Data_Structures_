#include "ParenthesisChecker.h"

int main() {
    int choice;
    string expr;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter a string of parentheses: ";
                getline(cin, expr);

                if (isBalanced(expr)) {
                    cout << "Balanced Parentheses\n";
                } else {
                    cout << "Unbalanced Parentheses\n";
                }
                break;

            case 2:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
