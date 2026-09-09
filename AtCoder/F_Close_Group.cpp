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

    int N, M;
    cin >> N >> M;
    vector<int> adj(N, 0);
    for (int i = 0; i < N; i++) adj[i] = (1 << i);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a] |= (1 << b);
        adj[b] |= (1 << a);
    }

    vector<bool> is_complete((1 << N), true);
    for (int S = 1; S < (1 << N); S++)
    {
        for (int v = 0; v < N; v++)
        {
            if ((S >> v) & 1)
            {
                if ((S & adj[v]) != S)
                {
                    is_complete[S] = false;
                    break;
                }
            }
        }
    }

    vector<int> dp((1 << N), 1e9);
    dp[0] = 0;
    for (int S = 1; S < (1 << N); S++)
    {
        for (int t = S; t > 0; t = (t - 1) & S)
        {
            if (is_complete[t]) dp[S] = min(dp[S], dp[S & ~t] + 1);
        }
    }

    cout << dp[(1 << N) - 1] << endl;
    return 0;
}