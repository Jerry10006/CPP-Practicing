#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, MOD = 1e9 + 7;
    cin >> N;
    vector<vector<int>> compatibility(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> compatibility[i][j];
    vector<int> dp(1 << N);
    dp[0] = 1;

    for (int S = 1; S < (1 << N); S++)
    {
        int cnt = __builtin_popcount(S);
        for (int j = 1; j <= N; j++)
        {
            if ((1 << (j - 1)) & S && compatibility[cnt][j])
            {
                dp[S] = (dp[S] + dp[S & ~(1 << (j - 1))]) % MOD;
            }
        }
    }

    cout << dp[(1 << N) - 1];
    return 0;
}
