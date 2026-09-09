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

vector<int> toposort(vector<vector<int>>& adj, int N)
{
    queue<int> q;
    vector<int> indeg(N + 1, 0), ans;

    for (int u = 1; u <= N; u++)
    {
        for (auto& v: adj[u]) indeg[v]++;
    }

    for (int i = 1; i <= N; i++) if (!indeg[i]) q.push(i);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (auto v: adj[u])
        {
            indeg[v]--;
            if (!indeg[v]) q.push(v);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> order = toposort(adj, N);
    vector<int> dp(N + 1, 0);

    for (auto u: order)
    {
        for (auto v: adj[u])
        {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}