//
// Created by 蔡杰叡 on 2025/8/30.
//
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int K, N;
    cin >> K >> N;
    int ans = 0;
    vector<vector<int>> rank(K, vector<int>(N + 1));

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            rank[i][num] = j;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            bool iWin = true, jWin = true;
            for (int round = 0; round < K; round++)
            {
                if (rank[round][i] < rank[round][j])
                {
                    jWin = false;
                    continue;
                }
                else
                {
                    iWin = false;
                    continue;
                }
            }
            if (iWin || jWin) ans++;
        }
    }
    cout << ans << endl;
}