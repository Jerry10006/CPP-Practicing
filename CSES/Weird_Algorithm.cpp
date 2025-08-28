#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    string ans = to_string(n);
    while (n != 1){
        if (n % 2 == 1){
            n = n * 3 + 1;
        }
        else{
            n = n / 2;
        }
        ans = ans + " " + to_string(n);
    }
    cout << ans;
    return 0;
}