#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;
using ll = long long;

int ans = -1;

void dfs(vector<vector<pair<int, int>>>& graph, int node, int from, int val, int k)
{
    ans++;
    for (auto& [n, kk]: graph[node])
    {
        if (min(val, kk) >= k && n != from) dfs(graph, n, node, min(val, kk), k);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int N, Q;
    cin >> N >> Q;
    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 1; i < N; i++)
    {
        int a, b, val;
        cin >> a >> b >> val;
        graph[a].push_back({b, val});
        graph[b].push_back({a, val});
    }

    for (int i = 0; i < Q; i++)
    {
        int k, v;
        cin >> k >> v;

        ans = -1;
        dfs(graph, v, -1, 1e9, k);
        cout << ans << "\n";
    }
    return 0;
}
