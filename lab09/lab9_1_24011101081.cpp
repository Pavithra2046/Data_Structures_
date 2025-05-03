#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void winners();

int main(){

    cout << endl;
    int tests;
    cout << "Enter number of test cases: ";
    cin >> tests;

    for (int i=0; i<tests; i++){
        winners();
        cout << endl;
    }

    return 0;
}

// This function calculates the number of winners for each test case
void winners(){

    int k,q;
    cin >> k;
    cin >> q;
    int e;

    vector<int> v1;
    for (int i=0; i<k; i++){

        cin >> e;
        v1.push_back(e);
    }

    vector<int> v2;
    for (int i=0; i<q; i++){

        cin >> e;
        v2.push_back(e);
    }

    int min = *min_element(v1.begin(),v1.end());

    cout << "Output: ";

    for (int i : v2){
        if (i < min){
            cout << i << " ";
        }
        else{
            cout << min-1 << " ";
        }
    }

    cout << endl;
}