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
    vector<vector<int>> dp(N + 5, vector<int>(N + 5, 0));
    const int MOD = 1e9 + 7;

    for (int len = 1; len <= N; len++)
    {
        for (int l = 0; l + len <= N; l++)
        {
            int r = l + len - 1;
            for (int k = l + 1; k <= r; k++)
            {
                if (S[l] != S[k]) continue;
                if (l + 1 <= k - 1 && dp[l + 1][k - 1] == 0) continue;

                int add = 0;
                if (l + 1 <= k - 1) add = (add + dp[l + 1][k - 1]) % MOD;
                if (k + 1 <= r) add = (add + dp[k + 1][r]) % MOD;

                dp[l][r] = (dp[l][r] + add) % MOD;
                cerr << "l = " << l << ", r = " << r << ", dp[l][r] = " << dp[l][r] << "\n";
            }
        }
    }

    cout << dp[0][N - 1];
    return 0;
}
