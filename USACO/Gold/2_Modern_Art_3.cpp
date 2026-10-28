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

    int N;
    cin >> N;
    vector<int> painting(N);
    for (auto& p: painting) cin >> p;
    vector<vector<int>> dp(N, vector<int>(N));

    for (int len = 1; len <= N; len++)
    {
        for (int l = 0; l + len <= N; l++)
        {
            int r = l + len - 1;
            dp[l][r] = 1;
            if (l < r) dp[l][r] = dp[l + 1][r] + 1;

            for (int k = l + 1; k <= r; k++)
            {
                if (painting[l] != painting[k]) continue;
                int tmp = 0;
                if (l + 1 < k) tmp += dp[l + 1][k - 1];
                if (k <= r) tmp += dp[k][r];
                dp[l][r] = min(dp[l][r], tmp);
            }
        }
    }

    cout << dp[0][N - 1];
    return 0;
}
