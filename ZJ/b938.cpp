#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> r(n + 6);

    for (int i = 1; i <= n; i++){
        r[i] = i + 1;
        if (i == n)
        {
            r[i] = -1;
        }
    }

    for (int i = 0; i < m; i ++){
        int num;
        cin >> num;
        if (r[num] == -1){
            cout << "0u0 ...... ?\n";
            continue;
        }
        cout << r[num] << "\n";
        int nextnext = r[r[num]];
        r[r[num]] = -1;
        r[num] = nextnext;
    }
}