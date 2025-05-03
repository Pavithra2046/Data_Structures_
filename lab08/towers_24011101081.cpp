// C++ program to find the maximum number of blocks

#include <iostream>
#include <algorithm>
using namespace std;

int height();

int main(){

    cout << "\nInput: " << endl;
    int tests;
    cin >> tests;

    int *maxheights = (int *)malloc(tests*sizeof(int));

    for (int i=0; i < tests; i++){
        maxheights[i]=height();
    }

    cout << "\nOutput: " << endl;

    for (int i=0; i < tests; i++){
        cout << maxheights[i] << endl;
    }

    cout << endl; 
    
    return 0;
}

// This function calculates the maximum height that tower 1 can reach
int height(){

    int towers;
    cin >> towers;

    int *blocks = (int *)malloc(towers*sizeof(int));
    int data;

    for (int i=0; i<towers; i++){
        cin >> data;
        blocks[i]=data;
    }

    int front=blocks[0];
    sort(blocks+1,blocks+towers);
    int extra=0;
    
    for (int i=0; i< towers; i++){
        if (blocks[i]>front){
            extra=blocks[i]-front;
            front+=(extra+1)/2;
            blocks[i]-=(extra+1)/2;

        }
    }

    return front;

}
