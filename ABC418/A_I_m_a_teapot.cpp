#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    string S;
    cin >> N;
    cin >> S;
    if (S.size() < 3){
        cout << "No";
        return 0;
    }
    string Last3 = S.substr(S.size() - 3);
    if (Last3 == "tea"){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}