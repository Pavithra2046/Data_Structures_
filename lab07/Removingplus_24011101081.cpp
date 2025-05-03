
#include <iostream>
#include "stack.h"

using namespace std;

int main(){

    string st;
    cout << "Enter string: ";
    cin >> st;

    stack s;

    for (char ch : st) {
        if (ch=='+'){
            s.pop();
        }
        else{
            s.push(ch);
        }
    }
    cout << "The string is ";
    s.display();
    return 0;
    
}