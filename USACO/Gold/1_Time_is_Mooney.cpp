#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    struct road
    {
        int start, end;
    };

    int N, M, C;
    cin >> N >> M >> C;
    vector<int> money(N);
    for (auto& m: money) cin >> m;
    vector<road> Road(M);
    for (auto& [start, end]: Road) cin >> start >> end, start--, end--;
    vector<vector<int>> dp(1005, vector<int>(N, -1));//天數/上一個地方
    dp[0][0] = 0;

    int ans = 0;
    for (int t = 1; t <= 1000; t++)
    {
        for (auto& [start, end]: Road)
        {
            if (dp[t - 1][start] != -1)
            {
                dp[t][end] = max(dp[t][end], dp[t - 1][start] + money[end]);
            }
        }
        if (dp[t][0] != -1) ans = max(ans, dp[t][0] - C * t * t);
    }

    cout << ans;
}
