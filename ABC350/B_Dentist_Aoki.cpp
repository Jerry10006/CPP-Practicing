#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int Q;
    cin >> N >> Q;
    int ans = 0;
    vector<int> Mouth(N, 1);
    for (int i = 0; i < Q; i++){
        string tooth;
        cin >> tooth;
        int itooth = stoi(tooth) - 1;
        if (Mouth[itooth] == 0){
            Mouth[itooth] = 1;
        }
        else if (Mouth[itooth] == 1)
        {
            Mouth[itooth] = 0;
        }
    }
    for (int &YN : Mouth){
        if (YN == 1) ans++;
    }
    cout << ans;
}