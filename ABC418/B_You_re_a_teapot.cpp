#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    long double ans = 0.0;
    for (int start = 0; start < s.size(); start++){
        for (int end = start + 2; end < s.size(); end++){
            if (s[start] == 't' && s[end] == 't'){
                int tCount = 0;
                for (int i = start; i <= end; i++){
                    if (s[i] == 't') tCount ++; 
                }
                if (tCount > 2){
                    long double rate = (long double) (tCount - 2)/(end - start + 1 - 2);
                    ans = max(ans, rate);
                }
            }
        }
    }
    cout << fixed << setprecision(17) << ans << "\n";
    return 0;
}