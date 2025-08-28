#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    string numStr;
    int num;
    numStr = S.substr(3, 3);
    num = stoi(numStr);
    if (1 <= num && num < 350 && num != 316){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}