#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    int countTime[26] = {0}; //每個字元出現的次數
    int countTime2[101] = {0};//每個每個字元出現的次數的次數 e.g. a出現2次 b出現兩次 則countTime2[2] = 2

    cin >> S;
    for (char c: S) countTime[c - 'a'] ++;
    for (int times: countTime){
        if (times > 0) countTime2[times] ++;
    }

    for (int times: countTime2){
        if (times != 0 && times != 2){
            cout << "No";
            return 0;
        } 
    }

    cout << "Yes";
}