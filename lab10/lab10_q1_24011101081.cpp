#include <iostream>
#include <vector>

using namespace std;

void solve();

int main(){

    int t;
    cout << endl;
    cout << "Enter number of testcases: ";
    cin >> t;
    cout << endl;

    for (int i=0; i<t; i++){
        solve();
        cout << endl;
    }

    return 0;
}

// Calculates the minimum number of elements to be removed so that remaining elements are different
void solve(){

    int n;
    cin >> n;

    vector<int> v(n);
    
    for (int &x : v){
        cin >> x;
    }

    vector<int> frequency(n+1,0);
    int right = n-1;

    while (right>=0){

        frequency[v[right]]++;
        if (frequency[v[right]]>1){
            break;
        }
        right--;
    }

    cout << "Output: " << right + 1 << endl;
}