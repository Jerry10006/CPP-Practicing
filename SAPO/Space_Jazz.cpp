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

#define pii pair<int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int N = S.size();
    vector<vector<int>> dp(N + 7, vector<int>(N + 7));

    for (int len = 1; len <= N; len++)
    {
        for (int l = 0; l + len <= N; l++)
        {
            int r = l + len - 1;
            dp[l][r] = 1;

            if (l < r) dp[l][r] += dp[l + 1][r];

            for (int k = l + 1; k <= r; k++)
            {
                if (S[l] != S[k]) continue;

                int cost = 0;
                if (l + 1 <= k - 1) cost += dp[l + 1][k - 1];
                if (k + 1 <= r) cost += dp[k + 1][r];

                dp[l][r] = min(dp[l][r], cost);
            }
        }
    }

    cout << dp[0][N - 1];
}
