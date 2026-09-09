#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, MOD = 1e9 + 7;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<vector<int>> dp((1 << n), vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }

    dp[1][0] = 1;

    for (int S = 1; S < (1 << n); S++)
    {
        for (int u = 0; u < n; u++)
        {
            if (!(S & (1 << u)) || dp[S][u] == 0) continue;
            if (u == n - 1 && S != (1 << n) - 1) continue;

            for (auto v: graph[u])
            {
                if (!(S & (1 << v)))
                {
                    int next_S = S | (1 << v);
                    dp[next_S][v] = (dp[next_S][v] + dp[S][u]) % MOD;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
    return 0;
}
