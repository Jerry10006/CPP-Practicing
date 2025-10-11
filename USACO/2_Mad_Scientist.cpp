//
// Created by 蔡杰叡 on 2025/10/8.
//
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int N, ans = 0;
    string A, B;
    bool Changed = false;

    cin >> N;
    cin >> A >> B;

    for (int i = 0; i < N; i++)
    {
        if (B[i] != A[i]) Changed = true;
        else
        {
            if (Changed == true) ans++; Changed = false;
        }
    }

    cout << ans;
    return 0;
}