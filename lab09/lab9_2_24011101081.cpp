#include <iostream>
using namespace std;

void difference();

int main(){

    cout << endl;
    int tests;
    cout << "Enter number of test cases: ";
    cin >> tests;

    for (int i=0; i<tests; i++){
        difference();
        cout << endl;
    }

    return 0;
}

// The fucntion calculates the difference between the number and the maximum value
void difference(){

    int k;
    cin >> k;
    int e;

    if (k<2){
        if (k==1){
            cin >> e;
            cout << "Output: ";
            cout << 0 << endl;
            return;
        }
        else{
            cout << "No elements!" << endl;
            return;
        }
    }

    int arr[k];

    for (int i=0; i<k;i++){
        cin >> e;
        arr[i]=e;
    }

    int max1=arr[0];
    int max2=0;

    for (int i=1; i<k;i++){
        if(arr[i]>max1){
            max2=max1;
            max1=arr[i];
        }else if (arr[i] > max2){
            max2=arr[i];
        }
    }
    
    cout << "Output: ";
    for (int i=0; i<k;i++){
        if (arr[i]==max1){
            cout << arr[i]-max2 << " ";
        }
        else{
            cout << arr[i]-max1 << " ";
        }
    }

    cout << endl;
    return;

}