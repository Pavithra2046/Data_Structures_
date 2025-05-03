#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

void score();

int main(){

    int t;
    cout << endl;
    cout << "Enter number of testcases: ";
    cin >> t;
    cout << endl;

    for (int i=0; i<t; i++){
        score();
        cout << endl;
    }

    return 0;

}

// Calculates the score of the players
void score(){

    int n;
    cin >> n;
    string s;

    vector<vector<string>> words(3,vector<string>(n));
    unordered_map<string,int> wordcount;

    for (int i=0; i<3; i++){
        for (int j=0; j<n; j++){
            cin >> s;
            words[i][j]=s;
            wordcount[s]++;
        }
    }

    vector<int> scores(3,0);

    for (int i=0; i<3; i++){
        for (int j=0; j<n; j++){
            s=words[i][j];
            if (wordcount[s]==1){
                scores[i]+=3;
            }
            else if(wordcount[s]==2){
                scores[i]+=1;
            }
        }
    }

    cout << "Output: " << scores[0] << " " << scores[1] << " " << scores[2] << endl;
}
